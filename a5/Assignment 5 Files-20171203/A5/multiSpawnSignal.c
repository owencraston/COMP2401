#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "multiSpawnSignal.h"
#include "stdio.h"

#include "signal.h"

int sent;
int done;


void my_handler(int signum) {
    if (signum == SIGUSR1) printf("Processes called: %d Processes not done: %d\n", sent, (sent - done));
}

int main(int argc, char *argv[]) {
  int code = 0;
  int size;

  signal(SIGUSR1, my_handler);

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
    //print size
    printf("size: %d \n", size);

    //create number array
    int numbers[size];
    //allocate numbers array t file
    fread(numbers, sizeof(int), size, fp);
    //call spawn and do all the things
    spawn(numbers, size);

  }
  else {
    //oops
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

  sent = 0;
  done = 0;

  //send processes
  for (int i=0; i<len; i++) {
    //check if the pid is less than 0 to check if it is a parent
    if (((ids[i] = fork()) >= 0) && (ids[i] == 0)) {
      char integer_string[200];
      //transfer value from array to integerString
      sprintf(integer_string, "%d \n", arr[i]);
      // morpch process into isPrime
      morph(integer_string);
    }
    sent++;
  }
  //keep looping untill all process have been completed
  while (len > count) {
    status = 0;
    cur_id = waitpid(-1, &status, 0);
    int output = WIFSIGNALED(status);
    //check if output is 0, if so exit
    if (output != 0) {
      return;
    } else {
        done++;
    }

    kill(getpid(), SIGUSR1);

    // iterate through array
    for (int i=0; i<len; i++) {
      //check if ids match and outpt is 0
      if (cur_id == ids[i] && output == 0) {
          //add to reponse array
        response[i] = status;
      }
    }
    //increment counter
    count++;
  }
  //iterate through response
  for (int i=0; i<len; i++) {
    // if response has status 256...print
    if (response[i] == 256) {
      printf("prime number: %d \n", arr[i]);
    }
  }


}