/*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: Ignacio
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Controller.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeList(LinkedList* pArrayListEmployee);

int parser_OneEmployee (LinkedList* pArrayListEmployee, int index);

int parser_BuscarIdMaximo (LinkedList* pArrayListEmployee);

int parser_GuardarIdMaximoText (int* idMaximo);

int parser_CopiarUlrimoID (int* ultimoID);

int parser_PedirCampos (int* id, char* nombre,int* hsTrabajadas,int* sueldo );

int parser_BuscarPorID (LinkedList* pArrayListEmployee, int* idObtenida, int* index);

int parser_ModificarEmployee (LinkedList* pArrayListEmployee, int* index);

int passer_BajaEmployee(LinkedList* pArrayListEmployee, int* index);

//int parser_BajaMomentanea (LinkedList* pArrayListEmployee, int* index,LinkedList*bajasMomentaneas);

int parser_BajaDefinitva (LinkedList* pArrayListEmployee, int* index);

int parser_SaveAsAText (FILE* pFile , LinkedList* pArrayListEmployee);

int parser_SaveAsBinary (FILE* pFile , LinkedList* pArrayListEmployee);

//int parser_LoadBinary (FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
