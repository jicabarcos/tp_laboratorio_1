#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Employee.h"
#include "bibliotecaUTN.h"
#include "Controller.h"
#include "funcionesAdicionales.h"

Employee* employee_new(){

    Employee* newEmployee = NULL;

    newEmployee = (Employee*) malloc(sizeof(Employee));

    if(newEmployee != NULL){

        employee_setId(newEmployee, 0);
        employee_setNombre(newEmployee, " ");
        employee_setHorasTrabajadas(newEmployee, 0);
        employee_setSueldo(newEmployee, 0);

    }

    return newEmployee;

}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr){

    Employee* newEmployee = employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){

        id = atoi(idStr);
        horasTrabajadas = atoi(horasTrabajadasStr);
        sueldo = atoi(sueldoStr);

        if(!(!employee_setId(newEmployee, id) &&
           !employee_setNombre(newEmployee, nombreStr) &&
           !employee_setHorasTrabajadas(newEmployee, horasTrabajadas) &&
           !employee_setSueldo(newEmployee, sueldo))){

            free(newEmployee);
            newEmployee = NULL;

        }

    }

    return newEmployee;

}

int employee_setId(Employee* this, int id){

    int error = 1;

    if(this != NULL && id > 0){

        this->id = id;
        error = 0;

    }

    return error;

}

int employee_getId(Employee* this, int* id){

    int error = 1;

    if(this != NULL && id != NULL){

        *id = this->id;
        error = 0;

    }

    return error;

}

int employee_setNombre(Employee* this, char* nombre){

    int error = 1;

    if(this != NULL && nombre != NULL){

        strcpy(this->nombre, nombre);
        error = 0;

    }

    return error;

}

int employee_getNombre(Employee* this, char* nombre){

    int error = 1;

    if(this != NULL && nombre != NULL){

        strcpy(nombre, this->nombre);
        error = 0;

    }

    return error;

}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){

    int error = 1;

    if(this != NULL && horasTrabajadas > 0){

        this->horasTrabajadas = horasTrabajadas;
        error = 0;

    }

    return error;

}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){

    int error = 1;

    if(this != NULL && horasTrabajadas != NULL){

        *horasTrabajadas = this->horasTrabajadas;
        error = 0;

    }

    return error;

}

int employee_setSueldo(Employee* this, int sueldo){

    int error = 1;

    if(this != NULL && sueldo > 0){

        this->sueldo = sueldo;
        error = 0;

    }

    return error;

}

int employee_getSueldo(Employee* this, int* sueldo){

    int error = 1;

    if(this != NULL && sueldo != NULL){

        *sueldo = this->sueldo;
        error = 0;

    }

    return error;

}

int employeeSortById(void* empleadoA, void* empleadoB){

    int retorno = 0;
    int idA;
    int idB;


    if((empleadoA != NULL) && (empleadoB != NULL)){

        employee_getId((Employee*) empleadoA, &idA);
        employee_getId((Employee*) empleadoB, &idB);

        retorno = idA - idB;
        if(retorno < 0){

            retorno = -1;

        }
        else if(retorno > 0){

            retorno = 1;

        }

    }

    return retorno;

}

int employeeSortByName(void* empleadoA, void* empleadoB){

    int retorno = 0;
    char nombreA[20];
    char nombreB[20];


    if((empleadoA != NULL) && (empleadoB != NULL)){

        employee_getNombre((Employee*) empleadoA, nombreA);
        employee_getNombre((Employee*) empleadoB, nombreB);

        retorno = strcmp(nombreA, nombreB);
        if(retorno < 0){

            retorno = -1;

        }
        else if(retorno > 0){

            retorno = 1;

        }

    }

    return retorno;

}


int employeeSortByHorasTrabajadas(void* empleadoA, void* empleadoB){

    int retorno = 0;
    int horasA;
    int horasB;


    if((empleadoA != NULL) && (empleadoB != NULL)){

        employee_getHorasTrabajadas((Employee*) empleadoA, &horasA);
        employee_getHorasTrabajadas((Employee*) empleadoB, &horasB);

        retorno = horasA - horasB;
        if(retorno < 0){

            retorno = -1;

        }
        else if(retorno > 0){

            retorno = 1;

        }

    }

    return retorno;

}

int employeeSortBySueldo(void* empleadoA, void* empleadoB){

    int retorno = 0;
    int sueldoA;
    int sueldoB;


    if((empleadoA != NULL) && (empleadoB != NULL)){

        employee_getSueldo((Employee*) empleadoA, &sueldoA);
        employee_getSueldo((Employee*) empleadoB, &sueldoB);

        retorno = sueldoA - sueldoB;
        if(retorno < 0){

            retorno = -1;

        }
        else if(retorno > 0){

            retorno = 1;

        }

    }

    return retorno;

}

