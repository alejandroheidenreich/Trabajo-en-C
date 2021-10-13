
#ifndef EXTRAEMPLOYEES_H_
#define EXTRAEMPLOYEES_H_
#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

/// @fn Employee CrearEmployee(int)
/// @param id recibe como argumento la id del empleado
/// se cargan todos los campos de la estructura Employee
/// @return de vuelve un empleado como estructura
Employee CrearEmployee(int id);

/// @fn void MostrarUnEmployees(Employee[], int)
/// @param employee recibe un array de la estructura Employee
/// @param pos recibe la posicion del array
/// imprime en array en la posicion recibida
void MostrarUnEmployees(Employee employee[], int pos);

/// @fn int ModifyEmployee(Employee*, int)
/// @param list recibe un array de la estructura Employee
/// @param len recibe el largo del array pasado por putero
/// @return pide al usuario la ID del empleado y cambia el valor del campo isEmpty a true
int ModifyEmployee(Employee* list, int len);

/// @fn float TotalSalarios(Employee*, int, int*)
/// @param list recibe un array de la estructura Employee
/// @param len recibe el largo del array
/// @param cantidadEmpleados recibe un entero como puntero la cantidad de empleados activos
/// @return devuelve el total de la suma de los salarios de los empleados
float TotalSalarios(Employee* list, int len, int* cantidadEmpleados);

/// @fn int EmpleadosSalariosMayores(Employee*, int, float)
/// @param list recibe un array de la estructura Employee
/// @param len recibe el largo del array
/// @param salario recibe un float como salario promedio
/// muestra los empleados que superan el salario
void EmpleadosSalariosMayores(Employee* list, int len, float salario);

/// @fn int VerificarEmpleadoCargado(Employee*, int)
/// @param list recibe un array de la estructura Employee
/// @param len recibe el largo del array
/// @return devuelve 0 si no todos los valores del campo isEmpty son 0, en caso contrario 1
int VerificarEmpleadoCargado(Employee* list, int len);

#endif /* EXTRAEMPLOYEES_H_ */
