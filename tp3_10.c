/*Realizar un programa que permita ingresar números enteros en un arreglo de orden N, luego
desplazar sus elementos X lugares a la derecha (tener en cuenta que al mover los elementos unba
posición hacia la derecha, el último elemento del arreglo pasará a ser el primer elemento del
arreglo). Mostrar por pantalla el arreglo ingresado y el arreglo modificado. Por ejemplo, si se ingresa
el siguiente arreglo: (3, 0, 8, 2, 1, 7) y X=3, entonces el arreglo modificado debe quedar del siguiente
modo: (2, 1, 7, 3, 0, 8)*/

#include <stdio.h>

int controlOrdenMaximo();
int controlPositivo();
void cargarArreglo(int orden, int vector[]);
void modificarArreglo(int orden, int vector[], int cantDesplazamientos, int nuevoVector[]);
void mostrarArreglo(int orden, int vector[]);

int main(int argc, char *argv[]){
    int enteros[50], ordenMax, numDesplazados, enterosDesplazados[50];
    printf("\nIndique el orden máximo del arreglo de enteros positivos: ");
    ordenMax = controlOrdenMaximo();
    printf("\nIngrese los números del arreglo\n");
    cargarArreglo(ordenMax, enteros);
    printf("Indique la cantidad de lugares que se desplazarán los npumeros del anterior arreglo: ");
    numDesplazados = controlPositivo();
    modificarArreglo(ordenMax, enteros, numDesplazados, enterosDesplazados);
    printf("\nLos enteros positivos ingresados en el arreglo fueron:");
    mostrarArreglo(ordenMax, enteros);
    printf("\nLuego de desplazarse %i lugares hacia la derecha son:", numDesplazados);
    mostrarArreglo(ordenMax, enterosDesplazados);
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

int controlPositivo(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0)
            printf("El valor ingresado tiene que ser mayor que cero, intente nuevamente: ");
    } while (num < 0);
    return num;
}

void cargarArreglo(int orden, int vector[]){
    for (int i = 0; i < orden; i++){
        printf("%iº número: ", i +1);
        scanf("%i", &vector[i]);
    }
}

void modificarArreglo(int orden, int vector[], int cantDesplazamientos, int nuevoVector[]){
    int auxiliar = 0;
    for (int i = 0; i < orden; i++){
        if (i + cantDesplazamientos < orden){
            nuevoVector[i + cantDesplazamientos] = vector[i];
        } else {
            nuevoVector[auxiliar] = vector[i];
            auxiliar++;
        }
    }
}

void mostrarArreglo(int orden, int vector[]){
    printf(" %i",vector[0]);
    for (int i = 1; i < orden; i++){
        if (i == orden - 1)
            printf("y %i\n", vector[i]);
        else
        printf(", %i ", vector[i]);
    }
}