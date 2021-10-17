/*
 * Employee.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Ignacio
 */


#include "Employee.h"


int initEmployees(eEmployee* list,int lenght)
{
	int i;
	int retorno;

	retorno=-1;

	if(list!=NULL && lenght>0)
	{
		for(i=0; i<lenght; i++)
		{
			if(list[i].id==0)
			{
				list[i].isEmpty=Vacio;
				retorno=0;
			}
		}
	}
	return retorno;
}

int printEmployees (eEmployee* list, int lenght)
{
	int i;
	int retorno;

	retorno=-1;
	printf("  ID    Nombre    Apellido    Sueldo     Sector\n");
	for(i=0;i<lenght;i++)
	{
		if(list[i].isEmpty==Activo)
		{
			MostrarUnEmp(list[i]);
			retorno=0;
		}
	}

	return retorno;
}

void MostrarUnEmp (eEmployee list)
{

		printf("\n %2d %10s %10s %10.2f %5d",list.id,list.name,list.lastName,list.salary,list.sector);

}


int CargaEmpleado (eEmployee* lista, int tamano)
{
	int retorno;
	int idEmpleadoAutomatico;
	char nombre[StringTam];
	char apellido[StringTam];
	float auxSalario;
	int auxSector;

	retorno=-1;

	auxSalario=-1;
	auxSector=-1;

	if(lista!=NULL && tamano>0)
	{
		AutoIncrementID(lista, tamano, &idEmpleadoAutomatico);
		addEmployee(lista, tamano, idEmpleadoAutomatico, nombre, apellido, auxSalario, auxSector);
		retorno=0;

	}
	return retorno;
}

int addEmployee(eEmployee* list, int lenght, int id, char name[], char lastName[],float salary,int sector)
{
	int retorno;
	int i;
	int auxI;
	//int idEmpleadoAutomatico;

	retorno=-1;
	auxI=-5;



	if(list!=NULL && lenght>0)
	{
		for(i=0;i<lenght;i++)
		{
			if(list[i].isEmpty==Vacio)
			{
				auxI=i;
				break;
			}
		}
		if(auxI!=-5)
		{

			list[auxI].id=id;
			//printf("\n\n  ");
			ObtenerSoloLetras(name, 51,"Ingrese Nombre del empleado: ");
			strncpy(list[auxI].name,name,StringTam);
			ObtenerSoloLetras(lastName, StringTam,"Ingrese Apellido del empleado: ");
			strncpy(list[auxI].lastName,lastName,StringTam);
			ObtenerFloatConLimite(&salary, "Ingrese el salario del empleado: ", "\n\n--Error, Monto invalido! Debe ser entre 1.000 y 1.000.000--\n\n", 1000, 1000000);
			list[auxI].salary=salary;
			ObtenerIntConLimite(&sector, "Ingrese el sector al que pertenece: ", "\n\n--Error, sector invalido! Debe ser entre 1 y 10--  ", 1, 10);
			list[auxI].sector=sector;
			list[auxI].isEmpty=Activo;
			retorno=0;
		}

	}
	return retorno;
}

int AutoIncrementID (eEmployee* list, int lenght, int* idEmpleadoAutomatico)
{
	int i;
	int idAuto;
	int flagIdAuto;
	int retorno;
	//int acumulador;

	flagIdAuto=1;
	retorno=1;
	//acumulador=0;

	if(list!=NULL && lenght>0)
	{
		//acumulador++;
		for(i=0;i<lenght;i++)
		{
			if(list[i].id>=idAuto || flagIdAuto==1 )
			{
				flagIdAuto=0;
				idAuto=list[i].id;
				idAuto=idAuto+1;
			}
		}
		*idEmpleadoAutomatico=idAuto;
		//printf("Iteraciones %d",acumulador);
		retorno=0;
	}
	return retorno;
}

int findeEmployeeById (eEmployee* list, int lenght, int id)
{
	int i;
	int retorno;

	retorno=-1;

	if(list!=NULL && lenght>0)
	{
		for(i=0;i<lenght;i++)
		{
			if(list[i].id==id)
			{
				printf("\n  ID    Nombre    Apellido    Sueldo     Sector\n");
				MostrarUnEmp(list[i]);
				retorno=0;
			}
		}

	}

	return retorno;
}


