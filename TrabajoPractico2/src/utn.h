/*
 * utn.h
 *
 *
 *   Author: Catalina Violante
 */

#ifndef UTN_H_
#define UTN_H_



int utn_getNumero(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int utn_esUnNombreValido(char* cadena,int limite);
int utn_getNombre(char* mensaje,char* mensajeError,char* pResultado, int reintentos, int limite);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int myGets(char *cadena, int longitud);


#endif /* UTN_H_ */



