/*Realizar un programa que permita cargar un arreglo cuyos elementos sean N números enteros y
luego permita presentarlo por pantalla.*/

#include <stdio.h>

int controlOrdenMaximo();
void cargarNumeros(int cantMaxima, int arreglo[]);
void mostrarArreglo(int cantidad, int numEnteros[]);

int main(int argc, char *argv[]){
    int numEnteros[50], orden;
    printf("\nIndique la cantidad de números que ingresará (debe ser un valor menor a 50): ");
    orden = controlOrdenMaximo();
    cargarNumeros(orden, numEnteros);
    mostrarArreglo(orden, numEnteros);
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
    printf("los números ingresados fueron: ");
    for (int i = 0; i < cantidad; i++){
        if (i == cantidad - 1){
            printf("%i\n", numEnteros[i]);
        } else
            printf("%i, ", numEnteros[i]);
    }
}