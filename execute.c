/*
   execute . cria um processo prog�nito e executa um programa
*/
#include "shell.h"

int ultimo ( int *numargs, char **args )
{
 if ( args[*numargs-1][0]=='&') {
 *numargs=*numargs-1;
 args[*numargs]=NULL ;
 return BG;
 }
 return FG; /*return FG ou BG Definidos no shell.h */
}



void execute (int numargs, char **args)
{
  int code = ultimo(&numargs, args);
  int pid, status;

  if ((pid = fork ()) < 0)
    { /* cria um processo progenito */
      perror ("forks");/* NOTE: perror() produz uma pequema mensagem de erro para o stream */
      exit (1);/* estandardizado de erros que descreve o ultimo erro encontrado */
               /* durante uma chamada ao sistema ou funcao duma biblioteca */
    }

  if (pid == 0)
    {
      numargs = redirects(numargs, args); // <-- redirecionamento ANTES de exec
      execvp(*args, args);
      perror(*args);
      exit(1);
    }                    /* vector de strings que contem os
                            * argumentos. O ultimo argument */
  if (FG == code){
    while (wait (&status) != pid)
    /*spin fazer nada */ ;
  } else
  {
      // modo background → não espera
      printf("[BG] Processo iniciado com PID: %d\n", pid);
  }

  return;
}