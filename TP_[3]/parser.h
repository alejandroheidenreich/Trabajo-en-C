

#ifndef PARSER_H_
#define PARSER_H_

/// @fn int parser_EmployeeFromText(FILE*, LinkedList*)
/// @param pFile
/// @param pArrayListEmployee
/// guarda cada empleado guardado en el archivo como texto en la linked list y devuelve la cantidad agregada
/// @return contador
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/// @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// @param pFile
/// @param pArrayListEmployee
/// guarda cada empleado guardado en el archivo como binario en la linked list y devuelve la cantidad agregada
/// @return contador
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
