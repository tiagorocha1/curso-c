#include <stdio.h>

#define NUMERO_DE_TENTATIVAS 5
int main() {

	//Imprimi o cabeçalho do jogo
    printf("************************************\n");
    printf("* Bem vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    int numeroSecreto = 42;

    int chute;
	
	int acertou = (chute==numeroSecreto);


	for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++){
	
		printf("Tentativa %d de %d\n",i,NUMERO_DE_TENTATIVAS );
		printf("Qual o seu chute? ");
	    scanf("%d",&chute);

	    acertou = (chute==numeroSecreto);

	    printf("Seu chute foi %d \n",chute);

		    if(acertou){
		    	
		    	printf("Parabéns! Você acertou!\n");
		    	printf("Jogue de novo, Você é um bom joagador!!\n");

		    	break;
		    }else{

		    	int maior = (chute > numeroSecreto);

		    	if(maior){
		    	
		    		printf("Seu chute foi maior que o número secreto\n");

		    	}else {

		    		printf("Seu chute foi menor que o número secreto\n");
		    	}
	    	
	    	}
	}


	
    
    printf("Fim de Jogo!\n");
}