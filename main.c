#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 20

char* plays[3] = {"pierre", "feuille", "ciseaux"};
int wins[2];

char* strtolower(char* dest, const char* src) {
    char* result = dest;
    while(*dest++ = tolower(*src++));

    return result;
}

bool is(char* str1, char* str2) {
    return strcmp(str1, str2) == 0;
}

void recapWin() {
    printf("Nombre de manches gagnees par le joueur : %d\n", wins[0]);
    printf("Nombre de manches gagnees par la machine : %d\n", wins[1]);
}

void checkWin(int joueur, int enemy) {
    printf("Le joueur a joue %s\n", plays[joueur]);
    printf("La machine a joue %s\n", plays[enemy]);
    int diff = joueur - enemy;

    if (diff == 0) {
        printf("Egalite !\n");
    } else if (diff > 0 || diff == 2) {
        printf("Le joueur a gagne cette manche !\n");
        wins[0] += 1;
    } else {
        printf("La machine a gagne cette manche !\n");
        wins[1] += 1;
    }
}

int findId(char element[7]) {
    char result[7];
    int index = -1;

    for (int i = 0; i < 3; i++) {
        if (is(strtolower(result, element), plays[i])) {
            index = i;
            break;
        }
    }

    return index;
}

bool checkInPlays(char element[7]) {
    bool exists = false;
    exists = findId(element) > -1;
    

    if (!exists) {
        printf("Saisie invalide !\n");
    }

    return exists;
}

void launchRound() {
    char play[7];
    int enemy = (rand() % 3);
    int joueur;

    do {
        printf("Entrez votre jeu parmi 'pierre', 'feuille' et 'ciseaux' : ");
        scanf("%s", play);
    } while (!checkInPlays(play));

    joueur = findId(play);

    checkWin(joueur, enemy);

    recapWin();
}

void launchGame() {
    int rounds;
    wins[0] = 0;
    wins[1] = 0;

    do {
        printf("Entrez le nombre de manches souhaites (entre 1 et 20) : ");
        scanf("%d", &rounds);
    } while(rounds < 1 || rounds > MAX);

    for (int i = 0; i < rounds; i++) {
        launchRound();
    }

    if (wins[0] > wins[1]) {
        printf("Victoire du joueur !\n");
    } else if (wins[1] > wins[0]) {
        printf("Victoire de la machine !\n");
    } else {
        printf("Egalite parfaite !\n");
    }
}

int main() {
    bool willPlay;
    char doesPlay[3];
    char result[3];
    do {
        launchGame();

        printf("Voulez-vous rejouer ? Entrez 'Oui' pour relancer une partie ou 'Non' pour terminer le jeu.\n");
        scanf("%s", doesPlay);
        willPlay = is(strtolower(result, doesPlay), "oui");

        if (willPlay) {
            printf("Nouvelle partie !\n");
        } else {
            printf("Fin du programme.");
        }
    } while (willPlay);

    return 0;
}