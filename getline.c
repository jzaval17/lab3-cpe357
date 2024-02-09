#define _GNU_SOURCE // Enables GNU-specific extensions, getline() is one of them
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Include for free
#include <errno.h> // Include for errno and perror


int main(int argc, char * argv[]) {//argc is the number of arguments, argv is the array of arguments
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    char *last = NULL, *secondLast = NULL;

    if (argc != 2){ //if the number of arguments is not 2, print an error message
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;

    }
    file = fopen(argv[1], "r");// Attempt to open file
    if (file == NULL) {//if the file does not exist, print an error message
        fprintf(stderr, "Error: %s: Unexpected setback\n", argv[1]);
        perror("");
        return 1;
    }
    //the while loop reads the file line by line and stores the second last and last line
    while (getline(&line, &len, file) != -1) {// Read the file line by line
        free(secondLast);
        secondLast = last;// Store the last line
        last = strdup(line);// Duplicate the current line
        }
        if (secondLast != NULL) { //if the second last line is not empty, print it
            printf("%s", secondLast);
            free(secondLast);
        }
        if (last != NULL) { //if the last line is not empty, print it
            printf("%s", last);
            free(last);
        }
        printf("\n");
        free(line);
        fclose(file);
        return 0;
    }

