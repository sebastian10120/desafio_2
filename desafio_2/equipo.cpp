#include "equipo.h"
#include <iostream>

equipo::equipo(){
    ranking_fifa = 0;
    pais = "";
    director = "";
    federacion = "";
    confederacion = "";

    goles_favor = 0;
    goles_contra = 0;

    partidos_g = 0;
    partidos_e = 0;
    partidos_p = 0;

    faltas = 0;
    tarjetas_a = 0;
    tarjetas_r = 0;
    cantidad_jugadores = 0;
    for (int i = 0; i < 26; i++) {
        jugadores[i] = jugador();
    }
}
equipo::equipo(int posicion, string pais_origen, string director_tecnico, string federacion_f,string confederacion_c, int goles_f, int goles_c, int partido_g, int partido_e, int partido_p)
{
    ranking_fifa = posicion;
    pais = pais_origen;
    director = director_tecnico;
    federacion = federacion_f;
    confederacion = confederacion_c;
    goles_favor = goles_f;
    goles_contra = goles_c;
    partidos_g = partido_g;
    partidos_e = partido_e;
    partidos_p = partido_p;
    faltas = 0;
    tarjetas_a = 0;
    tarjetas_r = 0;
    cantidad_jugadores = 0;
    for (int i = 0; i < 26; i++) {
        jugadores[i] = jugador();

    }
}
equipo::equipo(int posicion, string pais_origen, string director_tecnico, string federacion_f,string confederacion_c, int goles_f, int goles_c, int partido_g, int partido_e, int partido_p, int falta, int tarjeta_a,int tarjeta_r)
{
    ranking_fifa = posicion;
    pais = pais_origen;
    director = director_tecnico;
    federacion = federacion_f;
    confederacion = confederacion_c;
    goles_favor = goles_f;
    goles_contra = goles_c;
    partidos_g = partido_g;
    partidos_e = partido_e;
    partidos_p = partido_p;
    faltas = falta;
    tarjetas_a = tarjeta_a;
    tarjetas_r = tarjeta_r;
    cantidad_jugadores = 0;
}


void equipo::aumentargolequipo(){
    goles_favor++;
}
void equipo::aumentar_falta_equipo(){
    faltas++;
}
void equipo::aumentar_ta_equipo(){
    tarjetas_a++;
}
void equipo::aumentar_tr_equipo(){
    tarjetas_r++;
}
void equipo::aumentar_pg_equipo(){
    partidos_g++;
}
void equipo::aumentar_pe_equipo(){
    partidos_e++;
}
void equipo::aumentar_pp_equipo(){
    partidos_p++;
}


int equipo::get_ranking_fifa() const {
    return ranking_fifa;
}
string equipo::get_pais() const {
    return pais;
}
string equipo::get_director() const {
    return director;
}
string equipo::get_federacion() const {
    return federacion;
}
string equipo::get_confederacion() const {
    return confederacion;
}
int equipo::get_goles_favor() const {
    return goles_favor;
}
int equipo::get_goles_contra() const {
    return goles_contra;
}
int equipo::get_partidos_ganados() const {
    return partidos_g;
}
int equipo::get_partidos_empatados() const {
    return partidos_e;
}
int equipo::get_partidos_perdidos() const {
    return partidos_p;
}
int equipo::get_faltas() const {
    return faltas;
}
int equipo::get_tarjetas_amarillas() const {
    return tarjetas_a;
}
int equipo::get_tarjetas_rojas() const {
    return tarjetas_r;
}
jugador* equipo::get_jugadores(){
    return jugadores;
}
int equipo::get_cantidad_jugadores() const{
    return cantidad_jugadores;
}


bool equipo::operator==(const equipo& otro){
    return confederacion == otro.confederacion;
}
equipo equipo::comparar_goles_equipo(const equipo& a, const equipo& b){
    if (a.goles_favor > b.goles_favor){
        return a;
    }
    else if (a.goles_favor < b.goles_favor){
        return b;
    }
    else {
        return a;
    }
}
void equipo::agregar_jugador(jugador a){
    if (cantidad_jugadores < 26){
        jugadores[cantidad_jugadores] = a;

        cout << "Jugador " << cantidad_jugadores + 1
             << ": agregado al equipo " << pais << endl;

        cantidad_jugadores++;
    }
}
void equipo::set_jugadores(jugador lista[26]){
    for (int i = 0; i < 26; i++){
        jugadores[i] = lista[i];
    }
    cantidad_jugadores = 26;
}
