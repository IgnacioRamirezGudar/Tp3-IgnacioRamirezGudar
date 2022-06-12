#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	Passenger* AuxPassenger;

	int retorno;
	retorno = 1;

	int ResultadoEscaneo;

	char auxID[20];
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[20];
	char auxCodigoVuelo[20];
	char auxTipoPasajero[20];
	char auxEstadoVuelo[20];

	if(pFile !=NULL && pArrayListPassenger != NULL){

		ResultadoEscaneo = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n",auxID,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);

		while(!feof(pFile)){
			ResultadoEscaneo = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n",auxID,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);

			if(ResultadoEscaneo == 7){
				AuxPassenger = Passenger_newParametros(auxID, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);

				if(AuxPassenger != NULL){
					ll_add(pArrayListPassenger, AuxPassenger);
				} else {
					free(AuxPassenger);
					retorno = -1;
				}

			} else {
				free(AuxPassenger);
				retorno = -1;
			}
		}

	}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	Passenger* AuxPassenger;

	int retorno;
	int cantidadDatos;
	int DatosLeidos;

	retorno = 0;
	cantidadDatos = 0;
	DatosLeidos = 0;

	if(pFile !=NULL && pArrayListPassenger != NULL){
		while(!feof(pFile)){
			AuxPassenger = Passenger_new();
			cantidadDatos = fread(AuxPassenger, sizeof(Passenger), 1, pFile);

			if(cantidadDatos == 1 && AuxPassenger != NULL){
				ll_add(pArrayListPassenger, AuxPassenger);
				DatosLeidos++;
			}
		}
		if(DatosLeidos != 0){
			retorno = 1;
		}
	}

    return retorno;
}
