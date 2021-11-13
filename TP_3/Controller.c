
#include  "Controller.h"


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;

	retorno=0;
	if(pArrayListEmployee!=NULL && pArrayListEmployee>0)
	{
		parser_EmployeeList(pArrayListEmployee);
		retorno=1;
	}

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile=NULL;
	int retorno;

	retorno=0;

	pFile=fopen(path,"r");
	if(parser_EmployeeFromText(pFile, pArrayListEmployee))
	{
		//parser_BuscarIdMaximo(pArrayListEmployee);
		printf("\n Los datos fueron cargados con exito. \n");
		retorno=1;
	}
	else
	{
		printf("\n ---ERROR---Ocurrio un error en la carga de detos. \n");
	}
	fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile=NULL;
	int retorno;

	retorno=0;

	pFile=fopen(path,"rb");

		if(pFile!=NULL)
		{

			if(parser_EmployeeFromBinary(pFile, pArrayListEmployee)==1)
			{
				//parser_BuscarIdMaximo(pArrayListEmployee);
				printf("\nLos datos fueron cargados con exito.\n");
				retorno=1;
			}
			else
			{
				printf("\nERROR LOADBIN.\n");
			}

		}
		else
		{
			printf("\n-- Error---No queda suficiente memoria disponible.\n");
		}


	fclose(pFile);

	 return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int ulitmoId;
	char nombre[51];
	int hsTrabajadas;
	int sueldo;
	Employee* peEmpleado=NULL;

	retorno=0;

	if(pArrayListEmployee!=NULL&&
	   parser_BuscarIdMaximo(pArrayListEmployee)&&
	   parser_CopiarUlrimoID(&ulitmoId)&&
	   parser_PedirCampos(&ulitmoId, nombre, &hsTrabajadas, &sueldo))
	{
		peEmpleado=employee_newParametros(&ulitmoId, nombre,&hsTrabajadas,&sueldo);

		if(peEmpleado!=NULL && !ll_add(pArrayListEmployee, peEmpleado))
		{
			retorno=1;
		}
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int idDeseada;
	int index;

	retorno=0;

	if(pArrayListEmployee!=NULL &&
	   parser_BuscarPorID(pArrayListEmployee, &idDeseada,&index)&&
	   parser_ModificarEmployee(pArrayListEmployee, &index))
	{
		printf("\n Se modifico al Empledado con Exito.");
		retorno=1;
	}
	else
	{
		printf("\n El ID no existe.");
	}

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int idDeseada;
	int index;

	retorno=0;

	if(pArrayListEmployee!=NULL &&
	   parser_BuscarPorID(pArrayListEmployee, &idDeseada,&index))
	{
		if(passer_BajaEmployee(pArrayListEmployee, &index))
		{
			printf("\n Se dio de Baja al Empledado con Exito.");
		}
		else
		{
			printf("\n---Error---NO se dio de Baja a ningun Empledado.");
		}
	}
	else
	{
		printf("\n El ID no existe.");
	}

    return retorno;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int orden;

	retorno=0;

	if(pArrayListEmployee!=NULL)
	{
		ObtenerIntConLimite(&orden, "\nIngrese el criterio de ordenamiento: Siendo 1 ascendente y 0 desendente: ", "\n---Error-- Opcion no Valida!", 0, 1, 3);
		ll_sort(pArrayListEmployee, employee_OerdenarPorNombre, orden);
		controller_ListEmployee(pArrayListEmployee);
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;

	retorno=0;

	pFile=fopen(path,"w");
	if(parser_SaveAsAText(pFile, pArrayListEmployee))
	{
		printf("\n Los datos fueron guardados con exito. \n");
		retorno=1;
	}
	else
	{
		printf("\n ---ERROR---Ocurrio un error en la carga de detos. \n");
	}
	fclose(pFile);

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;

	retorno=0;

	pFile=fopen(path,"wb");
	if(parser_SaveAsBinary(pFile, pArrayListEmployee)==1)
	{

		printf("\n Los datos fueron guardados con exito. \n");
		retorno=1;
	}
	else
	{
		printf("\n ---ERROR---Ocurrio un error en la carga de detos. \n");
	}
	fclose(pFile);

    return retorno;
}

