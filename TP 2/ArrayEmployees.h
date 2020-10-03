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


/** \brief indica que todas las posiciones del array estan vacias,
 *
 * deja los campos isEmpty igualados a 1 en todas las posiciones
 * \param employeeList Employee array de empleados
 * \param len int largo del array
 * \return int error devuelve (1) si hay error o (0) si es exitoso
 *
 */
int initEmployees(Employee employeesList[], int len);


/** \brief llena una lista vacia de empleados con los ingresos del usuario,
 *
 * empezando desde la primer posicion libre y pone isEmpty en 0
 * \param employeeList Employee array de empleados
 * \param len int largo del array
 * \param id int numero de identificacion de cada empleado
 * \return int error devuelve (1) si hay error o (0) si es exitoso
 *
 */
int addEmployee(Employee employeesList[], int len, int id);


/** \brief busca a un empleado por id e informa su posicion en el array
 *
 * \param employeeList Employee array de empleados
 * \param len int largo del array
 * \param id int numero de identificacion de cada empleado
 * \return int index devuelve (-1) si falla o el numero que
 * corresponda a la posicion en el array si hay exito
 *
 */
int findEmployeeById(Employee employeesList[], int len, int id);


/** \brief da de baja a un empleado por id y pone isEmpty en 1
 *
 * \param employeeList Employee array de empleados
 * \param len int largo del array
 * \return int error devuelve (1) si falla, (0) si hay exito
 * o (2) si el usuario cancela la baja
 *
 */
int removeEmployee(Employee employeesList[], int len);


/** \brief imprime el contenido del array
 *
 * \param employeeList Employee array de empleados
 * \param len int largo del array
 * \return int error devuelve (1) si falla o (0) si hay exito
 *
 */
int printEmployees(Employee employeesList[], int len);
