#include <stdio.h>

int main() {
    int entrada[10];
    int conjuntos[10];
    int tamanho = 10;
    int i, j; 

    printf("");
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &entrada[i]);
    }

    for (i = 0; i < tamanho; i++) {
        printf("%d", entrada[i]);
        if (i != tamanho - 1) {
            printf("");
        }
    }
    printf("\n");

    for (i = 0; i < tamanho; i++) {
        conjuntos[i] = entrada[i];
    }

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            conjuntos[j] = conjuntos[j] + conjuntos[j + 1];
        }

        for (j = 0; j < tamanho - i - 1; j++) {
            printf("%d", conjuntos[j]);
            if (j != tamanho - i - 2) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}