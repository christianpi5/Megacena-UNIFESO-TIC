#include "megasena.h"
#include <stdio.h>

int main(){
    int quantidade_de_dezenas_por_aposta; //usar depois pra alguma coisa que ainda não sei
    int quantidade_de_apostas_manuais; // ^^
    menu();
    solicitacoes(&quantidade_de_dezenas_por_aposta, "Digite a quantidade de dezenas que voce ira jogar nas apostas", 6, 15);
    solicitacoes(&quantidade_de_apostas_manuais, "Digite a quantidade de apostas manuais que voce ira jogar", 0, 3);
    pede_valores_das_dezenas(&quantidade_de_dezenas_por_aposta, &quantidade_de_apostas_manuais);
    
    
    return 0;
}