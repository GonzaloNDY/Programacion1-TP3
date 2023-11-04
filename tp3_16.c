/*Ingresar en un arreglo de caracteres el nombre de una persona, ingresar cada letra en un elemento
del arreglo. Luego, ingresar un carácter por teclado y comprobar si dicho carácter pertenece al
nombre ingresado. Finalmente, mostrar el arreglo y el mensaje correspondiente*/

#include <stdio.h>

#define MAX 50

void cargarVectorPalabra(int *orden, char vector[]);
void caracterPertenece(int orden, char vector[], char caracterBuscado);
void mostrarArreglo(int orden, char vector[]);

int main(int argc, char *argv[]){
    char nombre[MAX], caracter;
    int orden = 0;
    printf("\nIngrese el nombre de una persona: ");
    cargarVectorPalabra(&orden, nombre);
    printf("Ingrese el caracter a buscar en ese nombre: ");
    scanf("%c", &caracter);
    printf("\nEl nombre ingresado en el arreglo fue: ");
    mostrarArreglo(orden, nombre);
    caracterPertenece(orden, nombre, caracter);
    return 0;
}

void cargarVectorPalabra(int *orden, char vector[]){
    for (int i = 0; vector[i - 1] != '\0'; i++){
        scanf("%c", &vector[i]);
        if (vector[i] == '\n'){
            vector[i] = '\0';
        }
        ++*orden;
    }
}

void caracterPertenece(int orden, char vector[], char caracterBuscado){
    for (int i = 0; i < orden; i++){
        if (caracterBuscado == vector[i]){
            printf("\nEl caracter \"%c\" pertenece al nombre ingresado\n",caracterBuscado);
            return;
        }
    }
    printf("\nEl caracter \"%c\" no pertenece al nombre ingresado\n", caracterBuscado);
    return;
}

void mostrarArreglo(int orden, char vector[]){
    for (int i = 0; i < orden; i++){
        printf("%c", vector[i]);
    }
    printf("\n");
}