/*
 * GetsUtn_2.h
 *
 *
 *      Author: Ignacio
 */

#ifndef GETSUTN_2_H_
#define GETSUTN_2_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// @fn char PedirChar(char[])
/// @brief pide un cahr al usuario por consola
///
/// @param mensaje Mensaje que se mostrara por consola
/// @return Retorna el char.
char PedirChar (char mensaje[]);

/// @fn int PedirCadena(char*, int)
/// @brief pide una cadena cualquira de caracteres para despues ser validada y verificada segun las condiciones deceadas
///
/// @param cadena Puntero a char*
/// @param longitud De la adena solicitada.
/// @return  retoro -1 si no puede verificar y 0 si esta todo bien
int PedirCadena (char* cadena, int longitud);

/// @fn int PedirInt(int*)
/// @brief  Pida una cadeda y la valida pra que sea solo int
///
/// @param pResultado puntero que  devuelva el resultado validado y verificado
/// @return -1 error 0 todos ok
int PedirInt (int* pResultado);

/// @fn int PedirFloat(float*)
/// @brief  Pida una cadeda y la valida pra que sea solo float
///
/// @param pResultado puntero que  devuelva el resultado validado y verificado
/// @return -1 error 0 todos ok
int PedirFloat (float* pNumero);

/// @fn int ValidarInt(char*, int)
/// @brief valida que cada caracter de string sean solo numeros Enteros
///
/// @param cadena A validar
/// @param limite Tamaño de la cadena
/// @return -1 error 0 todos ok
int ValidarInt (char* cadena, int limite);


/// @fn int ValidarFloat(char*, int)
/// @brief valida que cada caracter de string sean solo numeros Flotantes
///
/// @param cadena A validar
/// @param limite Tamaño de la cadena
/// @return -1 error 0 todos ok
int ValidarFloat (char* cadena, int limite);


/// @fn int ObtenerIntConLimite(int*, char*, char*, int, int, int)
/// @brief recive por puntero un entero y valida que sea del tipo int y que se encuentre dentros de una limites determinados,
/// con un limite de untentos por error.
///
/// @param pNumero Puntero int a verificar
/// @param mensaje mensajae que le pide el dato a usurio
/// @param mensajeError mensaje que le avisa de su error al usuario
/// @param minimo limite mino del int
/// @param maximo limite maximo del int
/// @param intentos cantidad de veces que se puede equivocar el usuario
/// @return -1 error 0 todos ok
int ObtenerIntConLimite (int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);

/// @fn int ObtenerInt(int*, char*, char*, int)
/// @brief  recive por puntero un entero y valida que sea del tipo int SIN limites.
///
/// @param pNumero Puntero int a verificar
/// @param mensaje mensajae que le pide el dato a usurio
/// @param mensajeError mensaje que le avisa de su error al usuario
/// @param intentos cantidad de veces que se puede equivocar el usuario
/// @return -1 error 0 todos ok
int ObtenerInt (int* pNumero, char* mensaje, char* mensajeError, int intentos);

/// @fn int ObtenerFloatConLimite(float*, char*, char*, int, int, int)
/// @brief recive por puntero un entero y valida que sea del tipo float y que se encuentre dentros de una limites determinados,
/// con un limite de untentos por error.
///
/// @param pNumero Puntero float a verificar
/// @param mensaje mensajae que le pide el dato a usurio
/// @param mensajeError mensaje que le avisa de su error al usuario
/// @param minimo limite mino del float
/// @param maximo limite maximo del float
/// @param intentos cantidad de veces que se puede equivocar el usuario
/// @return -1 error 0 todos ok
int ObtenerFloatConLimite (float* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);

/// @fn int ObtenerFloat(float*, char*, char*, int)
/// @brief  recive por puntero un entero y valida que sea del tipo float SIN limites.
///
/// @param pNumero Puntero float a verificar
/// @param mensaje tamaño del string.
/// @param mensajeError mensaje que le avisa de su error al usuario
/// @param tamaño del string.
/// @return -1 error 0 todos ok
int ObtenerFloat (float* pNumero, char* mensaje, char* mensajeError,int intentos);

/// @fn int ValidarSoloLetras(char*, int)
/// @brief Valida que en el string cada carecter sean solo letras.
///
/// @param cadena Puntero char a verificar
/// @param longitud tamaño del string.
/// @return -1 error 0 todos ok
int ValidarSoloLetras (char* cadena, int longitud);

/// @fn int ToupperArray(char*)
/// @brief  Pone cada carater de un string en Mayusculas.
///
/// @param array A convertir en msyusculas.
/// @return  -1 error 0 todos ok
int ToupperArray (char* array);

/// @fn int ObtenerSoloLetras(char*, int, char*, int)
/// @brief  obtiene la cadena ya validad y verific que el usuario ingrese el dato correctamente unos cuantos intentos.
///
/// @param cadena Puntero char a verificar
/// @param longitud tamaño del string.
/// @param mensaje tamaño del string.
/// @param intentos tamaño del string.
/// @return -1 error 0 todos ok
int ObtenerSoloLetras (char* cadena, int longitud, char* mensaje,int intentos);

/// @fn int ValidarStinrgNum(char*, int)
/// @brief  valida que en un string cada caracter sea numerico;
///
/// @param cadena Puntero char a verificar
/// @param longitud tamaño del string.
/// @return -1 error 0 todos ok
int ValidarStinrgNum (char* cadena, int limite);

/// @fn int PedirStringNum(char*, int)
/// @brief  Pide y laida un string para que cada caracter sea numerico;
///
/// @param cadena Puntero char a verificar
/// @param longitud tamaño del string.
/// @return -1 error 0 todos ok
int PedirStringNum (char* cadena, int longitud);

/// @fn int ObtenerStringNum(char*, int, char*, char*, int)
/// @brief  obtiene el dato ya validado  yverific que el usuario ingrese el dato correctamente unos cuantos intentos.
///
//// @param cadena Puntero char a verificar
/// @param longitud tamaño del string.
/// @param mensaje tamaño del string.
/// @param mensajeError mensaje que le avisa de su error al usuario
/// @param intentos cantidad de veces que se puede equivocar el usuario
/// @return -1 error 0 todos ok
int ObtenerStringNum (char* cadena, int longitud,char* mensaje,char* mensajeError,int intentos );





#endif /* GETSUTN_2_H_ */
