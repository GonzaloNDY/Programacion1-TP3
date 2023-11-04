/*Ingresar los datos de una cierta cantidad de monitores en un arreglo de estructuras. Luego,
presentar por pantalla los datos de los monitores en donde el precio sea menor o igual a un precio
de búsqueda ingresado por teclado. Los campos de la estructura deben almacenar los siguientes
datos: inicial de la marca, precio y cantidad en stock:
typedef struct{
char marca;
float precio;
int stock;
}monitores;
Utilizar funciones para:
● Controlar que el orden del arreglo sea un entero positivo y menor que el valor máximo
de elementos que pueden contener el arreglo.
● Solicitar al usuario los datos de cada uno de los monitores.
● Cargar el arreglo que contiene los monitores llamando a la función del ítem anterior.
● Presentar por pantalla los datos de cada monitor.
● Buscar y presentar por pantalla los datos de los monitores que cumplan que su precio
sea menor o igual a un precio de búsqueda ingresado por teclado*/

#include <stdio.h>

#define MAX 50

typedef struct {
    char marca;  //inicial de la marca
    float precio;
    int stock;
} monitores;

int controlOrdenMax();
void ingresoDatos(int posicion, monitores *equipo);
void ingresoTVs(int orden, monitores vectorDeMonitores[]);
void presentacionDatos(monitores equipo[], int posicion);
void presentacionMonitores(int orden, monitores equipos[], int precioMaximo);

int main(int argc, char *argv[]){
    int ordenMax;
    float precioMaximo;
    monitores equipos[MAX];
    printf("\nPrimero indique la cantidad máxima de monitores que se ingresarán (debe ser un valor positivo y menor a 50): ");
    ordenMax = controlOrdenMax();
    ingresoMonitores(ordenMax, equipos);
    printf("\nIngrese un precio máximo para iniciar la busqueda de monitores: ");
    scanf("%f", &precioMaximo);
    presentacionMonitores(ordenMax, equipos, precioMaximo);
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

void ingresoDatos(int posicion, monitores *equipo){
    printf("\n\tDatos de la %iº TV:\nMarca: ", posicion + 1);
    fgetc(stdin);
    scanf("%c", &(equipo->marca));
    printf("Precio: ");
    scanf("%f", &(equipo->precio));
    printf("Stock disponible: ");
    scanf("%i", &(equipo->stock));
}

void ingresoTVs(int orden, monitores vectorDeMonitores[]){
    printf("Ingrese los datos de los monitores a registrar:\n");
    for (int i = 0; i < orden; i++) {
        ingresoDatos(i, &vectorDeMonitores[i]);
    }
}

void presentacionDatos(monitores equipo[], int posicion){
    printf("\nMarca del monitor: %c\n", equipo[posicion].marca);
    printf("Precio del monitor: $%.2f\nStock disponible: %i\n", equipo[posicion].precio, equipo[posicion].stock);
}

void presentacionMonitores(int orden, monitores equipos[], int precioMaximo){
    printf("\nA continuación se mostraran los datos de los monitores con un precio menor o igual al que indicó anteriormente:\n");
    for (int i = 0; i < orden; i++){
        if (equipos[i].precio <= precioMaximo)
            presentacionDatos(equipos, i);
    }
}