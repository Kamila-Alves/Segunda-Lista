#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    char posicao;
    int forca;
} Jogador;

typedef struct {
    char nome[30];
    Jogador jogadores[11];
} Time;

float ForcaPonderada(Time time) {
    float G = 0, L = 0, Z = 0, V = 0, M = 0, A = 0;

    for (int i = 0; i < 11; i++) {
        switch (time.jogadores[i].posicao) {
            case 'G':
                G += time.jogadores[i].forca;
                break;
            case 'L':
                L += time.jogadores[i].forca;
                break;
            case 'Z':
                Z += time.jogadores[i].forca;
                break;
            case 'V':
                V += time.jogadores[i].forca;
                break;
            case 'M':
                M += time.jogadores[i].forca;
                break;
            case 'A':
                A += time.jogadores[i].forca;
                break;
            default:
                break;
        }
    }

    return (8 * G + 10 * L + 5 * Z + 8 * V + 11 * M + 12 * A) / 100.0;
}

int main() {
    Time time1, time2;
    char nomeTime1[100], nomeTime2[100];

    fgets(nomeTime1, 100, stdin);
    nomeTime1[strcspn(nomeTime1, "\n")] = 0;
    strncpy(time1.nome, nomeTime1, sizeof(time1.nome) - 1);

    for (int i = 0; i < 11; i++) {
        scanf(" %[^;]; %c; %d%*c", time1.jogadores[i].nome, &time1.jogadores[i].posicao, &time1.jogadores[i].forca);
    }

    fgets(nomeTime2, 100, stdin);
    nomeTime2[strcspn(nomeTime2, "\n")] = 0;
    strncpy(time2.nome, nomeTime2, sizeof(time2.nome) - 1);

    for (int i = 0; i < 11; i++) {
        scanf(" %[^;]; %c; %d%*c", time2.jogadores[i].nome, &time2.jogadores[i].posicao, &time2.jogadores[i].forca);
    }

    float forcaTime1 = ForcaPonderada(time1);
    float forcaTime2 = ForcaPonderada(time2);

    printf("%s: %.2f de forca\n", time1.nome, forcaTime1);
    printf("%s: %.2f de forca\n", time2.nome, forcaTime2);

    if (forcaTime1 > forcaTime2) {
        printf("%s eh mais forte\n", time1.nome);
    } else if (forcaTime2 > forcaTime1) {
        printf("%s eh mais forte\n", time2.nome);
    }

    return 0;
}
