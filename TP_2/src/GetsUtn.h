/*
 * GetsUtn.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Ignacio
 */

#ifndef GETSUTN_H_
#define GETSUTN_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char PedirChar (char mensaje[]);

int PedirCadena (char* cadena, int longitud);

int ValidarSoloLetras (char* cadena, int longitud);

int ObtenerSoloLetras (char* cadena, int longitud, char* mensaje);

int PedirInt (int* pResultado);

int PedirFloat (float* pNumero);

int ValidarInt (char* cadena, int limite);

int ValidarFloat (char* cadena, int limite);

int ObtenerIntConLimite (int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo);

int ObtenerInt (int* pNumero, char* mensaje, char* mensajeError);

int ObtenerFloatConLimite (float* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo);

int ObtenerFloat (float* pNumero, char* mensaje, char* mensajeError,int intentos);

void MensajesConfirmacion (int validacion,char* mensajeOk,char* mensajeError);




#endif /* GETSUTN_H_ */
