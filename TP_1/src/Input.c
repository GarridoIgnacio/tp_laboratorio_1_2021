/*
 * Input.c
 *
 *  Created on: 15 sep. 2021
 *      Author: Nacho
 */

#include "Input.h"


float PedirFloat (char mensaje[]){

	float numIngresado;

	printf("%s",mensaje);
	scanf("%f", &numIngresado);

	return numIngresado;
}

int VerificarNumero (char numero[]){

	int i;
	int retorno;

	retorno=1;

	for(i=0; i<strlen(numero);i++)
	{
		if(numero[i]!='.' && numero[i]!='-'){
			if(!(isdigit(numero[i])))
			{


				retorno=0;
			}
		}
	}
	return retorno;
}

int PedirInt (char mensaje[]){

	int numIngresado;

	printf("%s",mensaje);
	scanf("%d", &numIngresado);

	return numIngresado;
}

void MostrarResultado (char mensaje[],float numeroUno, float numeroDos, float resultado){

	printf("\n El resultado de %.2f %s %.2f es: %.4f",numeroUno,mensaje,numeroDos,resultado);

}

void MostrarCalculos (char mensaje[],float numeroUno,char mensajeSigno[],float numeroDos){

	printf("\n %s %.2f %s %.2f",mensaje,numeroUno,mensajeSigno,numeroDos);
}

void MostrarFactorial (char mensaje[],float numeroUno,int factorial){

	printf("\n%s %.0f es: %d \n",mensaje,numeroUno,factorial);
}

char PedirChar (char mensaje[]){

	char opcionIngrezada;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&opcionIngrezada);


	return opcionIngrezada;
}

void ValidarNumero (char mensaje[], char numero[])
{
	int valiarNumero;

	do{
		printf("\n %s", mensaje);
		scanf("%s", numero);
		valiarNumero=VerificarNumero(numero);

		if(valiarNumero==0)
		{
			printf("\n\n Error! El dato ingresado no es un numero.\n");
		}

	 }while(valiarNumero==0);

}




