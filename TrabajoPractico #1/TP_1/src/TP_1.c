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

	if(utn_validacionGetInt("\n Ingrese el primer número: ", "\n Error al ingresar el primer número.", &primerNumeroIngresado, 3, INT_MAX, INT_MIN)==0)
	{
		if(utn_validacionGetInt("\n Ingrese el segundo número: ", "\n Error al ingresar el segundo número", &segundoNumeroIngresado, 3, INT_MAX, INT_MIN)==0)
		{
			do{
			if(utn_validacionGetInt("\n Seleccione una opción: \n-> 1 Suma.\n-> 2 Resta.\n-> 3 Multiplicación.\n-> 4 Division.\n-> 5 Factoriales.\n-> 6 Salir.\n Opción: \n", "ERROR. Ingrese un número entre el 1 y el 6 inclusive.", &operacionSeleccionada, 3, 6, 1)==0)
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
						printf("\nNo fue posible realizar la división.");
					}
					break;
				case 5:
					if(utn_factorialInt(&resultadoFactorialPrimerNumero, primerNumeroIngresado) ==0 && utn_factorialInt(&resultadoFactorialSegundoNumero, segundoNumeroIngresado)==0)
					{
						printf("\nEl factorial de %d es = %d y el factorial de %d es %d", primerNumeroIngresado, resultadoFactorialPrimerNumero, segundoNumeroIngresado,resultadoFactorialSegundoNumero );
					}
					else
					{
						printf("\nNo fue posible calcular el factorial de alguno o de los dos números.");
					}
					break;
				case 6:
					printf("Salio del programa, gracias!");
					break;


				}
			}else
			{
				printf("\nNo le quedan mas reintentos para elegir una opcion, por favor, reinicie la aplicación.");
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
