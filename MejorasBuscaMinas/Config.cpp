#include <iostream>
#include <unistd.h>
#include "Config.h"
using namespace std;

Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero)
{
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero; //asignacion de las vidad que se pasan al configurar el juego asi mismo en el constructor ahora se asigna el valor de vidas a la variable de configuracion
}

void Config::menuConfiguracion()
{
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t4. Modo del Juego -------> " << (this->getmodoDesarrolladorTablero() ? "1" : "0") << endl;
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        cout << "\t\t6. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        if (opciones != 6)
        {
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }
        switch (opciones)
        {
        case 1:
            this->setfilasTablero(valorIngresado);
            cout << "Filas del Tablero actualizadas" << endl;
            break;
        case 2:
            this->setcolumnasTablero(valorIngresado);
            cout << "Columnas del Tablero actualizadas" << endl;
            break;
        case 3:
            this->setminasTablero(valorIngresado);
            cout << "Minas del Tablero actualizadas" << endl;
            break;
        case 4:
            this->setmodoDesarrolladorTablero(valorIngresado);
            cout << "Modo del Juego actualizado" << endl;
            break;
        case 5:
            this->setvidasTablero(valorIngresado); //se actualiza el numero de vidas con el valor que el usuario ingresa en el menu
            cout << "Vidas del Juego actualizadas" << endl;
            break;
        case 6:
            repetir = false;
            break;
        default:
            cout << "Opción inválida, intente nuevamente." << endl;
        }
        system("pause");
    } while (repetir);
}

int Config::getfilasTablero()
{
    return this->filasTablero;
}

void Config::setfilasTablero(int filasTablero)
{
    this->filasTablero = filasTablero;
}

int Config::getcolumnasTablero()
{
    return this->columnasTablero;
}

void Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero = columnasTablero;
}

int Config::getminasTablero()
{
    return this->minasTablero;
}

void Config::setminasTablero(int minasTablero)
{
    this->minasTablero = minasTablero;
}

bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero;
}

void Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
}

int Config::getvidasTablero()
{
    return this->vidasTablero;
}

void Config::setvidasTablero(int vidasTablero)
{
    this->vidasTablero = vidasTablero;
}

