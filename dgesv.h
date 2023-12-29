// dgesv.h
#ifndef DGESV_H
#define DGESV_H

extern const int N;

void printMatrix(const char* name, double matrix[N][N + 1]);
void eliminationGauss(double matrice[N][N + 1]);
void substitutionArriere(double matrice[N][N + 1], double solutions[N]);
int my_dgesv(int n, int nrhs, double *a, double *b, double matrice[N][N + 1]);

#endif



