#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define NUMBER_BUFFER_LENGTH 16
#define XOR_KEY 0xAAAAAAAA
#define ADD '+'
#define SUB '-'


void won_the_flag();
int add(int x, int y);
int sub(int x, int y);
void update(char* buffer, int *x, int *y, char *op);

int main(int argc, char** argv)
{
    char input[MAX_LENGTH] = { 0 };
    int formulaCount = 0xAAAAAAAA; // We will have fun with XOR
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
    int i = 0;
    // Finding the op
    for(i = 0; buffer[i]; ++i)
    {
        if(buffer[i] == ADD || buffer[i] == SUB)
        {
            *op = buffer[i];
            break;
        }
    }
    // Finding the x
    for(i = 0; buffer[i]; ++i)
    {
        if(buffer[i] == ADD || buffer[i] == SUB)
        {
            buff[i] = 0;
            *x = atoi(buff);
            break;
        }
        else
            buff[i] = buffer[i];
    }
    // Finding the y
    ++i;
    memset(buff, 0, NUMBER_BUFFER_LENGTH);
    for(int j = 0; buffer[i]; ++i, ++j)
    {
        buff[j] = buffer[i];
    }
    buff[i] = 0;
    *y = atoi(buff);

}