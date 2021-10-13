#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

void MostrarUnEmployees(Employee employee[], int pos)
{
		if(employee[pos].isEmpty!=1){
			printf("\t\t=========================================================================\n");
			printf("\t\t| ID |		NOMBRE	   |	APELLIDO	 |   SALARIO   | SECTOR |\n");
			printf("\t\t=========================================================================\n");
			printf("\t\t|%4d| %20s| %20s| $ %-10.2f| %-7d|\n", employee[pos].id,employee[pos].name,employee[pos].lastName,employee[pos].salary,employee[pos].sector);
			printf("\t\t=========================================================================\n");
		}
		else{
			printf("El campo esta vacio.\n");
		}

}

Employee CrearEmployee(int id){
	Employee unEmpleado;

	if(id<0){

		unEmpleado.id = id;
		IngresarCadena("Ingrese Nombre del Empleado: ", unEmpleado.name);
		printf("\n");
		IngresarCadena("Ingrese Apellido del Empleado: ", unEmpleado.lastName);
		printf("\n");
		unEmpleado.salary = IngresarFlotante("Ingrese Salario del Empleado: ", 1,10000000);
		printf("\n");
		unEmpleado.sector = IngresarEntero("Ingrese Sector del Empleado: ", 1,1000);
		printf("\n");


	}

	return unEmpleado;
}

int ModifyEmployee(Employee* list, int len){
	int check=0;
	int id;
	int posEmpleado;
	int opcion;

	id=IngresarEntero("Ingrese ID del Empleado: ", 1,999999999);

	posEmpleado = findEmployeeById(list, len, id);

	if(posEmpleado  == -1 || list[posEmpleado].isEmpty==1 ){
		printf("ERROR - Empleado no encontrado\n");
	}
	else{
		do{
		clear();
		printf("==================================\n");
		printf("||   Modificacion de Empleados  ||\n");
		printf("==================================\n\n");
		MostrarUnEmployees(list, posEmpleado);
		printf("\n\tQue dato desea modificar?\n");
		printf("\t1- NOMBRE\n\t2- APELLIDO\n\t3- SALARIO\n\t4- SECTOR\n\t5- ATRAS\n\n");
		opcion = IngresarEntero("\n\tIngrese una opcion: ",1,5);
		switch(opcion){
			case 1:
				IngresarCadena("Modifique Nombre del Empleado: ", list[posEmpleado].name);
				check=1;
				break;

			case 2:
				IngresarCadena("Modifique Apellido del Empleado: ", list[posEmpleado].lastName);
				check=1;
				break;

			case 3:
				list[posEmpleado].salary = IngresarFlotante("Modifique Salario del Empleado: ", 1,100000);
				check=1;
				break;

			case 4:
				list[posEmpleado].salary = IngresarEntero("Modifique Sector del Empleado: ", 1,100);
				check=1;
				break;
		}
		}while(opcion!=5);
	}

	return check;
}

float TotalSalarios(Employee* list, int len, int* cantidadEmpleados){
	float total=0;
	int cantidad=0;

	for(int i=0; i<len; i++){
		if(list[i].isEmpty==0){
			cantidad++;
			total = total + list[i].salary;
		}
	}

	*cantidadEmpleados = cantidad;
	return total;
}

void EmpleadosSalariosMayores(Employee* list, int len, float salario){

	for(int i=0; i<len ; i++){
		if(list[i].salary > salario && list[i].isEmpty !=1){
			MostrarUnEmployees(list, i);
		}
	}


}


