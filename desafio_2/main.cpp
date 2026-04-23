#include <iostream>
#include "equipo.h"
#include "jugador.h"
#include <fstream>
#include <string>
#include <random>
using namespace std;
/*prototipado*/
int char_a_entero(string a);
equipo* agrandarArreglo(equipo* viejo, int &tam);
int numero_random();
int sorteo_bombo();
string producir_nombre();
string producir_apellido();
void inicializar_en_cero(int arreglo[], int tam);
bool bombo_representado(int arreglo[], int tam, int a);
/*prototipado*/
int main()
{
    fstream documento;
    equipo equipo1;
    string pail, tecnico, confe, fede, dato_extraido = "";
    int ranking, goles_f, goles_c, partido_g,partido_l,partido_e,falta, tarjeta_a,tarjeta_r;
    char caracter;
    char *apuntador, arreglo[35];
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
        }
    }
    documento.close();
    /*creaacion de los bombos*/
    int tamano_bombo = 12;
    equipo* temporal = new equipo[cantidad_equipos];
    equipo* bombo1 = new equipo[tamano_bombo];
    equipo* bombo2 = new equipo[tamano_bombo];
    equipo* bombo3 = new equipo[tamano_bombo];
    equipo* bombo4 = new equipo[tamano_bombo];
    int posicion_unida;
    for (int i = 0; i < cantidad_equipos; i++){
        if (equipos[i].get_pais() == "United States"){
            posicion_unida = i;
            break;
        }
    }
    for (int c = 0; c < cantidad_equipos; c++){
        if (c == 0){
            temporal[0] = equipos[posicion_unida];
        }
        else if (c == posicion_unida){
            temporal[c] = equipos[0];
        }
        else {
            temporal[c] = equipos[c];
        }
    }
    for (int i = 0; i < cantidad_equipos; i++){
        if (i < tamano_bombo){
            bombo1[i] = equipos[i];
        }
        else if (i < tamano_bombo * 2){
            bombo2[i - tamano_bombo] = equipos[i];
        }
        else if (i < tamano_bombo * 3){
            bombo3[i - tamano_bombo * 2] = equipos[i];
        }
        else if (i < tamano_bombo * 4){
            bombo4[i - tamano_bombo * 3] = equipos[i];
        }
    }
    delete[] temporal;
    string pais_jugador, nombre_jugador, apellido_jugador;
    int numero_camiseta, cantidad_goles_jugador, cantidaad_faltas_jugador, cantidad_amarillas_jugador, cantidad_rojas_jugador, tiempo_jugado, partidos_jugados;
    int miembros_equipo = 26;
    for (int a = 0; a < cantidad_equipos; a++){
        int contador_miembros = 1;
        string pais = equipos[a].get_pais();
        while (miembros_equipo >= contador_miembros){
            numero_camiseta = contador_miembros;
            nombre_jugador = producir_nombre();
            apellido_jugador = producir_apellido();
            jugador a_jugador(pais,numero_camiseta,nombre_jugador,apellido_jugador);
            equipos[a].agregar_jugador(a_jugador);
            contador_miembros++;
        }
    }
    equipo grupos[12][4];
    char letra_grupo[12] = {'a','b','c','d','e','f','g','h','i','j','k','l'};
    bool confirmacion_grupos = false;
    int representante_1_valores[12];
    int representante_2_valores[12];
    int representante_3_valores[12];
    int representante_4_valores[12];
    inicializar_en_cero(representante_1_valores, 12);
    inicializar_en_cero(representante_2_valores, 12);
    inicializar_en_cero(representante_3_valores, 12);
    inicializar_en_cero(representante_4_valores, 12);
    for (int contador_grupos = 0; contador_grupos < 12; contador_grupos++){
        bool confirmacion = false;
        while (confirmacion == false){
            int representante_1 = sorteo_bombo();
            int representante_2 = sorteo_bombo();
            int representante_3 = sorteo_bombo();
            int representante_4 = sorteo_bombo();
            if (bombo_representado(representante_1_valores, contador_grupos, representante_1) == false ||
                bombo_representado(representante_2_valores, contador_grupos, representante_2) == false ||
                bombo_representado(representante_3_valores, contador_grupos, representante_3) == false ||
                bombo_representado(representante_4_valores, contador_grupos, representante_4) == false){
                continue;
            }
            equipo grupo_prueba[4] = { bombo1[representante_1],bombo2[representante_2],bombo3[representante_3],bombo4[representante_4]};
            int contador_uefa = 0;
            confirmacion = true;
            for (int i = 0; i < 4; i++){
                for (int j = i + 1; j < 4; j++){
                    if (grupo_prueba[i].get_confederacion() == grupo_prueba[j].get_confederacion()){
                        if (grupo_prueba[i].get_confederacion() == "UEFA"){
                            contador_uefa++;
                            if (contador_uefa > 1){
                                confirmacion = false;
                            }
                        }
                        else{
                            confirmacion = false;
                        }
                    }
                }
            }
            if (confirmacion == true){
                representante_1_valores[contador_grupos] = representante_1;
                representante_2_valores[contador_grupos] = representante_2;
                representante_3_valores[contador_grupos] = representante_3;
                representante_4_valores[contador_grupos] = representante_4;
                for (int i = 0; i < 4; i++){
                    grupos[contador_grupos][i] = grupo_prueba[i];
                }
            }
        }
    }
    delete[] bombo1;
    delete[] bombo2;
    delete[] bombo3;
    delete[] bombo4;
    for (int i = 0; i < 12; i++){
        cout << "Grupo " << letra_grupo[i] << ":\n";
        for (int j = 0; j < 4; j++){
            cout << grupos[i][j].get_pais()
            << " (" << grupos[i][j].get_confederacion() << ")\n";
        }
        cout << endl;
    }
    delete[] equipos;
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
jugador* agrandarJugadores(jugador* viejo, int &tam){
    jugador* nuevo = new jugador[tam + 1];
    for (int i = 0; i < tam; i++){
        nuevo[i] = viejo[i];
    }
    delete[] viejo;
    tam++;
    return nuevo;
}
int numero_random(){
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dis(1,30);
    int numero = dis(gen);
    return numero;
}
int sorteo_bombo(){
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dis(0,11);
    int numero = dis(gen);
    return numero;
}
string producir_nombre(){
    int posicion_nombre = numero_random(), contador = 1;
    fstream nombres;
    string nombre, nombre_guardado;
    nombres.open("nombres.txt",ios::in);
    while (getline(nombres,nombre)) {
        if (posicion_nombre == contador){
            nombre_guardado = nombre;
            break;
        }
        else{
            contador++;
        }
    }
    return nombre_guardado;
}
string producir_apellido(){
    int posicion_apellido = numero_random(), contador = 1;
    fstream apellidos;
    string apellido, apellido_guardado;
    apellidos.open("apellidos.txt",ios::in);
    while (getline(apellidos,apellido)) {
        if (posicion_apellido == contador){
            apellido_guardado = apellido;
            break;
        }
        else{
            contador++;
        }
    }
    return apellido_guardado;
}
equipo inicializar_valores_grupos(){

}
void inicializar_en_cero(int arreglo[], int tam){
    for (int i = 0; i < tam; i++){
        arreglo[i] = -1;
    }
}
bool bombo_representado(int arreglo[], int tam, int a){
    bool regresar = true;
    for (int b = 0; b < tam; b++){
        if (arreglo[b] == a){
            regresar = false;
        }
    }
    return regresar;
}
