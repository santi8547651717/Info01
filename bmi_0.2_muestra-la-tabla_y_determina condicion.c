#include <stdio.h>

int main() {
	float peso, altura, imc;
	
	printf("Calculadora de IMC\n");
	
	printf("Ingrese peso en [kg]: ");
	scanf("%f", &peso);
	
	printf("Ingrese altura en [mts]: ");
	scanf("%f", &altura);
	
	imc = peso / (altura * altura);
	
	
	printf("      Indice| Condicion\n");
	printf("      <18.5 | Bajo peso\n");
	printf("  18.5-24.9 | Normal\n");
	printf("    25-29.9 | Sobrepeso\n");
	printf("        >=30| Obesidad\n");
	
	
	if (imc < 18.5)
		printf("Bajo peso\n");
	else if (imc >= 18.5 && imc <= 24.9)
		printf("Normal\n");
	else if (imc >= 25.0 && imc <= 29.9)
		printf("Sobrepeso\n");
	else
		printf("Obesidad\n");
	
	printf("Su IMC es de: %.2f\n", imc);
	
	return 0;
}
