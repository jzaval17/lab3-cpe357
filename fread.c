#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 8192
int main(){
    char buffer[BUFFER_SIZE];
    int file = open("theme.txt", O_RDONLY);
    if (file < 0) { //if the file does not exist, print an error message
        perror("Error opening %s");
        return 1;
    }
    while (read(file, buffer, BUFFER_SIZE) > 0) {// Read the file character by character
    //wont print anything
    }
    close(file);
    return 0;

}