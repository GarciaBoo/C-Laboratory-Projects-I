#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int semente =-1 , linhaA, linhaB, colunaA, colunaB, **matrizA, **matrizB, **matrizAB;

	scanf("%d %d", &linhaA, &colunaA);
	scanf("%d %d", &linhaB, &colunaB);

	scanf ("%d", &semente);

	//aloco as linhas da matriz
	matrizA = (int**)malloc(linhaA*sizeof(int*));
	matrizB = (int**)malloc(linhaB*sizeof(int*));
	matrizAB = (int**)calloc(linhaA,sizeof(int*)); //utilizo calloc para inicializar os elementos da matriz com 0

	//aloco as colunas
	for(int i=0; i<linhaA; ++i)
		matrizA[i] = (int*)malloc(colunaA*sizeof(int));

	for(int i=0; i<linhaB; ++i)
		matrizB[i] = (int*)malloc(colunaB*sizeof(int));

	for(int i=0; i<linhaA; ++i)
		matrizAB[i] = (int*)calloc(colunaB,sizeof(int));

	// Definicao da semente de aleatoriedade de acordo com o pdf
	srand(semente);

	// Gera um numero aleatorio e armazena na posicao (i,j) da matriz.
	for(int i=0; i<linhaA; ++i){
		for(int j=0; j<colunaA; ++j){
			matrizA[i][j] = rand () %50 - 25;
		}
	}
	for(int i=0; i<linhaB; ++i){
		for(int j=0; j<colunaB; ++j){
			matrizB[i][j] = rand () %50 - 25;
		}
	}

	//numero de colunas de A deve ser igual ao numero de linhas de B
	if(colunaA == linhaB && semente != -1){

		for(int i=0; i<linhaA; ++i){
			for(int j=0; j<colunaB; ++j){
				for(int k=0; k<colunaA; ++k){
					//para cada elemento da matrizAB somo a multiplicacao dos elementos da linha A com os elementos da coluna B
					matrizAB[i][j] += (matrizA[i][k]*matrizB[k][j]);
				}
			}
		}

		//imprimo a matriz AB
		for(int i=0; i<linhaA; ++i){
			printf("Linha %d: ",i);
			for(int j=0; j<colunaB; ++j){
				printf("%d ",  matrizAB[i][j]);
			}
			printf("\n");
		}

	}else{
		printf("Valores invalidos para a multiplicacao.");
	}

	//libero a memoria
	for(int i=0; i<linhaA; ++i)
		free(matrizA[i]);

	for(int i=0; i<linhaB; ++i)
		free(matrizB[i]);

	for(int i=0; i<linhaA; ++i)
		free(matrizAB[i]);

	free(matrizA);
	free(matrizB);
	free(matrizAB);

  return 0;
}

