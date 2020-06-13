#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
#include "gets.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* myList;
    int option;
    int flag = 0;
    int order;
    myList = ll_newLinkedList();
    do
    {
        printf("                                MENU                                    \n");
        printf("1. Cargar los datos del empleado desde el archivo data.csv (modo texto) \n");
        printf("2. Cargar los datos del empleado desde el archivo data.csv (modo binario) \n");
        printf("3. Alta de empleado \n");
        printf("4. Modificar datos de empleado \n");
        printf("5. Baja de empleado \n");
        printf("6. Listar empleados \n");
        printf("7. Ordenar empleados \n");
        printf("8. Guardar los datos del empleado desde el archivo data.csv (modo texto) \n");
        printf("9. Guardar los datos del empleado desde el archivo data.csv (modo binario) \n");
        printf("10. Salir \n");
        option = getInt("Ingrese una opcion","Error, ingrese una opcion valida",1,10);
        system("cls");
        switch(option)
        {
            case 1:
                if(flag == 0)
                {
                    controller_loadFromText("data.csv", myList);
                }
                else
                {
                    printf("Ya se ha abierto un archivo\n");
                }
                flag = 1;
            break;
            case 2:
                if(flag == 0)
                {
                    controller_loadFromBinary("data.bin",myList);
                }else
                {
                    printf("Ya se ha abierto un archivo\n");
                }
                flag = 1;
            break;
            case 3:
                controller_addEmployee(myList);
            break;
            case 4:
                controller_editEmployee(myList);
            break;
            case 5:
                controller_removeEmployee(myList);
            break;
            case 6:
                controller_ListEmployee(myList);
            break;
            case 7:
                printf("MENU DE ORDENAMIENTO\n");
                order = getInt("1. Ordenar por ID de menor a mayor\n2. Ordenar por ID de mayor a menor\n3. Ordenar por nombre de a - z\n4. Ordenar por nombre de z - a\n","Error, ingrese una opcion valida",1,4);
                switch(order)
                {
                    case 1:
                        controller_sortEmployee(myList,1);
                    break;
                    case 2:
                        controller_sortEmployee(myList,2);
                    break;
                    case 3:
                        controller_sortEmployee(myList,3);
                    break;
                    case 4:
                        controller_sortEmployee(myList,4 );
                    break;
                    default:
                    break;
                }
            break;
            case 8:
                controller_saveAsText("data.csv",myList);
            break;
            case 9:
                controller_saveAsBinary("data.bin",myList);
            break;
            default:
            break;
        }

    }while(option != 10);
    // EJEMPLO DE COMO USAR LAS FUNCIONES
    /*Employee* e1 = (Employee*) malloc(sizeof(Employee));
    Employee* e2 = (Employee*) malloc(sizeof(Employee));
    Employee* e3 = (Employee*) malloc(sizeof(Employee));

    e1->id = 5;
    e1->horasTrabajadas = 10;
    strcpy(e1->nombre,"Juan");
    e1->sueldo = 10000;

    e2->id = 1;
    e2->horasTrabajadas = 15;
    strcpy(e2->nombre,"Martin");
    e2->sueldo = 15000;

    e3->id = 3;
    e3->horasTrabajadas = 10;
    strcpy(e3->nombre,"Aria");
    e3->sueldo = 20000;

    ll_add(miLista, e1);
    ll_add(miLista, e2);
    ll_add(miLista, e3);



    size = ll_len(miLista);


    ll_sort(miLista,employee_CompareById,0);

    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }

  printf("Remuevo 1\n");

    ll_remove(miLista, 1);

    size = ll_len(miLista);
    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }

    printf("El indice de e2 es: %d\n", ll_indexOf(miLista,e3));
    */



    return 0;
}
