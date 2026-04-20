#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
using namespace std;
class jugador
{
private:
    string pais;
    int numero;
    int camiseta;
    string nombre;
    string apellido;
    int Cantidad_goles;
    int Cantidad_faltas;
    int Cantidad_tarjetas_amarillas;
    int Cantidad_tarjetas_rojas;
    int tiempo_jugado;
    int partidos_jugados;


public:
    jugador(string contry, int camisa, string name, string lastnaame,int goles, int faltas,int tarjeta_amarilla, int tarjeta_roja,int tiempo,int partidos);
    jugador(string contry, int camisa, string name, string lastnaame);

    void aumentar_goles();
    void aumentar_faltas();
    void aumentar_t_amarillas();
    void aumentar_t_rojas();
    void aumentar_tiempo();
    void aumentar_partido();
};

#endif // JUGADOR_H
