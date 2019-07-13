//
//  main.cpp
//  ProyectoFinal
//
//  Created by Angie Borda on 13/07/19.
//  Copyright © 2019 KevinBorda. All rights reserved.
//

#include <iostream>
#include "lista.h"

using namespace std;


struct paseo{
    //Falta poner la fecha y las horas de inicio
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
    int Nperros, NViajes;
    lista<perro> perros;
};
struct paseador{
    string nombre, apellido, identificacion;
    string tipoId;
    string sexo;
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



int menu1();
int menuCliente(lista<cliente> clientes);
int menuPaseador();
int menuAdministrador();
bool comprobar (lista<cliente> Clientes, string nuemro);


int main(int argc, const char   * argv[]) {
    lista <cliente> clientes;
    int opc1=menu1();
    cliente C;
    string tipo;
    if (opc1==1){
        int opc2=menuCliente(clientes);
        if (opc2==1){
            cout<<"Eres nuevo, bienvenido, por favor llena estos datos"<<endl;
            cout<<"Nombre (solo 1)"<<endl;
            string nombre;
            cin>>nombre;
            C.nombre=nombre;
            cout<<"Apellido (solo 1)"<<endl;
            cin>>nombre;
            C.apellido=nombre;
            cout<<"Localidad donde vive"<<endl;
            cin>>nombre;
            C.localidad=nombre;
            cout<<"Numero de identificacion"<<endl;
            cin>>nombre;
            C.identificacion=nombre;
            cout<<"Cuantos perros tienes"<<endl;
            int n;
            cin>>n;
            C.Nperros=n;
            cout<<"Sexo"<<endl;
            cin>>nombre;
            C.sexo=nombre;
            cout<<"Muy bien has quedado registrado de manera corrcta"<<endl;
            cout<<"Te esperamos pronto "+C.nombre<<endl;
            clientes.insertar_final(C);
            
        }

            
    }
    else if (opc1==2)
        tipo = "Paseador";
    else
        tipo = "Administrador";
    
    
    
    return 0;
}


int menu1(){
    cout<<"Buen dia."<<endl;
    int opc=4;
    
    while (opc!=1 && opc!=2 && opc!=3){
        cout<<"1) Si eres cliente."<<endl;
        cout<<"2) Si eres paseador."<<endl;
        cout<<"3) Si eres administrador."<<endl;
        cin>>opc;
    }
    return opc;
}

int menuCliente(lista <cliente> clientes){
    string id;
    cliente C;
    cout<<"Por favor ingresa tu numero de documento"<<endl;
    cin >> id;
    
    bool nuevo = false;
    nuevo = comprobar(clientes, "cliente");
    //Comprobamos si es un usuario que ya esta en la lista o no
    if (nuevo)
        return 1;
    else {
        cout <<"Bienvenido de nuevo"<<endl;
        return 2;
    }
    
}
bool comprobar (lista<cliente> Clientes, string nuemro){
    lista<cliente> aux = Clientes;
    bool reto=false;
    while (!aux.lista_vacia() && !reto){
        if (aux.buscar(1).identificacion==nuemro){
            reto=true;
        }
        else
            aux.borrar_nodo(1);
    }
    return reto;
};
