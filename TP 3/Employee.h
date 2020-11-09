#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;

}Employee;

// CONSTRUCTOR AND DESTROYER
Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

// SETTERS AND GETTERS
int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);

int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this, int* sueldo);

// SORT
int employeeSortByName(void* empleadoA, void* empleadoB);
int employeeSortById(void* empleadoA, void* empleadoB);
int employeeSortByHorasTrabajadas(void* empleadoA, void* empleadoB);
int employeeSortBySueldo(void* empleadoA, void* empleadoB);

// EXTRA
void employee_listOneEmployee(LinkedList* employeesList);
int employee_addNewEmployee(LinkedList* employeesList);
int employee_modifyEmployee(LinkedList* employeesList);
int employee_removeEmployee(LinkedList* employeesList);

#endif // employee_H_INCLUDED
