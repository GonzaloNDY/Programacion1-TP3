/*Diseñar un programa que emplee un arreglo de números enteros de orden N y que cuente con un
menú interactivo con las siguientes opciones:
● a.Cargar arreglo de enteros
● b.Mostrar arreglo de enteros
● c.Mostrar el valor del mayor elemento del arreglo
● d.Mostrar el valor del menor elemento del arreglo.
Tener en cuenta que el usuario puede presionar la opción b, c o d sin haber cargado previamente el
arreglo (opción a), por lo que deberá controlar esta situación. Además, controlar que el valor de N,
ingresado por el usuario, sea un entero positivo y se encuentre en el rango permitido*/

#include <stdio.h>

#define MAX 50

int controlOrdenMax();
void cargarVector(int orden, int vector[]);
void encontrarMenorOMayorNum(int orden, int vector[], int *menorOMayorNum);
void mostrarArreglo(int orden, int vector[]);

int main(int argc, char *argv[]){
    char opcion;
    int enteros[MAX], ordenMax, menorNum, mayorNum, arregloVacio = 1;  
    printf("\nPrimero indique la cantidad de números que ingresará en el arreglo (debe ser un valor positivo y menor a 50): ");
    ordenMax = controlOrdenMax();
    do {
        menorNum = 2146474849;
        mayorNum = -2146474849;
        printf("\nElija una de las siguientes opciones:\na) Cargar arreglo de enteros\nb) Mostrar arreglo de enteros\nc) Mostrar el valor del mayor elemento del arreglo");
        printf("\nd) Mostrar el valor del menor elemento del arreglo\n\nOpción ingresada: ");
        fgetc(stdin);
        scanf("%c", &opcion);
        if (arregloVacio && opcion != '\n' && opcion != 'a'){  //arregloVacio será verdadero (distinto de cero) mientras el arreglo esté vacio 
            printf("\nTiene que cargar números en el arreglo para poder acceder a las otras opciones, se reiniciará el programa\n");
        } else {
            switch (opcion){
            case 'a':
                printf("\nIngrese los números que se guardarán en el arreglo:\n");
                cargarVector(ordenMax, enteros);
                arregloVacio = 0;  //arregloVacio sera cero (falso) cuando el arreglo deje de estar vacio
                break;
            case 'b':
                printf("\nLos elementos del arreglo son:\n");
                mostrarArreglo(ordenMax, enteros);
                break;
            case 'c':
                encontrarMenorOMayorNum(ordenMax, enteros, &menorNum);
                printf("\nEl menor valor ingresado en el arreglo es: %i\n", menorNum);
                break;
            case 'd':
                encontrarMenorOMayorNum(ordenMax, enteros, &mayorNum);
                printf("\nEl mayor valor ingresado en el arreglo es: %i\n", mayorNum);
                break;
            default:
                printf("\nLa opcion ingresada no existe\n");
                break;
            }
        }
        printf("\nPresione enter para volver al menú, ingrese cualquier otro caracter para finalizar: ");
        fgetc(stdin);
        scanf("%c", &opcion);
    } while (opcion != '\n');
    return 0;
}

int controlOrdenMax(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0 || num > 50)
            printf("El valor ingresado debe ser mayor a cero y menor a 50, intente nuevamente: ");
    } while (num < 0 || num > 50);
    return num;
}

void cargarVector(int orden, int vector[]){
    for (int i = 0; i < orden; i++){
        printf("%iº número: ", i +1);
        scanf("%i", &vector[i]);
    }
}

void encontrarMenorOMayorNum(int orden, int vector[], int *menorOMayorNum){
    int esBusquedaMenor = 0;
    if (*menorOMayorNum < 0){
        esBusquedaMenor = 1;
    }
    for (int i = 0; i < orden; i++){
        if (esBusquedaMenor && vector[i] > *menorOMayorNum)
            *menorOMayorNum = vector[i];
        else if (vector[i] < *menorOMayorNum)
            *menorOMayorNum = vector[i];
    }
}

void mostrarArreglo(int orden, int vector[]){
    printf("(");
    for (int i = 0; i < orden; i++){
        if (i == orden - 1)
            printf("%i)\n", vector[i]);
        else
            printf("%i, ", vector[i]);
    }
}