#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionesAdicionales.h"
#include "ArrayEmployees.h"
#include "utn.h"

int showMenu(int menuType){

    int menuOption;
    int upperLimit;

    // MENU PRINCIPAL
    if(menuType == 1){

        printf("> 1) Altas\n\n");
        printf("> 2) Modificar\n\n");
        printf("> 3) Baja\n\n");
        printf("> 4) Informar\n\n");
        printf("\nElija la opcion deseada: ");
        scanf("%d", &menuOption);

        upperLimit = 4;

    }
    // SUBMENU MODIFICAR
    else if(menuType == 2){

        printf("> 1) Nombre\n\n");
        printf("> 2) Apellido\n\n");
        printf("> 3) Salario\n\n");
        printf("> 4) Sector\n\n");
        printf("\nElija la opcion deseada: ");
        scanf("%d", &menuOption);

        upperLimit = 4;

    }
    // SUBMENU INFORMAR
    else if(menuType == 3){

        printf("> 1) Mostrar lista de empleados ordenada por apellido y sector.\n\n");
        printf("> 2) Informar total de salarios, promedio y cantidad de empleados que superan el promedio.\n\n");
        printf("\nElija la opcion deseada: ");
        scanf("%d", &menuOption);

        upperLimit = 2;

    }
    // SUBMENU ORDENAR
    else if(menuType == 4){

        printf("> 1) Sector ascendente, apellido ascendente.\n\n");
        printf("> 2) Sector descendente, apellido ascendente.\n\n");
        printf("> 3) Sector ascendente, apellido descendente.\n\n");
        printf("> 4) Sector descendente, apellido descendente.\n\n");
        printf("\nElija la opcion deseada: ");
        scanf("%d", &menuOption);

        upperLimit = 4;

    }

    // VALIDACION OPCION ELEGIDA
    while ((menuOption < 1) || (menuOption > upperLimit)){

        printf("Debe seleccionar una opcion valida, entre 1 y %d. Vuelva a elegir:\n", upperLimit);
        scanf("%d", &menuOption);

    }

    printf("\n");

    return menuOption;

}

int findEmpty(Employee employeesList[], int len){

    int index = -1;

    // RECORRO EL ARRAY BUSCANDO ESPACIOS DISPONIBLES
    for(int i = 0; i < len; i++){

        if(employeesList[i].isEmpty){

            index = i;
            break;

        }

    }

    return index;

}

void printOneEmployee(Employee employeesList){

    printf(" %d  %10s  %10s    %2.2f    %3d\n", employeesList.id, employeesList.name, employeesList.lastName, employeesList.salary, employeesList.sector);

}

