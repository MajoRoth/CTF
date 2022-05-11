#include <stdio.h>
#include <string.h>

int validate_login(char *username, char *password)
{
    int result = 1;
    for (int i = 0; i < strlen(username); i++)
    {
        if (username[i] + 3 != password[i])
        {
            result = 0;
        }
    }
    return result;

}

int main()
{
    char username[100];
    char password[100];
    printf("Welcome to the_authenticator challenge!\n");
    printf("Enter Username: ");
    scanf("%100s", username);
    printf("Enter Password: ");
    scanf("%100s", password);
    if (validate_login(username, password))
    {
        printf("Good Job! You completed the_authenticator challenge!\n");
    }
    else
    {
        printf("You're a noob. Ha Ha. Try again.\n");
    }
    return 0;

}

