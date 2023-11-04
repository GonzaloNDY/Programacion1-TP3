/*Se desea realizar un programa que permita ingresar en un arreglo los datos de N empleados, para
luego poder listarlos ordenados alfabéticamente por apellido en forma ascendente.
Utilizar funciones para:
● Cargar la lista de empleados.
● Solicitar los datos de un empleado en particular.
● Mostrar los datos de un empleado en particular.
● Ordenar la lista de empleados.
● Mostrar la lista de empleados.
Para cada elemento de la lista debe usar una estructura que contenga: la inicial del apellido, la inicial
del nombre y el número de documento. Al cargar cada empleado, la inicial del apellido y la inicial del
nombre deben ser caracteres alfabéticos y guardarse en mayúscula. No utilizar un arreglo auxiliar
para el ordenamiento.
Como sugerencia puede usar funciones con estas cabeceras:
void solicitarDatosEmpleado(datos *emp);
void mostrarDatosEmpleado(datos emp);
void cargarListaEmpleados(datos lista[], int numEmpleados);
void ordenarListaEmpleados(datos lista[], int numEmpleados);
void mostrarListaEmpleados(datos lista[], int numEmpleados);*/

#include <stdio.h>
#include <ctype.h>

#define MAX 50

typedef struct {
    char nombre, apellido;  //solo iniciales del nombre y del apellido
    int DNI;
} datos;

int controlOrdenMax();
char controlInicial();
void solicitarDatosEmpleado(datos *emp, int posicion);
void mostrarDatosEmpleado(datos emp, int posicion);
void cargarListaEmpleados(datos lista[], int numEmpleados);
void ordenarListaEmpleados(datos lista[], int numEmpleados);
void mostrarListaEmpleados(datos lista[], int numEmpleados);

int main(int argc, char *argv[]){
    datos empleados[MAX];
    int orden;
    printf("\nIndique la cantidad de empleados que registrará: ");
    orden = controlOrdenMax();
    cargarListaEmpleados(empleados, orden);
    ordenarListaEmpleados(empleados, orden);
    printf("\nSe presentará un listado de los empleados ordenados por el apellido:\n");
    mostrarListaEmpleados(empleados, orden);
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

char controlInicial(){
    char letra;
    do {
        fgetc(stdin);
        scanf("%c", &letra);
        if (!isalpha(letra))
            printf("La inicial ingresada debe ser una letra, ingrese una inicial válida: ");
    } while (!isalpha(letra));
    letra = toupper(letra);
    return letra;
}

void solicitarDatosEmpleado(datos *emp, int posicion){
    printf("\n\tDatos del %iº empleado:\nInicial del apellido: ", posicion);
    emp->apellido = controlInicial();
    printf("Inicial del nombre: ");
    emp->nombre = controlInicial();
    printf("DNI: ");
    scanf("%i", &emp->DNI);
}

void mostrarDatosEmpleado(datos emp, int posicion){
    printf("\n\tEmpleado nro %i\nInicial del apellido: %c\n", posicion, emp.apellido);
    printf("Inicial del nombre: %c\nDNI: %i\n", emp.nombre, emp.DNI);
}

void cargarListaEmpleados(datos lista[], int numEmpleados){
    printf("\nIngrese los datos de los empleados que registrá:\n");
    for (int i = 0; i <numEmpleados; i++) {
        solicitarDatosEmpleado(&lista[i], i + 1);
    }
}

void ordenarListaEmpleados(datos lista[], int numEmpleados){
    int indiceAuxiliar;
    datos valorActual;
    // Ordenamiento ascendente por inserción:
    for (int i = 1; i < numEmpleados; i++) {
        indiceAuxiliar = i - 1;
        valorActual = lista[i];  // Valor actual es el elemento actual que se insertará en su posicion correcta luego del while
        while (indiceAuxiliar >= 0 && lista[indiceAuxiliar].apellido > valorActual.apellido) {
        // Mientras el índice auxiliar sea válido y el elemento a la izquierda sea menor que el valor actual, desplazamos los elementos menores hacia la derecha
            lista[indiceAuxiliar + 1] = lista[indiceAuxiliar];
            indiceAuxiliar--;  // Decrementamos el índice auxiliar para seguir comparando hacia la izquierda
        }
        lista[indiceAuxiliar + 1] = valorActual;  // Insertamos el valor actual en la posición correcta encontrada
    }
}

void mostrarListaEmpleados(datos lista[], int numEmpleados){
    for (int i = 0; i < numEmpleados; i++){
        mostrarDatosEmpleado(lista[i], i + 1);
    }
}