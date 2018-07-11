#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

typedef struct {
	char titulo[500];
	char anio[500];
	char tagline[500];
	char Nombre[500];
	char Fecha[500];
	char Categoria[500];
	long int Movie;
	long int Person;
} Pelicula;

Pelicula Movies[1000];
Pelicula Persons[1000];
Pelicula MovPer[1000];

int cmpPelicula(void * str1, void * str2);
void printPelicula(void *data);

int main() {
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	FILE *M, *P, *PM;
	M = fopen("vertex_movies.csv", "r");
	if (M == NULL) {
		printf("Couldn't open the file for reading.\n");
	}
	P = fopen("vertex_person.csv", "r");
	if (P == NULL) {
		printf("Couldn't open the file for reading.\n");
	}
	PM = fopen("edges_PersonMovies.csv", "r");
	if (PM == NULL) {
		printf("Couldn't open the file for reading.\n");
	}
	char buff1[500], buff2[500], buff3[500];
	int new_movie = 0, new_person = 0, new_PM = 0;

	while (fscanf(M, "%[^,]%*c%[^,]%*c%[^\n]", buff1, buff2, buff3) != EOF) {
		fgetc(M);
		strcpy(Movies[new_movie].titulo, buff1);
		strcpy(Movies[new_movie].anio, buff2);
		strcpy(Movies[new_movie].tagline, buff3);
		memset(buff1, 0, sizeof(buff1));
		memset(buff2, 0, sizeof(buff2));
		memset(buff3, 0, sizeof(buff3));
		Movies[new_movie].Movie = new_movie + 1;
		Movies[new_movie].Person = 0;
		new_movie++;

	}
	fclose(M);
	while (fscanf(P, "%[^,]%*c%[^,]%*c%[^\n]", buff1, buff2, buff3) != EOF) {
		strcpy(Persons[new_person].Nombre, buff1);
		strcpy(Persons[new_person].Fecha, buff2);
		strcpy(Persons[new_person].Categoria, buff3);
		memset(buff1, 0, sizeof(buff1));
		memset(buff2, 0, sizeof(buff2));
		memset(buff3, 0, sizeof(buff3));
		Persons[new_person].Person = new_person + 1;
		Persons[new_person].Movie = 0;
		new_person++;
	}
	fclose(P);
	while (fscanf(PM, "%[^,]%*c%[^\n]", buff1, buff2) != EOF) {

		strcpy(MovPer[new_PM].Nombre, buff1);
		strcpy(MovPer[new_PM].titulo, buff2);
		memset(buff1, 0, sizeof(buff1));
		memset(buff2, 0, sizeof(buff2));
		new_PM++;
	}
	fclose(PM);

//	for (int j = 0; j < new_movie; j++) {
//		printf("%s, %s, %s", Movies[j].titulo, Movies[j].anio,
//				Movies[j].tagline);
//	}
//	printf("\n");
//	for (int j = 0; j < new_person; j++) {
//		printf("%s, %s, %s", Persons[j].Nombre, Persons[j].Fecha, Persons[j].Categoria);
//		}

	Graph PERMOV;
	PERMOV = graph_create(cmpPelicula, printPelicula);
	for (int j = 0; j < new_movie; j++) {
		graph_addVertex(PERMOV, &Movies[j]);
	}

	for (int j = 0; j < new_person; j++) {
		graph_addVertex(PERMOV, &Persons[j]);
	}

	graph_print(PERMOV);
	//printf("TAM MOVIES:%d  TAM PEOPLE: %d TAM POEPMOVIES: %d",new_movie,new_person,new_PM );
	//printf("\nVertices: %lu\n", graph_vertexCount(PERMOV));
	for (int j = 0; j < new_PM; j++) {
		printf("%s,%s", MovPer[j].Nombre,MovPer[j].titulo);
	}

	int SP = 0, SM = 0;
	for (int j = 0; j < new_PM; j++) {
		for (int a = 0; a < new_person; a++) {
			if (strcmp(MovPer[j].Nombre, Persons[a].Nombre) == 0) {
				//printf("%s:%s",MovPer[j].Nombre, Persons[a].Nombre);
				SP = a;
			}
		}
		for (int a = 0; a < new_movie; a++) {
			//printf("%s:%s\n",MovPer[j].titulo, Movies[a].titulo);
			if (strcmp(MovPer[j].titulo, Movies[a].titulo) == 0) {
				//printf("%s:%s\n",MovPer[j].titulo, Movies[a].titulo);
				SM = a;
			}
		}
		//printf("Funciona %d,%d\n", SP, SM);
		graph_addEdge(PERMOV, &Persons[SP], &Movies[SM]);

	}

	printf("\n\nNúmero de aristas: %lu",graph_edgeCount(PERMOV));

	return 0;

}
int cmpPelicula(void * str1, void * str2) {
	Pelicula *string1 = (Pelicula*) str1;
	Pelicula *string2 = (Pelicula*) str2;
	if (memcmp(&str1, &str2, sizeof(Pelicula)) != 0) {
		return false;

	} else if (strcmp(string1->titulo, string2->titulo) != 0) {
		return false;
	} else if (strcmp(string1->Nombre, string2->Nombre) == 0) {
		return true;
	}
return false;
}

void printPelicula(void *data) {
	Pelicula *Data = (Pelicula*) data;
	if (Data->Movie > 0) {
		printf("%s, %s, %s\n", Data->titulo, Data->anio, Data->tagline);
	} else if (Data->Person > 0) {
		printf("%s, %s, %s", Data->Nombre, Data->Fecha, Data->Categoria);
	}
}
