/*
 ============================================================================
 Name        : TP-2.c
 Author      : Garrido Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*									AVISO IMPORTANTE!!!!
 *
 * 			Este projecto y otro de bibliotecas cuadno le doy a Run as local Application en la consola de eclpse no andan,
 * 			Pero en el .exe funcionan perfecto, nose a que se debe eso. Aviso por si llega a pasar.
*/
#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#define TamLista 1000 // cambiar a 1000
#define Vacio 1
#define Activo 0

int main(void) {

	setbuf(stdout, NULL);

	eEmployee listaEmpleados[TamLista]= {{100,"Carlos","Sabala",2500.45,2,Vacio},
										 {101,"Jose","Garcia",2500.45,3,Vacio},
										 {102,"Armando","Barreda",1500.45,1,Vacio},
										 {103,"Pablo","Espinola",1500.45,1,Vacio}};
	char opcion;
	int validacion;
	int ordenUPoDow;
	int verif;


	initEmployees(listaEmpleados,TamLista);

	do
	{

		system("cls");
		printf("\n\t\t\t\t-----------------------------------------------");
		printf("\n \t\t\t\t|\t       Lista de Empleados             |"
			   "\n \t\t\t\t|\t                                      |");
		printf("\n \t\t\t\t|\t1. Dar de Altas empleados.            |");
		printf("\n \t\t\t\t|\t2. Modificar datos de empleados.      |");
		printf("\n \t\t\t\t|\t3. Dar de Baja empleados.             |");
		printf("\n \t\t\t\t|\t4. Informes.                          |");
		printf("\n \t\t\t\t|\t0. Salir                              |");
		printf("\n\t\t\t\t-----------------------------------------------\n");

		opcion=PedirChar("\n\nIngrese un numero del 1-5: ");

		verif=VerificarEstado(listaEmpleados, TamLista);

		switch(opcion)
		{
			case '1':
				validacion=CargaEmpleado (listaEmpleados,TamLista);
				MensajesConfirmacion(validacion, "\n Se ingreseo con exito un nuevo empleado.", "\n Error. No hay mas espacio en la lista, Remueva un empleado para continuar.");
			break;
			case '2':
				if(verif!=-1)
				{
					validacion=ModificarEmpleado(listaEmpleados, TamLista);
					MensajesConfirmacion(validacion, "\n Se modifico al Empleado con exito!", "\n Hubo un error, no se pudo modificar al Empleado. Vuela a intentarlo.");
				}
				MensajesConfirmacion(verif,"   " , "\n\n\t No Hay Empleados en el sistma. Comience a cargarlos en la opcion 1.\n\n");
			break;
			case'3':
				if(verif!=-1)
				{
					validacion=BajaEmpleado(listaEmpleados, TamLista);
					MensajesConfirmacion(validacion, "\n Se elimino al Empleado con exito.", "\n Hubo un error, vuela a intentarlo.");
				}
				MensajesConfirmacion(verif,"   " , "\n\n\t No Hay Empleados en el sistma. Comience a cargarlos en la opcion 1.\n\n");
			break;
			case '4':
				if(verif!=-1)
				{
					ObtenerIntConLimite(&ordenUPoDow, "Ingrese 1 ordenar de forma Ascendente o 0 para descendente: ", "opcion no valida", 0, 1);
					validacion=sortEmployees(listaEmpleados, TamLista, ordenUPoDow);
					SalarioMayorPromedio(listaEmpleados, TamLista);
					MensajesConfirmacion(validacion, " ", "\n No hay Empleados para mostrar");
				}
				MensajesConfirmacion(verif,"   " , "\n\n\t No Hay Empleados en el sistma. Comience a cargarlos en la opcion 1.\n\n");
			break;
			case '5':
				printf("\n\n\n\t\t\tGood Bey");
			break;
			default:
				printf("\n\t\tError Opcion no valida!\n");
			break;
		}

	}while(opcion!='0');


	return EXIT_SUCCESS;
}
