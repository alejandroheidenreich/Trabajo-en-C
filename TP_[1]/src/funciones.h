

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @fn int Decimales(double)
/// @param n - recibe un flotante y cuenta los numeros decimales hasta en contrar 0
/// @return - devuelve la cantaidad de decimales que tiene el numero.
int Decimales(double n);

/// @fn double PedirNumero(char[], char[])
/// @param mensaje error - recibe 2 mensajes (uno en caso de fallar la validacion), pide un array de char y verifica que cada uno de esos caracteres sea parte de un numero
/// @return - devuelve el numero que ingreso el usuario.
double PedirNumero(char mensaje[], char error[]);

/// @fn long int Factorial(double, double)
/// @param n - recibe un numero, verifica que el numero no tenga decimales (llamando a la funcion Decimales) y que sea entre 0 y 170, en caso que no tenga realiza la operacion, caso contrario devuelve cero
/// @return - devuelve el resultado del factorial por referencia
int Factorial(double numero,double *factorial);

/// @fn double Suma(double, double)
/// @param a b - recibe 2 numeros y los suma
/// @return - devuelve el resultado de la suma
double Suma(double a, double b);

/// @fn double Resta(double, double)
/// @param a b - recibe 2 numeros y los resta
/// @return - devuelve el resultado de la resta
double Resta(double a, double b);

/// @fn double Division(double, double)
/// @param a b - recibe 2 numeros, verifica que el dividendo no sea cero y los divide
/// @return - devuelve el resultado de la division, en caso contrario cero
int Division(double a, double b, double* division);

/// @fn double Multiplicacion(double, double)
/// @param a b - recibe 2 numeros y los multiplica
/// @return - devuelve el resultado de la multiplicacion
double Multiplicacion(double a, double b);

#endif /* FUNCIONES_H_ */
