/*
 * input-UTN.c
 *
 *  Created on: 7 jun. 2022
 *      Author: ignac
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input-UTN.h"

static int UTN_esNumerica(char* cadena, int limite);
static int UTN_getInt(int* pResultado);

int UTN_MyGets(char* cadena, int longitud){

	char bufferString[4096];
	int retorno = -1;

	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL){
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}

	return retorno;
}




int UTN_getInt(int* pResultado){
	int retorno = -1;

	char bufferString[50];

	if(pResultado != NULL && UTN_MyGets(bufferString, sizeof(bufferString)) == 0 && UTN_esNumerica(bufferString,sizeof(bufferString))){
		retorno = 0;
		*pResultado = atoi(bufferString);
	}

	return retorno;
}

int UTN_getNumero(int* pResultado, char* mensaje, char* mensajeERROR, int minimo, int maximo, int reintentos){
	int retorno = 1;

	int bufferInt;

	do{
		printf("%s", mensaje);
		if(UTN_getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo){
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s", mensajeERROR);
		reintentos--;
	}while(reintentos >= 0);

	return retorno;
}

int UTN_getNumeroRange(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	UTN_getInt(&bufferInt) == 0 &&bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 1;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

int UTN_esNumerica(char* cadena, int limite){
	int retorno = -1;

	if(cadena != NULL && limite > 0){
		retorno = 1;
		for(int i = 0;i < limite && cadena[i] != '\0'; i++){
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0'){
				retorno = 0;
				break;
			}
		}
	}


	return retorno;
}

int UTN_getChar(char* pResultado, char* mensaje, char* mensajeERROR, char minimo, char maximo, int reintentos){

	int retorno = -1;
	char buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeERROR != NULL && minimo <= maximo && reintentos >= 0){

		do{
			printf("%s", mensaje);
			scanf("%c", &buffer);
			if(buffer >= minimo && buffer <= maximo){
				*pResultado = buffer;
				retorno = 0;
			}
			printf("%s", mensajeERROR);
			reintentos--;
		}while(reintentos >= 0);
	}


	return retorno;
}

int UTN_esFlotante(char* cadena, int limite){
	int retorno = 1; //VERDADERO
	int i;
	int contadorPuntos = 0; // PARA QUE NO HAYA MAS DE 1 PUNTO EN EL NUMERO
	for(i = 0 ; i < limite && cadena[i] != '\0' ; i++)
	{
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			if(cadena[i] == '.' && contadorPuntos == 0)
			{
				contadorPuntos++;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
		//CONTINUE
	}
//BREAK
	return retorno;
}

static int UTN_getFloat(float* pResultado)
{
	int retorno = 1;
	char bufferString[50];
	if(pResultado != NULL)
	{
		if( UTN_MyGets(bufferString,sizeof(bufferString)) == 0 &&
				UTN_esFlotante(bufferString, sizeof(bufferString)) == 1)
		 	{
				*pResultado = atof(bufferString);
				retorno = 0;
			}
		}
	return retorno;
}

int UTN_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeERROR, float minimo, float maximo, int reintentos){
	int retorno = -1;
	float bufferFloat;
	do
	{
		printf("%s", mensaje);
		if(UTN_getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
		{
			*pResultado= bufferFloat;
			retorno = 1;
			break;
		}
		printf("%s", mensajeERROR);
		reintentos -- ;
	}while(reintentos >= 0);
	return retorno;
}

static int UTN_getNombre(char* pResultado, int longitud){
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(	UTN_MyGets(buffer,sizeof(buffer))==0 && UTN_esTexto(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud){
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int UTN_esTexto(char* cadena,int longitud){
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0){
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++){
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
					(cadena[i] < 'a' || cadena[i] > 'z' )){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int UTN_getString(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(UTN_getNombre(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud ){
			strncpy(pResultado,bufferString,longitud);
			retorno = 1;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

static int UTN_getNombreAlfanumerico(char* pResultado, int longitud){
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(	UTN_MyGets(buffer,sizeof(buffer))==0 &&
    		UTN_esAlfanumerica(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud){
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int UTN_esAlfanumerica(char* cadena,int longitud){
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0){
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++){
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
					(cadena[i] < 'a' || cadena[i] > 'z' ) &&
					(cadena[i] > '9' || cadena[i] < '0')){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int UTN_getAlfaNum(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
		int retorno = -1;
		while(reintentos>=0){
			reintentos--;
			printf("%s",mensaje);
			if(UTN_getNombreAlfanumerico(bufferString,sizeof(bufferString)) == 0 &&
					strnlen(bufferString,sizeof(bufferString)) < longitud ){
				strncpy(pResultado,bufferString,longitud);
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
		}
		return retorno;
}
