#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"
#include "input-UTN.h"

static int Generate_ID(void);

static int Generate_ID(void){
	static int IncrementalID = 1001;
	return IncrementalID++;
}


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){
	int retorno;
	retorno = 1;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile = fopen(path,"r");

		if(parser_PassengerFromText(pFile, pArrayListPassenger) == 0){
			retorno = -1;
		}
		fclose(pFile);
	}

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger){
	int retorno;
	retorno = 1;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile = fopen(path,"rb");

		if(parser_PassengerFromBinary(pFile, pArrayListPassenger) == 0){
			retorno = -1;
		}
		fclose(pFile);
	}

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger){
	int retorno;
	retorno = -1;

	if( pArrayListPassenger!=NULL )
	{
		Passenger* AuxPassenger;

		char nombre[50];
		char apellido[50];
		float precio;
		char codigoVuelo[20];
		int estadoVuelo;
		int tipoPasajero;

		char AuxID[20];
		char AuxPrecio[20];
		char AuxEstadoVuelo[20];
		char AuxTipoPasajero[20];

		sprintf(AuxID,"%d",Generate_ID());
		printf("============ AÑADIR PASAJERO ============");
		if(UTN_getString(nombre,20,"\nIngrese nombre del pasajero: ","Error al ingresar el nombre \nREINGRESE NOMBRE:", 5)){
			if(UTN_getString(apellido,20,"\nIngrese apellido del pasajero: ","Error al ingresar el apellido \nREINGRESE APELLIDO:",5)){
				if(UTN_getNumeroFlotante(&precio,"\nIngrese precio del vuelo: ","\nError al ingresar el precio \nREINGRESE PRECIO: ",0,1000000,5)){
					if(UTN_getAlfaNum(codigoVuelo,20,"\nIngrese codigo de vuelo: ","ERRIR al Ingresar el codigo de vuelo \nReingrese codigo de vuelo",5)){
						if(UTN_getNumeroRange(&estadoVuelo,"\n1-ATERRIZO"
								"\n2-EN HORARIO"
								"\n3-EN VUELO"
								"\n4-DEMORADO"
								"\nIngrese estado del vuelo:","\nERROR AL INGRESAR ESA OPCION DE ESTADO\nREINGRESE OPCION: ", 1,4,5)){
							if(UTN_getNumeroRange(&tipoPasajero,"\n1-ECONOMY CLASS | 2-EXECUTIVE CLASS | 3-FIRST CLASS","ERROR AL INGRESAR UNA OPCION \nREINGRESE OPCION: ",1,3,5)){
								sprintf(AuxPrecio,"%2f",precio);
								sprintf(AuxEstadoVuelo,"%d",estadoVuelo);
								sprintf(AuxTipoPasajero,"%d",tipoPasajero);
								AuxPassenger =  Passenger_newParametros(AuxID, nombre, apellido, AuxPrecio, codigoVuelo, AuxTipoPasajero, AuxEstadoVuelo);
								ll_add(pArrayListPassenger, AuxPassenger);

								retorno = 1;
							}
						}
					}
				}
			}
		}
	}

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){
	int retorno;
	int id;
	int AuxID;
	int sizeList;
	int opcion;
	retorno=0;

	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[20];
	int estadoVuelo;
	int tipoPasajero;

	char AuxEstadoVuelo[20];
	char AuxTipoPasajero[20];

	Passenger* AuxPassenger;

	if(pArrayListPassenger!=NULL){

		printf("\n\n\n==============MODIFICAR UN PASAJERO==============");
		printf("\nIngrese ID del usuario a modificar: ");
		scanf("%d",&id);
		UTN_getNumero(&opcion,"\n1- Modificar el Nombre"
				"\n2- Modificar el Apellido"
				"\n3- Modificar el Precio"
				"\n4- Modificar el Codigo de Vuelo"
				"\n5- Modificar el Tipo de Pasajero"
				"\n6- Modificar el Estado de Vuelo"
				"\n7-CANCELAR"
				"\nIngrese una opcion: ","ERROR AL INGRESAR UN OPCION \nREINGRESE UNA OPCION CORRECTA",1,7,5);

		sizeList = ll_len(pArrayListPassenger);

		for(int i=0; i<sizeList; i++){
			AuxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			if(Passenger_getId(AuxPassenger, &AuxID) == 1){
				if(AuxID == id){
					switch(opcion){
						case 1:

							UTN_getChar(nombre,"\n\n\nIngrese nombre del pasajero: ","Error al ingresar el nombre \nREINGRESE NOMBRE:", 0,50,5);
							Passenger_setNombre(AuxPassenger,nombre);
							retorno=1;
							break;
						case 2:

							UTN_getChar(apellido,"\n\n\nIngrese apellido del pasajero: ","Error al ingresar el apellido \nREINGRESE APELLIDO:",0,50,5);
							Passenger_setApellido(AuxPassenger,apellido);
							retorno=1;
							break;
						case 3:
							UTN_getNumeroFlotante(&precio,"\nIngrese precio del vuelo: ","\nError al ingresar el precio \nREINGRESE PRECIO: ",0,1000000,5);
							Passenger_setPrecio(AuxPassenger,precio);
							retorno=1;
							break;
						case 4:
							printf("Ingrese codigo de vuelo: ");
							fflush(stdin);
							gets(codigoVuelo);
							Passenger_setCodigoVuelo(AuxPassenger,codigoVuelo);
							retorno=1;
							break;

						case 5:
							UTN_getNumero(&tipoPasajero,"\n1-ECONOMY CLASS | 2-EXECUTIVE CLASS | 3-FIRST CLASS","ERROR AL INGRESAR UNA OPCION \nREINGRESE OPCION: ",1,3,5);
							sprintf(AuxTipoPasajero,"%d",tipoPasajero);
							Passenger_setTipoPasajero(AuxPassenger,AuxTipoPasajero);
							retorno=1;
							break;


						case 6:
							UTN_getNumero(&estadoVuelo,"\n1-ATERRIZO"
														"\n2-EN HORARIO"
														"\n3-EN VUELO"
														"\n4-DEMORADO"
														"\nIngrese estado del vuelo:","\nERROR AL INGRESAR ESA OPCION DE ESTADO\nREINGRESE OPCION: ", 1,4,5);
							sprintf(AuxEstadoVuelo,"%d",estadoVuelo);
							Passenger_setEstadoVuelo(AuxPassenger,AuxEstadoVuelo);
							retorno=1;
							break;
						default:
							break;
					}
				}
			}
		}
	}

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger){

	Passenger* AuxPassenger;
	int retorno;
	int id;
	int AuxID;
	int sizeList;
	retorno = 0;

	if(pArrayListPassenger!=NULL){
		printf("\n\n\n============ELIMINAR PASAJERO============");
		printf("Ingrese ID del pasajero a eliminar: ");
		scanf("%d",&id);

		sizeList = ll_len(pArrayListPassenger);

		for(int i=0; i<sizeList; i++){
			AuxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			if(Passenger_getId(AuxPassenger, &AuxID) == 1){
				if(AuxID == id){
					ll_remove(pArrayListPassenger, i);
					retorno = 1;
					break;
				}
			}
		}
	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger){

	Passenger* AuxPassenger;
	int retorno;
	int sizeList;

	retorno = 0;

	if(pArrayListPassenger!=NULL)
	{
		sizeList = ll_len(pArrayListPassenger);

		for(int i=0; i<sizeList; i++)
		{
			AuxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_printOne(AuxPassenger);
		}
		retorno = 1;
	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int retorno;
    int opcion;
    int subopcion;
    retorno=0;

    if(pArrayListPassenger!=NULL)
    {
		UTN_getNumero(&opcion,"\n1-Ordenar por ID"
				"\n2-Ordenar por Nombre"
				"\n3-Ordenar por Apellido"
				"\n4-Ordenar por Preci"
				"\n5-Ordenar por Codigo de Vuelo"
				"\n6-Ordenar por Tipo de Pasajero"
				"\n7-Ordenar por Estado de Vuelo"
				"\n8-Salir"
				"\nIngrese un opcion: ","\ERROR AL INGRESAR UNA OPCION  \n INGRESE UNA OPCION VALIDA: ", 1,8,5);

		switch(opcion)
		{
				case 1:
					UTN_getNumero(&subopcion,"\n1-Ascendente"
						"\n2-Desendente"
						"\nComo lo desea ordenar: ","\nREINGRESE UNA OPCION VALIDA",1,2,5);

				switch(subopcion)
				{
					case 1:
						ll_sort(pArrayListPassenger, Passenger_CompareId, 1);
						break;

					case 2:
						ll_sort(pArrayListPassenger, Passenger_CompareId, 0);
						break;
				}

				retorno=1;
				break;

			case 2:
				UTN_getNumero(&subopcion,"\n1-Ascendente"
					"\n2-Desendente"
					"\nComo lo desea ordenar: ","\nREINGRESE UNA OPCION VALIDA",1,2,5);
				switch(subopcion)
				{
					case 1:
						ll_sort(pArrayListPassenger, Passenger_CompareNombre, 1);
						break;

					case 2:
						ll_sort(pArrayListPassenger, Passenger_CompareNombre, 0);
						break;
				}

				retorno=1;
				break;

			case 3:
				UTN_getNumero(&subopcion,"\n1-Ascendente"
					"\n2-Desendente"
					"\nComo lo desea ordenar: ","\nREINGRESE UNA OPCION VALIDA",1,2,5);

				switch(subopcion)
				{
					case 1:
						ll_sort(pArrayListPassenger, Passenger_CompareApellido, 1);
						break;

					case 2:
						ll_sort(pArrayListPassenger, Passenger_CompareApellido, 0);
						break;
				}

				retorno=1;
				break;

			case 4:
				UTN_getNumero(&subopcion,"\n1-Ascendente"
					"\n2-Desendente"
					"\nComo lo desea ordenar: ","\nREINGRESE UNA OPCION VALIDA",1,2,5);

				switch(subopcion)
				{
					case 1:
						ll_sort(pArrayListPassenger, Passenger_ComparePrecio, 1);
						break;

					case 2:
						ll_sort(pArrayListPassenger, Passenger_ComparePrecio, 0);
						break;
				}

				retorno=1;
				break;

			case 5:
				UTN_getNumero(&subopcion,"\n1-Ascendente"
					"\n2-Desendente"
					"\nComo lo desea ordenar: ","\nREINGRESE UNA OPCION VALIDA",1,2,5);

				switch(subopcion)
				{
					case 1:
						ll_sort(pArrayListPassenger, Passenger_CompareCodigoVuelo, 1);
						break;

					case 2:
						ll_sort(pArrayListPassenger, Passenger_CompareCodigoVuelo, 0);
						break;
				}

				retorno=1;
				break;

			case 6:
				UTN_getNumero(&subopcion,"\n1-Ascendente"
					"\n2-Desendente"
					"\nComo lo desea ordenar: ","\nREINGRESE UNA OPCION VALIDA",1,2,5);

				switch(subopcion)
				{
					case 1:
						ll_sort(pArrayListPassenger, Passenger_CompareTipoPasajero, 1);
						break;

					case 2:
						ll_sort(pArrayListPassenger, Passenger_CompareTipoPasajero, 0);
						break;
				}

				retorno=1;
				break;

			case 7:
				UTN_getNumero(&subopcion,"\n1-Ascendente"
					"\n2-Desendente"
					"\nComo lo desea ordenar: ","\nREINGRESE UNA OPCION VALIDA",1,2,5);

				switch(subopcion)
				{
					case 1:
						ll_sort(pArrayListPassenger, Passenger_CompareEstadoVuelo, 1);
						break;

					case 2:
						ll_sort(pArrayListPassenger, Passenger_CompareEstadoVuelo, 0);
						break;
				}

				retorno=1;
				break;
				default:
					break;
		}
    }

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{

	int retorno;

	retorno = 1;

	int cantidadDatos;

	Passenger* AuxPassenger = NULL;

	if(path!=NULL && pArrayListPassenger!=NULL){

		FILE* pFile = fopen(path,"w");

		cantidadDatos = ll_len(pArrayListPassenger);

		fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n","id","nombre","apellido","precio","codigoVuelo","tipoPasajero","estadoVuelo");

		for(int i = 0; i < cantidadDatos; i++){
			AuxPassenger = (Passenger*) ll_get(pArrayListPassenger,i);
			Passenger_printOnFile(pFile,AuxPassenger);
		}
		if(!fclose(pFile)){
			retorno = 0;
		}

	}


    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	retorno = -1;
	FILE* pFILE;
	Passenger* AuxPassenger;
	int cantidadDatos;

	cantidadDatos = ll_len(pArrayListPassenger);


	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFILE = fopen(path, "wb");
		if(pFILE != NULL)
		{
			for(int i = 0; i < cantidadDatos ; i++)
			{
				AuxPassenger = ll_get(pArrayListPassenger, i);
				fwrite(AuxPassenger, sizeof(Passenger),1,pFILE);

			}
			retorno = 1;
		}
	}

    return retorno;
}
