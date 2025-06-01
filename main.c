#include "megasena.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    int quantidade_de_dezenas_por_aposta; //dezenas escolhidas pelo usuario
    int quantidade_de_apostas_manuais;  //apostas escolhidas pelo usuario
    int teimosinhas, surpresinhas;
    
    //int ** dezenas_escolhidas; //Matriz pra saber as dezenas escolhidas
	int *dezenas_sorteadas; // Vetor pra saber qual vai ser a combinação vencedora
    menu();
    solicitacoes(&quantidade_de_dezenas_por_aposta, "Digite a quantidade de dezenas que voce ira jogar nas apostas", 6, 15);
    solicitacoes(&quantidade_de_apostas_manuais, "Digite a quantidade de apostas manuais que voce ira jogar", 0, 3);
    pede_valores_das_dezenas(&quantidade_de_dezenas_por_aposta, &quantidade_de_apostas_manuais);

    srand(time(NULL)); // Apenas aqui, uma vez
    gerar_matriz_pai_de_surpresinhas(quantidade_de_dezenas_por_aposta);




   

	
    
    
    return 0;
}