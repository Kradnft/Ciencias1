 //
//  main.cpp
//  ProyectoFinal
//
//  Created by Angie Borda on 13/07/19.
//  Copyright � 2019 KevinBorda. All rights reserved.
//

#include <iostream>
#include "lista.h"
#include "interfaz.h"
#include "structs.h"
#include <fstream>
#include <vector>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp> 


using namespace std;



int menu1();
int validarCliente(lista<cliente> clientes);
int validarPaseador(lista <paseador> paseadores);
int menuCV();
int menuPV();
int menuAdministrador();
void imprimirClientes(lista<cliente> Clientes);
bool comprobarliente (lista<cliente> Clientes, string nuemro);
string leerArchivo(ifstream archivo);
cliente registrarCliente(cliente Cl);
cliente buscarPorId (lista<cliente> Clientes);
paseador comprobarP(lista <paseador> paseadores, string identificador);
paseador registrarPaseador(paseador Pa);
lista<cliente> llenarClientes(lista<cliente> Clientes);
perro registarPerro(perro P);
paseo newPaseo(string localidad, int hora,int dia, int mes, int duracion);

int main(int argc, const char   * argv[]) {
    lista <cliente> clientes;
    lista <administrador> administradores;
    lista <paseador> paseadores;
    lista <perro> perros;
    lista <paseo> paseos;
    ifstream clientesArchivo("clientes.txt");
    ifstream paseadoresArchivo("paseadores.txt");
    ofstream myfile;
    int opc1=5;
    cliente C;
    paseador P;
    administrador A;
    paseo Paseo;

    string tipo;
    while (opc1!=4){
	opc1=menu1();
	    if (opc1==1){
	        int opc2=validarCliente(clientes);
	        if (opc2==1){
	            cout<<"Eres nuevo, bienvenido, por favor llena estos datos"<<endl;
	            C = registrarCliente(C);
	            cout<<"Te esperamos pronto "+C.nombre<<endl;
	            clientes.insertar_final(C);
	            Interfaz::imprimirClientes(clientes); 
	            string Mclientes;
	            Mclientes=leerArchivo(clientesArchivo);
				//Le suma a lo del archivo el nuevo cliente ingresado.
				mensaje += C.identificacion + "-"+C.apellido+"-"+C.nombre+"-"+C.localidad;
				mensaje += "-"+C.sexo;
				//Abre el archivo y le escribe lo que ya se tenia en los clientes mas el nuevo
				myfile.open ("clientes.txt");
				myfile << mensaje <<"\n";
				myfile.close();                       
	        }
	        
	        else {
	        	int opcC=-1;
	        	cout<<"Por favor ingrese de nuevo su documento"<<endl;
	        	string doc;
	        	clientes = llenarClientes(clientes);
	        	while (opcC<0){
	        		cin>>doc;
	        		C = buscarPorId(clientes, doc);
	        		opcC= menuCV();
	        		if (opcC==1){
	        			perro Pe;
	        			lista<perro> perros;
	        			Pe=registarPerro(Pe);
	        			perros.insertar_final(perro);
	        			C.Nperros=C.Nperros+1;
	        			C.perros=perros;
					}
					else if (opcC==2){
						//De la lista del cliente cogemos su primer perro
						perro prro = C.perros.buscar(1);
						int dia=0, hora=0, mes=0;
						cout<<"Ingrese mes del paseo"<<endl;
						while (12<mes||mes<1)
							cin>>mes;					
						cout<<"Ingrese dia del paseo"<<endl;
						while (30<dia||mes<1)
							cin>>dia;
						cout<<"Ingrese hora del paseo (Nuestro horario es de 8:00 a 20:00)"<<endl;
						while (20<mes||mes<8)
							cin>>hora;
						cout<<"Ingrese localidad"<<endl;
						string localidad;
						cin>>localidad;
						inr dura;
						cout<<"Ingrese duracion del paseo (1 o 2 horas)"<<endl;
						while (2<dura||dura<1)
							cin>>dura;
						
						Paseo = newPaseo(localidad,hora,dia,mes, dura);
						prro.paseos.insertar_final(Paseo);
						
						
					}
					else if (opcC==3){
						//De la lista del cliente cogemos su primer perro
						//TOCA ARREGLAR PARA VER CUAL ES EL QUE SE VA A CANCELAR
						perro prro = C.perros.buscar(1);
						prro.paseos.borrar_nodo(1);
						prro.paseos.insertar_inicio(Paseo);
					}
					else {
	        			C = buscarPorId(clientes, doc);
	        			imprimirPerros(C.perros);
					}
	
				}
	        	
			}
	
	            
	    }
	    else if (opc1==2)
	        tipo = "Paseador";
	        int opcP=-1;
	        while (opcP<0){
	        	opcP = validarPaseador(Paseadores);
			}
			if (opcP==1){
				P = registrarPaseador(P);
				Paseadores.insertar_final(P);
				string MPaseadores;
	            MPaseadores=leerArchivo(paseadoresArchivo);
	            MPaseadores += P.identificacion+"-"+P.nombre+"-"+P.apellido+"-"+P.edad+"-"+P.cel+"-"+P.barrio;
	            myfile.open ("paseadores.txt");
				myfile << mensaje <<"\n";
				myfile.close();   
			}
			else{
				cout <<"Por favor ingrese de nuevo su documento"<<endl;
				string doc;
				cin>>doc;
				int opcPV;
				opcPV=menuPV();
				//FALTA EL DE ABAJO SIMILAR AL DE CLIENTES
				//paseadores=llenarPaseadores(paseadores);
				//FALTA CREAR ALGO PARA EL METODO DE ABAJO SIMILAR AL DE CLIENTES
				//P=buscarPaseadorID(paseadores, doc);
				if (opcPV==1){
					//FALTA METODO DE ABAJO
					//P=definirHorario(P);
				}
				//EN LO DE ABAJO TOCA UN METODO QUE NOS DEVUELVA LA POSICION DEL PASEADOR A BORRAR
				else 
					//paseadores.borrar_nodo(1);
				
				
				
			}
			//FALTA TODO ESTO, CREO QUE ESTE ES EL QUE HACE LAS CONSUTLTAS
	    else
	        tipo = "Administrador";
	}
    
    
    return 0;
}


