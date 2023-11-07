#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 4
#define COL 4

void MatrizLer(int matriz[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimir(int matriz[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

void somar(int matrizA[ROW][COL], int matrizB[ROW][COL]) {
    int resultado[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
    imprimir(resultado);
}

void subtrair(int matrizA[ROW][COL], int matrizB[ROW][COL]) {
    int resultado[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
    imprimir(resultado);
}

void multiplicar(int matrizA[ROW][COL], int matrizB[ROW][COL]) {
    int resultado[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < COL; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    imprimir(resultado);
}

int main() {
    int matrizA[ROW][COL];
    int matrizB[ROW][COL];
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
