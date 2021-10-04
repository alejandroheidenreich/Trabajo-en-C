
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#define MAX 1000

int PedirValidoNumeroEntero(char mensaje[], char error[]){
	char pedido[MAX];
	int largo, fail;
	int resultado;

	do{
		printf("%s", mensaje);
		fflush(stdin);
		gets(pedido);

		largo = strlen(pedido);

		for (int i=0;i<largo;i++){


			if (!(isdigit(pedido[i]))){
				fail=1;
				printf("%s",error);
				break;
			}
			else{
				fail=0;
			}
		}

	} while (fail==1);

	resultado = atoi(pedido);

	return resultado;
}

float PedirValidoNumeroFlotante(char mensaje[], char error[]){
	char pedido[MAX];
	int largo, fail;
	float resultado;

	do{
		printf("%s", mensaje);
		fflush(stdin);
		gets(pedido);

		largo = strlen(pedido);

		for (int i=0;i<largo;i++){


			if (!(isdigit(pedido[i]))){
				fail=1;
				printf("%s",error);
				break;
			}
			else{
				fail=0;
			}
		}

	} while (fail==1);

	resultado = atof(pedido);

	return resultado;
}


int IngresarEntero(char mensaje[],int min,int max){
	int numero;


	numero = PedirValidoNumeroEntero(mensaje,"ERROR DATO INVALIDO - ");

	while(numero <min || numero > max){
		printf("ERROR DATO INVALIDO (%d-%d) - ",min,max);

		numero = PedirValidoNumeroEntero(mensaje,"ERROR DATO INVALIDO - ");
	}

	return numero;

}

float IngresarFlotante(char mensaje[],int min,int max){
	float numero;

	numero = PedirValidoNumeroFlotante(mensaje, "ERROR DATO INVALIDO - ");
	while(numero <min || numero > max){
		printf("ERROR DATO INVALIDO (%d-%d) - ",min,max);
		numero = PedirValidoNumeroFlotante(mensaje, "ERROR DATO INVALIDO - ");
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
