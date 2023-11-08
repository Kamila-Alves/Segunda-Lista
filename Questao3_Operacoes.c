#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POSI 4
#define CART 4

void MatrizLer(int matriz[POSI][CART]) {
    for (int i = 0; i < POSI; i++) {
        for (int j = 0; j < CART; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimir(int matriz[POSI][CART]) {
    for (int i = 0; i < POSI; i++) {
        for (int j = 0; j < CART; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

void somar(int matrizA[POSI][CART], int matrizB[POSI][CART]) {
    int resultado[POSI][CART];
    for (int i = 0; i < POSI; i++) {
        for (int j = 0; j < CART; j++) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
    imprimir(resultado);
}

void subtrair(int matrizA[POSI][CART], int matrizB[POSI][CART]) {
    int resultado[POSI][CART];
    for (int i = 0; i < POSI; i++) {
        for (int j = 0; j < CART; j++) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
    imprimir(resultado);
}

void multiplicar(int matrizA[POSI][CART], int matrizB[POSI][CART]) {
    int resultado[POSI][CART];
    for (int i = 0; i < POSI; i++) {
        for (int j = 0; j < CART; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < CART; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    imprimir(resultado);
}

int main() {
    int matrizA[POSI][CART];
    int matrizB[POSI][CART];
    char operacao[10];

    MatrizLer(matrizA);
    MatrizLer(matrizB);
    scanf("%s", operacao);

    if (strcmp(operacao, "soma") == 0) {
        somar(matrizA, matrizB);
    } else if (strcmp(operacao, "sub") == 0) {
        subtrair(matrizA, matrizB);
    } else if (strcmp(operacao, "mult") == 0) {
        multiplicar(matrizA, matrizB);
    }

    return 0;
}