string leerArchivo(ifstream archivo){
	string line, mensaje;
	while(getline(clientesArchivo, line)){
		cout<<"Leyendo:"<<line <<endl;	
	    mensaje += line + "\n";
	}
	
	return mensaje;
}

//Metodo paseo
//FALTA LLENAR BIEN ESTE METODO CON LA VALIDACION DE MANES QUE PUEDEN HACERLO Y TODO ESO
paseo newPaseo(string localidad, int hora,int dia, int mes, int duracion){
	paseo pas;
	
	return pas;
}



//Metodos perros
perro registarPerro(perro P){
	cout<<"Nombre"<<endl;
    string nombre;
    cin>>nombre;
    P.nombre=nombre;
    cout<<"Raza"<<endl;
    cin>>nombre;
    P.raza=nombre;
    cout<<"Tamanio (GRANDE-MEDIANO-PEQUENIO)"<<endl;
    cin>>nombre;
    P.tamanio=nombre;
    cout<<"Tipo de comida que come"<<endl;
    cin>>nombre;
    P.Tcomida=nombre;
    cout<<"Edad"<<endl;
    int n=0;
    while (n<0)
    	cin>>n;
    P.edad=n;
    return P;
    
    
}


//Metodos paseadoeres
//Miramos si es nuevo o viejo
int validarPaseador(lista <paseador> Paseadores){
	string id;
    paseador P;
    cout<<"Por favor ingresa tu numero de documento"<<endl;
    cin >> id;
    P = comprobarP(Paseadores, id);
	if (!P)
		return 1;
	else
		return 2; 
}
//Miramos si ya existe dento de la lista
paseador comprobarP(lista <paseador> paseadores, string identificador){
	
}
//Registro de un nuevo paseador
paseador registrarPaseador(paseador Pa){
	cout<<"Nombre (solo 1)"<<endl;
    string nombre;
    cin>>nombre;
    Pa.nombre=nombre;
    cout<<"Apellido (solo 1)"<<endl;
    cin>>nombre;
    Pa.apellido=nombre;
    cout<<"Localidad donde vive"<<endl;
    cin>>nombre;
    Pa.localidad=nombre;
    
    cout<<"Tipo de identificacion"<<endl;
    cin>>nombre;
    Pa.identificacion=nombre;
    
    cout<<"Numero de identificacion"<<endl;
    cin>>nombre;
    Pa.identificacion=nombre;
    
    cout<<"Tu edad"<<endl;
    while (n<18)
    	cin>>n;
    Pa.edad=n;
    //ingresarPerros(n,C);
    cout<<"Sexo (M o F)"<<endl;
    while (nombre!="M" && nombre!="F")
    	cin>>nombre;
    Pa.sexo=nombre;
    cout<<"Tu telefono celular"<<endl;
    cin>>nombre;
    Pa.cel=nombre;
    cout<<"Telefono fijo"<<endl;
    cin>>nombre;
    Pa.fijo=nombre;
    
    cout<<"Correo"<<endl;
    cin>>nombre;
    Pa.correo=nombre;
    
    cout<<"Pais de nacimiento"<<endl;
    cin>>nombre;
    Pa.paisN=nombre;
    
    cout<<"Ciudad de nacimiento"<<endl;
    cin>>nombre;
    Pa.cidudadN=nombre;
    
    cout<<"Barrio donde vives"<<endl;
    cin>>nombre;
    Pa.barrio=nombre;

    cout<<"De que calle a que calle vas a trabajar:"<<endl;
    cout<<"Calle donde empiezas (nuestra cobertura es desde la 0 hasta la 80)";
    int Cin=-1, Cfin=-1;
    while (!80>Cin>0){
    	cin>>Cin;
	}
	cout<<"Calle donde finalizas (nuestra cobertura es desde la 0 hasta la 80)";
    while (!80>Cfin>0){
    	cin>>Cfin;
	}
    cout<<"Carrera donde empiezas (nuestra cobertura es desde la 0 hasta la 80)";
    int Kin=-1, Kfin=-1;
    while (!80>Cin>0){
    	cin>>Kin;
	}
	cout<<"Carrera donde finalizas (nuestra cobertura es desde la 0 hasta la 80)";
    while (!80>Cfin>0){
    	cin>>Kfin;
	}
	
    Pa.cllIn=Cin;
    Pa.cllFin=Cfin;
    Pa.craIn=Kin;
    Pa.craFin=Kfin;
    
    
    
    
    cout<<"Muy bien has quedado registrado de manera corrcta"<<endl;
	return cl;
}
int menuPV(){
	cout<<"Que deseas hacer: "<<endl;
	cout<<"1) Cambiar mi horario"<<endl;
	cout<<"2) Renunciar"<<endl;
	int opc=5;
	while (opc>4 || opc<1)
		cin>>opc;
}


