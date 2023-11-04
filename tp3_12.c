/*Dado un arreglo de N elementos enteros, se debe invertir los elementos del mismo y presentar por
pantalla el arreglo resultante. No debe usar un arreglo auxiliar. Ej: El Arreglo dado: V=(2,4,7,9,5,6)
se convierte en: V=(6,5,9,7,4,2)*/

#include <stdio.h>

int controlOrdenMax();
void cargarArreglo(int orden, int vector[]);
void invertirArreglo(int orden, int vector[]);
void mostrarArreglo(int orden, int vector[]);

int main(int argc, char *argv[]){
    int enteros[50], ordenMax;
    printf("\nIndique el orden máximo del arreglo de números enteros: ");
    ordenMax = controlOrdenMax();
    printf("\nIngrese los números del arreglo\n");
    cargarArreglo(ordenMax, enteros);
    printf("\nLos números ingresados en el arreglo fueron:");
    mostrarArreglo(ordenMax, enteros);
    invertirArreglo(ordenMax, enteros);
    printf("\nLuego de invertir el arreglo son:");
    mostrarArreglo(ordenMax, enteros);
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

void invertirArreglo(int orden, int vector[]){
    int auxiliar, j;
    j = orden -1;   //j = índice auxiliar que empieza desde el ultimo elemento del arreglo
    for (int i = 0; i < orden / 2; i++){
        auxiliar = vector[i];
        vector[i] = vector[j];
        vector[j] = auxiliar;
        j--;
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