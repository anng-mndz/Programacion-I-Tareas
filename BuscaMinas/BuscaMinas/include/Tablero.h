#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <vector>
#include "Celda.h"

using namespace std;

/**
 * Clase Tablero: Representa el tablero del juego de Buscaminas.
 * Se encarga de almacenar la información de cada celda, imprimir el tablero y manejar las minas.
 */
class Tablero
{
    public:
        /**
         * Constructor por defecto.
         * No inicializa dimensiones ni contenido del tablero.
         */
        Tablero();

        /**
         * Constructor con parámetros.
         * Inicializa el tablero con las dimensiones y el modo de juego indicados.
         * alturaTablero Altura del tablero (cantidad de filas).
         * anchoTablero Ancho del tablero (cantidad de columnas).
         * modoDesarrollador Indica si se mostrarán las minas (modo desarrollador).
         */
        Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);

        // Métodos para obtener y modificar atributos del tablero
        int getAlturaTablero(); // Devuelve la altura del tablero
        int setAlturaTablero(int alturaTablero); // Modifica la altura del tablero
        int getAnchoTablero(); // Devuelve el ancho del tablero
        int setAnchoTablero(int anchoTablero); // Modifica el ancho del tablero
        bool getModoDesarrollador(); // Devuelve el estado del modo desarrollador
        bool setModoDesarrollador(bool modoDesarrollador); // Activa o desactiva el modo desarrollador

        // Métodos para impresión del tablero en consola
        void imprimirSeparadorEncabezado(); // Imprime la línea superior del tablero
        void imprimirSeparadorFilas(); // Imprime las separaciones entre filas
        void imprimirEncabezado(); // Imprime la fila de números en la parte superior
        void imprimir(); // Imprime todo el tablero en consola

        // Métodos para manejar las minas
        bool colocarMina(int x, int y); // Coloca una mina en la posición indicada
        bool descubrirMina(int x, int y); // Descubre una celda y verifica si tiene mina
        int contarCeldasSinMinasYSinDescubrir(); // Cuenta cuántas celdas quedan sin minas y sin descubrir

    private:
        int alturaTablero, anchoTablero;  // Dimensiones del tablero
        bool modoDesarrollador;  // Indica si se deben mostrar las minas en el tablero
        vector<vector<Celda>> contenidoTablero;  // Matriz bidimensional que almacena las celdas del tablero

        // Métodos auxiliares
        string getRepresentacionMina(int x, int y); // Obtiene el símbolo que representa una celda (mina, número, o "?")
        int minasCercanas(int fila, int columna); // Cuenta cuántas minas hay alrededor de una celda específica
};

#endif // TABLERO_H
