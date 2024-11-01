#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void menuInicial();

void limpaTela(){
    system("CLS");
}
void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]){
    int linha, coluna;
    //Popula o tabuleiro com água
    for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }
}

void exibeMapa(){
    int cont;

    for (cont = 0; cont < 10; cont++){
        if (cont == 0){
            cout << "     ";
        }
        cout << cont << " ";
    }
    cout << "\n";

    for (cont = 0; cont < 10; cont++){
        if (cont == 0){
            cout << "     ";
        }
        cout << "| ";
    }
    cout << "\n";
}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10], bool mostraGabarito){

    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };

    int linha, coluna;

    for(linha = 0; linha < 10; linha++){
        cout << linha << " - ";
        for(coluna = 0; coluna < 10; coluna++){
            switch(mascara[linha][coluna]){
                case 'A':
                    cout << blue << " " << mascara[linha][coluna] << normal;
                    break;
                case 'P':
                    cout << red << " " << mascara[linha][coluna] << normal;
                    break;
                default:
                    cout << " " <<mascara[linha][coluna];
                    break;
            }
        }
        cout << "\n";
    }



    if (mostraGabarito == true){
        for(linha = 0; linha < 10; linha++){
            for(coluna = 0; coluna < 10; coluna++){
                cout << " "<< tabuleiro[linha][coluna];
            }
            cout << "\n";
        }
    }

}

void posicionaBarcos(char tabuleiro[10][10]){

    int cont, qtd = 10, qtdPosicionada = 0;

    while(qtdPosicionada < qtd){
        int linhaBarco = rand() % 10;
        int colunaBarco = rand() % 10;
        if(tabuleiro[linhaBarco][colunaBarco] == 'A'){
            tabuleiro[linhaBarco][colunaBarco] = 'P';
            qtdPosicionada++;
        }

    }
}

void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem){
    switch(tabuleiro[linhaJogada][colunaJogada]){
        case 'P':
            *pontos = *pontos + 10;
            *mensagem = "Voce acertou um barco pequeno! (10 pontos)";
            break;
        case 'A':
            *mensagem = "Voce acertou a agua (0 pontos)";
            break;
    }
}

void jogo(string nomeJogador){
    //Variáveis gerais
    char tabuleiro[10][10], mascara[10][10];
    int linha, coluna;
    int linhaJogada, colunaJogada;
    int estadoJogo = 1;
    int pontos = 0;
    int tentativas = 0, maximoTentativas = 20;
    int opcao;
    string mensagem = "Bem vindo ao jogo";

    iniciaTabuleiro(tabuleiro, mascara);
    posicionaBarcos(tabuleiro);

    while (tentativas < maximoTentativas){
        limpaTela();

        exibeMapa();

        exibeTabuleiro(tabuleiro, mascara, false);

        cout << "\n" << mensagem;
        cout << "\nPontos:" << pontos;
        cout << "\nTentativas restantes:" << maximoTentativas - tentativas;

        //Verificação de dados
        linhaJogada = -1;
        colunaJogada = -1;

        while((linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada > 9)){
            cout << "\n" << nomeJogador << ", digite uma linha:";
            cin >> linhaJogada;
            cout << "\n" << nomeJogador << ", digite uma coluna:";
            cin >> colunaJogada;
        }



        verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);

        //Revela o que está no tabuleiro
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];

        tentativas++;
    }

    cout << "Fim de jogo, o que deseja fazer?";
    cout << "\n1 - Jogar novamente";
    cout << "\n2 - Voltar para o Menu";
    cout << "\n3 - Sair\n";
    cin >> opcao;

    switch(opcao){
        case 1:
            jogo(nomeJogador);
            break;
        case 2:
            menuInicial();
            break;
    }

}
void menuInicial(){
    int opcao = 0;
    string nomeJogador;
    while (opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem Vindo ao Jogo de Batalha Naval";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER:";
        cin >> opcao;

        switch(opcao){
            case 1:
                //Inicia o jogo
                cout << "Jogo iniciado\n";
                cout << "Qual seu nome?\n";
                cin >> nomeJogador;
                jogo(nomeJogador);
                break;
            case 2:
                cout << "Jogo desenvolvido por Daniel Henrique Inoue Jange em 2024";
                break;
            case 3:
                cout << "Ate mais";
                break;
        }
    }
}

int main(){

    srand( (unsigned)time(NULL));

    menuInicial();

    return 0;
}
