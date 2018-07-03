///Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>
#include "StQueue.h"

#define MAX 20
//Variables Globales y nuevos tipos de datos
bool balancedBrackets(char *);
//prototipos de funciones
//Funci�n principal
int main() {
	//Configurando el buffer de salida
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	//Declaraci�n de variables
	char exp[MAX];
	int BOOL;
	printf("Ingrese una expresi�n aritm�tica: ");
	fflush(stdin);
	gets(exp);
	BOOL = balancedBrackets(exp);
	if (BOOL == 1)
		printf("True\n");
	else
		printf("False\n");
	return 0;
}
//Desarrollo de funciones
bool balancedBrackets(char *exp){
    //dentro de la variable s se almacenan los brackets y par�ntesis orientados hacia la derecha
 	Stack s = createStack();
     char ch;
     int i = 0;
     while (*(exp+i)!='\0') {
     	ch=*(exp+i);
     	//printf("%c\n",ch);
     	//Aqu� ingresamos los brackets y parentesis necesarios
         if (ch=='(' || ch=='[') {
             pushStack(s, &*(exp+i));
         }

         if (ch==')' || ch==']') {
             //Caso en el que encuentre un bracket/par�ntesis solo
         	if (isEmptyStack(s)) {
                 return false;
             }
         	//Casos para determinar si el siguiente par�ntesis es correcto
             char temp = *((char *) topStack(s));
             if (ch==')' && temp != '('   ) {
             	return false;
             }else if(ch==']' && temp != '['){
             	return false;
             }
             popStack(s);
         }
         i++;
     }
     //Si la ejecuci�n es completada corractamente, este regresar� el valor true
     return true;
}

