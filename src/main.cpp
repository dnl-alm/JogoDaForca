#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "forca.hpp"
#include "gerenciar_banco_palavras.hpp"

int main() {
    imprime_cabecalho();

    sorteia_palavra_secreta();
    
    while (nao_acertou() && nao_enforcou()) {
        imprime_erros();
        imprime_palavra();
        chuta();
    }

    fim_de_jogo();

}