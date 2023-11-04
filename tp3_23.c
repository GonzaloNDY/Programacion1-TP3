/*Realizar un programa que permita ingresar los datos de las fechas de nacimiento de una cantidad N
personas en un arreglo de estructuras. Luego presentar el arreglo por pantalla. Resolver el ejercicio
sin utilizar funciones para la carga y presentación por pantalla del arreglo correspondiente. Utilizar
funciones únicamente para la carga y presentación de cada estructura. Los campos de la estructura
deben almacenar los siguientes datos: día, mes, año y nombre (inicial):
typedef struct{
int dia, mes, anio;
char nombre;
}datos;*/

#include <stdio.h>

#define MAX 50

typedef struct{
    int dia, mes, anio;
    char nombre;  //inicial del nombre
} datos;

int controlOrdenMax();
datos ingresoDatos(int posicion);
void presentacionDatos(datos unaPersona, int posicion);

int main(int argc, char *argv[]){
    int ordenMax;
    datos personas[MAX];
    printf("\nPrimero indique la cantidad máxima de personas que se registrarán (debe ser un valor positivo y menor a 50): ");
    ordenMax = controlOrdenMax();
    for (int i = 0; i < ordenMax; i++){
        personas[i] = ingresoDatos(i);
    }
    for (int i = 0; i < ordenMax; i++){
        presentacionDatos(personas[i], i);
    }
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

datos ingresoDatos(int posicion){
    datos datosIngresados;
    int diasPorMes;
    printf("\n\t%iº persona:\nFecha de nacimiento\nAño: ", posicion + 1);
    scanf("%i", &datosIngresados.anio);
    if (datosIngresados.anio < 1900){
        do {
            printf("Ingrese un año válido (tiene que ser mayor a 1900): ");
            scanf("%i", &datosIngresados.anio);
        } while (datosIngresados.anio < 1900);
    }
    printf("Mes: ");
    scanf("%i", &datosIngresados.mes);
    if (datosIngresados.mes < 1 || datosIngresados.mes > 12){
        do {
            printf("Ingrese un mes valido: ");
            scanf("%i", &datosIngresados.mes);
        } while (datosIngresados.mes < 1 || datosIngresados.mes > 12);
    }
    switch (datosIngresados.mes){
        case 1:  //Enero
        case 3:  //Marzo
        case 5:  //Mayo
        case 7:  //Julio
        case 8:  //Agosto
        case 10: //Octubre    
        case 12: //Diciembre
            diasPorMes = 31;
            break;
        case 4:  //Abril
        case 6:  //Junio
        case 9:  //Septiembre
        case 11: //Noviembre
            diasPorMes = 30;    
            break;
        case 2:  //Febrero
            if (datosIngresados.anio % 400 == 0 && datosIngresados.anio % 4 == 0){
                diasPorMes = 29;
            } else {
                diasPorMes = 28;
            }
            break;
    }
    printf("Dia: ");
    scanf("%i", &datosIngresados.dia);
    if (datosIngresados.dia <1 || datosIngresados.dia > diasPorMes){
        do {
            printf("Ingrese un dia válido: ");
            scanf("%i", &datosIngresados.dia);
        } while (datosIngresados.dia < 1 || datosIngresados.dia > diasPorMes);
    }
    printf("Inicial del nombre: ");
    fgetc(stdin);
    scanf("%c", &datosIngresados.nombre);
    return datosIngresados;
}

void presentacionDatos(datos unaPersona, int posicion){
    printf("\n\tDatos de la %iº persona:\n", posicion + 1);
    printf("Nombre: %c\nfecha de nacimiento: %i/%i/%i\n", unaPersona.nombre, unaPersona.dia, unaPersona.mes, unaPersona.anio);
}