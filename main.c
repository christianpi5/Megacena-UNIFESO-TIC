#include "megasena.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main(){
    int quantidade_de_dezenas_por_aposta; //dezenas escolhidas pelo usuario
    int quantidade_de_apostas_manuais;  //apostas escolhidas pelo usuario
    int teimosinhas, quantidade_de_surpresinhas;
    float valor_aposta;
    float valor_dezena[] = {5.00,35.00,140.00,420.00,1050.00,2310.00,4620.00,8580.00,15015.00,25025.00};
    int ** dezenas_escolhidas; //Matriz pra saber as dezenas escolhidas
    int ** surpresinhas_sorteadas; //Matriz para salvar as surpresinhas do usuário
	int *dezenas_sorteadas; // Vetor pra saber qual vai ser a combinação vencedora
	
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
	while (true){
	    printf("\nDigite quantas teimosinhas voce gostaria: ");
	    scanf("%d",&teimosinhas);
	    
	    if(teimosinhas == 0 || teimosinhas == 2 || teimosinhas == 4 || teimosinhas == 8){
	        break;
	    }
	    printf("Valor invalido, voce pode escolher, 0, 2 ,4 ou 8 surpresinhas\n");
	}
	surpresinhas_sorteadas = (int**)malloc(quantidade_de_surpresinhas * sizeof(int*));
	for(int c = 0; c < quantidade_de_surpresinhas; c++){
		surpresinhas_sorteadas[c] = (int*)malloc(quantidade_de_dezenas_por_aposta * sizeof(int));
	}
	gerar_matriz_pai_de_surpresinhas(quantidade_de_surpresinhas,quantidade_de_dezenas_por_aposta,surpresinhas_sorteadas);
    if(teimosinhas == 0){
        teimosinhas =1;
        
    };
    
    valor_aposta = teimosinhas * (valor_dezena[quantidade_de_dezenas_por_aposta - 6] * (quantidade_de_apostas_manuais + quantidade_de_surpresinhas));
    
    printf("A sua aposta requer um deposito de: %.2f\nDeseja confirmar? ",valor_aposta);
    
//MUDANÇAS

    int* valor_sorteado = (int*)malloc(6 * sizeof(int) );
    gerar_dezena_sorteada(valor_sorteado);
    
    
    //Loop para definir acertos
    int indice_surpresinha = 0;
    int indice_manual = 0;
    int quadras = 0;
    int quinas = 0;
    int senas = 0;

    //Essas variaveis determinam quantas "quadras/senas/quinas" o usuario vai ter de acordo com quantas dezenas ele escolheu(6 - 15) e ao acertar 4/5 ou 6 numeros.
    //(ao chamar a função ocorrencias)
    int iteracao_4_acertos = (quantidade_de_dezenas_por_aposta - 6) + 1;
    int iteracao_5_acertos_quadra = (quantidade_de_dezenas_por_aposta - 6);
    int iteracao_5_acertos_quina = (quantidade_de_dezenas_por_aposta - 5);
    int iteracao_6_acertos_quadra = (quantidade_de_dezenas_por_aposta - 6);
    int iteracao_6_acertos_quina = (quantidade_de_dezenas_por_aposta - 6);

        //int acertos_manual = 6; <---- use aqui e comente o acertos_manual debaixo para testar <-------------------------------------------
        do{
        int acertos_manual = comparar(valor_sorteado, dezenas_escolhidas[indice_manual], quantidade_de_dezenas_por_aposta);

        printf("\nAcertos de aposta manual numero %d: %d\n", indice_manual + 1, acertos_manual);

        if(acertos_manual == 4){
            ocorrencias(acertos_manual, iteracao_4_acertos,0, &quadras, &quinas, &senas);
            printf("\nSeu numero de quadras foi: %d\n", quadras); //ok
        }else if(acertos_manual == 5){
            ocorrencias(acertos_manual, iteracao_5_acertos_quadra, iteracao_5_acertos_quina, &quadras, &quinas, &senas);
            printf("\nSeu numero de quadras foi: %d\n", quadras); //ok
            printf("\nSeu numero de quinas foi: %d\n", quinas); //ok

        } else if(acertos_manual == 6){
            ocorrencias(acertos_manual, iteracao_6_acertos_quadra, iteracao_6_acertos_quina, &quadras, &quinas, &senas);
            printf("\nSeu numero de quadras foi: %d\n", quadras); //ok
            printf("\nSeu numero de quinas foi: %d\n", quinas);  //ok
            printf("\nSeu numero de senas foi: %d\n", senas); //sempre 1
        }

        indice_manual++;
    } while(indice_manual < quantidade_de_apostas_manuais);

    printf("\nfim\n");

    do{
        int acertos = comparar(valor_sorteado, surpresinhas_sorteadas[indice_surpresinha], quantidade_de_dezenas_por_aposta);
        printf("\nAcertos de surpresinha numero %d: %d\n", indice_surpresinha + 1, acertos);

        if(acertos == 4){
            ocorrencias(acertos, iteracao_4_acertos,0, &quadras, &quinas, &senas);
        }else if(acertos == 5){
            ocorrencias(acertos, iteracao_5_acertos_quadra, iteracao_5_acertos_quina, &quadras, &quinas, &senas);
        } else if(acertos == 6){
            ocorrencias(acertos, iteracao_6_acertos_quadra, iteracao_6_acertos_quina, &quadras, &quinas, &senas);
        }
        indice_surpresinha++;
    } while(indice_surpresinha < quantidade_de_surpresinhas);




    return 0;
}
