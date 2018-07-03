///Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>
#include "StQueue.h"

#define MAX 20
//Variables Globales y nuevos tipos de datos
bool balancedBrackets(char *);
//prototipos de funciones
//Función principal
int main() {
	//Configurando el buffer de salida
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	//Declaración de variables
	char exp[MAX];
	int BOOL;
	printf("Ingrese una expresión aritmética: ");
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
    //dentro de la variable s se almacenan los brackets y paréntesis orientados hacia la derecha
 	Stack s = createStack();
     char ch;
     int i = 0;
     while (*(exp+i)!='\0') {
     	ch=*(exp+i);
     	//printf("%c\n",ch);
     	//Aquí ingresamos los brackets y parentesis necesarios
         if (ch=='(' || ch=='[') {
             pushStack(s, &*(exp+i));
         }

         if (ch==')' || ch==']') {
             //Caso en el que encuentre un bracket/paréntesis solo
         	if (isEmptyStack(s)) {
                 return false;
             }
         	//Casos para determinar si el siguiente paréntesis es correcto
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
     //Si la ejecución es completada corractamente, este regresará el valor true
     return true;
}

