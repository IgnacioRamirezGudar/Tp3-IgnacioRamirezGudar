/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Passenger.h"

//NEW PASSANGER
Passenger* Passenger_new(){

	Passenger* AuxPassenger;
	AuxPassenger = (Passenger*)malloc(sizeof(Passenger));
	return AuxPassenger;

}


//NEW PARAMETRO
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr){
	Passenger* AuxPassenger;

	AuxPassenger = Passenger_new();

	Passenger_setId(AuxPassenger,atoi(idStr));
	Passenger_setNombre(AuxPassenger,nombreStr);
	Passenger_setApellido(AuxPassenger,apellidoStr);
	Passenger_setCodigoVuelo(AuxPassenger,codigoVueloStr);
	Passenger_setTipoPasajero(AuxPassenger,tipoPasajeroStr);
	Passenger_setPrecio(AuxPassenger,atof(precioStr));
	Passenger_setEstadoVuelo(AuxPassenger,estadoVueloStr);

	if((idStr==NULL) && (nombreStr==NULL) && (apellidoStr==NULL) && (precioStr==NULL) && (codigoVueloStr==NULL) && (tipoPasajeroStr==NULL) && (estadoVueloStr==NULL))
	{
		Passenger_delete(AuxPassenger);

		if(AuxPassenger == NULL)
		{
			Passenger_delete(AuxPassenger);
		}
	}

	return AuxPassenger;
}


//DELETE
void Passenger_delete(Passenger* this){
	free(this);
}


