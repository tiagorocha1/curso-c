#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUANT_TENTATIVAS_NIVEL_FACIL 20
#define QUANT_TENTATIVAS_NIVEL_MEDIO 15
#define QUANT_TENTATIVAS_NIVEL_DIFICIL 6
#define PONTUACAO_INICIAL 1000

void abertura(){

printf("		   \\ \\  ___   __ _  ___                                  		\n");
printf("		    \\ \\/ _ \\ / _` |/ _ \\                                		\n"); 
printf("		 /\\_/ / (_) | (_| | (_) |                                		\n");
printf(" 		 \\___/ \\___/ \\__, |\\___/                                 		\n");
printf(" 	         	     |___/                                       			\n");
printf("		     _                                                   		\n");
printf(" 		  __| | __ _                                             		\n");	
printf("		 / _` |/ _` |                                            		\n");
printf("		| (_| | (_| |                                            		\n");
printf("		 \\__,_|\\__,_|                                            		\n");
printf("                                                         				\n");
printf("		   _       _ _       _       _                           		\n");
printf("		  /_\\   __| (_)_   _(_)_ __ | |__   __ _  ___ __ _  ___  		\n");
printf("		 //_\\ / _` | \\ \\ / / | '_ \\| '_ \\ / _` |/ __/ _` |/ _ \\ 		\n");
printf("		/  _  \\ (_| | |\\ V /| | | | | | | | (_| | (_| (_| | (_) |		\n");
printf("		\\_/ \\_/\\__,_|_| \\_/ |_|_| |_|_| |_|\\__,_|\\___\\__,_|\\___/ 		\n");
printf("																		\n\n");	
}

void voceAcertou(double pontos){
printf("Fim de Jogo!\n");

printf("												\n");
printf("				OOOOOOOOOOO 					\n");
printf("	         OOOOOOOOOOOOOOOOOOO 				\n");
printf("	      OOOOOO  OOOOOOOOO  OOOOOO 			\n");
printf("	    OOOOOO      OOOOO      OOOOOO 			\n");
printf("	  OOOOOOOO  #   OOOOO  #   OOOOOOOO 		\n");	
printf("	 OOOOOOOOOO    OOOOOOO    OOOOOOOOOO 		\n");
printf("	OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO 		\n");
printf("	OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO 		\n");
printf("	OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO 		\n");
printf("	 OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO 		\n");
printf("	  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO 		\n");
printf("	    OOOOO   OOOOOOOOOOOOOOO   OOOO 			\n");	
printf("	      OOOOOO   OOOOOOOOO   OOOOOO  			\n");
printf("	         OOOOOO         OOOOOO  			\n");
printf("	             OOOOOOOOOOOO  					\n");
printf("												\n");

		printf("Você ganhou!\n");
        printf("Total de pontos: %.1f\n", pontos);

}

void vocePerdeu(){
printf("Fim de Jogo!\n");
printf("	                          oooo$$$$$$$$$$$$ooooo                  					\n");
printf("	                      oo$$$$$$$$$$$$$$$$$$$$$$$$oo             						\n");
printf("	                   oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o         o$   $$ o$  			\n");
printf("	   o $ oo        o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o       $$ $$ $$o$ 			\n");	
printf("	oo $ $ \"$      o$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$o       $$$o$$o$ 			\n");
printf("	\"$$$$$$o$     o$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$o    $$$$$$$$ 				\n");
printf("	  $$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$ 				\n");
printf("	  $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$  \"\"\"$$$ 				\n");
printf("	   \"$$$\"\"\"\"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     \"$$$ 				\n");
printf("	    $$$   o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     \"$$$o 			\n");
printf("	   o$$\"   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$o 			\n");
printf("	   $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\" \"$$$$$$ooooo$$$$o 			\n");
printf("	  o$$$oooo$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   o$$$$$$$$$$$$$$$$$ 		\n");
printf("	  $$$$$$$$\"$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$\"\"\"\"\"\"\"\" 				\n");
printf("	 \"\"\"\"       $$$$    \"$$$$$$$$$$$$$$$$$$$$$$$$$$$$\"      o$$$  						\n");
printf("	            \"$$$o     \"\"\"$$$$$$$$$$$$$$$$$$\"$$\"         $$$ 						\n");
printf("	              $$$o          \"$$\"\"$$$$$$\"\"\"\"           o$$$ 							\n");
printf("	               $$$$o                                o$$$\"  							\n");
printf("	                \"$$$$o      o$$$$$$o\"$$$$o        o$$$$  							\n");
printf("	                  \"$$$$$oo     \"\"$$$$o$$$$$o   o$$$$\"\"            					\n");
printf("	                     \"\"$$$$$oooo  \"$$$o$$$$$$$$$\"\"\" 								\n");
printf("	                        \"\"$$$$$$$oo $$$$$$$$$$ 										\n");
printf("	                                \"\"\"\"$$$$$$$$$$$  									\n");
printf("	                                    $$$$$$$$$$$$ 									\n");
printf("	                                     $$$$$$$$$$\"  									\n");
printf("	                                      \"$$$\"\"\"\" 										\n");
printf("																						\n");
printf("																						\n");
		printf("Você perdeu, tente de novo!\n");
}

int getNivelDificuldade(){
	int nivel;
	printf("Qual o nível de dificuldade? \n");
	printf("(1) Fácil (2) Médio (3) Difícil\n\n");
	printf("Escolha: ");
	scanf("%d",&nivel);

	return nivel;
}

int getNumeroDeTentativas(int nivel){
	switch(nivel){

		case 1: return QUANT_TENTATIVAS_NIVEL_FACIL; break;				
		case 2: return QUANT_TENTATIVAS_NIVEL_MEDIO; break;
		default: return QUANT_TENTATIVAS_NIVEL_DIFICIL; break;	
	}

}

double iniciaOJogo(int numeroDeTentativas, int numeroSecreto){

	int chute=-1;
	int pontos = PONTUACAO_INICIAL;
	int tentativas =1;
	int acertou =0;

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

	if(!acertou){
		pontos=0;
	}else{
		printf("Você acertou em %d tentativas!\n", tentativas);
	}



	return pontos;
}

int getNumeroSecreto(){

	int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand();
    
    return numeroGrande % 100;
}

int main() {
	
    
    int numeroSecreto = getNumeroSecreto();

	int nivel = getNivelDificuldade();

	int numeroDeTentativas = getNumeroDeTentativas(nivel);

	abertura();	
	
	double pontos = iniciaOJogo(numeroDeTentativas,numeroSecreto);

	if(pontos){

		voceAcertou(pontos);
	}else{

		vocePerdeu();
	}
}