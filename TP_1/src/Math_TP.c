/*
 * Math_TP.c
 *
 *
 *      Author: Nacho
 */

#include "Math_TP.h"

float Suma (float numeroUno, float numeroDos){

	float resultado;

	resultado=numeroUno+numeroDos;

	return resultado;
}

float Resta (float numeroUno, float numeroDos){

	float resultado;

	resultado=numeroUno-numeroDos;

	return resultado;

}

float Divicion (float numeroUno, float numeroDos, float* divicionResultado){

	float resultado;
	int retorno;

	if(numeroDos==0.000000)
	{
		retorno=-1;
		return retorno;

	}
	else
	{
		resultado=numeroUno/numeroDos;
		retorno=0;
	}
	*divicionResultado=resultado;

	return retorno;

}

float Multiplicacion (float numeroUno, float numeroDos){

	float resultado;

	resultado=numeroUno*numeroDos;

	return resultado;

}

float Factorial (float numero,int* factorNumero, int limite){

	int i;
	int resultado;
	int retorno;

	resultado=1;
	retorno=0;


	if((numero<0 || numero>limite) || numero==0)
	{
		retorno=-1;
		return retorno;
	}

		for(i=(int)numero;i>0;i--)
		{
			resultado= resultado * i;

		}
		*factorNumero=resultado;

	return 	retorno;
}

/*int DetermninarSigno (int numero){

	int retorno;

	retorno=0;

	if(numero<0)
	{
		retorno=-1;
	}

	return retorno;

}*/












