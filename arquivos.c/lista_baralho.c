#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sCarta{
	int valor;
}Carta;

typedef struct sNo{
	Carta info;
	struct sNo *prox;
}No;

No* inicializarLista(No *ptrLista)
{
	ptrLista = NULL;
	return ptrLista;
}

No* alocarNoBaralho()
{
	return (No*) malloc (sizeof(No));
}

void desalocarNoBaralho(No *q)
{
	free(q);
}

void desalocarLista(No *ptrLista)
{
	No* aux;
	while(ptrLista != NULL)
	{
		aux=ptrLista;
		ptrLista= ptrLista->prox;
		free(aux);
	}
	free(ptrLista);
	
}

//cria um baralho ainda nao embaralhado em uma lista simplesmente encadeada
No* empilharBaralho(No *ptrLista){
	
	int i, j;
	No *novo;
	No *aux;
	
	for(i=1; i<5; i++)
	{
		for(j=1; j<14; j++)
		{
			novo = alocarNoBaralho();
		
			if(novo != NULL)
			{
				if(ptrLista == NULL){ 
					ptrLista = novo;
				}
				else if(ptrLista->prox == NULL){
					ptrLista->prox = novo;
				}
				else
				{
					aux = ptrLista;
					while(aux->prox != NULL)
					{
						aux = aux->prox;
					}
					aux->prox = novo;
				}
				
				novo->prox = NULL;
			}
			else
			{
				printf("Erro na alocacao !");
				exit(1);
			}
			
			(novo->info).valor = j;
		}	
	}
	
	return ptrLista;
}

// pega um nó aleatorio da lista nao embaralhada e insere no fim de uma nova lista (no final a funcao retorna essa nova lista para o ptrBaralho da main)
No* embaralharBaralho(No* ptrLista){
	
	int i, j, numRandom;
	
	No* aux1;
	No* aux2;
	
	No* ptrNovaLista;
	ptrNovaLista = inicializarLista(ptrNovaLista);
	No* auxNovaLista;
	
	for(i=52; i>0; i--)
	{
		aux1 = ptrLista;
		
		numRandom = rand() % i;
		
		for(j=0; j<numRandom; j++)
		{
			aux2 = aux1;
			aux1 = aux1->prox;
		}

		if(numRandom == 0)
		{
			ptrLista=aux1->prox;
		}
		else
		{
			aux2->prox = aux1->prox;
		}
		
		aux1->prox = NULL;
		
		if(ptrNovaLista == NULL){ 
			ptrNovaLista = aux1;
		}
		else if(ptrNovaLista->prox == NULL){
			ptrNovaLista->prox = aux1;
		}
		else
		{
			auxNovaLista = ptrNovaLista;
			while(auxNovaLista->prox != NULL)
			{
				auxNovaLista = auxNovaLista->prox;
			}
			auxNovaLista->prox = aux1;
		}
	}	
	
	return ptrNovaLista;
}
