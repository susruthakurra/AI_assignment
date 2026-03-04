#include <stdio.h>
#include <string.h>

void aiResponse(char input[]) {

    if(strstr(input,"hello") || strstr(input,"hi"))
        printf("AI: Hello! How are you?\n");

    else if(strstr(input,"name"))
        printf("AI: I am an AI participant.\n");

    else if(strstr(input,"weather"))
        printf("AI: The weather seems nice today.\n");

    else
        printf("AI: That is interesting.\n");
}

void humanResponse(char input[]) {

    if(strstr(input,"hello") || strstr(input,"hi"))
        printf("Human: Hey! I'm doing well.\n");

    else if(strstr(input,"name"))
        printf("Human: My name is Alex.\n");

    else if(strstr(input,"weather"))
        printf("Human: It feels pretty warm today.\n");

    else
        printf("Human: Hmm, I am not sure about that.\n");
}

int main() {

    char question[100];
    int choice;

    printf("Turing Test Simulation\n");

    printf("Ask a question: ");
    fgets(question,100,stdin);

    printf("\nSelect participant to answer:\n");
    printf("1. Participant A\n");
    printf("2. Participant B\n");
    scanf("%d",&choice);

    if(choice==1)
        aiResponse(question);
    else
        humanResponse(question);

    printf("\nJudge must determine whether the participant was human or AI.\n");

    return 0;
}
