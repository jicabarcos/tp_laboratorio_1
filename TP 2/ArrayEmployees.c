#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "funcionesAdicionales.h"

int initEmployees(Employee employeesList[], int len){

    int error = 1;

    if((employeesList != NULL) && (len > 0)){

        for(int i = 0; i < len; i++){

            employeesList[i].isEmpty = 1;

        }

        error = 0;

    }

    return error;

}

int addEmployee(Employee employeesList[], int len, int id){

    int error = 1;
    int index;
    Employee auxEmployee;

    if((employeesList != NULL) && (len > 0) && (id > 0)){

        index = findEmpty(employeesList, len);
        if(index == -1){

            printf("Sistema completo.\n");

        }
        else{

            system("cls");
            printf("*** ALTA DE EMPLEADO ***\n\n");

            // INGRESO DE DATOS DEL EMPLEADO
            auxEmployee.id = id;

            auxEmployee.isEmpty = 0;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmployee.name);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(auxEmployee.lastName);

            printf("Ingrese salario: ");
            scanf("%f", &auxEmployee.salary);

            printf("Ingrese sector: ");
            scanf("%d", &auxEmployee.sector);

            employeesList[index] = auxEmployee;

            error = 0;

        }

    }

    printf("\n");

    return error;

}

int findEmployeeById(Employee employeesList[], int len, int id){

    int index = -1;

    for(int i = 0; i < len; i++){

        if((employeesList[i].id == id) && (!employeesList[i].isEmpty)){

            index = i;
            break;

        }

    }

    return index;

}

int removeEmployee(Employee employeesList[], int len){

    int error = 1;
    int index;
    int id;
    char confirm;

    if((employeesList != NULL) && (len > 0)){

        system("cls");
        printf("*** BAJA PERSONA ***\n\n");
        printEmployees(employeesList, len);
        printf("\nIngrese id del empleado a dar de baja: ");
        scanf("%d", &id);

        index = findEmployeeById(employeesList, len, id);

        if(index == -1){

            printf("\nNo hay ningun empleado con ese id.\n\n");

        }
        else{

            printOneEmployee(employeesList[index]);
            printf("Confirma la baja?\n");
            fflush(stdin);
            scanf("%c", &confirm);
            printf("\n");
            if(confirm == 's'){

                employeesList[index].isEmpty = 1;
                error = 0;

            }
            else{

                error = 2;

            }

        }

    }

    return error;

}

int printEmployees(Employee employeesList[], int len){

    int error = 1;
    int flag = 0;

    if((employeesList != NULL) && (len > 0)){

        printf("***        LISTADO DE EMPLEADOS        ***\n\n");
        printf("  ID  NOMBRE  APELLIDO   SALARIO   SECTOR\n");
        printf("-----------------------------------------\n");
        for(int i = 0; i < len; i++){

            if(employeesList[i].isEmpty == 0){

                printOneEmployee(employeesList[i]);
                flag = 1;

            }

        }

        if(!flag){

            printf("No hay empleados en la lista.\n");

        }
        else{

            printf("\n\n");

        }

        error = 0;

    }

    return error;

}
