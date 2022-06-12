#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Passenger.h"
#include "input-UTN.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{

    	UTN_getNumero(&option,"\n============MENU DE AEROLINEA============"
    							"\n1)Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)"
    							"\n2)Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)"
    							"\n3)Alta de pasajero"
    							"\n4)Modificar datos de pasajero"
    							"\n5)Baja de pasajero"
    							"\n6)Listar pasajeros"
    							"\n7)Ordenar pasajeros"
    							"\n8)Guardar los datos de los pasajeros en el archivo data.csv (modo texto)"
    							"\n9)Guardar los datos de los pasajeros en el archivo data.csv (modo binario)"
    							"\n10)Salir"
    							"\n======================================"
    							"\nELIGA UNA OPCION: ","\nELIGA UNA OPCION VALIDA",1,10,5);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
            case 2:
            	controller_loadFromBinary("data.bin",listaPasajeros);
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros);
            	break;
            case 4:
            	controller_editPassenger(listaPasajeros);
            	break;
            case 5:
            	controller_removePassenger(listaPasajeros);
            	break;
            case 6:
            	printf("\n\n========================================LISTA PASAJEROS==========================================");
            	controller_ListPassenger(listaPasajeros);
            	printf("\n\n=================================================================================================");
            	break;
            case 7:
            	controller_sortPassenger(listaPasajeros);
            	break;
            case 8:
            	controller_saveAsText("data.csv",listaPasajeros);
            	break;
            case 9:
            	controller_saveAsBinary("data.bin",listaPasajeros);
            	break;
            default:
            	break;
        }
    }while(option != 10);
    return 0;
}

