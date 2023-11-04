/*Se desea mantener en una tabla la lista de empleados y la recaudación semanal de cada uno de
ellos, considerando los días de lunes a sábado, como se muestra en el ejemplo. Realizar un
programa para poder cargar la recaudación de la semana de cada empleado y luego poder
consultarla. Utilizar un arreglo bidimensional de orden M x N de números reales, donde M
representa la cantidad de empleados y N representa los días.
Ejemplo para 4 empleados:
            Lunes    Martes   Miérc.  Jueves   Viernes  Sábado
Empleado 1 5125,00  1234,40  345,00  12345,00  0,00     12345,00
Empleado 2 5125,00  4234,40  345,00  1864,40   0,00     1245,00
Empleado 3 4234,40  1864,40  2300,00 2300,00   0,00     2345,00
Empleado 4 5125,00  135,40   345,00  2300,76   0,00     7345,00 */

#include <stdio.h>

#define MAXempleados 100
#define MAXdias 7

int controlOrdenMax();
void cargarMatriz(float empleados, float dias, float recaudacionEmpleados[MAXempleados][MAXdias]);
void mostrarMatriz(float empleados, float dias, float recaudacionEmpleados[MAXempleados][MAXdias]);

int main(float argc, char *argv[]){
    int empleados, dias = 6; // Dias de lunes a sábado
    float recaudacionEmpleados[MAXempleados][MAXdias];
    printf("\nIngrese la cantidad de empleados que registrará: ");
    empleados = controlOrdenMax();
    // Carga de la matriz recaudacionEmpleados:
    cargarMatriz(empleados, dias, recaudacionEmpleados);
    // Presentacion de la matriz recaudacionEmpleados:
    printf("\n\t  Lunes\tMartes\tMierc.\tJueves\tViernes\tSábado\n");
    mostrarMatriz(empleados, dias, recaudacionEmpleados);
    return 0;
}

int controlOrdenMax(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0 || num > 50)
            printf("El valor ingresado debe ser mayor a uno y menor a 50, intente nuevamente: ");
    } while (num < 1 || num > 50);
    return num;
}

void cargarMatriz(float empleados, float dias, float recaudacionEmpleados[MAXempleados][MAXdias]){
    for (int i = 0; i < empleados; i++){
        printf("\n\tEmpleado %i:\n", i + 1);
        for (int j = 0; j < dias; j++){
            printf("Recaudacion del dia %i: ", j + 1);
            scanf("%f", &recaudacionEmpleados[i][j]);
        }
        printf("\n");
    }
}

void mostrarMatriz(float empleados, float dias, float recaudacionEmpleados[MAXempleados][MAXdias]){
    for (int i = 0; i < empleados; i++){
        printf("\nEmpleado %i:", i + 1);
        for (int j = 0; j < dias; j++){
            printf("\t%.2f", recaudacionEmpleados[i][j]);
        }
        printf("\n");
    }
}