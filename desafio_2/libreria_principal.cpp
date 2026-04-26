#include <iostream>
#include "equipo.h"
#include "jugador.h"
#include "fecha.h"
#include "partido.h"
#include <fstream>
#include <string>
#include <random>
using namespace std;


/*generacion de grupos, partidos, equipos, jugadores*/
void eliminar_matriz_equipo(equipo **a){
    for (int i = 0; i < 4; i++) {
        delete[] a[i];
    }
    delete[] a;
}
int char_a_entero(string a){
    int numero = 0;
    for (int i = 0; i < a.length(); i++) {
        numero = numero * 10 + (a[i] - '0');
    }
    return numero;
}
partido* agrandarArreglopartidos(partido* viejo, int &tam){
    partido* nuevo = new partido[tam + 1];
    for (int i = 0; i < tam; i++){
        nuevo[i] = viejo[i];
    }
    delete[] viejo;
    tam++;
    return nuevo;
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
int numero_random(int a, int b){
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dis(a,b);
    int numero = dis(gen);
    return numero;
}
string producir_estadio() {
    int posicion_estadio = numero_random(0,10);
    int contador = 0;
    fstream estadios;
    string linea, estadio_guardado;
    estadios.open("estadios.txt", ios::in);
    while (getline(estadios, linea)) {
        if (posicion_estadio == contador) {
            estadio_guardado = linea;
            break;
        }
        contador++;
    }
    estadios.close();
    return estadio_guardado;
}
string producir_arbitro() {
    int posicion_arbitro = numero_random(0,10);
    int contador = 0;
    fstream arbitros;
    string linea, arbitro_guardado;
    arbitros.open("arbitros_codigos.txt", ios::in);
    while (getline(arbitros, linea)) {
        if (posicion_arbitro == contador) {
            arbitro_guardado = linea;
            break;
        }
        contador++;
    }
    arbitros.close();
    return arbitro_guardado;
}
string producir_nombre(){
    int posicion_nombre = numero_random(1,30), contador = 1;
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
    int posicion_apellido = numero_random(1,30), contador = 1;
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


/*generacion de grupos, partidos, equipos, jugadores*/
/*datos para la generacion de probabilidad de los partidos*/


double raizQuinta(double n) {
    double r = n;
    for(int i = 0; i < 20; i++) {
        r = (4.0 * r + n / (r*r*r*r)) / 5.0;
    }
    return r;
}

double potencia_0_4(double x) {
    return raizQuinta(x * x);
}

double potencia_0_6(double x) {
    return raizQuinta(x * x * x);
}


/*datos para la generacion de probabilidad de los partidos*/
/*generaacion de equipos*/
equipo *extraer_equipos(equipo* a, int &tam){
    string dato_extraido, pail, tecnico, fede, confe;
    fstream documento;
    int fila_con_valor = 0, valor, ranking, posicion_inicial, goles_f, goles_c,partido_g,partido_e,partido_l;

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
            if (valor >=10){
                a = agrandarArreglo(a, tam);
                a[tam - 1] = equipo(ranking, pail, tecnico, fede, confe,goles_f, goles_c, partido_g, partido_e, partido_l);
            }
        }
    }
    documento.close();
    return a;
}
void temporal_equipos(equipo *tem, int tam, equipo *original){
    int posicion_unida;
    for (int i = 0; i < tam; i++){
        if (original[i].get_pais() == "United States"){
            posicion_unida = i;
            break;
        }
    }
    for (int c = 0; c < tam; c++){
        if (c == 0){
            tem[0] = original[posicion_unida];
        }
        else if (c == posicion_unida){
            tem[c] = original[0];
        }
        else {
            tem[c] = original[c];
        }
    }
}
equipo** generar_bombos(equipo* original, int total, int tam_bombo) {
    equipo** bombos = new equipo*[4];
    for (int i = 0; i < 4; i++) {
        bombos[i] = new equipo[tam_bombo];
    }
    for (int i = 0; i < total; i++) {
        int num_bombo = i / tam_bombo;   // 0..3
        int pos = i % tam_bombo;         // 0..11
        bombos[num_bombo][pos] = original[i];
    }

    return bombos;
}
void añadir_jugadores(int tam, equipo *original){
    string pais_jugador, nombre_jugador, apellido_jugador;
    int numero_camiseta;
    int miembros_equipo = 26;
    for (int a = 0; a < tam; a++){
        int contador_miembros = 1;
        string pais = original[a].get_pais();
        while (miembros_equipo >= contador_miembros){
            numero_camiseta = contador_miembros;
            nombre_jugador = producir_nombre();
            apellido_jugador = producir_apellido();
            jugador a_jugador(pais,numero_camiseta,nombre_jugador,apellido_jugador);
            original[a].agregar_jugador(a_jugador);
            contador_miembros++;
        }
    }
}
void grupos_torneos(equipo a[][4], equipo **bombo, char *letras){
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
            int representante_1 = numero_random(0,11);
            int representante_2 = numero_random(0,11);
            int representante_3 = numero_random(0,11);
            int representante_4 = numero_random(0,11);
            if (bombo_representado(representante_1_valores, contador_grupos, representante_1) == false ||
                bombo_representado(representante_2_valores, contador_grupos, representante_2) == false ||
                bombo_representado(representante_3_valores, contador_grupos, representante_3) == false ||
                bombo_representado(representante_4_valores, contador_grupos, representante_4) == false){
                continue;
            }
            equipo grupo_prueba[4] = {
                bombo[0][representante_1],
                bombo[1][representante_2],
                bombo[2][representante_3],
                bombo[3][representante_4]
            };
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
                    a[contador_grupos][i] = grupo_prueba[i];
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < 12; i++){
        cout << "Grupo " << letras[i] << ":\n";
        for (int j = 0; j < 4; j++){ cout << "  " << a[i][j].get_pais()<< " | " << a[i][j].get_confederacion()   << endl;
        }

        cout << "----------------------\n";
    }
}
void generar_calendario(equipo grupos[12][4], partido*& lista_partido, int& tamanp_lista_partido, fecha inicio_eliminatoria,char *letras){

    int diafinal[48];
    int partidosPorDia[19];

    for(int i = 0; i < 48; i++){
        diafinal[i] = -10;
    }

    for(int i = 0; i < 19; i++){
        partidosPorDia[i] = 0;
    }

    equipo a;
    equipo b;

    for (int grupo = 0; grupo < 12; grupo++){
        for (int equipo_1 = 0; equipo_1 < 4; equipo_1++){
            for (int equipo_2 = equipo_1+1; equipo_2 < 4 ;equipo_2++){
                a = grupos[grupo][equipo_1];
                b = grupos[grupo][equipo_2];
                int idA = grupo * 4 + equipo_1;
                int idB = grupo * 4 + equipo_2;
                string campo_nombre = producir_estadio();
                string arbitro1,arbitro2,arbitro3;
                bool comprobar_arbitro = false;
                while(comprobar_arbitro == false){
                    arbitro1 = producir_arbitro();
                    arbitro2 = producir_arbitro();
                    arbitro3 = producir_arbitro();

                    if (arbitro1 == arbitro2 || arbitro1 == arbitro3 || arbitro3 == arbitro2){
                        comprobar_arbitro = false;
                    }
                    else{
                        comprobar_arbitro = true;
                    }
                }
                int dia_asignado = -1;
                int hora_guardar = 0;
                for(int d = 0; d < 19; d++){
                    if(partidosPorDia[d] < 4){
                        if(d - diafinal[idA] >= 4){
                            if(d - diafinal[idB] >= 4){
                                dia_asignado = d;
                                hora_guardar = partidosPorDia[d];
                                partidosPorDia[d]++;
                                diafinal[idA] = d;
                                diafinal[idB] = d;

                                break;
                            }
                        }
                    }
                }
                if(dia_asignado != -1){
                    fecha fecha_partido = inicio_eliminatoria;
                    for(int k = 0; k < dia_asignado; k++){
                        fecha_partido.aumentar_dia();
                    }
                    int horaBase = 10;
                    int horaPartido = horaBase + (hora_guardar * 2);
                    fecha_partido.set_hora(horaPartido);
                    partido partidol(campo_nombre,arbitro1,arbitro2,arbitro3,a,b, letras[grupo]);
                    partidol.set_fecha(fecha_partido);
                    lista_partido = agrandarArreglopartidos(lista_partido, tamanp_lista_partido);
                    lista_partido[tamanp_lista_partido - 1] = partidol;
                }
            }
        }
    }
}
/*generaacion de equipos*/
