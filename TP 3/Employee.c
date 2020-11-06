#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

Employee* employee_new(){

    Employee* newEmployee = NULL;

    newEmployee = (Employee*) malloc(sizeof(Employee));

    if(newEmployee != NULL){

        newEmployee->id = 0;
        strcpy(newEmployee->nombre, " ");
        newEmployee->horasTrabajadas = ' ';
        newEmployee->sueldo = 0;

    }

    return newEmployee;

}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr){

    Employee* newEmployee = employee_new();
    int id;
    int horasTrabajadas;
    float sueldo;

    if(newEmployee != NULL){

    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atof(sueldoStr);

    if(employee_setId(newEmployee, id) &&
       employee_setNombre(newEmployee, nombreStr) &&
       employee_setHorasTrabajadas(newEmployee, horasTrabajadas) &&
       employee_setSueldo(newEmployee, sueldo)){

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

int employee_setSueldo(Employee* this, float sueldo){

    int error = 1;

    if(this != NULL && sueldo > 0){

        this->sueldo = sueldo;
        error = 0;

    }

    return error;

}

int employee_getSueldo(Employee* this, float* sueldo){

    int error = 1;

    if(this != NULL && sueldo != NULL){

        *sueldo = this->sueldo;
        error = 0;

    }

    return error;

}

int employeeSortByName(void* empleadoA, void* empleadoB){

    int retorno = 0;
    char nombreA[20];
    char nombreB[20];


    if((empleadoA != NULL) && (empleadoB != NULL)){

        employee_getNombre((Employee*) empleadoA, nombreA);
        employee_getNombre((Employee*) empleadoB, nombreB);

        retorno = strcmp(nombreA, nombreB);

    }

    return retorno;

}

int employeeSortById(void* empleadoA, void* empleadoB){

    int retorno = 0;
    int idA;
    int idB;


    if((empleadoA != NULL) && (empleadoB != NULL)){

        employee_getId((Employee*) empleadoA, &idA);
        employee_getId((Employee*) empleadoB, &idB);

        retorno = idA - idB;

    }

    return retorno;

}

int employeeSortByWorkHours(void* empleadoA, void* empleadoB){

    int retorno = 0;
    int horasA;
    int horasB;


    if((empleadoA != NULL) && (empleadoB != NULL)){

        employee_getHorasTrabajadas((Employee*) empleadoA, &horasA);
        employee_getHorasTrabajadas((Employee*) empleadoB, &horasB);

        retorno = horasA - horasB;

    }

    return retorno;

}

int employeeSortBySalary(void* empleadoA, void* empleadoB){

    int retorno = 0;
    int sueldoA;
    int sueldoB;


    if((empleadoA != NULL) && (empleadoB != NULL)){

        employee_getSueldo((Employee*) empleadoA, &sueldoA);
        employee_getSueldo((Employee*) empleadoB, &sueldoB);

        retorno = sueldoA - sueldoB;

    }

    return retorno;

}

