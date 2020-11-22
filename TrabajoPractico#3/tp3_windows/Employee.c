#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
#define BUFFER_SIZE 4096

static int isValidInt(char string[]);
static int isValidFloat(char string[]);
static int isValidString(char* string);

//PRIVATE FUNCTIONS
static int isValidInt(char string[])
{
	int retornar = 1;
	int i = 0;

	if(string!=NULL && strlen(string)>0)
	{
		if(string[0]=='-')
		{
			i=1;
		}
		for(;i<strlen(string);i++)
		{
			if(string[i]>'9' || string[i]<'0')
			{
				retornar=0;
				break;
			}
		}
	}
	return retornar;
}

static int isValidFloat(char string[])
{
	int returnValue = 1;
	int i = 0;
	int commaCounter=0;

	if(string!=NULL && strlen(string)>0)
	{
		if(string[0]=='-')
		{
			i=1;
		}
		for(;i<strlen(string);i++)
		{
			if(string[i]=='.')
			{
				commaCounter++;
			}
			if(commaCounter>1 || ((string[i]>'9' || string[i]<'0') && string[i]!='.'))
			{
				returnValue=0;
				break;
			}
		}
	}
	return returnValue;
}

static int isValidString(char* string)
{
	int retornar=1;
	if(string!=NULL && strlen(string)>0)
	{
		for(int i=0;i<strlen(string);i++)
		{
			if((string[i]<'a' || string[i]>'z') && (string[i]<'A' || string[i]>'Z') && string[i]!=32 && string[i]!=45)
			{
				retornar=0;
				break;
			}
		}
	}
	return retornar;
}




Employee* employee_new()
{

	Employee* this;
	this=(Employee*)malloc(sizeof(Employee));

	if(this!=NULL)
	{
		return this;
	}
	return NULL;

}

Employee* employee_newCharParameters(char* charId,char* charName,char* charWorkedHours, char* charSalary)
{
	Employee* this = employee_new();
	if(this!=NULL && charId!= NULL && charName!=NULL && charWorkedHours!=NULL && charSalary!=NULL)
	{
		if(  employee_setIdTxt(this, charId)!=-1 &&
		     employee_setName(this, charName)!=-1 &&
			 employee_setWorkedHoursTxt(this, charWorkedHours)!=-1 &&
			 employee_setSalaryTxt(this, charSalary)!=-1)
		{
			return this;
		}
	}
	employee_delete(this);
	return NULL;
}

int employee_setSalaryTxt(Employee* this, char* sueldo)
{
	int output=-1;
	char buffer[NAME_SIZE];
	if(this!=NULL && sueldo!=NULL && isInt(sueldo)==1)
	{
			strncpy(buffer, sueldo, NAME_SIZE);
			this->sueldo=atoi(buffer);
			output=0;
	}
	return output;
}
int employee_setSalary(Employee* this,int sueldo)
{
	int output=-1;
	if(this!=NULL && sueldo>0)
	{
		this->sueldo = sueldo;
		output=0;
	}
	return output;

}

Employee* employee_newParameters(int id,char* name,int workedHours, float salary)
{
	Employee* this = employee_new();
	if(this!=NULL && id>-1 && name!=NULL && workedHours>0 && salary>0)
	{
		if(  employee_setId(this, id)!=-1 &&
		     employee_setName(this, name)!=-1 &&
			 employee_setWorkedHours(this, workedHours)!=-1 &&
			 employee_setSalary(this, salary)!=-1)
		{
			return this;
		}
	}
	employee_delete(this);
	return NULL;
}


void employee_delete(Employee* this)
{
	free(this);
}
//GETTERS
int employee_getId(Employee* this, int* id)
{
	int returnValue=-1;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		returnValue=0;
	}
	return returnValue;
}

int employee_getName(Employee* this, char* name)
{
	int returnValue=-1;
	if(this!=NULL && name!=NULL)
	{
		strncpy(name, this->nombre, NAME_SIZE);
		returnValue=0;
	}
	return returnValue;
}

int employee_getWorkedHours(Employee* this, int* workedHours)
{
	int returnValue=-1;
	if(this!=NULL && workedHours!=NULL)
	{
		*workedHours = this->horasTrabajadas;
		returnValue=0;;
	}
	return returnValue;
}

int employee_getSalary(Employee* this, float* salary)
{
	int returnValue=-1;
	if(this!=NULL && salary!=NULL)
	{
		*salary = this->sueldo;
		returnValue=0;
	}
	return returnValue;
}

