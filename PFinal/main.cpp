 //
//  main.cpp
//  ProyectoFinal
//
//  Created by Angie Borda on 13/07/19.
//  Copyright © 2019 KevinBorda. All rights reserved.
//

#include <iostream>
#include "lista.h"
#include "interfaz.h"
#include "structs.h"
#include <fstream>
#include <vector>



using namespace std;



int menu1();
int validarCliente(lista<cliente> clientes);
int validarPaseador(lista <paseador> paseadores);
int menuCV();
int menuAdministrador();
void imprimirClientes(lista<cliente> Clientes);
bool comprobarliente (lista<cliente> Clientes, string nuemro);
cliente registrarCliente(cliente Cl);
cliente buscarPorId (lista<cliente> Clientes);
paseador comprobarP(lista <paseador> paseadores, string identificador);
paseador registrarPaseador(paseador Pa);
int main(int argc, const char   * argv[]) {
    lista <cliente> clientes;
    lista <administrador> administradores;
    lista <paseador> Paseadores;
    lista <perro> perros;
    lista <paseo> paseos;
    ifstream lect("clientes.txt");
    ofstream myfile;
    int opc1=5;
    cliente C;
    paseador P;
    
    
    
    
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
	            string mensaje,line;
	            //Lee lo que hay dentro del archivo
	            while(getline(lect, line)){
						cout<<"Leyendo"<<endl;	
					    mensaje += line + "\n";
			}
				cout<<mensaje<<".Mensaje";
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
	        	while (opcC<0){
	        		//C = buscarPorId(clientes);
	        		opcC= menuCV();
	        		
				}
	        	
			}
	
	            
	    }
	    else if (opc1==2)
	        tipo = "Paseador";
	        int opcP=-1;
	        while (opcP<0){
	        	opcP = validarPaseador();
			}
			if (opcP==1){
				P = registarPaseador(P);
			}
	    else
	        tipo = "Administrador";
	}
    
    
    return 0;
}

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

paseador comprobarP(lista <paseador> paseadores, string identificador){
	
}

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
    while (80>Cin>0){
    	
	}
    
    
    
    
    cout<<"Muy bien has quedado registrado de manera corrcta"<<endl;
	return cl;
}

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

bool comprobarCliente (lista<cliente> Clientes, string nuemro){
	vector<string> ids; 
    lista<cliente> aux = Clientes;
    string mensaje,line;
        ifstream lect("clientes.txt");
        
	    while(getline(lect, line)){
			    mensaje += line + "\n";
	}
    size_t  found = mensaje.find("-");
	ids.push_back(mensaje.substr(0,found));
	cout<<ids[0]<<endl;
    bool reto=true;
    while (!aux.lista_vacia() && reto){
        if (ids[0]==nuemro){
        	cout<<"Ya esta"<<endl;
            reto=false;
        }
        else
            aux.borrar_nodo(1);
    }
    return reto;
};



