/*
 * UTN.h
 *
 *  Created on: 8 sep. 2020
 *      Author: 54222
 */

#ifndef UTN_H_
#define UTN_H_

int utn_validacionGetInt(char* mensaje, char* mensajeError, int* pResultado, int reintentos, int maximo, int minimo);

int utn_sumarInt(int primerOperador, int segundoOperador, int* pResultadoSuma);

int utn_restarInt(int primerOperador, int segundoOperador, int* pResultadoResta);

int utn_multiplicarInt(int primerOperador, int segundoOperador, int* pResultadoMultiplicacion);

int utn_dividirInt(int primerOperador, int segundoOperador, float* pResultadoDivision);

int utn_factorialInt(int* pResultado,int operador);

#endif /* UTN_H_ */
