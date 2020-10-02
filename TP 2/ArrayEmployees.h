#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED


int initEmployees(Employee employeesList[], int len);

int addEmployee(Employee employeesList[], int len, int id);

int findEmployeeById(Employee employeesList[], int len, int id);

int removeEmployee(Employee employeesList[], int len);

int printEmployees(Employee employeesList[], int len);
