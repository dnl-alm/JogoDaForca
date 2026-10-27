#pragma once
#include <iostream>
#include <string>

bool letra_existe(char chute);

bool nao_acertou();

bool nao_enforcou();

inline void imprime_cabecalho() {
    std::cout << "*************************************" << std::endl;
    std::cout << "**** Bem-vindos ao jogo da forca ****" << std::endl;
    std::cout << "*************************************" << std::endl;
    std::cout << std::endl;
}

void imprime_erros();

void imprime_palavra();

void chuta();

void fim_de_jogo();