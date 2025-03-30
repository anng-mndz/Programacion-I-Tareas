// elecciones.h
#ifndef ELECCIONES_H
#define ELECCIONES_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define NUM_CANDIDATOS 5
#define NUM_VOTANTES 50
#define NUM_RONDAS 5

void ingresarCandidatos(string candidatos[]);
void generarVotos(int votos[][NUM_RONDAS]);
void mostrarResultados(string partidos[], string candidatos[], int votos[][NUM_RONDAS]);
void calcularGanador(string candidatos[], int votos[][NUM_RONDAS]);

#endif