//SETTERS
int employee_setIdTxt(Employee* this, char* id)
{
	int returnValue=-1;
	char bufferId[BUFFER_SIZE];
	if(this!=NULL && id!=NULL && isValidInt(id)==1)
	{
		strncpy(bufferId, id, BUFFER_SIZE);
		this->id = atoi(bufferId);
		returnValue=0;
	}
	return returnValue;
}

int employee_setId(Employee* this, int id)
{
	int returnValue=-1;
	if(this!=NULL && id>0)
	{
		this->id = id;
		returnValue=0;
	}
	return returnValue;
}

int employee_setName(Employee* this, char* name)
{
	int returnValue=-1;
	if(this!=NULL && name!=NULL && isValidString(name)==1)
	{
		strncpy(this->nombre, name, NAME_SIZE);
		returnValue=0;
	}
	return returnValue;
}

int employee_setWorkedHours(Employee* this, int workedHours)
{
	int returnValue=-1;
	if(this!=NULL && workedHours>0)
	{
		this->horasTrabajadas = workedHours;
		returnValue=0;
	}
	return returnValue;
}
int employee_setWorkedHoursTxt(Employee* this, char* workedHours)
{
	int returnValue=-1;
	char bufferHours[BUFFER_SIZE];
	if(this!=NULL && workedHours>0 && isValidInt(workedHours)==1)
	{
		strncpy(bufferHours, workedHours, BUFFER_SIZE);
		this->horasTrabajadas = atoi(bufferHours);
		returnValue=0;
	}
	return returnValue;
}

int employee_setSueldo(Employee* this, float salary)
{
	int returnValue=-1;
	if(this!=NULL && salary>0)
	{
		this->sueldo = salary;
		returnValue=0;
	}
	return returnValue;
}
int employee_setSueldoTxt(Employee* this, char* salary)
{
	int returnValue=-1;
	char bufferSalary[BUFFER_SIZE];
	if(this!=NULL && salary !=NULL && isValidFloat(salary)==1)
	{
		strncpy(bufferSalary, salary, BUFFER_SIZE);
		this->sueldo = atof(bufferSalary);
		returnValue=0;
	}
	return returnValue;
}




int employee_print(Employee* this)
{
	int returnValue=-1;
	char bufferName[BUFFER_SIZE];
	int bufferId;
	int bufferHours;
	float bufferSalary;
	if(this!=NULL)
	{
		if( !employee_getId(this, &bufferId) &&
			!employee_getName(this, bufferName) &&
			!employee_getWorkedHours(this, &bufferHours) &&
			!employee_getSalary(this, &bufferSalary))
		{
			printf("\n%-6d%-20s%-15d%.2f", bufferId, bufferName, bufferHours, bufferSalary);
			returnValue = 0;
		}
	}
	return returnValue;
}

int employee_sort(void* employeeOne, void* employeeTwo)
{
	int returnValue;
	Employee* bufferFirstEmp = (Employee*) employeeOne;
	Employee* bufferSecondEmp = (Employee*) employeeTwo;
	char bufferNameOne[BUFFER_SIZE];
	char bufferNameTwo[BUFFER_SIZE];
	if(employeeOne!=NULL && employeeTwo !=NULL)
	{
		employee_getName(bufferFirstEmp, bufferNameOne);
		employee_getName(bufferSecondEmp, bufferNameTwo);
		if(strncmp(bufferNameOne,bufferNameTwo,NAME_SIZE)>0)
		{
			returnValue=1;
		}
		else
		{
			if(strncmp(bufferNameOne,bufferNameTwo,NAME_SIZE)<0)
			{
				returnValue=-1;
			}
			else
			{
				returnValue=0;
			}
		}
	}
	return returnValue;
}

int employee_sortById(void* employeeOne, void* employeeTwo)
{
	int returnValue;
	Employee* bufferFirstEmp = employeeOne;
	Employee* bufferSecondEmp = employeeTwo;
	int bufferIdOne;
	int bufferIdTwo;
	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		employee_getId(bufferFirstEmp, &bufferIdOne);
		employee_getId(bufferSecondEmp, &bufferIdTwo);
		if(bufferIdOne>bufferIdTwo)
		{
			returnValue=1;
		}
		else
		{
			if(bufferIdOne<bufferIdTwo)
			{
				returnValue=-1;
			}
			else
			{
				returnValue=0;
			}
		}
	}
	return returnValue;
}
