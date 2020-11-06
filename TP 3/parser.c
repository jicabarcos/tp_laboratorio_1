#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int error = 1;
    int r;
    Employee* auxEmployee;
    char idStr[20];
    char nombreStr[20];
    char horasTrabajadasStr[20];
    char sueldoStr[20];
    int horasInt;

    if(idStr != NULL && nombreStr != NULL, horasTrabajadasStr != NULL &&
       sueldoStr != NULL && pFile != NULL){

        while(!feof(pFile)){

            r = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            if(r == 4){

                auxEmployee = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);

                if(auxEmployee != NULL){

                    ll_add(pArrayListEmployee, auxEmployee);

                }

            }

        }

    }

    horasInt = atoi(horasTrabajadasStr);

    employee_getHorasTrabajadas(auxEmployee, horasInt);
    printf("%d\n", horasInt);


    //printf("%d, %s, %d, %.2f", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);


    fclose(pFile);


    return error;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
