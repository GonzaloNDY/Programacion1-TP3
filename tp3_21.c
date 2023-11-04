/*Para pensar: Escribir un programa que, dada una frase de tamaño máximo N, determine si es un
palíndromo o no. Un palíndromo es una frase que, atendiendo sólo a sus letras e ignorando los
espacios, acentos, signos de puntuación y tipo de letra (mayúscula o minúscula) expresa lo mismo
leída de izquierda a derecha que de derecha a izquierda. “dabale arroz a la zorra el abad”.
Utilizar funciones para:
● Controlar que el orden del arreglo que se va a cargar sea un entero positivo y que no
supere el valor máximo que puede contener el arreglo.
● Ingresar la frase caracter a caracter en un arreglo.
● Evaluar si la frase es un palíndromo*/

#include <stdio.h>
#include <ctype.h>

#define MAX 200

int controlOrdenMax();
void cargarVector(int *orden, char vector[]);
void filtrarCaracteres(int *orden, char vector[]);
void verificarPalindromo(int orden, char vector[]);

int main(int argc, char *argv[]){
    char frase[MAX];
    int orden;
    printf("\nPrimero indique la cantidad máxima de caracteres que ingresará en el arreglo (debe ser un valor positivo y menor a 200): ");
    orden = controlOrdenMax();
    printf("\nIngrese la frase a guardar en el arreglo:\n");
    fgetc(stdin);
    cargarVector(&orden, frase);
    filtrarCaracteres(&orden, frase);
    verificarPalindromo(orden, frase);
    return 0;
}

int controlOrdenMax(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0 || num > 200)
            printf("El valor ingresado debe ser mayor a cero y menor a 200, intente nuevamente: ");
    } while (num < 0 || num > 200);
    return num;
}

void cargarVector(int *orden, char vector[]){
    for (int i = 0; i < *orden; i++){
        scanf("%c", &vector[i]);
        if (vector[i] == '\n'){
            vector[i] = '\0';
            *orden = i;
        }
    }
}

void verificarPalindromo(int orden, char vector[]){
    int indiceAuxiliar = orden - 1;
    for (int i = 0; i < orden / 2; i++, indiceAuxiliar--){
        if (vector[i] != vector[indiceAuxiliar]){
            printf("\nLa frase ingresada no es un palíndromo\n");
            return;
        }
    }
    printf("\nLa frase ingresada es un palíndromo\n");
}

void filtrarCaracteres(int *orden, char vector[]){
    for (int i = 0; i < *orden && vector[i] != '\0'; i++){
        vector[i] = tolower(vector[i]);
        if (!isalpha(vector[i]) && vector[i] != ' '){
            printf("\nIngrese una frase que no contenga acentos o caracteres no alfabeticos: ");
            fgetc(stdin);
            cargarVector(orden, vector);
            i = 0;
        } else if (vector[i] == ' '){
            for (int auxiliar = i; auxiliar < *orden; auxiliar++){
                if (auxiliar == *orden - 1)
                    vector[auxiliar] = '\0';
                else
                    vector[auxiliar] = vector[auxiliar + 1];
            }
            --*orden;
        }
    }
}