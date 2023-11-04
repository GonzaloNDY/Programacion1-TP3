/*Realizar un programa que permita determinar cuántas veces se encuentra el valor x en un arreglo.
Para esto se deberá:
○ ingresar números enteros en un arreglo de orden N
○ ingresar un valor x
○ mostrar por pantalla el arreglo ingresado
○ mostrar el elemento buscado x y la cantidad de veces que se encontró el elemento
buscado. En caso de que el vector no contenga un elemento de valor igual a x, mostrar el
mensaje correspondiente*/

#include <stdio.h>

int controlOrdenMaximo();
void cargarNumeros(int cantMaxima, int arreglo[]);
void mostrarArreglo(int cantidad, int numEnteros[]);
void mostrarNumBuscado(int numBuscado, int cantidad, int arreglo[]);

int main(int argc, char *argv[]){
    int numEnteros[50], ordenMax, numBuscado;
    printf("\nIndique la cantidad de números que ingresará (debe ser un valor menor a 50): ");
    ordenMax = controlOrdenMaximo();
    cargarNumeros(ordenMax, numEnteros);
    printf("Ingrese el número a buscar: ");
    scanf("%i", &numBuscado);
    mostrarArreglo(ordenMax, numEnteros);
    mostrarNumBuscado(numBuscado, ordenMax, numEnteros);
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

void cargarNumeros(int cantMaxima, int arreglo[]){
    printf("\n\tA continuación ingrese los números enteros que se guardarán\n");
    for (int i = 0; i < cantMaxima; i++){
        printf("%iº entero: ", i + 1);
        scanf("%i",&arreglo[i]);
    }
}

void mostrarArreglo(int cantidad, int numEnteros[]){
    printf("\nLos números ingresados fueron: ");
    for (int i = 0; i < cantidad; i++){
        if (i == cantidad - 1){
            printf("%i\n", numEnteros[i]);
        } else
            printf("%i, ", numEnteros[i]);
    }
}

void mostrarNumBuscado(int numBuscado, int cantidad, int arreglo[]){
    int contadorNumBuscado = 0;
    for (int i = 0; i < cantidad; i++){
        if (arreglo[i] == numBuscado)
            contadorNumBuscado++;
    }
    if (contadorNumBuscado == 0){
        printf("\nEl número %i no fue ingresado en este arreglo\n", numBuscado);
    } else {
        printf("\nEl número %i fue ingresado %i veces en total\n", numBuscado, contadorNumBuscado);
    }
}