#include "shell.h"

int ultimo ( int *numargs, char **args )
{
  if ( args[*numargs-1][0]=='&') {
    *numargs=*numargs-1;
    args[*numargs]=NULL ;
    return BG;
  }
  return FG;
}

int containsPipe (int numArgs, char **args) {
  for (int i = 0; i < numArgs; i++) {
    if (args[i][0] == '|')
      return i;
  }
  return -1;
}

void execute (int numargs, char **args)
{
  int code = ultimo(&numargs, args);
  int pid, status;

  int pipeIndex = containsPipe(numargs, args);

  if ((pid = fork ()) < 0) {
    perror ("fork");
    exit (1);
  }

  if (pid == 0) { // processo filho do shell

    if (pipeIndex == -1) {
      numargs = redirects(numargs, args);
      execvp(*args, args);
      perror(*args);
      exit(1);
    }

    // PIPE DETECTADO

    int fd[2];
    pipe(fd);

    args[pipeIndex] = NULL; // cortar o símbolo do pipe

    pid_t pid_neto = fork();

    if (pid_neto == 0) {
      // Processo NETO: comando antes do pipe
      close(fd[0]); 
      dup2(fd[1], STDOUT_FILENO);
      close(fd[1]);
      numargs = redirects(pipeIndex, args);
      execvp(args[0], args);
      perror("execvp neto");
      exit(1);
    } else {
      // Processo FILHO: comando depois do pipe
      close(fd[1]); 
      dup2(fd[0], STDIN_FILENO);
      close(fd[0]);
      char **args2 = &args[pipeIndex + 1];
      int numargs2 = numargs - pipeIndex - 1;
      numargs2 = redirects(numargs2, args2); 
      execvp(args2[0], args2);
      perror("execvp filho");
      exit(1);
    }

  } else {
    if (code == FG) {
      while (wait (&status) != pid);
    } else {
      printf("[BG] Processo iniciado com PID: %d\n", pid);
    }
  }

  return;
}
