#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesAdicionales.h"
#include "../inc/LinkedList.h"
#include "utn.h"

int menuDeOpciones(int tipoDeMenu){

    int eleccionMenu;

    if(tipoDeMenu == 0){

        printf("*** MENU PRINCIPAL ***\n\n");
        printf("1) Importar datos precargados\n");
        printf("2) Calcular largo de la lista\n");
        printf("3) Mostrar lista\n");
        printf("4) Modificar elemento\n");
        printf("5) Eliminar elemento\n");
        printf("6) Vaciar lista\n");
        printf("7) Eliminar lista\n");
        printf("8) Agregar un nuevo elemento a la lista\n");
        printf("9) Eliminar un elemento y guardar su direccion\n");
        printf("10) Comparar lista de autos con lista de eliminados\n");
        printf("11) Crear sublista\n");
        printf("12) Clonar lista\n");
        printf("13) Ordenar lista de mas barato a mas caro\n");
        printf("14) Filtrar autos con modelo posterior al 2010\n");
        printf("20) Salir\n");

        getValidInt("\nElija una opcion: ", "Debe estar entre 1 y 20, vuelva a intentar: ", &eleccionMenu, 1, 20, 3);

    }
    else{

        printf("*** MENU DE MODIFICACIONES ***\n\n");
        printf("1) Modificar marca\n");
        printf("2) Modificar modelo\n");
        printf("3) Modificar precio\n");

        getValidInt("\nElija una opcion: ", "Debe estar entre 1 y 3, vuelva a intentar: ", &eleccionMenu, 1, 3, 3);

    }
    return eleccionMenu;

}

void mostrarAuto(eAuto* unAuto){

    if(unAuto != NULL){

        printf("%d    %s   %d   %d\n", unAuto->id, unAuto->marca, unAuto->modelo, unAuto->precio);

    }

}

void mostrarAutos(LinkedList* lista){

    int tam;
    if(lista != NULL){

        tam = ll_len(lista);
        printf("*** LISTADO AUTOS ***\n\n");
        printf("ID      Marca       Modelo     Precio\n");
        printf("-------------------------------------\n");
        for(int i = 0; i < tam; i++){

            mostrarAuto(ll_get(lista, i));

        }
        printf("\n");

    }

}

eAuto* modificarAuto(LinkedList* lista){

    eAuto* nuevoAuto;
    eAuto* autoAnterior;
    int idAModificar;
    int tamanio = ll_len(lista);

    if(lista != NULL){

        getValidInt("Ingrese el ID del auto a modificar: ", "Debe ser un ID de la lista, vuelva a intentar: ", &idAModificar, 1, (tamanio + 1), 3);
        autoAnterior = (eAuto*) ll_get(lista, idAModificar);
        nuevoAuto->id = autoAnterior->id;
        getValidString("Ingrese marca del nuevo auto: ", "Solo puede ingresar caracteres, vuelva a intentar. ", "Debe ingresar como maximo 50 caracteres, vuelva a intentar. ", nuevoAuto->marca, 50, 3);
        getValidInt("Ingrese modelo del nuevo auto: ", "Solo puede ingresar numeros entre 1950 y 2020, vuelva a intentar. ", (int*) nuevoAuto->modelo, 1950, 2020, 3);
        getValidInt("Ingrese precio del nuevo auto: ", "Solo puede ingresar valores entre 100000 y 1000000, vuelva a intentar. ", (int*) nuevoAuto->precio, 100000, 1000000, 3);
        ll_set(lista, idAModificar, nuevoAuto);

    }
    return nuevoAuto;

}

int eliminarAuto(LinkedList* lista){

    int error = 1;
    int idAEliminar;
    int tamanio = ll_len(lista);

    if(lista != NULL){

        getValidInt("Ingrese el ID del auto a eliminar: ", "Debe ser un ID de la lista, vuelva a intentar: ", &idAEliminar, 1, (tamanio + 1), 3);
        if(!ll_remove(lista, (idAEliminar - 1))){

            error = 0;

        }

    }
    return error;

}

int vaciarLista(LinkedList* lista){

    int error = 1;

    if(lista != NULL){

        if(!ll_clear(lista)){

            error = 0;

        }

    }
    return error;

}

