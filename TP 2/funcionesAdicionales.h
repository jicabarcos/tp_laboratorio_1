#ifndef FUNCIONESADICIONALES_H_INCLUDED
#define FUNCIONESADICIONALES_H_INCLUDED
#include "ArrayEmployees.h"


#endif // FUNCIONESADICIONALES_H_INCLUDED

int showMenu(int menuType);

int findEmpty(Employee employeesList[], int len);

void printOneEmployee(Employee employeesList);

int modifyEmployee(Employee employeesList[], int len);

int salariesSum(Employee employeesList[], int len);

int employeesQuantity(Employee employeesList[], int len);

int employeesAboveProm(Employee employeesList[], int len, float prom);

int sortByLastNameAndSector(Employee employeesList[], int len, int lastNameOrder, int sectorOrder);

void howToSort(Employee employeesList[], int tam, int sortKind);
