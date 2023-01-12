#include "lde.h"
#include <stdlib.h>
#include <stdio.h>

ptLDE* criaLista(){
    printf("Inicializando lista...\n");
    return NULL;
}

void imprime(ptLDE *lista){

    printf("Imprimindo lista...\n");

    if (lista == NULL) printf("Lista vazia\n");

    else{

        ptLDE *aux = lista; //ponteiro auxiliar que percorrerá toda a lista

        while(aux != NULL){

            //exibe o número desse nodo
            printf("%d ", aux->numero);

            //aponta para o próximo nodo
            aux = aux->prox;
        }
        printf("\n");
    }
}

void imprimeInvertido(ptLDE *lista){

    printf("Imprimindo lista invertida...\n");

    if (lista == NULL) printf("Lista vazia\n");

    else{
        ptLDE *aux = lista;

        //Vai até o final da lista
        while (aux->prox != NULL)
            aux = aux->prox;

        //Imprime os números do final ao início
        while (aux != NULL){
            printf("%d ", aux->numero);
            aux = aux->ant;
        }
        printf("\n");
    }

}

ptLDE* insereFim(ptLDE *lista, int num){

    ptLDE *novo = (ptLDE*) malloc(sizeof(ptLDE)); //aloca novo nodo
    novo->numero = num; //atribui o número dado ao nodo novo

    //caso lista vazia insere novo no início
    if (lista == NULL){
        lista = novo;
        lista->ant = NULL;
        lista->prox = NULL;
    }

    else{

        ptLDE *aux = lista; //ponteiro auxiliar que percorrerá toda a lista

        //percorre toda a lista
        while (aux->prox != NULL)
            aux = aux->prox;

        //Insere nodo novo no final
        aux->prox = novo;
        novo->ant = aux;
        novo->prox = NULL;
    }

    return lista;
}

ptLDE* insereInicio(ptLDE *lista, int num){
    ptLDE *novo = (ptLDE*)malloc(sizeof(ptLDE)); //aloca nodo novo
    novo->numero = num;

    novo->ant = NULL;
    novo->prox = lista; //insere o número antes do resto da lista

    //Caso a lista não seja vazia
    if (lista != NULL){
        lista->ant = novo;
    }

    lista = novo;
    return lista;
}

ptLDE* destroi(ptLDE *lista){
    ptLDE *aux = NULL;

    printf("Lista Destruida\n");

    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
    free(lista);
    return NULL;
}

void procuraNum(ptLDE *lista, int num){
    ptLDE *aux = lista;
    int p = 1; //contador da posição

    while (aux != NULL){
        if (aux->numero == num){
            printf("O numero %d esta na posicao %d da lista\n", num, p);
            return;
        }
        p += 1;
        aux = aux->prox;
    }

    //Quando o while é todo percorrido, significa que num não está na lista
    printf("O numero %d nao esta na lista\n", num);
}

ptLDE* insere(ptLDE *lista, int num){
    //aloca nodo com o num
    ptLDE *novo = (ptLDE*)malloc(sizeof(ptLDE));
    novo->numero = num;

    //aloca nodo com o num - 1
    ptLDE *novoA = (ptLDE*)malloc(sizeof(ptLDE));
    novoA->numero = num - 1;

    //aloca nodo com o num + 1
    ptLDE *novoB = (ptLDE*)malloc(sizeof(ptLDE));
    novoB->numero = num + 1;

    //Caso em que a lista é vazia, recebe o nodo novo
    if (lista == NULL){
        novo->ant = NULL;
        novo->prox = NULL;
        lista = novo;
    }

    else{
        ptLDE *aux = lista; //ponteiro auxiliar para percorrer a lista
        ptLDE *ant = NULL; //ponteiro auxiliar para representar o antecessor de aux
        while(aux != NULL){
            if (aux->numero == num){


                //insere num - 1
                novoA->prox = ant->prox;
                ant->prox = novoA;
                novoA->ant = ant;

                //insere num + 1
                novoB->prox = aux->prox;
                aux->prox = novoB;
                novoB->ant = aux;

                return lista;
            }

            ant = aux; //atualiza o antecessor do aux
            aux = aux->prox; //incrementa aux
        }

        //caso em que num não está na lista
        lista->prox->ant = NULL;
        lista = lista->prox; //remove o primeiro elemento

        ant->ant->prox = NULL;
        ant = ant->ant;//remove o último elemento da lista
    }
    return lista;
}

ptLDE* removeNum(ptLDE *lista, int num){
    //aloca nodo com o num
    ptLDE *novo = (ptLDE*)malloc(sizeof(ptLDE));
    novo->numero = num;

    if(lista == NULL){
        printf("Lista vazia\n");
        return lista;
    }

    else{
        ptLDE *aux = lista;

        printf("Removendo o numero %d da lista...\n", num);

        while(aux->prox != NULL){
            //procura num e se estiver na lista o remove
            if (aux->prox->numero == num){
                aux->prox = aux->prox->prox;
                return lista;
            }
            aux = aux->prox;
        }

        printf("Numero nao esta na lista\n");
        return  lista;
    }
}
