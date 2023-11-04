/*Para Pensar: En una pila de platos, los platos van poniéndose uno sobre el otro, y si se quiere sacar
uno, se saca primero el último que se ha puesto. Realizar un programa que permita simular una pila
de números usando un arreglo unidimensional y un menú interactivo que muestre en pantalla las
siguientes operaciones:
● Apilar (push): Añadir un elemento en la parte superior de la pila, es decir que debe
ingresar un número por teclado y luego agregarlo en el vector a continuación del último
número agregado (se debe controlar previamente que exista lugar en el arreglo, en caso
contrario deberá mostrar el mensaje correspondiente).
● Desapilar (pop): Leer y retirar el elemento superior de la pila, es decir que debe mostrar
en pantalla el último número que fué ingresado en el vector y luego deberá eliminarlo,
dejando disponible esa posición para almacenar otro número (se debe controlar
previamente que la pila no se encuentre vacía, en caso contrario deberá mostrar el
mensaje correspondiente).
● Leer último (top o peek): Leer el elemento superior de la pila sin retirarlo, es decir que
debe mostrar en pantalla el último número que fué ingresado en el vector (se debe
controlar previamente que la pila no se encuentre vacía, en caso contrario deberá
mostrar el mensaje correspondiente).
● Mostrar el arreglo en pantalla.
● Salir*/

#include <stdio.h>

#define MAX 100

int controlOrdenMax();
void cargarElemento(int orden, int vector[], int *ultimaPosicion);
void quitarUltimoElemento(int orden, int vector[], int *ultimaPosicion);
void mostrarArreglo(int orden, int vector[]);

int main(int argc, char *argv[]){
    int enteros[MAX], ordenMax, arregloVacio = 1, ultimaPosicion = 0;
    char opcion;
    printf("\nPrimero indique la cantidad máxima de números que ingresará en el arreglo (debe ser un valor positivo y menor a 100): ");
    ordenMax = controlOrdenMax();
    do {
        printf("\n\tMenu:\na) Apilar (push): Añadir un elemento en la parte superior de la pila\nb) Desapilar (pop): Leer y retirar el elemento superior de la pila");
        printf("\nc) Leer último (top o peek): Leer el elemento superior de la pila sin retirarlo\nd)  Mostrar el arreglo en pantalla\ne) Salir\n\nOpción ingresada: ");
        fgetc(stdin);
        scanf("%c", &opcion);
        if (arregloVacio && opcion != 'a'){  //arregloVacio será verdadero (distinto de cero) mientras el arreglo esté vacio 
            printf("\nTiene que cargar números en el arreglo para poder acceder a las otras opciones, se reiniciará el programa\n");
        } else {
            switch (opcion){
            case 'a':
                if (ultimaPosicion < ordenMax){
                    printf("\nIngrese el %iº número que añadirá en la parte superior de la pila: ", ultimaPosicion + 1);
                    cargarElemento(ordenMax, enteros, &ultimaPosicion);
                } else {
                    printf("Ya no quedan lugares disponibles en la pila\n");
                }
                arregloVacio = 0;  //arregloVacio sera cero (falso) cuando el arreglo deje de estar vacio
                break;
            case 'b':
                if (ultimaPosicion > 0){
                    printf("\nEl último elemento es: %i, se lo eliminará de la pila\n", enteros[ultimaPosicion - 1]);
                    quitarUltimoElemento(ordenMax, enteros, &ultimaPosicion);
                } else {
                    printf("\nEl arreglo quedó vacio\n");
                }
                break;
            case 'c':
                if (ultimaPosicion > 0){
                    printf("El último elemento de la pila es %i\n", enteros[ultimaPosicion - 1]);
                } else {
                    printf("\nEl arreglo quedó vacio\n");
                }
                break;
            case 'd':
                if (ultimaPosicion > 0){
                    printf("\nEl arreglo ingresado es:\n");
                    mostrarArreglo(ultimaPosicion, enteros);
                } else {
                    printf("\nEl arreglo quedó vacio\n");
                }                
                break;
            default:
                printf("\n\nLa opcion ingresada no existe\n");
                break;
            }
            fgetc(stdin);
            printf("\nPresione \"e\" para finalizar, ingrese cualquier otro caracter para volver al menú: ");
            scanf("%c", &opcion);
        }
    } while (opcion != 'e');
    return 0;
}

int controlOrdenMax(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0 || num > 100)
            printf("El valor ingresado debe ser mayor a cero y menor a 100, intente nuevamente: ");
    } while (num < 0 || num > 100);
    return num;
}

void cargarElemento(int orden, int vector[], int *ultimaPosicion){
    scanf("%i", &vector[*ultimaPosicion]);
    ++*ultimaPosicion;
}

void quitarUltimoElemento(int orden, int vector[], int *ultimaPosicion){
    vector[*ultimaPosicion] = 0;
    --*ultimaPosicion;
}

void mostrarArreglo(int orden, int vector[]){
    printf("(");
    for (int i = 0; i < orden; i++){
        if (i == orden - 1)
            printf("%i)\n", vector[i]);
        else
            printf("%i, ", vector[i]);
    }
}