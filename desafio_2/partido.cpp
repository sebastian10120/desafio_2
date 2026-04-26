#include "partido.h"


partido::partido() {
    estadio = "";
    codigo_arbitro1 = "";
    codigo_arbitro2 = "";
    codigo_arbitro3 = "";
}
partido::partido(string stadio, string codigo1, string codigo2, string codigo3, equipo a, equipo b, char ch) {
    estadio = stadio;
    codigo_arbitro1 = codigo1;
    codigo_arbitro2 = codigo2;
    codigo_arbitro3 = codigo3;
    grupo1 = a;
    grupo2 = b;
    grupo = ch;
    cuando = fecha();

}

partido::partido(string stadio, string codigo1, string codigo2, string codigo3, equipo a, equipo b, fecha dia, char ch) {
    estadio = stadio;
    codigo_arbitro1 = codigo1;
    codigo_arbitro2 = codigo2;
    codigo_arbitro3 = codigo3;
    grupo1 = a;
    grupo2 = b;
    cuando = dia;
    ;
    grupo = '\0';
}


string partido::get_estadio() const {
    return estadio;
}

string partido::get_arbitro1() const {
    return codigo_arbitro1;
}
string partido::get_arbitro2() const {
    return codigo_arbitro2;
}

string partido::get_arbitro3() const {
    return codigo_arbitro3;
}

equipo partido::get_equipo1() const {
    return grupo1;
}

equipo partido::get_equipo2() const {
    return grupo2;
}

fecha partido::get_fecha() const {
    return cuando;
}

void partido::set_fecha(fecha f){
    cuando = f;
}
