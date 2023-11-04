/*Dado un arreglo V de orden N que contiene enteros positivos, generar un arreglo P de orden M que
contenga los elementos de V que sean números primos. Si el arreglo V no tiene números primos
entonces presentar un mensaje por pantalla.
Utilizar funciones para
● Controlar que el orden del arreglo que se va a cargar sea un entero positivo y que no
supere el valor máximo que puede contener el arreglo.
● Controlar que los valores ingresados sean positivos.
● Determinar si un número es primo o no.
● Armar el nuevo vector*/

#include <stdio.h>

#define MAX 50

int controlOrdenMaximo();
void cargarArreglos(int ordenE, int vectorE[], int vectorP[], int *j);
int controlPositivo();
int controlPrimo(int num);
void mostrarArreglos(int ordenE, int ordenP, int vectorE[], int vectorP[]);

int main(int argc, char *argv[]){
    int enteros[MAX], ordenE, primos[MAX], ordenP = 0;
    printf("\nIndique el orden máximo del arreglo de enteros positivos: ");
    ordenE = controlOrdemMaximo();
    printf("\nIngrese los números a controlar (tienen que ser valores positivos)\n");
    cargarArreglos(ordenE, enteros, primos, &ordenP);
    mostrarArreglos(ordenE, ordenP, enteros, primos);
    return 0;
}

int controlOrdenMaximo(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0 || num > 50)
            printf("El valor ingresado debe ser mayor a cero y menor a 50, intente nuevamente: ");
    } while (num < 0 || num > 50);
    return num;
}

void cargarArreglos(int ordenE, int vectorE[], int vectorP[], int *ordenP){
    for (int i = 0; i < ordenE; i++){
        printf("%iº número: ", i +1);
        vectorE[i] = controlPositivo();
        if (controlPrimo(vectorE[i]) && vectorE[i] > 1){
            vectorP[*ordenP] = vectorE[i];
            ++*ordenP;
        }
    }
}

int controlPositivo(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0)
            printf("El valor ingresado tiene que ser mayor que cero, intente nuevamente: ");
    } while (num < 0);
    return num;
}

int controlPrimo(int num){
    if (num < 2){
        return 0;
    }
    for (int i = 2; i < num; i++){
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void mostrarArreglos(int ordenE, int ordenP, int vectorE[], int vectorP[]){
    printf("\nLos enteros positivos ingresados en el arreglo fueron: %i",vectorE[0]);
    for (int i = 1; i < ordenE; i++){
        if (i == ordenE - 1)
            printf(" y %i\n", vectorE[i]);
        else
            printf(", %i", vectorE[i]);
    }
    if (ordenP == 0){
        printf("No se ingresaron números primos en el arreglo anterior\n");
    } else {
        printf("\nLos números primos del arreglo anterior son: %i",vectorP[0]);
        for (int i = 1; i < ordenP; i++){
            if (i == ordenP - 1)
                printf(" y %i\n", vectorP[i]);
            else
            printf(", %i", vectorP[i]);
        }
    }
}