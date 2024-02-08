#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
int main(){
    char buffer[BUFFER_SIZE];
    FILE *file = fopen("10mb.txt", O_RDONLY);
    if (file < 0) { //if the file does not exist, print an error message
        perror("Error opening %s");
        return 1;
    }
    while (fread(buffer, 1, BUFFER_SIZE, file) > 0) {// Read the file character by character
    //wont print anything
    }
    fclose(file);
    return 0;

}