#include <stdio.h>
#define TAM 5
/* https://github.com/santi8547651717/Info01 */

int main(void) {
	int cod_bar[TAM];
	float precios[TAM];
	int i;
	
	for (i = 0; i < TAM; i++) {
		do {
			printf("Ingrese el codigo de barras (1-999999999): ");
			scanf("%d", &cod_bar[i]);
			if (cod_bar[i] < 1 || cod_bar[i] > 999999999)
				printf("Error. El codigo de barras debe estar entre 1 y 999999999\n");
		} while (cod_bar[i] < 1 || cod_bar[i] > 999999999);
		
		do {
			printf("Ingrese el precio: ");
			scanf("%f", &precios[i]);
			if (precios[i] < 0)
				printf("Error. El precio no puede ser negativo\n");
		} while (precios[i] < 0);
	}
	
	printf("\nCodigo\t\tPrecio\n");
	for (i = 0; i < TAM; i++)
		printf("%d\t%.2f\n", cod_bar[i], precios[i]);
	
	int max = 0, min = 0;
	for (i = 1; i < TAM; i++) {
		if (precios[i] > precios[max]) max = i;
		if (precios[i] < precios[min]) min = i;
	}
	
	printf("\nMas caro: [%d] %.2f\n", cod_bar[max], precios[max]);
	printf("Mas barato: [%d] %.2f\n", cod_bar[min], precios[min]);
	
	return 0;
}
