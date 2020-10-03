/*
 * employee.h
 *
 *
 *      Author: Catalina Violante
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define TRUE 1
#define FALSE 0
#define NAME_LENGHT 51
#define QTY_EMPLOYEE 1000
#define QTY_SECTOR 4

typedef struct
{
	char name[NAME_LENGHT];
	char lastName [NAME_LENGHT];
	float salary;
	int sector;
	int isEmpty;
	int id;
}Employee;

int employee_mainMenu(int* pOpcion);
int employee_report(int* pOpcion);
int employee_initArray(Employee* pArray, int len);
int employee_GetData(Employee* pArray,int len);
int employee_add(Employee* pArray,int len ,int indice,char* name,char* lastName,int sector,float salary,int id);
int employee_findFreeIndex(Employee* pArray, int len, int* pResultado);
int employee_modifyRecord(Employee* pArray,int limite);
int employee_delete(Employee* pArray,int limite);
int employee_sortEmployee(Employee* pArray, int len,int order);
int employee_print(Employee* pArray, int len);
int employee_totalAverageSalaries(Employee* pArray,int len);
int employee_higherSalary(Employee* pArray,int len,float promedio, int* pResultado);
int employee_averageSalary(float salario,int cantidadId,float* pResultado);
int employee_countingById(Employee* pArray,int len,int* cantidadId);
int employee_salary(Employee* pArray,int len,float* pResultado);
int employee_searchIndexById (Employee* pArray, int limite,int idBuscar,int * pIndice);


#endif /* EMPLOYEE_H_ */
