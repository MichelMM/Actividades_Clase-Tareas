//Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Variables Globales y nuevos tipos de datos
#define MAX_ARREGLO 500
//Función principal
int main() {
	//Configurando el buffer de salida
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	char Cadena[MAX_ARREGLO];
	int Salto;

	printf(
			"Favor de ingresar una palabra u oración para que posteriormente este sea cifrado en base al cifrado César");
	gets(Cadena);
	int Tam = strlen(Cadena);
	printf(
			"Ahora ingrese cuantos saltos desea que realize para cada letra en la oración");
	scanf("%d", &Salto);

	for (int i = 0; i < Tam; i++) {
		if ((Cadena[i] > 64 && Cadena[i] < 91)
				|| ((Cadena[i] > 96 && Cadena[i] < 123))) {
			for (int j = 0; j < Salto; j++) {
				Cadena[i]++;
				if (Cadena[i] > 90&& Cadena[i] < 97) {
					Cadena[i] = 65;
				} else if (Cadena[i] > 122) {
					Cadena[i]=97;
				}
			}
		}
	}
	puts(Cadena);

	return 0;
}

