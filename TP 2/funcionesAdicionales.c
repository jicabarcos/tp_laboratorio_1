#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesAdicionales.h"
#include "ArrayEmployees.h"

int showMenu(int menuType){

    int menuOption;
    int upperLimit;

    if(menuType == 1){

        printf("> 1) Altas\n\n");
        printf("> 2) Modificar\n\n");
        printf("> 3) Baja\n\n");
        printf("> 4) Informar\n\n");
        printf("\nElija la opcion deseada: ");
        scanf("%d", &menuOption);

        upperLimit = 4;

    }
    else if(menuType == 2){

        printf("> 1) Nombre\n\n");
        printf("> 2) Apellido\n\n");
        printf("> 3) Salario\n\n");
        printf("> 4) Sector\n\n");
        printf("\nElija la opcion deseada: ");
        scanf("%d", &menuOption);

        upperLimit = 4;

    }
    else if(menuType == 3){

        printf("> 1) Mostrar lista de empleados ordenada por apellido y sector.\n\n");
        printf("> 2) Informar total de salarios, promedio y cantidad de empleados que superan el promedio.\n\n");
        printf("\nElija la opcion deseada: ");
        scanf("%d", &menuOption);

        upperLimit = 2;

    }
    else if(menuType == 4){

        printf("> 1) Sector ascendente, apellido ascendente.\n\n");
        printf("> 2) Sector ascendente, apellido descendente.\n\n");
        printf("> 3) Sector descendente, apellido ascendente.\n\n");
        printf("> 4) Sector descendente, apellido descendente.\n\n");
        printf("\nElija la opcion deseada: ");
        scanf("%d", &menuOption);

        upperLimit = 4;

    }

    while ((menuOption < 1) || (menuOption > upperLimit)){

        printf("Debe seleccionar una opcion valida, entre 1 y %d. Vuelva a elegir.", upperLimit);
        scanf("%d", &menuOption);

    }

    printf("\n");

    return menuOption;

}

int findEmpty(Employee employeesList[], int len){

    int index = -1;

    for(int i = 0; i < len; i++){

        if(employeesList[i].isEmpty){

            index = i;
            break;

        }

    }

    return index;

}

void printOneEmployee(Employee employeesList){

    printf(" %d  %10s  %10s  %.2f  %d\n", employeesList.id, employeesList.name, employeesList.lastName, employeesList.salary, employeesList.sector);

}

int modifyEmployee(Employee employeesList[], int len){  // 0 baja exitosa; 1 hubo problema; 2 cancelado

    int error = 1;
    int index;
    int id;
    Employee auxEmployee;
    int menuChoice;
    char confirm1;
    char confirm2;

    if((employeesList != NULL) && (len > 0)){

        system("cls");
        printf("*** MODIFICAR EMPLEADO ***\n\n");
        printEmployees(employeesList, len);
        printf("Ingrese id: ");
        scanf("%d", &id);

        index = findEmployeeById(employeesList, len, id);


        if(index == -1){

            printf("No hay ningun empleado con ese id.\n\n");

        }
        else{

            printf("\nEmpleado seleccionado:\n");
            printOneEmployee(employeesList[index]);
            printf("\nQue elemento desea modificar?\n\n");

            do{

            menuChoice = showMenu(2);

                switch(menuChoice){

                    case 1:

                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxEmployee.name);
                        break;

                    case 2:

                        printf("Ingrese nuevo apellido: ");
                        fflush(stdin);
                        gets(auxEmployee.lastName);
                        break;

                    case 3:

                        printf("Ingrese nuevo salario: ");
                        scanf("%f", &auxEmployee.salary);
                        break;

                    case 4:

                        printf("Ingrese nuevo sector: ");
                        scanf("%d", &auxEmployee.sector);
                        break;

                }

                printf("\nDesea realizar algun otro cambio? 'y' para aceptar, otro caracter para rechazar");
                fflush(stdin);
                scanf("%c", &confirm1);

            }while(confirm1 == 'y');

            printf("Confirma las modifaciones? 'y' para aceptar, otro caracter para rechazar: \n");
            fflush(stdin);
            scanf("%c", &confirm2);
            if(confirm2 == 'y'){

                employeesList[index] = auxEmployee;
                error = 0;

            }
            else{

                error = 2;

            }

        }

    }

    return error;

}

