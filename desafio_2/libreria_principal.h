#ifndef LIBRERIA_PRINCIPAL_H
#define LIBRERIA_PRINCIPAL_H
#include <iostream>
#include "equipo.h"
#include "jugador.h"
#include "fecha.h"
#include "partido.h"
#include <fstream>
#include <string>
#include <random>
using namespace std;
/*prototipado*/
equipo *extraer_equipos(equipo* a, int &tam);
equipo** generar_bombos(equipo* original, int total, int tam_bombo);
void grupos_torneos(equipo a[][4], equipo **bombo, char *letras);
void generar_calendario(equipo grupos[12][4],partido*& lista_partido,int& tamanp_lista_partido,fecha inicio_eliminatoria, char letras);
void eliminar_matriz_equipo(equipo **a);
void temporal_equipos(equipo *tem, int tam, equipo *original);
void añadir_jugadores(int tam, equipo *original);
int char_a_entero(string a);
equipo* agrandarArreglo(equipo* viejo, int &tam);
int numero_random(int a,int b);
int sorteo_bombo();
string producir_nombre();
string producir_apellido();
void inicializar_en_cero(int arreglo[], int tam);
bool bombo_representado(int arreglo[], int tam, int a);
int aleatorio_arbitro_estadio();
string producir_arbitro();
string producir_estadio();
partido* agrandarArreglopartidos(partido* viejo, int &tam);
double raizQuinta(double n);
double potencia_0_4(double x);
double potencia_0_6(double x);
/*prototipado*/
#endif // LIBRERIA_PRINCIPAL_H
