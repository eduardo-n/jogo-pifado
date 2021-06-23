#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_baralho.c"
#include "fila_monte.c"
#include "deque_espacos.c"
#include "pilha_espacosExtras.c"

/*

 Baralho = lista
 Espaços = deque
 Monte = fila
 EspaçoExtra = pilha
 
*/

int inserirEspacos(DequeEspacos **deque1, DequeEspacos **deque2, DequeEspacos **deque3, DequeEspacos **deque4, No* aux,char opcao){ 
	switch(opcao){
		
		// caso queria inserir uma carta no espaco1
		case '1':
			//se o espaco1 está vazio
			if((*deque1)->inicio==NULL)
			{
				(*deque1) = inserirInicio((*deque1),aux->info);
				free(aux);
				return 1;
			}
			//se o espaco1 tem apenas 1 carta
			else if((*deque1)->inicio == (*deque1)->fim){
				
			//se a nova carta é sequentemente menor que a carta que está no espaco1 ou se a nova carta é igual a do espaco1 
			//ou se a nova carta é um rei e a do esapco é um ás
				if((aux->info.valor == (((*deque1)->inicio)->info.valor -1)) || aux->info.valor == ((*deque1)->inicio)->info.valor ||
				(((*deque1)->inicio)->info.valor == 1 && aux->info.valor == 13))
				{
					//se a nova carta for um rei e a do espaco1 for um ás, o ás passa a ter o valor de 14(numero depois do rei(13))
					if((((*deque1)->inicio)->info.valor == 1 && aux->info.valor == 13)){
						((*deque1)->inicio)->info.valor = 14;
					}
					(*deque1) = inserirInicio((*deque1),aux->info);
					free(aux);
					return 1;
				}
				
			//se a nova carta é sequentemente maior que a carta que esta no espaco1 ou se a nova carta é um ás e a do espaco1 é um rei
				else if((aux->info.valor == (((*deque1)->inicio)->info.valor +1)) || (((*deque1)->inicio)->info.valor == 13 && aux->info.valor == 1))
				{
					//se a nova carta for um ás e a do espaco for um rei, o ás passa a ter o valor de 14 
					if((((*deque1)->inicio)->info.valor == 13 && aux->info.valor == 1)){
						aux->info.valor = 14;
					}
					(*deque1) = inserirFim((*deque1),aux->info);
					free(aux);
					return 1;
				}
				//caso a carta nao seja sequencia nem igual a do espaco1
				else
				{
					return 0;
				}

			}
			
			//caso tenham 2 cartas no espaco
			else
			{
				//a nova carta é igual as 2 cartas do espaco reseta o espaco
				if(((*deque1)->inicio)->info.valor == ((*deque1)->fim)->info.valor && ((*deque1)->inicio)->info.valor == aux->info.valor)
				{
					resetarDeque(*deque1);
					return 2;
				}
				//as duas cartas do espaco sao diferentes e a nova carta é sequentemente menor que a menor carta do espaco 
				else if(((*deque1)->inicio)->info.valor != ((*deque1)->fim)->info.valor && aux->info.valor == ((*deque1)->inicio)->info.valor-1)
				{
					resetarDeque(*deque1);
					return 2;
				}
				//as duas cartas do espaco sao diferentes e a nova carta é sequentemente maior que a maior carta do espaco ou 
				//se a nova carta for um ás e a maior carta deles for um rei
				else if((((*deque1)->inicio)->info.valor != ((*deque1)->fim)->info.valor && aux->info.valor == ((*deque1)->fim)->info.valor+1) ||
				(aux->info.valor == 1 && ((*deque1)->fim)->info.valor == 13))
				{
					resetarDeque(*deque1);
					return 2;
				}
				return 0;
			}
			break;
			
		case '2':
			if((*deque2)->inicio==NULL)
			{
				(*deque2) = inserirInicio((*deque2),aux->info);
				free(aux);
				return 1;
			}
			else if((*deque2)->inicio == (*deque2)->fim){
				if((aux->info.valor == (((*deque2)->inicio)->info.valor -1)) || aux->info.valor == ((*deque2)->inicio)->info.valor || 
				(((*deque2)->inicio)->info.valor == 1 && aux->info.valor == 13))
				{
					if((((*deque2)->inicio)->info.valor == 1 && aux->info.valor == 13)){
						((*deque2)->inicio)->info.valor = 14;
					}
					(*deque2) = inserirInicio((*deque2),aux->info);
					free(aux);
					return 1;
				}
				else if((aux->info.valor == (((*deque2)->inicio)->info.valor +1)) || (((*deque2)->inicio)->info.valor == 13 && aux->info.valor == 1)) //aux > deque->inicio em 1 unidade;
				{
					if((((*deque2)->inicio)->info.valor == 13 && aux->info.valor == 1)){
						aux->info.valor = 14;
					}
					(*deque2) = inserirFim((*deque2),aux->info);
					free(aux);
					return 1;
				}
				else
				{
					return 0;	
				}
			}
			else
			{
				if(((*deque2)->inicio)->info.valor == ((*deque2)->fim)->info.valor && ((*deque2)->inicio)->info.valor == aux->info.valor)
				{
					resetarDeque(*deque2);
					return 2;
				}
				else if(((*deque2)->inicio)->info.valor != ((*deque2)->fim)->info.valor && aux->info.valor == ((*deque2)->inicio)->info.valor-1)
				{
					resetarDeque(*deque2);
					return 2;
				}
				else if(((*deque2)->inicio)->info.valor != ((*deque2)->fim)->info.valor && aux->info.valor == ((*deque2)->fim)->info.valor+1 ||
				(aux->info.valor == 1 && ((*deque2)->fim)->info.valor == 13))
				{
					resetarDeque(*deque2);
					return 2;
				}
				return 0;
			}
			break;
			
		case '3':
			if((*deque3)->inicio==NULL)
			{
				(*deque3) = inserirInicio((*deque3),aux->info);
				free(aux);
				return 1;
			}
			else if((*deque3)->inicio == (*deque3)->fim){
				if((aux->info.valor == (((*deque3)->inicio)->info.valor -1)) || aux->info.valor == ((*deque3)->inicio)->info.valor || 
				(((*deque3)->inicio)->info.valor == 1 && aux->info.valor == 13))
				{
					if((((*deque3)->inicio)->info.valor == 1 && aux->info.valor == 13)){
						((*deque3)->inicio)->info.valor = 14;
					}
					(*deque3) = inserirInicio((*deque3),aux->info);
					free(aux);
					return 1;
				}
				else if((aux->info.valor == (((*deque3)->inicio)->info.valor +1)) || (((*deque3)->inicio)->info.valor == 13 && aux->info.valor == 1)) //aux > deque->inicio em 1 unidade;
				{
					if((((*deque3)->inicio)->info.valor == 13 && aux->info.valor == 1)){
						aux->info.valor = 14;
					}
					(*deque3) = inserirFim((*deque3),aux->info);
					free(aux);
					return 1;
				}
				return 0;
			}
			else
			{
				if(((*deque3)->inicio)->info.valor == ((*deque3)->fim)->info.valor && ((*deque3)->inicio)->info.valor == aux->info.valor)
				{
					resetarDeque(*deque2);
					return 2;
				}
				else if(((*deque3)->inicio)->info.valor != ((*deque3)->fim)->info.valor && aux->info.valor == ((*deque3)->inicio)->info.valor-1)
				{
					resetarDeque(*deque3);
					return 2;
				}
				else if(((*deque3)->inicio)->info.valor != ((*deque3)->fim)->info.valor && aux->info.valor == ((*deque3)->fim)->info.valor+1 ||
				(aux->info.valor == 1 && ((*deque3)->fim)->info.valor == 13))
				{
					resetarDeque(*deque3);
					return 2;
				}
				return 0;
			}
			break;
			
		case '4':
			if((*deque4)->inicio==NULL)
			{
				(*deque4) = inserirInicio((*deque4),aux->info);
				free(aux);
				return 1;
			}
			else if((*deque4)->inicio == (*deque4)->fim){
				if((aux->info.valor == (((*deque4)->inicio)->info.valor -1)) || aux->info.valor == ((*deque4)->inicio)->info.valor || 
				(((*deque4)->inicio)->info.valor == 1 && aux->info.valor == 13))
				{
					if(((*deque3)->inicio)->info.valor == 1 && aux->info.valor == 13 && aux->info.valor == 13){
						((*deque3)->inicio)->info.valor == 14;
					}
					(*deque4) = inserirInicio((*deque4),aux->info);
					free(aux);
					return 1;
				}
				else if((aux->info.valor == (((*deque4)->inicio)->info.valor +1)) || (((*deque1)->inicio)->info.valor == 13 && aux->info.valor == 1)) //aux > deque->inicio em 1 unidade;
				{
					if((((*deque1)->inicio)->info.valor == 13 && aux->info.valor == 1)){
						aux->info.valor = 14;
					}
					(*deque4) = inserirFim((*deque4),aux->info);
					free(aux);
					return 1;
				}
				return 0;
			}
			else
			{
				if(((*deque4)->inicio)->info.valor == ((*deque4)->fim)->info.valor && ((*deque4)->inicio)->info.valor == aux->info.valor)
				{
					resetarDeque(*deque4);
					return 2;
				}
				else if(((*deque4)->inicio)->info.valor != ((*deque4)->fim)->info.valor && aux->info.valor == ((*deque4)->inicio)->info.valor-1)
				{
					resetarDeque(*deque4);
					return 2;
				}
				else if(((*deque4)->inicio)->info.valor != ((*deque4)->fim)->info.valor && aux->info.valor == ((*deque4)->fim)->info.valor+1 ||
				(aux->info.valor == 1 && ((*deque4)->fim)->info.valor == 13))
				{
					resetarDeque(*deque4);
					return 2;
				}
				return 0;
			}
			break;
			
		default:
			return ;
	}
}


