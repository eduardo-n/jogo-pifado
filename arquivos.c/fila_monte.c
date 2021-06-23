#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sFila{
	struct sNo *inicio;
	struct sNo *fim;
}FilaMonte;

FilaMonte* inicializarFila(FilaMonte *fila)
{
	fila = (FilaMonte*) malloc(sizeof(FilaMonte));
	fila->inicio = NULL;
	fila->fim = NULL;
	return fila;
}

void desalocarFila(FilaMonte *fila)
{
	No* aux;
	while(fila->inicio != NULL)
	{
		aux=fila->inicio;
		fila->inicio = (fila->inicio)->prox;
		free(aux);
	}
	free(fila->inicio);
	free(fila->fim);
	free(fila);
	
}

void exibirCartaComprada(No* aux)
{	
	if(aux == NULL)
	{
		return;
	}
	else if((aux->info).valor == 1 || (aux->info).valor == 14)
	{
		printf("A\n");
	}
	else if((aux->info).valor == 11)
	{
		printf("J\n");
	}
	else if((aux->info).valor == 12)
	{
		printf("Q\n");
	}
	else if((aux->info).valor == 13)
	{
		printf("K\n");
	}
	else
	{
		printf("%d\n",(aux->info).valor);
	}
	return;
}

 // cria um monte com as cartas embaralhadas (lista ptrBaralho)
FilaMonte* criarMonte(FilaMonte *fila, No* ptrBaralho)
{	
	int i, j;
	
	No* aux1;
	No* aux2;
	
	for(i=52; i>0; i--)
	{
		aux1 = ptrBaralho;

		for(j=1; j<i; j++)
		{
			aux2 = aux1;
			aux1 = aux1->prox;
		}

		if(i == 1)
		{
			ptrBaralho=aux1->prox;
		}
		else
		{
			aux2->prox = aux1->prox;
		}
		
		aux1->prox = NULL;
		
		if(fila->inicio == NULL){ 
			fila->inicio = aux1;
			fila->fim = aux1;
		}
		else
		{
			(fila->fim)->prox = aux1;
			fila->fim = aux1;
		}
	}		
	
	return fila;
	
}

 //quando o usuario descarta a carta no monte (insercao no fim)
FilaMonte* enfileirar(FilaMonte* fila, No* carta){
	
	if(fila->inicio == NULL){ 
		fila->inicio = carta;
		fila->fim = carta;
	}
	else
	{
		(fila->fim)->prox = carta;
		fila->fim = carta;
	}
	return fila;
}

//quando o usuario compra a carta (remocao no inicio)
No* desenfileirar(FilaMonte **fila)
{
	No* aux;
	aux = (*fila)->inicio;
	(*fila)->inicio = ((*fila)->inicio)->prox;
	
	return aux;
}








