from random import random

def leerArchivo(nombreDeArchivo):
    archivo = open(nombreDeArchivo, "r");
    dimen = archivo.readline().split();
    tablero = [[0 for _ in range(int(dimen[1]))] for _ in range(int(dimen[0]))]
    numeroDeBarco = 1

    for line in archivo.readlines():
        barco = line.split()
        x = int(barco[0])
        y = int(barco[1])
        hor = int(barco[2])
        longi = int(barco[3])

        if hor == 0:
            for pos in range(longi):
                tablero[x + pos][y] = numeroDeBarco
        else:
            for pos in range(longi):
                tablero[x][y + pos] = numeroDeBarco
        numeroDeBarco += 1

    return tablero

def disparosDisponibles(tablero):
    disparos = 0
    for fila in tablero:
        for celda in fila:
            if celda != 0:
                disparos += 1

    return disparos * 3

def disparar(tablero, disparoX, disparoY):
    for iFila in range(len(tablero)):
        for iCelda in range(len(tablero[iFila])):
            if disparoY == iFila and disparoX == iCelda and tablero[iFila][iCelda] != 0:
                print('hit!', iFila, iCelda)
                tablero[iFila][iCelda] = 0
                return checkWin(tablero)
    print('miss')
    return False
    

def turnoComputadora(tableroAliado):
    disparoX = (round((random() * 100) % len(tableroAliado)))
    disparoY = (round((random() * 100) % len(tableroAliado[0])))
    return disparar(tableroAliado, disparoX, disparoY)

def turnoHumano(tableroEnemigo):
    disparoX = -1
    disparoY = -1
    while (not (0 <= disparoX and disparoX < len(tableroEnemigo))) or (not (0 <= disparoY and disparoY < len(tableroEnemigo[0]))):
        disparoX = int(input('Coordenada x para disparar: '))
        disparoY = int(input('Coordenada y para disparar: '))
    return disparar(tableroEnemigo, disparoX, disparoY)

def checkWin(tablero):
    for fila in tablero:
        for celda in fila:
            if celda != 0:
                print('no win')
                return False
    print('win')
    return True

def juego(tableroAliado, tableroEnemigo, disparosAliado, disparosEnemigo):
    while 0 <= disparosAliado and 0  <= disparosEnemigo:
        result = turnoComputadora(tableroAliado)
        if (result):
            print('Computadora gano')
            return None
        disparosEnemigo -= 1
        if disparosEnemigo <= 0:
            print('Humano gano')
            return None

        result = turnoHumano(tableroEnemigo)
        if (result != None and result):
            print('Humano gano')
            return None
        disparosAliado -= 1
        if disparosAliado <= 0:
            print('Humano gano')
            return None
        
    
    
        
def main():
    tableroAliado = leerArchivo("aliado.txt")
    tableroEnemigo = leerArchivo("enemigo.txt")

    disparosAliado = disparosDisponibles(tableroEnemigo)
    disparosEnemigo = disparosDisponibles(tableroAliado)

    juego(tableroAliado, tableroEnemigo, disparosAliado, disparosEnemigo)


if __name__ == "__main__":
    main()
