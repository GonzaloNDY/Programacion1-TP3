/*Ingresar los datos de N Instrumentos en un arreglo, luego mostrar todos los instrumentos
registrados ordenados por marca de forma ascendente.
Utilizar la siguiente estructura:
typedef struct{
int codigo; // Código del instrumento
char marca; // Solo la inicial
char modelo; // Solo la inicial
char frecuencia;
}instrumento;
Utilizar funciones para:
● Cargar el vector de instrumentos.
● Ordenar los instrumentos (arreglo unidimensional de instrumentos) por el campo marca.
● Mostrar el arreglo de instrumentos*/

#include <stdio.h>
#include <ctype.h>

#define MAX 50

typedef struct {
    int codigo; // Código del instrumento
    char marca; // Solo la inicial
    char modelo; // Solo la inicial
    char frecuencia;
} instrumento;

int controlOrdenMax();
char controlInicial();
void solicitarDatos(instrumento *instrumento, int posicion);
void mostrarInstrumento(instrumento instrumento, int posicion);
void cargarListaInstrumentos(instrumento lista[], int orden);
void ordenarListaInstrumentos(instrumento lista[], int orden);
void mostrarListaInstrumentos(instrumento lista[], int orden);

int main(int argc, char *argv[]){
    instrumento instrumentos[MAX];
    int orden;
    printf("\nIndique la cantidad de instrumentos que registrará: ");
    orden = controlOrdenMax();
    cargarListaInstrumentos(instrumentos, orden);
    ordenarListaInstrumentos(instrumentos, orden);
    printf("\nSe presentará un listado de los instrumentos ordenados por la marca:\n");
    mostrarListaInstrumentos(instrumentos, orden);
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
    return letra;
}

void solicitarDatos(instrumento *instrumento, int posicion){
    printf("\n\tDatos del %iº instrumento:\nCódigo: ", posicion);
    scanf("%i", &instrumento->codigo);
    printf("Inicial de la marca: ");
    instrumento->marca = controlInicial();
    printf("Inicial del modelo: ");
    instrumento->modelo = controlInicial();
    printf("Frecuencia: ");
    instrumento->frecuencia = controlInicial();
}

void mostrarInstrumento(instrumento instrumento, int posicion){
    printf("\n\tInstrumento nro %i\nCódigo: %i\nInicial de la marca: %c\n", posicion, instrumento.codigo, instrumento.marca);
    printf("Inicial del modelo: %c\nFrecuencia: %c\n", instrumento.modelo, instrumento.frecuencia);
}

void cargarListaInstrumentos(instrumento lista[], int orden){
    printf("\nIngrese los datos de los instrumentos que registrará:\n");
    for (int i = 0; i < orden; i++){
        solicitarDatos(&lista[i], i + 1);
    }
}

void ordenarListaInstrumentos(instrumento lista[], int orden){
    int indiceAuxiliar;
    instrumento valorActual;
    // Ordenamiento ascendente por inserción:
    for (int i = 1; i < orden; i++) {
        indiceAuxiliar = i - 1;
        valorActual = lista[i];  // Valor actual es el elemento actual que se insertará en su posicion correcta luego del while
        while (indiceAuxiliar >= 0 && lista[indiceAuxiliar].marca > valorActual.marca) {
        // Mientras el índice auxiliar sea válido y el elemento a la izquierda sea menor que el valor actual, desplazamos los elementos menores hacia la derecha
            lista[indiceAuxiliar + 1] = lista[indiceAuxiliar];
            indiceAuxiliar--;  // Decrementamos el índice auxiliar para seguir comparando hacia la izquierda
        }
        lista[indiceAuxiliar + 1] = valorActual;  // Insertamos el valor actual en la posición correcta encontrada
    }
}

void mostrarListaInstrumentos(instrumento lista[], int orden){
    for (int i = 0; i < orden; i++){
        mostrarInstrumento(lista[i], i + 1);
    }
}