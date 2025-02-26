#ifndef LISTA_H
#define LISTA_H

#include "../No/No.h"

class Lista
{
private:
    No* head; // Ponteiro para o primeiro nó da lista
public:
    Lista();
    ~Lista();

    void inserir(int destino); // Método para inserir um nó
    void imprimir(); // Método para imprimir a lista
};

#endif
