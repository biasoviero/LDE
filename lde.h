#ifndef LDE_H_INCLUDED
#define LDE_H_INCLUDED

struct TipoPtNo{
       int numero;
       struct TipoPtNo* ant;
       struct TipoPtNo* prox;
       };
typedef struct TipoPtNo ptLDE;

//Função que inicializa uma lista vazia
ptLDE* criaLista();

//Função que imprime a lista
void imprime(ptLDE *lista);

//Função que imprime a lista de trás pra frente
void imprimeInvertido(ptLDE *lista);

//Função que insere o número dado na próxima posição vazia da lista
ptLDE* insereFim(ptLDE *lista, int num);

//Função que insere o número dado na primeira posição da lista
ptLDE* insereInicio(ptLDE *lista, int num);

//Função que destrói a lista dada
ptLDE* destroi(ptLDE *lista);

//Dados um número e uma lista, retorna a posição desse número na lista
void procuraNum(ptLDE *lista, int num);

/*
Dados um número e uma lista, se a lista for vazia insere esse número.
Senão, se o num estiver na lista, insere num - 1 na posição anterior e num + 1 na posição sucessora
Se o número não estiver na lista, remove o primeiro e último elementos
*/
ptLDE* insere(ptLDE *lista, int num);

//Dados um número e uma lista, remove esse número da lista
ptLDE* removeNum(ptLDE *lista, int num);

#endif // LSE_H_INCLUDED
