#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "shell.h"
#define epsilon 1.0e-16


void calc(char *value1, char *op, char *value2) {
    double num1 = atof(value1);
    double num2 = atof(value2);
    double resultado;

    if (op == NULL || value1 == NULL || value2 == NULL) {
        printf("Erro: argumentos inválidos.\n");
        return;
    }

    switch (op[0]) {
        case '+':
            resultado = num1 + num2;
            printf("Resultado calc %.3f + %.3f = %.3f\n", num1, num2, resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("Resultado calc %.3f - %.3f = %.3f\n", num1, num2, resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("Resultado calc %.3f * %.3f = %.3f\n", num1, num2, resultado);
            break;
        case '/':
            if (fabs(num2) < epsilon) {
                printf("Erro: divisão por zero.\n");
            } else {
                resultado = num1 / num2;
                printf("Resultado calc %.3f / %.3f = %.3f\n", num1, num2, resultado);
            }
            break;
        case '^':
            resultado = pow(num1, num2);
            printf("Resultado calc %.3f ^ %.3f = %.3f\n", num1, num2, resultado);
            break;
        default:
            printf("Erro: operador desconhecido '%s'\n", op);
    }
}

void bits(char *op1, char *op, char *op2) {
    if (op1 == NULL || op == NULL) {
        printf("Erro: argumentos inválidos.\n");
        return;
    }

    unsigned short num1 = (unsigned short)atoi(op1);
    unsigned short num2 = op2 ? (unsigned short)atoi(op2) : 0;
    unsigned short resultado;

    // Operadores de 1 caractere → usar switch
    if (strlen(op) == 1) {
        switch (op[0]) {
            case '&':
                resultado = num1 & num2;
                printf("Resultado bits %hu & %hu = %hu\n", num1, num2, resultado);
                break;
            case '|':
                resultado = num1 | num2;
                printf("Resultado bits %hu | %hu = %hu\n", num1, num2, resultado);
                break;
            case '^':
                resultado = num1 ^ num2;
                printf("Resultado bits %hu ^ %hu = %hu\n", num1, num2, resultado);
                break;
            case '~':
                // operador unário
                printf("Resultado bits ~%hu = %hu\n", num1, (unsigned short)(~num1));
                break;
            default:
                printf("Operador inválido: %s\n", op);
                break;
        }
    }
    // Operadores compostos → usar strcmp
    else if (strcmp(op, "<<") == 0) {
        resultado = num1 << num2;
        printf("Resultado bits %hu << %hu = %hu\n", num1, num2, resultado);
    }
    else if (strcmp(op, ">>") == 0) {
        resultado = num1 >> num2;
        printf("Resultado bits %hu >> %hu = %hu\n", num1, num2, resultado);
    }
    else {
        printf("Operador inválido: %s\n", op);
    }
}