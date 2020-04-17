#include <stdio.h>
#include <stdlib.h>
#include "FuncionesCalculadora.h"
#include "FuncionesCalculadora.c"

int main()
{
    int opcion;
    float numA = 0; // primer numero ingresado por el usuario;
    float numB = 0; // segundo numero ingresado por el usuario;
    float resultadoSuma; // se guarda el resultado de la suma;
    float resultadoResta; // se guarda el resultado de la resta;
    float resultadoMultiplicacion; // se guarda el resultado de la multiplicacion;
    float resultadoDivision; // se guarda el resultado de la division;
    long int resultadoFactorialA; // se guarda el resultado del primer factorial ingresado
    long int resultadoFactorialB; // se guarda el resultado del segundo factorial ingresado;

    do // inicio while
    {
        menuOpciones(numA, numB);
        scanf("%d", &opcion);
        switch(opcion) // opciones que puede elejir el usuario(entre 1 y 5)
        {
            case 1:
                printf("1. Ingrese el primer operando : A\n");
                scanf("%f", &numA);
                printf("El primer numero es %.2f\n", numA);
            break;// fin ingreso primer numero
            case 2:
                printf("1. Ingrese el segundo operando : B\n");
                scanf("%f", &numB);
                printf("El segundo numero es %.2f\n", numB);
            break;// fin ingreso segundo numero
            case 3:
                resultadoSuma = getSuma(numA,numB);
                resultadoResta = getResta(numA,numB);
                resultadoMultiplicacion = getMultiplicacion(numA,numB);
                resultadoDivision = getDivision(numA, numB);
                resultadoFactorialA = getFactorialA(numA);
                resultadoFactorialB = getFactorialB(numB);
                printf("Las operaciones se han realizado con exito\n");
            break;//fin operacipnes
            case 4:
                printf("El resultado de %.2f + %.2f es: %.2f\n", numA, numB, resultadoSuma);
                printf("El resultado de %.2f - %.2f es: %.2f\n", numA, numB, resultadoResta);
                printf("El resultado de %.2f * %.2f es: %.2f\n", numA, numB, resultadoMultiplicacion);
                mostrarDivision(numA, numB, resultadoDivision);
                mostrarFactorialA(numA, resultadoFactorialA);
                mostrarFactorialA(numB, resultadoFactorialB);
            default: // fin mostrar operaciones
                validarOpcion(opcion);
            break;
        }
        system("pause");
        system("cls");
    }while(opcion != 5);// fin del while
    return 0;
}




