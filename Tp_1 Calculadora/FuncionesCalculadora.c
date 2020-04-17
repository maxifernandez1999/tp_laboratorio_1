#include <stdio.h>
#include "FuncionesCalculadora.h"
float getSuma(float num1, float num2)
{
    float resultadoSumar;
    resultadoSumar = num1 + num2;
    return resultadoSumar;
}

float getResta(float num1, float num2)
{
    float resultadoRestar;
    resultadoRestar = num1 - num2;
    return resultadoRestar;
}

float getMultiplicacion(float num1, float num2)
{
    float resultadoMultiplicar;
    resultadoMultiplicar = num1 * num2;
    return resultadoMultiplicar;
}

float getDivision(float num1, float num2)
{
    float resultadoDividir;
    resultadoDividir = num1 / num2;
    return resultadoDividir;
}
int getFactorialA(int i)
{
    int factorialA = 1;
    for(; i > 1 ; i--)
    {
        factorialA *= i;
    }
    return factorialA;
}
int getFactorialB(int j)
{
    int factorialB = 1;
    for(; j > 1 ; j--)
    {
        factorialB *= j;
    }
    return factorialB;
}
void menuOpciones(float num1, float num2)
{
        printf("###CALCULADORA UTN###\n");
        printf("1. Ingrese primer operando : A = %.2f\n", num1);
        printf("2. Ingrese segundo operando: B = %.2f\n", num2);
        printf("3. Calcular todas las operaciones\n");
        printf("\ta) Calcular la suma (A + B)\n");
        printf("\tb) Calcular la resta (A - B)\n");
        printf("\tc) Calcular la multiplicacion (A * B)\n");
        printf("\td) Calcular la division (A / B)\n");
        printf("\te) Calcular el factorial (A!)\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
        printf("Elija una opcion\n");

}
void mostrarDivision(float num1, float num2, float resultado)
{
    if(num2 == 0)
    {
        printf("Error, no se puede dividir por 0\n");
    }else
    {
        printf("El resultado de %.2f / %.2f es: %.2f\n", num1, num2, resultado);
    }
}

void mostrarFactorialA(float num1, long int resultadoFacA)
{
    if(num1 < 0 || num1 - (int)num1)
    {
        printf("Error, no se puede factorizar el %.2f porque es un numero negativo o es decimal\n", num1);

    }else
    {
        printf("El factorial de %.2f es: %li\n", num1, resultadoFacA);
    }
}
void mostrarFactorialB(float num2, long int resultadoFacB)
{
    if(num2 < 0 || num2 - (int)num2)
    {
        printf("Error, no se puede factorizar el %.2f porque es un numero negativo o es decimal\n", num2);

    }else
    {
        printf("El factorial de %.2f es: %li\n", num2, resultadoFacB);
    }
}
void validarOpcion(int op)
{
    if(op > 5 || op < 1)
    {
        printf("Error, reingrese una opcion valida\n");
    }
}

