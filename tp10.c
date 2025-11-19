#include <stdio.h>
#include <stdlib.h>

#define N_MAX 10
#define M_MAX 10

struct matrix {
  int filas;
  int columnas;
  float mat[N_MAX][M_MAX];
};

typedef struct matrix matrix_t;

void cargar_matriz(matrix_t *, char *);
void sumar_matrices(matrix_t, matrix_t, matrix_t *);
matrix_t sumar_matrices_r(matrix_t, matrix_t);
void imprimir_matriz(matrix_t);
void guardar_matriz(matrix_t, char *);

int main(void){
  matrix_t A = {0}, B = {0};
  matrix_t C = {0};

  cargar_matriz(&A, "mat_A.txt");
  cargar_matriz(&B, "mat_B.txt");

  imprimir_matriz(A);
  imprimir_matriz(B);

  sumar_matrices(A, B, &C);
  // C = sumar_matrices_r(A, B);
  imprimir_matriz(C);
  guardar_matriz(C, "mat_C.txt");

  return 0;
}

  void cargar_matriz(matrix_t *p, char *file) {
	  FILE *fp = fopen(file, "r");
	  if (fp == NULL) {
		  perror("Error");
		  exit(EXIT_FAILURE);
	  }
	  
	  if (fscanf(fp, "%d %d", &p->filas, &p->columnas) != 2) {
		  fclose(fp);
		  exit(EXIT_FAILURE);
	  }
	  
	  if (p->filas > N_MAX || p->columnas > M_MAX || p->filas < 0 || p->columnas < 0) {
		  fclose(fp);
		  exit(EXIT_FAILURE);
	  }
	  
	  for (int i = 0; i < p->filas; i++) {
		  for (int j = 0; j < p->columnas; j++) {
			  if (fscanf(fp, "%f", &p->mat[i][j]) != 1) {
				  fclose(fp);
				  exit(EXIT_FAILURE);
			  }
		  }
	  }
	  
	  fclose(fp);
  }
  
void imprimir_matriz(matrix_t m) {
  for (int i = 0; i < m.filas; i++) {
    for (int j = 0; j < m.columnas; j++)
      printf("%9.2f", m.mat[i][j]);
    printf("\n");
  }
  printf("\n\n");
}

void sumar_matrices(matrix_t A, matrix_t B, matrix_t *pC) {
	if (A.filas != B.filas || A.columnas != B.columnas) {
		exit(EXIT_FAILURE);
	}
	
	pC->filas = A.filas;
	pC->columnas = A.columnas;
	
	for (int i = 0; i < A.filas; i++) {
		for (int j = 0; j < A.columnas; j++) {
			pC->mat[i][j] = A.mat[i][j] + B.mat[i][j];
		}
	}
}

void guardar_matriz(matrix_t m, char *file) {
	FILE *fp = fopen(file, "w");
	if (fp == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}
	
	fprintf(fp, "%d %d\n", m.filas, m.columnas);
	
	for (int i = 0; i < m.filas; i++) {
		for (int j = 0; j < m.columnas; j++) {
			fprintf(fp, "%.2f", m.mat[i][j]);
			if (j < m.columnas - 1) fprintf(fp, " ");
		}
		fprintf(fp, "\n");
	}
	
	fclose(fp);
}
