#include "./assets/Grafo/Grafo.h"

int main(){
    Grafo g(5);

    g.includeEdge(0, 1);
    g.includeEdge(0, 4);
    g.includeEdge(1, 2);
    g.includeEdge(1, 3);
    g.includeEdge(1, 4);
    g.includeEdge(2, 3);
    g.includeEdge(3, 4);

    g.printGraph();

    return 0;
}

