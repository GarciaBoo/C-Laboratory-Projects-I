#include <stdio.h>
#include <stdlib.h>

/*• Uma sequencia de chars separados por espaco, que representa os caracteres em ordem para cada tecla
de acordo com configura¸c˜ao do teclado comprado por Bento;
• Um inteiro, representando a quantidade de caracteres da mensagem enviada por Bento;
• Uma sequˆencia de inteiros separados por espa¸co, que representa a mensagem codificada recebida por
Schr¨odinger.*/

int main(void) {
  char teclado[50], buffer;
	int mensagemTam, *codificada;

	for(int i=0; i<49; ++i){
		scanf("%c", &teclado[i]);
		scanf("%c", &buffer);	//tira o espaco
	}
	
	scanf("%d", &mensagemTam);

	//aloca memoria
	codificada =(int *)malloc(mensagemTam*(sizeof(int)));

	for(int i=0; i<mensagemTam; ++i)
		scanf("%d", &codificada[i]);

	//usa a posicao dada na mensagem para printar o exato cararcter do teclado
	for(int i=0; i<mensagemTam; ++i){
		if(teclado[codificada[i]] ==  '_')
			printf(" ");
		else if(teclado[codificada[i]] == 'E')
			printf("\n");
		else
			printf("%c", teclado[codificada[i]]);
	}

	//libera memoria
	free(codificada);
  return 0;
}