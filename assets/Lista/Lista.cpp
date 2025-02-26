#include "Lista.h"
#include <iostream>

using namespace std;

Lista::Lista() {
    head = nullptr;
}

Lista::~Lista() {
    No* atual = head;
    while (atual) {
        No* temp = atual;
        atual = atual->getProx();
        delete temp;
    }
}
    
void Lista::inserir(int destino) {
    No* novoNo = new No(destino, head);
    head = novoNo;
}

void Lista::imprimir() {
    No* atual = head;
    while (atual) {
        cout << atual->getDestino() << " -> ";
        atual = atual->getProx();
    }
    cout << "NULL" << endl;
}