int ModificarEmpleado (eEmployee* list, int lenght)
{
	int i;
	int retorno;
	char subMenu;
	int idEmpleado;

	retorno=-1;

	if(list!=NULL && lenght>0)
	{
		ObtenerInt(&idEmpleado, "\n Ingrese el ID del emplado: ", "\n Error! ID invalida ingrese numeros enteros.");
		if(findeEmployeeById(list,lenght,idEmpleado)==-1)
		{
			printf("\n El ID ingresado no existe.");
		}
		for(i=0;i<lenght;i++)
		{
			if(list[i].id==idEmpleado && list[i].isEmpty==Activo)
			{
				do{
					printf("\n\n\t ---------------------------");
					printf("\n\t |  Que desea Modificar?   |"
						   "\n\t |                         |");
					printf("\n\t | 1- Modificar Nombre.    |");
					printf("\n\t | 2- Modificar Apellido.  |");
					printf("\n\t | 3- Modificar Salario.   |");
					printf("\n\t | 4- Modificar Sector.    |");
					printf("\n\t | 0- Volver.              |");
					printf("\n\t ----------------------------");
					printf("\n\n Ingrese una opcion: ");

					scanf("%c",&subMenu);

					switch(subMenu)
					{
						case '1':
							ObtenerSoloLetras(list[i].name, sizeof(list[i].name), "\n Ingrese nuevo Nombre: ");
						break;
						case '2':
							ObtenerSoloLetras(list[i].lastName, sizeof(list[i].lastName), "\n Ingrese nuevo Apellido: ");
						break;
						case '3':
							ObtenerFloatConLimite(&list[i].salary, "\nIngrese nuevo Salario: ", "\n--Salario invalido debe ser entre 1.000 y 1.000.000--", 1000, 1000000);
						break;
						case '4':
							ObtenerIntConLimite(&list[i].sector, "\nIngrese nuevo Sector: ", "\n--Error, sector invalido! Debe ser entre 1 y 10--", 1, 10);
						break;
						case '0':
							printf("\n\n\t bye :)");
						break;
						default:
							printf("\n\n\tOpcion invalida, por favor elija una del 1-4 o 0 para salir");
						break;
					}
					retorno=0;
				}while(subMenu!='0');
			}
		}

	}

	return retorno;
}

int BajaEmpleado(eEmployee* list, int lenght)
{
	int retorno;
	int idEmpleado;

	retorno=-1;

	if(list!=NULL && lenght>0)
	{
		ObtenerInt(&idEmpleado, "\n Ingrese el ID del emplado: ", "\n--Error! ID invalida ingrese numeros enteros.--");
		if(!findeEmployeeById(list, lenght, idEmpleado))
		{
			if(!removeEmployee(list, lenght, idEmpleado))
			{
				retorno=0;
			}
		}
		printf("\n--Error. ID invalida.----");
	}

	return retorno;
}

int removeEmployee (eEmployee* list, int lenght, int id)
{
	int retorno;
	int i;

	retorno=-1;

	if(list!=NULL && lenght>0 && id > 0)
	{
		for(i=0;i<lenght;i++)
		{
			if(list[i].id==id && list[i].isEmpty==Activo)
			{
				list[i].isEmpty=Vacio;
				retorno=0;
			}
		}

	}
	return retorno;
}

int BuscarMinimoYMaximo (eEmployee* lista, int longitud,int* IdMinimo,int* IdMaximo)
{
	int i;
	int retorno;
	int flagMinimo;
	int flagMaximo;
	int	auxIdMinimo;
	int	auxIdMaximo;

	flagMinimo=1;
	flagMaximo=1;

	retorno=-1;
	if(lista!=NULL && longitud>0)
	{
		for(i=0;i<longitud;i++)
		{
			if(lista[i].id < auxIdMinimo || flagMinimo==1)
			{
				flagMinimo=0;
				auxIdMinimo=lista[i].id;
			}
			if(lista[i].id > auxIdMaximo || flagMaximo==1)
			{
				flagMaximo=0;
				auxIdMaximo=lista[i].id;
			}
		}
		*IdMaximo=auxIdMaximo;
		*IdMinimo=auxIdMinimo;
		retorno=0;
	}

	return retorno;
}

