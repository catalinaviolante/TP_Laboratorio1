#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NAME_SIZE 128

typedef struct
{
    int id;
    char nombre[NAME_SIZE];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newCharParameters(char* charId,char* charName,char* charWorkedHours, char* charSalary);
Employee* employee_newParameters(int id,char* name,int hours, float salary);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_setIdTxt(Employee* this,char* id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* name);
int employee_getName(Employee* this,char* name);

int employee_setWorkedHours(Employee* this,int workedHours);
int employee_setWorkedHoursTxt(Employee* this, char* workedHours);
int employee_getWorkedHours(Employee* this,int* workedHours);

int employee_setSalary(Employee* this,int salary);
int employee_setSalaryTxt(Employee* this, char* salary);
int employee_getSalary(Employee* this,float* salary);

int employee_print(Employee* this);
int employee_sort(void* employeeOne, void* employeeTwo);
int employee_sortById(void* employeeOne, void* employeeTwo);


#endif // employee_H_INCLUDED
