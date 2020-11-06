#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    ///controller_loadFromText("data.csv", listaEmpleados);


    Employee* tuVieja;

    tuVieja = employee_new();

    free(tuVieja);
    tuVieja = NULL;


    printf("%d",ll_add(listaEmpleados, tuVieja));

    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);

    // ll_sort(listaEmpleados, employeeSortBySalary, 1);
    // Employee* p1 = employee_new()
    // ll_add(listaEmpleados, p1)
    //Employee* unEmpleado = (Employee*) ll_get(listaEmpleados, 2);*/



    return 0;
}
