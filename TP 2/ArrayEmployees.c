#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "funcionesAdicionales.h"
#include "utn.h"

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
    int validName;
    int validLastName;
    int validSalary;
    int validSector;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;

    if((employeesList != NULL) && (len > 0) && (id > 0)){

        index = findEmpty(employeesList, len);
        if(index == -1){

            printf("Sistema completo.\n");

        }
        else{

            system("cls");
            printf("*** ALTA DE EMPLEADO ***\n\n");

            // INGRESO DE DATOS DEL EMPLEADO
            employeesList[index].id = id;
            employeesList[index].isEmpty = 0;

            do{

                validName = getValidString("Ingrese nombre: \n", "Solo puede ingresar letras. Vuelva a intentar: \n", "No puede tener mas de 50 caracteres. Vuelva a intentar: \n", auxName, 50, 1);

            }while(validName == -1);
            strcpy(employeesList[index].name, auxName);

            do{

                validLastName = getValidString("Ingrese apellido: \n", "Solo puede ingresar letras. Vuelva a intentar: \n", "No puede tener mas de 50 caracteres. Vuelva a intentar: \n", auxLastName, 50, 1);

            }while(validLastName == -1);
            strcpy(employeesList[index].lastName, auxLastName);

            do{

                validSalary = getValidFloat("Ingrese salario: \n", "Solo puede ingresar numeros enteros o decimales. Vuelva a intentar: \n", &auxSalary, 0, 1000000, 1);

            }while(validSalary == -1);
            employeesList[index].salary = auxSalary;

            do{

                validSector = getValidInt("Ingrese sector: \n", "Solo puede ingresar numeros enteros. Vuelva a intentar: \n", &auxSector, 0, 1000000, 1);

            }while(validSector == -1);
            employeesList[index].sector = auxSector;

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
            printf("\nConfirma la baja? 'y' para confirmar, otro caracter para rechazar\n");
            fflush(stdin);
            scanf("%c", &confirm);
            printf("\n");
            if(confirm == 'y'){

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
