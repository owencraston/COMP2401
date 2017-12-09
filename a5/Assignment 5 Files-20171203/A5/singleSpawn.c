#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
  FILE *file;
  char str[10];
  int code = 0;
  int integer;

  //check if the file is given
  if (argc < 2) {
    printf("Usage: singlePrime [fileName]");
    return(1);
  }

  // check if file exists
  code = fexists(argv[1]);
  //if file exists 
  if (code != 0) {
    char integer_string[200];
    FILE *fp = NULL;
    //open file
    fp = fopen(argv[1], "rb+");
    //read file
    fread(&integer, sizeof(int), 1, fp);
    //print 
    sprintf(integer_string, "%d", integer);

    int process_id;
    int status;
    process_id = fork();
    //spawn child
    if (process_id == 0) {
      morph(integer_string);
    }
    //spawn parent
    else {
      if (wait(&status) >= 0) {
        if (WIFEXITED(status)) {
          if (WEXITSTATUS(status) == 1) printf("%s is prime \n", integer_string);
          else printf("%s is not a prime \n", integer_string);
        }
      }
    }

  }
  else {
    printf("File %s does not exist \n", argv[1]);
  }
  //return 0
  return 0;
}

//morph function
int morph(char *num){
  char *arg = "./isPrime";
  char *params[2] = { "isPrime", num };
  execvp(arg, params);
  return -1;
}

//create function to check if file exists
int fexists(char *fileName) {
  FILE *fp = NULL;
  int code = 0;
  fp = fopen(fileName, "r");
    if(fp == NULL) {
      code = 0;
  }
  else {
    fclose(fp);
    code = 1;
  }
  return(code);
}