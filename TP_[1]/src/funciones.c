#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#include <unistd.h>
#define MAX 100


int Decimales(float n){
	int decimales = 0;
	int entero;
	entero = (int)n;
	n -= entero;

	while (n != 0){
	    n *= 10;
	    decimales++;
	    entero = (int)n;
	    n -= entero;
	}
	return decimales;
}

float PedirNumero(char mensaje[], char error[]){
	char pedido[MAX];
	int largo, fail;
	float resultado;

	do{
	printf("%s", mensaje);
	fflush(stdin);
	gets(pedido);

    largo = strlen(pedido);

    for (int i=0;i<largo;i++){

    	if (isdigit(pedido[i])){
    		fail=0;
        }
        else{
        	fail=1;
        	mensaje=error;
        }
    }
	}while (fail);

	resultado = (float)atof(pedido);

	return resultado;
}


long int Factorial(float n){
	int  decimal;
	long int fact, numero;

	fact=0;

	decimal = Decimales(n);

	if(decimal == 0 && n > 0){
		numero = (long int)n;
		if(numero == 1){
		fact = 1;
		}
		else{
			fact = numero * Factorial(numero-1);
		}
	}
	return fact;

}

float Suma(float a, float b){
	float suma;
	suma = a+b;
	return suma;
}

float Resta(float a, float b){
	float resta;
	resta = a-b;
	return resta;
}

int Division(float a, float b, float* division){
	int divisionF=0;
	if(b == 0){
		divisionF=1;
	}
	else{
		*division = a/b;
	}

	return divisionF;
}

float Multiplicacion(float a, float b){
	float multiplicacion;
	multiplicacion = a*b;
	return multiplicacion;
}

