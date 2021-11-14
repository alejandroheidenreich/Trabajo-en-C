#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    //int flagCarga=0;
    int flagSave=0;
    int flagCarga=0;
    int idEmpleado=1;
    int exit=0;
    int verify;
    LinkedList* listaEmpleados = ll_newLinkedList();


    do{
    	clear();
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    	printf("3. Alta de empleado\n");
    	printf("4. Modificar datos de empleado\n");
    	printf("5. Baja de empleado\n");
    	printf("6. Listar empleados\n");
    	printf("7. Ordenar empleados\n");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    	printf("10. Salir\n");

    	option = IngresarEntero("Ingrese una opcion\n",1,10);
        switch(option){
            case 1:
            	idEmpleado=controller_loadFromText("data.csv",listaEmpleados);
            	if(idEmpleado!=0){
            		printf("Data cargada desde texto\n");
            		controller_setIDUpdate("id.csv", idEmpleado);
            		flagCarga=1;
            	}
            	else{
            		printf("Error en la carga desde texto\n");
            	}
            	system("pause");
                break;
            case 2:
            	idEmpleado=controller_loadFromBinary("data.bin",listaEmpleados);
            	if(idEmpleado != 0){
            		printf("Data cargada desde binario\n");
            		controller_setIDUpdate("id.csv", idEmpleado);
            		flagCarga=1;
            	}
            	else{
            		printf("Error en la carga desde Binario\n");
            	}
            	system("pause");
                break;
            case 3:
            	verify = controller_addEmployee(listaEmpleados);
            	if(verify){
            		idEmpleado++;
            		controller_setIDUpdate("id.csv", idEmpleado);
            		flagSave=0;
            		flagCarga=1;
            	}
            	system("pause");
            	break;
            case 4:
            	if(flagCarga==1){
					verify=controller_editEmployee(listaEmpleados);
					if(verify){
						printf("Empleado nodificado");
						flagSave=0;
					}
            	}
            	else{
            		printf("No hay empleados cargados");
            	}
            	system("pause");
            	break;
            case 5:
            	if(flagCarga==1){
					verify=controller_removeEmployee(listaEmpleados);
					if(verify){
						printf("Empleado dado de baja\n");
						flagSave=0;
					}
            	}
            	else{
            		printf("No hay empleados cargados");
            	}
            	system("pause");
            	break;
            case 6:
            	if(flagCarga==1){
					printf("Lista de Empleados\n");
					controller_ListEmployee(listaEmpleados);
            	}
            	else{
            		printf("No hay empleados cargados");
            	}
            	system("pause");
            	break;
            case 7:
            	if(flagCarga==1){
					verify=controller_sortEmployee(listaEmpleados);
					if(verify==1){
						printf("Lista de Empleados Ordenada por ID\n");
					}
					else if(verify==2){
						printf("Lista de Empleados Ordenada por Nombre\n");
					}
					else if(verify==3){
						printf("Lista de Empleados Ordenada por Horas Trabajadas\n");
					}
					else if(verify==4){
						printf("Lista de Empleados Ordenada por Sueldo\n");
					}
					else{
						printf("La Lista de Empleados no ha sido Ordenada\n");
					}
            	}
            	else{
            		printf("No hay empleados cargados");
            	}
            	system("pause");
            	break;
            case 8:
            	if(flagCarga==1){
            		verify=controller_saveAsText("data.csv",listaEmpleados);
					if(verify){
						 printf("Archivo guardado como texto\n");
						 controller_setIDUpdate("id.csv", idEmpleado);
						 flagSave=1;
					}
            	}
            	else{
            		printf("No hay empleados cargados");
            	}
                 system("pause");
                 break;
            case 9:
            	if(flagCarga==1){
					verify=controller_saveAsBinary("data.bin",listaEmpleados);
					if(verify){
						printf("Archivo guardado como binario\n");
						controller_setIDUpdate("id.csv", idEmpleado);
						flagSave=1;
					}
            	}
            	else{
            		printf("No hay empleados cargados");
            	}
            	system("pause");
            	break;
            case 10:
            	if(flagSave){
            		exit=1;
            	}
            	else{
            		printf("Cambios no guardados, desea salir igualmente?\n1-SI\n2-NO\n");
            		option = IngresarEntero("Ingrese una opcion\n",1,2);
            		switch(option){
            			case 1:
            				exit=1;
            				break;
            		}
            	}
            	system("pause");
            	break;
        }
    }while(exit == 0);

    return 0;
}