//Metodos clientes
//Menu cliente antiguo
int menuCV(){
	
	cout<<"Que deseas hacer: "<<endl;
	cout<<"1) Registrar un nuevo perro"<<endl;
	cout<<"2) Agendar un nuevo paseo"<<endl;
	cout<<"3) Cancelar un paseo"<<endl;
	cout<<"4) Ver lista de perros"<<endl;
	int opc=5;
	while (opc>4 || opc<1)
		cin>>opc;	
}
//Buscar cliente por un ID dado
cliente buscarPorId(lista<cliente> Clientes, string id){
	cliente cl;
	bool encontrado = false;
	int pos = 1;
	while (!encontrado){
		if (Clientes.buscar(pos).identificacion==id){
			cl = Clientes.buscar(pos);
			encontrado=true;
		}
		pos++;	
	}
	return cl;
} 
//Registro de un nuevo cliente
cliente registrarCliente(cliente cl){
	cout<<"Nombre (solo 1)"<<endl;
    string nombre;
    cin>>nombre;
    cl.nombre=nombre;
    cout<<"Apellido (solo 1)"<<endl;
    cin>>nombre;
    cl.apellido=nombre;
    cout<<"Localidad donde vive"<<endl;
    cin>>nombre;
    cl.localidad=nombre;
    cout<<"Numero de identificacion"<<endl;
    cin>>nombre;
    cl.identificacion=nombre;
    cout<<"Cuantos perros tienes"<<endl;
    int n=-1;
    while (n<0)
    	cin>>n;
    cl.Nperros=n;
    cout<< "Datos del perro: "<<endl;
    while (n>0){
    	perro per;
    	per = registrarPerro;
    	cl.perros.insertar_final(per);
	}
    cout<<"Datos tuyo de nuevo" <<endl;
    cout<<"Ingresa tu edad"<<endl;
    while (n<15)
    	cin>>n;
    cl.edad=n;
    //ingresarPerros(n,C);
    cout<<"Sexo (M o F)"<<endl;
    while (!nombre.compare("M")==0)
    	cin>>nombre;
    cl.sexo=nombre;
    cout<<"Muy bien has quedado registrado de manera corrcta"<<endl;
	return cl;
}
//Miramos si es nuevo o viejo
int validarCliente(lista <cliente> clientes){
    string id;
    cliente C;
    cout<<"Por favor ingresa tu numero de documento"<<endl;
    cin >> id;
    
    bool nuevo = false;
    nuevo = comprobarCliente(clientes, id);
    
    //Comprobamos si es un usuario que ya esta en la lista o no
    if (nuevo)
        return 1;
    else {
        cout <<"Bienvenido de nuevo"<<endl;
        return 2;
    }
    
}
//LLena la lista de clientes con los que hay en el archivo de texto
lista<cliente> llenarClientes(lista<cliente> Clientes){
	cliente x;
    ifstream lect("clientes.txt");
    string mensaje,line;

	while(getline(lect, line)){
			    mensaje += line + "\n";
	
	}
    vector<string> clientes, atributos; 
    boost::split(clientes, mensaje, boost::is_any_of("\n")); 
	for (int i = 0; i < clientes.size(); i++) {
    	boost::split(atributos, clientes[i], boost::is_any_of("-")); 
    	x.identificacion = atributos[0];
    	x.nombre = atributos[2];
    	x.apellido = atributos[1];
    	x.localidad = atributos[3];
    	x.sexo = atributos[4];
    	Clientes.insertar_final(x);
	}
	return Clientes;
}
//Miramos si ya existe dento de la lista
bool comprobarCliente (lista<cliente> Clientes, string nuemro){
    lista<cliente> aux = llenarClientes(Clientes);
    cliente x;
    bool reto=true;

    for (int r=1; r<=aux.get_tam; r++){
		x = aux.buscar(r);
		if (x.identificacion==nuemro)
			reto = false;
	}
    return reto;
};

//Menu inicial 

int menu1(){
    cout<<"Buen dia."<<endl;
    int opc=5;
    
    while (opc!=1 && opc!=2 && opc!=3 &&opc!=4){
        cout<<"1) Si eres cliente."<<endl;
        cout<<"2) Si eres paseador."<<endl;
        cout<<"3) Si eres administrador."<<endl;
        cout<<"4) Salir. "<<endl;
        cin>>opc;
    }
    return opc;
}

