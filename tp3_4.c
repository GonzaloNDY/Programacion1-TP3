/*Cargar caracteres en un arreglo de orden N. Luego contabilizar cuántos caracteres del arreglo son
alfabéticos, cuántos son dígitos y cuántos de otras categorías*/

#include <stdio.h>
#include <ctype.h>

int controlOrdenMaximo();
void cargarCaracteres(int cantMaxima, char caracteres[]);
void controlTipoCaracter(char caracteres[], int cantidad, int *cantL, int *cantD, int *cantOtros);

int main(int argc, char *argv[]){
    int cantidad, cantLetras = 0, cantDigitos = 0, cantOtros = 0;
    char caracteres[50];
    printf("\nIndique la cantidad de caracteres que se ingresarán (tiene que ser un valor positivo menor a 50): ");
    cantidad = controlOrdenMaximo();
    printf("Ingrese los caracteres a controlar: ");
    cargarCaracteres(cantidad, caracteres);
    controlTipoCaracter(caracteres, cantidad, &cantLetras, &cantDigitos, &cantOtros);
    printf("\nSe ingresaron %i letras, %i dígitos y %i caracteres de otro tipo\n", cantLetras, cantDigitos, cantOtros);
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

void cargarCaracteres(int cantMaxima, char caracteres[]){
    printf("\n\tA continuación ingrese los caracteres que se guardarán\n");
    for (int i = 0; i < cantMaxima; ++i){
        fgetc(stdin);
        printf("%iº caracter: ", i + 1);
        scanf("%c",&caracteres[i]);
    }
}

void controlTipoCaracter(char caracteres[], int cantidad, int *cantL, int *cantD, int *cantOtros){
    for (int i = 0; i < cantidad; i++){
        if (isalpha(caracteres[i])){
            ++*cantL;
        } else if (isdigit(caracteres[i])){
            ++*cantD;
        } else {
            ++*cantOtros;
        }
    }
}