# LDE
 Implementação em C de uma lista duplamente encadeada
 
 ## Estrutura da lista
 ```
 struct TipoPtNo{
       int numero;
       struct TipoPtNo* ant;
       struct TipoPtNo* prox;
       };
typedef struct TipoPtNo ptLDE;
 
 ```
 
 Cada nodo da lista ptLDE segue a estrutura TipoPtNo, que contém um número inteiro, um ponteiro ant para o nodo anterior e um ponteiro prox para o nodo sucessor.
 
 ## Funções utilizadas
 ### criaLista
 Inicializa uma lista vazia
 
 ### imprime
 Imprime a lista
 
 ### imprimeInvertido
 Imprime a lista de trás para frente
 
 ### insereFim
 Insere o número dado como parâmetro na última posição da lista
 
 ### insereInicio
 Insere o número dado como parâmetro na primeira posição da lista
 
 ### destroi
 Destrói a lista e a torna vazia
 
 ### procuraNum
 Procura na lista o número dado como parâmetro e informa em qual posição ele se encontra
 
 ### insere
 Dado um número como parâmetro, o procura na lista. Caso ele esteja, adiciona num - 1 antes do número dado e num + 1 depois. Caso não esteja, remove o primeiro e último elementos da lista. Se a lista estiver vazia, insere o número na lista.
 
 ### removeNum
 Remove da lista o número dado como parâmetro.
