#include <stdio.h>
#include <stdlib.h>

#define TAM_NOMBRE_ESTUDIANTE 80
#define TAM_NOMBRE_MATERIA 80

typedef struct {
	char nombre[TAM_NOMBRE_MATERIA];
	int cantidad_parciales;
	int *parcial;
	float promedio;
} materia_t;

struct estudiante {
	int legajo;
	char nombre[TAM_NOMBRE_ESTUDIANTE];
	int cantidad_materias;
	materia_t *materia;
};

struct estudiante cargar_estudiante(void);
void imprimir_estudiante(struct estudiante);
materia_t* reservar_materias(int);
void liberar_materias(materia_t*);
int* reservar_parciales(int);
void liberar_parciales(int*);
void cargar_materias(struct estudiante*);
void cargar_parciales(materia_t*);
void calcular_promedio(materia_t*);

int main(void){
	struct estudiante est1;
	
	est1 = cargar_estudiante();
	cargar_materias(&est1);
	
	imprimir_estudiante(est1);
	
	for (int i = 0; i < est1.cantidad_materias; i++) {
		liberar_parciales(est1.materia[i].parcial);
	}
	liberar_materias(est1.materia);
	
	return 0;
}
	
	struct estudiante cargar_estudiante(void) {
		struct estudiante e;
		
		printf("Ingrese legajo del estudiante: ");
		scanf("%d", &e.legajo);
		
		printf("Ingrese nombre del estudiante: ");
		scanf(" %80[^\n]s", e.nombre);
		
		printf("¿Cuántas materias va a cargar? ");
		scanf("%d", &e.cantidad_materias);
		
		e.materia = reservar_materias(e.cantidad_materias);
		
		return e;
	}
	
	void imprimir_estudiante(struct estudiante e) {
		printf("%10d %s\n", e.legajo, e.nombre);
		printf("\n");
		
		for (int i = 0; i < e.cantidad_materias; i++) {
			printf("%s:", e.materia[i].nombre);
			for (int j = 0; j < e.materia[i].cantidad_parciales; j++) {
				printf("%5d", e.materia[i].parcial[j]);
			}
			printf(" Promedio: %.2f\n", e.materia[i].promedio);
		}
	}
	
	void cargar_materias(struct estudiante *e) {
		for (int i = 0; i < e->cantidad_materias; i++) {
			printf("Ingrese el nombre de la materia: ");
			scanf(" %80[^\n]s", e->materia[i].nombre);
			printf("¿Cuántos parciales tiene %s? ", e->materia[i].nombre);
			scanf("%d", &e->materia[i].cantidad_parciales);
			
			e->materia[i].parcial = reservar_parciales(e->materia[i].cantidad_parciales);
			
			cargar_parciales(&e->materia[i]);
		}
	}
	
	void cargar_parciales(materia_t *p) {
		for (int i = 0; i < p->cantidad_parciales; i++) {
			int nota;
			do {
				printf("Ingrese calificación del %d° parcial: ", i + 1);
				scanf("%d", &nota);
				if (nota < 1 || nota > 10) {
					printf("Error: La nota debe estar entre 1 y 10.\n");
				}
			} while (nota < 1 || nota > 10);
			p->parcial[i] = nota;
		}
		calcular_promedio(p);
	}
	
	void calcular_promedio(materia_t *p) {
		float suma = 0;
		for (int i = 0; i < p->cantidad_parciales; i++) {
			suma += p->parcial[i];
		}
		p->promedio = suma / p->cantidad_parciales;
	}
	
	materia_t* reservar_materias(int n) {
		materia_t *p = NULL;
		
		p = malloc(n * sizeof(materia_t));
		if (p == NULL) {
			printf("No se pudo reservar memoria. Fin del programa.\n");
			exit(1);
		}
		
		return p;
	}
	
	int* reservar_parciales(int n) {
		int *p = NULL;
		
		p = malloc(n * sizeof(int));
		if (p == NULL) {
			printf("No se pudo reservar memoria. Fin del programa.\n");
			exit(1);
		}
		
		return p;
	}
	
	void liberar_parciales(int *p) {
		if (p != NULL)
			free(p);
	}
	
	void liberar_materias(materia_t *p) {
		if (p != NULL)
			free(p);
	}
