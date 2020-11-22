/*
 * utn.c
 *
 *  Created on: Sep 21, 2020
 *      Author: Cat
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE 4096
#define LONG_NOMBRE 50
int utn_getMenu(int *pResult, int attemps, int min, int max)
{
	int retorno = -1;
	char bufferString[ARRAY_SIZE];
	int bufferInt;

	if(pResult != NULL && attemps >= 0 && min <= max)
	{
		do
		{
			printf("\nMenu de opciones\n"
					"1) Cargar los datos de los empleados desde 'data.csv' (modo texto)\n"
					"2) Cargar los datos de los empleados desde 'data.bin' (modo binario)\n"
					"3) Alta de empleado\n"
					"4) Modificar datos de empleado\n"
					"5) Baja de empleado\n"
					"6) Listar empleados\n"
					"7) Ordenar empleados\n"
					"8) Guardar los datos de los empleados en 'data.csv' (modo texto)\n"
					"9) Guarar los datos de los empleados en 'data.bin' (modo binario)\n"
					"10) Salir\n"
					"> > OPCION:");
			if(myGets(bufferString, ARRAY_SIZE) == 0 && isInt(bufferString) == 1)
			{
				bufferInt = atoi(bufferString);
				if(bufferInt >= min && bufferInt<= max)
				{
					*pResult = bufferInt;
					retorno = 0;
					break;
				}
				else
				{
					printf("\nError! opcion invalida");
					attemps--;
				}

			}
			else
			{
				printf("Error!opcion invalida");
				attemps--;
			}
		}while(attemps >= 0);
	}
	return retorno;
}

int myGets(char cadena[], int longitud)
{
	int retorno=-1;
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n' && cadena[0] != '\n')
		{
		cadena[strlen(cadena)-1] = '\0';
		}
		retorno=0;
	}
	return retorno;
}


int isString(char string[])
{
	int retorno = 1;
	if(string != NULL && strlen(string) > 0)
	{
		for(int i = 0;string[i] != '\0'; i++)
		{
			if((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && string[i] != 32)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int isFloat(char string[])
{
	int retorno = 1;
	int i = 0;
	int commaCounter=0;

	if(string != NULL && strlen(string) > 0)
	{
		if(string[0] == '-')
		{
			i = 1;
		}

		for(;string[i] != '\0' ; i++)
		{
			if(string[i] == '.')
			{
				commaCounter++;
			}
			if(commaCounter>1 || ((string[i] > '9' || string[i] < '0') && string[i] != '.'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int isInt(char string[])
{
	int retorno = 1;
	int i = 0;

	if(string != NULL && strlen(string) > 0)
	{
		if(string[0] == '-')
		{
			i = 1;
		}
		for(;string[i] != '\0' ; i++)
		{
			if(string[i] > '9' || string[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int utn_getString(char msg[], char msgError[], char pResult[], int attemps, int limit)
{
	int retorno = -1;
	char bufferString[ARRAY_SIZE];

	if(msg != NULL && msgError != NULL && pResult != NULL && attemps >= 0)
	{
		do
		{
			printf("\n%s", msg);
			if(myGets(bufferString, ARRAY_SIZE) == 0 && isString(bufferString) == 1 && strnlen(bufferString, sizeof(bufferString)) < limit)
			{
				retorno = 0;
				strncpy(pResult, bufferString, limit);
				break;
			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}
		}while(attemps >= 0);
	}
	return retorno;
}

/**
 * \brief Funcion para pedirle al usuario un numero entero
 * \param char msg[]: Puntero a una cadena de texto
 * \param char msgError[]: Puntero a una cadena de texto en caso de error
 * \param int *pResult: Puntero del entero que vamos a devolver
 * \param int attemps: Reintentos que va a tener la funcion en caso de error
 * \param int min: Es el minimo permitido para el numero
 * \param int max: Es el maximo permitido para el numero
 * \return (-1) si algo salio mal (0) si todo esta OK
 */
int utn_getInt(char msg[], char msgError[], int *pResult, int attemps, int min, int max)
{
	int retorno = -1;
	char bufferString[ARRAY_SIZE];
	int bufferInt;

	if(msg != NULL && msgError != NULL && pResult != NULL && attemps >= 0 && min <= max)
	{
		do
		{
			printf("%s", msg);
			if(myGets(bufferString, ARRAY_SIZE) == 0 && isInt(bufferString) == 1)
			{
				bufferInt = atoi(bufferString);
				if(bufferInt >= min && bufferInt<= max)
				{
					*pResult = bufferInt;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s", msgError);
					attemps--;
				}

			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}

		}while(attemps >= 0);
	}
	return retorno;
}



int utn_getFloat(char msg[], char msgError[], float *pResult, int attemps, int min, int max)
{
	int retorno = -1;
	char bufferString[ARRAY_SIZE];
	float bufferFloat;

	if(msg != NULL && msgError != NULL && pResult != NULL && attemps >= 0 && min <= max)
	{
		do
		{
			printf("%s", msg);
			if(myGets(bufferString, ARRAY_SIZE) == 0 && isFloat(bufferString) == 1)
			{
				bufferFloat = atof(bufferString);
				if(bufferFloat >= min && bufferFloat<= max)
				{
					*pResult = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s", msgError);
					attemps--;
				}

			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}

		}while(attemps >= 0);
	}
	return retorno;
}

