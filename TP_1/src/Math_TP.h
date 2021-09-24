/*
 * Math_TP.h
 *
 *  Created on: 15 sep. 2021
 *      Author: Nacho
 */
#include <stdio.h>
#ifndef MATH_TP_H_
#define MATH_TP_H_

/// @fn float Suma(float, float)
/// @brief La función realiza una suma entre deos numero tipo float
///
/// @param Primer operado a sumar
/// @param Segundo perador a sumar
/// @return Retoran el resultado en tipo de dato float al main
float Suma (float, float);

/// @fn float Resta(float, float)
/// @brief La función realiza una resta entre deos numero tipo float
///
/// @param Primer operado a restar
/// @param Segundo operador que le resta al anterior
/// @return Retoran el resultado en tipo de dato float al main
float Resta (float, float);

/// @fn float Divicion(float, float, float*)
/// @brief Realiza una divicion entre dos numero, el resultado se pasa por puntero y se usa el retorno como validación
/// 		cuando el divisor es igual a 0.
///
/// @param El dividendo
/// @param El divisor
/// @param Puntero donde se guarda el resultado de la operación.
/// @return Retoran un -1 si el divisor es 0 de lo contrario retorna un 0
float Divicion (float, float, float*);

/// @fn float Multiplicacion(float, float)
/// @brief La función realiza una multipicación entre deos numero tipo float
///
/// @param Primer operador
/// @param Segunfo operador
/// @return Retoran el resultado en tipo de dato float al main
float Multiplicacion (float, float);

/// @fn float Factorial(float, int*, int)
/// @brief Calcula el factoriald el numero inrgezado, el resultado se apsa por puntero y el return se usa como verificaión
///			retorna -1 cuando el numero a facorial es negativo, mayor al limite o es igual a 0
///
/// @param EL numero a factoriar
/// @param El puntero donde se guarda el resultado
/// @param El limite que se le quiera dar como numero maximo a factoriar
/// @return retorna un int : -1 cuando el numero a facorial es negativo mayor al limite o es igual a 0
float Factorial (float, int*, int);

//int DetermninarSigno (int);


#endif /* MATH_TP_H_ */
