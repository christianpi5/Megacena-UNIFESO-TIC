#include "megasena.h"
#include "megasena.c"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    int quantidade_de_dezenas_por_aposta; //dezenas escolhidas pelo usuario
    int quantidade_de_apostas_manuais;  //apostas escolhidas pelo usuario
    int teimosinhas, quantidade_de_surpresinhas;
    
    int ** dezenas_escolhidas; //Matriz pra saber as dezenas escolhidas
    int ** surpresinhas_sorteadas; //Matriz para salvar as surpresinhas do usuário
	int *dezenas_sorteadas; // Vetor pra saber qual vai ser a combinação vencedora
	
	//Variável para controle de qual opção do menu o usuário vai escolher sendo 4 = saída
	menu();


	solicitacoes(&quantidade_de_dezenas_por_aposta, "Digite a quantidade de dezenas que voce ira jogar nas apostas", 6, 15);
	solicitacoes(&quantidade_de_apostas_manuais, "Digite a quantidade de apostas manuais que voce ira jogar", 0, 3);
	
	dezenas_escolhidas = (int**)malloc(quantidade_de_apostas_manuais * sizeof(int*));
	for(int c = 0; c < quantidade_de_apostas_manuais; c++){
		dezenas_escolhidas[c] = (int*)malloc(quantidade_de_dezenas_por_aposta * sizeof(int));
	}
	pede_valores_das_dezenas(&quantidade_de_dezenas_por_aposta, &quantidade_de_apostas_manuais,dezenas_escolhidas);
	
	srand(time(NULL)); // Apenas aqui, uma vez
	
	//Agora a solicitação pela quantidade de surpresinhas é feita pela função de solicitação
	solicitacoes(&quantidade_de_surpresinhas, "Digite a quantidade de surpresinhas que voce quer", 0, 7);
	
	surpresinhas_sorteadas = (int**)malloc(quantidade_de_surpresinhas * sizeof(int*));
	for(int c = 0; c < quantidade_de_surpresinhas; c++){
		surpresinhas_sorteadas[c] = (int*)malloc(quantidade_de_dezenas_por_aposta * sizeof(int));
	}
	gerar_matriz_pai_de_surpresinhas(quantidade_de_surpresinhas,quantidade_de_dezenas_por_aposta,surpresinhas_sorteadas);
//				Essa parte abaixo eu coloquei só pra mostrar que agora a main tem acesso as dezenas escolhidas pelo usuário
//				Esse mesmo código funciona se refeito para surpresinhas   			
//				for(int i = 0; i < quantidade_de_apostas_manuais ; i++){
//					for(int j = 0; j < quantidade_de_dezenas_por_aposta; j++){
//						printf("\n\nTamanho da array: %d\n",sizeof(dezenas_escolhidas));
//						printf("\n\nDezena [%d] da aposta [%d]: %d\n\n",i,j,dezenas_escolhidas[i][j]);
//					}
//				}
//				Repetindo o código acima pra teste de surpresinha
//    			for(int i = 0; i < quantidade_de_surpresinhas;i++){
//    				for(int j = 0; j < quantidade_de_dezenas_por_aposta; j++){
//    					printf("\n\nDezena [%d] da surpresinha [%d]: %d\n\n",j,i,surpresinhas_sorteadas[i][j]);	
//					}
//    				
//				}
    return 0;
}
