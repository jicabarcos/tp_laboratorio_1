#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_textFromEmployee(FILE* pFile, LinkedList* pArrayListEmployee);
int parser_binaryFromEmployee(FILE* pFile, LinkedList* pArrayListEmployee);
