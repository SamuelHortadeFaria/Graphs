#ifndef GRAFO_H
#define GRAFO_H

#include "../Lista/Lista.h"

class Grafo {
private:
    int numVertices;
    Lista* lista_de_adjacencia;
public:
    Grafo(int numVertices);
    ~Grafo();

    void includeEdge(int origem, int destino);

    void printGraph();
};

#endif