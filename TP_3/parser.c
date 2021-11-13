
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	char idString[11];
	char nombreStr[128];
	char horasTrabajadasStr[11];
	char sueldoStr[20];
	int id;
	int hsTrabajadas;
	int sueldo;
	Employee* peEmpleado=NULL;


	retorno=0;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idString,nombreStr,horasTrabajadasStr,sueldoStr);

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idString,nombreStr,horasTrabajadasStr,sueldoStr);
			id=atoi(idString);
			hsTrabajadas=atoi(horasTrabajadasStr);
			sueldo=atoi(sueldoStr);
			peEmpleado=employee_newParametros(&id, nombreStr,&hsTrabajadas,&sueldo);

			if(peEmpleado!=NULL && !ll_add(pArrayListEmployee, peEmpleado))
			{
				retorno=1;
			}
			else{
				printf("\n-- Error---No queda suficiente memoria disponible.\n");
			}
			/*if(feof(pFile))
			{
				break;
			}*/

		}

	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee  eEmpleado;
	Employee* peEmpleado=NULL;

	retorno=0;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			if(fread((Employee*)&eEmpleado,sizeof(Employee),1,pFile)==1)
			{
				peEmpleado=employee_newParametros(&(eEmpleado.id), eEmpleado.nombre, &(eEmpleado.horasTrabajadas),&(eEmpleado.sueldo));
				if(peEmpleado!=NULL)
				{
					ll_add(pArrayListEmployee, (Employee*)peEmpleado);
					retorno=1;
				}
				else{
					printf("\n-- Error---No queda suficiente memoria disponible.\n");
				}
			}

		}
	}
	return retorno;
}

/// @fn int parser_EmployeeList(LinkedList*)
/// @brief Printea la lista de los todos los empleados sin ordenar.
///
/// @param pArrayListEmployee El puntero a la linkedlist donde esta la lsiat de los empleados.
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int parser_EmployeeList(LinkedList* pArrayListEmployee)
{
	int retorno;
	int len;

	len=ll_len(pArrayListEmployee);
	retorno=0;
	printf("\n \t Cantidad LL: %d \n", len);

	    if(pArrayListEmployee!=NULL && len>0)
	    {
	    	printf("\n  ID            NOMBRE       HsTRABAJADAS      SUELDO \n");
			for(int i=0;i<len;i++)
			{
				parser_OneEmployee(pArrayListEmployee, i);
			}
			retorno=1;

	    }
	    return retorno;
}

/// @fn int parser_OneEmployee(LinkedList*, int)
/// @brief Printea un solo empleado de la lista.
///
/// @param pArrayListEmployee El puntero a la linkedlist donde esta la lsiat de los empleados.
/// @param index el indice del empleado que se desa imprimir.
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int parser_OneEmployee (LinkedList* pArrayListEmployee, int index)
{
	int retorno;
	int idUnboxing;
	char nombreUnboxing[128];
	int horasTrabajadasUnbox;
	int sueldoUnboxing;
	Employee* peEpleadoUnbox=NULL;

	retorno=0;
	if(pArrayListEmployee!=NULL)
	{
		peEpleadoUnbox=(Employee*)ll_get(pArrayListEmployee, index);

		employee_getId(peEpleadoUnbox, &idUnboxing);
		employee_getNombre(peEpleadoUnbox, nombreUnboxing);
		employee_getHorasTrabajadas(peEpleadoUnbox, &horasTrabajadasUnbox);
		employee_getSueldo(peEpleadoUnbox, &sueldoUnboxing);

		printf("\n %4d %15s %15d %15d", idUnboxing ,nombreUnboxing,horasTrabajadasUnbox,sueldoUnboxing);
		retorno=1;
	}

	return retorno;
}

