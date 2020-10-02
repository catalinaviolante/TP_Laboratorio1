/*
 * UTN.c
 *
 *  Created on: 8 sep. 2020
 *      Author: Cat
 */
#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

/**
 * \brief Solicita un número entero y valida que sea de ese tipo.
 *   \param Mensaje para pedir el número entero.
 * \param Mensaje de error.
 * \param Puntero con el número entero introducido.
 * \param Número máximo de intentos permitidos.
 *  * \param Número máximo de intentos permitidos.
 * \return 0: el número se introdujo con éxito /return -1: error en la funcion, operador ingresado no valido.
 */
int utn_validacionGetInt(char* mensaje, char* mensajeError, int* pResultado, int reintentos, int maximo, int minimo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d",&bufferInt);
			if(resultadoScanf == 1&& bufferInt<=maximo && bufferInt>=minimo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				fflush(stdin);
				reintentos--;
			}
		}
		while(reintentos > 0);
	}
	return retorno;
}
/**
 * \brief Suma numeros enteros.
 * \param primer numero a sumar.
 * \param segundo numero a sumar.
 * \param puntero donde se guardara el resultado de la suma.
 * \return 0: el número se introdujo con éxito /return -1: error en la funcion, operador ingresado no valido.
 */
int utn_sumarInt(int primerOperador, int segundoOperador, int* pResultadoSuma)
{
	int retorno = -1;

	if(pResultadoSuma != NULL)
	{
		*pResultadoSuma = (primerOperador + segundoOperador);
		retorno = 0;
	}

	return retorno;
}

int utn_restarInt(int primerOperador, int segundoOperador, int* pResultadoResta)
{
	int retorno = -1;

	if(pResultadoResta != NULL)
	{
		*pResultadoResta = (primerOperador - segundoOperador);
		retorno = 0;
	}

	return retorno;
}

int utn_multiplicarInt(int primerOperador, int segundoOperador, int* pResultadoMultiplicacion)
{
	int retorno = -1;

	if(pResultadoMultiplicacion!= NULL)
	{
		*pResultadoMultiplicacion = (primerOperador * segundoOperador);
		retorno = 0;
	}

	return retorno;
}



int utn_dividirInt(int primerOperador, int segundoOperador, float* pResultadoDivision)
{
	int retorno = -1;

	if(pResultadoDivision!= NULL && segundoOperador !=0)
	{
		*pResultadoDivision = ((float)primerOperador / segundoOperador);
		retorno = 0;
	}

	return retorno;
}


/**
 * \brief Obtiene el factorial de un operador
 * \param Puntero con el resultado del factorial.
 * \param El operador del cual obtendremos el factorial.
 * \return -1 si la funcion dio error. return 0 si fue realizada con exito.
 */
int utn_factorialInt(int* pResultado,int operador)
{

	int resultadoFactorial=1;
	int repeticiones;
	int retorno = -1;

	if(pResultado!=NULL && operador>-1)
	{
		if(operador!=0)
		{
			for(repeticiones=operador; repeticiones>1; repeticiones--)
			{
				resultadoFactorial=resultadoFactorial*repeticiones;
			}
			retorno = 0;
		}
		else
		{
			resultadoFactorial=1;
			retorno = 0;
		}
	}

	*pResultado=resultadoFactorial;
	return retorno;
}
