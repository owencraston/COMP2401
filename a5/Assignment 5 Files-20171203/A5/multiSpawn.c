#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "multiSpawn.h"
#include "stdio.h"


int main(int argc, char *argv[]) {
  int code = 0;
  int size;

  //check if the file is given
  if (argc < 2) {
    printf("Usage: singlePrime [fileName]");
    return(1);
  }

  // check if file exists
  code = fexists(argv[1]);
  //if file exists 
  if (argv[1] != NULL) {

    FILE *fp;
    //open file
    fp = fopen(argv[1], "rb");

    //get file size
    size = filesize(fp);

    printf("size: %d \n", size);

    int numbers[size];

    fread(numbers, sizeof(int), size, fp);

    spawn(numbers, size);

  }
  else {
    printf("File %s does not exist \n", argv[1]);
  }
  //return 0
  return 0;
}

//create function to get size of file
int filesize(FILE *fp) {
  int start = ftell(fp);
  fseek(fp, 0L, SEEK_END);
  int size = ftell(fp);
  fseek(fp, start, SEEK_SET);
  return size / sizeof(int);
}

//morph function
int morph(char *num){
  char *arg = "./isPrime";
  char *params[3] = { "isPrime", num };
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

// create function for logic
void spawn(int arr[], int len) {
  //variables 
  pid_t cur_id;
  pid_t ids[len];
  int response[len];
  int status = 0;
  int count = 0;
  int output;

  //send processes
  for (int i=0; i<len; i++) {
    //check if the pid is less than 0 to check if it is a parent
    if ((ids[i] = fork()) < 0) {
        //
    } else if (ids[i] == 0) {
        char integer_string[200];
        sprintf(integer_string, "%d \n", arr[i]);
        morph(integer_string);
    }
  }


  while (len > count) {
    status = 0;
    
    cur_id = waitpid(-1, &status, 0);

    int output = WIFSIGNALED(status);

    if (output != 0) {
      return;
    } 


    for (int i=0; i<len; i++) {
      if (cur_id == ids[i] && output == 0) {
          //printf("test \n");
        response[i] = status;
      }
    }
    count++;
  }

  for (int i=0; i<len; i++) {
    //printf("r: %d\n", response[i]);
    if (response[i] == 256) {
      printf("prime number: %d \n", arr[i]);
    }
  }


}
