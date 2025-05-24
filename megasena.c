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

void solicitacoes(int* quantidade)
{
    printf("\n\nSelecione a quantidade de dezenas que voce ira jogar nas apostas\n");
    scanf("%d", quantidade);
    if(*quantidade < 6 || *quantidade > 15){
        printf("\n\tInvalido, try again\n");
        solicitacoes(quantidade); //recursão para casos triviais 
    }
}
