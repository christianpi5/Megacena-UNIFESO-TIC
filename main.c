#include "megasena.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    int quantidade_de_dezenas_por_aposta; //dezenas escolhidas pelo usuario
    int quantidade_de_apostas_manuais;  //apostas escolhidas pelo usuario
    int teimosinhas, surpresinhas;
    
    int ** dezenas_escolhidas; //Matriz pra saber as dezenas escolhidas
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
    			gerar_matriz_pai_de_surpresinhas(quantidade_de_dezenas_por_aposta);
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