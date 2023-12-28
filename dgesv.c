// dgesv.c
#include "dgesv.h"
#include <math.h>

const int N = 3;

void afficherMatrice(double matrice[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            printf("%.2f\t", matrice[i][j]);
        }
        printf("\n");
    }
}

void eliminationGauss(double matrice[N][N + 1]) {
    for (int col = 0; col < N - 1; col++) {
        // Recherche du pivot maximal dans la colonne actuelle
        int max_row = col;
        for (int i = col + 1; i < N; i++) {
            if (fabs(matrice[i][col]) > fabs(matrice[max_row][col])) { //"fabs" permet de calculer la valeur absolue d'un nombre en virgule flottante en C.
                max_row = i;
            }
        }
        // Échange des lignes pour mettre le pivot maximal en haut, pour avoir une plus grande stabilité
        for (int j = 0; j < N + 1; j++) {
            double tempon = matrice[col][j]; 
            matrice[col][j] = matrice[max_row][j];
            matrice[max_row][j] = tempon;
        }
        // Échelonnement des lignes
        for (int i = col + 1; i < N; i++) {
            double factor = matrice[i][col] / matrice[col][col]; //en gros permet d'échelonné avec la diagonale de la matrice (dur à expliquer)
            for (int j = col; j < N + 1; j++) {
                matrice[i][j] -= factor * matrice[col][j];
            }
        }
    }
}

//résolution du système du bas vers le haut
void substitutionArriere(double matrice[N][N + 1], double solutions[N]) {
    for (int i = N - 1; i >= 0; i--) {
        solutions[i] = matrice[i][N];
        for (int j = i + 1; j < N; j++) {
            solutions[i] -= matrice[i][j] * solutions[j];
        }
        solutions[i] /= matrice[i][i];
    }
}

int my_dgesv(int n, int nrhs, double *a, double *b) {
    double matrice[N][N + 1];
    double solutions[N];

    // Copiez les données d'entrée dans la matrice
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            matrice[i][j] = a[i * (N + 1) + j];
        }
    }

    // Élimination de Gauss
    eliminationGauss(matrice);

    // Substitution arrière
    substitutionArriere(matrice, solutions);

    // Copiez les solutions dans le vecteur de sortie
    for (int i = 0; i < N; i++) {
        b[i] = solutions[i];
    }

    return 0;
}
