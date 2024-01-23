#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int Npontos, *pontosX, *pontosY, *valoresI;

	scanf("%d", &Npontos);
	
	//aloco as colunas que sera o espaco para o X e Y respectivamente
	pontosX = (int*)malloc(Npontos*sizeof(int));
	pontosY = (int*)malloc(Npontos*sizeof(int));
	valoresI = (int*)malloc(Npontos*sizeof(int)); //variavel que guarda os valores de i

	for(int i=0; i<Npontos; ++i){
		scanf("%d %d %d", &pontosX[i], &pontosY[i], &valoresI[i]);
	}

	

	free(pontosX);
	free(pontosY);
	free(valoresI);

  return 0;
}