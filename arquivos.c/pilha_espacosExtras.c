#include <stdio.h>
#include <stdlib.h>
#include <string.h>

No* inicializarPilha(No *ptrPilha)
{
	ptrPilha = NULL;
	return ptrPilha;
}

No* alocarNoPilha()
{
	return (No*) malloc (sizeof(No));
}

void desalocarNoPilha(No *q)
{
	free(q);
}

void desalocarPilha(No *pilha)
{
	No* aux;
	while(pilha != NULL)
	{
		aux=pilha;
		pilha = pilha->prox;
		free(aux);
	}
	free(pilha);
	
}

void exibirCartaTopoExtra(No* ptrPilha)
{	
	if(ptrPilha == NULL)
	{
		return;
	}
	else if((ptrPilha->info).valor == 1)
	{
		printf("A  ");
	}
	else if((ptrPilha->info).valor == 11)
	{
		printf("J  ");
	}
	else if((ptrPilha->info).valor == 12)
	{
		printf("Q  ");
	}
	else if((ptrPilha->info).valor == 13)
	{
		printf("K  ");
	}
	else
	{
		printf("%d   ",(ptrPilha->info).valor);
	}
	return;
}

//quando o usuario coloca uma carta no espaco Extra
No* empilharCarta(No* ptrPilha, No* carta)
{
	carta->prox = ptrPilha;
	ptrPilha = carta;
	
	return ptrPilha;
}

//quando ele retira a carta de cima do espaco Extra
No* desempilharCarta(No** ptrPilha)
{
	No* aux;
	aux = *ptrPilha;
	*ptrPilha = (*ptrPilha)->prox;
	
	return aux;
}









