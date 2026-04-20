#ifndef EQUIPO_H
#define EQUIPO_H
#include <string>
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
public:
    equipo(int posicion, string pais_origen, string director_tecnico, string federacion_f,string confederacion_c, int goles_f, int goles_c, int partido_g, int partido_e, int partido_p);

    equipo(int posicion, string pais_origen, string director_tecnico, string federacion_f,string confederacion_c, int goles_f, int goles_c, int partido_g, int partido_e, int partido_p, int falta, int tarjeta_a,int tarjeta_r);

    void aumentargolequipo();
    void aumentar_falta_equipo();
    void aumentar_ta_equipo();
    void aumentar_tr_equipo();
    void aumentar_pg_equipo();
    void aumentar_pe_equipo();
    void aumentar_pp_equipo();

    bool  operator==(const equipo& otro);
    equipo comparar_goles_equipo(const equipo& a, const equipo& b);
};

#endif // CLASE_EQUIPO_H
