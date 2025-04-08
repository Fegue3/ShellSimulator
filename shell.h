#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/wait.h>

int parse(char *buf, char **args);

void execute (int numargs, char **args);

int builtin (char **args);

void socp(char *fonte, char *destino);

void ioCopy(int IN,int OUT);

int ultimo ( int *numargs, char **args );

void calc(char *value1, char *op, char *value2);

void bits(char *op1, char *op, char *op2);

int isjpg(int fd);

int fd_is_valid(int fd);

void openfile(char *nome);

void closefd(int fd);

void readfile(char *fdstr, char *nbytesstr);

void fileinfo();

void displayBitOps(unsigned short um, unsigned short dois);

int redirects(int numargs, char *args[]);

/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1
