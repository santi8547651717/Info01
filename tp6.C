//perimetro y area de un rectangulo y un circulo 
#include <stdio.h>
#include <math.h>

float calcularAreaRectangulo(float base,float alt){
	return (alt * base);
}
	
float calcularPerimetroRectangulo(float base,float alt){
return(2*(base+alt));
}
float calcularDiagonalRectangulo(float base,float alt){
	return sqrt((base*base)+(alt*alt));
}		
	
float calcularAreaCirculo(float radio){
	return(M_PI*radio*radio);
}
	
float calcularPerimetroCirculo(float radio){
	return(M_PI*radio*2);
}
	
void imprimirResultados(float perimetro,float area,float diagonal){
	printf("El perimetro calculado es: %.2f\n",perimetro);
	printf("El area calculada es: %.2f\n",area);
	if(diagonal!=0)
		printf("La diagonal del rectangulo es: %.2f\n",diagonal);
}
int main(void) {
	int op;
	float largo_R,alto_R;
	float are_R,diag_R,per_R;
	float rad_C;
	float per_C,area_C;
	
	printf("Ingrese la figura que desea calcular (1: rectangulo, 2: círculo): ");
	scanf("%d",&op);
	
	switch(op){
	case 1:
		printf("Usted ingreso rectangulo\n");
		printf("Ingrese el largo de la base del rectangulo: ");
		scanf("%f",&largo_R);
		printf("Ingrese la altura del rectangulo: ");
		scanf("%f",&alto_R);
		
		per_R=calcularPerimetroRectangulo(largo_R,alto_R);
		are_R=calcularAreaRectangulo(largo_R,alto_R);
		diag_R=calcularDiagonalRectangulo(largo_R,alto_R);
		
		imprimirResultados(per_R,are_R,diag_R);
		break;
	case 2:
		
		printf("Usted ingreso circulo\n");
		printf("Ingrese el radio: ");
		scanf("%f",&rad_C);
		
		per_C=calcularPerimetroCirculo(rad_C);
		area_C=calcularAreaCirculo(rad_C);
		
		imprimirResultados(per_C,area_C,0);
		
		
		break;
		
		
	default:
		printf("Ingrese una opcion valida!!");
		break;
	}
	return 0;
}

