#include <iostream>
#include "equipo.h"
#include "jugador.h"
#include "fecha.h"
#include "partido.h"
#include <fstream>
#include <string>
#include <random>
#include "libreria_principal.h"
using namespace std;

/*prototipado*/
equipo *extraer_equipos(equipo* a, int &tam);
equipo** generar_bombos(equipo* original, int total, int tam_bombo);
void grupos_torneos(equipo a[][4], equipo **bombo, char *letras);
void generar_calendario(equipo grupos[12][4], partido*& lista_partido, int& tamanp_lista_partido, fecha inicio_eliminatoria,char *letras);
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
void copia_grupos(equipo copia[12][4],equipo grupos[12][4])
/*prototipado*/
int main()
{
    int cantidad_equipos = 0;
    equipo* equipos = new equipo[0];
    bool etapa_eliminatoria = true;
    equipos = extraer_equipos(equipos, cantidad_equipos);
    añadir_jugadores(cantidad_equipos,equipos);
    equipo* temporal = new equipo[cantidad_equipos];
    temporal_equipos(temporal,cantidad_equipos,equipos);
    int tamano_bombo = 12;
    equipo** bombos = generar_bombos(temporal, cantidad_equipos,tamano_bombo);
    delete[] temporal;
    equipo grupos[12][4];
    char letra_grupo[12] = {'a','b','c','d','e','f','g','h','i','j','k','l'};
    grupos_torneos(grupos,bombos,letra_grupo);
    eliminar_matriz_equipo(bombos);
    partido* lista_partido;
    int tamano_lista_partido = 0;
    fecha inicio_eliminatoria(20,6,2026);
    generar_calendario(grupos,lista_partido,tamano_lista_partido,inicio_eliminatoria,letra_grupo);
    equipo copia[12][4];

}
void simular_partidos_eliminatoria(int tamano_lista, partido *lista_partido, char *letras,equipo grupos[12][4]){
    int puntaje_promedio_equipoa;
    int puntaje_promedio_equipob;
    double u = 1.35;
    int turnos = 90;
    int tamaño_equipos = 26;
    for (int i = 0; i < tamano_lista; i ++){
        equipo a = lista_partido[i].get_equipo1();
        equipo b = lista_partido[i].get_equipo2();
        double xa = (a.get_goles_favor()/u);
        double ya = (a.get_goles_contra()/u);
        double xb = (b.get_goles_favor()/u);
        double yb = (b.get_goles_contra()/u);
        puntaje_promedio_equipoa = (potencia_0_6(xa) * 1.35)*(potencia_0_4(ya));
        puntaje_promedio_equipoa = (potencia_0_6(xb) * 1.35)*(potencia_0_4(yb));

    }
}
void copia_grupos(equipo copia[12][4],equipo grupos[12][4]){

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 4; j++) {
            copia[i][j] = grupos[i][j];
        }
    }
}
jugador *extraaerjugadores(equipo a){
    jugador *jugadores = a.get_jugadores();
    jugador* titular = new jugador[11];;
    int total_jugadores = a.get_cantidad_jugadores();
    int indices[26];
    for (int i = 0; i < total_jugadores; i++) {
        indices[i] = i;
    }
    for (int i = total_jugadores - 1; i > 0; i--) {
        int j = numero_random(0, i);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }
    for (int i = 0; i < 11; i++) {
        titular[i] = jugadores[indices[i]];
    }
    return titular;

}
