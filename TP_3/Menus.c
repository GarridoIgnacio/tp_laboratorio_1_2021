/*
 * Menus.c
 *
 *  Created on: 6 nov. 2021
 *      Author: Ignacio
 */


#include "Controller.h"


int MenuPrincipal ()
{
	int opcion;



			//system("clear");
			printf("\n\t\t\t\t----------------------------------------------------------------------------------");
			printf("\n \t\t\t\t|\t       Lista de Empleados                                                |"
				   "\n \t\t\t\t|\t                                                                         |");
			printf("\n \t\t\t\t|\t1. Cargar los empleados desde el archivo data.csv (modo texto).          |");
			printf("\n \t\t\t\t|\t2. Cargar los empleados desde el archivo data.bin (modo binario).        |");
			printf("\n \t\t\t\t|\t3. Alta de empleado                                                      |");
			printf("\n \t\t\t\t|\t4. Modificar datos de empleado                                           |");
			printf("\n \t\t\t\t|\t5. Baja de empleado.                                                     |");
			printf("\n \t\t\t\t|\t6. Listar empleados.                                                     |");
			printf("\n \t\t\t\t|\t7. Ordenar empleados.                                                    |");
			printf("\n \t\t\t\t|\t8. Guardar los datos de empleados en el archivo data.csv (modo texto).   |");
			printf("\n \t\t\t\t|\t9. Guardar los datos de empleados en el archivo data.dat (modo binario). |");
			printf("\n \t\t\t\t|\t0. Salir                                                                 |");
			printf("\n\t\t\t\t----------------------------------------------------------------------------------\n");

			ObtenerIntConLimite(&opcion, "\n\nIngrese una Opcion de 0-9: ", "\n\t\tError Opcion no valida!", 0, 9, 3);

			return opcion;

}

int SubMenuModificacion ()
{
	int opcion;

		printf("\n\t\t\t\t--------------------------------------------------");
		printf("\n \t\t\t\t|\t      Modificar datos del empleado:      |"
			   "\n \t\t\t\t|\t                                         |");
		printf("\n \t\t\t\t|\t1. Nombre.                               |");
		printf("\n \t\t\t\t|\t2. Horas Trabajadas.                     |");
		printf("\n \t\t\t\t|\t3. Sueldo.                               |");
		printf("\n \t\t\t\t|\t0. Volver.                               |");
		printf("\n\t\t\t\t--------------------------------------------------\n");

		ObtenerIntConLimite(&opcion, "\n\nIngrese una Opcion de 0-3: ", "\n\t\tError Opcion no valida!", 0, 3, 3);

		return opcion;
}

int SubMenuBajaEmpleado ()
{
	int opcion;

			printf("\n\t\t\t\t--------------------------------------------------");
			printf("\n \t\t\t\t|\t      Baja de Empleado:                  |"
				   "\n \t\t\t\t|\t                                         |");
			printf("\n \t\t\t\t|\t1. Baja Momentanea.                      |");
			printf("\n \t\t\t\t|\t2. Baja Definitiva.                      |");
			printf("\n \t\t\t\t|\t3. Lista de Bajas Momentaneas.           |");
			printf("\n \t\t\t\t|\t0. volver.                               |");
			printf("\n\t\t\t\t--------------------------------------------------\n");

			ObtenerIntConLimite(&opcion, "\n\nIngrese una Opcion de 0-3: ", "\n\t\tError Opcion no valida!", 0, 3, 3);

			return opcion;
}

void CortarElClear ()
{
	char tecla;

	printf("\n\nPara continuar ingrese una letra cualquiera..");
	fflush(stdin);
	scanf("%c",&tecla);
	printf("\n\n");
}

