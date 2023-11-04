/* Cargar un arreglo con N números enteros, luego buscar el menor elemento impar contenido en el
mismo. En caso de no encontrar elementos impares presentar un mensaje por pantalla*/

#include <stdio.h>

#define MAX 50

int controlOrdenMax();
void cargarVector(int orden, int vector[]);
void encontrarMenorImpar(int orden, int vector[], int *menorImpar);

int main(int argc, char *argv[]){
    int enteros[MAX], ordenMax, menorImpar = 2146474849;
    printf("\nIndique la cantidad de números que ingresará en el arreglo (debe ser un valor positivo y menor a 50): ");
    ordenMax = controlOrdenMax();
    printf("\nIngrese los números que guardará en el arreglo:\n");
    cargarVector(ordenMax, enteros);
    encontrarMenorImpar(ordenMax, enteros, &menorImpar);
    if (menorImpar == 2146474849){
        printf("\nNo se encontraron números impares en el arreglo\n");
    } else {
        printf("\nEl menor número impar en el arreglo ingresado es: %i\n", menorImpar);
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

void encontrarMenorImpar(int orden, int vector[], int *menorImpar){
    for (int i = 0; i < orden; i++){
        if (vector[i] % 2 != 0 && vector[i] < *menorImpar)
            *menorImpar = vector[i];
    }
}