#ifndef FUNCIONESADICIONALES_H_INCLUDED
#define FUNCIONESADICIONALES_H_INCLUDED
#include "ArrayEmployees.h"


#endif // FUNCIONESADICIONALES_H_INCLUDED


/** \brief muestra distintos menues de opciones
 *
 * \param menuType int indica cual de los menues usara
 * \return int menuOption eleccion del usuario
 *
 */
int showMenu(int menuType);


/** \brief recorre array en busca de espacios libres
 *
 * \param employeesList Employee array de empleados
 * \param len int largo del array
 * \return int index devuelve (-1) si falla o el numero que
 * corresponda a la posicion en el array si hay exito
 *
 */
int findEmpty(Employee employeesList[], int len);


/** \brief imprime un empleado de la lista
 *
 * \param employeesList Employee array de empleados
 * \return void
 *
 */
void printOneEmployee(Employee employeesList);


/** \brief modifica un empleado que el usuario elegira
 * por id
 *
 * \param employeesList Employee array de empleados
 * \param len int largo del array
 * \return int error devuelve (1) si falla, (0) si hay exito
 * o (2) si el usuario cancela la modificacion
 *
 */
int modifyEmployee(Employee employeesList[], int len);


/** \brief recorre el array y suma los salarios de los empleados
 *
 * \param employeesList Employee array de empleados
 * \param len int largo del array
 * \return int sum suma de salarios
 *
 */
int salariesSum(Employee employeesList[], int len);


/** \brief recorre el array y cuenta los empleados
 *
 * \param employeesList Employee array de empleados
 * \param len int largo del array
 * \return int quantity cantidad de empleados
 *
 */
int employeesQuantity(Employee employeesList[], int len);


/** \brief recorre el array y busca empleados que superen
 * el salario promedio
 * \param employeesList Employee array de empleados
 * \param len int largo del array
 * \param prom float salario promedio
 * \return topPaid int cantidad de empleados que superan el sueldo promedio
 *
 */
int employeesAboveProm(Employee employeesList[], int len, float prom);


/** \brief ordena el array por sector y nombre
 *
 * \param employeesList Employee array de empleados
 * \param len int largo del array
 * \param lastNameOrder int elije ascendente o descendente
 * \param sectorOrder int elije ascendente o descendente
 * \return int error devuelve (1) si hay error o (0) si es exitoso
 *
 */
int sortByLastNameAndSector(Employee employeesList[], int len, int lastNameOrder, int sectorOrder);


/** \brief da la opcion de ordenar con distintos criterios
 *
 * \param employeesList Employee array de empleados
 * \param len int largo del array
 * \param sortKind todas las variantes de ascendente y descendente
 * \return void
 *
 */
void howToSort(Employee employeesList[], int tam, int sortKind);
