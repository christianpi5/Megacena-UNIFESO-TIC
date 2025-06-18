#include "megasena.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void menu()
{
    printf("\n\t\t** MEGA SENA **\n");

    for(int j = 0; j < 60; j++){
		// Toda vez que o j for divisivel por 10 ele da a quebra de linha
        if(j % 10 == 0){
            printf("\n");
        }
        //Assim tira a necessidade de ter 2 dois for, e reduz pra um só, sem ter a necessidade de salvar os números a serem exibidos
        if(j + 1 < 10 ){
            printf("[ 0%d ]", j + 1); //Acrescenta um zero a esquerda para numeros < 9 para deixar a formatação mais bonita
        }else{
            printf("[ %d ]", j + 1); 
        }
    }
    printf("\n\nOla, bem vindo ao app da mega sena, o que voce deseja?\n"
	"1 - Criar aposta\n"
	"2 - Verificar aposta criada\n"
	"3 - Verificar resultado\n"
	"4 - Sair da aplicacao\n");
}
void solicitacoes(int* quantidade, char *frase,  int condicao1, int condicao2) //modularizar solicitações
{
    printf("\n\n %s \n", frase);
    scanf("%d", quantidade);

    if(*quantidade < condicao1 || *quantidade > condicao2){
        printf("\tInvalido, try again");
        solicitacoes(quantidade, frase, condicao1, condicao2); //recursão para casos triviais 
    } 

}

//implementando a logica do professor em sala. criando array de ponteiros para array com inteiros.
//Pegando cada digito e inserindo dentro do array de inteiros, que está dentro do array de ponteiros
void pede_valores_das_dezenas(int* dezenas, int* apostas,int** dezenas_escolhidas)
{     
	
	/*
	Agora o código não usa de recursão para retornar ao início, ele roda dentro de um while, essa implementação ainda não está 100%, vai ser preciso 
	Usar um segundo while para o fluxo ser o seguinte, -> Input do usuario -> validacao -> input -> validacao... 
	Assim a validação é feita por aposta para não precisar voltar os inputs ao início
	*/
	bool retorno;	
	do{
		retorno = false;
		
		dezenas_escolhidas = (int**)malloc(*apostas * sizeof(int*));
	   for(int c = 0; c < *apostas; c++){
	   	dezenas_escolhidas[c] = (int*)malloc(*dezenas * sizeof(int));	
	        for(int j = 0; j < *dezenas; j++){
	            printf("\nDigite o valor da dezena [%d] da aposta [%d]\n",  j + 1, c + 1);
	            scanf("%d", &dezenas_escolhidas[c][j]);
	        }
	   }
	
	 // Demonstrando dezenas escolhidas separado por apostas
	   for(int x = 0; x < *apostas; x++){
	    printf("\nAposta %d: \n", x+1);
	    for(int t = 0; t < *dezenas; t++){
	        printf("\n[%d]", dezenas_escolhidas[x][t]);
	    }
	   }
	   //Validação
	   int conta_quantas_vezes_o_numero_aparece_no_array = 0;
	   for(int a = 0; a < *apostas; a++){
	    for(int b = 0; b < *dezenas; b++){
	        //Aqui eu peço pra z ser 1 a mais que b, pois não faz sentido comparar z com numeros passados
	        //pois os numeros passados já fizeram suas contagens com o restante dos numeros.
	        //seria desnecessário comparar o index atual com o index anterior, ja que anterior ja foi comparado
	        //com o atual. e também não faz sentido comparar o index atual com index atual, pois OBVIAMMENTE são valores iguais.
	        for(int z = b + 1; z < *dezenas; z++){
	            //quando b for diferente de z, ou seja, quando os indices forem diferentes.
	            //pois não faz diferente comparar numeros quando sao de msm indice, pois OBVIAMMENTE serão iguais
	            if(b != z && dezenas_escolhidas[a][b] == dezenas_escolhidas[a][z]){
	                conta_quantas_vezes_o_numero_aparece_no_array++; //ele possui 1 ou mais incidencias no array, o que não é permitido
	                if(conta_quantas_vezes_o_numero_aparece_no_array >= 1){
	                    printf("%d", conta_quantas_vezes_o_numero_aparece_no_array);
	                    printf("\nHa numeros de dezenas duplicados, tente novamente\n");
	                    retorno = true;
						break; //tente novamente do zero #implementar melhoria aqui para não voltar do
	                    //zero, e sim retornar somente na aposta atual, pois de 2 apostas, o cliente não precisa reescrever as 2 apostas manuais,
	                    //somente uma, a que ele se encontra.
	                }
	            }
	        }
	        conta_quantas_vezes_o_numero_aparece_no_array = 0;
	
	    }
	   }
	} while(retorno != false);
}
void gerar_dezenas_aleatorias(int quant_dezenas_a_gerar,int* vetor_a_preencher){
	const int LIMITE_DEZENA = 60;
	
	for(int i = 0; i < quant_dezenas_a_gerar; i++){
		vetor_a_preencher[i] = rand() % LIMITE_DEZENA + 1; //Limita os valores aleatórios a 60
		for(int j = 0; j < i; j++){ //obriga I a refazer um novo numero aleatoria caso o mesmo seja identico a algum numero anterior desde que J<I
			if(vetor_a_preencher[j] == vetor_a_preencher[i]){
				i--;
				break;
			}
		}
	}
	for(int i = 0;i < quant_dezenas_a_gerar;i++){
		printf("\nValor [%d]: %d",i,vetor_a_preencher[i]);	
	}
}

void gerar_matriz_pai_de_surpresinhas(int quantidade_de_surpresinhas,int dezenas,int** surpresinhas)
{
    //Criação da MATRIZ de surpresinhas
    int** matriz_pai_de_surpresinhas = (int**)malloc(quantidade_de_surpresinhas * sizeof(int*));

    for (int j = 0; j < quantidade_de_surpresinhas; j++) {
    matriz_pai_de_surpresinhas[j] = (int*)malloc(dezenas * sizeof(int));
    printf("\nGERANDO SURPRESINHA %d\n", j + 1);
    gerar_dezenas_aleatorias(dezenas, matriz_pai_de_surpresinhas[j]);
}
	surpresinhas = matriz_pai_de_surpresinhas;
}
