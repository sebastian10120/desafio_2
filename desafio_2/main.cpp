#include <iostream>
#include "equipo.h"
#include "jugador.h"
#include <fstream>
#include <string>
using namespace std;
/*prototipado*/
int char_a_entero(string a);
equipo* agrandarArreglo(equipo* viejo, int &tam);
/*prototipado*/
int main()
{
    fstream documento;
    equipo equipo1;
    string pail, tecnico, confe, fede, dato_extraido = "";
    int ranking, goles_f, goles_c, partido_g,partido_l,partido_e,falta, tarjeta_a,tarjeta_r;
    char caracter;
    int posicion_caracter = 0, posicion_inicial = 0, valor,fila_con_valor = 0;
    int cantidad_equipos = 0;
    equipo* equipos = new equipo[0];
    documento.open("selecciones_clasificadas_mundial.csv",ios::in);
    while (getline(documento,dato_extraido)){
        if (fila_con_valor < 2){
            fila_con_valor++;
        }
        else if (fila_con_valor >= 2){
            valor = 1;
            posicion_inicial = 0;
            string fila_cortada;
            for (int n = 0; n < dato_extraido.length();n++){
                if (dato_extraido[n] == ';' || dato_extraido[n] == '\n'){
                    if (valor == 1){
                        fila_cortada = dato_extraido.substr(posicion_inicial, n-posicion_inicial);
                        posicion_inicial = n;
                        ranking = char_a_entero(fila_cortada);
                        fila_cortada = "";
                        valor++;
                    }
                    else if (valor == 2){
                        fila_cortada = dato_extraido.substr(posicion_inicial+1, n-posicion_inicial-1);
                        posicion_inicial = n;
                        pail = fila_cortada;
                        fila_cortada = "";
                        valor++;
                    }
                    else if (valor == 3){
                        fila_cortada = dato_extraido.substr(posicion_inicial+1, n-posicion_inicial-1);
                        posicion_inicial = n;
                        tecnico = fila_cortada;
                        fila_cortada = "";
                        valor++;
                    }
                    else if (valor == 4){
                        fila_cortada = dato_extraido.substr(posicion_inicial+1, n-posicion_inicial-1);
                        posicion_inicial = n;
                        fede = fila_cortada;
                        fila_cortada = "";
                        valor++;
                    }
                    else if (valor == 5){
                        fila_cortada = dato_extraido.substr(posicion_inicial+1, n-posicion_inicial-1);
                        posicion_inicial = n;
                        confe = fila_cortada;
                        fila_cortada = "";
                        valor++;
                    }
                    else if (valor == 6){
                        fila_cortada = dato_extraido.substr(posicion_inicial+1, n-posicion_inicial-1);
                        posicion_inicial = n;
                        goles_f = char_a_entero(fila_cortada);
                        fila_cortada = "";
                        valor++;
                    }
                    else if (valor == 7){
                        fila_cortada = dato_extraido.substr(posicion_inicial+1, n-posicion_inicial-1);
                        posicion_inicial = n;
                        goles_c = char_a_entero(fila_cortada);
                        fila_cortada = "";
                        valor++;
                    }
                    else if (valor == 8){
                        fila_cortada = dato_extraido.substr(posicion_inicial+1, n-posicion_inicial-1);
                        posicion_inicial = n;
                        partido_g = char_a_entero(fila_cortada);
                        fila_cortada = "";
                        valor++;
                    }
                    else if (valor == 9){
                        fila_cortada = dato_extraido.substr(posicion_inicial+1, n-posicion_inicial-1);
                        posicion_inicial = n;
                        partido_e = char_a_entero(fila_cortada);
                        fila_cortada = "";
                        valor++;
                    }
                }
            }
            if (valor == 10){
                fila_cortada = dato_extraido.substr(posicion_inicial+1);
                partido_l = char_a_entero(fila_cortada);
                fila_cortada = "";
            }
            equipos = agrandarArreglo(equipos, cantidad_equipos);
            equipos[cantidad_equipos - 1] = equipo(ranking, pail, tecnico, fede, confe,goles_f, goles_c, partido_g, partido_e, partido_l);
            cout << equipos[cantidad_equipos - 1].get_ranking_fifa() << "|"
                 << equipos[cantidad_equipos - 1].get_pais() << "|"
                 << equipos[cantidad_equipos - 1].get_director() << "|"
                 << equipos[cantidad_equipos - 1].get_federacion() << "|"
                 << equipos[cantidad_equipos - 1].get_confederacion() << "|"
                 << equipos[cantidad_equipos - 1].get_goles_favor() << "|"
                 << equipos[cantidad_equipos - 1].get_goles_contra() << "|"
                 << equipos[cantidad_equipos - 1].get_partidos_ganados() << "|"
                 << equipos[cantidad_equipos-1].get_partidos_empatados() << "|"
                 << equipos[cantidad_equipos-1].get_partidos_perdidos() << "|"
                 << equipos[cantidad_equipos-1].get_faltas() << "|"
                 << equipos[cantidad_equipos-1].get_tarjetas_amarillas() << "|"
                 << equipos[cantidad_equipos-1].get_tarjetas_rojas() << "|" << endl;
        }
    }
    delete[] equipos;
    documento.close();
}
int char_a_entero(string a){
    int numero = 0;
    for (int i = 0; i < a.length(); i++) {
        numero = numero * 10 + (a[i] - '0');
    }
    return numero;
}
equipo* agrandarArreglo(equipo* viejo, int &tam){
    equipo* nuevo = new equipo[tam + 1];
    for (int i = 0; i < tam; i++){
        nuevo[i] = viejo[i];
    }
    delete[] viejo;
    tam++;
    return nuevo;
}
