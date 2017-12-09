#ifndef _multi_spawn_signal_h
#define _multi_spawn_signal_h

int morph(char *number);
int fexists(char *fileName);
int filesize(FILE *fp);
void spawn(int arr[], int len);
void my_handler(int signum);

#endif