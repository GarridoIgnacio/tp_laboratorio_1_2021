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

#define TAM 34

int main(void) {

	setbuf(stdout, NULL);

	char opciones;
	char numeroUno[1000000];
	char numeroDos[1000000];
	//int valiarNumeroUno;
	float numeroUnoValidado;
	float nuemroDosValidado;
	float suma;
	float resta;
	float multiplicacion;
	float divicionResultado;
	int factorNumeroUno;
	int factorNumeroDos;
	int verificaDivicion;



	do
	{
		printf("\n============================================================================\n");
		printf("\t\tIngrese 1 para ingresar el 1er operador: %.2f\n",numeroUnoValidado);
		printf("\t\tIngrese 2 para ingresar el 2do operador: %.2f\n",nuemroDosValidado);
		printf("\t\tIngrese 3 para calcular todas las operaciones\n");
		printf("\t\tIngrese 4 para ver todos los resultados\n");
		printf("============================================================================\n");

		opciones=PedirChar("Elija una opción de 1-4: ");

		switch (opciones)
		{
			case '1':

				ValidarNumero("Ingrese el 1er operador: ",numeroUno);

				numeroUnoValidado=atof(numeroUno);

			break;
			case '2':

				ValidarNumero("Ingrese el 2do operador: ",numeroDos);

				nuemroDosValidado=atof(numeroDos);

			break;
			case '3':

					printf("\nCalculando...... \n");

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
					printf("\n Calcular el Factor de %.2f!",numeroUnoValidado);
					printf("\n Calcular el Factor de %.2f!",nuemroDosValidado);

					printf("\n\nTerminado!\n");

			break;
			case '4':

				MostrarResultado("+",numeroUnoValidado,nuemroDosValidado,suma);
				MostrarResultado("-",numeroUnoValidado,nuemroDosValidado,resta);
				MostrarResultado("*",numeroUnoValidado,nuemroDosValidado,multiplicacion);
				if(verificaDivicion==0)
				{
					MostrarResultado("/",numeroUnoValidado,nuemroDosValidado,divicionResultado);

				}
				else
				{
					printf("\nEl divisor no pude ser 0");

				}
				if(Factorial(numeroUnoValidado,&factorNumeroUno,TAM)==0) // validar que nosea negativo ni decimal
				{
					MostrarFactorial("El factorial de :",numeroUnoValidado,factorNumeroUno);
				}
				else
				{
					printf("\nEl numero %.2f es negativo o muy grande para factoriar, no de ser mayor a: %d",numeroUnoValidado,TAM);
				}
				if( Factorial(nuemroDosValidado,&factorNumeroDos,TAM)==0)
				{
					MostrarFactorial("El factorial de :",nuemroDosValidado,factorNumeroDos);
				}
				else
				{
					printf("\nEl numero %.2f es negativo o muy grande para factoriar, no de ser mayor a: %d",nuemroDosValidado ,TAM);
				}


			break;
			default:
				printf("\n ERROR! Debe ser un numero de 1-4 no se aceptan ni letras ni simbolos.\n");
			break;
		}
	}while(opciones!='4');



	printf("\n\n\n\t\tGracias vuelva prontos...\n\n");




	return EXIT_SUCCESS;
}
