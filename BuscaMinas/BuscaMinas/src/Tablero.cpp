#include "Tablero.h"
#include <sstream>
#include <iostream>

using namespace std;

/**
 * Constructor por defecto de Tablero.
 * No inicializa valores, por lo que se debe utilizar el constructor con parámetros.
 */
Tablero::Tablero()
{
}

/**
 * Constructor de Tablero con parámetros.
 * Inicializa el tablero con las dimensiones especificadas y configura el modo desarrollador.
 * Crea una matriz de celdas vacía (sin minas).
 *
 * alturaTablero Altura del tablero (cantidad de filas).
 * anchoTablero Ancho del tablero (cantidad de columnas).
 * modoDesarrollador Indica si las minas se mostrarán en el tablero (modo desarrollador).
 */
Tablero::Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador)
{
    this->alturaTablero = alturaTablero;
    this->anchoTablero = anchoTablero;
    this->modoDesarrollador = modoDesarrollador;

    // Se inicializa la matriz del tablero con celdas vacías
    for (int y = 0; y < this->alturaTablero; y++)
    {
        vector<Celda> fila;
        for (int x = 0; x < this->anchoTablero; x++)
        {
            fila.push_back(Celda(x, y, false)); // Cada celda inicia sin mina
        }
        this->contenidoTablero.push_back(fila);
    }
}

// Métodos "getter" para obtener las dimensiones y estado del modo desarrollador
int Tablero::getAlturaTablero()
{
    return this->alturaTablero;
}

int Tablero::setAlturaTablero(int alturaTablero)
{
    this->alturaTablero = alturaTablero;
}

int Tablero::getAnchoTablero()
{
    return this->anchoTablero;
}

int Tablero::setAnchoTablero(int anchoTablero)
{
    this->anchoTablero = anchoTablero;
}

bool Tablero::getModoDesarrollador()
{
    return this->modoDesarrollador;
}

bool Tablero::setModoDesarrollador(bool modoDesarrollador)
{
    this->modoDesarrollador = modoDesarrollador;
}

/**
 * Obtiene la representación visual de una celda en el tablero.
 * Si la celda contiene una mina y está descubierta o el modo desarrollador está activado, se muestra "*".
 * Si no hay mina, se muestra el número de minas cercanas.
 * Si la celda no ha sido descubierta, se muestra "?".
 */
string Tablero::getRepresentacionMina(int coordenadaX, int coordenadaY)
{
    Celda celdaTemporal = this->contenidoTablero.at(coordenadaY).at(coordenadaX);

    if (celdaTemporal.getMinaDescubierta() || this->modoDesarrollador)
    {
        if (celdaTemporal.getMina())
        {
            return "*"; // Se muestra la mina si está descubierta o en modo desarrollador
        }
        else
        {
            int cantidadCelda = this->minasCercanas(coordenadaY, coordenadaX);
            stringstream ss;
            ss << cantidadCelda;
            return ss.str(); // Se muestra el número de minas cercanas
        }
    }
    else
    {
        return "?"; // Si la celda no está descubierta, se muestra "?"
    }
}

/**
 * Cuenta la cantidad de minas en las celdas adyacentes a la posición indicada.
 */
int Tablero::minasCercanas(int filaTablero, int columnaTablero)
{
    int contadorTablero = 0;
    int filaInicioTablero = max(0, filaTablero - 1);
    int filaFinTablero = min(this->alturaTablero - 1, filaTablero + 1);
    int columnaInicioTablero = max(0, columnaTablero - 1);
    int columnaFinTablero = min(this->anchoTablero - 1, columnaTablero + 1);

    for (int m = filaInicioTablero; m <= filaFinTablero; m++)
    {
        for (int l = columnaInicioTablero; l <= columnaFinTablero; l++)
        {
            if (this->contenidoTablero.at(m).at(l).getMina())
            {
                contadorTablero++; // Se incrementa el contador si la celda tiene mina
            }
        }
    }
    return contadorTablero;
}

// Métodos de impresión para mostrar el tablero en consola

void Tablero::imprimirSeparadorEncabezado()
{
    for (int m = 0; m <= this->anchoTablero; m++)
    {
        cout << "----";
        if (m + 2 == this->anchoTablero)
        {
            cout << "-";
        }
    }
    cout << "\n";
}

void Tablero::imprimirSeparadorFilas()
{
    for (int m = 0; m <= this->anchoTablero; m++)
    {
        if (m <= 1)
        {
            cout << "|---";
        }
        else
        {
            cout << "+---";
        }
        if (m == this->anchoTablero)
        {
            cout << "+";
        }
    }
    cout << "\n";
}

void Tablero::imprimirEncabezado()
{
    this->imprimirSeparadorEncabezado();
    cout << "|   ";
    for (int l = 0; l < this->anchoTablero; l++)
    {
        cout << "| " << l + 1 << " ";
        if (l + 1 == this->anchoTablero)
        {
            cout << "|";
        }
    }
    cout << "\n";
}

void Tablero::imprimir()
{
    this->imprimirEncabezado();
    this->imprimirSeparadorEncabezado();
    for (int y = 0; y < this->alturaTablero; y++)
    {
        cout << "| " << y + 1 << " ";
        for (int x = 0; x < this->anchoTablero; x++)
        {
            cout << "| " << this->getRepresentacionMina(x, y) << " ";
            if (x + 1 == this->anchoTablero)
            {
                cout << "|";
            }
        }
        cout << "\n";
        this->imprimirSeparadorFilas();
    }
}

/**
 * Coloca una mina en la celda especificada.
 * return Devuelve true si la mina se colocó correctamente.
 */
bool Tablero::colocarMina(int x, int y)
{
    return this->contenidoTablero.at(y).at(x).setMina(true);
}

/**
 * Descubre una celda y verifica si contiene una mina.
 * Si la celda tiene una mina, el juego termina.
 * @return Devuelve false si hay una mina en la celda, true si no la hay.
 */
bool Tablero::descubrirMina(int x, int y)
{
    this->contenidoTablero.at(y).at(x).setMinaDescubierta(true);
    Celda celda = this->contenidoTablero.at(y).at(x);
    return !celda.getMina();
}

/**
 * Cuenta cuántas celdas quedan sin minas y sin descubrir.
 * Se usa para verificar si el jugador ha ganado la partida.
 */
int Tablero::contarCeldasSinMinasYSinDescubrir()
{
    int contador = 0;
    for (int y = 0; y < this->alturaTablero; y++)
    {
        for (int x = 0; x < this->anchoTablero; x++)
        {
            Celda celdaTemporal = this->contenidoTablero.at(y).at(x);
            if (!celdaTemporal.getMinaDescubierta() && !celdaTemporal.getMina())
            {
                contador++;
            }
        }
    }
    return contador;
}
