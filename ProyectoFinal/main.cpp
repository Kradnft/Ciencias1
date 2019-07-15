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
int menuCliente(lista<cliente> clientes);
int menuPaseador();
int menuAdministrador();
void imprimirClientes(lista<cliente> Clientes);
bool comprobar (lista<cliente> Clientes, string nuemro);


int main(int argc, const char   * argv[]) {
    lista <cliente> clientes;
    ifstream lect("example.txt");
    ofstream myfile;
    int opc1=5;
    cliente C;
    string tipo;
    while (opc1!=4){
	opc1=menu1();
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
	            int n=-1;
	            while (n<0)
	            	cin>>n;
	            C.Nperros=n;
	            //ingresarPerros(n,C);
	            cout<<"Sexo"<<endl;
	            cin>>nombre;
	            C.sexo=nombre;
	            cout<<"Muy bien has quedado registrado de manera corrcta"<<endl;
	            cout<<"Te esperamos pronto "+C.nombre<<endl;
	            clientes.insertar_final(C);
	            Interfaz::imprimirClientes(clientes); 
	            string mensaje,line;
	            while(getline(lect, line)){
						cout<<"Leyendo"<<endl;	
					    mensaje += line + "\n";
			}
				cout<<mensaje<<".Mensaje";
				mensaje += C.nombre + "-"+C.apellido+"-"+C.identificacion+"-"+C.localidad;
				mensaje += "-"+C.sexo;
				myfile.open ("example.txt");
				  myfile << mensaje <<"\n";
				  myfile.close();                       
	        }
	        else {
	        	
			}
	
	            
	    }
	    else if (opc1==2)
	        tipo = "Paseador";
	    else
	        tipo = "Administrador";
	}
    
    
    return 0;
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

int menuCliente(lista <cliente> clientes){
    string id;
    cliente C;
    cout<<"Por favor ingresa tu numero de documento"<<endl;
    cin >> id;
    
    bool nuevo = false;
    nuevo = comprobar(clientes, id);
    
    //Comprobamos si es un usuario que ya esta en la lista o no
    if (nuevo)
        return 1;
    else {
        cout <<"Bienvenido de nuevo"<<endl;
        return 2;
    }
    
}

vector<string> tokenizar(string text, string token, string path) {
	vector<string> list;
	vector<vector<string>> subList;
    string mensaje, line;
    ifstream lect(path);
	while(getline(lect, line))
		list.push_back(line);
	while()
    size_t found = mensaje.find("-");
	list.push_back(mensaje.substr(0,found));
	return list;
}

bool comprobar (lista<cliente> Clientes, string nuemro){
	vector<string> ids; 
    lista<cliente> aux = Clientes;
    string mensaje,line;
        ifstream lect("example.txt");

	    while(getline(lect, line)){
			    mensaje += line + "\n";
	}
    size_t  found = mensaje.find("-");
	ids.push_back(mensaje.substr(0,found));
	cout<<ids[0];
    bool reto=true;
    while (!aux.lista_vacia() && reto){
    	
        if (ids[0]==nuemro){
            reto=false;
        }
        else
            aux.borrar_nodo(1);
    }
    return reto;
};



