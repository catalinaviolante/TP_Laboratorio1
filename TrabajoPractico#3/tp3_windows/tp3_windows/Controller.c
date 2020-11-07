#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#define BUFFER_SIZE 4096

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{	int returnValue=-1;
	FILE* pFile;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile = fopen(path, "r");
		if(pFile!=NULL && !parser_EmployeeFromText(pFile, pArrayListEmployee))
		{
			printf("\nArchivo cargado con éxito.");
			returnValue=0;
		}
		else
		{
			printf("\nArchivo no existente.");
		}
		fclose(pFile);
	}
	return returnValue;

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
	int returnValue=-1;
		FILE* pFile;
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			pFile = fopen(path, "rb");
			if(pFile!=NULL && !parser_EmployeeFromBinary(pFile, pArrayListEmployee))
			{
				printf("\nArchivo cargado con éxito.");
				returnValue=0;
			}
			else
			{
				printf("\nArchivo no existente!");
			}
			fclose(pFile);
		}
		return returnValue;
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
	int returnValue=-1;
		char bufferName[BUFFER_SIZE];
		int bufferWorkedHours;
		float bufferSalary;
		int bufferId;

		Employee* bufferEmployee;
		if(pArrayListEmployee!=NULL)
		{
			if(	!utn_getString("Ingrese el nombre: ", "\nERROR: Nombre invalido.", bufferName, 2, BUFFER_SIZE) &&
				!utn_getInt("\nIngrese las horas trabajadas: ", "\nERROR: numero invalido.", &bufferWorkedHours, 2, 1, 9999) &&
				!utn_getFloat("\nIngrese sueldo: ", "\nERROR: numero invalido.", &bufferSalary, 2, 1, 999999))
			{
				bufferId = controller_searchMaxId(pArrayListEmployee);
				bufferEmployee = employee_newParameters(bufferId, bufferName, bufferWorkedHours, bufferSalary);
				ll_add(pArrayListEmployee, bufferEmployee);
				printf("\nID: %d", bufferId);
				returnValue=0;
			}
			else
			{
				printf("\nAlgo salio mal al intentar obtener los datos!\n");
			}
		}
	    return returnValue;
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
	int returnValue=-1;
		int id;
		int index;
		int choosenOption;
		char bufferName[BUFFER_SIZE];
		int bufferWorkedHours;
		float bufferSalary;
		Employee* bufferEmployee;
		if(pArrayListEmployee!=NULL)
		{
			if( !utn_getInt("\nID del empleado a modificar: ", "\nERROR: ID invalido", &id, 2, 1, 99999) &&
				!controller_findById(pArrayListEmployee, id, &index) && index>-1)
			{
				printf("\nEmpleado encontrado!\n");
				bufferEmployee = ll_get(pArrayListEmployee, index);
				employee_print(bufferEmployee);
				if(!utn_getInt( "\n\nIndique el campo que desea cambiar?\n1)Nombre.\n2)Horas trabajadas.\n3)Sueldo.\n4)Volver.\n> >Opcion:",
								"ERROR: opcion invalida" , &choosenOption, 2, 1, 4))
				{
					switch(choosenOption)
					{
						case 1:
							if( !utn_getString("Nuevo nombre: ", "\nERROR: nombre invalido", bufferName, 2, BUFFER_SIZE) &&
								!employee_setName(bufferEmployee, bufferName))
							{
								ll_set(pArrayListEmployee, index, bufferEmployee);
								returnValue=0;
							}
						break;
						case 2:
							if( !utn_getInt("\nHoras trabajadas: ", "\nERROR: numero invalido", &bufferWorkedHours, 2, 1, 9999) &&
								!employee_setWorkedHours(bufferEmployee, bufferWorkedHours))
							{
								ll_set(pArrayListEmployee, index, bufferEmployee);
								returnValue=0;
							}
						break;
						case 3:
							if( !utn_getFloat("\nNuevo salario: ", "\nERROR: numero invalido", &bufferSalary, 2, 1, 999999) &&
								!employee_setSalary(bufferEmployee, bufferSalary))
							{
								ll_set(pArrayListEmployee, index, bufferEmployee);
								returnValue=0;
							}
						break;
					}
				}
			}
			else
			{
				printf("\nNo fue posible hallar al empleadx!\n");
			}
		}
	    return returnValue;
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
	int returnValue=-1;
		int id;
		int index;
		int choosenOption;
		Employee* bufferEmployee;
		if(pArrayListEmployee!=NULL)
		{
			if( !utn_getInt("\nID del empleado a eliminar: ", "\nERROR: numero invalido", &id, 2, 1, 99999) &&
				!controller_findById(pArrayListEmployee, id, &index) && index>-1)
			{
				printf("\nEmpleado encontrado!\n");
				bufferEmployee = ll_get(pArrayListEmployee, index);
				employee_print(bufferEmployee);
				if( !utn_getInt("\n\nDesea eliminar este registro? 1: eliminar, 2: cancelar: ", "\nERROR: opcion invalida", &choosenOption, 2, 1, 2) &&
					choosenOption==1)
				{
					ll_remove(pArrayListEmployee, index);
					returnValue=0;
				}
				else
				{
					printf("\nRegistro no eliminado.\n");
				}
			}
			else
			{
				printf("\nNo fue posible hallar al empleadx.");
			}
		}
	    return returnValue;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0: OK, -1:ERROR
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int returnValue=-1;
		int len = ll_len(pArrayListEmployee);
		Employee* bufferEmployee;
		if(pArrayListEmployee!=NULL && !ll_isEmpty(pArrayListEmployee))
		{
			printf("\nID        Nombre              Horas trabajadas    Salario    ");
			printf("\n-------------------------------------------------------------");
			for(int i=0; i<len;i++)
			{
				bufferEmployee = ll_get(pArrayListEmployee, i);
				employee_print(bufferEmployee);
				returnValue=0;
			}
			printf("\n-------------------------------------------------------------");
		}
		else
		{
			printf("\nNo es posible listar empleadxs.");
		}
	    return returnValue;
}
int controller_searchMaxId(LinkedList* pArrayListEmployee)
{
	int returnValue=-1;
	int len = ll_len(pArrayListEmployee);
	Employee* bufferEmployee;
	int id;
	int maxId;
	if(pArrayListEmployee!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			bufferEmployee = ll_get(pArrayListEmployee, i);
			employee_getId(bufferEmployee, &id);
			if(i==0 || id>maxId)
			{
				maxId = id;
				returnValue = maxId+1;
			}
		}
	}
	return returnValue;
}


