#include "equipo.h"


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

