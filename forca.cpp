#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "gerenciar_banco_palavras.cpp"
using namespace std;

map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute) {
    for (char letra : palavra_secreta) {
        if (chute == letra) return true;
    }
    return false;
}

bool nao_acertou() {
    for (char letra : palavra_secreta) {
        if (!chutou[letra]) {
            return true;
        }
    }
    return false;
}

bool nao_enforcou() {
    return chutes_errados.size() < 6;
}

void imprime_cabecalho() {
    cout << "*************************************" << endl;
    cout << "**** Bem-vindos ao jogo da forca ****" << endl;
    cout << "*************************************" << endl;
    cout << endl;
}

void imprime_erros() {
    cout << "Chutes errados: ";
    for (char letra : chutes_errados) {
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra() {
    for (char letra : palavra_secreta) {
        if (chutou[letra]) {
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }
}

void chuta() {
    cout << endl << "Seu chute: ";
    char chute;
    cin >> chute;
    chute = toupper(chute);

    if (chutou[chute]) {
        cout << "Voce ja chutou esta letra." << endl;
    } else {
        chutou[chute] = true;
        if (letra_existe(chute)) {
            cout << "Voce acertou! Seu chute esta na palavra." << endl;
        } else {
            cout << "Voce errou! Seu chute nao esta na palavra" << endl;
            chutes_errados.push_back(chute);
        } 
        cout << endl;
    }
}

int main() {
    imprime_cabecalho();

    sorteia_palavra_secreta();
    
    while (nao_acertou() && nao_enforcou()) {
        imprime_erros();
        imprime_palavra();
        chuta();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era " << palavra_secreta << endl;
    if (nao_acertou()) {
        cout << "Voce perdeu! Tente novamente." << endl;
    } else {
        cout << "Parabens! Voce acertou a palavra secreta!" << endl;

        cout << "Voce deseja adicionar uma nova plavavra ao banco? (S/N)" << endl;
        char resposta;
        cin >> resposta;
        resposta = toupper(resposta);
        if (resposta == 'S') {
            adiciona_palavra();
        }
    }

}