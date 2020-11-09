#include <stdio.h>
#include <stdlib.h>
#include <time.h> //randomizar as cartas
#include <locale.h> 
#include <string.h>
#include "pilhaseq.h"

Pilha *p1;

int main(){

	int menu, i=0;
	char x, *y;
	char cartas[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};
	char nipes[4][8] = {"Espadas", "Paus", "Copas", "Ouros"};  	//Espadas=0, Paus=1, Copas=2, Ouros=3;
	
	srand(time(NULL));
	
	p1 = criarPilha();
	
	setlocale(LC_ALL, "Portuguese");
		
		for(i=0;i<24;i++){  // São 24 Cartas no total
		x = cartas[rand()%13];
		y = nipes[rand()%4];
		empilhar(p1,(x-48)); // Foram empilhado as cartas mas falta empilhar os nipes aleatorios 
}	
	while (true){
		
		inicio: printf("\n\t\t\t\t\tSeja Bem vindo(a) ao jogo Paciência\n\n");
		printf("  O que deseja fazer?:\n  [1] Jogar\n  [2] Mostrar cartas do cava\n  [3] Regras\n  [4] Creditos\n  [5] Sair\n\n"); 
		
		scanf("%d", &menu);
		system("cls");
		
		switch(menu){
			case 1: 
			printf("Jogar\n");

	break;	
			
			case 2: 
			printf("Cartas do cava\n");	

//	printf("%c de %s \n",cartas[rand()%13], nipes[rand()%4]); // teste de funcionamento
	
	imprimirDadosPilha(p1);  // 40=X, 17=A, 27=K, 33= Q, 26= J 	
	printf("\n");
			break;
			
			case 3: 
			printf("Regras\n");	
			
			break;	
			
			case 4: 
			printf("Creditos\n");	
			break;	
			
			case 5: 
			goto fim;
			break;	
		}		
	}
	fim: printf("Fim do programa");
	return 0;
}

