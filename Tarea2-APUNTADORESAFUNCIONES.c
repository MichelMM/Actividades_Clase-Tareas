//Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
//Variables Globales y nuevos tipos de datos
typedef struct {
	long i;
	float cont;
	int j,hilos;
} PI;
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
	long i;
	double cont = 0;
	do {
		printf("¿Cuántos hilos desea utilizar en esta ejecucuón de programa?\n[a]1\n[b]2\n[c]4\n[d]8\n[e]16\n[f]Salir\n");
		scanf("%c", &d);
		switch (d) {
		case 'a':
			pi.hilos=1;
			for (i = 0; i < pi.hilos; i++) {
				pi.j = i;
				h[i] = CreateThread(NULL, 0, PIPP, (void *) &pi, 0, NULL);
				WaitForSingleObject(h[i], INFINITE);
				cont += pi.cont;
			}
			cont *= 4;
			printf("%.10lf\n", cont);

			break;
		case 'b':
			pi.hilos=2;
			for (i = 0; i < pi.hilos; i++) {
				pi.j = i;
				h[i] = CreateThread(NULL, 0, PIPP, (void *) &pi, 0, NULL);
				WaitForSingleObject(h[i], INFINITE);
				cont += pi.cont;
			}
			cont *= 4;
			printf("%.10lf\n", cont);

			break;
		case 'c':
			pi.hilos=4;
			for (i = 0; i < pi.hilos; i++) {
				pi.j = i;
				h[i] = CreateThread(NULL, 0, PIPP, (void *) &pi, 0, NULL);
				WaitForSingleObject(h[i], INFINITE);
				cont += pi.cont;
			}
			cont *= 4;
			printf("%.10lf\n", cont);

			break;
		case 'd':
			pi.hilos=8;
			for (i = 0; i < pi.hilos; i++) {
				pi.j = i;
				h[i] = CreateThread(NULL, 0, PIPP, (void *) &pi, 0, NULL);
				WaitForSingleObject(h[i], INFINITE);
				cont += pi.cont;
			}
			cont *= 4;
			printf("%.10lf\n", cont);

			break;
		case 'e':
			pi.hilos=16;
			for (i = 0; i < pi.hilos; i++) {
				pi.j = i;
				h[i] = CreateThread(NULL, 0, PIPP, (void *) &pi, 0, NULL);
				WaitForSingleObject(h[i], INFINITE);
				cont += pi.cont;
			}
			cont *= 4;
			printf("%.10lf\n", cont);

			break;
		default:
			break;
		}

		clock_t stop = clock();
		int ms = 1000 * (stop - start) / CLOCKS_PER_SEC;
		printf("%d ms\n", ms);
	} while (d != 'f');

	/*for (i = 1; i <= n; i++) {
	 cont += (pow(-1, i + 1) / (2 * i - 1));
	 }
	 cont *= 4;
	 printf("%.10f\n", cont);*/

	//Entrada de datos
	//Procesameinto de datos
	//Salida de información
	return 0;
}
//Desarrollo de funciones
DWORD WINAPI PIPP(void *pi) {
	PI *P = (PI *) pi;
	for (P->i = 50000000000 / (P->hilos) * (P->j)+1;P->i <= 50000000000 / (P->hilos) * (P->j + 1); P->i ++) {
		P->cont += ((P->i+1) & 1? -1.0 : 1.0) / (2 *P->i - 1);
	}
	return 0;
}
