#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

Employee* employee_new(); // usado
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

Employee* employee_newArguments(int id, char* nombre, int hs, int sueldo);
Employee CrearEmployee(int id);

int ModifyEmployee(Employee* unEmpleado);

int OrdenarPorIDEmployee(void* empleado1, void* empleado2);

int OrdenarPorNombreEmployee(void* empleado1, void* empleado2);

int OrdenarPorHorasTrabajadasEmployee(void* empleado1, void* empleado2);

int OrdenarPorSueldoEmployee(void* empleado1, void* empleado2);

void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);// usado
int employee_getId(Employee* this,int* id);// usado

int employee_setNombre(Employee* this,char* nombre);// usado
int employee_getNombre(Employee* this,char* nombre);// usado

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);// usado
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);// usado

int employee_setSueldo(Employee* this,int sueldo);// usado
int employee_getSueldo(Employee* this,int* sueldo);// usado

void employee_mostrar(Employee* this);// usado
#endif // employee_H_INCLUDED
