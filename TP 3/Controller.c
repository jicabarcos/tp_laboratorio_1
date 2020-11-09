#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

    int error = 1;
    FILE* f = fopen(path, "r");

    if(f != NULL && pArrayListEmployee != NULL){

        if(!(parser_EmployeeFromText(f, pArrayListEmployee))){

            error = 0;

        }

    }
    fclose(f);

    return error;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

    int error = 1;

    FILE* f = fopen(path, "rb");
    if(f != NULL && pArrayListEmployee != NULL){

        if(!(parser_EmployeeFromBinary(f, pArrayListEmployee))){

            error = 0;

        }

    }
    fclose(f);

    return error;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    int error = 1;

    if(pArrayListEmployee != NULL){

        if(!employee_addNewEmployee(pArrayListEmployee)){

            error = 0;

        }

    }

    return error;

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    int error = 1;

    if(pArrayListEmployee != NULL){

        employee_removeEmployee(pArrayListEmployee);
        error = 0;

    }

    return error;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee = employee_new();

    if(pArrayListEmployee != NULL && auxEmployee != NULL){

        employee_listOneEmployee(pArrayListEmployee);

    }

    return 1;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int error = 1;
    int eleccionMenu;

    if(pArrayListEmployee != NULL){

        eleccionMenu = menuDeOpciones(2);
        switch(eleccionMenu){

            case 1:

                ll_sort(pArrayListEmployee, employeeSortById, 1);
                error = 0;
                break;

            case 2:

                ll_sort(pArrayListEmployee, employeeSortById, 0);
                error = 0;
                break;

            case 3:

                ll_sort(pArrayListEmployee, employeeSortByName, 1);
                error = 0;
                break;

            case 4:

                ll_sort(pArrayListEmployee, employeeSortByName, 0);
                error = 0;
                break;

            case 5:

                ll_sort(pArrayListEmployee, employeeSortByHorasTrabajadas, 1);
                error = 0;
                break;

            case 6:

                ll_sort(pArrayListEmployee, employeeSortByHorasTrabajadas, 0);
                error = 0;
                break;

            case 7:

                ll_sort(pArrayListEmployee, employeeSortBySueldo, 1);
                error = 0;
                break;

            case 8:

                ll_sort(pArrayListEmployee, employeeSortBySueldo, 0);
                error = 0;
                break;


        }

    }

    return error;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    int error = 1;
    FILE* f = fopen(path, "w");

    if(f != NULL && pArrayListEmployee != NULL){

        if(!(parser_textFromEmployee(f, pArrayListEmployee))){

            error = 0;

        }

    }
    fclose(f);

    return error;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

    int error = 1;
    FILE* f = fopen(path, "wb");

    if(f != NULL && pArrayListEmployee != NULL){

        if(!(parser_binaryFromEmployee(f, pArrayListEmployee))){

            error = 0;

        }

    }
    fclose(f);

    return error;

}

int controller_modifyEmployee(LinkedList* pArrayListEmployee){

    int error = 1;

    if(pArrayListEmployee != NULL){

        if(employee_modifyEmployee(pArrayListEmployee) == 0){

            error = 0;

        }
        else if(employee_modifyEmployee(pArrayListEmployee) == 2){

            error = 2;

        }

    }

    return error;

}
