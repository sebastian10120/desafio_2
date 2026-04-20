#include "jugador.h"


jugador::jugador(string contry, int camisa, string name, string lastname){
    pais = contry;
    camiseta = camisa;
    nombre = name;
    apellido =  lastname;
    Cantidad_goles = 0;
    Cantidad_faltas = 0;
    Cantidad_tarjetas_amarillas = 0;
    tiempo_jugado = 0;
    partidos_jugados = 0;
}
jugador::jugador(string contry, int camisa, string name, string lastname,int goles, int faltas,int tarjeta_amarilla, int tarjeta_roja,int tiempo,int partidos) {
    pais = contry;
    camiseta = camisa;
    nombre = name;
    apellido =  lastname;
    Cantidad_goles = 0;
    Cantidad_faltas = 0;
    Cantidad_tarjetas_amarillas = 0;
    tiempo_jugado = 0;
    partidos_jugados = 0;
}

void jugador::aumentar_goles(){
    Cantidad_goles++;
}
void jugador::aumentar_faltas(){
    Cantidad_faltas++;
}
void jugador::aumentar_t_amarillas(){
    Cantidad_tarjetas_amarillas++;
}
void jugador::aumentar_t_rojas(){
    Cantidad_tarjetas_rojas++;
}
void jugador::aumentar_tiempo(){
    tiempo_jugado++;
}
void jugador::aumentar_partido(){
    partidos_jugados++;
}
