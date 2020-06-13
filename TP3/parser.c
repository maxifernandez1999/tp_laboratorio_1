#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r;
    Employee* myEmployee;
    char id[51];
    char nombre[51];
    char horasTrabajadas[51];
    char sueldo[51];
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
        do
        {
            r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
            if(r == 4)
            {
                myEmployee = employee_new();
                strcpy(myEmployee->nombre, nombre);
                myEmployee->id = atoi(id);
                myEmployee->horasTrabajadas = atoi(horasTrabajadas);
                myEmployee->sueldo = atoi(sueldo);
                ll_add(pArrayListEmployee,myEmployee);
            }
            else
                break;
        }while(!feof(pFile));
    }
    return 1;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* myEmployee;
    while(!feof(pFile))
    {
        if(feof(pFile))
        {
            break;
        }
        myEmployee = employee_new();
        if(fread(myEmployee,sizeof(Employee),1,pFile)==1)
        {
            ll_add(pArrayListEmployee,myEmployee);
        }
    }
    return 1;
}