int OrdenarPorApellidoySector(eEmployee* list, int lenght,int* order)
{
  int i;
  int j;
  eEmployee pivote;
  int retorno;
  int auxOrder;

  retorno = -1;
  auxOrder=*order;

  if(list!=NULL && lenght>0)
  {
	  for (i = 0; i < lenght - 1; i++)
	  {
		  for (j = i + 1; j < lenght; j++)
		  {
			switch(auxOrder)
			{
				case 0:
			  	  	if (strcmp(list[i].lastName,list[j].lastName) > 0 ||
			  	  		(strcmp(list[i].lastName,list[j].lastName)==0 &&
			  	  				list[i].sector > list[j].sector	))
					{
						  pivote = list[i];
						  list[i] = list[j];
						  list[j] = pivote;
						  retorno = 0;
					}
			  	break;
				case 1:
					if (strcmp(list[i].lastName,list[j].lastName) < 0 ||
					   (strcmp(list[i].lastName,list[j].lastName)==0 &&
							   list[i].sector < list[j].sector	))
					{
						pivote = list[i];
						list[i] = list[j];
						list[j] = pivote;
						retorno = 0;
					}
				break;
				default:
					printf("\n\n\t Opcion incorrecta elija 1 o 0 \n");
				break;
			}
		  }
	   }
  }

  return retorno;
}


int sortEmployees(eEmployee* list, int lenght, int order)
{
	int retorno;
	int auxOrder;

	retorno=-1;
	auxOrder=order;

	if(list!=NULL && lenght>0)
	{
		if(OrdenarPorApellidoySector(list, lenght,&auxOrder)==0&&
								(auxOrder!= 1 || auxOrder!= 0))
		{
			printEmployees(list, lenght);
			retorno=0;
		}


	}

	return retorno;
}

int SumaYPromedioSalarios (eEmployee* lista,int lenght, float* resPromedio, float* resSuma)
{
	int i;
	int retorno;
	int contador;
	float acumulador;

	acumulador=0;
	contador=0;
	retorno=-1;

	if(lista!=NULL && lenght>0)
	{
		for(i=0;i<lenght;i++)
		{
			if(lista[i].isEmpty==Activo)
			{
				contador++;
				acumulador=Suma(acumulador, lista[i].salary);
				retorno=0;
			}
		}
		*resSuma=acumulador;
		*resPromedio=Promedio(acumulador, contador);
	}
	return retorno;
}

int SalarioMayorPromedio (eEmployee* lista, int lenght)
{
	int i;
	int retorno;
	float resultadoSuma;
	float resultadoPromedio;
	int contadorMayorAPromedio;

	retorno=-1;
	contadorMayorAPromedio=0;

	SumaYPromedioSalarios(lista, lenght,&resultadoPromedio,&resultadoSuma);

	if(lista!=NULL && lenght>0)
	{
		for(i=0;i<lenght;i++)
		{
			if(lista[i].isEmpty==Activo && lista[i].salary>resultadoPromedio)
			{
				contadorMayorAPromedio++;
				retorno=0;
			}
		}
		printf("\n\n El total de los salrios es: %.2f \n",resultadoSuma);
		printf("\n El promedio de los salarios es: %.2f \n",resultadoPromedio);
		printf("\n %d Epleados superan el salario promedio.\n",contadorMayorAPromedio);
	}

	return retorno;
}

int VerificarEstado (eEmployee* lista, int lenght)
{
	int i;
	int retorno;

	retorno=-1;

	if(lista!=NULL && lenght>0)
	{
		for(i=0;i<lenght;i++)
		{
			if(lista[i].isEmpty!=Vacio)
			{
				retorno=0;
			}
		}
	}

	return retorno;
}








