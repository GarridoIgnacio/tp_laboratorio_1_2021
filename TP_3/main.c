
#include "Controller.h"



/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf (stdout,NULL);

	int option;
	int lenghtLL;
	LinkedList* listaEmpleados = ll_newLinkedList();
	LinkedList* ListaOrdenamientos= ll_newLinkedList();

	lenghtLL=ll_len(listaEmpleados);

  do{
	        system("cls");
			option=MenuPrincipal ();

			switch(option)
			{
				case 1:
					controller_loadFromText("C:\\UTN Programación\\Programa y Labo 1\\tp_laboratorio_1\\TP_3\\data.csv", listaEmpleados);
					lenghtLL=ll_len(listaEmpleados);

					CortarElClear();
				break;
				case 2:
					controller_loadFromBinary("C:\\UTN Programación\\Programa y Labo 1\\tp_laboratorio_1\\TP_3\\data_Bin.dat", listaEmpleados);
					lenghtLL=ll_len(listaEmpleados);
					CortarElClear();
				break;
				case 3:
					if(listaEmpleados!=NULL && lenghtLL>0)
					{
						controller_addEmployee(listaEmpleados);

					}
					else
					{
						printf("\n\tNo se cargo ninguna lista.");
					}
					CortarElClear();
				break;
				case 4:
					if(listaEmpleados!=NULL && lenghtLL>0)
					{
						controller_editEmployee(listaEmpleados);
					}
					else
					{
						printf("\n\tNo se cargo ninguna lista.");
					}
					CortarElClear();
				break;
				case 5:
					if(listaEmpleados!=NULL && lenghtLL>0)
					{
						controller_removeEmployee(listaEmpleados);
					}
					else
					{
						printf("\n\tNo se cargo ninguna lista.");
					}
					CortarElClear();
				break;
				case 6:
					if(listaEmpleados!=NULL && lenghtLL>0)
					{
						controller_ListEmployee(listaEmpleados);
					}
					else
					{
						printf("\n\tNo se cargo ninguna lista.");
					}
					CortarElClear();
				break;
				case 7:
					if(listaEmpleados!=NULL && lenghtLL>0)
					{
						ListaOrdenamientos=ll_clone(listaEmpleados);
						controller_sortEmployee(ListaOrdenamientos);
						ll_deleteLinkedList(ListaOrdenamientos);
					}
					else
					{
						printf("\n\tNo se cargo ninguna lista.");
					}
					CortarElClear();
				break;
				case 8:
					if(listaEmpleados!=NULL && lenghtLL>0)
					{
						controller_saveAsText("C:\\UTN Programación\\Programa y Labo 1\\tp_laboratorio_1\\TP_3\\data.csv", listaEmpleados);
					}
					else
					{
						printf("\n\tNo se cargo ninguna lista.");
					}
					CortarElClear();
				break;
				case 9:
					if(listaEmpleados!=NULL && lenghtLL>0)
					{
						controller_saveAsBinary("C:\\UTN Programación\\Programa y Labo 1\\tp_laboratorio_1\\TP_3\\data_Bin.dat", listaEmpleados);
					}
					else
					{
						printf("\n\tNo se cargo ninguna lista.");
					}
					CortarElClear();
				break;
				case 0:
					ll_deleteLinkedList(listaEmpleados);
					ArtHomero();
					CortarElClear();
					printf("\n\n\n\t\t\tGood Bey");
				break;
			}

    }while(option!=0);


    return 0;
}

