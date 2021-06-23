#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNoDeque{
	Carta info;
	struct sNoDeque *prox;
	struct sNoDeque *ant;
}NoDeque;

typedef struct sDeque{
	struct sNoDeque *inicio;
	struct sNoDeque *fim;
}DequeEspacos;

DequeEspacos* inicializarDeque(DequeEspacos *deque)
{
	deque = (DequeEspacos*) malloc(sizeof(DequeEspacos));
	deque->inicio = NULL;
	deque->fim = NULL;
	return deque;
}

NoDeque* alocarNoDeque()
{
	return (NoDeque*) malloc (sizeof(NoDeque));
}

void desalocarNoDeque(NoDeque *q)
{
	free(q);
}

void desalocarDeque(DequeEspacos *deque)
{
	NoDeque* aux;
	while(deque->inicio != NULL)
	{
		aux = deque->inicio;
		deque->inicio = (deque->inicio)->prox;
		free(aux);
	}
	free(deque->inicio);
	free(deque->fim);
	free(deque);
	
}

void exibirDeque(DequeEspacos *deque)
{
	
	NoDeque *aux;
	aux = deque->inicio;
	
	if(deque->inicio == NULL){
		return;
	}
	else
	{
		while(aux != NULL){
			if((aux->info).valor == 1 || (aux->info).valor == 14)
			{
				printf("A  ");
			}
			else if((aux->info).valor == 11)
			{
				printf("J  ");
			}
			else if((aux->info).valor == 12)
			{
				printf("Q  ");
			}
			else if((aux->info).valor == 13)
			{
				printf("K  ");
			}
			else
			{
				printf("%d  ",(aux->info).valor);
			}
			
			aux = aux->prox;
		}
	}
	
	return;
}

DequeEspacos* inserirInicio(DequeEspacos *deque, Carta carta)
{
	NoDeque* novoNo;
	novoNo = alocarNoDeque();
	
	if(novoNo != NULL)
	{
		novoNo->ant = NULL;	
		(novoNo->info).valor = carta.valor;
		
		if(deque->inicio == NULL)
		{
			deque->inicio = novoNo;	
			deque->fim = novoNo;
			novoNo->prox = NULL;	
		}
		else if((deque->inicio)->prox == NULL)
		{
			novoNo->prox = deque->inicio;
			(deque->inicio)->ant = novoNo;
			deque->inicio = novoNo;
		}
	}
	else
	{
		printf("Erro na alocacao !");
		exit(1);
	}
	
	return deque;
}

DequeEspacos* inserirFim(DequeEspacos *deque, Carta carta)
{
	NoDeque* novoNo;
	novoNo = alocarNoDeque();
	
	if(novoNo != NULL)
	{
		novoNo->prox = NULL;	
		(novoNo->info).valor = carta.valor;
		
		if(deque->inicio == NULL)
		{
			deque->inicio = novoNo;	
			deque->fim = novoNo;
			novoNo->ant = NULL;	
		}
		else if((deque->inicio)->prox == NULL)
		{
			novoNo->ant = deque->fim;
			(deque->fim)->prox = novoNo;
			deque->fim = novoNo;
		}
	}
	else
	{
		printf("Erro na alocacao !");
		exit(1);
	}
	
	return deque;
}

// quando o usuario forma 3 cartas no espaco
DequeEspacos* resetarDeque(DequeEspacos *deque)
{
	
	desalocarNoDeque(deque->inicio);
	desalocarNoDeque(deque->fim);
	
	deque->inicio = NULL;
	deque->fim = NULL;
	
	return deque;
}









