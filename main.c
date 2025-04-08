#include "shell.h"

char prompt[100];

int main ()
{
  int len;
  char linha[1024];/* um comando */
  char *args[64];/* com um maximo de 64 argumentos */
  
  strcpy (prompt, "SOSHELL: Introduza um comando : prompt>");
  while (1)
  {
    printf ("%s", prompt);
    if (fgets (linha, 1023, stdin) == NULL)
    {
      printf ("\n");
      exit (0);
    }
    len = strlen (linha);
    if (1 == len)
      continue;/* linha é apenas \n */
    if (linha[len - 1] == '\n')
      linha[len - 1] = '\0';
    int numargs = parse (linha, args);/* particiona a string em argumentos */

    if (!builtin (args))
      execute(numargs, args);/* executa o comando */
    }
  return 0;
}

int builtin (char **args)
{
  /* Toda a funcionalidade embutida deverá devolver 1*/
  if (strcmp (args[0], "sair") == 0)
  {
    exit (0);
    return 1; /* funcionalidade embutida */
  }
  if (strncmp (args[0], "42", 2) == 0)
  {
    printf("42 is the answer to life the universe and everything\n");
    printf("https://pt.wikipedia.org/wiki/The_Hitchhiker's_Guide_to_the_Galaxy\n");
    return 1;/* funcionalidade embutida */
  }
  if( 0==strcmp(args[0], "obterinfo") ){
    printf("SO Shell 2025 versaõ 1.0\n");
    return 1 ; //comando embutido
   }

   if( strlen(args[0])>4 && 0==strncmp(args[0], "PS1=",4) ){
    strcpy(prompt,args[0]+4);
    return 1 ; //comando embutido
   }
   if( 0==strcmp(args[0], "quemsoueu") ){
    system("id");
    return 1 ; //comando embutido
   }

   if (0 == strcmp(args[0], "cd")) {
    int err;
    
    // Verifica se o argumento é nulo, "~" ou "$HOME"
    if (args[1] == NULL || strcmp(args[1], "~") == 0 || strcmp(args[1], "$HOME") == 0)
        err = chdir(getenv("HOME"));  // Vai para a pasta HOME do utilizador
    else
        err = chdir(args[1]);  // Vai para o diretório indicado
    
    if (err < 0)
        perror(args[1]);  // Imprime erro caso a mudança falhe
    
    return 1;  // comando tratado internamente
  }
  if( 0==strcmp(args[0], "socp") ){
    if (args[1]!=NULL && args[2] !=NULL)
    socp( args[1], args[2] );
    else
    printf("Syntax Incorreto: Usage: socp fonte destino");
    return 1; //comando embutido
   }
   if (strcmp(args[0], "calc") == 0) {
    if (args[1] != NULL && args[2] != NULL && args[3] != NULL && args[4] == NULL) {
        calc(args[1], args[2], args[3]);
    } else {
        printf("Uso correto: calc operando1 operador operando2\n");
    }
    return 1;
  }
  if(strcmp(args[0], "bits") == 0){
    if (args[1] && args[2] && (args[3] || args[2][0] == '~') && args[4] == NULL) {
      bits(args[1], args[2], args[3]);  // args[3] pode ser NULL no caso do ~
  } else {
      printf("Uso: bits operando1 operador operando2\n");
  }
  return 1;
  }
  if (strcmp(args[0], "isjpeg") == 0) {
    if (args[1] != NULL) {
        int fd = open(args[1], O_RDONLY);
        if (fd < 0) {
            perror("Erro ao abrir o ficheiro");
        } else {
            if (isjpg(fd)) {
                printf("O ficheiro %s é JPEG válido.\n", args[1]);
            } else {
                printf("O ficheiro %s NÃO é JPEG.\n", args[1]);
            }
            close(fd);
        }
    } else {
        printf("Uso: isjpeg nome_do_ficheiro.jpg\n");
    }
    return 1;
  }
  if (strcmp (args[0], "isValid") == 0) {
    if (NULL!=args[1]) {
    int fd=atoi(args[1]);
    printf("%s é %s válido\n", args[1], fd_is_valid(fd) ? "" : "não");
    }
    return 1;
  }

   if (strcmp (args[0], "read") == 0) {
    if (NULL!=args[2] )
    readfile(args[1], args[2]);
    return 1;
   }
   if (strcmp (args[0], "fileinfo") == 0) {
    fileinfo();
    return 1;
   }
   if (strcmp (args[0], "closefd") == 0) {
    if (NULL!=args[1])
    closefd( atoi(args[1]) );
    return 1;
   }
   if (strcmp (args[0], "openfile") == 0) {
    if (NULL!=args[1] )
    openfile(args[1]);
    return 1;
   }
   if (strcmp(args[0], "displayBitOps") == 0) {
    if (args[1] && args[2]) {
        unsigned short um = (unsigned short)atoi(args[1]);
        unsigned short dois = (unsigned short)atoi(args[2]);
        displayBitOps(um, dois);
    } else {
        printf("Uso: displayBitOps <um> <dois>\n");
    }
    return 1;
  }
  /* IMPORTANTE : 
   Devolver 0 para indicar que não existe comando embutido e que
   será executado usando exec() na função execute.c
  */
  return 0;
}
