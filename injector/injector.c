#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
        char buffer[100];
        printf("Enter input: ");
        gets(buffer);
        printf("Copied the input into the buffer (0x%x) to do nothing :) printed using (0x%x)\n", buffer, printf);
        return 0;
}