void employee_listOneEmployee(LinkedList* employeesList){

    int auxId;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSueldo;
    int cantidadDeEmpleados;
    Employee* auxEmployee = NULL;

    cantidadDeEmpleados = ll_len(employeesList);

    if(employeesList != NULL){

        auxEmployee = employee_new();
        if(auxEmployee != NULL){

            for(int i = 0; i < cantidadDeEmpleados; i++){

                auxEmployee = (Employee*) ll_get(employeesList, i);
                employee_getId(auxEmployee, &auxId);
                employee_getNombre(auxEmployee, auxNombre);
                employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
                employee_getSueldo(auxEmployee, &auxSueldo);
                printf("%d   %s   %d   %d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

            }

        }

    }

}

int employee_addNewEmployee(LinkedList* employeesList){

    int error = 1;
    Employee* newEmployee;
    char newId[50];
    char newNombre[50];
    char newHorasTrabajadas[50];
    char newSueldo[50];
    int x;
    int cantidadDeEmpleados;

    if(employeesList != NULL){

        printf("\n *** ALTA EMPLEADO ***\n\n");

        cantidadDeEmpleados = ll_len(employeesList);
        itoa(lastId(cantidadDeEmpleados), newId, 10);
        getString("Ingrese nombre: ", newNombre);  // VALID STRING LAS 3
        getString("Ingrese cantidad de horas trabajadas: ", newHorasTrabajadas);
        getString("Ingrese sueldo: ", newSueldo);

        newEmployee = employee_newParametros(newId, newNombre, newHorasTrabajadas, newSueldo);
        if(newEmployee != NULL){

            x = ll_add(employeesList, newEmployee);
            if(!x){

                error = 0;

            }

        }

    }
    return error;

}

int employee_modifyEmployee(LinkedList* employeesList){

    int error = 1;
    Employee* auxEmployee;
    int cantidadDeEmpleados;
    int idABuscar;
    int auxId;
    int eleccionMenuModify;
    char nuevoNombre[50];
    int nuevasHorasTrabajadas;
    int nuevoSueldo;
    int flagNombre = 0;
    int flagHorasTrabajadas = 0;
    int flagSueldo = 0;
    char otraModif;
    char confirmaModif;

    if(employeesList != NULL){

        printf("\n *** MODIFICAR EMPLEADO ***\n\n");

        controller_ListEmployee(employeesList);
        cantidadDeEmpleados = ll_len(employeesList);
        printf("\n\n");
        if(!getValidInt("Ingrese ID del empleado a modificar: ", "Debe ser un ID valido, vuelva a ingresar: ", &idABuscar, 1, cantidadDeEmpleados, 3)){

            for(int i = 0; i < cantidadDeEmpleados; i++){

                auxEmployee = (Employee*) ll_get(employeesList, i);
                employee_getId(auxEmployee, &auxId);
                if(auxEmployee != NULL){

                    if(idABuscar == auxId){

                        do{

                            eleccionMenuModify = menuDeOpciones(1);
                            switch(eleccionMenuModify){

                                case 1:

                                    getValidString("Ingrese nuevo nombre: ", "Solo puede ingresar letras, vuelva a intentar: ", "No puede ingresar mas de 50 caracteres, vuelva a intentar: ", nuevoNombre, 50, 5);
                                    flagNombre = 1;
                                    break;

                                case 2:

                                    getValidInt("Ingrese nuevas horas trabajadas: ", "Solo puede ingresar numeros enteros entre 1 y 1000, vuelva a intentar: ", &nuevasHorasTrabajadas, 1, 1000, 5);
                                    flagHorasTrabajadas = 1;
                                    break;

                                case 3:

                                    getValidInt("Ingrese nuevo sueldo: ", "Solo puede ingresar numeros enteros entre 1 y 100000, vuelva a intentar: ", &nuevoSueldo, 1, 100000, 5);
                                    flagSueldo = 1;
                                    break;

                            }
                            printf("Desea realizar otra modificacion sobre el mismo empleado? 'Y' para aceptar.\n");
                            fflush(stdin);
                            otraModif = toupper(getchar());

                        }while(otraModif == 'Y');

                    }
                    else{

                        continue;

                    }
                    printf("Confirma las modificaciones realizadas? 'Y' para aceptar.\n");
                    fflush(stdin);
                    confirmaModif = toupper(getchar());
                    if(confirmaModif == 'Y'){

                        if(flagNombre){

                            employee_setNombre(auxEmployee, nuevoNombre);

                        }
                        if(flagHorasTrabajadas){

                            employee_setHorasTrabajadas(auxEmployee, nuevasHorasTrabajadas);

                        }
                        if(flagSueldo){

                            employee_setSueldo(auxEmployee, nuevoSueldo);

                        }
                        error = 0;

                    }
                    else{

                        error = 2;

                    }

                }
                break;
            }

        }

    }
    return error;

}


int employee_removeEmployee(LinkedList* employeesList){

    int error = 1;
    Employee* auxEmployee;
    int cantidadDeEmpleados;
    int idABuscar;
    int auxId;
    char confirmation;

    if(employeesList != NULL){

        printf("\n *** BAJA EMPLEADO ***\n\n");

        controller_ListEmployee(employeesList);
        cantidadDeEmpleados = ll_len(employeesList);
        printf("\n\n");
        getValidInt("Ingrese ID del empleado a dar de baja: ", "Debe ser un ID valido, vuelva a ingresar: ", &idABuscar, 1, cantidadDeEmpleados, 3);
        for(int i = 0; i < cantidadDeEmpleados; i++){

            auxEmployee = (Employee*) ll_get(employeesList, i);
            employee_getId(auxEmployee, &auxId);
            if(auxEmployee != NULL){

                if(idABuscar == auxId){

                    printf("Desea eliminar al empleado con ID %d? 'Y' para confirmar.\n", auxId);
                    fflush(stdin);
                    confirmation = toupper(getchar());
                    if(confirmation == 'Y'){

                        ll_remove(employeesList, i);
                        free(auxEmployee);
                        break;

                    }

                }
                else{

                    continue;

                }

            }

        }
        error = 0;

    }

    return error;

}
