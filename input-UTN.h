/*
 * input-UTN.h
 *
 *  Created on: 7 jun. 2022
 *      Author: ignac
 */

#ifndef INPUT_UTN_H_
#define INPUT_UTN_H_

int UTN_MyGets(char* cadena, int longitud);
int UTN_getNumero(int* pResultado, char* mensaje, char* mensajeERROR, int minimo, int maximo, int reintentos);
int UTN_getChar(char* pResultado, char* mensaje, char* mensajeERROR, char minimo, char maximo, int reintentos);
int UTN_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeERROR, float minimo, float maximo, int reintentos);
int UTN_getString(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int UTN_esTexto(char* cadena,int longitud);
int UTN_getAlfaNum(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int UTN_esAlfanumerica(char* cadena,int longitud);
int UTN_getNumeroRange(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
#endif /* INPUT_UTN_H_ */
