#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Conte�do: 
	- introdu�o a structs
*/

struct game{
	char titulo[100];
	char plataforma[20];
	unsigned short int ano;
	float preco;
};

void preencheFicha(struct game jogo){
	//jogo (endere�o da struct)
	//(*jogo).x (conte�do do atributo x dentro de struct game)
	//&((*jogo).x) (endere�o do atributo x dentro de struct game)
	//por exemplo, scanf("%f", &((*jogo).preco))

	strcpy((*jogo).titulo, "The last of us");
	strcpy((*jogo).plataforma, "PS3");
	(*jogo).ano = 2013;
	(*jogo).preco = 80.0;
}

void imprimeFicha(struct game jogo){
	printf("*** Ficha do produto ***\n");
	printf("Titulo: %s\n", jogo.titulo);
	printf("Plataforma: %s\n", jogo.plataforma);
	printf("Ano de lancamento: %d\n", jogo.ano);
	printf("Preco: %f\n\n", jogo.preco);
}

int main(){
	//mem�ria Stack "convencional":
	//char titulo[100];
	//strcpy(titulo, "Red Dead Redemption");
	//printf("Titulo: %s\n", titulo);

	//declarando uma vari�vel (jogo1) do tipo struct game
	struct game jogo1;
	
	//atribuindo valores para os atributos
	strcpy(jogo1.titulo, "Red Dead Redemption");
	strcpy(jogo1.plataforma, "PS3");
	jogo1.ano = 2010;
	jogo1.preco = 50.0;
	
	printf("*** Ficha do produto ***\n");
	printf("Titulo: %s\n", jogo1.titulo);
	printf("Plataforma: %s\n", jogo1.plataforma);
	printf("Ano de lancamento: %d\n", jogo1.ano);
	printf("Preco: %f\n\n", jogo1.preco);
	
	//para utilizar fun�es, a struct deve estar declarada globalmente
	struct game jogo2;
	preencheFicha(&jogo2);
	imprimeFicha(jogo2);
	
	return 0;
}
