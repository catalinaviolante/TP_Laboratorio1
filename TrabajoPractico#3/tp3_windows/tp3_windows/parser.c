#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#define BUFFER_SIZE 4096
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{


	int returnValue=-1;
	char bufferId[BUFFER_SIZE];
	char bufferName[BUFFER_SIZE];
	char bufferHours[BUFFER_SIZE];
	char bufferSalary[BUFFER_SIZE];
	Employee* bufferEmployee;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		ll_clear(pArrayListEmployee);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferHours,bufferSalary)==4)
			{
				bufferEmployee = employee_newCharParameters(bufferId, bufferName, bufferHours, bufferSalary);
				ll_add(pArrayListEmployee, bufferEmployee);
				returnValue=0;
			}
			else
			{
				employee_delete(bufferEmployee);
			}
		}while(feof(pFile)==0);
	}
    return returnValue;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int returnValue=-1;
	Employee* bufferEmployee;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		ll_clear(pArrayListEmployee);
		do
		{
			bufferEmployee = employee_new();
			if( fread(bufferEmployee,sizeof(Employee),1,pFile)==1 )
			{
				ll_add(pArrayListEmployee, bufferEmployee);
				returnValue=0;
			}
			else
			{
				employee_delete(bufferEmployee);
			}
		}while(feof(pFile)==0);
	}
	return returnValue;
}
