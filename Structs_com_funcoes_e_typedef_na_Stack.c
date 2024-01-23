#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Conte�do: 
	- Structs_com_funcoes_e_typedef_na_Stack
*/

//o comando typedef permite dar um nome ou renomear um tipo de dado
//poderia fazer:
//typedef float real; assim, ao inves de utilizar o tipo de dado float poderia indicar real
//sintaxe:
//typedef <tipo> <apelido>;

typedef struct game{
	char titulo[100];
	char plataforma[20];
	unsigned short int ano;
	float preco;
} Game;

Game preencherFicha();
void preencherFichaReferencia(Game *jogo);
void imprimirFicha(Game jogo);

int main(){
	//struct na Stack
	Game jogo1 = preencherFicha();
	imprimirFicha(jogo1);
	
	Game jogo2;
	preencherFichaReferencia(&jogo2);
	imprimirFicha(jogo2);
	
	//criando um vetor de structs
	printf("*** Vetor de structs ***\n");
	Game jogos[10];
	strcpy(jogos[0].titulo, "FIFA");
	strcpy(jogos[1].titulo, "NBA");
	jogos[0].preco = 65.99;
	jogos[1].preco = 99.99;
	
	typedef int inteiro;
	inteiro i;
	for (i=0; i<10;i++)
		printf("Titulo: %s. R$ %.2f\n", jogos[i].titulo, jogos[i].preco);
		
	return 0;
}

Game preencherFicha(){
	Game jogo;
	strcpy(jogo.titulo, "Red Dead Redemption");
	strcpy(jogo.plataforma, "PS3");
	jogo.ano = 2010;
	jogo.preco = 50.0;
	return jogo;
}

void imprimirFicha(Game jogo){
	printf("*** Ficha do produto ***\n");
	printf("Titulo: %s\n", jogo.titulo);
	printf("Plataforma: %s\n", jogo.plataforma);
	printf("Ano de lancamento: %d\n", jogo.ano);
	printf("Preco: %f\n\n", jogo.preco);
}

void preencherFichaReferencia(Game *jogo){
	//o uso de setas � somente para acessar endere�os
	//strcpy((*jogo).titulo, "The last of us");
	strcpy(jogo->titulo, "The last of us");
	strcpy(jogo->plataforma, "PS3");
	jogo->ano = 2013;
	jogo->preco = 80.0;
}

//passagem por valor: jogo.titulo
//passagem por referencia: jogo->titulo (*jogo). � equivalente a jogo->

