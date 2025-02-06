#include <iostream>
#include <cstdlib>
// Este programa servira para calcular tu masa corporal mediante tu estatura y peso.
//Febrero 2025 anng-mndz
using namespace std;

int main()
{
    // Variables
    float estaturaPulgadas = 0;
    float pesoEnLibras = 0;
    float pesoEnKilos = 0;
    float resultadoMasaCorporal = 0;
    int opcionSeleccionada;
    char salidaMenu;

    // Inicia el ciclo
    do
    {
        system("cls");
        // Reiniciar valores
        opcionSeleccionada = 0;
        resultadoMasaCorporal = 0;

        cout << "Calculadora de Masa Corporal" << endl;
        cout << "1. Peso en Libras" << endl;
        cout << "2. Peso en Kilos" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionSeleccionada;

        if (opcionSeleccionada == 1)
        {
            cout << "Ingrese su estatura en centimetros: ";
            float estaturaCm;
            cin >> estaturaCm;
            estaturaPulgadas = estaturaCm / 2.54; // lo convierte en base a conversion de estaturas cm a pulgadas

            cout << "Ingrese su peso en libras: ";
            cin >> pesoEnLibras;
        }
        else if (opcionSeleccionada == 2)
        {
            cout << "Ingrese su estatura en centimetros: ";
            float estaturaCm;
            cin >> estaturaCm;
            estaturaPulgadas = estaturaCm / 2.54;

            cout << "Ingrese su peso en kilogramos: ";
            cin >> pesoEnKilos;
        }
        else
        {
            cout << "Opcion invalida." << endl;
            continue;
        }

        switch (opcionSeleccionada)
        {
        case 1:
            resultadoMasaCorporal = (pesoEnLibras * 703) / (estaturaPulgadas * estaturaPulgadas);
            break;
        case 2:
            resultadoMasaCorporal = pesoEnKilos / ((estaturaPulgadas * 0.0254) * (estaturaPulgadas * 0.0254)); //Conversion a metros para no pedir por asi decirlo otro dato extra y sea mas amigable :)
            break;
        }

        cout << "Su indice de masa corporal es: " << resultadoMasaCorporal << endl;

        cout << "En base a la tabla puede determinar su masa corporal Underweight = 18.5, Normal weight = 18.5 to 24.9, Overweight = 25 to 29.9, Obesity = IMC of 30 or greater" << endl;

        cout << "Desea realizar otra operacion? Si=S o No=N";
        cin >> salidaMenu;

    } while (salidaMenu == 's' || salidaMenu == 'S');

    return 0;
}
