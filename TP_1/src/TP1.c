/*
 ============================================================================
 Name        : TP1.c
 Author      : Garrido Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "Math_TP.h"
#include <ctype.h>

#define TAM 31

int main(void) {

	setbuf(stdout, NULL);

	char opciones;
	char numeroUno[1000000];
	char numeroDos[1000000];
	float numeroUnoValidado;
	float nuemroDosValidado;
	float suma;
	float resta;
	float multiplicacion;
	float divicionResultado;
	int factorNumeroUno;
	int factorNumeroDos;
	int verificaDivicion;
	char opcionAntes;
	char opcionAntesDos;
	int castFactorUno;
	int castFactorDos;




	do
	{
		printf("\n============================================================================\n");
		printf("\t\tIngrese 1 para ingresar el 1er operador: %.2f\n",numeroUnoValidado);
		printf("\t\tIngrese 2 para ingresar el 2do operador: %.2f\n",nuemroDosValidado);
		printf("\t\tIngrese 3 para calcular todas las operaciones\n");
		printf("\t\tIngrese 4 para ver todos los resultados\n");
		printf("\t\tIngrese 5 para salir de la caluladora\n");
		printf("============================================================================\n\n");

		opciones=PedirChar("Elija una opcion de 1-4: ");



		switch (opciones)
		{
			case '1':
				opcionAntes=opciones;

				ValidarNumero("Ingrese el 1er operador: ",numeroUno);

				numeroUnoValidado=atof(numeroUno);

			break;
			case '2':
				opcionAntesDos=opciones;

				ValidarNumero("Ingrese el 2do operador: ",numeroDos);

				nuemroDosValidado=atof(numeroDos);

			break;
			case '3':


				printf("\nCalculando...... \n");

				if(opcionAntes=='1' && opcionAntesDos=='2')
				{
					opcionAntes=opciones;
					castFactorUno=(int)numeroUnoValidado;
					castFactorDos=(int)nuemroDosValidado;
					suma=Suma(numeroUnoValidado,nuemroDosValidado);
					resta=Resta(numeroUnoValidado,nuemroDosValidado);
					verificaDivicion=Divicion(numeroUnoValidado,nuemroDosValidado,&divicionResultado);
					multiplicacion=Multiplicacion(numeroUnoValidado,nuemroDosValidado);
					Factorial(numeroUnoValidado,&factorNumeroUno,TAM);
					Factorial(nuemroDosValidado,&factorNumeroDos,TAM);

					MostrarCalculos("Calcular la suma ",numeroUnoValidado,"+",nuemroDosValidado);
					MostrarCalculos("Calcular la resta ",numeroUnoValidado,"-",nuemroDosValidado);
					MostrarCalculos("Calcular la división ",numeroUnoValidado,"/",nuemroDosValidado);
					MostrarCalculos("Calcular la multiplicación ",numeroUnoValidado,"*",nuemroDosValidado);
					printf("\n Calcular el Factor de %d!",castFactorUno);
					printf("\n Calcular el Factor de %d!",castFactorDos);
					printf("\n\nTerminado!\n");
				}
				else
				{
					printf("\nNo se ingresaron suficientes numeros. Asegurese de ingresar los Dos operadores.\n");
				}

			break;
			case '4':

				if(opcionAntes=='3')
				{
					MostrarResultado("+",numeroUnoValidado,nuemroDosValidado,suma);
					MostrarResultado("-",numeroUnoValidado,nuemroDosValidado,resta);
					MostrarResultado("*",numeroUnoValidado,nuemroDosValidado,multiplicacion);
					if(verificaDivicion==0)
					{
						MostrarResultado("/",numeroUnoValidado,nuemroDosValidado,divicionResultado);

					}
					else
					{
						printf("\n El divisor no pude ser 0");

					}
					if(Factorial(numeroUnoValidado,&factorNumeroUno,TAM)==0) // validar que nosea negativo ni decimal
					{
						numeroUnoValidado=(int)numeroUnoValidado;
						MostrarFactorial("\n El factorial de :",numeroUnoValidado,factorNumeroUno);
					}
					else
					{
						printf("\n\n El numero %.2f es un 0, negativo o muy grande para factoriar, no debe ser mayor a: %d \n",numeroUnoValidado,TAM);
					}
					if( Factorial(nuemroDosValidado,&factorNumeroDos,TAM)==0)
					{
						nuemroDosValidado=(int)nuemroDosValidado;
						MostrarFactorial(" El factorial de :",nuemroDosValidado,factorNumeroDos);
					}
					else
					{
						printf("\n\nEl numero %.2f es un 0, negativo o muy grande para factoriar, no debe ser mayor a: %d \n",nuemroDosValidado ,TAM);
					}
				}
				else
				{
					printf("\n\t\tNo se realizo ningun calculo aun. Precione opcion 3 en el menu por favor.\n");
				}

			break;
			case '5':
				printf("\n\n\n\t\tGracias vuelva prontos...\n\n");
			break;
			default:
				printf("\n\n ERROR! Debe ser un numero de 1-5 no se aceptan ni letras ni simbolos.\n");
			break;
		}
	}while(opciones!='5');




	return EXIT_SUCCESS;
}
