#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

// EL USUARIO ELIJE QUE HACER
int mostrarMenu()
{

    int opcionMenu;

    printf("> 1) Ingrese 1er operando.\n\n");

    printf("> 2) Ingrese 2do operando.\n\n");

    printf("> 3) Calcular operaciones.\n\n");

    printf("> 4) Mostrar resultados.\n\n");

    printf("> 5) Resetear / Salir.\n\n");

    printf("Elija la opcion deseada: ");
    scanf("%d", &opcionMenu);
    printf("\n");

    return opcionMenu;

}

// CAPTURO LOS DOS VALORES CON LOS QUE EL USUARIO QUIERE OPERAR
int ingresoOperandos(int operando, int opcionMenu)
{

    if (opcionMenu == 1)
    {

        printf("Ingrese 1er operando: ");
        scanf("%d", &operando);
        printf("\n");

    }
    else if (opcionMenu == 2)
    {

        printf("Ingrese 2do operando: ");
        scanf("%d", &operando);
        printf("\n");

    }

    return operando;

}

// MUESTRO LOS RESULTADOS DE LOS CALCULOS CORRESPONDIENTES
void mostrarResultados(int resultadoSuma, int resultadoDiferencia, float resultadoDivision, int resultadoMultiplicacion, int resultadoPrimerFactorial, int resultadoSegundoFactorial)
{

    printf("> a) El resultado de A + B es: %d\n\n", resultadoSuma);

    printf("> b) El resultado de A - B es: %d\n\n", resultadoDiferencia);

    if (!resultadoDivision)
    {

        printf("> c) No es posible dividr por cero.\n\n");

    }
    else
    {

        printf("> c) El resultado de A / B es: %.2f\n\n", resultadoDivision);

    }

    printf("> d) El resultado de A * B es: %d\n\n", resultadoMultiplicacion);

    printf("> e) El factorial de A es %d y el de B es %d\n\n", resultadoPrimerFactorial, resultadoSegundoFactorial);

}

// CALCULO SUMA
int sumar(int num1, int num2)
{

    int suma;

    suma = num1 + num2;

    return suma;

}

// CALCULO RESTA
int restar(int num1, int num2)
{

    int resta;

    resta = num1 - num2;

    return resta;

}

// CALCULO DIVISION
float dividir(int num1, int num2)
{

    float cociente;

    // VALIDO DIVISION POR CERO
    if (!num2)
    {

        cociente = 0;

    }
    else
    {

        cociente = (float) num1 / num2;

    }

    return cociente;

}

// CALCULO MULTIPLICACION
int multiplicar(int num1, int num2)
{

    int producto;

    producto = num1 * num2;

    return producto;

}

// CALCULO FACTORIAL
long long int factorial(int num)
{

    int i;
    int factorial = 1;

    // VALIDO SI SE PUEDE HACER FACTORIAL
    if (num < 0)
    {

        printf("Tiene que ser mayor o igual a 0.");

    }
    else if (!num)
    {

        factorial = 1;

    }
    else
    {

        for(i = 1; i <= num; i++)
        {

            factorial *= i;

        }

    }

    return factorial;

}
