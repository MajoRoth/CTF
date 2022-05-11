#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome! Enter password: ");
    char answer[100];
    char a;
    scanf("%100s", answer);
    if (!strcmp(answer, "LacosteIsTheBest"))
    {
        printf("Good Job! You succeeded RE challenge 1");
    }
    else
    {
        printf("Wrong! try again...");
    }
    return 0;
}