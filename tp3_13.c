/* Realizar un programa que permita cargar un arreglo V de orden N de números enteros y luego
presente por pantalla el arreglo ingresado y genere otro arreglo P que contenga todos los números
pares de V, y lo presente por pantalla. En caso de que V no tenga números pares mostrar el
correspondiente mensaje por pantalla*/

#include <stdio.h>

#define MAX 50

int controlOrdenMax();
void cargarVector(int orden, int vector[]);
void vectorDePares(int orden, int vector[], int numPares[], int *ordenPares);
void mostrarArreglo(int orden, int vector[]);

int main(int argc, char *argv[]){
    int enteros[MAX], ordenMax, enterosPares[MAX], ordenPares = 0;
    printf("\nIndique el orden máximo del arreglo de enteros positivos: ");
    ordenMax = controlOrdenMax();
    printf("\nIngrese los números que guardará en el arreglo:\n");
    cargarVector(ordenMax, enteros);
    vectorDePares(ordenMax, enteros, enterosPares, &ordenPares);
    printf("\nLos números ingresados en el arreglo fueron: ");
    mostrarArreglo(ordenMax, enteros);
    if (ordenPares == 0){
        printf("Ninguno de los números del arreglo anterior son pares");
    } else {    
        printf("\nLos números pares del arreglo anterior son: ");
        mostrarArreglo(ordenPares, enterosPares);
    }
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

void vectorDePares(int orden, int vector[], int numPares[], int *ordenPares){
    for (int i = 0; i < orden; i++){
        if (vector[i] % 2 == 0 && vector[i] != 0){
            numPares[*ordenPares] = vector[i];
            ++*ordenPares;
        }
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