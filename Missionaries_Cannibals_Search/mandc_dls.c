#include <stdio.h>

typedef struct {
    int m;
    int c;
    int boat;
} State;

void printState(State s) {
    printf("(%dM,%dC,%s)\n", s.m, s.c, s.boat==0?"Left":"Right");
}

int isGoal(State s){
    return (s.m==0 && s.c==0 && s.boat==1);
}

int isValid(State s){

    int mr = 3 - s.m;
    int cr = 3 - s.c;

    if(s.m<0 || s.c<0 || s.m>3 || s.c>3)
        return 0;

    if(s.m>0 && s.m<s.c)
        return 0;

    if(mr>0 && mr<cr)
        return 0;

    return 1;
}

void DLS(State current, int depth){

    printState(current);

    if(isGoal(current)){
        printf("Goal reached\n");
        return;
    }

    if(depth<=0)
        return;

    int moves[5][2] = {
        {1,0},{2,0},{0,1},{0,2},{1,1}
    };

    for(int i=0;i<5;i++){

        State next=current;

        if(current.boat==0){
            next.m-=moves[i][0];
            next.c-=moves[i][1];
            next.boat=1;
        }
        else{
            next.m+=moves[i][0];
            next.c+=moves[i][1];
            next.boat=0;
        }

        if(isValid(next))
            DLS(next, depth-1);
    }
}

int main(){

    State start={3,3,0};

    printf("Depth Limited Search\n\n");

    DLS(start,10);

    return 0;
}
