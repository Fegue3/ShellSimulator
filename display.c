#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

typedef unsigned short tipo;
tipo mask = 0x8000; // 1000 0000 0000 0000

void printBits(tipo numero, tipo mascara) {
    while (mascara > 0) {
        putchar((numero & mascara) ? '1' : '0');
        mascara >>= 1;
    }
}

void printBitsLn(tipo numero, tipo mascara) {
    printBits(numero, mascara);
    putchar('\n');
}

void displayBitOps(tipo um, tipo dois) {
    printf("Expressão       binary              decimal  octal  hex\n");

    printf("um              ");
    printBits(um, mask);
    printf("  %7u  %5o  %3x\n", um, um, um);

    printf("dois            ");
    printBits(dois, mask);
    printf("  %7u  %5o  %3x\n", dois, dois, dois);

    tipo r_and = um & dois;
    printf("um & dois       ");
    printBits(r_and, mask);
    printf("  %7u  %5o  %3x\n", r_and, r_and, r_and);

    tipo r_or = um | dois;
    printf("um | dois       ");
    printBits(r_or, mask);
    printf("  %7u  %5o  %3x\n", r_or, r_or, r_or);

    tipo r_xor = um ^ dois;
    printf("um ^ dois       ");
    printBits(r_xor, mask);
    printf("  %7u  %5o  %3x\n", r_xor, r_xor, r_xor);

    tipo r_clear = um & ~dois;
    printf("um &~ dois      ");
    printBits(r_clear, mask);
    printf("  %7u  %5o  %3x\n", r_clear, r_clear, r_clear);
}

