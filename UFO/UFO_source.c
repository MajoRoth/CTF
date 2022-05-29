#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
    char *password;
};
int main()
{
    char word[100];
    struct user *user;
    printf("Enter Command: ");
    while(scanf("%99s", word))
    {
        if(!strcmp(word, "new_user"))
        {
            user = malloc(sizeof(struct user));
            //user->password = malloc(sizeof(char));
            printf("Enter Password: ");
            char temp[100];
            scanf("%4s", temp);
            user->password = malloc((strlen(temp)+1)*sizeof(char));
            strcpy(user->password, temp);
        }

        if(!strcmp(word, "delete_user"))
        {
            free(user->password);
        }

        if (!strcmp(word, "allocate_string"))
        {
            char buffer[100];
            scanf("%99s", buffer);
            char *t = malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(t, buffer);
        }
        if (!strcmp(word, "login"))
        {
            if (!strcmp(user->password, "LACOSTE"))
            {
                printf("Good Job!\n");
            }
            else
            {
                printf("Wrong Password\n");
            }
        }
        printf("Enter Command: ");

    }
}

