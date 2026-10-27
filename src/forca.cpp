#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include "forca.hpp"
#include "gerenciar_banco_palavras.hpp"

using namespace std;

extern string palavra_secreta;
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

void fim_de_jogo() {
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