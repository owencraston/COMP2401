#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
  FILE *file;
  unsigned int num;
  char str[10];
  int code = 0;

  //check if the file is given
  if (argc < 2) {
    printf("Usage: singlePrime [fileName]");
    return(1);
  }

  // check if file exists
  code = fexists(argv[1]);
  if(code == 1){
    // The files does exist
    file = fopen(argv[1], "r");
    fread(&num, sizeof(num), 1, file);
    fclose(file);
    sprintf(str, "%d", num);
    morph(str);
  }
  else{
   // The file doesn't exist
   printf("%s not found in folder \n", argv[1]);
  }
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