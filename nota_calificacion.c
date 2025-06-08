#include <stdio.h>

int main(void) {
int nota;





printf("Ingrese nota para determinar la calificación: ");
scanf("%d",&nota);

if(nota>= 90)
	printf("Calificación A");
else if (nota>=80 && nota <90)
	printf("Calificacion B");
else if (nota >= 70 && nota <80 )
	printf("Calificación C");
else if (nota >= 60&& nota<70)
	printf ("Calificación D");
else if (nota<60)
	printf ("Calificación F");



return 0;
}