int modifyMenu(){

    int modifyMenuOption;

    printf("> 1) Nombre\n\n");

    printf("> 2) Apellido\n\n");

    printf("> 3) Salario\n\n");

    printf("> 4) Sector\n\n");

    printf("\nElija la opcion deseada: ");
    scanf("%d", &modifyMenuOption);

    while ((modifyMenuOption < 1) || (modifyMenuOption > 4)){

        printf("Debe seleccionar una opción válida, entre 1 y 4. Vuelva a elegir.");
        scanf("%d", &modifyMenuOption);

    }

    printf("\n");

    return modifyMenuOption;

}

int salariesSum(Employee employeesList[], int len){

    int i;
    int sum = 0;

    if((employeesList != NULL) && (len > 0)){

        for(i = 0; i < len; i++){

            if(employeesList[i].isEmpty == 0){

                sum = (float) sum + employeesList[i].salary;

            }

        }

    }

    return sum;

}

int employeesQuantity(Employee employeesList[], int len){

    int i;
    int quantity = 0;

    if((employeesList != NULL) && (len > 0)){

        for(i = 0; i < len; i++){

            if(employeesList[i].isEmpty == 0){

                quantity++;

            }

        }

    }

    return quantity;

}

int employeesAboveProm(Employee employeesList[], int len, float prom){

    int i;
    int topPaid = 0;

    if((employeesList != NULL) && (len > 0)){

        for(i = 0; i < len; i++){

            if(employeesList[i].salary > prom && employeesList[i].isEmpty == 0){

                topPaid++;

            }

        }

    }

    return topPaid;

}

int sortByLastNameAndSector(Employee employeesList[], int len, int lastNameOrder, int sectorOrder){ // 1 asc, 0 desc

    int error = 1;
    int i;
    int j;
    Employee auxEmployee;

    if(employeesList != NULL && len > 0 && lastNameOrder >= 0 && lastNameOrder <= 1 && sectorOrder >= 0 && sectorOrder <= 1){

        for(i = 0; i < len - 1; i++){

            for(j = i + 1; j < len; j++){

                if(sectorOrder && (strcmp(employeesList[i].lastName, employeesList[j].lastName) == 1)){

                    auxEmployee = employeesList[i];
                    employeesList[i] = employeesList[j];
                    employeesList[j] = auxEmployee;

                }
                else if((!sectorOrder) && (strcmp(employeesList[i].lastName, employeesList[j].lastName) == -1)){

                    auxEmployee = employeesList[i];
                    employeesList[i] = employeesList[j];
                    employeesList[j] = auxEmployee;

                }// CORREGIR SORT SECTOR APELLIDO
                else if((strcmp(employeesList[i].lastName, employeesList[j].lastName) == 0) && ((((employeesList[i].sector > employeesList[j].sector) && lastNameOrder)) || ((employeesList[i].sector < employeesList[j].sector) && (!lastNameOrder)))){

                    auxEmployee = employeesList[i];
                    employeesList[i] = employeesList[j];
                    employeesList[j] = auxEmployee;

                }

            }

        }

        error = 0;

    }

    return error;

}

void howToSort(Employee employeesList[], int tam, int sortKind){ // 1 AA, 2 AD, 3 DA, 4 DD

    if(sortKind == 1){

        sortByLastNameAndSector(employeesList, tam, 1, 1);

    }
    else if(sortKind == 2){

        sortByLastNameAndSector(employeesList, tam, 1, 0);

    }
    else if(sortKind == 3){

        sortByLastNameAndSector(employeesList, tam, 0, 1);

    }
    else{

        sortByLastNameAndSector(employeesList, tam, 0, 0);

    }

}
