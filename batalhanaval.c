#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	char inimigo[8][8];			//matriz 8x8 do tabuleiro valores
	char tabuleiro[8][8];		//matriz 8x8 do tabuleiro impressão
	char nome[10], nome2[10];
	int a, c, p = 1, cont = 0, i = 0, ops = 0, tr, d;
	int pontos[2];
	int control;
	
	for(a = 0; a < 8; a++){
		for(c = 0; c < 8; c++){
			inimigo[a][c] = 0;
		}
	}
	
	inimigo[1][1] = 1;    //Sumimarino
	inimigo[4][4] = 3;    //Fragata
	inimigo[4][5] = 3;    //Fragata
	inimigo[6][3] = 3;    //Porta avião
	inimigo[6][4] = 3;    //Porta avião
	inimigo[6][5] = 3;    //Porta avião
	
	printf("------------------------------ Jogo Batalha Naval ------------------------------\n");
	
	printf("1 - Players vs Console.\n2 - Player vs Player.");
	do{
		printf("\nDigite: ");
		scanf("%d", &ops);
	}while((ops > 2) || (ops < 1));
	
	do{
		switch (ops){
			case 1:
				
				//Exibi tipo de partida selecionada
				printf("\n--------------------------------- Selecionado ----------------------------------\n");
				printf("----------------------------- Player vs Computer! ------------------------------");
			
				printf("\nNome do Player: ");
				scanf("%s", &nome[10]);
				system ("clear");
				
				printf("\n\n\n------------------------------ Tiros ------------------------------\n");
				printf("\nEmbarcacoes:1 - Fragata   //   2 - Porta Avioes   //   3 - Submarino\n");
				printf("\t0 \t1 \t2 \t3 \t4 \t5 \t6 \t7 \n");
				
				do{
					for(a = 0; a < 8; a++){
						printf("\n%d", a);
						for(c = 0; c < 8; c++){
							tabuleiro[a][c] = '~';
							printf("\t%c", tabuleiro[a][c]);
						}
						printf("\n");
					}

					do{
						
						do{
							printf("Linha: ");						//digitar a linha de 0 á 7
							scanf("%d", &a);
						}while((a < 0) || (a > 7));
						do{
							printf("Coluna: ");						//digitar a coluna de 0 á 7
							scanf("%d", &c);
						}while((c < 0) || (c > 7));
						printf("\a");
					
						if(inimigo[a][c] == 1){						//Acerto Porta Avições
							tabuleiro[a][c] = 'X';
							cont = cont + 5;						
						}
						if(inimigo[a][c] == 2){						//Acerto Fragata
							tabuleiro[a][c] = 'X';
							cont = cont + 10;						
						}
						if(inimigo[a][c] == 3){						//Acerto submarino
							tabuleiro[a][c] = 'X';
							cont = cont + 25;						
						}
						if(inimigo[a][c] == 0){						//se acertar na água você 
							tabuleiro[a][c] = '*';
							cont = cont + 0;						
						}
						printf("\t0 \t1 \t2 \t3 \t4 \t5 \t6 \t7 \n");
						for(a = 0; a < 8; a++){
							printf("\n%d", a);
							for(c = 0; c < 8; c++)
							{
								printf("\t%c", tabuleiro[a][c]);
							}
							printf("\n");
						}
						i++;
						tr = 8 - i;
						printf("\n%d Tentativas restantes.\n", tr);
						printf("Voce obteve %d pontos\n\n", cont);
					}while(i < 8);
					i = 0;
					printf("Fim de Jogo\n");
					printf("0 - Sair\n1 - Jogar novamente\n");
					printf("Digite: ");
					scanf("%d", &ops);
					if(ops != 0){
						printf("\nEmbarcacoes:1 - Fragata   //   2 - Porta Avioes   //   3 - Submarino\n");
						printf("\t0 \t1 \t2 \t3 \t4 \t5 \t6 \t7 \n");
					}
				}while(ops != 0);
				
			break;
			case 2:
			//Exibi tipo de partida selecionada
			printf("\n--------------------------------- Selecionado ----------------------------------\n");
			printf("------------------------------ Player vs Player!--------------------------------");
			
			//Guarda nome dos jogadores
			printf("\nNome do Player: ");
			scanf("%s", &nome[10]);
			printf("Nome do Player: ");
			scanf("%s", &nome2[10]);
			
			d = 3;
			p = 1;
			do{
				do{
				
				printf("\n---------------------- Player %d esconda suas embarcações -----------------------\n", p);
				printf("Escolha a linha e coluda da ponta esquerda dos barcos respectivamente.\n");
				
				for(a = 0; a < 8; a++){
					for(c = 0; c < 8; c++){
						inimigo[a][c] = 0;
					}
				}
				
				printf("\nPorta Aviões = 3 posições\n");
				do{
					printf("Linha: ");							//digitar a linha de 0 á 7
					scanf("%d", &a);
				}while((a < 0) || (a > 7));
				
				control = 0;
				do{
					printf("Coluna: ");							//digitar a coluna de 0 á 7							
					scanf("%d", &c);
					if((inimigo[a][c] == 0) && (c <= 5)){		//Verificar possibilidade de alocação de barco
						inimigo[a][c] = 2;
						inimigo[a][c + 1] = 2;
						inimigo[a][c + 2] = 2;
						control = 1;							//Cotrole se Barco poder ser alocado
					}else{
						printf("Impossível alocar o barco nas cordenadas indicadas.\n");
					}
				}while(control == 0);
			
				
				printf("\nFragata = 2 posições\n");
				do{
					printf("Linha: ");							//digitar a linha de 0 á 7
					scanf("%d", &a);
				}while((a < 0) || (a > 7));
				
				control = 0;
				do{
					printf("Coluna: ");							//digitar a coluna de 0 á 7							
					scanf("%d", &c);
					if((inimigo[a][c] == 0) && (inimigo[a][c + 1] == 0) && (c <= 6)){
						inimigo[a][c] = 1;
						inimigo[a][c + 1] = 1;
						control = 1;
					}else{
						printf("Impossível alocar o barco nas cordenadas indicadas.\n");
					}
				}while(control == 0);
				
				
				printf("\nSubmarino = 1 posições\n");
				do{
					printf("Linha: ");//digitar a linha de 0 á 7
					scanf("%d", &a);
				}while((a < 0) || (a > 7));
				
				control = 0;
				do{
					printf("Coluna: ");//digitar a coluna de 0 á 7							
					scanf("%d", &c);
					if((inimigo[a][c] == 0) && (c <= 7)){
						inimigo[a][c] = 3;
						control = 1;
					}else{
						printf("Impossível alocar o barco nas cordenadas indicadas.\n");
					}
				}while(control == 0);
				
				
				d--;				//Contador para Players que deve atirar
				
				printf("\n\n\n------------------------------ Tiros ------------------------------\n");
				printf("\nEmbarcacoes:1 - Fragata   //   2 - Porta Avioes   //   3 - Submarino\n");
				printf("Tiros Player %d", d);
				printf("\n\n\n\t0 \t1 \t2 \t3 \t4 \t5 \t6 \t7 \n");
				
				
				for(a = 0; a < 8; a++){
					printf("\n%d", a);
					for(c = 0; c < 8; c++){
						tabuleiro[a][c] = '~';
						printf("\t%c", tabuleiro[a][c]);
					}
					printf("\n");
				}
				
				i = 0;
				do{
					do{
						printf("Linha: ");			//digitar a linha de 0 á 7
						scanf("%d", &a);
					}while((a < 0) || (a > 7));
					do{
						printf("Coluna: ");			//digitar a coluna de 0 á 7
							scanf("%d", &c);
					}while((c < 0) || (c > 7));
					printf("\a");
					
					if(inimigo[a][c] == 1){			//Teste para acerto porta navios
						tabuleiro[a][c] = 'X';
						cont = cont + 5;
					}
					if(inimigo[a][c] == 2){			//Teste para acerto Fragata
						tabuleiro[a][c] = 'X';
						cont = cont + 10;
					}
					if(inimigo[a][c] == 3){			//Teste para acerto Submarino
						tabuleiro[a][c] = 'X';
						cont = cont + 25;
					}
					if(inimigo[a][c] == 0){			//Teste para acerto na água
						tabuleiro[a][c] = '*';
						cont = cont + 0;
					}
					if(cont == 65){					//Se acertar todos os Barcos terminar tiros
						printf("Parabéns você destruiu todos as Embarcações!");
						i = 7;
					}
					
					printf("\t0 \t1 \t2 \t3 \t4 \t5 \t6 \t7 \n");
					for(a = 0; a < 8; a++){			//Impressão numeros de orientação
						printf("\n%d", a);
						for(c = 0; c < 8; c++){
							printf("\t%c", tabuleiro[a][c]);
						}	
						printf("\n");
					}
					i++;
					pontos[p] = cont; 				//Guardar pontuação de jogadores
					printf("\nVoce obteve %d pontos\n", pontos[p]);
					
					tr = 8 - i;						//Aponta quantidade restante de tentativas
					printf("\n%d Tentativas restantes.\n", tr);
				}while(i < 8);
				cont = 0; 
				p++;
			}while(p <= 2);
			
			//Comparação de pontos entre jogadores e apontamento de vencedor da partida
			if(pontos[2] == pontos[1]){
				printf("\n-------------------------- Empate entre os jogadores! --------------------------");
				printf("\n---------------------------- Player 2 com %d pontos -----------------------------", pontos[2]);
				printf("\n---------------------------- Player 1 com %d pontos -----------------------------", pontos[1]);
			}
			if(pontos[1] > pontos[2]){
				printf("\n----------------------- Vencedor Player 1 com %d pontos ------------------------", pontos[1]);
				printf("\n----------------------- Perdedor Player 2 com %d pontos ------------------------", pontos[2]);
			}
			if(pontos[2] > pontos[1]){
				printf("\n----------------------- Vencedor Player 2 com %d pontos ------------------------", pontos[2]);
				printf("\n----------------------- VEnce Player 1 com %d pontos ------------------------", pontos[1]);
			}
			
			//Menu para Jogar novamente e Sair
			printf("\n\n0 - Sair\n1 - Revanche\n");
			printf("Digite: ");
			scanf("%d", &ops);
			
			d = 3;					//Se escolher revanche
			p = 1;					//Se escolher revanche
			
		}while(ops != 0);
		
		break;
		}
	}while(ops != 0);
return 0;
}