/// @fn int parser_BuscarIdMaximo(LinkedList*)
/// @brief  Busca el ID maximo de toda la lista y se lo pasa a parser_GuardarIdMaximoText por puntero.
///
/// @param pArrayListEmployee El puntero a la linkedlist donde esta la lsiat de los empleados.
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int parser_BuscarIdMaximo (LinkedList* pArrayListEmployee)
{
	int retorno;
	int i;
	int lenghtLL;
	int flagIdMaximo;
	int IdMaximo;
	int idUnboxing;
	Employee* peEpleadoUnbox=NULL;

	retorno=0;
	flagIdMaximo=1;

	if(pArrayListEmployee!=NULL)
	{
		lenghtLL=ll_len(pArrayListEmployee);

		if(lenghtLL>0)
		{
			for(i=0; i<lenghtLL;i++)
			{
				peEpleadoUnbox=(Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(peEpleadoUnbox, &idUnboxing);
				if(flagIdMaximo==1 || idUnboxing> IdMaximo)
				{
					IdMaximo=idUnboxing;
					flagIdMaximo=0;
					retorno=1;
				}
			}
			if(!parser_GuardarIdMaximoText(&IdMaximo))
			{
				printf("\n---ERRO 102---\n");
			}
		}
	}

	return retorno;
}


/// @fn int parser_GuardarIdMaximoText(int*)
/// @brief Guarda el ID maximo que ressivio por puntero en un archivo de texto .csv.
///
/// @param idMaximo puntero a un ID maximo.
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int parser_GuardarIdMaximoText (int* idMaximo)
{
	int retorno;
	int maximoId;
	char string[10];
	FILE* pUlrimoId=NULL;

	retorno=0;

	if(idMaximo!=NULL)
	{
		maximoId=*idMaximo;
		sprintf(string,"%d",maximoId);
		//printf("\n --IDMAx-- : %d, %s\n", *idMaximo,string);
		pUlrimoId=fopen("C:\\UTN Programación\\Programa y Labo 1\\tp_laboratorio_1\\TP_3\\Ultimo_id_Text.csv","w");
		if(pUlrimoId!=NULL)
		fwrite(string,sizeof(char),strlen(string),pUlrimoId);
		fclose(pUlrimoId);
		retorno=1;
	}

	return retorno;
}

/// @fn int parser_CopiarUlrimoID(int*)
/// @brief  Copia el el ID maximo guardado en el archivo .csv y los pasa por puntero a la funcionq ue lo requira.
///
/// @param ultimoID puntero a para pasar un ID maximo
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int parser_CopiarUlrimoID (int* ultimoID)
{
	int retorno;
	FILE* pUlrimoId=NULL;
	char string[10];
	int idUltimo;

	retorno=0;

	if(ultimoID!=NULL)
	{
		pUlrimoId=fopen("C:\\UTN Programación\\Programa y Labo 1\\tp_laboratorio_1\\TP_3\\Ultimo_id_Text.csv","r");
		if(pUlrimoId!=NULL)
		fscanf(pUlrimoId,"%[^\n]",string);
		fclose(pUlrimoId);
		//printf("\n%s\n",string);
		idUltimo=atoi(string);
		//printf("\n%d\n",idUltimo);
		*ultimoID=idUltimo;
		retorno=1;
	}

	return retorno;
}

/// @fn int parser_PedirCampos(int*, char*, int*, int*)
/// @brief Piedo al usuarioq que ingrese por teclado los datos de los campos para pasarselso pro punteros a controller_addEmployee.
///
/// @param id Puntero que guarada la direccionde memorai la varivle id de la funcion controller_addEmployee
/// @param nombre Puntero que guarada la direccionde memorai la varivle nombre de la funcion controller_addEmployee
/// @param hsTrabajadas Puntero que guarada la direccionde memorai la varivle hsTrabajadas de la funcion controller_addEmployee
/// @param sueldo Puntero que guarada la direccionde memorai la varivle sueldo de la funcion controller_addEmployee
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int parser_PedirCampos (int* id, char* nombre,int* hsTrabajadas,int* sueldo )
{
	int retorno;
	int idAux;

	retorno=0;

	if(id!=NULL && nombre!=NULL && hsTrabajadas!=NULL && sueldo!=NULL)
	{
		idAux=*id;
		idAux++;
		*id=idAux;
		if(!ObtenerSoloLetras(nombre, 51, "\n Ingrese el nombre: ", 3) &&
		   !ObtenerIntConLimite(hsTrabajadas, "\n Ingrese las Horas Trabajadas: ", "\n--Error--Dato invalido debe ser un numero entre 0 y 2000.", 0, 2000, 3)&&
		   !ObtenerIntConLimite(sueldo, "\n Ingrese el sueldo: ", "\n--Error--Dato invalido debe ser un numero entre 1000 y 1000000.", 1000, 1000000, 3))
		{
			retorno=1;
		}

	}

	return retorno;
}

/// @fn int parser_BuscarPorID(LinkedList*, int*, int*)
/// @brief  Busca y mestra a un empleado por id el mismo se le pide al usuraioq eu lo ingrese por consola.
///
/// @param pArrayListEmployee Puntero a linqked list el cual almacena por indices a cada empleado en una lsita.
/// @param idObtenida Puntere que le invia por direccionde memeria ID resultado de la busqieda;
/// @param index  Puntere que le invia por direccionde memeria Indicie resultado de la busqieda;
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int parser_BuscarPorID (LinkedList* pArrayListEmployee, int* idObtenida, int* index)
{
	int retorno;
	int i;
	int lenghtLL;
	int idABuscar;
	int idUnboxing;
	Employee* peEmployee;

	retorno=0;
	if(pArrayListEmployee!=NULL)
	{
		lenghtLL=ll_len(pArrayListEmployee);
		if(lenghtLL>0)
		{
			ObtenerInt(&idABuscar, "\nIngrese el ID del empleado: ", "\n No es un ID Valido.", 3);
			for(i=0;i<lenghtLL;i++)
			{
				peEmployee=(Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(peEmployee, &idUnboxing);
				if(idUnboxing==idABuscar)
				{
					*idObtenida=idUnboxing;
					*index=i;
					printf("\n  ID            NOMBRE       HsTRABAJADAS      SUELDO \n");
					parser_OneEmployee(pArrayListEmployee, i);
					retorno=1;
					break;
				}
			}
		}
	}

	return retorno;
}

/// @fn int parser_ModificarEmployee(LinkedList*, int*)
/// @brief Modifica nombre, horas trabajadas y/o sueldo de un empleado determinado selecioando por ID
///
/// @param pArrayListEmployee puntero a linqked list el cual almacena por indices a cada empleado en una lsita.
/// @param index Punteroq ue recive la mdirección de memoria del resultado de la busqueda por ID
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int parser_ModificarEmployee (LinkedList* pArrayListEmployee, int* index)
{
	int retorno;
	int opcion;
	char nombre[51];
	int hsTarabajdas;
	int sueldo;
	Employee* peEmpleado=NULL;

	retorno=0;

	if(pArrayListEmployee!=NULL)
	{

		peEmpleado=(Employee*)ll_get(pArrayListEmployee,*index);
		do{
			opcion=SubMenuModificacion();
			switch (opcion)
			{
				case 1:
					if(!ObtenerSoloLetras(nombre, 51, "\n Ingrese el nuevo Nombre: ", 3))
					employee_setNombre(peEmpleado, nombre);
				break;
				case 2:
					if(!ObtenerIntConLimite(&hsTarabajdas, "\n Ingrese las Horas Trabajadas: ", "\n--Error--Dato invalido debe ser un numero entre 0 y 2000.", 0, 2000, 3))
					employee_setHorasTrabajadas(peEmpleado, hsTarabajdas);
				break;
				case 3:
					if(!ObtenerIntConLimite(&sueldo, "\n Ingrese el sueldo: ", "\n--Error--Dato invalido debe ser un numero entre 1000 y 1000000.", 1000, 1000000, 3))
					employee_setSueldo(peEmpleado, sueldo);
				break;
				case 0:
					printf("\n...\n");
				break;
			}
			retorno=1;
		}while(opcion!=0);
	}

	return retorno;
}


/// @fn int passer_BajaEmployee(LinkedList*, int*)
/// @brief Elimina primero el empleado de memorai dinamica y luego elimina el nodo de la linkedlist.
///
/// @param pArrayListEmployee puntero a linqked list el cual almacena por indices a cada empleado en una lsita.
/// @param index Punteroq ue recive la mdirección de memoria del resultado de la busqueda por ID
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int passer_BajaEmployee(LinkedList* pArrayListEmployee, int* index)
{
	int retorno;
	//int opciones;
	//int lenghtLLBajas;
	char respuesta;
	Employee* peEmpleado=NULL;
	//LinkedList* bajasMomentaneas;
	retorno=0;


	if(pArrayListEmployee!=NULL)
	{
		peEmpleado=(Employee*)ll_get(pArrayListEmployee,*index);
		respuesta=PedirChar("\n---Warning---ATENCION! Esta accion borrara DEFINITIVAMENTE al Empleado.\n\tDesea Proceder? S-N: ");
		respuesta=tolower(respuesta);
		if(respuesta=='s')
		{
			employee_delete(peEmpleado);
			parser_BajaDefinitva(pArrayListEmployee, index);
			retorno=1;
		}
		/*do{
			opciones=SubMenuBajaEmpleado();
			switch (opciones)
			{
				case 1:
					bajasMomentaneas = ll_newLinkedList();
					if(!parser_BajaMomentanea(pArrayListEmployee,index, bajasMomentaneas))
					{
						printf("\n---Error---En baja momentanea.");
					}
					lenghtLLBajas=ll_len(bajasMomentaneas);
					retorno=1;
				break;
				case 2:
					respuesta=PedirChar("\n---Warning---ATENCION! Esta accion borrara DEFINITIVAMENTE al Empleado.\n\tDesea Proceder? S-N: ");
					respuesta=tolower(respuesta);
					if(respuesta=='s')
					{
						parser_BajaDefinitva(pArrayListEmployee, index, peEmpleado);
						retorno=1;
					}
				break;
				case 3:
					if(lenghtLLBajas>0)
					{
						parser_EmployeeList(bajasMomentaneas);
					}
					else
					{
						printf("\n\tLista vacia.");
					}
				break;
				case 0:
					printf("\n...\n");
				break;
			}
		}while(opciones!=0);*/
	}
	return retorno;
}

/*int parser_BajaMomentanea (LinkedList* pArrayListEmployee, int* index, LinkedList* bajasMomentaneas)
{
	Employee* peEmployee=NULL;
	int retorno;

	retorno=0;

	if(pArrayListEmployee!=NULL && bajasMomentaneas!=NULL && index!=NULL)
	{
		peEmployee=(Employee*)ll_pop(pArrayListEmployee, *index);
		ll_add(bajasMomentaneas, peEmployee);
		//ll_push(bajasMomentaneas, *index, peEmployee);
		retorno=1;
	}

	return retorno;
}*/

/// @fn int parser_BajaDefinitva(LinkedList*, int*, Employee*)
/// @brief Borra el nodo de la linkedlist seleccionado:
///
/// @param pArrayListEmployee puntero a linqked list el cual almacena por indices a cada empleado en una lsita.
/// @param index ndex Punteroq ue recive la mdirección de memoria del resultado de la busqueda por ID
/// @param peEemployeeBajaPermante
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int parser_BajaDefinitva (LinkedList* pArrayListEmployee, int* index)
{
	int retorno;
	//Employee* peEmployee;

	retorno=0;

	if(pArrayListEmployee!=NULL && index!=NULL )
	{
		//free(peEemployeeBajaPermante);
		ll_remove(pArrayListEmployee, *index);
		retorno=1;
	}
	return retorno;
}

/// @fn int parser_SaveAsAText(FILE*, LinkedList*)
/// @brief Garda loa todos lso datos que se en ecuntran en la linkedlist en un archivo de texto.csv
///
/// @param pFile Punterp al archivo donde se dea guardar lso doatos.
/// @param pArrayListEmployee puntero a linqked list el cual almacena por indices a cada empleado en una lsita.
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.
int parser_SaveAsAText (FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	int i;
	int lenghtLL;
	int id;
	char idString[10];
	char nombre[128];
	int hsTrabajadas;
	char hsTrabajadasString[6];
	int sueldo;
	char sueldoString[10];
	Employee* peEmployee;


	retorno=0;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		lenghtLL=ll_len(pArrayListEmployee);
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		for(i=0;i<lenghtLL;i++)
		{
			peEmployee=(Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(peEmployee, &id);
			sprintf(idString,"%d",id);
			employee_getNombre(peEmployee, nombre);
			employee_getHorasTrabajadas(peEmployee, &hsTrabajadas);
			sprintf(hsTrabajadasString,"%d",hsTrabajadas);
			employee_getSueldo(peEmployee, &sueldo);
			sprintf(sueldoString,"%d",sueldo);

			fprintf(pFile,"%s,%s,%s,%s\n",idString,nombre,hsTrabajadasString,sueldoString);
		}
		retorno=1;
	}

	return retorno;
}


/// @fn int parser_SaveAsBinary(FILE*, LinkedList*)
/// @brief arda loa todos lso datos que se en ecuntran en la linkedlist en un archivo de Binario .dat
///
/// @param pFile Punterp al archivo donde se dea guardar lso doatos.
/// @param pArrayListEmployee puntero a linqked list el cual almacena por indices a cada empleado en una lsita.
/// @return int 0 si los punteros estan en NULL y 1 si pudo parser con normalidad.n
int parser_SaveAsBinary (FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	int i;
	int lenghtLL;
	Employee* peEmployee;


	retorno=0;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		lenghtLL=ll_len(pArrayListEmployee);
		for(i=0;i<lenghtLL;i++)
		{
			peEmployee=(Employee*)ll_get(pArrayListEmployee, i);

			if(peEmployee==NULL || fwrite((Employee*)peEmployee,sizeof(Employee),1,pFile)!=1)
			{
				break;
			}

		}

	 }
	if(i > 0 && i == lenghtLL)
	{
		retorno=1;

	}

	return retorno;
}







































