
#ifndef INPUT_H_
#define INPUT_H_

/// @fn int PedirValidoNumeroEntero(char[], char[])
/// @param mensaje se recibe para imprimir
/// @param error se recibe para imprimir en caso de error de validacion
/// @return devuelve el numero entero validado
int PedirValidoNumeroEntero(char mensaje[], char error[]);

/// @fn float PedirValidoNumeroFlotante(char[], char[])
/// @param mensaje se recibe para imprimir
/// @param error se recibe para imprimir en caso de error de validacion
/// @return devuelve el numero flotante validado
float PedirValidoNumeroFlotante(char mensaje[], char error[]);

/// @fn int IngresarEntero(char[], int, int)
/// @param mensaje se recibe para imprimir
/// @param min el intervalo minimo del numero a ingresar
/// @param max el intervalo maximo del numero a ingresar
/// @return returna el numero entero validado
int IngresarEntero(char mensaje[],int min,int max);

/// @fn float IngresarFlotante(char[], int, int)
/// @param mensaje se recibe para imprimir
/// @param min el intervalo minimo del numero a ingresar
/// @param max el intervalo maximo del numero a ingresar
/// @return returna el numero flotante validado
float IngresarFlotante(char mensaje[],int min,int max);

/// @fn void IngresarCadena(char[], char[])
/// @param mensaje se recibe para imprimir
/// @param cadena se pasa por puntero y devuelve una cadena valida
void IngresarCadena(char mensaje[], char cadena[]);

/// @fn void CorreccionCadena(char[])
/// @param cadena se recibe como puntero y se corrige las mayusculas y minusculas de la cadena
void CorreccionCadena(char cadena[]);

/// @fn float CalcularPromedio(float, int)
/// @param numero recibe un numero flotante
/// @param divisor recibe un entero como divisor
/// @return reporta un flotante con el promedio de los 2 argumentos
float CalcularPromedio(float numero, int divisor);

/// @fn void clear()
/// limpia la consola e imprime el titulo del programa
void clear();

#endif /* INPUT_H_ */
