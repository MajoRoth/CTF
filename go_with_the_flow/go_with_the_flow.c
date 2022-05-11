#include <stdio.h>
#include <string.h>

int main()
{
    char a[5];
    printf("enter b: ");
    char x[1];
    char b[5];
    scanf("%s", b);
    if (!strcmp(a, "YEAH"))
    {
        printf("Good Job! You completed go_with_the_flow challenge!\n");
    }
    else
    {
        printf("Failed. Try again. x = %c\n", x[0]);
    }
}