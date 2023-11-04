/* Dado un arreglo de orden N, realizar un programa que permita ingresar números enteros a dicho
arreglo. Controlar que la cantidad de elementos ingresados no supere el orden permitido del
arreglo. Luego contar los elementos del arreglo que sean mayores a un número entero ingresado
por teclado. Finalmente, mostrar por pantalla el arreglo ingresado, el número ingresado y la
cantidad de elementos del arreglo que son mayores al número ingresado*/

#include <stdio.h>

int controlOrdenMaximo();
void cargarArreglo(int cantidad, int arreglo[]);
void controlNumeros(int cantidad, int arreglo[], int numControl, int *mayores);
void mostrarArreglo(int cantidad, int arreglo[]);

int main(int argc, char *argv[]){
    int ordenMaximo, numeros[50], numControl, numMayores = 0;
    printf("\nIndique la cantidad de números que se ingresarán en el arreglo(tiene que ser un valor positivo menor a 50): ");
    ordenMaximo = controlOrdenMaximo();
    printf("\n\tIngrese los números del arreglo\n");
    cargarArreglo(ordenMaximo, numeros);
    printf("\nIngrese un número para compararlo con los del arreglo: ");
    scanf("%i", &numControl);
    controlNumeros(ordenMaximo, numeros, numControl, &numMayores);
    printf("\nSe ingresaron %i números mayores que %i\n", numMayores, numControl);
    mostrarArreglo(ordenMaximo, numeros);
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

void controlNumeros(int cantidad, int arreglo[], int numControl, int *mayores){
    for (int i = 0; i < cantidad; i++){
        if (arreglo[i] > numControl)
            ++*mayores;
    }
}

void mostrarArreglo(int cantidad, int arreglo[]){
    printf("\nLos números ingresados fueron: %i", arreglo[0]);
    for (int i = 1; i < cantidad; i++){
        if (i == cantidad - 1){
            printf(" y %i\n", arreglo[i]);
        } else {
            printf(", %i", arreglo[i]);
        }
    }
}