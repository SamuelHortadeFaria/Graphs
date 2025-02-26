#include "No.h"

No::No(int destino, No* prox){
    this->destino = destino;
    this->prox = prox;
}

No::No(int destino){
    this->destino = destino;
    this->prox = nullptr;
}

No::~No(){}

int No::getDestino() const {
    return this->destino;
}

No* No::getProx() const {
    return this->prox;
}

// Método para definir o próximo nó
void No::setProx(No* prox) {
    this->prox = prox;
}
