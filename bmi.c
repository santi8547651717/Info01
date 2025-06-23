#include <stdio.h>

int main(){
	float peso,altura,imc;
	
	printf("Calculadora de imc\n");
	printf("Ingrese peso en [kg]: ");
	scanf("%f",&peso);
	printf("Ingrese altura en [mts]: ");
	scanf("%f",&altura);
	
	imc = peso / ( altura * altura );
	
	
	printf("      Indice| Condicion\n");
	printf("      <18.5 | Bajo peso\n");
	printf("  18.5-24.9 | Normal\n");
	printf("    25-29.9 | Sobrepeso\n");
	printf("        >=30| Obesidad\n");
	
	
	printf ("Su imc es de: %.2f",imc);
	
	
	return(0);
}
