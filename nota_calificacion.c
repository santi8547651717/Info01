#include <stdio.h>

int main(void) {
int nota;





printf("Ingrese nota para determinar la calificaci�n: ");
scanf("%d",&nota);

if(nota>= 90)
	printf("Calificaci�n A");
else if (nota>=80 && nota <90)
	printf("Calificacion B");
else if (nota >= 70 && nota <80 )
	printf("Calificaci�n C");
else if (nota >= 60&& nota<70)
	printf ("Calificaci�n D");
else if (nota<60)
	printf ("Calificaci�n F");



return 0;
}

