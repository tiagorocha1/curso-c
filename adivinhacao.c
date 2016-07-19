#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUANT_TENTATIVAS_NIVEL_FACIL 20
#define QUANT_TENTATIVAS_NIVEL_MEDIO 15
#define QUANT_TENTATIVAS_NIVEL_DIFICIL 6

int main() {
	
	//Imprimi o cabeçalho do jogo
    printf("************************************\n");
    printf("* Bem vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand();
    int numeroSecreto = numeroGrande % 100;
    int chute=-1;
    int tentativas =1;
   	double pontos = 1000;
	
	int acertou = 0;

	int nivel;

	int numeroDeTentativas;

	printf("Qual o nível de dificuldade? \n");
	printf("(1) Fácil (2) Médio (3) Difícil\n\n");
	printf("Escolha: ");
	scanf("%d",&nivel);

	switch(nivel){

		case 1: numeroDeTentativas =QUANT_TENTATIVAS_NIVEL_FACIL; break;				
		case 2: numeroDeTentativas = QUANT_TENTATIVAS_NIVEL_MEDIO; break;
		default: numeroDeTentativas = QUANT_TENTATIVAS_NIVEL_DIFICIL; break;	
	}
	
	for (int i=1; i<=numeroDeTentativas;i++){
	
		printf("Tentativa %d\n",tentativas );
		printf("Qual o seu chute? ");
	    scanf("%d",&chute);

	    if(chute < 0){

	    	printf("Você não pode chutar números negativos!\n");
	    	continue;
	    }

	  	acertou = (chute==numeroSecreto);
	  	int maior = (chute > numeroSecreto);

	    printf("Seu chute foi %d \n",chute);

		    if(acertou){		    			    	

		    	break;

		    }else if(maior){
		    	
		    		printf("Seu chute foi maior que o número secreto\n");

		    }else{
		    		printf("Seu chute foi menor que o número secreto\n");
		   	}
	    	
	    	tentativas++;

	    	double pontosPerdidos = abs(chute - numeroSecreto) / (double)2 ;

	    	pontos = pontos - pontosPerdidos;
	}

	printf("Fim de Jogo!\n");
	if(acertou){
		
		printf("Você ganhou!\n");
		printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
        
	}else{

		printf("Você perdeu, tente de novo!\n");
	}
}