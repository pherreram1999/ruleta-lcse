#ifndef RULETA_HEADER_H
#define RULETA_HEADER_H
#endif //RULETA_HEADER_H
#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct regalo {
    string tipo;
    string descripcion;
} Regalo;

typedef struct nodo {
    int id;
    Regalo regalo;
    struct nodo * sig;
} Nodo;


Nodo * crearPremio(int,string,string);

bool insertarPremio(Nodo **,Nodo *);

void mostrarPremios(Nodo *);

int cantidad(Nodo *);

int hacerTurno();

Nodo * buscarPremio(Nodo*,int);

void imprimirPremio(Nodo *);

void editarPremdio(Nodo *,string, string);