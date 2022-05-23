#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define NUMBER_BUFFER_LENGTH 8
#define XOR_KEY 0x46464646
#define ADD '+'
#define SUB '-'

void won_the_flag();
int add(int x, int y);
int sub(int x, int y);
void update(char* buffer, int *x, int *y, char *op);
int updateNumber(char* buffer, char* targetBuffer, const char op);
char findOp(char* buffer);

int main(int argc, char** argv)
{
    char input[MAX_LENGTH] = { 0 };
    int formulaCount = XOR_KEY; // We will have fun with XOR
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
        formulaCount ^= XOR_KEY;
        formulaCount++;
        formulaCount ^= XOR_KEY;
        if(strlen(input) > 0)
        {
            update(input, &x, &y, &op);
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
                printf("Your %d formula result is: %d\n", formulaCount ^ XOR_KEY, formula(x, y));
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

void update(char* buffer, int *x, int *y, char *op)
{
    char buff[NUMBER_BUFFER_LENGTH] = { 0 };
    *op = findOp(buffer);
    if((*op) == '\0')
        return;
    buffer = buffer + updateNumber(buffer, buff, *op) + 1;
    *x = atoi(buff);
    updateNumber(buffer, buff, *op);
    *y = atoi(buff);
}

int updateNumber(char* buffer, char* targetBuffer, const char op)
{
    int i = 0;
    for(i = 0; buffer[i] != 0 && buffer[i] != op; ++i)
    {
        targetBuffer[i] = buffer[i];
    }
    return i;
}

char findOp(char* buffer)
{
    int i = 0;
    for(i = 0; buffer[i]; ++i)
    {
        if(buffer[i] == ADD || buffer[i] == SUB)
            return buffer[i];
    }
    return '\0';
}