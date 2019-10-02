//Darin Johnson,
//SYST 44288 – Operating Systems & Systems Programming
//Assignment 2 proceess and erros
//Question 2 Filcopy


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    
int pipeFds[2];
    int fileBytesLength;
    char buffer[100];
    char childBuffer[100];

    // Checking for  3 arguments
    
    if (argc != 3) {
      perror("Filecopy: filecopy.exe input.txt copy.txt. \n");
      exit(1);
    }
    
    char* srcFile = argv[1];
    char* dstFile = arg[2];
    
    //process of creating pipe
    if (pipe(pipeFds) < 0){
      printf("pipe is incorrect! %s\n", sterror(errno));
        exit(1);
        
    }
    
    //Proecess of creating forking
     switch(fork()) {
             //forking error in child process
             
         case -1:
             printf("error in forking child process. %s\n", strerror(errno));
             exit(1);
             
         case 0:
             close(pipeFds[1]);
             ssize_t num_bytes_child = read(pipeFds[0], childBuffer, sizeof(childBuffer));
             close(pipeFds[0]);
             
             int targetDesc = open(dstFile, O_CREAT | O_WRONLU);
             write(targetDesc, childBuffer, num_bytes_child);
             
         default:
             close(pipeFds[0[);
             int fileInDesc = open(srcFile, O_RDONLY);
              ssize_t num_bytes = read(fileInDesc, buffer, sizeof(buffer));
               write(pipeFds[1], buffer, num_bytes);
               close(pipeFds[1]);
                             
            }
                 
           retrun 0;
                             
        
        
