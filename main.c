#include "megasena.h"
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
	char escolha_usuario = '0';
	while(escolha_usuario != '4'){
		menu();
		scanf("%c",&escolha_usuario);
		switch(escolha_usuario){
			case '1':
				solicitacoes(&quantidade_de_dezenas_por_aposta, "Digite a quantidade de dezenas que voce ira jogar nas apostas", 6, 15);
    			solicitacoes(&quantidade_de_apostas_manuais, "Digite a quantidade de apostas manuais que voce ira jogar", 0, 3);
    			
   				pede_valores_das_dezenas(&quantidade_de_dezenas_por_aposta, &quantidade_de_apostas_manuais,dezenas_escolhidas);
   				
   				srand(time(NULL)); // Apenas aqui, uma vez
   				
   				//Agora a solicitação pela quantidade de surpresinhas é feita pela função de solicitação
   				solicitacoes(&quantidade_de_surpresinhas, "Digite a quantidade de surpresinhas que voce quer", 0, 7);
    			gerar_matriz_pai_de_surpresinhas(quantidade_de_surpresinhas,quantidade_de_dezenas_por_aposta,surpresinhas_sorteadas);
    			
 				//Essa parte abaixo eu coloquei só pra mostrar que agora a main tem acesso as dezenas escolhidas pelo usuário
				//Esse mesmo código funciona se refeito para surpresinhas   			
//				for(int i = 0; i < quantidade_de_apostas_manuais ; i++){
//					for(int j = 0; j < quantidade_de_dezenas_por_aposta; j++){
//						printf("\n\nTamanho da array: %d\n",sizeof(dezenas_escolhidas));
//						printf("\n\nDezena [%d] da aposta [%d]: %d\n\n",i,j,dezenas_escolhidas[i][j]);
//					}
//				}
    			
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				printf("\nObrigado por usar nossos servicos, volte sempre!");
				return 0;
				break;
			default:
				printf("Valor invalido");
				break;
				
		}
	}

    return 0;
}