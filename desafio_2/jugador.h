#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
using namespace std;
class jugador
{
private:
    string pais;
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
    jugador();
    jugador(string contry, int camisa, string name, string lastnaame,int goles, int faltas,int tarjeta_amarilla, int tarjeta_roja,int tiempo,int partidos);
    jugador(string contry, int camisa, string name, string lastnaame);

    void aumentar_goles();
    void aumentar_faltas();
    void aumentar_t_amarillas();
    void aumentar_t_rojas();
    void aumentar_tiempo();
    void aumentar_partido();


    string getPais() const;
    int getCamiseta() const;
    string getNombre() const;
    string getApellido() const;
    int getCantidadGoles() const;
    int getCantidadFaltas() const;
    int getCantidadTarjetasAmarillas() const;
    int getCantidadTarjetasRojas() const;
    int getTiempoJugado() const;
    int getPartidosJugados() const;
};

#endif // JUGADOR_H
