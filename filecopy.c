#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int pipeFds[2];
    int fileBytesLength;
    char buffer[100];
    char childBuffer[100];

    // Checking for  3 arguments
    
    if (argc != 3) {
      perror("Filecopy: filecopy.exe input.txt copy.txt. \n");
      exit(1);
