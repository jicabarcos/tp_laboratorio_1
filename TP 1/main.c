#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{

    int eleccionMenu;
    int a = 0;
    int b = 0;
    int flagA = 0;
    int flagB = 0;
    int flagEleccionTres = 0;
    int suma;
    int diferencia;
    float cociente;
    int producto;
    int factorialPrimerOperando;
    int factorialSegundoOperando;
    char eleccionCaseCinco;

    do
    {

        // TITULO
        printf("***CALCULADORA***\n\n");
        // ESTADO ACTUAL DE LOS OPERANDOS
        printf("A = %d\n", a);
        printf("B = %d\n\n", b);

        eleccionMenu = mostrarMenu(eleccionMenu);

        switch(eleccionMenu)
        {

            case 1:

                a = ingresoOperandos(a, eleccionMenu);
                flagA = 1;
                system("pause");
                break;

            case 2:

                b = ingresoOperandos(b, eleccionMenu);
                flagB = 1;
                system("pause");
                break;

            case 3:

                // CHECKEO QUE HAYA INGRESADO AMBOS OPERANDOS
                if (flagA  && flagB)
                {

                    // REALIZACION DE CALCULOS
                    suma = sumar(a,b);
                    diferencia = restar(a,b);
                    cociente = dividir(a,b);
                    producto = multiplicar(a,b);
                    factorialPrimerOperando = factorial(a);
                    factorialSegundoOperando = factorial(b);
                    flagEleccionTres = 1;

                }
                else
                {

                    printf("Primero debe ingresar ambos operandos.\n\n");

                }
                system("pause");
                break;

            case 4:

                // CHEQUEO QUE HAYA INGRESADO AMBOS OPERANDOS Y HAYA REALIZADO LOS CALCULOS
                if (flagA && flagB && flagEleccionTres)
                {

                    mostrarResultados(suma, diferencia, cociente, producto, factorialPrimerOperando, factorialSegundoOperando);

                }
                // PUEDE HABER INGRESADO LOS OPERANDOS, PERO NO REALIZAR LOS CALCULOS
                else if (flagA && flagB && !flagEleccionTres)
                {

                    printf("Antes de mostrar los resultados, debe realizar los calculos.\n\n");

                }
                else
                {

                    printf("Sin ingresar operandos ni calcularlos, no puedo mostrar ningun resultado.\n\n");

                }

                system("pause");
                break;


            case 5:

                printf("Presione 'x' para confirmar la salida o 'r' para resetear la calculadora a sus valores por defecto.\n");
                fflush(stdin);
                scanf("%c", &eleccionCaseCinco);
                // RESETEO LOS VALORES PARA QUE EL USUARIO NO TENGA QUE ABRIR Y CERRAR EL .EXE SI QUIERE OPERAR CON OTROS VALORES
                if (eleccionCaseCinco == 'r')
                {

                    a = 0;
                    b = 0;
                    flagA = 0;
                    flagB = 0;
                    flagEleccionTres = 0;
                    system("pause");

                }
                else if(eleccionCaseCinco == 'x')
                {

                    // DESPEDIDA
                    system("cls");
                    printf("\n\nGracias por usar la calculadora!!!\n\n\n");
                    system("pause");

                }
                break;

            default:

                printf("Debe seleccionar una opcion valida.\n\n");
                system("pause");
                break;

        }

        system("cls");

    }while (eleccionCaseCinco != 'x');

    return 0;

}
