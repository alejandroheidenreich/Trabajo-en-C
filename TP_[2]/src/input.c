
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"

int IngresarEntero(char mensaje[],int min,int max){
	int numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numero);
	while(numero <min || numero > max){
		printf("ERROR DATO INVALIDO (%d-%d) - ",min,max);
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numero);
	}

	return numero;

}

float IngresarFlotante(char mensaje[],int min,int max){
	float numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numero);
	while(numero <min || numero > max){
		printf("ERROR DATO INVALIDO (%d-%d) - ",min,max);
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numero);
	}

	return numero;

}


void IngresarCadena(char mensaje[], char cadena[]){
	int flagE=0;
	int largo;

	do{

		if(flagE){
			printf("ERROR DATO INVALIDO - ");
		}
		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);
		largo = strlen(cadena);
		if(cadena == NULL || largo <2){
			flagE=1;
		}
		else {
			for(int i=0; i<largo; i++){
				if((isdigit(cadena[i]) == 1 && cadena[i]!=32) || (cadena[i-1]==32 && cadena[i]==32) || (cadena[i-1]==32 && cadena[i]==32)  || (largo<5 && cadena[i]==32)){
					flagE=1;
					break;
				}
				else{
					flagE=0;
				}

			}
		}
	}while(flagE);

	CorreccionCadena(cadena);
}

void CorreccionCadena(char cadena[]){
	int largo;

	largo = strlen(cadena);

	strlwr(cadena);

	for(int i=0; i<largo;i++){

		if(i==0 || cadena[i-1]==32){
			cadena[i] = toupper(cadena[i]);
		}

	}
}

float CalcularPromedio(float numero, int divisor){
	float promedio;

	if(divisor !=0){
		promedio = numero / divisor;
	}
	else{
		promedio = -1;
	}

	return promedio;
}

void clear()
{

    system("cls");
    printf("\t\t\t\t==================================================\n");
    printf("\t\t\t\t||\t      Sistema de Empelados       \t||\n");
    printf("\t\t\t\t==================================================\n\n\n");
}
