#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

string palavra_secreta;

vector<string> le_arquivo() {
    ifstream arquivo;
    arquivo.open("banco_palavras.txt");

    if (arquivo.is_open()) {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        vector<string> palavras_do_arquivo;

        for (int i = 0; i < quantidade_palavras; i++) {
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_do_arquivo;
    } else {
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        exit(0);
    }
}

void sorteia_palavra_secreta() {
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista) {
    ofstream arquivo;
    arquivo.open("banco_palavras.txt");

    if (arquivo.is_open()) {
        arquivo << nova_lista.size() << endl;

        for (string palavra : nova_lista) {
            arquivo << palavra << endl;
        }

        arquivo.close();
    } else {
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        exit(0);
    }
}

void adiciona_palavra() {
    cout << "Digite a nova palavra:" << endl;
    string nova_palavra;
    cin >> nova_palavra;
    for (int i = 0; i < nova_palavra.size(); i++) {
        char letra = nova_palavra[i];
        letra = toupper(letra);
        nova_palavra[i] = letra;
    }

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
    cout << "Palavra " << nova_palavra << " adicionada." << endl;
}