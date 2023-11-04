/*Realizar un programa que permita cargar un arreglo bidimensional con N filas y M columnas cuyos
elementos sean números enteros y luego lo presente por pantalla. Resolver sin utilizar funciones
para la carga y presentación del arreglo.
Ejemplo de un arreglo bidimensional de 4 columnas por 3 filas:
4 8 -2 1
0 3 6 -7
-9 2 5 3*/

#include <stdio.h>

#define MAX 50

int controlOrdenMax();

int main(int argc, char *argv[]){
    int enteros[MAX][MAX], ordenI, ordenJ;  // I/i=filas, J/j=columnas
    printf("\nIngrese la cantidad de filas que tendrá el arreglo: ");
    ordenI = controlOrdenMax();
    printf("Ingrese la cantidad de columnas que tendrá el arreglo: ");
    ordenJ = controlOrdenMax();
    // Carga de la matriz enteros:
    for (int i = 0; i < ordenI; i++){
        for (int j = 0; j < ordenJ; j++){
            printf("Ingrese el elemento de la fila %i y la columna %i: ", i + 1, j + 1);
            scanf("%i", &enteros[i][j]);
        }
        printf("\n");
    }
    // Presentacion de la matriz enteros:
    printf("\nEl arreglo ingresado es:\n\n");
    for (int i = 0; i < ordenI; i++){
        for (int j = 0; j < ordenJ; j++){
            printf("%i\t", enteros[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int controlOrdenMax(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0 || num > 50)
            printf("El valor ingresado debe ser mayor a cero y menor a 50, intente nuevamente: ");
    } while (num < 1 || num > 50);
    return num;
}