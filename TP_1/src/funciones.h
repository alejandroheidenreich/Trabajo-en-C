

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @fn int Decimales(float)
/// @param n - recibe un flotante y cuenta los numeros decimales hasta en contrar 0
/// @return - devuelve la cantaidad de decimales que tiene el numero.
int Decimales(float n);

/// @fn float PedirNumero(char[], char[])
/// @param mensaje error - recibe 2 mensajes (uno en caso de fallar la validacion), pide un array de char y verifica que cada uno de esos caracteres sea parte de un numero
/// @return - devuelve el numero que ingreso el usuario.
float PedirNumero(char mensaje[], char error[]);

/// @fn long int Factorial(float)
/// @param n - recibe un float, verifica que el numero no tenga decimales (llamando a la funcion Decimales), en caso que no tenga realiza la operacion, caso contrario devuelve cero
/// @return - devuelve el resultado del factorial, caso contrario, cero
long int Factorial(float n);

/// @fn float Suma(float, float)
/// @param a b - recibe 2 numeros y los suma
/// @return - devuelve el resultado de la suma
float Suma(float a, float b);

/// @fn float Resta(float, float)
/// @param a b - recibe 2 numeros y los resta
/// @return - devuelve el resultado de la resta
float Resta(float a, float b);

/// @fn float Division(float, float)
/// @param a b - recibe 2 numeros, verifica que el dividendo no sea cero y los divide
/// @return - devuelve el resultado de la division, en caso contrario cero
float Division(float a, float b);

/// @fn float Multiplicacion(float, float)
/// @param a b - recibe 2 numeros y los multiplica
/// @return - devuelve el resultado de la multiplicacion
float Multiplicacion(float a, float b);

#endif /* FUNCIONES_H_ */
