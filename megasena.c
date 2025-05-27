#include "megasena.h"
#include <stdlib.h>
#include <stdio.h>

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
}
void solicitacoes(int* quantidade, char *frase,  int condicao1, int condicao2) //modularizar solicitações
{
    printf("\n\n %s \n", frase);
    scanf("%d", quantidade);

    if(*quantidade < condicao1 || *quantidade > condicao2){
        printf("\tInvalido, try again");
        solicitacoes(quantidade, frase, condicao1, condicao2); //recursão para casos triviais 
    } 
    else{
       printf("teste");
    }

}

//implementando a logica do professor em sala. criando array de ponteiros para array com inteiros.
//Pegando cada digito e inserindo dentro do array de inteiros, que está dentro do array de ponteiros
void pede_valores_das_dezenas(int *dezenas, int *apostas)
{
   int** array_que_aponta_pra_ponteiros_de_inteiros = (int**)malloc(*apostas * sizeof(int*));//define n numero de apostas manuais  que o usuario inseriu
   
   for(int c = 0; c < *apostas; c++){
    array_que_aponta_pra_ponteiros_de_inteiros[c] = (int*)malloc(*dezenas * sizeof(int));

        for(int j = 0; j < *dezenas; j++){
            printf("\nDigite o valor da aposta manual numero %d e seu digito numero %d\n", c + 1, j + 1);
            scanf("%d", &array_que_aponta_pra_ponteiros_de_inteiros[c][j]);
        }
   }

 // FUNCIONA !!!!!!!! - falta retornar esses valores para main though ...
   for(int x = 0; x < *apostas; x++){
    for(int t = 0; t < *dezenas; t++){
        printf("\n%d", array_que_aponta_pra_ponteiros_de_inteiros[x][t]);

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
            if(b != z && array_que_aponta_pra_ponteiros_de_inteiros[a][b] == array_que_aponta_pra_ponteiros_de_inteiros[a][z]){
                conta_quantas_vezes_o_numero_aparece_no_array++; //ele possui 1 ou mais incidencias no array, o que não é permitido
                if(conta_quantas_vezes_o_numero_aparece_no_array >= 1){
                    printf("%d", conta_quantas_vezes_o_numero_aparece_no_array);
                    printf("\nHa numeros de dezenas duplicados, tente novamente\n");
                    pede_valores_das_dezenas(dezenas, apostas); //tente novamente do zero #implementar melhoria aqui para não voltar do
                    //zero, e sim retornar somente na aposta atual, pois de 2 apostas, o cliente não precisa reescrever as 2 apostas manuais,
                    //somente uma, a que ele se encontra.
                }
            }
        }
        conta_quantas_vezes_o_numero_aparece_no_array = 0;

    }
   }

}
void gerar_dezenas_aleatorias(int quant_dezenas_a_gerar,int* vetor_a_preencher){
	const int LIMITE_DEZENA = 60;
	
	for(int i = 0; i < quant_dezenas_a_gerar; i++){
		vetor_a_preencher[i] = rand() % LIMITE_DEZENA + 1; //Limita os valores aleatórios a 60

		for(int j = 0; j < i; j++){
			if(vetor_a_preencher[j] == vetor_a_preencher[i]){
				i--;
				break;
			}
		}
			printf(("%d\n"),vetor_a_preencher[i]);
	}
	for(int i = 0;i < quant_dezenas_a_gerar;i++){
		printf("\nValor [%d]: %d",i,vetor_a_preencher[i]);	
	}
}