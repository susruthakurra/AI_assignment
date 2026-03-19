#include <stdio.h>

typedef struct {
    int m;
    int c;
    int boat;
    int cost;
} State;

State queue[100];
int front = 0, rear = 0;

void printState(State s) {
    printf("(%dM, %dC, %s) Cost=%d\n",
           s.m, s.c,
           s.boat == 0 ? "Left" : "Right",
           s.cost);
}

int isGoal(State s) {
    return (s.m == 0 && s.c == 0 && s.boat == 1);
}

int isValid(State s) {

    int mr = 3 - s.m;
    int cr = 3 - s.c;

    if (s.m < 0 || s.c < 0 || s.m > 3 || s.c > 3)
        return 0;

    if (s.m > 0 && s.m < s.c)
        return 0;

    if (mr > 0 && mr < cr)
        return 0;

    return 1;
}

void sortQueue() {
    for(int i = front; i < rear - 1; i++) {
        for(int j = i + 1; j < rear; j++) {

            if(queue[i].cost > queue[j].cost) {

                State temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;

            }
        }
    }
}

int main() {

    printf("Missionaries and Cannibals using Uniform Cost Search\n\n");

    State start = {3,3,0,0};
    queue[rear++] = start;

    int moves[5][2] = {
        {1,0},
        {2,0},
        {0,1},
        {0,2},
        {1,1}
    };

    while(front < rear) {

        sortQueue();

        State current = queue[front++];

        printState(current);

        if(isGoal(current)) {
            printf("Goal reached using UCS\n");
            return 0;
        }

        for(int i = 0; i < 5; i++) {

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

            next.cost = current.cost + 1;

            if(isValid(next)) {
                queue[rear++] = next;
            }
        }
    }

    return 0;
}
