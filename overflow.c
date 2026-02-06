#include <stdio.h>
#include <string.h>
void vulnerable_function(const char *input) {
    char buffer1[10];
    char canary[4] = {'C','A','N','Y'}; // sentinel between buffers
    char buffer2[10];
    printf("len(input) = %zu\n", strlen(input));
    strcpy(buffer1, input); // overflow when len >= 10
    printf("\ncanary after copy: %c%c%c%c\n", canary[0], canary[1], canary[2], canary[3]);
    printf("\nbuffer2 (may be corrupted):\n");
    for (int i = 0; i < 10; i++) {
        printf("[%d]: %c\n", i, buffer2[i]);
    }
}
int main(int argc, char *argv[]) { //entry point
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    vulnerable_function(argv[1]); // Passes user input to the vulnerable function
    printf("\n");
    return 0;
}