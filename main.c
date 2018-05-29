//Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
//Variables Globales y nuevos tipos de datos
typedef struct {
	int Expediente;
	char Nombre[100];
	int Carrera;
	int Edad;
} Alumno;
//prototipos de funciones
void Registro_Alumno(Alumno *Student, int b) {
	printf("Expediente del alumno #%d: ", b + 1);
	scanf("%d", &(Student + b)->Expediente);
	printf("Nombre del alumno #%d: ", b + 1);
	fflush(stdin);
	gets((Student + b)->Nombre);
	printf("Número de Carrera: ");
	scanf("%d", &(Student + b)->Carrera);
	printf("edad del alumno #%d:", b + 1);
	scanf("%d", &(Student + b)->Edad);
}
void Imprimir_Datos(Alumno *Student) {

	for (int i = 0; i < MAX; i++) {
		if (Student->Expediente != 0) {
			printf("Expediente del alumno #%d: %d\n", i + 1,
					Student->Expediente);
			printf("Nombre del alumno #%d: ", i + 1);
			puts(Student->Nombre);
			printf("Número de Carrera: %d\n", Student->Carrera);
			printf("edad del alumno #%d: %d\n", i + 1, Student->Edad);
			Student++;
		}
	}
}
void Borrar_Datos(Alumno *Student, int b) {
	(Student + b)->Expediente = 0;
	for (int i = 0; i < strlen((Student + b)->Nombre); i++) {
		(Student + b)->Nombre[i] = ' ';
	}
	(Student + b)->Carrera = 0;
	(Student + b)->Edad = 0;
}
void Imprimir_Dato(Alumno *Student, int i) {
	printf("Expediente del alumno #%d: %d\n", i + 1, (Student + i)->Expediente);
	printf("Nombre del alumno #%d: ", i + 1);
	puts((Student + i)->Nombre);
	printf("Número de Carrera: %d\n", (Student + i)->Carrera);
	printf("edad del alumno #%d: %d\n", i + 1, (Student + i)->Edad);
}
void Buscar_Alumno(Alumno *Student, int f, int j) {
	int m;
	for (int i = 0; i < MAX; i++) {
		if (f == 1) {
			m=(Student+i)->Expediente;
			if (j == m) {
				Imprimir_Dato(Student, i);
			}
		}
		if (f == 2) {
			m=(Student+i)->Edad;
			if (j == m) {
				Imprimir_Dato(Student, i);
			}
		}
	}

}
//Función principal
int main() {
	//Configurando el buffer de salida
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	//Declaración de variables
	Alumno Estudiante[MAX];
	Alumno *Student = Estudiante;
	char Menu;
	int b;
	int f, j;
	//Entrada de datos
	for (int i = 0; i < MAX; i++) {
		Borrar_Datos(Student, i);
	}
	do {
		printf(
				"           Menu          \n[a] Registrar nuevo alumno\n[b] Imprimir datos\n[c] Eliminar alumno\n[d] Buscar alumno\n[e]Salir\n");
		fflush(stdin);
		Menu = getchar();
		switch (Menu) {
		case 'a':
			Student = Estudiante;
			printf(
					"Favor de ingresar el número del alumno al que desea ingresar datos: ");
			scanf("%d", &b);
			b -= 1;
			Registro_Alumno(Student, b);
			break;
		case 'b':
			Student = Estudiante;
			Imprimir_Datos(Student);
			break;
		case 'c':

			printf(
					"Favor de ingresar el número del alumno que desea eliminar sus datos: ");
			scanf("%d", &b);
			b -= 1;
			Borrar_Datos(Student, b);
			break;
		case 'd':
			printf(
					"¿De qué forma desea buscar el alumno?\n[1]Expediente\n[2]Edad\n");
			scanf("%d", &f);
			if (f == 1) {
				printf("Ingrese el expediente del alumno: ");
				scanf("%d", &j);
			} else if (f == 2) {
				printf("Ingrese la edad del alumno del alumno: ");
				scanf("%d", &j);
			}

			Buscar_Alumno(Student, f, j);
			break;
		case 'e':
			Menu = 'e';
			break;
		default:
			printf("Error, vuelva a ingresar un inciso válido\n");
		}
	} while (Menu != 'e');
	//Procesameinto de datos
	//Salida de información
	return 0;
}

//Desarrollo de funciones



