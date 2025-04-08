#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "shell.h"

void ioCopy(int IN, int OUT) {
    char buffer[1024];
    ssize_t bytes;
    while ((bytes = read(IN, buffer, sizeof(buffer))) > 0) {
        write(OUT, buffer, bytes);
    }
}

void socp(char *fonte, char *destino) {
    int fdin = open(fonte, O_RDONLY);
    if (fdin < 0) {
        perror("Erro ao abrir ficheiro fonte");
        return;
    }

    int fdout = open(destino, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fdout < 0) {
        perror("Erro ao criar ficheiro destino");
        close(fdin);
        return;
    }

    ioCopy(fdin, fdout);

    close(fdin);
    close(fdout);
}
