/*Con el arreglo del ejercicio anterior, implementar una función para mostrar los instrumentos
agrupados por frecuencia de calibración. Deberá solicitar al usuario que ingrese, mediante un
submenú, qué frecuencia de calibración desea consultar, puede ser A-ANUAL, B-SEMESTRAL,
C-TRIMESTRAL y luego mostrar por pantalla todos los instrumentos que corresponden a la misma.
Utilizar funciones para:
● La lectura de la frecuencia por la cual agrupar.
● Buscar todos los instrumentos que corresponden a una frecuencia ingresada.
Como sugerencia puede usar una función con esta cabecera:
void mostrarInstrumentosPorFrec(instrumento lista[], int orden, char frec);*/

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
void cargarListaInstrumentos(instrumento lista[], int orden);
void mostrarInstrumento(instrumento instrumento);
void mostrarInstrumentosPorFrec(instrumento lista[], int orden, char frec);

int main(int argc, char *argv[]){
    instrumento instrumentos[MAX];
    int orden;
    char frecuenciaConsultada;
    printf("\nIndique la cantidad de instrumentos que registrará: ");
    orden = controlOrdenMax();
    cargarListaInstrumentos(instrumentos, orden);
    printf("\nIngrese la frecuencia de calibración que desea consultar (A=anual, B=semestral, C=trimestral): ");
    frecuenciaConsultada = controlInicial();
    while (frecuenciaConsultada != 'A' && frecuenciaConsultada != 'B' && frecuenciaConsultada != 'C'){
        printf("Tiene que ingresar una de las opciones anteriores (A=anual, B=semestral, C=trimestral): ");
        frecuenciaConsultada = controlInicial();
    }
    printf("\nA continuación se mostrarán los instrumentos con una frecuencia de calibración igual a la buscada:\n ");
    mostrarInstrumentosPorFrec(instrumentos, orden, frecuenciaConsultada);
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

void solicitarDatos(instrumento *instrumento, int posicion){
    printf("\n\tDatos del %iº instrumento:\nCódigo: ", posicion);
    scanf("%i", &instrumento->codigo);
    printf("Inicial de la marca: ");
    instrumento->marca = controlInicial();
    printf("Inicial del modelo: ");
    instrumento->modelo = controlInicial();
    printf("Frecuencia de calibración (A: anual, B: semestral, C: trimestral): ");
    instrumento->frecuencia = controlInicial();
    while (instrumento->frecuencia != 'A' && instrumento->frecuencia != 'B' && instrumento->frecuencia != 'C'){
        printf("Tiene que ingresar una de las opciones anteriores (A=anual, B=semestral, C=trimestral): ");
        instrumento->frecuencia = controlInicial();
    }
}

void cargarListaInstrumentos(instrumento lista[], int orden){
    printf("\nIngrese los datos de los instrumentos que registrará:\n");
    for (int i = 0; i < orden; i++){
        solicitarDatos(&lista[i], i + 1);
    }
}

void mostrarInstrumento(instrumento instrumento){
    printf("\nCódigo del instrumento: %i\nInicial de la marca: %c\n", instrumento.codigo, instrumento.marca);
    printf("Inicial del modelo: %c\nFrecuencia de calibración: %c\n", instrumento.modelo, instrumento.frecuencia);
}

void mostrarInstrumentosPorFrec(instrumento lista[], int orden, char frec){
    for (int i = 0; i < orden; i++){
        if (frec == lista[i].frecuencia)
            mostrarInstrumento(lista[i]);
    }
}