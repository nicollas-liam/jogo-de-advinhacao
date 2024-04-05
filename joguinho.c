#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("*****************************************\n");
    printf("* Bem vindo ao nosso jogo de advinhação *\n");
    printf("*****************************************\n");

    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativa = 1;
    double pontos = 1000;
    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) fácil (2) médio (3) difícil\n\n");
    printf("escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;
    if(nivel == 1) {
        numerodetentativas = 20;
    }
    else if (nivel == 2)
    {
        numerodetentativas = 12;
    }
    else {
        numerodetentativas = 6;
    }
    

    for (int i = 1; i <= numerodetentativas; i++) {
    
        printf("Tentativa %d\n", tentativa);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);

        if (chute < 0)
        {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }
        
        acertou = (chute == numerosecreto);
        int  maior = (chute > numerosecreto);

        if (acertou) {
            break;
        }
        else if (maior) {
            printf("Seu chute foi maior que o número secreto.\n");
        }  
        else {
            printf("Seu chute foi menor que o número secreto.\n");
        }   
        tentativa++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }   
    
    printf("Fim de jogo!\n");

    if(acertou){
        printf("Parabéns, você acertou!\n");
        printf("Você ganhou em %d tentativas!\n", tentativa);
        printf("Total de pontos: %.1f\n", pontos);
    }  
    else {
        printf("Você perdeu.\no número secreto era %d.\nJogue de novo\n", numerosecreto);
    }
}