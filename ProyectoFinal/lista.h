
//Directrices del pre-procesador

#ifndef LISTA_H
#define LISTA_H
//Contenido de la libreria
#include <iostream>
using namespace std;

template <class T> // o template <typename T>

struct nodo{
	T dato;
	nodo <T> *sig;
};


template <class T>

class lista{
	nodo <T> *cab;
	int tam;
		
	public: lista(){
		cab = NULL;
		tam = 0;	
	}
	bool lista_vacia();
	void insertar_nodo(int pos, T d);
	void insertar_final(T d);
	void insertar_inicio(T d);
	void borrar_nodo(int pos);
	T buscar(int pos);
	T cambiar(int pos, T d);
	int get_tam();
	void imprimir();
};


template <class T>

int lista<T>::get_tam(){
	int cont = 0;
	
	nodo <T> *aux;
	aux = cab;
	
	while(aux != NULL){
		aux = aux -> sig;
		cont++;
	}
	
	return cont;
}


template <class T>

T lista<T>::cambiar(int pos, T d){
	int cont = 1;
	
	nodo <T> *aux;	
	aux = cab;
	
	while(cont < pos){
		aux = aux -> sig;
		cont++;
	}
	
	aux -> dato = d;
}


template <class T>

void lista<T>::insertar_nodo(int pos, T d){
	int tam = get_tam();
	int cont;
	
	if(pos > tam){
		insertar_final(d);
	}else if(pos == 1){
		insertar_inicio(d);
		
	}else{
		nodo <T> *nuevo, *aux;
		nuevo = new nodo <T>;
		nuevo -> dato = d;
		
		aux = cab;
		cont = 1;
		
		while(cont < pos - 1 && aux != NULL){
			aux = aux -> sig;
			cont++;
		}
		
		nuevo -> sig = aux -> sig;
		aux -> sig = nuevo;
		tam++;
	}
}


template <class T>

void lista<T>::insertar_final(T d){
	int tam = get_tam();
	int cont = 0;
	nodo <T> *nuevo, *aux;
	nuevo = new nodo <T>;
	nuevo -> dato = d;
	nuevo -> sig = NULL;
	aux = cab;
	while(cont < tam && aux -> sig != NULL){
		aux = aux -> sig;
		cont++;
	}
	if(tam == 0){
		cab = nuevo;
	}else{
		aux -> sig = nuevo;
	}
	
	tam++;
}


template <class T>

void lista<T>::insertar_inicio(T d){
	int tam = get_tam();
	nodo <T> *nuevo;
	nuevo = new nodo <T>;
	nuevo -> dato = d;
	nuevo -> sig = cab;
	cab = nuevo;
	tam++;
}


template <class T>

void lista<T>::imprimir(){
	nodo <T> *aux;
	aux = cab;
    while (aux != NULL){
        cout << aux -> dato << " ";
        aux = aux -> sig;
    }
    cout << endl;
}

template<typename T>
void lista<T>::borrar_nodo(int pos)
{
    int tam = get_tam();
    nodo<T> *aux = cab;
    nodo<T> *aux1 = aux->sig;
    if (pos < 1 || pos > tam) {
        cout << "La posicion no se encuentra en la lista. " << endl;
    } else if (pos == 1) {
        cab = aux->sig;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                nodo<T> *aux_nodo = aux1;
                aux->sig = aux1->sig;
                delete aux_nodo;
                tam--;
            }
            aux = aux->sig;
            aux1 = aux1->sig;
        }
    }
}

template <class T>
T lista <T>::buscar(int pos){
	int i = 1;
	nodo<T> *aux;
	aux = cab;
	while (aux != NULL && i < pos){
		aux = aux -> sig;
		i++;
	}
	if (i == pos){ 
		return aux -> dato;
	}

}

template <class T>
bool lista <T>::lista_vacia(){
	int tam = get_tam();
	if(tam == 0){
		cout<<"Lista vacia."<<endl;
		return true;
	} else {
		cout<<"Lista no se encuentra vacia."<<endl;
		return false;
	}
}



#endif

