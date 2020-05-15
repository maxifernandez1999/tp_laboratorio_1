#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "input.h"
#define S 1000
#define EMPLY 0
#define FULL 1

int main()
{
    eEmployee listEmployees[S];
    int retorno;
    float salary;
    int option;
    float average;
    int salaryMax;
    int counter = 0;


    initEmployees(listEmployees, S);
    do
    {
        printf("------------------\n");
        printf("#####AMB MENU#####\n");
        printf("------------------\n");
        printf("\n");
        option = getInt("1. Add employee\n2. Modify employee\n3. Remove employee\n4. Print employee\n5. Inform\n6. Exit\n", "Error, re-enter a valid option: ",1,6);
        switch(option)
        {
            case 1:
                counter++;
                printf("Enter the employee data\n");
                retorno = LoadEmployee(listEmployees, S, counter);

                switch(retorno)
                {
                    case 1:
                        printf("------------------\n");
                        printf("Successful entry\n");
                    break;
                    case 0:
                        printf("------------------\n");
                        printf("Space exhausted\n");
                    break;
                    default:
                    break;
                }
            break;
            case 2:
                if(counter > 0)
                {
                    retorno = modifyEmployee(listEmployees, S);
                    switch(retorno)
                    {
                        case 0:
                            printf("------------------\n");
                            printf("Successful modification!!\n");
                        break;
                        case -1:
                            printf("------------------\n");
                            printf("ID not found\n");
                        break;
                        default:
                        break;
                    }
                }else
                {
                    printf("------------------\n");
                    printf("Enter an employee first\n");
                }

            break;
            case 3:
                if(counter > 0)
                {
                    retorno = removeEmployee(listEmployees, S);
                    switch(retorno)
                    {
                        case 0:
                            printf("------------------\n");
                            printf("Successful removal\n");
                        break;
                        case 1:
                            printf("------------------\n");
                            printf("Operation cancelled\n");
                        break;
                        case -1:
                            printf("------------------\n");
                            printf("ID not found\n");
                        break;
                        default:
                        break;
                    }
                }else
                {
                    printf("------------------\n");
                    printf("Enter an employee first\n");
                }
            break;
            case 4:
                if(counter > 0)
                {
                    printEmployees(listEmployees, S);
                }else
                {
                    printf("Enter an employee first\n");
                }
            break;
            case 5:
                if(counter > 0)
                {
                    retorno = getInt("###INFORM MENU###\n1. List employees by last name and sector\n2. Total and average wages and how many employees exceed the average wage\n", "Error, re-enter a valid option",1,2);
                    switch(retorno)
                    {
                        case 1:
                            printf("Select option\n");
                            retorno = getInt("1. Sort employees down\n2. Sort employees ascending\n", "Error, re-enter a valid option",1,2);
                            switch(retorno)
                            {
                                case 1:
                                    sortEmployees(listEmployees, S, 1);
                                    printEmployees(listEmployees, S);
                                break;
                                case 2:
                                    sortEmployees(listEmployees,S,2);
                                    printEmployees(listEmployees, S);
                                default:
                                break;
                            }
                        break;
                        case 2:
                            salary = accumulateSalary(listEmployees,S);
                            printf("The accumulated total of wages is:  %f\n",salary);
                            printf("------------------\n");
                            average = getAverage(listEmployees,S,counter);
                            printf("The average is: %f\n",average);
                            printf("------------------\n");
                            salaryMax = salaryExceedsAverage(listEmployees,S, counter);
                            printf("The number of employees that exceed the average salary is: %d\n", salaryMax);
                            printf("------------------\n");

                        break;
                        default:
                        break;
                    }
                }else
                {
                    printf("------------------\n");
                    printf("Enter an employee first\n");
                }
            break;
            default:
            break;
        }
    }while(option != 6);


    return 0;
}
