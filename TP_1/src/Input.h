/*
 * Input.h
 *
 *  Created on: 15 sep. 2021
 *      Author: Nacho
 */

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


#ifndef INPUT_H_
#define INPUT_H_

/// @fn float PedirFloat(char[])
/// @brief Se pide al usuario un núermo del tipo float, por medio de un mansaje, se guarda en una variable con scanf
/// 		y se retonra al main
///
/// @param Se pasa un string a modo de mansaje para pedir al ausuario un numero
/// @return Retonra un numero float
float PedirFloat (char[]);

/// @fn int PedirInt(char[])
/// @brief Se pide al usuario un núermo del tipo int, por medio de un mansaje, se guarda en una variable con scanf
/// 		y se retonra al main
/// @param Se pasa un string a modo de mansaje para pedir al ausuario un numero
/// @return Retonra un numero int
int PedirInt (char[]);

/// @fn char PedirChar(char[])
/// @brief Se pide al usuario un núermo del tipo char, por medio de un mansaje, se guarda en una variable con scanf
/// 		y se retonra al main
/// @param Se pasa un string a modo de mansaje para pedir al ausuario que ingrese un caracter.
/// @return Retonra un numero char
char PedirChar (char[]);


/// @fn void MostrarResultado(char[], float, float, float)
/// @brief Muestra el tipo de calculoq 1ue se ralizó e infomra el resultado.
///
/// @param es un string para el signo de la operación.
/// @param es el numero al cual se le  aplicar una opeción matemática.
/// @param es el nuemro a realizar la opercaión matemática.
/// @param este es el reultado de la operacion de los anteriores.
void MostrarResultado (char[],float, float, float);

/// @fn void MostrarCalculos(char[], float, char[], float)
/// @brief Muetra el calculo que se va a realizar.
///
/// @param string a mondo de mensaje.
/// @param numero al cual se le  aplicar una opeción matemática.
/// @param string para el signo de la operación.
/// @param nuemro que realizar la opercaión matemática.
void MostrarCalculos (char[],float,char[],float);

/// @fn void MostrarFactorial(char[], float, int)
/// @brief Muestra el numero que se factotio con su resultado
///
/// @param string a modo de mensaje.
/// @param Numero a factoriar.
/// @param Resultado de la factorizacion.
void MostrarFactorial (char[],float,int);

/// @fn int VerificarFloat(char[])
/// @brief verifica si el dato ingresado mediante un array es un digito o un caracter.
///
/// @param string a verificar.
/// @return  si es un digito retorna un 0 si no lo es retorna un 1
int VerificarNumero (char numero[]);

/// @fn void ValidarNumero(char[], char[])
/// @brief verifica con la funció VerificarNumero(), si no lo es vuelve a pedir el dato hasta que este correcto
///
/// @param string  a modo de mensaje para pedir el numero.
/// @param string a validar.
void ValidarNumero (char mensaje[], char numero[]);

#endif /* INPUT_H_ */