int eliminarLista(LinkedList* lista){

    int error = 1;

    if(lista != NULL){

        if(!ll_deleteLinkedList(lista)){

            error = 0;

        }

    }
    return error;

}

int lastId(int idLista){

    static int staticId;
    int ultimoId;

    staticId = idLista;
    staticId++;
    ultimoId = staticId;

    return ultimoId;

}

eAuto generarElemento(LinkedList* lista){

    eAuto auxAuto;
    int nuevoId = ll_len(lista);

    if(lista != NULL){

        auxAuto.id = lastId(nuevoId);
        getValidString("Ingrese marca del nuevo auto: ", "Solo puede ingresar caracteres, vuelva a intentar. ", "Debe ingresar como maximo 50 caracteres, vuelva a intentar. ", &auxAuto.marca, 50, 3);
        getValidInt("Ingrese modelo del nuevo auto: ", "Solo puede ingresar numeros entre 1950 y 2020, vuelva a intentar. ", &auxAuto.modelo, 1950, 2020, 3);
        getValidInt("Ingrese precio del nuevo auto: ", "Solo puede ingresar valores entre 100000 y 1000000, vuelva a intentar. ", &auxAuto.precio, 100000, 1000000, 3);

    }
    return auxAuto;

}

int agregarElemento(LinkedList* lista, eAuto autoNuevo){

    int error = 1;
    int indiceElegido;
    int cantidad = ll_len(lista);

    if(lista != NULL){

        getValidInt("Ingrese la posicion en la que desea agregar al nuevo elemento: ", "Solo puede ingresar numeros, vuelva a intentar. ", &indiceElegido, 0, (cantidad + 1), 3);
        ll_push(lista, indiceElegido, &autoNuevo);
        error = 0;

    }
    return error;

}

void* eliminarYGuardar(LinkedList* lista){

    void* auxElemento = NULL;
    int indiceElegido;

    if(lista != NULL){

        getValidInt("Ingrese la posicion del elemento a eliminar: ", "Solo puede ingresar numeros, vuelva a intentar. ", &indiceElegido, 0, ll_len(lista), 3);
        auxElemento = ll_pop(lista, (indiceElegido - 1));

    }
    return auxElemento;

}

int compararListas(LinkedList* lista1, LinkedList* lista2){

    int error = -1;

    if(lista1 != NULL && lista2 != NULL){

        if(!ll_containsAll(lista1, lista2)){

            error = 1;

        }
        else{

            error = 0;

        }

    }
    return error;

}

LinkedList* crearSubLista(LinkedList* lista){

    int inferior;
    int superior;
    LinkedList* subLista = NULL;

    if(lista != NULL){

        getValidInt("Ingrese limite inferior de la sublista: ", "Solo puede ingresar numeros, vuelva a intentar. ", &inferior, 0, ll_len(lista), 3);
        getValidInt("Ingrese limite superior de la sublista: ", "Solo puede ingresar numeros, vuelva a intentar. ", &superior, 0, ll_len(lista), 3);
        subLista = ll_subList(lista, inferior, superior);

    }
    return subLista;

}

int ordenarAutoPorPrecio(void* auto1, void* auto2){

    int retorno = 0;
    float precio1;
    float precio2;


    if((auto1 != NULL) && (auto2 != NULL)){

        auto_getPrecio((eAuto*) auto1, &precio1);
        auto_getPrecio((eAuto*) auto2, &precio2);

        retorno = precio1 - precio2;
        if(retorno < 0){

            retorno = -1;

        }
        else if(retorno > 0){

            retorno = 1;

        }

    }

    return retorno;

}

int auto_getPrecio(eAuto* unAuto, int* precio){

    int error = 1;

    if(unAuto != NULL && precio != NULL){

        *precio = unAuto->precio;
        error = 0;

    }
    return error;

}

int filtrarAutosNuevos(void* unAuto){

    int rta = 0;
    eAuto* otroAuto = NULL;
    if(unAuto != NULL){

        otroAuto = (eAuto*) unAuto;
        if(otroAuto->modelo >= 2010){

            rta = 1;

        }

    }
    return rta;

}
