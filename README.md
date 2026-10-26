# 🎯 Jogo da Forca em C++

Jogo da forca para terminal, escrito em C++. A palavra secreta é sorteada a partir de um banco de palavras salvo em arquivo, e o jogador pode adicionar novas palavras ao banco depois de vencer.

## ✨ Funcionalidades

- Sorteio aleatório da palavra secreta a partir de um arquivo de texto
- Limite de **6 chutes errados** antes da derrota
- Exibição das letras já acertadas e dos chutes errados a cada rodada
- Entrada não diferencia maiúsculas de minúsculas (convertida com `toupper`)
- Aviso quando a letra já foi chutada anteriormente
- Ao vencer, é possível **adicionar uma nova palavra** ao banco

## 📁 Estrutura do projeto

```
.
├── forca.cpp                    # Lógica principal do jogo (main)
├── gerenciar_banco_palavras.cpp # Leitura, sorteio e gravação das palavras
└── banco_palavras.txt           # Banco de palavras (precisa existir)
```

## 🛠️ Requisitos

- Compilador C++ com suporte a C++11 ou superior (g++, clang++ ou MSVC)

## ▶️ Como compilar e executar

Compile apenas o arquivo principal, pois ele já inclui `gerenciar_banco_palavras.cpp` via `#include`:

```bash
g++ -std=c++11 forca.cpp -o forca
./forca
```

No Windows (PowerShell/CMD):

```bash
g++ -std=c++11 forca.cpp -o forca.exe
forca.exe
```

> ⚠️ Execute o programa a partir da pasta que contém o `banco_palavras.txt`, pois o arquivo é aberto com caminho relativo.

## 📝 Formato do banco de palavras

O arquivo `banco_palavras.txt` deve ter, na **primeira linha**, a quantidade de palavras, seguida de uma palavra por linha, **em maiúsculas e sem espaços**:

```
5
MELANCIA
BANANA
ABACAXI
LARANJA
MORANGO
```

Se o arquivo não existir ou não puder ser aberto, o jogo exibe "Nao foi possivel acessar o banco de palavras." e encerra.

## 🎮 Como jogar

1. Inicie o programa; uma palavra é sorteada e exibida como `_ _ _ _`.
2. Digite uma letra por vez e pressione Enter.
3. Acertou: a letra aparece nas posições corretas. Errou: a letra entra na lista de chutes errados.
4. Você **vence** ao descobrir todas as letras e **perde** ao atingir 6 erros.
5. Se vencer, escolha `S` para cadastrar uma nova palavra no banco.

### Exemplo de execução

```
*************************************
**** Bem-vindos ao jogo da forca ****
*************************************

Chutes errados:
_ _ _ _ _ _
Seu chute: a
Voce acertou! Seu chute esta na palavra.

Chutes errados:
_ A _ A _ A
Seu chute: z
Voce errou! Seu chute nao esta na palavra
```

## 🧩 Como funciona

| Função | Arquivo | Descrição |
|---|---|---|
| `le_arquivo()` | gerenciar_banco_palavras.cpp | Lê o banco e devolve um `vector<string>` |
| `sorteia_palavra_secreta()` | gerenciar_banco_palavras.cpp | Escolhe a palavra com `rand()` |
| `salva_arquivo()` | gerenciar_banco_palavras.cpp | Regrava o banco com a lista atualizada |
| `adiciona_palavra()` | gerenciar_banco_palavras.cpp | Pede uma palavra, converte para maiúsculas e salva |
| `letra_existe()` | forca.cpp | Verifica se o chute está na palavra |
| `nao_acertou()` | forca.cpp | `true` enquanto faltar alguma letra a descobrir |
| `nao_enforcou()` | forca.cpp | `true` enquanto houver menos de 6 erros |
| `chuta()` | forca.cpp | Lê e processa o chute do jogador |

O estado do jogo fica em duas estruturas globais: um `map<char, bool>` com as letras já chutadas e um `vector<char>` com os chutes errados.
