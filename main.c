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

void updateWins(char winner[7]) {
    if (is(winner, "joueur")) {
        printf("Le joueur a gagne cette manche !\n");
        wins[0] += 1;
    } else if (is(winner, "machine")) {
        printf("La machine a gagne cette manche !\n");
        wins[1] += 1;
    } else {
        printf("Egalite !\n");
    }

    printf("Nombre de victoires du joueur : %d\n", wins[0]);
    printf("Nombre de victoires de la machine : %d\n", wins[1]);
}

char* checkWin(char* play, char enemy[7]) {
    printf("Le joueur a joue %s\n", play);
    printf("La machine a joue %s\n", enemy);

    char* winner;
    if (is(play, enemy)) {
        winner = "none";
    } else if (is(play,"pierre") && is(enemy,"ciseaux")) {
        winner = "joueur";
    } else if (is(play, "feuille") && is(enemy, "pierre")) {
        winner = "joueur";
    } else if (is(play, "ciseaux") && is(enemy, "feuille")) {
        winner = "joueur";
    } else {
        winner = "machine";
    }

    return winner;
}

bool checkInPlays(char element[7]) {
    char result[7];
    bool exists = false;
    for (int i = 0; i < 3; i++) {
        if (is(strtolower(result, element), plays[i])) {
            exists = true;
        }
    }

    if (!exists) {
        printf("Saisie invalide !\n");
    }

    return exists;
}

void launchRound() {
    char play[7];
    char result[7];
    int randnum = (rand() % 3);
    char* enemy = plays[randnum];
    do {
        printf("Entrez votre jeu parmi 'pierre', 'feuille' et 'ciseaux' : ");
        scanf("%s", play);
    } while (!checkInPlays(play));

    char* winner = checkWin(strtolower(result, play), enemy);

    updateWins(winner);
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