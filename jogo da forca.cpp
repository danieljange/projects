#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalvraAleatoria(){
    string palavras[3] = {"abacaxi", "manga", "morango"};

    int indiceAleatorio = rand() % 3;

    return palavras[indiceAleatorio];
}

string retornaPalavraMascarada(string palavra, int tamanhoDaPalavra){
    int cont = 0;
    string palavraMascarada;

    while (cont < tamanhoDaPalavra){
        palavraMascarada += "_";
        cont ++;
    }
    return palavraMascarada;
}

void exibeStatus(string palavraMascarada, int tamanhoDaPalavra, int tentativasRestantes, string letrasArriscadas, string mensagem){
    cout << mensagem << "\n";
    cout << "Palavra: " << palavraMascarada;
    cout << "Tamanho da palavra:" << tamanhoDaPalavra;
    cout << "\nTentativas restantes: " << tentativasRestantes;

    int cont;
    cout << "\nLetras arriscadas: ";
    for (cont = 0; cont < letrasArriscadas.size(); cont++){
        cout << letrasArriscadas[cont] << ", ";
    }

}
int jogar(int numJogadores){
    string palavra;
    if(numJogadores == 1){
        palavra = retornaPalvraAleatoria();
    }else{
        cout << "\nDigite uma palavra: ";
        cin >> palavra;
    }


    int tamanhoDaPalavra = palavra.size();

    string palavraMascarada = retornaPalavraMascarada(palavra, tamanhoDaPalavra);

    int tentativas = 0, maximoTentativas = 7;
    int cont = 0;
    int opcao;
    char letra;
    string letrasArriscadas;
    string mensagem = "Bem vindo ao jogo";
    string palavraArriscada;
    bool jaDigitou = false, acertouLetra = false;

    while(palavra != palavraMascarada && maximoTentativas - tentativas > 0){
        limpaTela();
        exibeStatus(palavraMascarada, tamanhoDaPalavra, maximoTentativas - tentativas, letrasArriscadas, mensagem);
        cout << "\nDigite uma letra (ou digite 1 para arriscar a palavra inteira):";
        cin >> letra;

        if (letra == '1'){
            cin >> palavraArriscada;
            if (palavraArriscada == palavra){
                palavraMascarada = palavraArriscada;
            }else{
                tentativas = maximoTentativas;
            }
        }

        for (cont = 0; cont < tentativas; cont++){
            if(letrasArriscadas[cont] == letra){
                mensagem = "Letra ja digitada anteriormente";
                jaDigitou = true;
            }
        }
        if (jaDigitou == false){

            letrasArriscadas += tolower(letra);

            for (cont = 0; cont < tamanhoDaPalavra; cont++){
                if (palavra[cont] == tolower(letra)){
                    palavraMascarada[cont] = palavra[cont];
                    acertouLetra = true;
                }
            }


            if (acertouLetra == false){
                mensagem = "Voce errou uma letra";
            }else{
                mensagem = "Voce acertou uma letra!";

            }
            tentativas++;
        }

        jaDigitou = false;
        acertouLetra = false;
    }

    if (palavraMascarada == palavra){
        limpaTela();
        cout << "Parabens!" << "\nVoce ganhou!";
        cout << "Deseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao;
    }else{
        limpaTela();
        cout << "Nao foi dessa vez";
        cout << "Deseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao;
    }
}

void menuInicial(){
    int opcao = 0;
    while(opcao<1 || opcao >3){
        limpaTela();
        cout << "Bem Vindo ao Jogo da Forca";
        cout << "\n1 - Jogar";
        cout << "\n2 - Jogar em Dupla";
        cout << "\n3 - Sobre";
        cout << "\n4 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER:";
        cin >> opcao;

        switch(opcao){
        case 1:
            cout << "Jogo iniciado" << "\n";
            if(jogar(1) == 1){
                menuInicial();
            }
            break;
        case 2:
            cout << "Jogo iniciado" << "\n";
            if(jogar(2) == 1){
                menuInicial();
            }
            break;
        case 3:
            cout << "Informações do jogo";
            limpaTela();
            cout << "Jogo desenvolvido por Daniel Henrique Inoue Jange em 2024";
            cout << "\n1 - Voltar";
            cout << "\n2 - Sair";
            cin >> opcao;
            if (opcao == 1){
                menuInicial();
            }
            break;
        case 4:
            cout << "Até mais!";
            break;
        }
    }
}

int main(){

    srand( (unsigned)time(NULL));
    menuInicial();

    return 0;
}
