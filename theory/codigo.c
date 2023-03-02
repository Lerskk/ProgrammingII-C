#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// leerLineaStdin: Void -> Char*
// Lee los caracteres ingresados por la entrada estandar hasta que se ingrese un enter. Guarda el string leido en un array en memoria dinamica.
char *leerLineaStdin () {
    char *linea = malloc(0); // Inicializar array en memoria dinamica de 0 de largo
    int largo = 0;

    char c = getchar(); // Leer primer caracter
    while (c != '\n') { // Mientras no se ingrese un enter, seguir leyendo
        largo++; // Contar caracteres
        linea = realloc(linea, largo * sizeof(char)); // Solicitar mas memoria por cada caracter que se ingresa
        linea[largo - 1] = c; // Guardar caracter
        c = getchar(); // Leer un nuevo caracter
    }

    linea = realloc(linea, (largo+1) * sizeof(char)); // Solicitar mas memoria para el terminador
    linea[largo] = '\0'; // Guardar terminador

    return linea;
}

// generarPartida: FILE* -> Int -> Void
// Recibe el tamanio del tablero y el archivo donde se debe guardar la partida. Escribe en ese archivo un tablero generado de forma aleatoria.
void generarPartida (FILE *file, int tamanio) {
    fprintf(file, "DIMENSION\n%d\nTABLERO\n", tamanio); // Escribir dimension en el archivo

    srand(time(NULL)); // Inicializar generador de numeros aleatorios
    for (int i = 0; i < tamanio; i++) { // Iterar n veces (cantidad de filas)
        for (int j = 0; j < tamanio - 1; j++) { // Iterar n-1 veces (cantidad de columnas)
            int ficha = rand() % 3; // Generar numero aleatorio perteneciente a [0, 2]. Si sale 2 corresponde a una casilla vacia, si sale 0 o 1 corresponde al numero de jugador
            if (ficha == 2)
                fputc('_', file); // Escribir casilla vacia en el archivo
            else
                fprintf(file, "%d", ficha); // Escribir numero de jugador en el archivo
        }
        fputc('\n', file); // Pasar a una nueva fila
    }
}

int main() {
    int tamanio;

    printf("Ingrese el tamaño del tablero: ");
    scanf("%d", &tamanio); // Leer tamanio del tablero
    getchar(); // Leer el enter para que no interfiera con la lectura del nombre del archivo

    if (tamanio < 5) { // Validar tamanio del tablero
        printf("Error: El tamaño minimo del tablero es 5x4.\n");
        return 1;
    }

    printf("Ingrese el nombre del archivo a escribir: ");
    char *filename = leerLineaStdin();

    FILE *file = fopen(filename, "w"); // Abrir archivo de salida en modo escritura

    generarPartida(file, tamanio);

    fclose(file); // Cerrar archivo de salida

    return 0;
}