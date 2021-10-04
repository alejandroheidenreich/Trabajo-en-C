/*
 * func.c
 *
 *  Created on: 27 sep. 2021
 *      Author: tentative
 */
#include "ArrayEmployees.h"
#include "ExtraEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"


int initEmployees(Employee* list, int len)
{
	int check=-1;

	if(!(list == NULL || len>1000 || len<1)){
		check = 0;
		for(int i=0; i<len; i++){
			list[i].isEmpty = 1;
		}
	}


	return check;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int check = -1;

	if(list != NULL && (len<1000 || len>1)){
		check = 0;
		for(int i=0; i<len; i++){
			if(list[i].isEmpty==1){

				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = 0;
				break;
			}
		}
	}
    return check;
}

int findEmployeeById(Employee* list, int len, int id)
{
	int i = -1;

		if(list != NULL && (len<1000 || len>1)){
			i = 0;
			for(i=0; i<len; i++){
				if(list[i].id==id){
					break;
				}
			}
		}

    return i;
}

int removeEmployee(Employee* list, int len, int id)
{
	int check = -1;

	if(list != NULL && (len<1000 || len>1)){
		check = 0;
		for(int i=0; i<len; i++){
			if(list[i].id==id){
				list[i].isEmpty=1;
				break;
			}
		}
	}

	return check;
}

int sortEmployees(Employee* list, int len, int order)
{
	int check = -1;
	Employee aux;
	if(list != NULL && (len<1000 || len>1)){
		check = 0;
		for(int i=0; i<len; i++){
			for(int j=0; j<len; j++){

				if(order==1 && list[i].isEmpty==0 && ((strcmp(list[i].lastName,list[j].lastName)<0)  || (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector > list[j].sector))){
					aux = list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				if(order==0 && list[i].isEmpty==0 && ((strcmp(list[i].lastName,list[j].lastName)>0) || (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector < list[j].sector))){
					aux = list[i];
					list[i]=list[j];
					list[j]=aux;
				}

			}
		}
	}

    return check;
}

int printEmployees(Employee* list, int length)
{
	printf("\t\t=========================================================================\n");
	printf("\t\t| ID |		NOMBRE	   |	APELLIDO	 |   SALARIO   | SECTOR |\n");
	printf("\t\t=========================================================================\n");
	for(int i=0; i<length-1; i++){
		if(list[i].isEmpty==0){
		printf("\t\t|%4d| %20s| %20s| $ %-10.2f| %-7d|\n", list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
		printf("\t\t=========================================================================\n");
		}
	}

    return 0;
}