int modifyEmployee(Employee employeesList[], int len){

    int error = 1;
    int index;
    int id;
    int validName;
    int validLastName;
    int validSalary;
    int validSector;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    int menuChoice;
    char confirm1;
    char confirm2;

    if((employeesList != NULL) && (len > 0)){

        system("cls");
        printf("*** MODIFICAR EMPLEADO ***\n\n");
        printEmployees(employeesList, len);
        printf("Ingrese id: ");
        scanf("%d", &id);

        // VERIFICO SI HAY ALGUN EMPLEADO CON ESE ID
        index = findEmployeeById(employeesList, len, id);

        // ID USADO
        if(index == -1){

            printf("No hay ningun empleado con ese id.\n\n");

        }
        // ID LIBRE
        else{

            printf("\nEmpleado seleccionado:\n");
            printOneEmployee(employeesList[index]);
            printf("\nQue elemento desea modificar?\n\n");

            do{

            // MENU MODIFICAR
            menuChoice = showMenu(2);

                switch(menuChoice){

                    // MODIFICAR NOMBRE
                    case 1:

                        do{

                            validName = getValidString("Ingrese nuevo nombre: \n", "Solo puede ingresar letras. Vuelva a intentar: \n", "No puede tener mas de 50 caracteres. Vuelva a intentar: \n", auxName, 50, 1);

                        }while(validName == -1);
                        strcpy(employeesList[index].name, auxName);
                        break;

                    // MODIFICAR APELLIDO
                    case 2:

                        do{

                            validLastName = getValidString("Ingrese nuevo apellido: \n", "Solo puede ingresar letras. Vuelva a intentar: \n", "No puede tener mas de 50 caracteres. Vuelva a intentar: \n", auxLastName, 50, 1);

                        }while(validLastName == -1);
                        strcpy(employeesList[index].lastName, auxLastName);
                        break;

                    // MODIFICAR SALARIO
                    case 3:

                        do{

                            validSalary = getValidFloat("Ingrese nuevo salario: \n", "Solo puede ingresar numeros enteros o decimales. Vuelva a intentar: \n", &auxSalary, 0, 1000000, 1);

                        }while(validSalary == -1);
                        employeesList[index].salary = auxSalary;
                        break;

                    // MODIFICAR SECTOR
                    case 4:

                        do{

                            validSector = getValidInt("Ingrese sector: \n", "Solo puede ingresar numeros enteros. Vuelva a intentar: \n", &auxSector, 0, 1000000, 1);

                        }while(validSector == -1);
                        employeesList[index].sector = auxSector;
                        break;

                }

                // OPCION DE SEGUIR MODIFICANDO O FRENAR
                printf("\nDesea realizar algun otro cambio? 'y' para aceptar, otro caracter para rechazar.\n");
                fflush(stdin);
                scanf("%c", &confirm1);

            }while(confirm1 == 'y');

            // CONFIRMACION DE LAS MODIFICACIONES REALIZADAS
            printf("Confirma las modifaciones? 'y' para aceptar, otro caracter para cancelar: \n");
            fflush(stdin);
            scanf("%c", &confirm2);
            if(confirm2 == 'y'){

                error = 0;

            }
            // USUARIO CANCELA MODIFICACIONES
            else{

                error = 2;

            }

        }

    }

    return error;

}

int salariesSum(Employee employeesList[], int len){

    int i;
    int sum = 0;

    if((employeesList != NULL) && (len > 0)){

        // RECORRO ARRAY EN BUSCA LUGARES OCUPADOS Y ACUMULO LOS SALARIOS CORRESPONDIENTES
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

        // RECORRO ARRAY EN BUSCA DE LUGARES OCUPADOS Y CUENTO
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

        // RECORRO ARRAY EN BUSCA DE EMPLEADOS QUE SUPEREN EL SALARIO PROMEDIO
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

    if(employeesList != NULL && len > 0 && sectorOrder >= 0 && sectorOrder <= 1 && lastNameOrder >= 0 && lastNameOrder <= 1){

        for(i = 0; i < len - 1; i++){

            for(j = i + 1; j < len; j++){

                // CRITERIOS DE ORDENAMIENTO
                if((sectorOrder && (employeesList[i].sector > employeesList[j].sector)) ||
                ((!sectorOrder) && (employeesList[i].sector < employeesList[j].sector)) ||
                ((employeesList[i].sector == employeesList[j].sector) && ((strcmp(employeesList[i].lastName, employeesList[j].lastName) == 1) && lastNameOrder)) ||
                ((employeesList[i].sector == employeesList[j].sector) && ((strcmp(employeesList[i].lastName, employeesList[j].lastName) == -1) && !lastNameOrder))){

                    // SWAP / BURBUJEO
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

void howToSort(Employee employeesList[], int tam, int sortKind){

    system("cls");
    if(sortKind == 1){

        // APELLIDO ASCENDENTE, SECTOR ASCENDENTE
        sortByLastNameAndSector(employeesList, tam, 1, 1);

    }
    else if(sortKind == 2){

        // APELLIDO ASCENDENTE, SECTOR DESCENDENTE
        sortByLastNameAndSector(employeesList, tam, 1, 0);

    }
    else if(sortKind == 3){

        // APELLIDO DESCENDENTE, SECTOR ASCENDENTE
        sortByLastNameAndSector(employeesList, tam, 0, 1);

    }
    else{

        // APELLIDO DESCENDENTE, SECTOR DESCENDENTE
        sortByLastNameAndSector(employeesList, tam, 0, 0);

    }

}
