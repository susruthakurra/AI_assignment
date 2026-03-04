#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CAPTCHA_LENGTH 6

void generateCaptcha(char captcha[]) {

    char characters[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    for(int i = 0; i < CAPTCHA_LENGTH; i++) {
        int index = rand() % (sizeof(characters) - 1);
        captcha[i] = characters[index];
    }

    captcha[CAPTCHA_LENGTH] = '\0';
}

void distortCaptcha(char captcha[]) {

    printf("\nCAPTCHA Challenge: ");

    for(int i = 0; captcha[i] != '\0'; i++) {
        printf("%c ", captcha[i]);
    }

    printf("\n");
}

int verifyCaptcha(char original[], char userInput[]) {

    if(strcmp(original, userInput) == 0)
        return 1;
    else
        return 0;
}

int main() {

    char captcha[CAPTCHA_LENGTH + 1];
    char userInput[20];

    srand(time(NULL));

    printf("CAPTCHA Verification System\n");

    generateCaptcha(captcha);

    distortCaptcha(captcha);

    printf("Enter the CAPTCHA: ");
    scanf("%s", userInput);

    if(verifyCaptcha(captcha, userInput))
        printf("Verification Successful. User is human.\n");
    else
        printf("Verification Failed. Try again.\n");

    return 0;
}