void ArtHomero ()
{


	printf("\n                            G##E                            ");
	printf("\n                           #      K                          ");
	printf("\n                          f        t                       ");
	printf("\n                        ;###;   ,#DjtjL#,                  ");
	printf("\n                      .;.    ;#:,,,,,,,,,D;                ");
	printf("\n                        #   #,,,,,,,,,,,,,,#               ");
	printf("\n                    D  L #:,,,,,,,,,,,,,,,,L               ");
	printf("\n                    K  iD,,,,,,,,,,,,,,,,,,,D              ");
	printf("\n                    ,  G,,,,,,,,,,,,,,,,,,,,,W             ");
	printf("\n                    , GE,,,,,,,,,,,,,,,,,,,,,,i            ");
	printf("\n                    LD,,,,,,,,,,,,,,,,,,,,,,,,t            ");
	printf("\n                    #i,,,,,,,,,,,,,,,,,,,,,,,,,D           ");
	printf("\n                    f,,,,,,,,,,,,,,,,,,,,,,,,,,t           ");
	printf("\n                    ,,,,,,,,,,,,,,,,,,,,,,,,,,,,t          ");
	printf("\n                    #,,,,,,,,,,,,,,,,,,,,,,,,,,,#          ");
	printf("\n                    W,,,,,,,,,,,,,,,,,,,,,,,,,,,,          ");
	printf("\n                    K,,,,,,,,,,,,,,,,,,,,,,,,,,,,:         ");
	printf("\n                    K,,,,,,,,,,,,,,,,,,,,,,,,,,,,iE        ");
	printf("\n                    W,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,        ");
	printf("\n                    #,,,,,,,,,,,,,,,,,,,,,,,,:K##K,f       ");
	printf("\n                    L,,,,,,,,,,,,,D    D,,,,#      #       ");
	printf("\n                      ,,,,,,,,,,,#        K,E        f     ");
	printf("\n                      ,,,,,,,,,,#          #          L    ");
	printf("\n                      ,,,,,,,,,j           ;          j    ");
	printf("\n                      #,,,,,,,,L            i              ");
	printf("\n                      t,,,,,,,,             K    :         ");
	printf("\n                      ;,,,,,,:    i        #    #    .     ");
	printf("\n                      #,,,,,,:    #        #         #     ");
	printf("\n                       :#,,,,:             t     .i,      ");
	printf("\n                        W#G,,,,t            ;;,,,,,,,i     ");
	printf("\n                      # .#;,,,,j           W,,,,,,,,,,G    ");
	printf("\n                        #,#,,,,K         #,,,,,,,,,,,#     ");
	printf("\n                      L #,:,,,,,tf      L,,,,,,,,,,,,t     ");
	printf("\n                        D#,,E,,,,,,iD#Di,,,,,,,,,,,,,;     ");
	printf("\n                        K,,,:,,,,,,,,,,,,,,,,,,:,,;#G      ");
	printf("\n                        E,,,,,,,,,,,,,,,,;#Ef;;;;;;;;E     ");
	printf("\n                          #E,,,,,,,,,,,,,E;;;;;;;;;;;;;D   ");
	printf("\n                        .,,,i,,,,,,,,,jj;;;;;;;;;;;;;;;t   ");
	printf("\n                        #t#,,,,,,,,,,#;;;;;;;;;;;;;;;;;;   ");
	printf("\n                        ft,,,,,,,,,,#;;;;;;;;;;;;;;;;;;;K  ");
	printf("\n                        f,,,,,,,,,,#;;;;;;;;;;;;;;;;;;;;;  ");
	printf("\n                        #,,,,,,,,,,;;;;;;;;;;;;;;;;;;;;;;D ");
	printf("\n                        f:jL,,,,,D;;;;;;;;;;;;;;;;;;;;;;#  ");
	printf("\n                          ,,,,,,,f;;;;;;;;;;;;;;;;;;;;;;#  ");
	printf("\n                          ,,,,,,,;;;;;;;;;;;;;;;;;;;;;;;#  ");
	printf("\n                          ,,,,,,,;;;;;;;;;;;;;;;;;;;;;;D   ");
	printf("\n                          ,,,,,,,;;;;;EDi;;;;;;;;;;;t#     ");
	printf("\n                          :,,,,,,;;;;;;;;;;;fGDDGj;j       ");
	printf("\n                          :,,,,,,t;;;;;;;;;;;;;;;;;#       ");
	printf("\n                          :,,,,,,#;;;;;;;;;;;;;;;;;.       ");
	printf("\n                          ,,,,,,,,;;;;;;;;;;;;;;;#,        ");
	printf("\n                         ,,,,,,,,#;;;;;;;;;;;;;f          ");
	printf("\n                          ,,,,,,,,,K;;;;;;;;;;;;.          ");
	printf("\n                          ,,,,,,,,,,#;;;;;;;;;E            ");
	printf("\n                          ,,,,,,,,,,,:#j;;;tKLt            ");
	printf("\n                          ,,,,,,,,,,,,,,,:::,,,W           ");
	printf("\n                          L,,,,,,,,,,,,,,,,,,,,#           ");
	printf("\n                          D,,,,,,,,,,,,,,,,,,,,E           ");
	printf("\n                          K,,,,,,,,,,,,,,,,,,,,L           ");
	printf("\n                            K,,,,,,,,,,,,,,,,,,i           ");
	printf("\n                            Kt,,,,,,,,,,,,,,,,:            ");
	printf("\n                              ;E:,,,,,,,,,,,,,,            ");
	printf("\n                                 t#t:,,,,,,:iKj           ");
	printf("\n                                        ,,,                ");
	printf("\n\nEl usuario.. ");
	printf("\n\t¿Cual es cualquiera?, veo la Esc, Ctrl y PgUp... No tiene letra cualquiera!..");

}
