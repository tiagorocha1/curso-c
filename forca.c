#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"


//variaveis globais
char palavrasecreta[20];
char chutes[26];
int chutesDados = 0;

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
}

int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesDados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() {

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void escolhepalavra() {
    
    FILE* f;

    f = fopen("palavras.txt","r");

    if(f == 0 ){
        printf("Desculpe, banco de dados não disponível\n");
        exit(1);
    }

    int qtdDePalavras;
    fscanf(f,"%d",&qtdDePalavras);

    srand(time(0));
    int randomico = rand() % qtdDePalavras;

    for (int i = 0; i <=randomico; i++){
        
        fscanf(f,"%s",palavrasecreta);
    }

    fclose(f);
}

int enforcou(){

    int erros;

    for (int i = 0; i < chutesDados; i++){
        
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++){
            
            if(jachutou(palavrasecreta[j])){
               
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }

    return erros >= 5;
}

int acertou(){

    for (int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }

    return 1;
}

int main() {

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

        chutesDados++;

    } while (!acertou() && !enforcou());

}