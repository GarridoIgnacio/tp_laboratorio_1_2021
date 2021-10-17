/*
 * Employee.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Ignacio
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "GetsUtn.h"
#include "Math_TP.h"
#define Vacio 1
#define Activo 0
#define StringTam 51

struct
{
	int id;
	char name[StringTam];
	char lastName[StringTam];
	float salary;
	int sector;
	int isEmpty;
}typedef eEmployee;

#endif /* EMPLOYEE_H_ */

int initEmployees(eEmployee* list,int lenght);

void MostrarUnEmp (eEmployee list);

int printEmployees (eEmployee* list, int lenght);

int CargaEmpleado (eEmployee* lista, int tamano);

int addEmployee(eEmployee* list, int lenght, int id, char name[], char lastName[],float salary,int sector);

int AutoIncrementID (eEmployee* list, int lenght, int* idEmpleadoAutomatico);

int findeEmployeeById (eEmployee* list, int lenght, int id);

int ModificarEmpleado (eEmployee* list, int lenght);

int BajaEmpleado(eEmployee* list, int lenght);

int removeEmployee (eEmployee* list, int lenght, int id);

int BuscarMinimoYMaximo (eEmployee* lista, int longitud,int* IdMinimo,int* IdMaximo);

int OrdenarPorApellidoySector(eEmployee* list, int lenght,int* order);

int sortEmployees(eEmployee* list, int lenght, int order);

int SumaYPromedioSalarios (eEmployee* lista,int lenght, float* resPromedio, float* resSuma);

int SalarioMayorPromedio (eEmployee* lista, int lenght);

int VerificarEstado (eEmployee* lista, int lenght);


