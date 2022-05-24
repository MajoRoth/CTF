#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
        char buffer[100];

        if (argc < 2) {
                printf("Usage: %s <input>\n", argv[0]);
                exit(0);
        }

        strcpy(buffer, argv[1]);
        printf("Copied the input into the buffer (0x%x) to do nothing :)\n", buffer);
        return 0;
}
