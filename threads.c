#include <stdio.h>
#include "shell.h"

#define MAX 100

char strings[MAX][130];
int k = 0;

void aviso(char *mesg, int tempo) {
    while (tempo > 0) {
        sleep(1);
        tempo--;
    }
    fprintf(stderr, "Aviso : %s\n", mesg);
}

void *avisowrapperMAU(void *args) {
    char **pargs = (char **) args;
    aviso(pargs[1], atoi(pargs[2]));
    return NULL;
}

void *avisowrapper(void *args) {
    aviso_t *ptr = (aviso_t *)args;
    aviso(ptr->msg, ptr->tempo);
    free(ptr);
    return NULL;
}

void *socpwrapper(void *args) {
    copiar_t *ptr = (copiar_t *)args;
    socp(ptr->fonte, ptr->destino, ptr->buffsize); 
    
    // Registar no vetor de logs
    time_t t;
    time(&t);
    char *tempo = ctime(&t);
    if (tempo[strlen(tempo)-1] == '\n') tempo[strlen(tempo)-1] = '\0';
    sprintf(strings[k++ % MAX], "%s %s", tempo, ptr->fonte);
    k++;
    free(ptr);
    return NULL;
}

void mostrarRelatorio() {
    printf("Registos de cópias efetuadas:\n");
    for (int i = 0; i < k && i < MAX; i++) {
        printf("%s\n", strings[i]);
    }
}