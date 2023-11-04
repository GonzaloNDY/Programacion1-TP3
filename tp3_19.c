/*Ingresar un arreglo de caracteres de orden N, luego convertir los caracteres alfabéticos en
mayúscula a minúscula y viceversa. Presentar el arreglo original y el modificado por pantalla. No
utilizar un arreglo valorActual*/

#include <stdio.h>
#include <ctype.h>

#define MAX 50

int controlOrdenMax();
void cargarVector(int orden, char vector[]);
void convertirArreglo(int orden, char vector[]);
void mostrarArreglo(int orden, char vector[]);

int main(int argc, char *argv[]){
    char caracteres[MAX], caracter;
    int orden;
    printf("\nPrimero indique la cantidad de caracteres que ingresará en el arreglo (debe ser un valor positivo y menor a 50): ");
    orden = controlOrdenMax();
    printf("\nIngrese los caracteres a guardar en el arreglo:\n");
    cargarVector(orden, caracteres);
    printf("\nLos caracteres ingresados en el arreglo son: ");
    mostrarArreglo(orden, caracteres);
    convertirArreglo(orden, caracteres);
    printf("\nLos elementos cambiados a mayuscula o minuscula son: ");
    mostrarArreglo(orden, caracteres);
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

void convertirArreglo(int orden, char vector[]){
    for (int i = 0; i < orden; i++){
        if (isupper(vector[i]))
            vector[i] = tolower(vector[i]);
        else
            vector[i] = toupper(vector[i]);
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