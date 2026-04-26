#ifndef PARTIDO_H
#define PARTIDO_H
#include <string>
#include "equipo.h"
#include "fecha.h"
class partido
{
private:
    string estadio;
    string codigo_arbitro1;
    string codigo_arbitro2;
    string codigo_arbitro3;
    equipo grupo1;
    equipo grupo2;
    fecha cuando;
    char grupo;
public:
    partido();
    partido(string stadio, string codigo1, string codigo2, string codigo3, equipo a, equipo b, char grupo);
    partido(string stadio, string codigo1, string codigo2, string codigo3, equipo a, equipo b, fecha dia, char grupo);

    string get_estadio() const;
    string get_arbitro1() const;
    string get_arbitro2() const;
    string get_arbitro3() const;
    equipo get_equipo1() const;
    equipo get_equipo2() const;
    fecha get_fecha() const;
    equipo& get_equipo1();
    equipo& get_equipo2();


    void set_fecha(fecha f);

};

#endif // PARTIDO_H
