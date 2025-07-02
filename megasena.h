//se não foi definida anteriormente(if not def) então defina (define)
#ifndef MEGASENA_H 
#define MEGASENA_H

void menu(); //chama menu bonitinho da megacena
void solicitacoes(int* quantidade, char *frase, int condicao1, int condicao2); //pede numero de dezenas >= 6 ou <= 15
void pede_valores_das_dezenas(int* dezenas, int* apostas,int** dezenas_escolhidas);
void gerar_dezenas_aleatorias(int quant_dezenas_a_gerar,int* vetor_a_preencher);
void gerar_matriz_pai_de_surpresinhas(int quantidade_de_surpresinhas,int dezenas,int** surpresinhas);
void gerar_dezena_sorteada(int* valor_sorteado);

int comparar(int* valor_sorteado, int* dezenas_do_usuario, int quantidade_de_dezenas_por_aposta);

int ocorrencias(int acertos, int iteracao1, int iteracao2, int* quadras, int* quinas, int* senas);


#endif
