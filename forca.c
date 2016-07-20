#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"


//variaveis globais
char palavrasecreta[TAMANHO_PALAVRA];
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

    int erros = chutesErrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '),(erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

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


int chutesErrados(){
    
    int erros=0;

    for (int i = 0; i < chutesDados; i++){
        
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++){
             
            if(chutes[i] == palavrasecreta[j]){
                
                 existe = 1;
                break;
            }
         }

        if(!existe) erros++;
    }

    return erros;
}
int enforcou(){

    return chutesErrados() >= 5;
}

int acertou(){

    for (int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }

    return 1;
}

int adicionaPalavra(){

    char quer;

    printf("Você deseja adicionar uma nova palavra no Jogo? (S\\N\n");
    scanf(" %c",&quer);

    if(quer == 'S'){

        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a palavra? ");
        scanf("%s", novaPalavra);

        FILE* f;

        f= fopen("palavras.txt","r+");

        if(f == 0 ){
            printf("Desculpe, banco de dados não disponível\n");
            exit(1);
        }

        int qtd;
        fscanf(f,"%d",&qtd);
        qtd++;

        fseek(f,0,SEEK_SET);
        fprintf(f, "%d",qtd );

        fseek(f,0,SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

int main() {

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

        chutesDados++;

    } while (!acertou() && !enforcou());

   // adicionaPalavra();

    if(acertou()) {
    printf("\nParabéns, você ganhou!\n\n");

    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");

} else {
    printf("\nPuxa, você foi enforcado!\n");
    printf("A palavra era **%s**\n\n", palavrasecreta);

    printf("    _______________         \n");
    printf("   /               \\       \n"); 
    printf("  /                 \\      \n");
    printf("//                   \\/\\  \n");
    printf("\\|   XXXX     XXXX   | /   \n");
    printf(" |   XXXX     XXXX   |/     \n");
    printf(" |   XXX       XXX   |      \n");
    printf(" |                   |      \n");
    printf(" \\__      XXX      __/     \n");
    printf("   |\\     XXX     /|       \n");
    printf("   | |           | |        \n");
    printf("   | I I I I I I I |        \n");
    printf("   |  I I I I I I  |        \n");
    printf("   \\_             _/       \n");
    printf("     \\_         _/         \n");
    printf("       \\_______/           \n");
}

}