#!/usr/bin/python3

# TABLERO es List[List[String]]

# leerPartida: String -> Tuple[TABLERO, Int]
# La funcion recibe el nombre de un archivo, lo abre en modo lectura y devuelve una tupla con el tablero y su tamanio
def leerPartida(filename):
    file = open(filename, "r") # Abrir archivo en modo lectura

    lines = file.readlines() # Leer todas las lineas

    tamanio = int(lines[1].strip()) # Sacar "\n" a la segunda linea (mediante el metodo strip()) y transformarlo a int para obtener el tamanio

    tablero = []
    for line in lines[3:tamanio+3]: # Recorrer filas 3 a 3+tamanio (las que corresponden al tablero)
        fila = list(line.strip()) # Sacar el enter a cada linea y usar la funcion list() para obtener una lista con sus caracteres. Esta lista representa una fila del tablero
        tablero.append(fila) # Agregar la fila al tablero
    
    return (tablero, tamanio) # Devolver tupla con tablero y tamanio

# calcularDiferenciaFichas: TABLERO -> Int
# Recibe el tablero, cuenta cuantas fichas hay de cada jugador en el mismo y devuelve la diferencia.
def calcularDiferenciaFichas(tablero):
    # Inicializar contadores
    cantidad0 = 0
    cantidad1 = 0

    for fila in tablero: # Recorrer cada fila del tablero
        for casilla in fila: # Recorrer cada casilla de la fila
            # Contar fichas
            if casilla == "0":
                cantidad0 += 1
            elif casilla == "1":
                cantidad1 += 1
    
    dif = abs(cantidad1 - cantidad0) # Calcular valor absoluto de la diferencia entre las cantidades
    return dif
    
# verificarFichasFlotantes: TABLERO -> Int
# Recibe un tablero y verifica que no haya fichas flotantes (casillas distintas de "_" que tienen una casilla con "_" debajo). Devuelve el numero de columna en el que se encontraron las fichas flotantes o -1 si no se encontro ninguna
def verificarFichasFlotantes(tablero, tamanio):
    columnaFichaFlotante = -1 # Si no se encuentra ninguna ficha flotante, esta variable seguira siendo -1 y se devolvera ese valor

    for columna in range(tamanio-1): # Recorrer por columnas
        encontroFichaVacia = False # Reiniciar bandera por cada columna

        for fila in range(tamanio-1, -1, -1): # Recorrer fichas de la columna de abajo hacia arriba
            if tablero[fila][columna] == "_": # Una vez encontrada una casilla vacia, lo marco para saber que en lo que resta de la fila, dado que recorro de abajo hacia arriba, no deberia haber ninguna casilla no vacia
                encontroFichaVacia = True
            elif encontroFichaVacia: # Si se encuentra una casilla no vacia y ya se habia encontrado una casilla vacia, entonces la casilla actual tiene una ficha flotante y guardo la columna
                columnaFichaFlotante = columna
    
    return columnaFichaFlotante

# verificarGanadoresLista: List[String] -> Dict[String, Int]
# Recibe una lista (que podria representar una fila, columna o diagonal) y devuelve un diccionario indicando cuantas veces gano cada jugador dentro de esa lista.
def verificarGanadoresLista(lista):
    # Inicializar diccionario
    ganadores = {
        "0": 0,
        "1": 0
    }

    jugadorAnterior = None
    cantidad = 0
    for casilla in lista:
        if casilla != jugadorAnterior: # Dado que las 4 o mas fichas deben estar en forma consecutiva, si cambia el jugador de una casilla a la siguiente, reiniciamos el conteo
            cantidad = 0
            jugadorAnterior = casilla
        cantidad += 1

        if cantidad == 4: # Si se encontraron 4 fichas seguidas del mismo jugador, significa que gano
            ganadores[casilla] += 1
        
    return ganadores

# obtenerColumnas: TABLERO -> Int -> List[List[String]]
# Recibe un tablero y su tamanio. Devuelve una lista con las columnas del tablero. Cada columna esta representada por una lista de strings, siendo cada string una casilla del tablero.
def obtenerColumnas(tablero, tamanio):
    columnas = []

    for nroColumna in range(tamanio-1): # Recorrer por columnas
        columna = []
        for nroFila in range(tamanio): # Recorrer filas
            columna.append(tablero[nroFila][nroColumna]) # Agregar cada casilla de la columna a una lista
        columnas.append(columna) # Agregar cada columna a la lista de columnas
    
    return columnas

