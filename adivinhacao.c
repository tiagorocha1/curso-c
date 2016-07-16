#include <stdio.h>

#define NUMERO_DE_TENTATIVAS 5
int main() {

 	//Imprimi o cabeçalho do jogo
    printf("************************************\n");
    printf("* Bem vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    int numeroSecreto = 42;

    int chute;
	
	

	for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++){
	
		printf("Tentativa %d de %d\n",i,NUMERO_DE_TENTATIVAS );
		printf("Qual o seu chute? ");
	    scanf("%d",&chute);

	    if(chute < 0){

	    	printf("Você não pode chutar números negativos!\n");
	    	--i;
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
	    	
	    	
	}
    
    printf("Fim de Jogo!\n");
}