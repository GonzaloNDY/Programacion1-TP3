/*Dado un arreglo de N elementos enteros, se debe guardar sus elementos en otro arreglo de orden
N pero en sentido invertido. Ej: Arreglo dado: V=(2,4,7,9,5,6); Arreglo invertido: W=(6,5,9,7,4,2)*/

#include <stdio.h>

int controlOrdenMax();
void cargarArreglo(int orden, int vector[]);
void invertirArreglo(int orden, int vector[], int nuevoVector[]);
void mostrarArreglo(int orden, int vector[]);

int main(int argc, char *argv[]){
    int enteros[50], ordenMax, arregloInvertido[50];
    printf("\nIndique el orden máximo del arreglo de números enteros: ");
    ordenMax = controlOrdenMax();
    printf("\nIngrese los números del arreglo\n");
    cargarArreglo(ordenMax, enteros);
    invertirArreglo(ordenMax, enteros, arregloInvertido);
    printf("\nLos números ingresados en el arreglo fueron:");
    mostrarArreglo(ordenMax, enteros);
    printf("\nLuego de invertir el arreglo son:");
    mostrarArreglo(ordenMax, arregloInvertido);
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

void cargarArreglo(int orden, int vector[]){
    for (int i = 0; i < orden; i++){
        printf("%iº número: ", i +1);
        scanf("%i", &vector[i]);
    }
}

void invertirArreglo(int orden, int vector[], int nuevoVector[]){
    int auxiliar;
    auxiliar = orden -1;
    for (int i = 0; i < orden; i++, auxiliar--){
        nuevoVector[i] = vector[auxiliar];
    }
}

void mostrarArreglo(int orden, int vector[]){
    printf(" %i",vector[0]);
    for (int i = 1; i < orden; i++){
        if (i == orden - 1)
            printf(" y %i\n", vector[i]);
        else
        printf(", %i", vector[i]);
    }
}