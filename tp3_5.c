/*Dado un arreglo de orden N, realizar un programa que permita ingresar números enteros a dicho
arreglo. Controlar que la cantidad de elementos ingresados no supere el orden permitido del
arreglo. Luego mostrar por pantalla el arreglo ingresado, el valor del promedio de los elementos
ingresados, la cantidad de elementos ingresados que son mayores al promedio y la cantidad de
elementos ingresados que sean menores al promedio.*/

#include <stdio.h>

int controlOrdenMaximo();
void cargarArreglo(int cantidad, int arreglo[]);
void promedioNumeros(int cantidad, int arreglo[], float *promedio);
void controlNumeros(int cantidad, int arreglo[], float promedio, int *mayores, int *menores);

int main(int argc, char *argv[]){
    int ordenMaximo, numeros[50], numMayores = 0, numMenores = 0;
    float promedio;
    printf("\nIndique la cantidad de números que se ingresarán (tiene que ser un valor positivo menor a 50): ");
    ordenMaximo = controlOrdenMaximo();
    printf("\n\tIngrese los números a controlar\n");
    cargarArreglo(ordenMaximo, numeros);
    promedioNumeros(ordenMaximo, numeros, &promedio);
    printf("\nEl promedio de los %i números ingresados es %.1f", ordenMaximo, promedio);
    controlNumeros(ordenMaximo, numeros, promedio, &numMayores, &numMenores);
    printf("\nSe ingresaron %i números mayores al promedio y %i números menores al promedio\n", numMayores, numMenores);
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

void cargarArreglo(int cantidad, int arreglo[]){
    for (int i = 0; i < cantidad; i++){
        printf("%iº número: ", i + 1);
        scanf("%i", &arreglo[i]);
    }
}

void promedioNumeros(int cantidad, int arreglo[], float *promedio){
    for (int i = 0; i < cantidad; i++){
        *promedio += arreglo[i];
    }
    *promedio /= cantidad;
}

void controlNumeros(int cantidad, int arreglo[], float promedio, int *mayores, int *menores){
    for (int i = 0; i < cantidad; i++){
        if (arreglo[i] > promedio){
            ++*mayores;
        } else {
            ++*menores;
        }
    }
}