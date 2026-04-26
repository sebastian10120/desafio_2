#include "fecha.h"

fecha::fecha() {

}
fecha::fecha(int day, int month, int year){
    dia = day;
    mes = month;
    anio = year;
    hora = 0;
}
fecha::fecha(int day, int month, int year, int hour){
    dia = day;
    mes = month;
    anio = year;
    hora = hour;
}


void fecha::aumentar_dia() {
    dia++;
    if (dia > 30) {
        dia = 1;
        aumentar_mes();
    }
}
void fecha::aumentar_hora() {
    hora++;
    if (hora >= 24) {
        hora = 0;
        aumentar_dia();
    }
}
void fecha::aumentar_mes() {
    mes++;
    if (mes > 12) {
        mes = 1;
        aumentar_anio();
    }
}
void fecha::aumentar_anio() {
    anio++;
}
void fecha::aumentar_mas_dias(int a){
    dia = dia + a;

    while (dia > 30) {
        dia = dia - 30;
        aumentar_mes();
    }
}
int fecha::get_dia() const {
    return dia;
}

int fecha::get_mes() const {
    return mes;
}

int fecha::get_anio() const {
    return anio;
}

int fecha::get_hora() const {
    return hora;
}


void fecha::set_dia(int d){
    dia = d;
}

void fecha::set_mes(int m){
    mes = m;
}

void fecha::set_anio(int a){
    anio = a;
}

void fecha::set_hora(int h){
    hora = h;
}
void fecha::set_fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}
void fecha::set_fecha(int d, int m, int a, int h){
    dia = d;
    mes = m;
    anio = a;
    hora = h;
}

fecha::fecha(const fecha& otra) {
    dia = otra.dia;
    mes = otra.mes;
    anio = otra.anio;
    hora = otra.hora;
}
