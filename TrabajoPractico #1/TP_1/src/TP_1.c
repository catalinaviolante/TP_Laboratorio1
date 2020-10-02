/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "UTN.h"

int main(void) {

	setbuf(stdout, NULL);

	int primerNumeroIngresado;
	int segundoNumeroIngresado;
	int operacionSeleccionada;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorialPrimerNumero;
	int resultadoFactorialSegundoNumero;

	if(utn_validacionGetInt("\n Ingrese el primer n�mero: ", "\n Error al ingresar el primer n�mero.", &primerNumeroIngresado, 3, INT_MAX, INT_MIN)==0)
	{
		if(utn_validacionGetInt("\n Ingrese el segundo n�mero: ", "\n Error al ingresar el segundo n�mero", &segundoNumeroIngresado, 3, INT_MAX, INT_MIN)==0)
		{
			do{
			if(utn_validacionGetInt("\n Seleccione una opci�n: \n-> 1 Suma.\n-> 2 Resta.\n-> 3 Multiplicaci�n.\n-> 4 Division.\n-> 5 Factoriales.\n-> 6 Salir.\n Opci�n: \n", "ERROR. Ingrese un n�mero entre el 1 y el 6 inclusive.", &operacionSeleccionada, 3, 6, 1)==0)
			{

				switch(operacionSeleccionada)
				{
				case 1:
					if(utn_sumarInt(primerNumeroIngresado, segundoNumeroIngresado, &resultadoSuma)== 0)
					{
						printf("\nLa suma entre %d+%d es = %d.", primerNumeroIngresado, segundoNumeroIngresado, resultadoSuma);
					}
					break;
				case 2:
					if(utn_restarInt(primerNumeroIngresado, segundoNumeroIngresado, &resultadoResta)== 0)
					{
						printf("\nEl resultado de la resta entre %d-%d es = %d.", primerNumeroIngresado, segundoNumeroIngresado, resultadoResta);
					}
					break;
				case 3:
					if(utn_multiplicarInt(primerNumeroIngresado, segundoNumeroIngresado, &resultadoMultiplicacion)== 0)
					{
						printf("\nEl resultado de la multiplicacion entre %d*%d es = %d.", primerNumeroIngresado, segundoNumeroIngresado, resultadoMultiplicacion);
					}
					break;
				case 4:
					if(utn_dividirInt(primerNumeroIngresado, segundoNumeroIngresado, &resultadoDivision)== 0)
					{
						printf("\nEl resultado de %d/%d es: %.2f.", primerNumeroIngresado, segundoNumeroIngresado, resultadoDivision);
					}
					else
					{
						printf("\nNo fue posible realizar la divisi�n.");
					}
					break;
				case 5:
					if(utn_factorialInt(&resultadoFactorialPrimerNumero, primerNumeroIngresado) ==0 && utn_factorialInt(&resultadoFactorialSegundoNumero, segundoNumeroIngresado)==0)
					{
						printf("\nEl factorial de %d es = %d y el factorial de %d es %d", primerNumeroIngresado, resultadoFactorialPrimerNumero, segundoNumeroIngresado,resultadoFactorialSegundoNumero );
					}
					else
					{
						printf("\nNo fue posible calcular el factorial de alguno o de los dos n�meros.");
					}
					break;
				case 6:
					printf("Salio del programa, gracias!");
					break;


				}
			}else
			{
				printf("\nNo le quedan mas reintentos para elegir una opcion, por favor, reinicie la aplicaci�n.");
			}

			}while(operacionSeleccionada != 6);

		}

	else
	{
		printf("\n No le quedan mas reintentos, por favor reinicie el programa.");
	}
}
else
{
	printf("\n No le quedan mas reintentos, por favor reinicie el programa.");
}




	return EXIT_SUCCESS;
}
