

#include "Controller.h"

Employee* employee_new()
{
	Employee* peAuxiliar=NULL;

	peAuxiliar= (Employee*)malloc(sizeof(Employee));

	return peAuxiliar;
}

Employee* employee_newParametros(int* id,char* nombreStr,int* horasTrabajadas,int* sueldo)
{
	Employee* peEmpleado=NULL;


	if(id!=NULL && nombreStr!=NULL && horasTrabajadas!=NULL && sueldo!=NULL)
	{
		peEmpleado=employee_new();
		employee_setId(peEmpleado,*id);
		employee_setNombre(peEmpleado,nombreStr);
		employee_setHorasTrabajadas(peEmpleado,*horasTrabajadas);
		employee_setSueldo(peEmpleado,*sueldo);
	}

	return peEmpleado;
}

void employee_delete(Employee* peEmpleado)
{
	free(peEmpleado);
}

int employee_setId(Employee* this,int id)
{
	int retorno;

	retorno=0;

	if(this!=NULL)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}


int employee_getId(Employee* this,int* id)
{
	int retorno;

	retorno=0;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;

	retorno=0;
	if(this!=NULL && nombre!=NULL)
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno=1;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;

	retorno=0;
	if(this!=NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombre,sizeof(this->nombre));
		retorno=1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;

	retorno=0;
	if(this!=NULL )
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=1;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;

	retorno=0;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;

	retorno=0;
	if(this!=NULL )
	{
		this->sueldo=sueldo;
		retorno=1;
	}

	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;

	retorno=0;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}

int employee_OerdenarPorNombre (void* primerEmpeado, void* segundoEmpleado)
{
	Employee* empleadoUno;
	Employee* empleadoDos;
	int orden;

	if(primerEmpeado!=NULL && segundoEmpleado!=NULL)
	{
		empleadoUno=(Employee*)primerEmpeado;
		empleadoDos=(Employee*)segundoEmpleado;

		orden=strcmp(empleadoUno->nombre,empleadoDos->nombre);
	}
	return orden;
}


































