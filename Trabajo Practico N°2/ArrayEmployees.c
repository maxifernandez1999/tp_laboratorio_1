#include "ArrayEmployees.h"
#define EMPLY 0
#define FULL 1
#include "input.h"
#include <stdio.h>
#include <string.h>


void initEmployees(eEmployee list[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        list[i].isEmply = EMPLY;
    }
}
int findFree(eEmployee list[], int size)
{
    int i;
    int index = -1;

    for(i = 0; i < size; i++)
    {
        if(list[i].isEmply == EMPLY)
        {
            index =  i;
            break;
        }
    }
    return index;

}
int LoadEmployee(eEmployee list[], int size, int counter)
{
  int index;
  int retorno = 0;

  index = findFree(list, size);

  if(index!=-1)
  {
      list[index] = createEmployee(counter);
      retorno = 1;
  }
  return retorno;
}
eEmployee createEmployee(int counter)
{
    eEmployee myEmployee;

    myEmployee.id = getId(counter);
    getString("Enter name: ", myEmployee.name);
    getString("Enter last name: ", myEmployee.lastName);
    myEmployee.salary = getFloat("Enter salary: ","Enter a valid salary",100,10000);
    myEmployee.sector = getInt("Enter sector: ","Enter a valid sector", 1, 10);
    myEmployee.isEmply = FULL;

    return myEmployee;
}
void printEmployees(eEmployee list[], int size)
{
    int i;
    printf("------ ID --------- NAME ------ LASTNAME ------- SALARY ---- SECTOR\n");
    printf("-------------------------------------------------------------------\n");
    for(i = 0; i < size; i++)
    {
        if(list[i].isEmply == FULL)
        {
            printEmployee(list[i]);
        }
    }
    printf("____________________________________________________________________\n");
}
void printEmployee(eEmployee myEmployee)
{
    printf("%8d %15s %15s \t%.2f %8d\n",myEmployee.id,
                                        myEmployee.name,
                                        myEmployee.lastName,
                                        myEmployee.salary,
                                        myEmployee.sector);

}
int modifyEmployee(eEmployee list[], int size)
{
    int id;
    int i;
    int option;
    int returnValue;

    printf("Enter ID to modify: ");
    scanf("%d", &id);
    for(i = 0; i < size ; i++)
    {
        if(list[i].isEmply == FULL && id == list[i].id)
        {
            printf("select the option to modify:\n 1. Name/n 2. LastName/n 3. Salary/n 4. sector\n");
            scanf("%d", &option);
            switch(option)
            {
                case 1:
                    getString("Enter the new name: ", list[i].name);
                break;
                case 2:
                    getString("Enter the new last name: ", list[i].name);
                break;
                case 3:
                    getFloat("Enter the new salary: ","Enter a valid salary ($100 - $10000) ",99,10001);
                break;
                case 4:
                    getInt("Enter the new SECTOR: ","Enter a valid sector (1 - 10) ",1,10);
                break;
                default:
                break;
            }
            returnValue = 0;
            break;
        }else
        {
            returnValue = -1;
        }

    }

    return returnValue;
}
int removeEmployee(eEmployee list[], int size)
{
    int id;
    int i;
    int returnValue = -1;
    char confirmation;
    printf("Enter ID to remove: ");
    scanf("%d", &id);
    for(i = 0; i < size; i++)
    {
        if(list[i].isEmply == FULL && id == list[i].id)
        {
            confirmation = getCharacter("Continue? Enter (y/n)","Error, re-enter a valid option (y/n)", 'a', 'z');
            if(confirmation == 'y')
            {
                list[i].isEmply = EMPLY;
                returnValue = 0;
            }else
            {
                returnValue = 1;
            }
            break;
        }
    }
    return returnValue;
}
void sortEmployees(eEmployee list[], int size, int order)
{
    int i;
    int j;
    eEmployee AuxEmployee;
    switch(order)
    {
        case 1:
            for(i = 0; i < size-1; i++)
            {
                for(j = i+1 ; j < size; j++)
                {
                    if(strcmp(list[i].lastName, list[j].lastName) > 0)
                    {
                        AuxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = AuxEmployee;
                    }else
                    {
                        if(strcmp(list[i].lastName, list[j].lastName) == 0)
                        {
                            if(list[i].sector > list[j].sector)
                            {
                                AuxEmployee = list[i];
                                list[i] = list[j];
                                list[j] = AuxEmployee;
                            }
                        }
                    }
                }

            }
        break;
        case 2:
            for(i = 0; i < size-1; i++)
            {
                for(j = i+1 ; j < size; j++)
                {
                    if(strcmp(list[i].lastName, list[j].lastName) < 0)
                    {
                        AuxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = AuxEmployee;
                    }else
                    {
                        if(strcmp(list[i].lastName, list[j].lastName) == 0)
                        {
                            if(list[i].sector < list[j].sector)
                            {
                                AuxEmployee = list[i];
                                list[i] = list[j];
                                list[j] = AuxEmployee;
                            }
                        }
                    }
                }

            }
        break;
        default:
        break;
    }
}
float accumulateSalary(eEmployee list[], int size)
{
    int i;
    float accumulator = 0;
    for(i = 0; i < size; i++)
    {
        accumulator = accumulator + list[i].salary;
    }
    return accumulator;
}

float getAverage(eEmployee list[], int size, int counter)
{
    int i;
    float average;
    int contador = 0;
    float acumulador = 0;
    for(i = 0; i < size; i++)
    {
        acumulador = acumulador + list[i].salary;
    }
    for(i = 0; i < counter; i++)
    {
        list[i].salary = contador++;
    }
    average = acumulador / contador;
    return average;

}
int salaryExceedsAverage(eEmployee list[], int size, int counter)
{
    int i;
    float average;
    int contador = 0;
    float max;
    average = getAverage(list,size,counter);
    for(i = 0; i < size; i++)
    {
        if(i == 0 || average > max)
        {
            max = average;
            contador++;
        }
    }
    return contador;




}
