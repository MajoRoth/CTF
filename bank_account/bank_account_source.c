#include <stdlib.h>

#include <unistd.h>

#include <string.h>
#include <sys/types.h>
#include <stdio.h>

struct auth {
    char name[32];
    int auth;
};

struct auth *auth;

char *service;

int main(int argc, char **argv) {

    int is_logged = 0;
    char *command;
    char line[128];

    while (1) {

        printf("[ auth = %p %s,\n"
               "service = %p\n"
               "command = %p ]\n", auth, auth->name, service, command);

        if (is_logged) {
            printf("logged in options: \n-command"
                   " (command name) \n-apply [only admins]\n");
        }

        if (fgets(line, sizeof(line), stdin) == NULL) break;

        if (is_logged) {
            if (strncmp(line, "command ", 8) == 0) {
                command = malloc(32);
                memset(command, 0, 32);

                if (strlen(line + 8) < 10) {
                    strcpy(command, line + 8);
                } else {
                    printf("command too long\n");
                }
            }

            if (strncmp(line, "apply", 5) == 0) {
                printf("%d\n", strncmp(auth->name, "admin", 5));
                if (strncmp(auth->name, "admin", 5) == 0) {
                    if (strncmp(command, "give_me_the_flag", 16) == 0) {
                        printf("You got the flag!\n");
                        break;
                    }
                } else {
                    free(command);
                    printf("You must be admin to use apply\n");
                }
            }
        }


        if (strncmp(line, "auth ", 4) == 0) {

            auth = malloc(sizeof(struct auth));


            memset(auth, 0, sizeof(struct auth));

            if (strlen(line + 5) < 31) {

                strcpy(auth->name, line + 5);

            }

        }

        if (strncmp(line, "reset", 5) == 0) {

            free(auth);

        }

        if (strncmp(line, "service", 7) == 0) {

            service = strdup(line + 8);

        }

        if (strncmp(line, "login", 5) == 0) {

            if (auth->auth) {

                is_logged = 1;
                printf("welcome to the system.\n");

            } else {

                printf("please enter your password\n");

            }

        }

    }
}