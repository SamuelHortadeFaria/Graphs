#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//-------| MAPEANDO OS ÍNDICES PARA CADA CARACTERE |----------
char mapear(int i) {
    return 'A' + i;
}

//-------| CRIANDO AS ARESTAS |---------
void novaAresta(vector<vector<int>>& lista, int i, int j) {
    lista[i].push_back(j);
    lista[j].push_back(i);
}

//--------| IMPRIMINDO O GRAFO |--------
void imprimir(const vector<vector<int>>& lista) {
    for (size_t i = 0; i < lista.size(); i++) {
        cout << mapear(i) << ": ";
        for (int vizinho : lista[i]) {
            cout << mapear(vizinho) << " ";
        }
        cout << endl;
    }
}

//--------| VERIFICA SE A PERMUTAÇÃO FORMA UM CICLO |--------
bool formaCiclo(const vector<int>& perm, const vector<vector<int>>& lista) {
    int n = perm.size();
    
    // O ciclo precisa começar e terminar no mesmo nó
    if (perm.front() != perm.back()) return false;

    // Verifica se todos os passos na permutação são conexões válidas no grafo
    for (int i = 0; i < n - 1; i++) {
        int u = perm[i];
        int v = perm[i + 1];

        // Se não há uma aresta entre os nós, não é um ciclo válido
        if (find(lista[u].begin(), lista[u].end(), v) == lista[u].end()) {
            return false;
        }
    }

    return true;
}

//--------| GERA SUBCONJUNTOS E ACHA CICLOS |--------
void gerarSubconjuntos(vector<int>& nos, int inicio, int tamanho, vector<int>& atual, set<vector<int>>& ciclos, const vector<vector<int>>& lista) {
    if (atual.size() == tamanho) {
        vector<int> perm = atual;
        perm.push_back(perm.front()); // Fecha o ciclo

        do {
            if (formaCiclo(perm, lista)) {
                vector<int> cicloOrdenado = perm;
                sort(cicloOrdenado.begin(), cicloOrdenado.end());
                ciclos.insert(cicloOrdenado);
            }
        } while (next_permutation(perm.begin() + 1, perm.end() - 1)); // Permuta nós internos

        return;
    }

    for (int i = inicio; i < nos.size(); i++) {
        atual.push_back(nos[i]);
        gerarSubconjuntos(nos, i + 1, tamanho, atual, ciclos, lista);
        atual.pop_back();
    }
}

//--------| CONTANDO CICLOS POR PERMUTAÇÃO |--------
int contarCiclos(const vector<vector<int>>& lista) {
    int tam = lista.size();
    vector<int> nos(tam);
    
    // Preenchendo vetor com índices [0, 1, 2, ..., tam-1]
    for (int i = 0; i < tam; i++) {
        nos[i] = i;
    }

    set<vector<int>> ciclosUnicos; // Para evitar ciclos duplicados

    // Gerar subconjuntos de tamanhos de 3 até o número total de nós
    for (int tamanho = 3; tamanho <= tam; tamanho++) {
        vector<int> atual;
        gerarSubconjuntos(nos, 0, tamanho, atual, ciclosUnicos, lista);
    }

    return ciclosUnicos.size();
}

//--------| MAIN |--------------
int main() {
    int V = 6; // Grafo de 6 vértices

    vector<vector<int>> lista(V);

    // Conectando as arestas
    novaAresta(lista, 0, 1);
    novaAresta(lista, 0, 4);
    novaAresta(lista, 0, 3);
    novaAresta(lista, 1, 3);
    novaAresta(lista, 1, 2);
    novaAresta(lista, 1, 4);
    novaAresta(lista, 2, 4);
    novaAresta(lista, 2, 5);
    novaAresta(lista, 3, 2);
    novaAresta(lista, 3, 5);
    novaAresta(lista, 4, 5);

    imprimir(lista);

    int quantCiclos = contarCiclos(lista);
    cout << "O grafo possui " << quantCiclos << " ciclos" << endl;

    return 0;
}
