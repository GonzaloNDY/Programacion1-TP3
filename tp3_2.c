/*Realizar un programa que permita cargar un arreglo cuyos elementos sean N caracteres y luego
permita presentarlo por pantalla*/

#include <stdio.h>

int controlOrdenMaximo();
void cargarCaracteres(int cantMaxima, char arreglo[]);
void mostrarArreglo(int cantidad, char caracteres[]);

int main(int argc, char *argv[]){
    char caracteres[50];
    int orden;
    printf("\nIndique la cantidad de caracteres que ingresará (debe ser un valor menor a 50): ");
    orden = controlOrdenMaximo();
    cargarCaracteres(orden, caracteres);
    mostrarArreglo(orden, caracteres);
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

void cargarCaracteres(int cantMaxima, char arreglo[]){
    printf("\n\tA continuación ingrese los caracteres que se guardarán\n");
    for (int i = 0; i < cantMaxima; i++){
        fgetc(stdin);
        printf("%iº caracter: ", i + 1);
        scanf("%c",&arreglo[i]);
    }
}

void mostrarArreglo(int cantidad, char caracteres[]){
    printf("los caracteres ingresados fueron: ");
    for (int i = 0; i < cantidad; i++){
        if (i == cantidad - 1){
            printf("\"%c\"\n", caracteres[i]);
        } else
            printf("\"%c\", ", caracteres[i]);
    }
}