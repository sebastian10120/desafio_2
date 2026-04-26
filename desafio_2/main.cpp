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
void copia_grupos(equipo copia[12][4],equipo grupos[12][4]);
void simular_partidos_eliminatoria(int tamano_lista, partido *lista_partido, char *letras,equipo grupos[12][4]);
jugador *extraerjugadores(equipo a);
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
void simular_partidos_eliminatoria(int tamano_lista, partido *lista_partido, char *letras, equipo grupos[12][4]) {

    double alpha = 0.6;
    double beta = 0.4;
    double u = 1.35;
    int turnos = 90;

    for (int i = 0; i < tamano_lista; i++) {

        // ⚠️ referencias correctas a los equipos del partido
        equipo &a = lista_partido[i].get_equipo1();
        equipo &b = lista_partido[i].get_equipo2();

        double xa = (a.get_goles_favor() / u);
        double ya = (b.get_goles_contra() / u);

        double xb = (b.get_goles_favor() / u);
        double yb = (a.get_goles_contra() / u);

        int goles_esperados_a = (pow(xa, alpha) * u) * (pow(ya, beta));
        int goles_esperados_b = (pow(xb, alpha) * u) * (pow(yb, beta));

        jugador *titulares_a = extraerjugadores(a);
        jugador *titulares_b = extraerjugadores(b);

        int golesa = 0, golesb = 0;
        int faltasa = 0, faltasb = 0;
        int amarillas_a = 0, amarillas_b = 0;

        // ================= SIMULACIÓN =================
        for (int turno = 0; turno < turnos; turno++) {

            // -------- A --------
            float gol_prob = float_random(0, 100);

            if (gol_prob <= 4 && golesa < goles_esperados_a) {
                int j = numero_random(0, 10);

                golesa++;
                titulares_a[j].aumentar_goles();
                a.aumentargolequipo();
                b.aumentargolcontra();
            }

            float falta_prob = float_random(0, 100);

            if ((faltasa == 0 && falta_prob <= 13) ||
                (faltasa == 1 && falta_prob <= 2.75) ||
                (faltasa >= 2 && falta_prob <= 0.7)) {

                int j = numero_random(0, 10);
                titulares_a[j].aumentar_faltas();
                a.aumentar_falta_equipo();
                faltasa++;
            }

            float amarilla_prob = float_random(0, 100);

            if ((amarillas_a == 0 && amarilla_prob <= 6) ||
                (amarillas_a == 1 && amarilla_prob <= 1.15)) {

                int j = numero_random(0, 10);

                titulares_a[j].aumentar_t_amarillas();
                a.aumentar_ta_equipo();
                amarillas_a++;

                if (titulares_a[j].getCantidadTarjetasAmarillas() >= 2) {
                    titulares_a[j].aumentar_t_rojas();
                    a.aumentar_tr_equipo();
                }
            }

            // -------- B --------
            gol_prob = float_random(0, 100);

            if (gol_prob <= 4 && golesb < goles_esperados_b) {
                int j = numero_random(0, 10);

                golesb++;
                titulares_b[j].aumentar_goles();
                b.aumentargolequipo();
                a.aumentargolcontra();
            }

            falta_prob = float_random(0, 100);

            if ((faltasb == 0 && falta_prob <= 13) ||
                (faltasb == 1 && falta_prob <= 2.75) ||
                (faltasb >= 2 && falta_prob <= 0.7)) {

                int j = numero_random(0, 10);
                titulares_b[j].aumentar_faltas();
                b.aumentar_falta_equipo();
                faltasb++;
            }

            float amarilla_prob_b = float_random(0, 100);

            if ((amarillas_b == 0 && amarilla_prob_b <= 6) ||(amarillas_b == 1 && amarilla_prob_b <= 1.15) || (amarillas_b >= 2 && amarilla_prob_b <= 0.7)) {

                int j = numero_random(0, 10);

                titulares_b[j].aumentar_t_amarillas();
                b.aumentar_ta_equipo();
                amarillas_b++;

                if (titulares_b[j].getCantidadTarjetasAmarillas() >= 2) {
                    titulares_b[j].aumentar_t_rojas();
                    b.aumentar_tr_equipo();
                }
            }
        }
        lista_partido[i].set_resultado(golesa, golesb);
        if (golesa > golesb) {
            a.sumar_victoria();
            b.sumar_derrota();
        }
        else if (golesb > golesa) {
            b.sumar_victoria();
            a.sumar_derrota();
        }
        else {
            if (a.get_goles_favor() > b.get_goles_favor()){
                a.sumar_victoria();
                b.sumar_derrota();
            }
            else if(a.get_goles_favor() < b.get_goles_favor()){
                b.sumar_victoria();
                a.sumar_derrota();
            }
            else{
                int victoria  = numero_random(1,2);
                if (victoria == 1){
                    a.sumar_victoria();
                    b.sumar_derrota();
                }
                else {
                    b.sumar_victoria();
                    a.sumar_derrota();
                }

            }
        }
        cout << "\nPartido " << letras[i] << ":\n";
        cout << a.get_pais() << " " << golesa << " - " << golesb << " " << b.get_pais() << "\n";

        cout << "Goleadores A: ";
        for (int j = 0; j < 11; j++) {
            if (titulares_a[j].getCantidadGoles() > 0) {
                cout << "#" << titulares_a[j].getCamiseta() << " ";
            }
        }

        cout << "\nGoleadores B: ";
        for (int j = 0; j < 11; j++) {
            if (titulares_b[j].getCantidadGoles() > 0) {
                cout << "#" << titulares_b[j].getCamiseta() << " ";
            }
        }

        cout << "\n";
    }
}
void ordenar_grupo(equipo grupo[4]) {

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {

            int dg_i = grupo[i].get_goles_favor() - grupo[i].get_goles_contra();
            int dg_j = grupo[j].get_goles_favor() - grupo[j].get_goles_contra();

            if (
                grupo[j].get_puntos() > grupo[i].get_puntos() ||
                (grupo[j].get_puntos() == grupo[i].get_puntos() && dg_j > dg_i) ||
                (grupo[j].get_puntos() == grupo[i].get_puntos() && dg_j == dg_i &&
                 grupo[j].get_goles_favor() > grupo[i].get_goles_favor())
                ) {
                equipo temp = grupo[i];
                grupo[i] = grupo[j];
                grupo[j] = temp;
            }
        }
    }
}

void copia_grupos(equipo copia[12][4],equipo grupos[12][4]){
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 4; j++) {
            copia[i][j] = grupos[i][j];
        }
    }
}
jugador *extraerjugadores(equipo a){
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
