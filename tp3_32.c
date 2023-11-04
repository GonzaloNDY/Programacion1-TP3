/*Realizar un programa que permita cargar un arreglo bidimensional con N filas y M columnas cuyos
elementos sean caracteres y luego lo presente por pantalla recorriendolo por columnas. Utilizar una
función para controlar que los valores de la cantidad de filas y columnas sean mayores que 1 y
menores que el máximo definido para el arreglo*/

#include <stdio.h>

#define MAX 50

int controlOrdenMax();
void cargarMatriz(int ordenI, int ordenJ, int enteros[MAX][MAX]);
void mostrarMatriz(int ordenI, int ordenJ, int enteros[MAX][MAX]);

int main(int argc, char *argv[]){
    int enteros[MAX][MAX], ordenI, ordenJ;  // I/i=filas, J/j=columnas
    printf("Ingrese la cantidad de columnas que tendrá el arreglo: ");
    ordenJ = controlOrdenMax();
    printf("\nIngrese la cantidad de filas que tendrá el arreglo: ");
    ordenI = controlOrdenMax();
    // Carga de la matriz enteros:
    cargarMatriz(ordenI, ordenJ, enteros);
    // Presentacion de la matriz enteros:
    printf("\nEl arreglo ingresado es:\n");
    mostrarMatriz(ordenI, ordenJ, enteros);
    return 0;
}

int controlOrdenMax(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0 || num > 50)
            printf("El valor ingresado debe ser mayor a uno y menor a 50, intente nuevamente: ");
    } while (num < 1 || num > 50);
    return num;
}

void cargarMatriz(int ordenI, int ordenJ, int enteros[MAX][MAX]){
    for (int j = 0; j < ordenJ; j++){
        for (int i = 0; i < ordenI; i++){
            printf("Ingrese el elemento de la columna %i y la fila %i: ", j + 1, i + 1);
            scanf("%i", &enteros[j][i]);
        }
        printf("\n");
    }
}

void mostrarMatriz(int ordenI, int ordenJ, int enteros[MAX][MAX]){
    for (int j = 0; j < ordenJ; j++){
        printf("\nColumna %i:\n", j + 1);
        for (int i = 0; i < ordenI; i++){
            printf("%i\n", enteros[j][i]);
        }
    }
}