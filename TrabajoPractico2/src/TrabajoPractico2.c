/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : Catalina Violante
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "utn.h"
#include <string.h>
#define QTY_EMPLOYEE 1000

int main(void)
{
	setbuf(stdout,NULL);
	Employee list[QTY_EMPLOYEE];
	int option;
	int reportOption;
	int order;
	int flagEmployee=0;
	float averageSalary;
	int quantityIds;
	int higherSalary;


	employee_initArray(list,QTY_EMPLOYEE);

	do
	{
		switch(employee_mainMenu(&option))
		{
			case 1:

					if(employee_GetData(list, QTY_EMPLOYEE)==0)
					{
						printf("\nEmpleado cargado correctamente\n");
						flagEmployee=1;
					}
				break;
			case 2:
					if(employee_modifyRecord(list,QTY_EMPLOYEE)==0 && flagEmployee==1)
					{
						printf("\nEmpleado modificado correctamente\n");
					}
					else
					{
						printf("No se pudo realizar la modificacion\n");
					}
				break;
			case 3:
					if(employee_delete(list,QTY_EMPLOYEE)==0 && flagEmployee==1)
					{
						printf("\nEmpleado borrado correctamente\n");
					}
				break;
			case 4:

				do
				{
					switch(employee_report(&reportOption))
						{
						case 1:
								if(utn_getNumero("\nOpcion 1 :Ordenar de manera ascendente.\n"
										"Opcion 2 : Ordenar de manera descendente.\n"
										"OPCION 3 : VOLVER AL MENU DE INFORMES.\n\n"
										"Ingrese opcion elegida: ","\nError,Opcion incorrecta.\n",&order,3,3,1)==0)
								{
									employee_sortEmployee(list, QTY_EMPLOYEE, order);
								}
							break;

						case 2:
								employee_print(list, QTY_EMPLOYEE);
							break;
						case 3:
							employee_totalAverageSalaries(list,QTY_EMPLOYEE);
							break;
						}
				}while(reportOption!=4);


					break;

		}
	}while(option!=5);



	return EXIT_SUCCESS;
}
