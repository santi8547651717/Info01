#include <stdio.h>

int main(){
	float peso,altura,imc;
	
	printf("Calculadora de imc\n");
	
	do{
		printf("Ingrese peso en [kg]: ");
		scanf("%f",&peso);
		if (peso<=0)
			printf("Ingrese un numero positivo\n");
	}while(peso<=0);
	
	
	
	do{
		printf("Ingrese altura en [mts]: ");
		scanf("%f",&altura);
		if (altura<=0)
			printf("Ingrese una altura valida\n");
	}while(altura<=0);
	
	imc = peso / ( altura * altura );
	
	
	
	
	printf("      Indice| Condicion\n");
	printf("      <18.5 | Bajo peso\n");
	printf("  18.5-24.9 | Normal\n");
	printf("    25-29.9 | Sobrepeso\n");
	printf("        >=30| Obesidad\n");
	
	
	printf ("Su imc es de: %.2f",imc);
	
	
	return(0);
}
