/* Modificar el programa anterior agregando un menú para realizar las diferentes operaciones:
● Cargar el arreglo con la recaudación de la semana de cada empleado pero ahora
controlando que los valores de la recaudación de la semana sean valores positivos.
● Mostrar el arreglo.
● Calcular y mostrar la recaudación semanal de un empleado en particular.
● Calcular cuál fue el día de la semana que más recaudó y el monto*/

#include <stdio.h>

#define MAX_EMPLEADOS 500
#define MAX_DIAS 6

int controlOrdenMax();
float controlPositivo();
void cargarMatriz(int ordenI, int ordenJ, float recaudacionEmpleados[MAX_EMPLEADOS][MAX_DIAS]);
void mostrarMatriz(int ordenI, int ordenJ, float recaudacionEmpleados[MAX_EMPLEADOS][MAX_DIAS]);
float recaudacionTotalE(int ordenJ, float recaudacionEmpleados[MAX_EMPLEADOS][MAX_DIAS], int empleado);
int obtenerDiaMayorRecaudacion(int ordenJ, int ordenI, float recaudacionEmpleados[MAX_EMPLEADOS][MAX_DIAS], float *recaudacionTotalDia);

int main(){
    int empleados, unEmpleado, diaMayorRecaudacion;
    float recaudacionEmpleados[MAX_EMPLEADOS][MAX_DIAS], recaudacionEmpleado, recaudacionDia;

    printf("\nIngrese la cantidad de empleados que registrará: ");
    empleados = controlOrdenMax();

    cargarMatriz(empleados, MAX_DIAS, recaudacionEmpleados);
    printf("\n\t\tLunes\tMartes\tMierc.\tJueves\tViernes\tSábado\n");

    mostrarMatriz(empleados, MAX_DIAS, recaudacionEmpleados);

    printf("\nIndique el número del empleado al que se le calculará la recaudación total: ");
    scanf("%i", &unEmpleado);

    recaudacionEmpleado = recaudacionTotalE(MAX_DIAS, recaudacionEmpleados, unEmpleado);
    printf("\nEl empleado nro %i recaudó un total de $ %.2f\n", unEmpleado, recaudacionEmpleado);

    diaMayorRecaudacion = obtenerDiaMayorRecaudacion(MAX_DIAS, empleados, recaudacionEmpleados, &recaudacionDia);
    printf("\nEl dia de la semaná que mas se recaudó fue el %i, con una recaudación total de $ %.2f\n", diaMayorRecaudacion, recaudacionDia);

    return 0;
}

int controlOrdenMax(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 1 || num > 100)
            printf("El valor ingresado debe ser mayor a uno y menor a 100, intente nuevamente: ");
    } while (num < 1 || num > 100);
    return num;
}

float controlPositivo(){
    float num;
    do {
        scanf("%f", &num);
        if (num < 0)
            printf("El valor ingresado debe ser mayor a cero, intente nuevamente: ");
    } while (num < 0);
    return num;
}

void cargarMatriz(int ordenI, int ordenJ, float recaudacionEmpleados[MAX_EMPLEADOS][MAX_DIAS]){
    for (int i = 0; i < ordenI; i++){
        printf("\n\tEmpleado %i:\n", i + 1);
        for (int j = 0; j < ordenJ; j++){
            printf("Recaudacion del dia %i: ", j + 1);
            recaudacionEmpleados[i][j] = controlPositivo();
        }
        printf("\n");
    }
}

void mostrarMatriz(int ordenI, int ordenJ, float recaudacionEmpleados[MAX_EMPLEADOS][MAX_DIAS]){
    for (int i = 0; i < ordenI; i++){
        printf("\nEmpleado %i:", i + 1);
        for (int j = 0; j < ordenJ; j++){
            printf("\t%.2f", recaudacionEmpleados[i][j]);
        }
        printf("\n");
    }
}

float recaudacionTotalE(int ordenJ, float recaudacionEmpleados[MAX_EMPLEADOS][MAX_DIAS], int empleado){
    float recaudacionTotalE = 0;
    for (int j = 0; j < ordenJ; j++){
        recaudacionTotalE += recaudacionEmpleados[empleado - 1][j];
    }
    return recaudacionTotalE;
}

int obtenerDiaMayorRecaudacion(int ordenJ, int ordenI, float recaudacionEmpleados[MAX_EMPLEADOS][MAX_DIAS], float *recaudacionTotalDia){
    int indiceDelDia;
    float mayorRecaudacion = 0;
    float recaudacionDia = 0;
    for (int j = 0; j < ordenJ; j++){
        recaudacionDia = 0;
        for (int i = 0; i < ordenI; i++){
            recaudacionDia += recaudacionEmpleados[i][j];
        }
        if (recaudacionDia > mayorRecaudacion){
                mayorRecaudacion = recaudacionDia;
                indiceDelDia = j + 1;
            }
    }
    *recaudacionTotalDia = mayorRecaudacion;
    return indiceDelDia;
}