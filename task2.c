#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1
int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    int file = open(argv[1], O_RDONLY);
    if (file < 0) { // If the file does not exist, print an error message including the file name
        fprintf(stderr, "Error opening %s\n", argv[1]);
        return 1;
    }
    while (read(file, buffer, BUFFER_SIZE) > 0) {
        // Process buffer here if needed
    }
    close(file);
    return 0;
}