#ifndef NO_H
#define NO_H
/*Estrutura para representação de um Nó*/
class No
{
private:
    int destino; 
    No * prox;
public:
    No(int destino, No* prox);

    No(int destino);

    ~No();

    int getDestino() const;

    No* getProx() const;

    // Método para definir o próximo nó
    void setProx(No* prox);

};
#endif
