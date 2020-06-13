#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "gets.h"
#include "controller.h"
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee) // LEE EL ARCHIVO DE TEXTO , LO GUARDA EN EL LINLEDLIST Y LO MUESTRA
{
    FILE* Archivo;
    Employee* myEmployee;
    myEmployee = (Employee*)malloc(sizeof(Employee)*1100);
    if(myEmployee != NULL)
    {
        Archivo = fopen(path, "r");
        if(Archivo != NULL)
        {
            parser_EmployeeFromText(Archivo,pArrayListEmployee);
        }
        fclose(Archivo); // destruir la lista cada vez q vamos a cargar otra
    }
    printf("\n");
    printf("DATOS DEL DATA.CSV CARGADOS CON EXITO\n");

    return 1;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* ArchivoBinario;
    ArchivoBinario = fopen(path, "rb");
    if(ArchivoBinario != NULL)
    {
        parser_EmployeeFromBinary(ArchivoBinario,pArrayListEmployee);
        fclose(ArchivoBinario);
        printf("\n");
        printf("DATOS DEL DATA.BIN CARGADOS CON EXITO\n");
    }
    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* myEmployee;
    Employee* aux;
    int index;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[51];
    myEmployee = employee_new();
    id = generarIDempleado(pArrayListEmployee);
    employee_setId(myEmployee,id);
    getString("Ingrese el nombre:\n ",nombre);
    employee_setNombre(myEmployee,nombre);
    horasTrabajadas = getInt("Ingrese cantidad de horas trabajadas:\n","Error, reingrese",1,72);
    employee_setHorasTrabajadas(myEmployee,horasTrabajadas);
    sueldo = getInt("Ingrese sueldo:\n","Error, reingrese",1,100000);
    employee_setSueldo(myEmployee,sueldo);
    ll_add(pArrayListEmployee,myEmployee);
    index = ll_indexOf(pArrayListEmployee,myEmployee);
    aux = (Employee*)ll_get(pArrayListEmployee,index);
    printf("SE HA AGREGADO AL EMPLEADO CON EXITO\n");
    printf("\n");
    employee_getId(aux,&id);
    employee_getNombre(aux,nombre);
    employee_getHorasTrabajadas(aux,&horasTrabajadas);
    employee_getSueldo(aux,&sueldo);
    printf("       ID          NOMBRE     HORAS TRABAJADAS     SUELDO\n");
    printf("---------------------------------------------------------\n");
    printf("%8d %15s \t%8d \t%8d\n",id ,nombre ,horasTrabajadas ,sueldo);
    return 1;
}
int generarIDempleado(LinkedList* pArrayListEmployee)
{
    int i;
    int max;
    int len = ll_len(pArrayListEmployee);
    Employee* myEmployee;
    for(i = 0; i < len;i++)
    {
        myEmployee = employee_new();
        myEmployee = (Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(myEmployee, &max);
    }
    return max + 1;
}
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int aux;
    int opcion;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[51];
    Employee* myEmployee;
    aux = getInt("Ingrese el ID a modificar:\n","Error,ingrese un ID valido(ID de duenios comienza en N°1)",1,100000);
    myEmployee = (Employee*)ll_get(pArrayListEmployee,aux-1);
    opcion = getInt("Ingrese el campo a modificar: \n1. ID\n2. Nombre\n3. Horas trabajadas\n4. Sueldo\n","Error, ingrese una opcion valida.\n",1,4);
    switch(opcion)
    {
        case 1:
            id = getInt("Ingrese el ID:","Error, ID invalido",1,10000);
            employee_setId(myEmployee,id);
        break;
        case 2:
            getString("Ingrese el nombre: ",nombre);
            employee_setNombre(myEmployee,nombre);
        break;
        case 3:
            horasTrabajadas = getInt("Ingrese la cantidad de horas trabajadas:","Error, reingrese",1,100);
            employee_setHorasTrabajadas(myEmployee,horasTrabajadas);
        break;
        case 4:
            sueldo = getInt("Ingrese el sueldo: ","Error, reingrese un sueldo valido( 1 - 100000)",1,100000);
            employee_setSueldo(myEmployee,sueldo);
        break;
        default:
        break;
    }
    ll_set(pArrayListEmployee,aux-1,myEmployee);
    printf("SE HA MODIFICADO EL EMPLEADO CORRECTAMENTE\n");
    printf("\n");
    printf("      ID        NOMBRE     HORAS TRABAJADAS     SUELDO\n");
    printf("------------------------------------------------------\n");
    employee_getId(myEmployee,&id);
    employee_getNombre(myEmployee,nombre);
    employee_getHorasTrabajadas(myEmployee,&horasTrabajadas);
    employee_getSueldo(myEmployee,&sueldo);
    printf("%8d %15s \t%8d \t%8d\n", id , nombre, horasTrabajadas, sueldo);

    return 1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int aux;
    aux = getInt("Ingrese el ID a eliminar:\n","Error,ingrese un ID valido(ID de duenios comienza en N°1)",1,100000);
    ll_remove(pArrayListEmployee,aux-1);
    printf("\n");
    printf("SE HA ELIMINADO EL EMPLEADO SELECCIONADO\n");
    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[51];
    Employee* aux;
    int len;
    len = ll_len(pArrayListEmployee);
    printf("LISTA DE EMPLEADOS\n");
    printf("\n");

    for(i = 0; i < len; i++)
    {
        aux = employee_new();
        aux = (Employee*)ll_get(pArrayListEmployee,i);
        if(i % 100 == 0 )
        {
            system("pause");
        }
        employee_getId(aux,&id);
        employee_getNombre(aux,nombre);
        employee_getHorasTrabajadas(aux,&horasTrabajadas);
        employee_getSueldo(aux,&sueldo);
        printf("%8d %15s \t%8d \t%8d\n", id, nombre ,horasTrabajadas ,sueldo);
    }
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee, int order)
{
    Employee* myEmployee;
    int i;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[51];
    int len;
    len = ll_len(pArrayListEmployee);
    printf("MENU DE ORDENAMIENTO\n");
    printf("\n");
    switch(order)
    {
        case 1:
            ll_sort(pArrayListEmployee,employee_CompareById,1);
        break;
        case 2:
            ll_sort(pArrayListEmployee,employee_CompareById,0);
        break;
        case 3:
            ll_sort(pArrayListEmployee,employee_CompareByName,1);
        break;
        case 4:
            ll_sort(pArrayListEmployee,employee_CompareByName,0);
        break;
        default:
        break;
    }
    printf("Cargando...\n");
    for(i = 0 ; i < len; i++)
    {
        myEmployee = (Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(myEmployee,&id);
        employee_getNombre(myEmployee,nombre);
        employee_getHorasTrabajadas(myEmployee,&horasTrabajadas);
        employee_getSueldo(myEmployee,&sueldo);
        if(i % 100 == 0 )
        {
            system("pause");
        }
        printf("%8d %15s \t%8d \t%8d\n",id,nombre,horasTrabajadas,sueldo);
    }
    printf("\n");
    printf("EMPLEADOS ORDENADOS\n");

    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* Archivo;
    int len;
    int i = 0;
    int id, horasTrabajadas, sueldo;
    char nombre[51];
    len = ll_len(pArrayListEmployee);
    Employee* aux = (Employee*) malloc(sizeof(Employee)*len);
    Archivo = fopen(path,"w");
    if(Archivo != NULL && pArrayListEmployee != NULL)
    {
        fprintf(Archivo,"%d, %s, %d, %d\n",id,nombre,horasTrabajadas,sueldo);
        for(i = 0; i < len; i++)
        {
            aux = (Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(aux,&id);
            employee_getNombre(aux,nombre);
            employee_getHorasTrabajadas(aux,&horasTrabajadas);
            employee_getSueldo(aux,&sueldo);
            fprintf(Archivo,"%d,%s,%d,%d\n",id ,nombre ,horasTrabajadas ,sueldo);
        }
    }
    fclose(Archivo);

    for(i = 0; i < len; i++)
    {
        if(i % 200 == 0)
        {
            system("pause");
            printf("       ID          NOMBRE     HORAS TRABAJADAS     SUELDO\n");
            printf("---------------------------------------------------------\n");
        }
        aux = (Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(aux,&id);
        employee_getNombre(aux,nombre);
        employee_getHorasTrabajadas(aux,&horasTrabajadas);
        employee_getSueldo(aux,&sueldo);
        printf("%8d %15s \t%8d \t%8d\n",id,nombre,horasTrabajadas,sueldo);
    }
    printf("\n");
    printf("NUEVAS MODIFICACIONES DE EMPLEADOS CARGADOS CON EXITO EN DATA.CSV\n");
    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* ArchivoBinario; //entonces asi en crudo, no? si entra de nuevo limpio la linked list y listo?
    int i = 0;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[51];
    int len;
    Employee* aux;
    len = ll_len(pArrayListEmployee);
    ArchivoBinario = fopen(path,"wb");
    if(ArchivoBinario != NULL && pArrayListEmployee != NULL)
    {
        for(i=0; i<len; i++)
        {
            aux = employee_new();
            aux = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(aux, sizeof(Employee),1,ArchivoBinario);
            if(i %200 == 0)
                {
                    system("pause");
                    printf("       ID          NOMBRE     HORAS TRABAJADAS     SUELDO\n");
                    printf("---------------------------------------------------------\n");
                }
            employee_getId(aux,&id);
            employee_getNombre(aux,nombre);
            employee_getHorasTrabajadas(aux,&horasTrabajadas);
            employee_getSueldo(aux,&sueldo);
            printf("%8d %15s \t%8d \t%8d\n",id,nombre,horasTrabajadas,sueldo);
        }
        fclose(ArchivoBinario);
        printf("NUEVAS MODIFICACIONES DE EMPLEADOS CARGADOS CON EXITO EN DATA.BIN\n");
    }
    return 1;
}


