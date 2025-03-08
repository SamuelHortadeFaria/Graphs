#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//
//-------| MAPEANDO OS ÍNDICES PARA CADA CARACTERE |----------
//
char mapear(int i) {
    return 'A' + i;
}

//
//-------| CRIANDO AS ARESTAS |---------
//
void novaAresta(vector<vector<int>>& lista, int i, int j) {
    lista[i].push_back(j);
    lista[j].push_back(i);
}

//
//--------| IMPRIMINDO O GRAFO |--------
//
void imprimir(const vector<vector<int>>& lista) {
    for (size_t i = 0; i < lista.size(); i++) {
        cout << mapear(i) << ": ";
        for (int vizinho : lista[i]) {
            cout << mapear(vizinho) << " ";
        }
        cout << endl;
    }
}

//
//--------| BUSCANDO CICLOS COM DFS |----------
//
void cicloDFS(int atual, int origem, const vector<vector<int>>& lista, vector<bool>& visita, set<vector<int>>& ciclos, vector<int>& caminho) {
    visita[atual] = true;
    caminho.push_back(atual);

    for (int vizinho : lista[atual]) {
        if (vizinho == origem && caminho.size() > 2) {
            vector<int> cicloEncontrado = caminho;
            sort(cicloEncontrado.begin(), cicloEncontrado.end());
            ciclos.insert(cicloEncontrado);
        } 
        else if (!visita[vizinho]) {
            cicloDFS(vizinho, origem, lista, visita, ciclos, caminho);
        }
    }

    visita[atual] = false;
    caminho.pop_back();
}

//
//--------| CAMINHANDO E CONTANDO OS CICLOS |-------------
//
int contarCiclos(const vector<vector<int>>& lista) {
    set<vector<int>> ciclosDFS;
    int tam = lista.size();
    vector<bool> visita(tam, false);

    // DFS para encontrar ciclos corretamente
    for (int i = 0; i < tam; i++) {
        vector<int> caminho;
        cicloDFS(i, i, lista, visita, ciclosDFS, caminho);
    }

    // Debug: listar os ciclos encontrados
    cout << "Ciclos encontrados:\n";
    for (const auto& ciclo : ciclosDFS) {
        for (int no : ciclo) {
            cout << mapear(no) << " ";
        }
        cout << endl;
    }

    return ciclosDFS.size();
}

//
//--------| MAIN |--------------
//
int main() {
    int V = 6; // Grafo de 6 vértices.

    vector<vector<int>> lista(V);

    // Adicionando as arestas conforme o grafo.
    novaAresta(lista, 0, 1); // A - B
    novaAresta(lista, 0, 4); // A - E
    novaAresta(lista, 0, 3); // A - D
    novaAresta(lista, 1, 3); // B - D
    novaAresta(lista, 1, 2); // B - C
    novaAresta(lista, 1, 4); // B - E
    novaAresta(lista, 2, 4); // C - E
    novaAresta(lista, 2, 5); // C - F
    novaAresta(lista, 3, 2); // D - C
    novaAresta(lista, 3, 5); // D - F
    novaAresta(lista, 4, 5); // E - F

    // Exibindo a lista de adjacência
    imprimir(lista);

    // Verifica se o grafo tem ciclos e conta quantos existem
    int quantCiclos = contarCiclos(lista);
    cout << "O grafo possui " << quantCiclos << " ciclos" << endl;

    return 0;
}
