#ifndef LDE_H_INCLUDED
#define LDE_H_INCLUDED

struct TipoPtNo{
       int numero;
       struct TipoPtNo* ant;
       struct TipoPtNo* prox;
       };
typedef struct TipoPtNo ptLDE;

//Fun��o que inicializa uma lista vazia
ptLDE* criaLista();

//Fun��o que imprime a lista
void imprime(ptLDE *lista);

//Fun��o que imprime a lista de tr�s pra frente
void imprimeInvertido(ptLDE *lista);

//Fun��o que insere o n�mero dado na pr�xima posi��o vazia da lista
ptLDE* insereFim(ptLDE *lista, int num);

//Fun��o que insere o n�mero dado na primeira posi��o da lista
ptLDE* insereInicio(ptLDE *lista, int num);

//Fun��o que destr�i a lista dada
ptLDE* destroi(ptLDE *lista);

//Dados um n�mero e uma lista, retorna a posi��o desse n�mero na lista
void procuraNum(ptLDE *lista, int num);

/*
Dados um n�mero e uma lista, se a lista for vazia insere esse n�mero.
Sen�o, se o num estiver na lista, insere num - 1 na posi��o anterior e num + 1 na posi��o sucessora
Se o n�mero n�o estiver na lista, remove o primeiro e �ltimo elementos
*/
ptLDE* insere(ptLDE *lista, int num);

//Dados um n�mero e uma lista, remove esse n�mero da lista
ptLDE* removeNum(ptLDE *lista, int num);

#endif // LSE_H_INCLUDED
