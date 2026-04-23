#ifndef EQUIPO_H
#define EQUIPO_H
#include <string>
#include "jugador.h"
using namespace std;
class equipo
{
private:
    int ranking_fifa;
    string pais;
    string director;
    string federacion;
    string confederacion;
    int goles_favor;
    int goles_contra;
    int partidos_g;
    int partidos_e;
    int partidos_p;
    int faltas;
    int tarjetas_a;
    int tarjetas_r;
    jugador jugadores[26];
    int cantidad_jugadores;
    int puntaje_eliminatoria;
public:
    equipo();
    equipo(int posicion, string pais_origen, string director_tecnico, string federacion_f,string confederacion_c, int goles_f, int goles_c, int partido_g, int partido_e, int partido_p);

    equipo(int posicion, string pais_origen, string director_tecnico, string federacion_f,string confederacion_c, int goles_f, int goles_c, int partido_g, int partido_e, int partido_p, int falta, int tarjeta_a,int tarjeta_r);

    void aumentargolequipo();
    void aumentar_falta_equipo();
    void aumentar_ta_equipo();
    void aumentar_tr_equipo();
    void aumentar_pg_equipo();
    void aumentar_pe_equipo();
    void aumentar_pp_equipo();


    int get_ranking_fifa() const;
    string get_pais() const;
    string get_director() const;
    string get_federacion() const;
    string get_confederacion() const;
    int get_goles_favor() const;
    int get_goles_contra() const;
    int get_partidos_ganados() const;
    int get_partidos_empatados() const;
    int get_partidos_perdidos() const;
    int get_faltas() const;
    int get_tarjetas_amarillas() const;
    int get_tarjetas_rojas() const;
    jugador* get_jugadores();
    int get_cantidad_jugadores() const;


    bool  operator==(const equipo& otro);
    equipo comparar_goles_equipo(const equipo& a, const equipo& b);
    void agregar_jugador(jugador a);
    void set_jugadores(jugador lista[26]);
};

#endif // CLASE_EQUIPO_H
