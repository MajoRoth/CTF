#include <stdio.h>
#include <stdlib.h>

void get_here()
{
    printf("Good Job!\n");
}

void end()
{
    printf("Program ended\n");
}

int main()
{
    void (*x)() = &end;
    int y = 3;
    char s[2];
    printf("Enter name: ");
    scanf("%15s", s);
    printf("y = %d\n", y);
    (*x)();
}