#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Conte�do: 
	- Structs com fun�es na Heap
*/

typedef struct game{
	char titulo[100];
	char plataforma[20];
	unsigned short int ano;
	float preco;
} Game;

void preencherFicha(Game *jogo, char titulo[], char plataforma[], int ano, float preco){
	strcpy(jogo->titulo, titulo);
	strcpy(jogo->plataforma, plataforma);
	jogo->ano = ano;
	jogo->preco = preco;
}

void imprimirFicha(Game jogo){
	printf("*** Ficha do produto ***\n");
	printf("Titulo: %s\n", jogo.titulo);
	printf("Plataforma: %s\n", jogo.plataforma);
	printf("Ano de lancamento: %d\n", jogo.ano);
	printf("Preco: %f\n\n", jogo.preco);
}

int main(){
	//struct na Heap
	Game *jogos;
	
	jogos = malloc(1*sizeof(Game));
	preencherFicha(&jogos[0], "Red Dead Redemption", "PS3", 2010, 50.0);
	imprimirFicha(jogos[0]);
	
	jogos = realloc(jogos, 2*sizeof(Game));
	preencherFicha(&jogos[1],"The last of us", "PS3", 2013, 80.0);
	imprimirFicha(jogos[1]);
	
	free(jogos);
	
	return 0;
}

