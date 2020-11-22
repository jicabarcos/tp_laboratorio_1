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
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct{

    int id;
    char nombre[50];
    char sexo;
    float sueldo;

}eEmpleado;

void mostrarEmpleado(eEmpleado* e){

    if(e != NULL){

        printf("%d    %s   %c   %.2f\n", e->id, e->nombre, e->sexo, e->sueldo);

    }

}

void mostrarEmpleados(LinkedList* lista){

    int tam;
    if(lista != NULL){

        tam = ll_len(lista);
        for(int i = 0; i < tam; i++){

            mostrarEmpleado(ll_get(lista, i));

        }

    }

}

int filtrarMujeres(void* emp){ // o puedo filtrar como quiera

    int rta = 0;
    eEmpleado* e = NULL;
    if(emp != NULL){

        e = (eEmpleado*) emp;

        if(e->sexo == 'f'){

            rta = 1;

        }

    }

    return rta;

}


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


    LinkedList* lista = ll_newLinkedList();
    LinkedList* mujeres = NULL;

    eEmpleado emp1 = {1, "Juan", 'm', 30000};
    eEmpleado emp2 = {2, "Juana", 'f', 50000};
    eEmpleado emp3 = {3, "Miguel", 'm', 20000};
    eEmpleado emp4 = {4, "Analia", 'f', 60000};
    eEmpleado emp5 = {5, "Jorge", 'm', 34000};
    eEmpleado emp6 = {6, "Julia", 'f', 44000};
    eEmpleado emp7 = {7, "Andrea", 'f', 37000};

    ll_add(lista, &emp1);
    ll_add(lista, &emp2);
    ll_add(lista, &emp3);
    ll_add(lista, &emp4);
    ll_add(lista, &emp5);
    ll_add(lista, &emp6);
    ll_add(lista, &emp7);

    mujeres = ll_filter(lista, filtrarMujeres);


    printf("TODOS\n");
    mostrarEmpleados(lista);

    printf("\n\nMUJERES\n");
    mostrarEmpleados(mujeres);

    free(lista);
    free(mujeres);









    return 0;

}

































