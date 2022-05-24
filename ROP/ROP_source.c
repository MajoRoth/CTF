#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hack_me(int a)
{
    if (a == 0x41414141)
    {
        printf("Good Job!");
    }
    else
    {
        printf("almost... not good enough");
    }

}

int handle(int favorite_number)
{
    char s[1];
    printf("Enter you name: ");
    char buffer1[100];
    char buffer2[100];
    scanf("%99s", buffer1);
    scanf("%99s", buffer2);
    sprintf(s, "%s%c%s", buffer1, '\0', buffer2);
}

int main()
{
    printf("Enter you favorite number: ");
    int x;
    scanf("%d", &x);
    handle(x);
    printf("You failed.");



}