//PRINT LIST PASSANGER
void Passenger_printOne(Passenger* this){
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[20];
	char tipoPasajero[20];
	char estadoVuelo[20];

	Passenger_getId(this, &id);
	Passenger_getNombre(this, nombre);
	Passenger_getApellido(this, apellido);
	Passenger_getPrecio(this, &precio);
	Passenger_getCodigoVuelo(this, codigoVuelo);
	Passenger_getTipoPasajero(this, tipoPasajero);
	Passenger_getEstadoVuelo(this, estadoVuelo);


	printf("%d ||%15s ||%15s ||%12.2f ||%10s ||%20s ||%15s\n", id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

}

//PRINT LIST ON FILE
int Passenger_printOnFile(FILE* pFile,Passenger* this){

	int retorno;
	retorno = -1;

	int id;
	float precio;
	char AUXID[20];
	char AUXnombre[50];
	char AUXapellido[50];
	char AUXprecio[20];
	char AUXcodigoVuelo[20];
	char AUXtipoPasajero[20];
	char AUXestadoVuelo[20];

	if(pFile!=NULL && this!=NULL){

		if(Passenger_getId(this, &id) == 1 && Passenger_getNombre(this, AUXnombre) == 1 && Passenger_getApellido(this, AUXapellido) == 1 && Passenger_getPrecio(this, &precio) == 1 &&
				Passenger_getCodigoVuelo(this,AUXcodigoVuelo) == 1 && Passenger_getTipoPasajero(this,AUXtipoPasajero) ==1 && Passenger_getEstadoVuelo(this,AUXestadoVuelo) == 1)
		{
				sprintf(AUXID,"%d",id);
				sprintf(AUXprecio,"%f",precio);
				fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n",AUXID,AUXnombre,AUXapellido,AUXprecio,AUXcodigoVuelo,AUXtipoPasajero,AUXestadoVuelo);
		}


		retorno = 0;
	}


	return retorno;
}


//SETS
int Passenger_setId(Passenger* this,int id){
	int retorno;
	retorno=0;

	if(this!=NULL && id>0){
		this->id = id;
		retorno=1;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno;
	retorno=0;

	if(this!=NULL && nombre!=NULL){
		strcpy(this->nombre,nombre);
		retorno=1;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno;
	retorno=0;

	if(this!=NULL && apellido!=NULL){
		strcpy(this->apellido,apellido);
		retorno=1;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno;
	retorno=0;

	if(this!=NULL && codigoVuelo!=NULL){
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno=1;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero){
	int retorno;
	retorno=0;

	if(this!=NULL && tipoPasajero!=NULL){
		strcpy(this->tipoPasajero,tipoPasajero);
		retorno=1;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio){
	int retorno;
	retorno=0;

	if(this!=NULL && precio > -1){
		this->precio = precio;
		retorno=1;
	}

	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo){
	int retorno = 0;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno=1;
	}
	return retorno;
}


//GETS
int Passenger_getId(Passenger* this,int* id){
	int retorno;
	retorno=0;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno=1;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno;
	retorno=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=1;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno;
	retorno=0;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido,this->apellido);
		retorno=1;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno;
	retorno=0;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno=1;
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){
	int retorno;
	retorno=0;

	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		retorno=1;
	}

	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno;
	retorno=0;

	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		retorno=1;
	}

	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo){
	int retorno;
	retorno=0;

	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno=1;
	}

	return retorno;
}

//COMPARES
int Passenger_CompareId(void* pasajero1, void* pasajero2){
	int retorno;
	retorno = 0;

	Passenger* AuxPassanger1;
	Passenger* AuxPassanger2;
	AuxPassanger1 = (Passenger*) pasajero1;
	AuxPassanger2 = (Passenger*) pasajero2;

	if(AuxPassanger1->id > AuxPassanger2->id)
	{
		retorno=1;
	}
	else
	{
		if(AuxPassanger1->id < AuxPassanger2->id)
		{
			retorno=-1;
		}
	}

	return retorno;
}
int Passenger_CompareNombre(void* pasajero1, void* pasajero2){
	int retorno;
	retorno=-2;

	Passenger* AuxPassanger1;
	Passenger* AuxPassanger2;
	AuxPassanger1 = (Passenger*) pasajero1;
	AuxPassanger2 = (Passenger*) pasajero2;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		retorno = strcmp(AuxPassanger1->nombre, AuxPassanger2->nombre);
	}

	return retorno;
}
int Passenger_CompareApellido(void* pasajero1, void* pasajero2){
	int retorno;
	retorno=-2;

	Passenger* AuxPassanger1;
	Passenger* AuxPassanger2;
	AuxPassanger1 = (Passenger*) pasajero1;
	AuxPassanger2 = (Passenger*) pasajero2;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		retorno = strcmp(AuxPassanger1->apellido, AuxPassanger2->apellido);
	}

	return retorno;
}
int Passenger_ComparePrecio(void* pasajero1, void* pasajero2){
	int retorno;
	retorno=0;

	Passenger* AuxPassanger1;
	Passenger* AuxPassanger2;
	AuxPassanger1 = (Passenger*) pasajero1;
	AuxPassanger2 = (Passenger*) pasajero2;

	if(AuxPassanger1->precio > AuxPassanger2->precio)
	{
		retorno=1;
	}
	else
	{
		if(AuxPassanger1->precio < AuxPassanger2->precio)
		{
			retorno=-1;
		}
	}

	return retorno;
}
int Passenger_CompareCodigoVuelo(void* pasajero1, void* pasajero2){
	int retorno;
	retorno=-2;

	Passenger* AuxPassanger1;
	Passenger* AuxPassanger2;
	AuxPassanger1 = (Passenger*) pasajero1;
	AuxPassanger2 = (Passenger*) pasajero2;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		retorno = strcmp(AuxPassanger1->codigoVuelo, AuxPassanger2->codigoVuelo);
	}

	return retorno;
}
int Passenger_CompareTipoPasajero(void* pasajero1, void* pasajero2){
	int retorno;
	retorno=-2;

	Passenger* AuxPassanger1;
	Passenger* AuxPassanger2;
	AuxPassanger1 = (Passenger*) pasajero1;
	AuxPassanger2 = (Passenger*) pasajero2;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		retorno = strcmp(AuxPassanger1->tipoPasajero, AuxPassanger2->tipoPasajero);
	}

	return retorno;
}
int Passenger_CompareEstadoVuelo(void* pasajero1, void* pasajero2){
	int retorno;
	retorno=-2;

	Passenger* AuxPassanger1;
	Passenger* AuxPassanger2;
	AuxPassanger1 = (Passenger*) pasajero1;
	AuxPassanger2 = (Passenger*) pasajero2;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		retorno = strcmp(AuxPassanger1->estadoVuelo, AuxPassanger2->estadoVuelo);
	}

	return retorno;
}
