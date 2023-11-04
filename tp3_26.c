/*Los datos de un televisor se almacenan usando la siguiente estructura:
typedef struct{
char marca;
float precio;
int cantidad;
}televisores;
Realizar un programa que permita ingresar los datos de N televisores en un vector. Presentar por
pantalla el vector y luego permitir la modificación del precio en los casos en donde exista
coincidencia entre una inicial de una marca ingresada por teclado y la inicial registrada para el
televisor. Al realizar la búsqueda:
Si no existe en el vector un elemento con esa inicial presentar por pantalla el mensaje
correspondiente.
Si se encuentra coincidencia (una o más), se solicitará el ingreso del nuevo precio. Se debe presentar
por pantalla el contenido de dicho vector antes y después de la modificación.
Utilizar funciones para:
● Almacenar los datos de los televisores en el vector. Se sugiere además el uso de una
función para solicitar los datos de cada televisor.
● Realizar la búsqueda de las coincidencias y si es que hubiera, realizar el reemplazo del
valor del precio.
● Mostrar el vector de televisores*/

#include <stdio.h>

#define MAX 50

typedef struct {
    char marca;
    float precio;
    int cantidad;
} televisores;

int controlOrdenMax();
void ingresoDatos(int posicion, televisores *equipo);
void ingresoTVs(int orden, televisores vectorDeTVs[]);
void modificarPrecioPorMarca(int orden, televisores vectorDeTVs[], char marcaBuscada);
void presentacionDatos(televisores equipo[], int posicion);
void presentacionTVs(int orden, televisores equipos[]);

int main(int argc, char *argv[]){
    int ordenMax;
    televisores vectorDeTVs[MAX];
    char marcaBuscada;
    printf("\nPrimero indique la cantidad máxima de televisores que se ingresarán (debe ser un valor positivo y menor a 50): ");
    ordenMax = controlOrdenMax();
    ingresoTVs(ordenMax, vectorDeTVs);
    printf("\nA continuación se mostraran los datos de los televisores ingresados:\n");
    presentacionTVs(ordenMax, vectorDeTVs);
    printf("\nIngrese la inicial de la marca que modificará su precio: ");
    fgetc(stdin);
    scanf("%c", &marcaBuscada);
    modificarPrecioPorMarca(ordenMax, vectorDeTVs, marcaBuscada);
    printf("\nA continuación se mostraran los datos de los televisores luego de modificar los precios de las TV de marca %c:\n", marcaBuscada);
    presentacionTVs(ordenMax, vectorDeTVs);
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

void ingresoDatos(int posicion, televisores *equipo){
    printf("\n\tDatos de la %iº TV:\nMarca: ", posicion + 1);
    fgetc(stdin);
    scanf("%c", &(equipo->marca));
    printf("Precio: ");
    scanf("%f", &(equipo->precio));
    printf("Stock disponible: ");
    scanf("%i", &(equipo->cantidad));
}

void ingresoTVs(int orden, televisores vectorDeTVs[]){
    printf("Ingrese los datos de los televisores a registrar:\n");
    for (int i = 0; i < orden; i++) {
        ingresoDatos(i, &vectorDeTVs[i]);
    }
}

void modificarPrecioPorMarca(int orden, televisores vectorDeTVs[], char marcaBuscada){
    int cantCoincidencias = 0;
    float nuevoPrecio;
    for (int i = 0; i < orden; i++){
        if (marcaBuscada == vectorDeTVs[i].marca){
            cantCoincidencias++;
            if (cantCoincidencias == 1){
                printf("\nIngrese el nuevo precio para la marca de TV \"%c\": ", vectorDeTVs[i].marca);
                scanf("%f", &nuevoPrecio);
            }
            vectorDeTVs[i].precio = nuevoPrecio;
        }
    }
    if (cantCoincidencias == 0)
        printf("\nNo se encontraron marcas con esa inicial\n");
}

void presentacionDatos(televisores equipo[], int posicion){
    printf("\n\t1º TV\nTVMarca: %c\n", equipo[posicion].marca, posicion + 1);
    printf("Precio: $%.2f\nStock disponible: %i\n", equipo[posicion].precio, equipo[posicion].cantidad);
}

void presentacionTVs(int orden, televisores equipos[]){
    for (int i = 0; i < orden; i++){
        presentacionDatos(equipos, i);
    }
}