int controller_findById(LinkedList* pArrayListEmployee, int id, int* index)
{
	int returnValue=-1;
	int len = ll_len(pArrayListEmployee);
	int bufferId;
	Employee* bufferEmp;
	if(pArrayListEmployee!=NULL && id>0 && index!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			bufferEmp = ll_get(pArrayListEmployee, i);
			if(!employee_getId(bufferEmp, &bufferId) && bufferId == id)
			{
				returnValue = 0;
				*index = i;
				break;
			}
		}
	}
	return returnValue;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0: OK, -1:ERROR
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int returnValue=-1;
		int choosenOption;
		if(pArrayListEmployee!=NULL && !ll_isEmpty(pArrayListEmployee) &&  utn_getInt("\nSeleccione un orden\n1-Descendente \n0-Ascendente \n>:","\ERROR: numero invalido.",&choosenOption,2,-1,1)==0)
		{
			ll_sort(pArrayListEmployee,employee_sort,choosenOption);
			printf("\nLista ordenada.\n");
			returnValue=0;
		}
		else
		{
			printf("\nNo hay datos para ordenar.\n");
		}
	return returnValue;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0: OK, -1:ERROR
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int returnValue=-1;
		int len = ll_len(pArrayListEmployee);
		char bufferName[BUFFER_SIZE];
		int bufferId;
		int bufferWorkedHours;
		float bufferSalary;
		FILE* pFile;
		Employee* bufferEmp;
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			pFile = fopen(path, "w");
			if(pFile!=NULL)
			{
				ll_sort(pArrayListEmployee, employee_sortById, 1);
				fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
				for(int i=0;i<len;i++)
				{
					bufferEmp = ll_get(pArrayListEmployee, i);
					if( !employee_getId(bufferEmp, &bufferId) &&
						!employee_getName(bufferEmp, bufferName) &&
						!employee_getWorkedHours(bufferEmp, &bufferWorkedHours) &&
						!employee_getSalary(bufferEmp, &bufferSalary))
					{
						fprintf(pFile, "%d,%s,%d,%f\n",bufferId, bufferName, bufferWorkedHours, bufferSalary);
						returnValue=0;
					}
				}
				printf("Datos guardados con exitosamente.");
				fclose(pFile);
			}
		}
	    return returnValue;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0: OK, -1:ERROR
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int returnValue=-1;
		int len = ll_len(pArrayListEmployee);
		FILE* pFile;
		Employee* bufferEmployee;
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			pFile = fopen(path, "wb");
			if(pFile!=NULL)
			{
				ll_sort(pArrayListEmployee, employee_sortById, 1);
				for(int i=0;i<len;i++)
				{
					bufferEmployee = ll_get(pArrayListEmployee, i);
					fwrite(bufferEmployee, sizeof(Employee),1, pFile);
					returnValue=0;
				}
				printf("Datos guardados con exitosamente.");
				fclose(pFile);
			}
		}
		return returnValue;
}

