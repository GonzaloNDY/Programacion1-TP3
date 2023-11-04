/* Realizar un programa que permita cargar un arreglo V de orden N de números enteros y luego
presente por pantalla el arreglo ingresado y genere otro arreglo P que contenga todos los números
pares de V, y lo presente por pantalla ordenado de forma ascendente. En caso de que V no tenga
números pares mostrar el correspondiente mensaje por pantalla*/

#include <stdio.h>

#define MAX 50

int controlOrdenMax();
void cargarVector(int orden, int vector[]);
void vectorDePares(int orden, int vector[], int numPares[], int *ordenPares);
void ordenamientoPorInsercion(int orden, int vector[]);
void mostrarArreglo(int orden, int vector[]);

int main(int argc, char *argv[]){
    int enteros[MAX], ordenMax, enterosPares[MAX], ordenPares = 0;
    printf("\nIndique el orden máximo del arreglo de enteros positivos: ");
    ordenMax = controlOrdenMax();
    printf("\nIngrese los números que guardará en el arreglo:\n");
    cargarVector(ordenMax, enteros);
    ordenamientoPorInsercion(ordenMax, enteros);
    vectorDePares(ordenMax, enteros, enterosPares, &ordenPares);
    printf("\nLos enteros positivos ingresados en el arreglo fueron: ");
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

void ordenamientoPorInsercion(int orden, int vector[]){
    int indiceAuxiliar, valorActual;
    for(int i = 1; i < orden; i++){
        indiceAuxiliar = i - 1;
        valorActual = vector[i];
        while (indiceAuxiliar >= 0 && vector[indiceAuxiliar] > valorActual){
            vector[indiceAuxiliar + 1] = vector[indiceAuxiliar];
            indiceAuxiliar--;
        }
        vector[indiceAuxiliar + 1] = valorActual;
    }
}

void vectorDePares(int orden, int vector[], int numPares[], int *ordenPares){
    int auxiliar = 0, indiceAuxiliar = 0;
    for (int i = 0; i < orden; i++){
        if (vector[i] % 2 == 0 && vector[i] > 0){
            numPares[indiceAuxiliar] = vector[i];
            indiceAuxiliar++;
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