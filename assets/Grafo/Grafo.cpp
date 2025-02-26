#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int numVertices){
    this->numVertices = numVertices;
    lista_de_adjacencia = new Lista[numVertices];
}

Grafo::~Grafo(){
    delete[] lista_de_adjacencia;
}

void Grafo::includeEdge(int origem, int destino){
    lista_de_adjacencia[origem].inserir(destino);
    lista_de_adjacencia[destino].inserir(origem);
}

void Grafo::printGraph(){
    for(int i = 0; i< this->numVertices; i++){
        cout << "Vértice " << i+1 << ": ";
        lista_de_adjacencia[i].imprimir();
    }
}