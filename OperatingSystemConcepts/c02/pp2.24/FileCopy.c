/*
 * In Section 2.3, we described a program that copies the contents of one file
 * to a destination file. This program works by first prompting the user for
 * the name of the source and destination files. Write this program using
 * either the POSIX or Windows API. Be sure to include all necessary error 
 * checking, including ensuring that the source file exists. Once you have 
 * correctly designed and tested the program, if you used a system that 
 * supports it, run the program using a utility that traces sys- tem calls. 
 * Linux systems provide the strace utility, and macOS systems use the dtruss 
 * command. (The dtruss command, which actually is a front end to dtrace, 
 * requires admin privileges, so it must be run using sudo.) These tools can be 
 * used as follows (assume that the name of the executable file is FileCopy: 
 * Linux: strace ./FileCopy
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char filename[100];
    FILE *inFile, *outFile;
    char buffer[BUFSIZ];
    size_t n;

    printf("Enter the source file: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    
    if((inFile = fopen(filename, "rb")) == NULL){
        perror("Error");
        exit(EXIT_FAILURE);
    }

    printf("Enter the destination file: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    if((outFile = fopen(filename, "wb")) == NULL){ 
        perror("Error");
        exit(EXIT_FAILURE);
    }
    
    while((n = fread(buffer, 1, BUFSIZ, inFile)) != 0){
        fwrite(buffer, 1, n, outFile);
    }
    return 0;
}
