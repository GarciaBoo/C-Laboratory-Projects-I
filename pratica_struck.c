#include <stdio.h>
#include <stdlib.h>

int main(){
	//jogos de videogame, poss�veis atributos:
	//titulo
	//plataforma
	//ano de lan�amento
	//pre�o
	
	//forma mais simples de armazenar, declarando vari�veis escalares na Stack
	//consigo manipular informa�es de apenas um jogo
	//posso fazer atribui�es, leituras e escritas diretamente nas vari�veis
	char titulo[100];
	char plataforma[20];
	unsigned short int ano;
	float preco;
	
	//manipula�o de muitos jogos na Stack, uma quantidade finita e pr�-definida de jogos
	//posso fazer atribui�es, leituras e escritas diretamente nas vari�veis de acordo com as posi�es
	char titulos[20][100];
	char plataformas[20][20];
	unsigned short int anos[20];
	float precos[20];
	
	//manipula�o de muitos jogos na Heap, uma quantidade finita e n�o pr�-definida de jogos
	//posso fazer atribui�es, leituras e escritas, observando os endere�os de mem�ria
	//devo utilizar malloc(), calloc() ou realloc(), dependendo do cen�rio
	char** titulosHeap;
	char** plataformasHeap;
	unsigned short int* anosHeap;
	float* precosHeap;
	
	//alocando espa�o para o primeiro jogo
	titulosHeap = malloc(1*sizeof(char*));
	titulosHeap[0] = malloc(100*sizeof(char));
	//... outros atributos
	anosHeap = malloc(1*sizeof(unsigned short int));
	
	//alocando espa�o para o segundo jogo
	titulosHeap = realloc(titulosHeap, 2*sizeof(char*));
	titulosHeap[1] = malloc(100*sizeof(char));
	//... outros atributos
	anosHeap = realloc(2*sizeof(unsigned short int));
	
	//independente da forma que escolhemos para armazenar estes valores,
	//a lista de atributos pode ser longa
	//assim, se temos fun�es e rotinas, sempre teremos uma lista grande de parametros
	//tendo o risco de esquecer algum, passar na ordem errada, etc...
	//se houver a inclus�o ou remo�o de atributos, todas as fun�es devem ser alteradas
	
	//uma alternativa � utilizar uma vari�vel que agrupe tudo em uma �nica estrutura.
	//structs n�o s�o vari�veis, mas um tipo de dado
	struct game{
		char titulo[100];
		char plataforma[20];
		unsigned short int ano;
		float preco;
	};
	
	//declarando a vari�vel primeiroJogo do tipo de dado game
	struct game primeiroJogo;
	
	//assim, ao inv�s de passar cada atributo individualmente, passamos a struct game como parametro,
	//acessando os atributos internos.
	
	return 0;
}
