/// @fn int controller_loadFromText(char*, LinkedList*)
/// @param path
/// @param pArrayListEmployee
/// abre activo en la direccion "path" llama a a la funcion "parser_EmployeeFromText" y luego cierra el archivo
/// @return check
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @param path
/// @param pArrayListEmployee
/// abre activo en la direccion "path" llama a a la funcion "parser_EmployeeFromBinary" y luego cierra el archivo
/// @return check
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_addEmployee(LinkedList*)
/// @param pArrayListEmployee
/// recibe la id del empleado con la funcion "controller_setIDUpdate" y crea un nuevo empleado a la linked list
/// con las funciones "CrearEmployee", "employee_newArguments" y "ll_add"
/// @return check
int controller_addEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_editEmployee(LinkedList*)
/// @param pArrayListEmployee
/// busca la posicion del del empleado en la linked list por "controller_findEmployee", edita el empleado con "ModifyEmployee"
/// y la carga a la linked list con "ll_set", actualizando los datos del empleado
/// @return check
int controller_editEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_removeEmployee(LinkedList*)
/// @param pArrayListEmployee
/// busca la posicion del del empleado en la linked list por "controller_findEmployee", y elimina al empleado con "ll_remove" y "employee_delete"
/// @return check
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_ListEmployee(LinkedList*)
/// @param pArrayListEmployee
/// imprime cada uno de los empleado con "ll_get" y "employee_mostrar"
/// @return check
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_sortEmployee(LinkedList*)
/// @param pArrayListEmployee
/// ordena la lista de empleados segun el argumento elegido en "ll_sort"
/// @return check
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_saveAsText(char*, LinkedList*)
/// @param path
/// @param pArrayListEmployee
/// abre el archivo en el "path" y escribe cada uno de los empleado en el mismo con "ll_get" y "fprintf"
/// @return check
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_saveAsText(char*, LinkedList*)
/// @param path
/// @param pArrayListEmployee
/// abre el archivo en el "path" y escribe cada uno de los empleado en el mismo con "ll_get" y "fwrite"
/// @return check
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_setIDUpdate(char*, int)
/// @param path
/// @param idEmpleado
/// abre el archivo en el "path" y guarda la id del ultimo empleado con "ll_get" y "fprintf"
/// @return check
int controller_setIDUpdate(char* path, int idEmpleado);

/// @fn int controller_loadID(char*)
/// @param path
/// abre el archivo en el "path" y lee la id cargada en el archivo "ll_get" y "fread"
/// @return id
int controller_loadID(char* path);

/// @fn int controller_findEmployee(LinkedList*)
/// @param pArrayListEmployee
/// pregunta la id del empleado y busca la posicion en la linked list del mismo
/// @return i
int controller_findEmployee(LinkedList* pArrayListEmployee);


