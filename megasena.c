#include "megasena.h"
#include <stdlib.h>
#include <stdio.h>

void menu()
{
    int contador = 0;

    printf("\n\t\t*** MEGA SENA ***\n");

    int* array_de_numeros_para_serem_exibidos = malloc(60 * sizeof(int));
    //Cria aqui um array com 60 numeros
    
    for(int i  = 0; i < 60; i++){
        array_de_numeros_para_serem_exibidos[i] = i + 1;
    }

    for(int j = 0; j < 60; j++){

        if(contador == 10){ //pula linha de 10 em 10 pra sair bonitinho no terminal xD
            printf("\n");
            contador = 0;
        }
        contador++;
        
        if(array_de_numeros_para_serem_exibidos[j] < 9){
            printf("[ 0%d ]", array_de_numeros_para_serem_exibidos[j]); //Acrescenta um zero a esquerda para numeros < 9 para deixar a formatação mais bonita
        }else{
            printf("[ %d ]", array_de_numeros_para_serem_exibidos[j]); 
        }
        
    }

    free(array_de_numeros_para_serem_exibidos); //liberar pra nao dar ruim
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

}
