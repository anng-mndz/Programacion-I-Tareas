//LUIS ANGEL MÉNDEZ FUENTES
//Marzo 2025
//Curso de Programaciòn I
#include "elecciones.h"

int main() {
    srand(time(0));
    string candidatos[NUM_CANDIDATOS];
    string partidos[NUM_CANDIDATOS] = {"Partido A", "Partido B", "Partido C", "Partido D", "Partido E"};
    int votos[NUM_CANDIDATOS][NUM_RONDAS] = {0};

    char repetir;
    do {
        ingresarCandidatos(candidatos);
        generarVotos(votos);
        mostrarResultados(partidos, candidatos, votos);
        calcularGanador(candidatos, votos);

        cout << "\nDesea realizar otra eleccion? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}
