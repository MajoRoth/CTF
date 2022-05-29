#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_USERNAME_LENGTH 8
int user_name_actual_length;


void wow(int start, int *s)
{
    *s = start - *s;
}

void get_password(char **argv)
{
    char username[MAX_USERNAME_LENGTH];
    fgets(username, 256, stdin);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("USAGE: the_kanas.exe [username]");
        return 1;
    }

    user_name_actual_length = strlen(argv[1]);
    get_password(argv);

    if (user_name_actual_length == -1)
    {
        printf("if the exit code is 0, you won!");
    }
    else
    {
        printf("No...");
    }
    printf("\nexit code: %d\n", user_name_actual_length + 1);
    exit(user_name_actual_length + 1);
}