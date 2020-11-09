#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funcionesAdicionales.h"

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

    LinkedList* listaEmpleados = ll_newLinkedList();
    int cantidad;
    int eleccionMenu;
    int flagLoadText = 0;
    int flagLoadBin = 0;
    int flagAlta = 0;
    /*Employee* prueba;
    prueba = employee_newParametros("123","juan","42","42000");
    employee_listOneEmployee(prueba);*/

    if(listaEmpleados != NULL){

        do{

            system("cls");

            cantidad = ll_len(listaEmpleados);
            eleccionMenu = menuDeOpciones(0);
            switch(eleccionMenu){

                case 1:

                    if(!controller_loadFromText("data.csv", listaEmpleados)){

                        system("cls");
                        printf("\nArchivo de texto cargado con exito!\n\n");
                        flagLoadText = 1;
                        system("pause");

                    }
                    else{

                        printf("Error al cargar los datos.\n\n");
                        system("pause");

                    }
                    break;

                case 2:

                    if(!controller_loadFromBinary("data.bin",listaEmpleados)){

                        system("cls");
                        printf("\nArchivo binario cargado con exito!\n\n");
                        flagLoadBin = 1;
                        system("pause");

                    }
                    else{

                        printf("Error al cargar los datos.\n\n");
                        system("pause");

                    }
                    break;

                case 3:

                    if(!controller_addEmployee(listaEmpleados)){

                        system("cls");
                        printf("\nEmpleado dado de alta con exito!\n\n");
                        flagAlta = 1;
                        system("pause");

                    }
                    else{

                        printf("Error al intentar dar de alta.\n\n");
                        system("pause");

                    }
                    break;

                case 4:

                    if(controller_modifyEmployee(listaEmpleados) == 0){

                        system("cls");
                        printf("\nEmpleado modificado con exito!\n\n");
                        system("pause");

                    }
                    else if(controller_modifyEmployee(listaEmpleados) == 1){

                        printf("Error al intentar modificar.\n\n");
                        system("pause");

                    }
                    else{

                        printf("Modificacion cancelada por el usuario.\n\n");
                        system("pause");

                    }
                    break;

                case 5:

                    if(!controller_removeEmployee(listaEmpleados)){

                        system("cls");
                        printf("\nEmpleado dado de baja con exito!\n\n");
                        system("pause");

                    }
                    else{

                        printf("Error al intentar dar de baja.\n\n");
                        system("pause");

                    }
                    break;

                case 6:

                    if(flagLoadText || flagLoadBin || flagAlta){

                        controller_ListEmployee(listaEmpleados);
                        system("pause");

                    }
                    else{

                        printf("\nAntes de listar los empleados debe realizar la carga de datos.\n\n");
                        system("pause");

                    }
                    break;

                case 7:

                    if(flagLoadText || flagLoadBin || flagAlta){

                        if(!controller_sortEmployee(listaEmpleados)){

                            system("cls");
                            printf("\nEmpleados ordenados con exito!\n\n");
                            system("pause");

                        }
                        else{

                            printf("\nAntes de listar los empleados debe realizar la carga de datos.\n\n");
                            system("pause");

                        }

                    }
                    break;

                case 8:

                    if(!controller_saveAsText("data.csv", listaEmpleados) && (flagLoadText || flagLoadBin)){

                        system("cls");
                        printf("\nGuardado de texto exitoso!\n\n");
                        system("pause");

                    }
                    else{

                        printf("\nPara guardar debe cargar algun empleado.\n\n");
                        system("pause");

                    }

                    break;

                case 9:

                    if(!controller_saveAsBinary("data.bin", listaEmpleados) && (flagLoadText || flagLoadBin)){

                        system("cls");
                        printf("\nGuardado binario exitoso!\n\n");
                        system("pause");

                    }
                    else{

                        printf("\nPara guardar debe cargar algun empleado.\n\n");
                        system("pause");

                    }

                    break;

                case 10:

                    system("cls");
                    printf("\nGracias por utilizar el programa!\n");
                    break;

            }

        }while(eleccionMenu != 10);


    }


    // ll_sort(listaEmpleados, employeeSortBySalary, 1);
    // Employee* p1 = employee_new()
    // ll_add(listaEmpleados, p1)
    //Employee* unEmpleado = (Employee*) ll_get(listaEmpleados, 2);



    return 0;
}
