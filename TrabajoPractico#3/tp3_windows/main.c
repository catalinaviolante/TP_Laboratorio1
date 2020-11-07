#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    int menuChoosenOption;
     int option;
     int listFlag=0;

     LinkedList* listaEmpleados = ll_newLinkedList();
     do{
     	if(utn_getMenu(&menuChoosenOption, 2, 1, 10)==0)
     	{
 			switch(menuChoosenOption)
 			{
 				case 1:
 					if(listFlag== 0 && !controller_loadFromText("data.csv",listaEmpleados))
 					{
 						printf("\nLa lista de empleados fue cargada correctamente!\n");
 						listFlag=1;
 					}
 					else
 					{
 						if( !utn_getInt("\nYa existe una lista, desea reemplazarla?:  1: Aceptar, 2:Cancelar.", "\nERROR!", &option, 2, 1, 2) &&
 							option==1 && !controller_loadFromText("data.csv", listaEmpleados))
 						{
 							printf("\nLa lista ha sido cargada con exito!\n");
 						}
 						else
 						{
 							printf("\nError: no fue posible la carga de empleados.\n");
 						}
 					}
 				break;
 				case 2:
 					if(listFlag==0 && !controller_loadFromBinary("data.bin", listaEmpleados))
 					{
 						printf("\nLa lista(en binario) de empleados fue cargada correctamente!\n");
 						listFlag=1;
 					}
 					else
 					{
 						if( !utn_getInt("\nYa existe una lista, desea reemplazarla?:  1: Aceptar, 2:Cancelar.", "\nERROR!", &option, 2, 1, 2) &&
 							option==1 && !controller_loadFromBinary("data.bin", listaEmpleados))
 						{
 							printf("\nLa lista ha sido cargada con exito!\n");
 						}
 						else
 						{
 							printf("\nError: no fue posible la carga de empleados.\n");
 						}
 					}
 				break;
 				case 3:
 					if(listFlag)
 					{
 						if(!controller_addEmployee(listaEmpleados))
 						{
 						printf("\nEmpleado cargado exitosamente!\n");
 						}
 					}
 					else
 					{
 						printf("\nNo fue posible realizar la carga del empleadx.\n");
 					}
 				break;
 				case 4:
 					if(!ll_isEmpty(listaEmpleados))
 					{
 						if(!controller_editEmployee(listaEmpleados))
 						{
 							printf("\nModificacion de empleadx exitosa!\n");
 						}
 					}
 					else
 					{
 						printf("\nNo fue posible realizar la modificacion del empleadx.\n");
 					}
 				break;
 				case 5:
 					if(!ll_isEmpty(listaEmpleados))
 					{
 						if(!controller_removeEmployee(listaEmpleados))
 						{
 							printf("\nBaja de empleadx exitosa!\n");
 						}
 					}
 					else
 					{
 						printf("\nNo fue posible realizar la baja del empleadx.\n");
 					}
 				break;
 				case 6:
 					if(!ll_isEmpty(listaEmpleados))
 					{
 						if(!controller_ListEmployee(listaEmpleados))
 						{
 							printf("\nFin de la impresion\n");
 						}
 					}
 					else
 					{
 						printf("\nError en la impresion.\n");
 					}
 				break;
 				case 7:
 					if(!ll_isEmpty(listaEmpleados))
 					{
 						if(!controller_sortEmployee(listaEmpleados))
 						{
 							printf("\nLista ordenada.");
 						}
 					}
 					else
 					{
 						printf("\nNo fue posible ordenar la lista.\n");
 					}
 				break;
 				case 8:
 					if(listFlag && !controller_saveAsText("data.csv", listaEmpleados))
 					{
 						printf("\nSe han guardado exitosamente lxs empleadxs en el archivo!\n");
 					}
 					else
 					{
 						printf("\nError al guardar en el archivo.\n");
 					}
 				break;
 				case 9:
 					if(listFlag && !controller_saveAsBinary("data.bin", listaEmpleados))
 					{
 						printf("\nSe han guardado exitosamente lxs empleadxs en el archivo binario!\n");
 					}
 					else
 					{
 						printf("\nError al guardar en el archivo.\n");
 					}
 				break;
 			}
     	}
     }while(menuChoosenOption != 10);
     ll_deleteLinkedList(listaEmpleados);
     printf("Gracias, vuelva pronto!");
     return 0;
}

