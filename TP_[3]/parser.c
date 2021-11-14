#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

		int contador=0;
		int checkConvert;
		int verify;
		Employee* aux;
		char idStr[50];
		char nombreStr[50];
		char hsStr[50];
		char sueldoStr[50];
		int id,hs,sueldo;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,hsStr,sueldoStr);

		while(!feof(pFile)){
			checkConvert=0;
			aux = employee_new();
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,hsStr,sueldoStr);
			checkConvert+=CadenaAEntero(idStr, &id);
			checkConvert+=CadenaAEntero(hsStr, &hs);
			checkConvert+=CadenaAEntero(sueldoStr, &sueldo);

			if(strlen(nombreStr) != 0 && checkConvert==3){
				aux = employee_newArguments(id, nombreStr, hs, sueldo);
				if(aux != NULL){
					verify = ll_add(pArrayListEmployee,aux);
					if(verify){
						contador++;
					}
				}
			}
		}



    return contador;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int contador=0;
	int check;
	Employee* aux;

	if(pFile != NULL && pArrayListEmployee != NULL){
		while(!feof(pFile)){
			check = 0;
			aux = employee_new();
			fread(aux, sizeof(Employee), 1, pFile);
			if(feof(pFile)){
				break;
			}
			check = ll_add(pArrayListEmployee,aux);
			if(!check){
				contador++;
			}

		}
	}

    return contador;
}

