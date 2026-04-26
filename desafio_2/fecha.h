#ifndef FECHA_H
#define FECHA_H

class fecha
{
private:
    int dia;
    int mes;
    int anio;
    int hora;
public:
    fecha();
    fecha(int day, int month, int year);
    fecha(int day, int month, int year, int hour);


    void aumentar_dia();
    void aumentar_hora();
    void aumentar_mes();
    void aumentar_anio();
    void aumentar_mas_dias(int a);

    int get_dia() const;
    int get_mes() const;
    int get_anio() const;
    int get_hora() const;


    void set_dia(int a);
    void set_mes(int a);
    void set_anio(int a);
    void set_hora(int a);
    void set_fecha(int d, int m, int a);
    void set_fecha(int d, int m, int a, int h);

    fecha(const fecha& otra);
};

#endif // FECHA_H
