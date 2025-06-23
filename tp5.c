//https://github.com/santi8547651717/Info01
#include <stdio.h>

int main() {
	int n;
	float nota, suma = 0, mayor = -1, menor = 101;
	
	do {
		printf("Cantidad de estudiantes: ");
		scanf("%d", &n);
	} while (n <= 0);
	
	for (int i = 0; i < n; i++) {
		do {
			printf("Nota %d: ", i + 1);
			scanf("%f", &nota);
			if (nota < 0 || nota > 100)
				printf("Nota inválida. Debe estar entre 0 y 100.\n");
		} while (nota < 0 || nota > 100);
		
		suma += nota;
		if (nota > mayor) mayor = nota;
		if (nota < menor) menor = nota;
	}
	
	printf("Promedio: %.2f\n", suma / n);
	printf("Mayor nota: %.2f\n", mayor);
	printf("Menor nota: %.2f\n", menor);
	
	return 0;
}
