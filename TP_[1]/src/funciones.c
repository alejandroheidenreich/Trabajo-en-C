#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#include <unistd.h>
#define MAX 10


int Decimales(double n){
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

double PedirNumero(char mensaje[], char error[]){
	char pedido[MAX];
	int largo, fail;
	double resultado;

	do{
	printf("%s", mensaje);
	fflush(stdin);
	gets(pedido);

    largo = strlen(pedido);

    if(largo>8){
    	fail=1;
    	mensaje=error;
    }
    else{
		for (int i=0;i<largo;i++){

			if (!(isdigit(pedido[i]) || pedido[i] == 45 || pedido[i] == 46)){
				fail=1;
				mensaje=error;
				break;
			}
			fail=0;
		}
	}
	}while (fail);

	resultado = (float)atof(pedido);

	return resultado;
}

int Factorial(double numero,double *factorial){
    int fact=0,decimal;

    decimal = Decimales(numero);


    if(decimal == 0 && numero > 0){ // && numero <= 170
    	 if(numero > 170){
    		 fact=-1;
    	 }
    	 else{
    		 fact=1;
    		 for(int i=(numero-1); i > 1 ; i--){
    			 numero *= i;
    		 }

    		 *factorial = numero;
    	 }

    }

    return fact;
}


double Suma(double a, double b){
	double suma;
	suma = a+(b);
	return suma;
}

double Resta(double a, double b){
	double resta;
	resta = a-(b);
	return resta;
}

int Division(double a, double b, double* division){
	int divisionF=0;
	if(b == 0){
		divisionF=1;
	}
	else{
		*division = a/(b);
	}

	return divisionF;
}

double Multiplicacion(double a, double b){
	double multiplicacion;
	multiplicacion = a*(b);
	return multiplicacion;
}

