#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego
{
private:
    Tablero tablero;
    int cantidadMinas;
    int vidasTablero;  // Nueva variable para almacenar las vidas

    int aleatorio_en_rango(int minimo, int maximo);
    int filaAleatoria();
    int columnaAleatoria();

public:
    Juego(Tablero tablero, int cantidadMinas, int vidasTablero);  // Modificado para recibir vidas
    void colocarMinasAleatoriamente();
    int solicitarFilaUsuario();
    int solicitarColumnaUsuario();
    bool jugadorGana();
    void iniciar();
    void dibujarPortada(string nombreArchivo);
};

#endif // JUEGO_H
