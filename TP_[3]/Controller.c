#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_setIDUpdate(char* path, int idEmpleado)
{
	int check = 0;
	char aux[100];

	FILE* pFile;
	if(path != NULL && idEmpleado != -1){
		pFile = fopen(path, "w");

		sprintf(aux,"%d",idEmpleado);

		if(pFile!=NULL){
			fprintf(pFile,"%s",aux);
			//fwrite(&idEmpleado, sizeof(int), 1, pFile);
			check = 1;
			//printf("Creaste el archivo ID\n");
		}

		fclose(pFile);
	}
    return check;
}

int controller_loadID(char* path){
	int id = -1;
	char aux[100];

	FILE* pFile;

	if(path != NULL){
	pFile = fopen(path, "r");

		if(pFile!=NULL){
			fread(&aux, sizeof(aux), 1, pFile);

		}

		fclose(pFile);

		id=atoi(aux);
	}

    return id;
}

int controller_findEmployee(LinkedList* pArrayListEmployee)
{
	int i, largo, id;

	Employee* aux = employee_new();

	if(pArrayListEmployee != NULL){
		largo = ll_len(pArrayListEmployee);

		id = IngresarEntero("Ingrese el ID del Empleado: ", 1,100000);

		for(i=0; i<largo; i++){
			aux = ll_get(pArrayListEmployee,i);

			if(id == aux->id){
				break;
			}

		}

		if(i==largo){
			i = -1;
		}
	}
    return i;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int check=0;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL){
		pFile = fopen(path, "r");

		if(pFile!=NULL){
			ll_clear(pArrayListEmployee);
			check=parser_EmployeeFromText(pFile,pArrayListEmployee);
		}

		fclose(pFile);
	}
    return check;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int check = 0;
	int verify;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL){
		pFile = fopen(path, "rb");
		if(pFile!=NULL){
			ll_clear(pArrayListEmployee);
			verify=parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			if(verify){
				check = 1;
			}
		}

		fclose(pFile);
	}

    return check;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int check=0;
	Employee* aux;
	int idEmpleado;
	Employee unCliente;

	if(pArrayListEmployee != NULL){
		idEmpleado=controller_loadID("id.csv");

		if(idEmpleado != -1){
			check=1;
			unCliente = CrearEmployee(idEmpleado);
			aux=employee_newArguments(unCliente.id, unCliente.nombre, unCliente.horasTrabajadas, unCliente.sueldo);
			ll_add(pArrayListEmployee,aux);
		}
	}
    return check;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int pos;
	int check=0;
	Employee* aux;

	if(pArrayListEmployee != NULL){
		pos = controller_findEmployee(pArrayListEmployee);

		if(pos!=-1){

			aux = (Employee*) ll_get(pArrayListEmployee, pos);
			check = ModifyEmployee(aux);
			if(check==1){

				ll_set(pArrayListEmployee, pos, aux);
			}

		}
	}
    return check;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int pos;
	int check=0;
	Employee* aux;

	if(pArrayListEmployee != NULL){
		pos = controller_findEmployee(pArrayListEmployee);
		if(pos!=-1){
			check=1;
			aux = (Employee*) ll_get(pArrayListEmployee, pos);
			ll_remove(pArrayListEmployee,pos);
			employee_delete(aux);
		}
	}
	return check;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int check=0;
	int largo;
	Employee* aux=employee_new();

	if(pArrayListEmployee != NULL){
		largo = ll_len(pArrayListEmployee);
		printf("=====================================================\n");
		printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
		printf("=====================================================\n");
		for(int i=0; i<largo; i++){
			aux = (Employee*) ll_get(pArrayListEmployee, i);
			employee_mostrar(aux);
		}
		printf("=====================================================\n");
	}
    return check;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int opcion;
	int check=0;
	int verify;
	int orden;

	if(pArrayListEmployee != NULL){
		do{
			printf("\n\tComo desea ordenar la lista?\n");
			printf("\t1- ID\n\t2- NOMBRE\n\t3- HORAS TRABAJADAS\n\t4- SALARIO\n\n");
			opcion = IngresarEntero("\n\tIngrese una opcion: ",1,5);
			if(opcion != 5){
				printf("\t1- ASCENDENTE\n\t2- DESCENDENTE\n\n");
				orden = IngresarEntero("\n\tIngrese una opcion: ",1,2);
				if(orden!=1){
					orden=0;
				}
				printf("\n\tOrdenando la lista, porfavor espere...\n");
				switch(opcion){
					case 1:
						verify = ll_sort(pArrayListEmployee, OrdenarPorIDEmployee, orden);
						if(verify){
							check=1;
						}
						break;

					case 2:
						verify = ll_sort(pArrayListEmployee, OrdenarPorNombreEmployee, orden);
						if(verify){
							check=2;
						}

						break;

					case 3:
						verify = ll_sort(pArrayListEmployee, OrdenarPorHorasTrabajadasEmployee, orden);
						if(verify){
							check=3;
						}
						break;
					case 4:
						verify = ll_sort(pArrayListEmployee,OrdenarPorSueldoEmployee, orden);
						if(verify){
							check=4;
						}
						break;
				}
			}
		}while(check!=0);
	}
    return check;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int check = 0;
	int largo;

	FILE* pFile;
	Employee* aux;

	if(path != NULL && pArrayListEmployee != NULL){
		largo = ll_len(pArrayListEmployee);

		pFile = fopen(path, "w");

		if(pFile!=NULL){
			fprintf(pFile,"ID,Nombre,HorasTrabajadas,Salario\n");
			for(int i=0;i<largo;i++){
				//validar
				// pasar a string
				aux=(Employee*)ll_get(pArrayListEmployee,i);
				if(aux != NULL){
					fprintf(pFile,"%d,%s,%d,%d\n",aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
				}
			}
			check = 1;
		}
		fclose(pFile);
	}
    return check;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int check = 0;
	int largo;

	FILE* pFile;
	Employee* aux;

	if(path != NULL && pArrayListEmployee != NULL){
		largo = ll_len(pArrayListEmployee);

		pFile = fopen(path, "wb");

		if(pFile!=NULL){

			for(int i=0;i<largo;i++){
				aux=(Employee*)ll_get(pArrayListEmployee,i);
				fwrite(aux, sizeof(Employee), 1, pFile);
			}
			check = 1;
		}
		fclose(pFile);
	}
    return check;
}



