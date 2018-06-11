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
double Acumu = 0;
//prototipos de funciones
DWORD WINAPI PIPP(void *);
//Función principal
int main() {
	//Configurando el buffer de salida
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	//Declaración de variables
	HANDLE h[16];
	PI pi[16];
	int hilos;
	clock_t start = clock();
	printf("Hilos?");
	scanf("%d", &hilos);
	for (int i = 0; i < hilos; i++) {
		pi[i].inicio = 50000000000 / hilos * i + 1;
		pi[i].fin = 50000000000 / hilos * (i + 1);
		h[i] = CreateThread(NULL, 0, PIPP, (void *) &pi[i], 0, NULL);
	}
	WaitForMultipleObjects(hilos, h, 1, INFINITE);
	Acumu *= 4;
	printf("PI: %.10lf\n", Acumu);
clock_t stop = clock();
int ms = 1000 * (stop - start) / CLOCKS_PER_SEC;
printf("Tiempo: %d ms\n", ms);

return 0;
}
//Desarrollo de funciones
DWORD WINAPI PIPP(void *pi) {
PI *P = (PI *) pi;
long long i;
double cont = 0;
for (i = P->inicio; i <= P->fin; i++) {
	cont += (((i + 1) & 1 ? -1.0 : 1.0) / (i + i - 1));
}
Acumu += cont;
return 0;
}