# obtenerDiagonales: TABLERO -> Int -> List[List[String]]
# Recibe un tablero y su tamanio. Devuelve una lista con las diagonales del tablero. Cada diagonal esta representada por una lista de strings, siendo cada string una casilla del tablero.
def obtenerDiagonales(tablero, tamanio):
    diagonales = []

    # Recorrer filas empezando desde filas negativas. Esto sirve para alcanzar todas las diagonales del tablero, ya que la variable filaInicial se refiere a la fila de la casilla en la que empieza la diagonal (casilla pegada a un borde), pero no siempre esta dento del tablero. Por ejemplo, si tomamos en cuenta en el siguiente tablero formado unicamente por las letras mayusculas (las minusculas son para referencia nada mas), si yo quisiera obtener la diagonal ["B", "F"], la puedo pensar como la diagonal ["m", "B", "F"] (sacando la "m"), que empieza en la fila -1:
    # Fila -1: m n o
    # Fila  0: A B C
    # Fila  1: D E F
    # Fila  2: G H I
    # Fila  3: J K L
    for filaIncial in range(-(tamanio-2), tamanio):
        # Diagonal hacia abajo a la derecha
        diagonal = []
        fila = filaIncial
        columna = 0 # Empezar desde la izquierda
        while fila < tamanio and columna < tamanio-1: # Mientras no se salga de los bordes del tablero
            if (fila >= 0): # Si la casilla esta realmente dentro del tablero, agregarla a la diagonal
                diagonal.append(tablero[fila][columna])
            fila += 1 # Recorrer hacia abajo
            columna += 1 # Recorrer hacia la izquierda
        diagonales.append(diagonal) # Agregar diagonal resultante a la lista de diagonales

        # Diagonal hacia abajo a la izquierda
        diagonal = []
        fila = filaIncial
        columna = tamanio - 2 # Empezar desde la derecha
        while fila < tamanio and columna >= 0: # Mientras no se salga de los bordes del tablero
            if (fila >= 0): # Si la casilla esta realmente dentro del tablero, agregarla a la diagonal
                diagonal.append(tablero[fila][columna])
            fila += 1 # Recorrer hacia abajo
            columna -= 1 # Recorrer hacia la izquierda
        diagonales.append(diagonal) # Agregar diagonal resultante a la lista de diagonales
    
    return diagonales

# verificarGanadores: TABLERO -> Int -> Dict[String, Int]
# Recibe un tablero y su tamanio. Devuelve un diccionario indicando cuantas veces gano cada jugador segun el tablero dado.
def verificarGanadores(tablero, tamanio):
    # Inicializar diccionario
    ganadores = {
        "0": 0,
        "1": 0
    }

    for fila in tablero: # Verificar cada fila
        ganadoresFila = verificarGanadoresLista(fila)
        # Sumar ganadores de la fila al diccionario general
        ganadores["0"] += ganadoresFila["0"]
        ganadores["1"] += ganadoresFila["1"]
    
    for columna in obtenerColumnas(tablero, tamanio): # Verificar cada columna
        ganadoresColumna = verificarGanadoresLista(columna)
        # Sumar ganadores de la columna al diccionario general
        ganadores["0"] += ganadoresColumna["0"]
        ganadores["1"] += ganadoresColumna["1"]

    for diagonal in obtenerDiagonales(tablero, tamanio): # Verificar cada diagonal
        ganadoresDiagonal = verificarGanadoresLista(diagonal)
        # Sumar ganadores de la diagonal al diccionario general
        ganadores["0"] += ganadoresDiagonal["0"]
        ganadores["1"] += ganadoresDiagonal["1"]

    return ganadores

# Punto de entrada del programa
def main():
    filename = input("Ingrese el nombre del archivo generado por el programa en C: ") # Leer nombre del archivo
    (tablero, tamanio) = leerPartida(filename)

    dif = calcularDiferenciaFichas(tablero)
    if dif > 1:
        print(f"Partida Invalida: La cantidad de fichas de los jugadores difiere en {dif}. Puede diferir, como maximo, en 1.")
        return

    columnaFichasFlotantes = verificarFichasFlotantes(tablero, tamanio)
    if columnaFichasFlotantes != -1:
        print(f"Partida Invalida: Se encontraron fichas flotantes en la columna {columnaFichasFlotantes+1}.")
        return
    
    ganadores = verificarGanadores(tablero, tamanio)

    if ganadores["0"] > 0 and ganadores["1"] > 0:
        print("Partida Invalida: Ambos jugadores han ganado.")
    elif ganadores["0"] > 1:
        print("Partida Invalida: El jugador 0 gano multiples veces.")
    elif ganadores["1"] > 1:
        print("Partida Invalida: El jugador 1 gano multiples veces.")
    elif ganadores["0"] == 1:
        print("Partida valida: El ganador es el jugador 0.")
    elif ganadores["1"] == 1:
        print("Partida valida: El ganador es el jugador 1.")
    else:
        print("Partida valida: No hay ganador.")

# Evitar que se ejecute el main si se importa el archivo
if __name__ == "__main__":
    main()