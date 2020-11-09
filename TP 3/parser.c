#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
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

    if(pFile != NULL && pArrayListEmployee != NULL){

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
        do{

            r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            if(r == 4){

                auxEmployee = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
                if(auxEmployee != NULL){

                    ll_add(pArrayListEmployee, auxEmployee);

                }

            }

        }while(!feof(pFile));
        error = 0;

    }


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

    int error = 1;
    int r;
    Employee* auxEmployee;


    if(pFile != NULL && pArrayListEmployee != NULL){

            do{

                auxEmployee = employee_new();
                if(auxEmployee != NULL){

                    r = fread(auxEmployee, sizeof(Employee), 1, pFile);
                    if(r){

                        if(auxEmployee != NULL){

                            ll_add(pArrayListEmployee, auxEmployee);

                        }

                    }

                }

            }while(!feof(pFile));
            error = 0;

    }

    return error;

}

int parser_textFromEmployee(FILE* pFile, LinkedList* pArrayListEmployee){

    int error = 1;
    Employee* auxEmployee;
    int cantidadDeEmpleados;
    int auxId;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pFile != NULL && pArrayListEmployee != NULL){

        cantidadDeEmpleados = ll_len(pArrayListEmployee);
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
        for(int i = 0; i < cantidadDeEmpleados; i++){

            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if(auxEmployee != NULL){

                employee_getId(auxEmployee, &auxId);
                employee_getNombre(auxEmployee, auxNombre);
                employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
                employee_getSueldo(auxEmployee, &auxSueldo);
                fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

            }

        }
        error = 0;

    }
    return error;

}

int parser_binaryFromEmployee(FILE* pFile, LinkedList* pArrayListEmployee){

    int error = 1;
    Employee* auxEmployee;
    int cantidadDeEmpleados;

    if(pFile != NULL && pArrayListEmployee != NULL){

        cantidadDeEmpleados = ll_len(pArrayListEmployee);
        for(int i = 0; i < cantidadDeEmpleados; i++){

            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if(auxEmployee != NULL){

                fwrite(auxEmployee, sizeof(Employee), 1, pFile);

            }

        }
        error = 0;

    }
    return error;

}
