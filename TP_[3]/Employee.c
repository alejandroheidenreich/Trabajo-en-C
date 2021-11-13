#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <ctype.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new(){
	Employee* unEmpleado;

	unEmpleado = (Employee*)malloc(sizeof(Employee));

	return unEmpleado;
}

//Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
//	Employee* unEmpleado;
//
//	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){
//
//		unEmpleado->id = atoi(idStr);
//		strcpy(unEmpleado->nombre, nombreStr);
//		unEmpleado->horasTrabajadas = atoi(horasTrabajadasStr);
//		unEmpleado->sueldo = atoi(sueldoStr);
//	}
//
//	return unEmpleado;
//}

void employee_mostrar(Employee* this){

	if(this!=NULL){
		printf("| %5d | %20s | %5d | %10d |\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
	}
}

Employee* employee_newArguments(int id, char* nombre, int hs, int sueldo){
	Employee* unEmpleado;
	unEmpleado = employee_new();

	if(unEmpleado != NULL){
		employee_setId(unEmpleado,id);
		employee_setNombre(unEmpleado,nombre);
		employee_setHorasTrabajadas(unEmpleado,hs);
		employee_setSueldo(unEmpleado, sueldo);
	}


	return unEmpleado;
}

Employee CrearEmployee(int id){
	Employee unEmpleado;

	if(id>0){

		unEmpleado.id = id;
		IngresarCadena("Ingrese Nombre del Empleado: ", unEmpleado.nombre);
		printf("\n");
		unEmpleado.horasTrabajadas = IngresarEntero("Ingrese Horas Trabajadas del Empleado: ", 1,10000);
		printf("\n");
		unEmpleado.sueldo = IngresarEntero("Ingrese Sueldo del Empleado: ", 1,100000);
		printf("\n");

	}

	return unEmpleado;
}

int ModifyEmployee(Employee* unEmpleado){

	int check=0;
	int opcion;


	do{

		employee_mostrar(unEmpleado);
		printf("\n\tQue dato desea modificar?\n");
		printf("\t1- NOMBRE\n\t2- HORAS TRABAJADAS\n\t3- SALARIO\n\t4- ATRAS\n\n");
		opcion = IngresarEntero("\n\tIngrese una opcion: ",1,4);
		switch(opcion){
			case 1:
				IngresarCadena("Modifique Nombre del Empleado: ", unEmpleado->nombre);
				check=1;
				break;

			case 2:
				unEmpleado->horasTrabajadas = IngresarEntero("Modifique las Horas Trabajasdas del Empleado: ", 1,10000);
				check=1;
				break;

			case 3:
				unEmpleado->sueldo = IngresarEntero("Modifique el salario del Empleado: ", 1,1000000);
				check=1;
				break;
		}
	}while(opcion!=4);


	return check;
}

int OrdenarPorIDEmployee(void* empleado1, void* empleado2){
	int check;
	Employee* unEmpleado;
	Employee* otroEmpleado;


	if(empleado1!=NULL && empleado2!=NULL){
		check=0;
		unEmpleado = (Employee*)empleado1;
		otroEmpleado = (Employee*)empleado2;

		if(unEmpleado->id < otroEmpleado->id){
			check = -1;
		}
		else if(unEmpleado->id > otroEmpleado->id){
			check = 1;
		}
	}

	return check;
}

int OrdenarPorNombreEmployee(void* empleado1, void* empleado2){
	int check;
	Employee* unEmpleado;
	Employee* otroEmpleado;


	if(empleado1!=NULL && empleado2!=NULL){
		unEmpleado = (Employee*)empleado1;
		otroEmpleado = (Employee*)empleado2;

		check = strcmp(unEmpleado->nombre,otroEmpleado->nombre);
	}

	return check;
}

int OrdenarPorHorasTrabajadasEmployee(void* empleado1, void* empleado2){
	int check;
	Employee* unEmpleado;
	Employee* otroEmpleado;


	if(empleado1!=NULL && empleado2!=NULL){
		check=0;
		unEmpleado = (Employee*)empleado1;
		otroEmpleado = (Employee*)empleado2;

		if(unEmpleado->horasTrabajadas < otroEmpleado->horasTrabajadas){
			check = -1;
		}
		else if(unEmpleado->horasTrabajadas > otroEmpleado->horasTrabajadas){
			check = 1;
		}
	}

	return check;
}

int OrdenarPorSueldoEmployee(void* empleado1, void* empleado2){
	int check;
	Employee* unEmpleado;
	Employee* otroEmpleado;


	if(empleado1!=NULL && empleado2!=NULL){
		check=0;
		unEmpleado = (Employee*)empleado1;
		otroEmpleado = (Employee*)empleado2;

		if(unEmpleado->sueldo < otroEmpleado->sueldo){
			check = -1;
		}
		else if(unEmpleado->sueldo > otroEmpleado->sueldo){
			check = 1;
		}
	}

	return check;
}


void employee_delete(Employee* this){
		free(this);
}

int employee_setId(Employee* this,int id){
	int check=0;
	if(this!=NULL){
		check=1;
		this->id=id;
	}
	return check;
}
int employee_getId(Employee* this,int* id){
	int check=0;
	if(this!=NULL){
			check=1;
			*id=this->id;
	}
	return check;
}

int employee_setNombre(Employee* this,char* nombre){
	int check=0;

	if(this!=NULL){
		check=1;
		strcpy(this->nombre,nombre);
	}

	return check;
}

int employee_getNombre(Employee* this,char* nombre){
	int check=0;

	if(this!=NULL){
		check=1;
		strcpy(nombre,this->nombre);
	}
	return check;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int check=0;

	if(this!=NULL){
		check=1;
		this->horasTrabajadas=horasTrabajadas;
	}

	return check;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int check=0;

	if(this!=NULL){
		check=1;
		*horasTrabajadas=this->horasTrabajadas;
	}

	return check;
}

int employee_setSueldo(Employee* this,int sueldo){
	int check=0;

	if(this!=NULL){
		check=1;
		this->sueldo=sueldo;
	}

	return check;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int check=0;

	if(this!=NULL){
		check=1;
		*sueldo=this->sueldo;
	}

	return check;
}

