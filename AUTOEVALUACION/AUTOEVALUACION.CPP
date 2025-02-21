#include <iostream>
#include <iomanip>

using namespace std;

//calculos para nota finales y el porcentaje
void calcularNotaFinal(int parcial1, int parcial2, int actividades, int examenFinal, int &notaFinal, float &porcentaje) {
    notaFinal = parcial1 + parcial2 + actividades + examenFinal;
    porcentaje = (float)notaFinal / 100 * 100;
}

int main() {
    string alumnos[] = {"alumno 1", "alumno 2", "alumno 3", "alumno 4", "alumno 5"};

    int parcial1, parcial2, actividades, examenFinal, notaFinal;
    float porcentaje;

//calculo para todos los punteos de los alumnos, con condicionales de notas para que no se pasen del rango correspondido de los parciales, etc
    for (int i = 0; i < 5; i++) {
        cout << "Ingrese las notas para " << alumnos[i] << ":" << endl;

        cout << "1er Parcial (0-20): ";
        cin >> parcial1;
        while (parcial1 < 0 || parcial1 > 20) {
            cout << "Ingrese una nota entre 0 y 20 para el 1er Parcial: ";
            cin >> parcial1;
        }

        cout << "2do Parcial (0-25): ";
        cin >> parcial2;
        while (parcial2 < 0 || parcial2 > 25) {
            cout << "Ingrese una nota entre 0 y 25 para el 2do Parcial: ";
            cin >> parcial2;
        }

        cout << "Actividades (0-20): ";
        cin >> actividades;
        while (actividades < 0 || actividades > 20) {
            cout << "Ingrese una nota entre 0 y 20 para Actividades: ";
            cin >> actividades;
        }

        cout << "Examen Final (0-35): ";
        cin >> examenFinal;
        while (examenFinal < 0 || examenFinal > 35) {
            cout << "Ingrese una nota entre 0 y 35 para el Examen Final: ";
            cin >> examenFinal;
        }

        calcularNotaFinal(parcial1, parcial2, actividades, examenFinal, notaFinal, porcentaje);

        // Mostrar los resultados del alumno uno por uno
        cout << alumnos[i] << ":" << endl;
        cout << "Parcial 1: " << parcial1 << ", Parcial 2: " << parcial2 << ", Actividades: " << actividades << ", Examen Final: " << examenFinal << endl;
        cout << "Nota Final: " << notaFinal << ", Porcentaje: " << porcentaje << "%" << endl << endl;
    }

    return 0;
}
