/*Cargar caracteres en un arreglo de orden N. Luego contabilizar, usando funciones, cuántos
caracteres del arreglo son alfabéticos, cuántos son dígitos y cuántos son de otras categorías*/

#include <stdio.h>
#include <ctype.h>

#define MAX 50

int controlOrdenMax();
void cargarVector(int orden, char vector[]);
void controlarArreglo(int orden, char vector[], int *letras, int *numeros, int *otros);
void mostrarArreglo(int orden, char vector[]);

int main(int argc, char *argv[]){
    char caracteres[MAX], caracter;
    int orden, cantLetras = 0, cantDigitos = 0, cantOtros = 0;
    printf("\nPrimero indique la cantidad de caracteres que ingresará en el arreglo (debe ser un valor positivo y menor a 50): ");
    orden = controlOrdenMax();
    printf("\nIngrese los caracteres a guardar en el arreglo:\n");
    cargarVector(orden, caracteres);
    controlarArreglo(orden, caracteres, &cantLetras, &cantDigitos, &cantOtros);
    printf("\nLos caracteres ingresados en el arreglo son: ");
    mostrarArreglo(orden, caracteres);
    printf("\nSe ingresaron %i caracteres alfabeticos, %i dígitos y %i caracteres de otras categorias\n", cantLetras, cantDigitos, cantOtros);
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

void cargarVector(int orden, char vector[]){
    for (int i = 0; i < orden; i++){
        fgetc(stdin);
        printf("%iº caracter: ", i + 1);
        scanf("%c", &vector[i]);
    }
}

void controlarArreglo(int orden, char vector[], int *letras, int *numeros, int *otros){
    for (int i = 0; i < orden; i++){
        if (isalpha(vector[i]))
            ++*letras;
        else if (isdigit(vector[i]))
            ++*numeros;
        else
            ++*otros;
    }
}

void mostrarArreglo(int orden, char vector[]){
    for (int i = 0; i < orden; i++){
        if (i == orden - 1)
            printf("%c\n", vector[i]);
        else
            printf("%c - ", vector[i]);
    }
}