//Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <inttypes.h>
//Variables Globales y nuevos tipos de datos
typedef struct {
	long long inicio, fin;
} PI;
float Acumu = 0;
//prototipos de funciones
DWORD WINAPI PIPP(void *);
//Función principal
int main() {
	//Configurando el buffer de salida
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	//Declaración de variables
	clock_t start = clock();
	HANDLE h[16];
	PI pi;
	char d;
	int i,hilos;
	do {
		printf(
				"¿Cuántos hilos desea utilizar en esta ejecucuón de programa?\n[a]Ingresar hilos\n[f]Salir\n");
		scanf("%c", &d);

		switch (d) {
		case 'a':
			scanf("%d",&hilos);
			for (i = 0; i < hilos; i++) {
				pi.inicio=500/hilos*i+1;
				pi.fin=500/hilos*(i+1);
				h[i] = CreateThread(NULL, 0, PIPP, (void *) &pi, 0, NULL);
			}
			for (i = 0; i < hilos; i++) {
				WaitForSingleObject(h[i], INFINITE);
			}
			//WaitForMultipleObjects(pi.hilos, h, TRUE, INFINITE);
			//pi.cont *= 4;
			printf("%.10f\n", Acumu * 4);
			break;
		}
		fflush(stdin);
		clock_t stop = clock();
		int ms = 1000 * (stop - start) / CLOCKS_PER_SEC;
		printf("%d ms\n", ms);
	} while (d != 'f');

	/*for (i = 1; i <= n; i++) {
	 cont += (pow(-1, i + 1) / (2 * i - 1));
	 }
	 cont *= 4;
	 printf("%.10f\n", cont);*/
	return 0;
}
//Desarrollo de funciones
DWORD WINAPI PIPP(void *pi) {
	PI *P = (PI *) pi;
	long long i;
	printf("HOLA");
	float cont = 0;
	float ant;
	for (i =P->inicio; i <= P->fin; i++) {
		//printf("%"PRId64"\n", i);
		printf("%.10f\n", ant);
		ant= ((float) ((i + 1) & 1 ? -1.0 : 1.0) / (2 * (float) i - 1));
		cont+=ant;
	}
	Acumu += cont;
	return 0;
}
