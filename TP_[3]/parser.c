#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <ctype.h>
#include <string.h>
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
		int verify;
		Employee* aux;
		char idStr[50];
		char nombreStr[50];
		char hsStr[50];
		char sueldoStr[50];
		int id,hs,sueldo;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,hsStr,sueldoStr);

		while(!feof(pFile)){
			aux = employee_new();
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,hsStr,sueldoStr);
			if(CadenaAEntero(idStr, &id)==1 && CadenaAEntero(hsStr, &hs)==1 && CadenaAEntero(sueldoStr, &sueldo)==1){
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
	int check=0;
	Employee* aux;

	if(pFile != NULL && pArrayListEmployee != NULL){
		while(!feof(pFile)){
			check=1;
			aux = employee_new();
			fread(aux, sizeof(Employee), 1, pFile);
			if(feof(pFile)){
				break;
			}

			check=ll_add(pArrayListEmployee,aux);
		}
	}


    return check;
}

