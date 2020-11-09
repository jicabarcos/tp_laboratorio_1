#include <stdio.h>
#include <stdlib.h>

#include "funcionesAdicionales.h"
#include "Employee.h"
#include "bibliotecaUTN.h"

int menuDeOpciones(int menuType){

    int eleccion;

    if(menuType == 0){

        printf(" *** MENU PRINCIPAL ***\n\n");
        printf(">> 1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf(">> 2) Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
        printf(">> 3) Alta de empleado\n");
        printf(">> 4) Modificar datos de empleado\n");
        printf(">> 5) Baja de empleado\n");
        printf(">> 6) Listar empleados\n");
        printf(">> 7) Ordenar empleados\n");
        printf(">> 8) Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf(">> 9) Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
        printf(">> 10) Salir\n\n");
        getValidInt("Elija la opcion deseada: ", "Debe ser un entero del 1 al 10, vuelva a ingresar: ", &eleccion, 1, 10, 5);

    }
    else if(menuType == 1){

        printf("\n *** MENU DE MODIFICACIONES ***\n\n");
        printf("> 1) Nombre\n");
        printf("> 2) Horas trabajadas\n");
        printf("> 3) Sueldo\n");
        getValidInt("\nElija la opcion deseada: ", "Debe ser un entero del 1 al 3, vuelva a ingresar: ", &eleccion, 1, 3, 5);

    }
    else if(menuType == 2){

        printf("\n *** MENU DE ORDENAMIENTOS ***\n\n");
        printf("> 1) ID ascendente\n");
        printf("> 2) ID descendente\n");
        printf("> 3) Nombre ascendente\n");
        printf("> 4) Nombre descendente\n");
        printf("> 5) Horas trabajadas ascendente\n");
        printf("> 6) Horas trabajadas descendente\n");
        printf("> 7) Sueldo ascendente\n");
        printf("> 8) Sueldo descendente\n");
        getValidInt("\nElija la opcion deseada: ", "Debe ser un entero del 1 al 8, vuelva a ingresar: ", &eleccion, 1, 8, 5);

    }
    return eleccion;

}

int lastId(int idLista){

    static int staticId;
    int ultimoId;

    staticId = idLista;
    staticId++;
    ultimoId = staticId;

    return ultimoId;

}

