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

float PedirFloat (char[]);

int PedirInt (char[]);

char PedirChar (char[]);

void MostrarResultado (char[],float, float, float);

void MostrarCalculos (char[],float,char[],float);

void MostrarFactorial (char[],float,int);

int VerificarFloat (char numero[]);

void ValidarNumero (char mensaje[], char numero[]);

#endif /* INPUT_H_ */
