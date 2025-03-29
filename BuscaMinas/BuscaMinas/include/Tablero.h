#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <vector>
#include "Celda.h"

using namespace std;

/**
 * Clase Tablero: Representa el tablero del juego de Buscaminas.
 * Se encarga de almacenar la informaci�n de cada celda, imprimir el tablero y manejar las minas.
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
         * Constructor con par�metros.
         * Inicializa el tablero con las dimensiones y el modo de juego indicados.
         * alturaTablero Altura del tablero (cantidad de filas).
         * anchoTablero Ancho del tablero (cantidad de columnas).
         * modoDesarrollador Indica si se mostrar�n las minas (modo desarrollador).
         */
        Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);

        // M�todos para obtener y modificar atributos del tablero
        int getAlturaTablero(); // Devuelve la altura del tablero
        int setAlturaTablero(int alturaTablero); // Modifica la altura del tablero
        int getAnchoTablero(); // Devuelve el ancho del tablero
        int setAnchoTablero(int anchoTablero); // Modifica el ancho del tablero
        bool getModoDesarrollador(); // Devuelve el estado del modo desarrollador
        bool setModoDesarrollador(bool modoDesarrollador); // Activa o desactiva el modo desarrollador

        // M�todos para impresi�n del tablero en consola
        void imprimirSeparadorEncabezado(); // Imprime la l�nea superior del tablero
        void imprimirSeparadorFilas(); // Imprime las separaciones entre filas
        void imprimirEncabezado(); // Imprime la fila de n�meros en la parte superior
        void imprimir(); // Imprime todo el tablero en consola

        // M�todos para manejar las minas
        bool colocarMina(int x, int y); // Coloca una mina en la posici�n indicada
        bool descubrirMina(int x, int y); // Descubre una celda y verifica si tiene mina
        int contarCeldasSinMinasYSinDescubrir(); // Cuenta cu�ntas celdas quedan sin minas y sin descubrir

    private:
        int alturaTablero, anchoTablero;  // Dimensiones del tablero
        bool modoDesarrollador;  // Indica si se deben mostrar las minas en el tablero
        vector<vector<Celda>> contenidoTablero;  // Matriz bidimensional que almacena las celdas del tablero

        // M�todos auxiliares
        string getRepresentacionMina(int x, int y); // Obtiene el s�mbolo que representa una celda (mina, n�mero, o "?")
        int minasCercanas(int fila, int columna); // Cuenta cu�ntas minas hay alrededor de una celda espec�fica
};

#endif // TABLERO_H
