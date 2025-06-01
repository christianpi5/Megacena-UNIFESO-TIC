//se não foi definida anteriormente(if not def) então defina (define)
#ifndef MEGASENA_H 
#define MEGASENA_H

void menu(); //chama menu bonitinho da megacena
void solicitacoes(int* quantidade, char *frase, int condicao1, int condicao2); //pede numero de dezenas >= 6 ou <= 15
void pede_valores_das_dezenas(int* dezenas, int* apostas);
void gerar_dezenas_aleatorias(int quant_dezenas_a_gerar,int* vetor_a_preencher);

void gerar_matriz_pai_de_surpresinhas(int dezenas);

#endif