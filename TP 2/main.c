#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "funcionesAdicionales.h"

#define LEN 1000
#define ASC 1
#define DESC 0

int main()
{

    // DECLARACION DE VARIABLES
    Employee list[LEN];
    int menuChoice;
    int flagAddEmployee = 0;
    int idNumber = 1000;
    int addEmployeeResult;
    int modifyEmployeeResult;
    int removeEmployeeResult;
    int informChoice1;
    int informChoice2;
    int howManyEmployees;
    int abovePromResult;
    float salariesSumResult;
    float salariesProm;
    char exit;


    // INICIALIZACION DEL ARRAY
    initEmployees(list, LEN);
    printf("Preparando nomina...\n\n");
    system("pause");

    do{

        // TITULO
        system("cls");
        printf("***NOMINA DE EMPLEADOS***\n\n\n");

        // MENU
        menuChoice = showMenu(1);

        // OPCION A REALIZAR EN BASE A LO QUE ELIJA EL USUARIO
        switch(menuChoice){

            // ALTA
            case 1:

                addEmployeeResult = addEmployee(list, LEN, idNumber);
                if(!addEmployeeResult){

                    idNumber++;
                    printf("Empleado agregado con exito.\n\n");
                    flagAddEmployee = 1;

                }
                else{

                    printf("Error al intentar agregar empleado.\n");

                }
                system("pause");
                break;

            // MODIFICAR
            case 2:

                if(flagAddEmployee){

                    modifyEmployeeResult = modifyEmployee(list, LEN);
                    if(modifyEmployeeResult == 0){

                        printf("Modifiacion exitosa.\n\n");

                    }
                    else if(modifyEmployeeResult == 1){

                        printf("Error al intentar modificar.\n\n");

                    }
                    else{

                        printf("Modificacion cancelada por el usuario.");

                    }


                }
                else{

                    printf("Primero debe dar de alta al menos a un empleado.\n\n");

                }
                system("pause");
                break;

            // BAJA
            case 3:

                if(flagAddEmployee){

                    removeEmployeeResult = removeEmployee(list, LEN);
                    if(removeEmployeeResult == 0){

                        printf("Baja exitosa.\n\n");

                    }
                    else if(removeEmployeeResult == 1){

                        printf("Error al intentar dar la baja.\n\n");

                    }
                    else{

                        printf("Baja cancelada por el usuario.\n\n");

                    }

                }
                else{

                    printf("Primero debe dar de alta al menos a un empleado.\n\n");

                }
                system("pause");
                break;

            // INFORMAR
            default:

                if(flagAddEmployee){

                    informChoice1 = showMenu(3);
                    if(informChoice1 == 1){

                        printf("Como quiere ordenar?\n\n");
                        informChoice2 = showMenu(4);
                        howToSort(list, LEN, informChoice2);
                        printEmployees(list, LEN);

                    }
                    else{

                        salariesSumResult = salariesSum(list, LEN);
                        howManyEmployees = employeesQuantity(list, LEN);
                        salariesProm = (float) salariesSumResult / howManyEmployees;
                        abovePromResult = employeesAboveProm(list, LEN, salariesProm);

                        printEmployees(list, LEN);

                        printf("La suma total de los salarios es de %.2f.\n", salariesSumResult);
                        printf("El promedio es %.2f.\n", salariesProm);
                        printf("Hay %d empleados que cobran por encima del promedio.\n\n", abovePromResult);

                    }

                }
                else{

                    printf("Primero debe dar de alta al menos a un empleado.\n\n");

                }
                system("pause");

        }

        printf("Pulse 'x' si desea salir, u otra letra para seguir operando.");
        scanf("%c", &exit);

    }while(exit != 'x');

    system("cls");
    printf("Gracias por usar el programa!!\n\n");

    return 0;
}
