#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 32
#define NUMBER_BUFFER_LENGTH 8
#define ADD '+'
#define SUB '-'

struct stack_controler{
    char input[MAX_LENGTH];
    unsigned char formulaCount;
    int (*formula)(int, int);
};

void won_the_flag();
int add(int x, int y);
int sub(int x, int y);
void update(char* buffer, int* x, int* y, char* op,  size_t length);
int updateNumber(char* buffer, char* targetBuffer, const char op, size_t length);
char findOp(char* buffer, size_t length);

int main(int argc, char** argv)
{
    struct stack_controler stack = {0};
    stack.formulaCount = 0;
    // char input[MAX_LENGTH] = { 0 };
    // int formulaCount = 0xAAAAAAAA; // We will have fun with XOR
    // int (*formula)(int, int) = NULL;
    int x = 0, y = 0;
    char op = '\0';

    printf("Welcome to my calculator you can add and substract: \n");
    do
    {
        printf("Enter your formula (empty string to exit): \n");
        fflush(stdout);
        gets(stack.input);
        /*
        if (strlen(stack.input) > 0 && stack.input[strlen(stack.input) - 1] == '\n')
        {
            stack.input[strlen(stack.input) - 1] = 0;
        }
        */
        stack.formulaCount++;

        printf("You entered: %s\n", stack.input);
        if (strlen(stack.input) > 0)
        {
            update(stack.input, &x, &y, &op, MAX_LENGTH);
            switch (op)
            {
            case ADD:
                stack.formula = add;
                break;
            case SUB:
                stack.formula = sub;
                break;
            default:
                printf("Invalid operation\n");
                break;
            }
            if (stack.formula != NULL)
            {
                printf("Your %u formula result is: %d\n", (unsigned int) stack.formulaCount, stack.formula(x, y));
            }
            fflush(stdout);
        }
        else
            break;

    } while (1);


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

void update(char* buffer, int* x, int* y, char* op, size_t length)
{
    char buff[NUMBER_BUFFER_LENGTH] = { 0 };
    *op = findOp(buffer, length);
    if ((*op) == '\0')
        return;
    buffer = buffer + updateNumber(buffer, buff, *op, NUMBER_BUFFER_LENGTH) + 1;
    *x = atoi(buff);
    updateNumber(buffer, buff, *op, NUMBER_BUFFER_LENGTH);
    *y = atoi(buff);
}

int updateNumber(char* buffer, char* targetBuffer, const char op, size_t length)
{
    int i = 0;
    for (i = 0;i < length && buffer[i] != 0 && buffer[i] != op; ++i)
    {
        targetBuffer[i] = buffer[i];
    }
    targetBuffer[i] = 0;
    return i;
}

char findOp(char* buffer, size_t length)
{
    int i = 0;
    for (i = 0; i < length & buffer[i]; ++i)
    {
        if (buffer[i] == ADD || buffer[i] == SUB)
            return buffer[i];
    }
    return '\0';
}