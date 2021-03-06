/*
 * GetsUtn.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Ignacio
 */


#include "GetsUtn.h"

char PedirChar (char mensaje[]){

	char opcionIngrezada;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&opcionIngrezada);


	return opcionIngrezada;
}

int PedirCadena (char* cadena, int longitud){

	int retorno;
	char bufferString[4096]; // El tama?o hay que cambiarlo seg?n implementaci?n, hasta aprender Memoria Dinamica.

	retorno=-1;

	if(cadena !=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);

				retorno=0;
			}
		}
	}


	return retorno;
}

int ValidarSoloLetras (char* cadena, int longitud)
{
	int retorno;
	int i;
	int contador;

	retorno=-1;
	contador=0;

	for(i=0;i<longitud && cadena[i]!='\0';i++)
	{
		if(isalpha(cadena[i])!=0)
		{
			contador++;

		}
		else
		{
			retorno=1;
		}
	}
	if(contador==strlen(cadena))
	{
		retorno=0;
	}

	return retorno;
}

int ObtenerSoloLetras (char* cadena, int longitud, char* mensaje)
{
	int retorno;
	char bufferString[4096];

	retorno=-1;

	do{
		printf("\n\n %s", mensaje);
		if(!PedirCadena(bufferString, sizeof(bufferString)) &&
		   ValidarSoloLetras(bufferString, sizeof(bufferString))==0)
		{
			retorno=0;
			strncpy(cadena,bufferString,longitud);
			break;
		}
		printf("\n---Error. Dato invalido ingrese solo letras.---");

	}while(retorno!=0);


	return retorno;
}


int ObtenerIntConLimite (int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo){

	int retorno;
	int bufferInt;

	retorno=-1;

	do
	{
		printf("\n\n %s", mensaje);
		if( PedirInt(&bufferInt) ==0 &&
			bufferInt>=minimo&&
			bufferInt<=maximo)
		{
			retorno=0;
			*pNumero=bufferInt;
			break;
		}
		printf("\n\n %s", mensajeError);


	}while(retorno!=0);

	return retorno;
}

int ObtenerInt (int* pNumero, char* mensaje, char* mensajeError){

	int retorno;
	int bufferInt;

	retorno=-1;

	do
	{
		printf("\n\n %s", mensaje);
		if( PedirInt(&bufferInt) ==0)
		{
			retorno=0;
			*pNumero=bufferInt;
			break;
		}
		printf("\n\n %s", mensajeError);


	}while(retorno!=0);

	return retorno;
}


int ObtenerFloatConLimite (float* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo){

	int retorno;
	float bufferInt;

	retorno=-1;

	do
	{
		printf("\n\n %s", mensaje);
		if( PedirFloat(&bufferInt) ==0 &&
			bufferInt>=minimo&&
			bufferInt<=maximo)
		{
			retorno=0;
			*pNumero=bufferInt;
			break;
		}
		printf("\n\n %s", mensajeError);


	}while(retorno!=0);

	return retorno;
}

int ObtenerFloat (float* pNumero, char* mensaje, char* mensajeError,int intentos){

	int retorno;
	float bufferInt;

	retorno=-1;

	do
	{
		printf("\n\n %s", mensaje);
		if( PedirFloat(&bufferInt) ==0)
		{
			retorno=0;
			*pNumero=bufferInt;
			break;
		}
		printf("\n\n %s", mensajeError);
		intentos--;

	}while(intentos>=0);

	return retorno;
}

int ValidarInt (char* cadena, int limite){

	int retorno;
	int i;

	retorno=1;

	for(i=0;i<limite && cadena[i]!='\0';i++)
	{
		if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
		{
			continue;
		}
		if(isdigit(cadena[i])==0)
		{
			retorno=0;
			break;
		}
	}

	return retorno;
}

int ValidarFloat (char* cadena, int limite){

	int retorno;
	int i;
	int flagComa;

	retorno=1;
	flagComa=0;

	for(i=0;i<limite && cadena[i]!='\0';i++)
	{
		if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
		{
			continue;
		}
		if(flagComa==0 && cadena[i]=='.')
		{
			flagComa=1;
			continue;
		}
		if(isdigit(cadena[i])==0)
		{
			retorno=0;
			break;
		}
	}

	return retorno;
}

int PedirInt (int* pNumero){

	int retorno;
	char bufferString[50];

	retorno=-1;

	if( pNumero !=NULL &&
		!PedirCadena(bufferString, sizeof(bufferString)) && // ES lo mismo que... PedirCadena(bufferString, sizeof(bufferString), "Ingrese un numero entero: ")==0
		ValidarInt(bufferString,sizeof(bufferString)))
	{
		retorno=0;

		*pNumero=atoi(bufferString);
	}

	return retorno;
}

int PedirFloat (float* pNumero){

	int retorno;
	char bufferString[50];

	retorno=-1;

	if( pNumero !=NULL &&
		!PedirCadena(bufferString, sizeof(bufferString)) && // ES lo mismo que... PedirCadena(bufferString, sizeof(bufferString), "Ingrese un numero entero: ")==0
		ValidarFloat(bufferString,sizeof(bufferString)))
	{
		retorno=0;

		*pNumero=atof(bufferString);
	}

	return retorno;
}


void MensajesConfirmacion (int validacion,char* mensajeOk,char* mensajeError)
{
	char tecla;

	if(validacion!=0)
	{
		printf("\n\n%s", mensajeError);
	}
	else
	{
		printf("\n%s", mensajeOk);
	}
	printf("\n\nPara continuar presione enter cualquiera..");
	fflush(stdin);
	scanf("%c",&tecla);
	printf("\n\n");
}





























