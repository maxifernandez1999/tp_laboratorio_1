#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee = (Employee*)calloc(sizeof(Employee),1);
    if(pEmployee == NULL)
    {
        printf("No hay espacio en memoria\n");
        return 0;
    }


    return pEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;
    pEmployee = employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[51];
    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        employee_setId(pEmployee,id);
        employee_setHorasTrabajadas(pEmployee,horasTrabajadas);
        employee_setSueldo(pEmployee,sueldo);
        employee_setNombre(pEmployee,nombre);
    }
    return pEmployee;
}

int employee_setNombre(Employee* Employee,char* nombre)
{
    int ret = 0;
    if(Employee!=NULL && nombre!=NULL)
    {
        strcpy(Employee->nombre , nombre);
        ret = 1;
    }
    return ret;
}

int employee_getNombre(Employee* Employee,char* nombre)
{
    int retorno = 0;
    if(Employee!=NULL)
    {
        strcpy(nombre,Employee->nombre);
        retorno = 1;
    }
    return retorno;
}



int employee_setSueldo(Employee* Employee,int sueldo)
{
    int ret = 0;
    if(Employee!=NULL)
    {
        Employee->sueldo = sueldo;
        ret = 1;
    }

    return ret;
}
int employee_getSueldo(Employee* Employee,int* sueldo)
{
    int retorno = 0;
    if(Employee!=NULL)
    {
        *sueldo = Employee->sueldo;
        retorno = 1;
    }
    return retorno;

}

int employee_setId(Employee* Employee,int id)
{
    int ret = 0;
    if(Employee!=NULL)
    {
        Employee->id = id;
        ret = 1;
    }

    return ret;
}
int employee_getId(Employee* Employee,int* id)
{
    int retorno = 0;
    if(Employee!=NULL)
    {
        *id = Employee->id;
        retorno = 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* Employee,int horasTrabajadas)
{
    int ret = 0;
    if(Employee!=NULL)
    {
        Employee->horasTrabajadas = horasTrabajadas;
        ret = 1;
    }
    return ret;
}
int employee_getHorasTrabajadas(Employee* Employee,int* horasTrabajdas)
{
    int retorno = 0;
    if(Employee!=NULL)
    {
        *horasTrabajdas = Employee->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}


int employee_CompareByName(void* e1, void* e2)
{
    e1 = (Employee*)e1;
    e2 = (Employee*)e2;
    char nombreE1[51];
    char nombreE2[51];
    employee_getNombre(e1,nombreE1);
    employee_getNombre(e2,nombreE2);
    int retorno;
    if(e1 != NULL && e2 != NULL)
    {
        retorno = strcmpi(nombreE1, nombreE2);
    }
    return retorno;
}

int employee_CompareById(void* e1, void* e2)
{
    e1 = (Employee*)e1;
    e2 = (Employee*)e2;
    int idE1;
    int idE2;
    employee_getId(e1,&idE1);
    employee_getId(e2,&idE2);

    int retorno;
    if(e1 != NULL && e2 != NULL)
    {
        if(idE1 > idE2)
        {
            retorno = 1;
        }
        else
        {
            if(idE1 < idE2)
            {
                retorno = -1;
            }
            else
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}


