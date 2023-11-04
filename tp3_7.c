/*Realizar un programa que permita cargar un arreglo que contenga una cantidad N de caracteres
alfabéticos y luego lo presente por pantalla. Recordar que debe resolverse empleando una función
para cargar el arreglo y controlar los caracteres que se ingresan y otra función para presentar por
pantalla el arreglo resultante*/

#include <stdio.h>
#include <ctype.h>

int controlOrdenMaximo();
void cargarArreglo(int cantidad, char arreglo[]);
void mostrarArreglo(int cantidad, char arreglo[]);


int main(int argc, char *argv[]){
    char letras[50];
    int ordenMax;
    printf("\nIndique la cantidad de letras que guardará en el arreglo: ");
    ordenMax = controlOrdenMaximo();
    printf("Ingrese las letras a guardar\n");
    cargarArreglo(ordenMax, letras);
    mostrarArreglo(ordenMax, letras);
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

void cargarArreglo(int cantidad, char arreglo[]){
    for (int i = 0; i < cantidad; i++){
        printf("%iº letra: ", i + 1);
        do {
            fgetc(stdin);
            scanf("%c", &arreglo[i]);
            if (!isalpha(arreglo[i]))
                printf("El caracter ingresado debe ser una letra, intente nuevamente: ");
        } while (!isalpha(arreglo[i]));
    }
}

void mostrarArreglo(int cantidad, char arreglo[]){
    printf("\nLas letras ingresadas fueron: \"%c\"", arreglo[0]);
    for (int i = 1; i < cantidad; i++){
        if (i == cantidad - 1){
            printf(" y \"%c\"\n", arreglo[i]);
        } else {
            printf(", \"%c\"", arreglo[i]);
        }
    }
}