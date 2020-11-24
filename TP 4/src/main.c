/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "funcionesAdicionales.h"

int main(void)
{
        /*startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
        startTesting(3);  // getNode - test_getNode
        startTesting(4);  // addNode - test_addNode
        startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove
        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone
        startTesting(19); // ll_sort */


    int opcionElegida;
    int flagCarga = 0;
    int tamanioLista;
    char confirmaEliminar;
    eAuto nuevoAuto;
    eAuto* autoEliminado;
    char agregarEliminados;
    int flagPop = 0;
    char imprimirSubLista;
    char imprimirListaFiltrada;
    char salir;

    LinkedList* listaAutos = ll_newLinkedList();
    LinkedList* listaEliminados = ll_newLinkedList();
    LinkedList* subLista = NULL;
    LinkedList* listaClonada = NULL;
    LinkedList* listaFiltrada = NULL;

    eAuto auto1 = {1, "Ford", 2010, 300000};
    eAuto auto2 = {2, "Chevrolet", 2002, 270000};
    eAuto auto3 = {3, "Volkswagen", 2016, 350000};
    eAuto auto4 = {4, "Renault", 1983, 320000};
    eAuto auto5 = {5, "Audi", 2018, 400000};

    printf("Inicializando programa...\n\n");
    system("pause");

    do{

        system("cls");
        opcionElegida = menuDeOpciones(0);

        switch(opcionElegida){

            case 1:

                system("cls");
                if(!flagCarga){

                    ll_add(listaAutos, &auto1);
                    ll_add(listaAutos, &auto2);
                    ll_add(listaAutos, &auto3);
                    ll_add(listaAutos, &auto4);
                    ll_add(listaAutos, &auto5);
                    printf("Datos importados con exito!\n\n");
                    flagCarga = 1;
                }
                else{

                    printf("Ya se realizo la carga anteriormente!\n\n");

                }
                system("pause");
                break;

            case 2:

                system("cls");
                if(ll_isEmpty(listaAutos) == 0){

                    tamanioLista = ll_len(listaAutos);
                    printf("La lista tiene %d elementos\n", tamanioLista);

                }
                else if(ll_isEmpty(listaAutos) == 1){

                    printf("La lista tiene 0 elementos\n");

                }
                else{

                    printf("Hubo un error al calcular el largo de la lista\n");

                }
                system("pause");
                break;

            case 3:

                system("cls");
                if(flagCarga){

                    mostrarAutos(listaAutos);

                }
                system("pause");
                break;

            case 4:

                system("cls");
                if(flagCarga){

                    mostrarAutos(listaAutos);
                    modificarAuto(listaAutos);

                }
                system("pause");
                break;

            case 5:

                system("cls");
                if(flagCarga){

                    mostrarAutos(listaAutos);
                    if(!eliminarAuto(listaAutos)){

                        printf("Elemento eliminado con exito!\n");

                    }

                }
                else{

                    printf("No puede eliminar un elemento si no hay ninguno cargado.\n");

                }
                system("pause");
                break;

            case 6:

                system("cls");
                if(!vaciarLista(listaAutos)){

                    printf("Lista vaciada con exito!\n");

                }
                else{

                    printf("Hubo un error al intentar vaciar la lista\n");

                }
                system("pause");
                break;

            case 7:

                system("cls");
                printf("\nPRECAUCION!!! Esta a punto de eliminar la lista definitivamente\n");
                printf("Si desea hacerlo, pulse 'X', de lo contrario, pulse otro caracter\n");
                fflush(stdin);
                confirmaEliminar = toupper(getchar());
                if(confirmaEliminar != 'X'){

                    printf("Eliminacion cancelada por el usuario\n");
                    system("pause");
                    break;

                }
                else{

                    if(!eliminarLista(listaAutos)){

                        printf("Eliminacion exitosa!\n");

                    }
                    else{

                        printf("Error al eliminar la lista\n");

                    }
                    system("pause");
                    break;

                }

            case 8:

                system("cls");
                nuevoAuto = generarElemento(listaAutos);
                if(!agregarElemento(listaAutos, nuevoAuto)){

                    printf("Elemento agregado a la lista con exito!\n");

                }
                else{

                    printf("Error al agregar elemento a la lista\n");

                }
                system("pause");
                break;

            case 9:

                system("cls");
                mostrarAutos(listaAutos);
                autoEliminado = (eAuto*) eliminarYGuardar(listaAutos);
                printf("Desea agregar este elemento a la lista de eliminados? 'Y' para confirmar\n");
                fflush(stdin);
                agregarEliminados = toupper(getchar());
                if(agregarEliminados == 'Y'){

                    ll_add(listaEliminados, autoEliminado);
                    flagPop = 1;

                }
                system("pause");
                break;

            case 10:

                system("cls");
                if(flagCarga && flagPop){

                    if(compararListas(listaAutos, listaEliminados) == 0){

                        printf("Las listas son iguales!\n\n");

                    }
                    else if(compararListas(listaAutos, listaEliminados) == 1){

                        printf("Las listas no son iguales\n\n");

                    }
                    else{

                        printf("Error al comparar las listas\n\n");

                    }

                }
                else{

                    printf("No hay dos listas para comparar\n\n");

                }
                system("pause");
                break;

            case 11:

                system("cls");
                subLista = crearSubLista(listaAutos);
                printf("Quiere imprimir la sublista? 'Y' para confirmar\n");
                fflush(stdin);
                imprimirSubLista = toupper(getchar());
                if(imprimirSubLista == 'Y'){

                    mostrarAutos(subLista);

                }
                system("pause");
                break;

            case 12:

                system("cls");
                listaClonada = ll_clone(listaAutos);
                system("pause");
                break;

            case 13:

                system("cls");
                if(!ll_sort(listaAutos, ordenarAutoPorPrecio, 1)){

                    printf("Lista ordenada con exito!\n");

                }
                else{

                    printf("Error al intentar ordenar la lista\n");

                }
                system("pause");
                break;

            case 14:

                system("cls");
                listaFiltrada = ll_filter(listaAutos, filtrarAutosNuevos);
                printf("Quiere imprimir la lista filtrada? 'Y' para confirmar\n");
                fflush(stdin);
                imprimirListaFiltrada = toupper(getchar());
                if(imprimirListaFiltrada == 'Y'){

                    mostrarAutos(listaFiltrada);

                }

                system("pause");
                break;

            case 20:

                system("cls");
                printf("Pulse 'Y' para salir u otro caracter para seguir trabajando\n");
                fflush(stdin);
                salir = toupper(getchar());
                system("pause");
                break;

        }

    }while(salir != 'Y');

    system("cls");
    printf("Gracias por utilizar el programa, hasta la proxima!!\n\n");
    system("pause");

    free(listaAutos);
    free(listaEliminados);
    free(subLista);
    free(listaClonada);
    free(listaFiltrada);
    return 0;

}
