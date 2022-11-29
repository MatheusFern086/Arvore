 #include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int op,novo,resul=0, valor = 0;
	struct No *antecede = NULL;
	struct No *sucede = NULL;
	struct No *aux = NULL;
	setlocale(LC_ALL,"portuguese");
/*	raiz = (struct No*)malloc(sizeof(struct No));
	raiz->valor = 5;
	raiz->esq = (struct No*)malloc(sizeof(struct No));
	raiz->dir = (struct No*)malloc(sizeof(struct No));
	raiz->esq->valor=2;
	raiz->dir->valor= 7;
	raiz->esq->esq = (struct No*)malloc(sizeof(struct No));
	raiz->esq->dir = (struct No*)malloc(sizeof(struct No));
	raiz->esq->esq->valor = 1;
	raiz->esq->dir->valor = 4;
	raiz->esq->esq->esq = NULL;
	raiz->esq->esq->dir = NULL;
	raiz->esq->dir->esq = NULL;
	raiz->esq->dir->dir = NULL;
	raiz->dir->esq = NULL;
	raiz->dir->dir = NULL;
*/
  /* insereArvoreDeBusca(5,&raiz);
   printf("\n%d teste\n", raiz->valor);
   insereArvoreDeBusca(7,&raiz);
   insereArvoreDeBusca(3,&raiz);
   buscaArvoreBusca(1,raiz); // testando valor que n tem na arvore
   buscaArvoreBusca(5,raiz); // testando valor que tem na arvore
   
    printf("\nPercurso pré:\n");
	preOrdem(raiz);
	
	printf("\nPercurso in:\n");
	inOrdem(raiz);
	
	printf("\nPercurso pós:\n");
	posOrdem(raiz);*/
	
	do{
		printf("\n1 - Inserir Elemento");
		printf("\n2 - Imprimir em Ordem Crescente");
		printf("\n3 - Imprimir em Ordem Decrescente");
		printf("\n4 - Imprimir a soma dos valores");
		printf("\n5 - Contar quantos elementos tem");
		printf("\n6 - Encontra maior numero");
		printf("\n7 - Encontra menor numero");
		printf("\n8 - Valor antecessor");
		printf("\n9 - Valor sucessor");
		printf("\n10 - Remover valor");
		printf("\n0 - Sair\n");
		printf("\nEscolha: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("Informe o número que deseja inserir: ");
				scanf("%d", &novo);
				insereArvoreDeBusca(novo,&raiz);
				break;
			case 2:
				inOrdem(raiz);
				break;
			case 3:
				imprimeDecrescente(raiz);
				break;
			case 4:
				resul = somaArvore(raiz);
				printf("Soma: %d", resul);
				break;
			case 5:
				resul = contaArvore(raiz); 
				printf("Elementos: %d", resul);
				break;
			case 6:
				maiorElemento(raiz);
				break;
			case 7:
				menorElemento(raiz);
				break;
			case 8:
				//ler o valor a ser buscado
				printf("\nInforme o valor que deseja buscar o antecessor: ");
				scanf("%d", &valor);
				
				//buscar o nó na árvore
				aux = busca(raiz, valor);
				
				if(aux != NULL){
					
					antecede = antecessor(aux);
					if(antecede!= NULL){
						antecede = antecessor(aux);
						if(antecede != NULL)
							printf("\nO valor que antecede a raiz é %d: " , antecede->valor);
						else
							printf("\nValor não está na árvore");
					}
				}
				
				break;
			case 9:
				//ler o valor a ser buscado
				printf("\nInforme o valor que deseja buscar o sucessor: ");
				scanf("%d", &valor);
				
				//buscar o nó na árvore
				aux = busca(raiz, valor);
				
				if(aux != NULL){
					
					sucede = sucessor(aux);
					if(sucede!= NULL){
						sucede = sucessor(aux);
						if(sucede != NULL)
							printf("\nO valor que sucede a raiz é %d: " , sucede->valor);
						else
							printf("\nValor não está na árvore");
					}
				}
				break;
			case 10:
				printf("\nInforme o valor que deseja remover: ");
				scanf("%d", &valor);

				aux = busca(raiz, valor);

				if(aux != NULL){
					removePorCopia(&aux);
				}else{

					printf("Valor não está na árvore!");
					break;
				}
				printf("Valor removido com sucesso!");
				break;
			default :
				printf("\nEscolha inválida tente novamente");
		}
	}while(op!= 0);
	
}
