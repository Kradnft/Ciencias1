#include <iostream>
#include "lista.h"

#ifndef STRUCTS_H
#define STRUCTS_H


struct paseo{
    //Falta poner la fecha y las horas de inicio. kevin tonto
    string Npaseador;
    string Tactividad;
    string Observaciones;
};

struct perro{
    string nombre, raza, tamanio, Tcomida;
    int edad;
    lista <paseo> paseos;
};

struct cliente{
    string nombre, apellido, identificacion, localidad;
    string sexo;
    int Nperros, NViajes, edad;
    lista<perro> perros;
};
struct paseador{
    string nombre, apellido, identificacion;
    string tipoId;
    string sexo, localidad;
    string cel, fijo, correo, cidudadN, paisN, barrio;
    int NperrosAct, edad, NViajes;
    int cllIn, cllFin, craIn, craFin;
    lista <paseo> paseos;

    //Falta ver como manejra horario
};
struct sucursal{
    string nombre, localidad;
    int calle, carrera;
    int Npaseadores, NClientes;
    int cllIn, cllFin, craIn, craFin;
};

struct administrador{
    string nombre, identificacion;
};

#endif
