#include <stdio.h>
#include <stdlib.h>

int main() {
	
	//Imprimi o cabeçalho do jogo
    printf("************************************\n");
    printf("* Bem vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    int numeroSecreto = 42;

    int chute=-1;

    int tentativas =1;

   	double pontos = 1000;
	
	while(1){
	
		printf("Tentativa %d\n",tentativas );
		printf("Qual o seu chute? ");
	    scanf("%d",&chute);

	    if(chute < 0){

	    	printf("Você não pode chutar números negativos!\n");
	    	continue;
	    }

	  	int acertou = (chute==numeroSecreto);
	  	int maior = (chute > numeroSecreto);

	    printf("Seu chute foi %d \n",chute);

		    if(acertou){
		    	
		    	printf("Parabéns! Você acertou!\n");
		    	printf("Jogue de novo, Você é um bom joagador!!\n");

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
    printf("Você acertou em %d tentativas\n", tentativas);
    printf("Total de pontos %.2f\n",pontos );
}