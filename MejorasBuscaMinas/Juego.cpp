#include "Juego.h"
#include <fstream>
#include <unistd.h>

int Juego::aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int Juego::filaAleatoria()
{
    return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
}

int Juego::columnaAleatoria()
{
    return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
}

Juego::Juego(Tablero tablero, int cantidadMinas, int vidasTablero) //ahora se recibe el numero de vidas del jugador como un parametro
{
    this->tablero = tablero;
    this->cantidadMinas = cantidadMinas;
    this->vidasTablero = vidasTablero;  // Usamos el valor configurado de vidas
    this->colocarMinasAleatoriamente();
}


void Juego::colocarMinasAleatoriamente()
{
    int x, y, minasColocadas = 0;

    while (minasColocadas < this->cantidadMinas)
    {
        x = this->columnaAleatoria();
        y = this->filaAleatoria();
        if (this->tablero.colocarMina(x, y))
        {
            minasColocadas++;
        }
    }
}

int Juego::solicitarFilaUsuario()
{
    int fila = 0;
    cout << "Ingresa la FILA en la que desea jugar: ";
    cin >> fila;
    return fila - 1;
}

int Juego::solicitarColumnaUsuario()
{
    int columna = 0;
    cout << "Ingresa la COLUMNA en la que desea jugar: ";
    cin >> columna;
    return columna - 1;
}

bool Juego::jugadorGana()
{
    int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
    if (conteo == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Juego::iniciar()
{
    int fila, columna;
    int vidasRestantes = this->vidasTablero; // Usamos el valor de vidas configurado

    while (vidasRestantes > 0) // El juego sigue mientras haya vidas
    {
        this->tablero.imprimir();
        fila = this->solicitarFilaUsuario();
        columna = this->solicitarColumnaUsuario();

        bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);

        if (!respuestaAUsuario) // Si el jugador pisa una mina
        {
            vidasRestantes--; // Restar una vida
            cout << "¡Has pisado una mina! Vidas restantes: " << vidasRestantes << endl;

            if (vidasRestantes == 0) // Si ya no hay vidas, el juego termina
            {
                cout << "Perdiste el Juego\n";
                this->tablero.setModoDesarrollador(true);
                this->tablero.imprimir();
                break;
            }
        }

        if (this->jugadorGana()) // Si el jugador gana
        {
            cout << "Ganaste el Juego\n";
            this->tablero.setModoDesarrollador(true);
            this->tablero.imprimir();
            break;
        }
    }
}
