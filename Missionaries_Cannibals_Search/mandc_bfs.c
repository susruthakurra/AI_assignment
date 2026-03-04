#include <stdio.h>

typedef struct {
    int m;
    int c;
    int boat;
} State;

State queue[100];
int front = 0, rear = 0;

void printState(State s) {
    printf("(%dM, %dC, %s)\n", s.m, s.c, s.boat == 0 ? "Left" : "Right");
}

int isValid(State s) {

    int mRight = 3 - s.m;
    int cRight = 3 - s.c;

    if (s.m < 0 || s.c < 0 || s.m > 3 || s.c > 3)
        return 0;

    if (s.m > 0 && s.m < s.c)
        return 0;

    if (mRight > 0 && mRight < cRight)
        return 0;

    return 1;
}

int isGoal(State s) {
    return (s.m == 0 && s.c == 0 && s.boat == 1);
}

int main() {

    printf("Missionaries and Cannibals using BFS\n\n");

    State start = {3,3,0};
    queue[rear++] = start;

    int moves[5][2] = {
        {1,0},
        {2,0},
        {0,1},
        {0,2},
        {1,1}
    };

    while(front < rear) {

        State current = queue[front++];
        printState(current);

        if(isGoal(current)) {
            printf("Goal reached using BFS\n");
            return 0;
        }

        for(int i=0;i<5;i++) {

            State next = current;

            if(current.boat == 0) {
                next.m -= moves[i][0];
                next.c -= moves[i][1];
                next.boat = 1;
            }
            else {
                next.m += moves[i][0];
                next.c += moves[i][1];
                next.boat = 0;
            }

            if(isValid(next)) {
                queue[rear++] = next;
            }
        }
    }

    return 0;
}