int main(){
	
	int contMonteJ1 = 52, contMonteJ2 = 52, menu = 1, jogador = 1,pontosJ1 = 0, pontosJ2 =0, controle = 1;
	char opcao1, opcao2, opcao3;

	No *baralhoJ1;
	No *baralhoJ2;
	No *aux;
	
	FilaMonte *monteJ1;
	FilaMonte *monteJ2;
	
	DequeEspacos *espacoJ1_1;
	DequeEspacos *espacoJ1_2;
	DequeEspacos *espacoJ1_3;
	DequeEspacos *espacoJ1_4;
	
	DequeEspacos *espacoJ2_1;
	DequeEspacos *espacoJ2_2;
	DequeEspacos *espacoJ2_3;
	DequeEspacos *espacoJ2_4;
	
	No *espacosExtrasJ1;
	No *espacosExtrasJ2;
					
	// Criando os baralhos
	baralhoJ1 = inicializarLista(baralhoJ1);	
	baralhoJ1 = empilharBaralho(baralhoJ1);
	baralhoJ1 = embaralharBaralho(baralhoJ1);
		
	baralhoJ2 = inicializarLista(baralhoJ2);
	baralhoJ2 = empilharBaralho(baralhoJ2);
	baralhoJ2 = embaralharBaralho(baralhoJ2);
	
	//  Enfileirando as cartas do baralho em um novo monte, apos ser embaralhado
	monteJ1 = inicializarFila(monteJ1);
	monteJ1 = criarMonte(monteJ1, baralhoJ1);
	monteJ2 = inicializarFila(monteJ2);
	monteJ2 = criarMonte(monteJ2, baralhoJ2);
	

	espacoJ1_1 = inicializarDeque(espacoJ1_1);
	espacoJ1_2 = inicializarDeque(espacoJ1_2);
	espacoJ1_3 = inicializarDeque(espacoJ1_3);
	espacoJ1_4 = inicializarDeque(espacoJ1_4);
	
	espacoJ2_1 = inicializarDeque(espacoJ2_1);
	espacoJ2_2 = inicializarDeque(espacoJ2_2);
	espacoJ2_3 = inicializarDeque(espacoJ2_3);
	espacoJ2_4 = inicializarDeque(espacoJ2_4);
	
	espacosExtrasJ1 = inicializarPilha(espacosExtrasJ1);
	espacosExtrasJ2 = inicializarPilha(espacosExtrasJ2);
	
	while(pontosJ1 != 5 && pontosJ2 != 5)
	{
		if(jogador == 1)
		{	
			opcao1=0;
			
			while(opcao1 != '1' && opcao1 != '2' && opcao1 != '3')
			{
				printf("\n\n-------------- PiFaDo - Pife Adaptado --------------");
				printf("\n\n___________ J1 ___________\n");
				printf("\nPontos ganhos: %d\n",pontosJ1);
				printf("M1: %d\n", contMonteJ1);
				printf("E1: ");
				exibirDeque(espacoJ1_1);
				printf("\nE2: ");
				exibirDeque(espacoJ1_2);
				printf("\nE3: ");
				exibirDeque(espacoJ1_3);
				printf("\nE4: ");
				exibirDeque(espacoJ1_4);
				printf("\nX1: ");
				exibirCartaTopoExtra(espacosExtrasJ1);
				printf("\n\n----------opcoes----------");
				printf("\n\n1- Comprar do MONTE");
				printf("\n2- Comprar do espaco extra");
				printf("\n3- Desistir do jogo\n");
				printf("\nDigite a opcao desejada: ");
				fflush(stdin);
				scanf("%c",&opcao1);
				system("cls");
				
				if(opcao1 == '2' && espacosExtrasJ1 == NULL)
				{
					printf("Seu Espaco Extra esta vazio");
					opcao1 = 0;
				}
			}
			if(opcao1 == '1')
			{
				contMonteJ1 --;
				aux = desenfileirar(&monteJ1); // aux recebe a carta do monte
				opcao2 = 0;
				controle = 0;
				
				while((opcao2 != '1' && opcao2 != '2' && opcao2 != '3' && opcao2 != '4' && opcao2 != '5' && opcao2 != '6') || controle==0)
				{
					printf("\n\n-------------- PiFaDo - Pife Adaptado --------------");
					printf("\n\n___________ J1 ___________\n");
					printf("\nCarta Comprada: ");
					exibirCartaComprada(aux);
					printf("M1: %d\n", contMonteJ1);
					printf("E1: ");
					exibirDeque(espacoJ1_1);
					printf("\nE2: ");
					exibirDeque(espacoJ1_2);
					printf("\nE3: ");
					exibirDeque(espacoJ1_3);
					printf("\nE4: ");
					exibirDeque(espacoJ1_4);
					printf("\nX1: ");
					exibirCartaTopoExtra(espacosExtrasJ1);
					printf("\n\n----------opcoes----------");
					printf("\n\n1- colocar carta no E1");
					printf("\n2- colocar carta no E2");
					printf("\n3- colocar carta no E3");
					printf("\n4- colocar carta no E4");
					printf("\n5- colocar carta no EXTRA");
					printf("\n6- descartar carta no MONTE\n");
					printf("\nDigite a opcao desejada: ");
					fflush(stdin);
					scanf("%c",&opcao2);
					system("cls");
					
					if(opcao2 == '5')
					{
						espacosExtrasJ1 = empilharCarta(espacosExtrasJ1, aux);
						controle = 1;
					}
					else if(opcao2 == '6')
					{
						monteJ1 = enfileirar(monteJ1, aux);
						contMonteJ1 ++;
						controle = 1;
					}
					else
					{						
						controle = inserirEspacos(&espacoJ1_1, &espacoJ1_2, &espacoJ1_3, &espacoJ1_4, aux, opcao2);
						if(controle == 2)
						{
							pontosJ1 ++;
						}
					}
					if(controle == 0)
					{
						printf("\nSua jogada eh invalida! Escolha outra opcao");	
					}
				}
			}
			else if(opcao1 == '2')
			{	
				aux = desempilharCarta(&espacosExtrasJ1);
				opcao3 = 0;
				controle = 0;
				
				while((opcao3 != '1' && opcao3 != '2' && opcao3 != '3' && opcao3 != '4') || controle == 0)
				{
					printf("\n\n-------------- PiFaDo - Pife Adaptado --------------");
					printf("\n\n___________ J1 ___________\n");
					printf("\nCarta Comprada: ");
					exibirCartaComprada(aux);
					printf("M1: %d\n", contMonteJ1);
					printf("E1: ");
					exibirDeque(espacoJ1_1);
					printf("\nE2: ");
					exibirDeque(espacoJ1_2);
					printf("\nE3: ");
					exibirDeque(espacoJ1_3);
					printf("\nE4: ");
					exibirDeque(espacoJ1_4);
					printf("\nX1: ");
					exibirCartaTopoExtra(espacosExtrasJ1);
					printf("\n\n----------opcoes----------");
					printf("\n\n1- colocar carta no E1");
					printf("\n2- colocar carta no E2");
					printf("\n3- colocar carta no E3");
					printf("\n4- colocar carta no E4\n");
					printf("\nDigite a opcao desejada: ");
					fflush(stdin);
					scanf("%c",&opcao3);
					system("cls");
					
					controle = inserirEspacos(&espacoJ1_1, &espacoJ1_2, &espacoJ1_3, &espacoJ1_4, aux, opcao3);
					
					if(controle == 2)
					{
						pontosJ1 ++;
					}
					if(controle == 0)
					{
						printf("\nsua jogada eh invalida. Escolha outra opcao");
					}
				}
			}
			else
			{
				pontosJ2 = 5;	
			}
			
		}
		else
		{
			opcao1=0;
			
			while(opcao1 != '1' && opcao1 != '2')
			{
				printf("\n\n-------------- PiFaDo - Pife Adaptado --------------");
				printf("\n\n___________ J2 ___________\n");
				printf("\nPontos ganhos: %d\n",pontosJ2);
				printf("M2: %d\n", contMonteJ2);
				printf("E1: ");
				exibirDeque(espacoJ2_1);
				printf("\nE2: ");
				exibirDeque(espacoJ2_2);
				printf("\nE3: ");
				exibirDeque(espacoJ2_3);
				printf("\nE4: ");
				exibirDeque(espacoJ2_4);
				printf("\nX2: ");
				exibirCartaTopoExtra(espacosExtrasJ2);
				printf("\n\n----------opcoes----------");
				printf("\n\n1- Comprar do MONTE");
				printf("\n2- Comprar do espaco extra");
				printf("\n3- Desistir do jogo\n");
				printf("\nDigite a opcao desejada: ");
				fflush(stdin);
				scanf("%c",&opcao1);
				system("cls");
				
				if(opcao1=='2' && espacosExtrasJ2 == NULL)
				{
					printf("Seu Espaco Extra esta vazio");
					opcao1 = 0;
				}
			}
			if(opcao1=='1')
			{
				contMonteJ2--;
				aux = desenfileirar(&monteJ2); // aux recebe a carta do monte
				opcao2 = 0;
				controle = 0;
				
				while((opcao2 != '1' && opcao2 != '2' && opcao2 != '3' && opcao2 != '4' && opcao2 != '5' && opcao2 != '6') || controle == 0)
				{
					printf("\n\n-------------- PiFaDo - Pife Adaptado --------------");
					printf("\n\n___________ J2 ___________\n");
					printf("\nCarta Comprada: ");
					exibirCartaComprada(aux);
					printf("M2: %d\n", contMonteJ2);
					printf("E1: ");
					exibirDeque(espacoJ2_1);
					printf("\nE2: ");
					exibirDeque(espacoJ2_2);
					printf("\nE3: ");
					exibirDeque(espacoJ2_3);
					printf("\nE4: ");
					exibirDeque(espacoJ2_4);
					printf("\nX2: ");
					exibirCartaTopoExtra(espacosExtrasJ2);
					printf("\n\n----------opcoes----------");
					printf("\n\n1- colocar carta no E1");
					printf("\n2- colocar carta no E2");
					printf("\n3- colocar carta no E3");
					printf("\n4- colocar carta no E4");
					printf("\n5- colocar carta no EXTRA");
					printf("\n6- descartar carta no MONTE\n");
					printf("\nDigite a opcao desejada: ");
					fflush(stdin);
					scanf("%c",&opcao2);
					system("cls");
					
					if(opcao2 == '5')
					{
						espacosExtrasJ2 = empilharCarta(espacosExtrasJ2, aux);	
						controle = 1;
					}
					else if(opcao2 == '6')
					{
						monteJ2 = enfileirar(monteJ2,aux);
						contMonteJ2 ++;
						controle = 1;
					}
					else
					{		
						controle = inserirEspacos(&espacoJ2_1, &espacoJ2_2, &espacoJ2_3, &espacoJ2_4, aux, opcao2);
						if(controle == 2)
						{
							pontosJ2 ++;
						}
					}
					if(controle == 0)
					{
						printf("\nSua jogada eh invalida. Escolha outra opcao");	
					}
				}
			}
			else if(opcao1 == '2')
			{	
				aux = desempilharCarta(&espacosExtrasJ2);
				opcao3 = 0;
				controle = 0;
				
				while((opcao3 != '1' && opcao3 != '2' && opcao3 != '3' && opcao3 != '4' && controle != 0) || controle == 0)
				{
					printf("\n\n-------------- PiFaDo - Pife Adaptado --------------");
					printf("\n\n___________ J2 ___________\n");
					printf("\nCarta Comprada: ");
					exibirCartaComprada(aux);
					printf("M2: %d\n", contMonteJ2);
					printf("E1: ");
					exibirDeque(espacoJ2_1);
					printf("\nE2: ");
					exibirDeque(espacoJ2_2);
					printf("\nE3: ");
					exibirDeque(espacoJ2_3);
					printf("\nE4: ");
					exibirDeque(espacoJ2_4);
					printf("\nX2: ");
					printf("\n\n----------opcoes----------");
					exibirCartaTopoExtra(espacosExtrasJ2);
					printf("\n\n1- colocar carta no E1");
					printf("\n2- colocar carta no E2");
					printf("\n3- colocar carta no E3");
					printf("\n4- colocar carta no E4\n");
					printf("\nDigite a opcao desejada: ");
					fflush(stdin);
					scanf("%c",&opcao3);
					system("cls");
					
					controle = inserirEspacos(&espacoJ2_1, &espacoJ2_2, &espacoJ2_3, &espacoJ2_4, aux, opcao3);
					
					if(controle == 2)
					{
						pontosJ2 ++;
					}
					if(controle == 0)
					{
						printf("\nSua jogada eh invalida. Escolha outra opcao");	
					}
				}
			}
			else
			{
				pontosJ1 = 5;
			}
		}
		
		if(jogador == 1)
		{
			jogador = 2;	
		}
		else
		{
			jogador = 1;	
		}
		system("cls");
	}
	
	if(pontosJ1 == 5)
	{
		printf("\n\nParabens: Jogador1 ganhou o jogo\n");
	}
	else if(pontosJ2 == 5)
	{
		printf("\n\nParabens: Jogador2 ganhou o jogo\n");
	}
	
	desalocarFila(monteJ1);
	desalocarFila(monteJ2);
	
	desalocarDeque(espacoJ1_1);
	desalocarDeque(espacoJ1_2);
	desalocarDeque(espacoJ1_3);
	desalocarDeque(espacoJ1_4);
	desalocarDeque(espacoJ2_1);
	desalocarDeque(espacoJ2_2);
	desalocarDeque(espacoJ2_3);
	desalocarDeque(espacoJ2_4);
	
	desalocarLista(baralhoJ1);
	desalocarLista(baralhoJ2);
	
	desalocarPilha(espacosExtrasJ1);
	desalocarPilha(espacosExtrasJ2);

	return 0;
}
