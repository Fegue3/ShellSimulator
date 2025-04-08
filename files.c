#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "shell.h"

int fd_is_valid(int fd) {
    return fcntl(fd, F_GETFD) != -1 || errno != EBADF;
}

void openfile(char *nome) {
    int fd = open(nome, O_RDONLY);
    if (fd >= 0)
        printf("Aberto %s para leitura com descritor fd %d\n", nome, fd);
    else
        perror(nome);
}

void closefd(int fd) {
    if (close(fd) < 0)
        perror("closefd falhou");
    else
        printf("Descritor %d fechado com sucesso\n", fd);
}

void readfile(char *fdstr, char *nbytesstr) {
    int fd = atoi(fdstr);
    int nbytes = atoi(nbytesstr);
    char buffer[2048];

    if (nbytes > 2048) nbytes = 2048;

    int lidos = read(fd, buffer, nbytes);
    if (lidos < 0) {
        perror("Erro ao ler");
        return;
    }

    printf("ASCII: ");
    for (int i = 0; i < lidos; i++) {
        if (buffer[i] >= 32 && buffer[i] <= 126)
            putchar(buffer[i]);
        else
            putchar('.');
    }
    printf("\nHex:   ");
    for (int i = 0; i < lidos; i++) {
        printf("%02x ", (unsigned char)buffer[i]);
    }
    printf("\n");
}

void fileinfo() {
    // stdout info
    if (stdout) {
        int outfd = fileno(stdout);
        printf("STDOUT está aberto: descritor %d\n", outfd);
    } else {
        printf("STDOUT está fechado.\n");
    }

    // limite de descritores
    struct rlimit lim;
    if (getrlimit(RLIMIT_NOFILE, &lim) == 0) {
        printf("Limite de descritores de ficheiro do processo: %ld\n", lim.rlim_cur);
    }

    // listar descritores abertos
    printf("Descritores abertos: ");
    int abertos = 0;
    for (int i = 0; i < 64; i++) { // limite prático
        if (fd_is_valid(i)) {
            printf("%d ", i);
            abertos++;
        }
    }
    printf("\nTotal de ficheiros abertos: %d\n", abertos);
}

int isjpg(int fd) {
    unsigned char b[4];
    int n = read(fd, b, 4);

    if (n < 4) {
        perror("Erro ao ler os bytes iniciais");
        return 0;
    }

    // Voltar ao início do ficheiro
    lseek(fd, 0, SEEK_SET);

    // Verifica os magic bytes principais para JPEG
    if (b[0] == 0xFF && b[1] == 0xD8 && b[2] == 0xFF &&
        (b[3] == 0xE0 || b[3] == 0xE1 || b[3] == 0xE2 || b[3] == 0xE8)) {
        return 1;
    }

    return 0;
}