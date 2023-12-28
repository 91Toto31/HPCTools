// dgesv.h
#ifndef DGESV_H
#define DGESV_H

void eliminationGauss(double matrice[N][N + 1], int N);
void substitutionArriere(double matrice[N][N + 1], double solutions[N], int N);
int my_dgesv(int n, int nrhs, double *a, double *b, int N);

#endif


