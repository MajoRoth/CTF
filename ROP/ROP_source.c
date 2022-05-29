#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hack_me(int arg)
{
    // Wierd stuff... better look in IDA what this does
    register int mystery asm("ebx");

    printf("Good Job!\n");
    printf("arg = %x (Should be deadbeef)\n", arg);
    printf("mystery = %x (Should be cafebabe)\n", mystery);
}

int handle(int favorite_number)
{
    char s[32];
    printf("Enter you name: ");
    fgets(s, 256, stdin);
}

int main()
{
    printf("Enter you favorite number: ");
    int x;
    scanf("%d\n", &x);
    handle(x);
    printf("You failed.");



}
