#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

/// @fn Employee employee_new*()
/// crea un puntero de employee con "malloc"
/// @return
Employee* employee_new();

/// @fn Employee employee_newArguments*(int, char*, int, int)
/// @param id
/// @param nombre
/// @param hs
/// @param sueldo
/// setea los campos de un employee por puntero
/// @return
Employee* employee_newArguments(int id, char* nombre, int hs, int sueldo);

/// @fn Employee CrearEmployee(int)
/// @param id
/// el usuario carga los campos de un employee
/// @return
Employee CrearEmployee(int id);

/// @fn int ModifyEmployee(Employee*)
/// @param unEmpleado
/// permite al usuario modificar los campo de un empleado requiriendo su ID
/// @return
int ModifyEmployee(Employee* unEmpleado);

/// @fn int OrdenarPorIDEmployee(void*, void*)
/// @param empleado1
/// @param empleado2
/// compara las id de 2 empleados
/// @return
int OrdenarPorIDEmployee(void* empleado1, void* empleado2);

/// @fn int OrdenarPorNombreEmployee(void*, void*)
/// @param empleado1
/// @param empleado2
/// compara los nombres de 2 empleados
/// @return
int OrdenarPorNombreEmployee(void* empleado1, void* empleado2);

/// @fn int OrdenarPorHorasTrabajadasEmployee(void*, void*)
/// @param empleado1
/// @param empleado2
/// compara las horas trabajadas de 2 empleados
/// @return
int OrdenarPorHorasTrabajadasEmployee(void* empleado1, void* empleado2);

/// @fn int OrdenarPorSueldoEmployee(void*, void*)
/// @param empleado1
/// @param empleado2
/// compara los sueldos de 2 empleados
/// @return
int OrdenarPorSueldoEmployee(void* empleado1, void* empleado2);

/// @fn void employee_delete(Employee*)
/// @param this
/// libera el espacio reservado en memorioa de un empleado con "free"
void employee_delete(Employee* this);

/// @fn int employee_setId(Employee*, int)
/// @param this
/// @param id
/// llena el campo ID de un empleado
/// @return
int employee_setId(Employee* this,int id);

/// @fn int employee_getId(Employee*, int*)
/// @param this
/// @param id
/// devuelve por puntero la id de un empleado
/// @return
int employee_getId(Employee* this,int* id);

/// @fn int employee_setNombre(Employee*, char*)
/// @param this
/// @param nombre
/// llena el campo nombre de un empleado
/// @return
int employee_setNombre(Employee* this,char* nombre);

/// @fn int employee_getNombre(Employee*, char*)
/// @param this
/// @param nombre
/// devuelve por puntero el nombre de un empleado
/// @return
int employee_getNombre(Employee* this,char* nombre);

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @param this
/// @param horasTrabajadas
/// llena el campo horasTrabajadas de un empleado
/// @return
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @param this
/// @param horasTrabajadas
/// devuelve por puntero las horas trabajadas de un empleado
/// @return
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// @fn int employee_setSueldo(Employee*, int)
/// @param this
/// @param sueldo
/// llena el campo sueldo de un empleado
/// @return
int employee_setSueldo(Employee* this,int sueldo);

/// @fn int employee_getSueldo(Employee*, int*)
/// @param this
/// @param sueldo
/// devuelve por puntero el sueldo de un empleado
/// @return
int employee_getSueldo(Employee* this,int* sueldo);

/// @fn void employee_mostrar(Employee*)
/// @param this
/// imprime los campos de un empleado que recibe por puntero
void employee_mostrar(Employee* this);
#endif // employee_H_INCLUDED
