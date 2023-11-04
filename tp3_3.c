/*Realizar un programa que permita cargar un arreglo cuyos elementos sean N números de punto
flotante y luego permita presentarlo por pantalla.*/

#include <stdio.h>

int controlOrdenMaximo();
void cargarNumeros(int cantMaxima, float arreglo[]);
void mostrarArreglo(int cantidad, float numDecimales[]);

int main(int argc, char *argv[]){
    float numDecimales[50];
    int orden;
    printf("\nIndique la cantidad de números que ingresará (debe ser un valor menor a 50): ");
    orden = controlOrdenMaximo();
    cargarNumeros(orden, numDecimales);
    mostrarArreglo(orden, numDecimales);
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

void cargarNumeros(int cantMaxima, float arreglo[]){
    printf("\n\tA continuación ingrese los números decimales que se guardarán\n");
    for (int i = 0; i < cantMaxima; i++){
        printf("%iº decimal: ", i + 1);
        scanf("%f",&arreglo[i]);
    }
}

void mostrarArreglo(int cantidad, float numDecimales[]){
    printf("los números ingresados fueron: ");
    for (int i = 0; i < cantidad; i++){
        if (i == cantidad - 1){
            printf("%.1f\n", numDecimales[i]);
        } else
            printf("%.1f, ", numDecimales[i]);
    }
}