/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[20];
	char tipoPasajero[20];
	char estadoVuelo[20];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo);

void Passenger_printOne(Passenger* this);
int Passenger_printOnFile(FILE* pFile,Passenger* this);

int Passenger_CompareId(void* pasajero1, void* pasajero2);
int Passenger_CompareNombre(void* pasajero1, void* pasajero2);
int Passenger_CompareApellido(void* pasajero1, void* pasajero2);
int Passenger_ComparePrecio(void* pasajero1, void* pasajero2);
int Passenger_CompareCodigoVuelo(void* pasajero1, void* pasajero2);
int Passenger_CompareTipoPasajero(void* pasajero1, void* pasajero2);
int Passenger_CompareEstadoVuelo(void* pasajero1, void* pasajero2);



#endif /* PASSENGER_H_ */
