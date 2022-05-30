#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define NUMBER_BUFFER_LENGTH 8
#define ADD '+'
#define SUB '-'

void won_the_flag();
int add(int x, int y);
int sub(int x, int y);
void update(char* input, int *x, int *y, char *op);
int updateNumber(char* input, char* numberBuffer, const char op);
char findOp(char* input);

int main(int argc, char** argv)
{
    char input[MAX_LENGTH] = { 0 };
    unsigned int formulaCount = 0;
    int (*formula)(int, int) = NULL;
    int x = 0, y = 0;
    char op = '\0';

    printf("Welcome to my calculator you can add and substract: \n");
    do{
        printf("Enter your formula (empty string to exit): ");
        fgets(input, MAX_LENGTH, stdin);
        if(strlen(input) > 0 && input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = 0;
        }
        printf("You entered: %s\n", input);
        formulaCount++;

        if(strlen(input) > 0)
        {
            update(input,
                   &x, &y, &op);
            switch(op)
            {
                case ADD:
                    formula = add;
                    break;
                case SUB:
                    formula = sub;
                    break;
                default:
                    printf("Invalid operation\n");
                    break;
            }
            if(formula != NULL)
            {
                printf("Your %d formula result is: %d\n", formulaCount, formula(x, y));
            }
        }
        else
            break;
        
    }while(1);
    

    return 0;
}


void won_the_flag()
{
    printf("You won the flag!\n");
    exit(1);
}

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

void update(char* input, int *x, int *y, char *op)
{
    char numberBuffer[NUMBER_BUFFER_LENGTH] = { 0 };
    *op = findOp(input);
    if((*op) == '\0')
        return;
    input = input + updateNumber(input, numberBuffer, *op) + 1;
    *x = atoi(numberBuffer);
    updateNumber(input, numberBuffer, *op);
    *y = atoi(numberBuffer);
}

int updateNumber(char* input, char* numberBuffer, const char op)
{
    int i = 0;
    for(i = 0; input[i] != 0 && input[i] != op; ++i)
    {
        numberBuffer[i] = input[i];
    }
    numberBuffer[i] = 0;
    return i;
}

char findOp(char* input)
{
    int i = 0;
    for(i = 0; input[i]; ++i)
    {
        if(input[i] == ADD || input[i] == SUB)
            return input[i];
    }
    return '\0';
}