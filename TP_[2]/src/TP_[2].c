/*
 ============================================================================
Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
Datos:
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.
Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees” que
facilitará el manejo de la lista de empleados y su modificación. En la sección siguiente se
detallan las funciones que esta biblioteca debe tener.
 ============================================================================
 Alejandro Heidenreich
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "ExtraEmployees.h"
#include "input.h"
#define EMP 1000


int main(void) {
	setbuf(stdout,NULL);
	Employee listaEmpleados[EMP];
	Employee unEmpleado;
	int opcion;
	int flagCarga=0;
	int verify;
	int idIngresado;
	int idVerify=1;
	int cantidadEmpleados = 0;
	float salarioTotal;
	float salarioPromedio;


	initEmployees(listaEmpleados, EMP);

	clear();

	system("pause");


	do{
		clear();
		printf("==================================\n");
		printf("|| Menu de Control de Empleados ||\n");
		printf("==================================\n\n");

		printf("\t1- ALTAS\n\t2- MODIFICAR\n\t3- BAJAS\n\t4- INFORMAR\n\t5- SALIR\n\n\n\t");

		opcion = IngresarEntero("Ingrese una opcion: ",1,5);

		switch(opcion){
		case 1:
			clear();
			printf("==================================\n");
			printf("||       Alta de Empleados      ||\n");
			printf("==================================\n\n");
			unEmpleado = CrearEmployee(idVerify);
			verify = addEmployee(listaEmpleados, EMP, unEmpleado.id, unEmpleado.name,unEmpleado.lastName,unEmpleado.salary,unEmpleado.sector);
			if(verify==-1){
				printf("Error: Empleado Vacio\n");
			}
			else{
				idVerify = unEmpleado.id+1;
				flagCarga=1;
			}
			system("pause");
			break;

		case 2:
			clear();
			printf("==================================\n");
			printf("||   Modificacion de Empleados  ||\n");
			printf("==================================\n\n");
			if(flagCarga!=0){
				verify = ModifyEmployee(listaEmpleados, EMP);
				if(verify){
					clear();
					printf("Empleado Modificado\n");
				}
			}
			else{
				printf("Ningun empleado ha sido dado de alta.\n");
			}
			system("pause");
			break;

		case 3:
			clear();
			printf("==================================\n");
			printf("||       Baja de Empleados      ||\n");
			printf("==================================\n\n");
			if(flagCarga!=0){
				idIngresado = IngresarEntero("\n\tIngrese la ID del empleado: ",1,1000);
				verify = findEmployeeById(listaEmpleados, EMP, idIngresado);
				MostrarUnEmployees(listaEmpleados, verify);
				printf("\t1- DAR DE BAJA\n\t2- CANCELAR\n\n");
				opcion = IngresarEntero("\n\tIngrese una opcion: ",1,2);
				if(opcion==1){
					verify = removeEmployee(listaEmpleados, EMP, idIngresado);
					if(verify==0){
						printf("Empleado con ID (%d) fue dado de baja\n", idIngresado);
					}
				}
				else{
					system("pause");
					break;
				}

			}
			else{
				printf("Ningun empleado ha sido dado de alta.\n");
			}
			verify = VerificarEmpleadoCargado(listaEmpleados, EMP);
			if(verify==1){
				flagCarga=0;
			}
			system("pause");
			break;

		case 4:
			do{
			clear();
			printf("==================================\n");
			printf("||      Informe de Empleados    ||\n");
			printf("==================================\n\n");
			printf("\t1- LISTADO DE EMPLEADOS\n\t2- INFORME DE SALARIOS\n\t3- ATRAS\n\n");
			opcion = IngresarEntero("\n\tIngrese una opcion: ",1,3);
			switch (opcion){
				case 1:
					if(flagCarga!=0){
						clear();
						printf("==================================\n");
						printf("||      Listado de Empleados    ||\n");
						printf("==================================\n\n");
						printf("\tORDENAR EMPLEADOS\n");
						printf("\t1- ASCENDENTE\n\t2- DESCENDENTE:\n");
						opcion = IngresarEntero("\n\tIngrese una opcion: ",1,2);
						if(opcion==2){
							opcion=0;
						}
						sortEmployees(listaEmpleados, EMP, opcion);
						printEmployees(listaEmpleados, EMP);

					}
					else{
						printf("Ningun empleado ha sido dado de alta.\n");
					}

					system("pause");
					break;

				case 2:
					if(flagCarga!=0){
						clear();
						printf("==================================\n");
						printf("||      Informe de Salarios     ||\n");
						printf("==================================\n\n");
						salarioTotal = TotalSalarios(listaEmpleados, EMP, &cantidadEmpleados);
						printf("\tSALARIO TOTAL: ");
						printf("$%.2f\n",salarioTotal);
						salarioPromedio = CalcularPromedio(salarioTotal, cantidadEmpleados);
						printf("\tPROMEDIO SALARIAL: ");
						printf("$%.2f\n",salarioPromedio);
						printf("\tEMPLEADOS QUE SUPERAN EL PROMEDIO SALARIAL:\n");
						EmpleadosSalariosMayores(listaEmpleados, EMP, salarioPromedio);
					}
					else{
						printf("Ningun empleado ha sido dado de alta.\n");
					}
					system("pause");
					break;

				}
			}while(opcion!=3);
			system("pause");
			break;
		}

	}while(opcion!=5);


	return EXIT_SUCCESS;
}

