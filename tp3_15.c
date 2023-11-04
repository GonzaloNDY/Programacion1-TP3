/*Realizar un programa que permita cargar un arreglo de orden N de números enteros. Luego ordenar
sus elementos en forma descendente y presentarlos por pantalla. No utilizar un arreglo auxiliar
para el ordenamiento*/

#include <stdio.h>

#define MAX 50

int controlOrdenMax();
void cargarVector(int orden, int vector[]);
void ordenamientoPorInsercionDescendente(int orden, int vector[]);
void mostrarArreglo(int orden, int vector[]);

int main(int argc, char *argv[]){
    int enteros[MAX], ordenMax;
    printf("\nIndique el orden máximo del arreglo de enteros positivos: ");
    ordenMax = controlOrdenMax();
    printf("\nIngrese los números que guardará en el arreglo:\n");
    cargarVector(ordenMax, enteros);
    ordenamientoPorInsercionDescendente(ordenMax, enteros);
    printf("\nLos números ingresados en el arreglo, ordenados en forma descendente son: ");
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

void cargarVector(int orden, int vector[]){
    for (int i = 0; i < orden; i++){
        printf("%iº número: ", i +1);
        scanf("%i", &vector[i]);
    }
}

void ordenamientoPorInsercionDescendente(int orden, int vector[]) {
    int indiceAuxiliar, valorActual;
    for (int i = 1; i < orden; i++) {
        indiceAuxiliar = i - 1;
        valorActual = vector[i];  // Valor actual es el elemento actual que se insertará en su posicion correcta luego del while
        while (indiceAuxiliar >= 0 && vector[indiceAuxiliar] < valorActual) {
        // Mientras el índice auxiliar sea válido y el elemento a la izquierda sea menor que el valor actual, desplazamos los elementos menores hacia la derecha
            vector[indiceAuxiliar + 1] = vector[indiceAuxiliar];
            indiceAuxiliar--;  // Decrementamos el índice auxiliar para seguir comparando hacia la izquierda.
        }
        vector[indiceAuxiliar + 1] = valorActual;  // Insertamos el valor actual en la posición correcta encontrada.
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