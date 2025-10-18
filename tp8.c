#include <stdio.h>
#include <stdlib.h>
#define TAM 20

int cuantas_piezas(int max) {
	int n;
	do {
		printf("Cuántas piezas ingresará: ");
		scanf("%d", &n);
		if (n <= 0 || n > max)
			printf("Error: debe ingresar entre 1 y %d piezas.\n", max);
	} while (n <= 0 || n > max);
	return n;
}

int rectificable(float diametro, float valor) {
	return diametro > valor;
}

int rechazada(float diametro, float valor) {
	return diametro < valor;
}

void cargar_piezas(float *p, int n) {
	float valor;
	for (int i = 0; i < n; i++) {
		do {
			printf("Ingrese el diámetro de la pieza [%d]: ", i);
			scanf("%f", &valor);
			if (valor <= 0)
				printf("Error: el diámetro debe ser positivo.\n");
		} while (valor <= 0);
		*(p + i) = valor;
	}
}

int contar(int (*criterio)(float, float), float valor, float *p, int n) {
	int contador = 0;
	for (int i = 0; i < n; i++) {
		if (criterio(*(p + i), valor))
			contador++;
	}
	return contador;
}

float* reservar_memoria(int n) {
	float *ptr = (float*) malloc(n * sizeof(float));
	if (ptr == NULL) {
		printf("Error: no se pudo hacer la reserva de memoria.\n");
		exit(1);
	}
	return ptr;
}

void segregar(int (*criterio)(float, float), float valor, float *p, int n, float *q) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (criterio(*(p + i), valor)) {
			*(q + j) = *(p + i);
			j++;
		}
	}
}

void mostrar_piezas(char *mensaje, float *p, int n) {
	printf("Piezas %s:\n", mensaje);
	for (int i = 0; i < n; i++) {
		printf("Diámetro: %.2f\n", *(p + i));
	}
}

int main(void) {
	float diametros[TAM] = {0};
	int n;
	float max = 12;
	float min = 10;
	
	n = cuantas_piezas(TAM);
	cargar_piezas(diametros, n);
	
	int n_rectificar = contar(rectificable, max, diametros, n);
	float *p_rectificables = reservar_memoria(n_rectificar);
	segregar(rectificable, max, diametros, n, p_rectificables);
	
	int n_rechazar = contar(rechazada, min, diametros, n);
	float *p_rechazadas = reservar_memoria(n_rechazar);
	segregar(rechazada, min, diametros, n, p_rechazadas);
	
	mostrar_piezas("rectificables", p_rectificables, n_rectificar);
	mostrar_piezas("rechazadas", p_rechazadas, n_rechazar);
	
	free(p_rectificables);
	free(p_rechazadas);
	
	return 0;
}
