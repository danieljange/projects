#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void menuInicial();

void limpaTela(){
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[3][3]){
    int linha, coluna;
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }
}

void exibeTabuleiro(char tabuleiro[3][3]){
    int linha, coluna;

    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            cout << tabuleiro[linha][coluna];
        }
    cout << "\n";
    }
}
//1 - X venceu; 2 - O venceu e 0 - Nada aconteceu
int confereTabuleiro(char tabuleiro[3][3]){

    int linha, coluna;

    for (linha = 0; linha < 3; linha++){
        if (tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
            return 1;
        }else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
            return 2;
        }
    }
    for (coluna = 0; coluna < 3; coluna++){
        if (tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
            return 1;
        }else if(tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
            return 2;
        }
    }

    if (tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
        if (tabuleiro[0][0] == 'X'){
            return 1;
        }else{
            return 2;
        }
    }

    if (tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
        if (tabuleiro[0][2] == 'X'){
            return 1;
        }else{
            return 2;
        }
    }
    return 0;
}

void exibeInstrucoes(){

    cout << "\nMapa de Posicoes";
    cout << "\n 7 | 8 | 9";
    cout << "\n 4 | 5 | 6";
    cout << "\n 1 | 2 | 3";
}

void jogo(string nomeUm, string nomeDois, int pontuacaoUm, int pontuacaoDois){

    //Variáveis gerais
    string nomeAtual;
    char tabuleiro[3][3];
    int linha, coluna;
    int linhaJogada, colunaJogada, posicaoJogada;
    int estadoJogo = 1;
    int turnoJogador = 1;
    int rodada = 0;
    int opcao;
    bool posicaoCerta;

    iniciaTabuleiro(tabuleiro);

    while (rodada < 9 && estadoJogo == 1){
        limpaTela();
        exibeTabuleiro(tabuleiro);
        exibeInstrucoes();
        cout << "\nRodada:" << rodada << "\n";
        cout << "Pontuacao:" << nomeUm << " " << pontuacaoUm << " x " << nomeDois << " " << pontuacaoDois << "\n";

        if(turnoJogador == 1){
            nomeAtual = nomeUm;
        }else{
            nomeAtual = nomeDois;
        }

        posicaoCerta = false;

        int posicoes[9][2] = {{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};

        while (posicaoCerta == false){
            cout << nomeAtual << ", digite uma posicao conforme o mapa acima:";
            cin >> posicaoJogada;

            linhaJogada = posicoes[posicaoJogada-1][0];
            colunaJogada = posicoes[posicaoJogada-1][1];

            if (tabuleiro[linhaJogada][colunaJogada] == '-'){

                posicaoCerta = true;

                if (turnoJogador == 1){
                    tabuleiro[linhaJogada][colunaJogada] = 'X';
                    turnoJogador = 2;
                }else{
                    tabuleiro[linhaJogada][colunaJogada] = 'O';
                    turnoJogador = 1;
                }
            }
        }





        if(confereTabuleiro(tabuleiro) == 1){
            cout << "O jogador X venceu\n";
            pontuacaoUm++;
            estadoJogo = 0;
        }else if (confereTabuleiro(tabuleiro) == 2){
            cout << "O jogador O venceu\n";
            pontuacaoDois++;
            estadoJogo = 0;
        }

        rodada++;
    }
    exibeTabuleiro(tabuleiro);
    cout << "\nFim de jogo";
    cout << "\nO que deseja fazer?";
    cout << "\n1 - Continuar jogando";
    cout << "\n2 - Menu Inicial";
    cout << "\n3 - Sair\n";
    cin >> opcao;
    if (opcao == 1){
        jogo(nomeUm, nomeDois, pontuacaoUm, pontuacaoDois);
    }else if (opcao == 2){
        menuInicial();
    }

}

void menuInicial(){
    int opcao = 0;
    string nomeUm, nomeDois;

    while (opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem vindo ao Jogo da Velha";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER:";
        cin >> opcao;

        switch(opcao){
            case 1:
                cout << "Digite o nome do Jogador 1:";
                cin >> nomeUm;
                cout << "Digite o nome do Jogador 2:";
                cin >> nomeDois;
                jogo(nomeUm, nomeDois,0,0);
                break;
            case 2:
                cout << "Jogo desenvolvido por Daniel Henrique Inoue Jange em 2024";
                break;
            case 3:
                cout << "Até mais";
                break;
        }
    }
}

int main(){

    menuInicial();

    return 0;
}
