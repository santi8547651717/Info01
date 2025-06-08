#include <stdio.h>

int main(){
    float peso,altura,imc;
    
    printf("Calculadora de imc\n");
    printf("Ingrese peso en [kg]: ");
    scanf("%f",&peso);
    printf("Ingrese altura en [mts]: ");
    scanf("%f",&altura);
    
imc = peso / ( altura * altura );


if (imc < 18.5)
	printf("Bajo peso\n");
else if (imc >= 18.5 && imc <= 24.9)
	printf("Normal\n");
else if (imc >= 25.0 && imc <= 29.9)
	printf("Sobrepeso\n");
else
	printf("Obesidad\n");
printf ("Su imc es de: %.2f",imc);
  
  
 return(0);
}
