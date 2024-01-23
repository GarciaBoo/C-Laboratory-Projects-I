#include <stdio.h>
#include <stdlib.h>

char **cria_matriz_caracters(int linha, int coluna);
char **libera_matriz_caracters(char **matriz, int linha);
char **le_matriz(char **matriz, int linha, int coluna);
void mostra_matriz(char **matriz, int linha, int coluna);
char **game_of_file(char **matriz, int linha, int coluna, int geracao, int verifica);

int main() {

	int m, n; //dados da matriz
	scanf("%d %d", &m, &n);

	int p; //geracoes
	scanf("%d", &p);

	char v; //caracter que define o modelo de vizinhança
	scanf("%*c");
	scanf("%c", &v);

	if(v == 'M' || v == 'N'){ //verifica se os valores são validos
		if(m <= 0 || n <= 0 || p < 0){
			printf("Dados de entrada apresentam erro.\n");
		}else
		{
			char **matriz;
			matriz = cria_matriz_caracters(m,n);
			matriz = le_matriz(matriz,m,n);

			if(v == 'M'){
				matriz = game_of_file(matriz, m, n, p,0);
			}
			if(v == 'N'){
				matriz = game_of_file(matriz, m, n, p,1);
			}

			mostra_matriz(matriz, m, n);
			matriz = libera_matriz_caracters(matriz,m);
		}
	}else{
		printf("Dados de entrada apresentam erro.\n");
	}
	
  return 0;
}

//realiza a leitura de uma matriz de caractes
char **le_matriz(char **matriz, int linha, int coluna){
	scanf("%*c");
	for(int i=0; i<linha; ++i){
		for(int j=0; j<coluna; ++j){
			scanf("%c", &matriz[i][j]);
		}
		scanf("%*c"); //tira o buffer ou lixo
	}
	return matriz;
}

//imprime a matriz
void mostra_matriz(char **matriz, int linha, int coluna){
	for(int i=0; i<linha; ++i){
		for(int j=0; j<coluna; ++j){
			printf("%c",matriz[i][j]);
		}
		printf("\n");
	}
}

//aloca memoria para uma matriz de caracters e retorna essa matriz
char **cria_matriz_caracters(int linha, int coluna){
	char **matriz;
	matriz = (char**)malloc(linha*sizeof(char*));
	//aloco as colunas
	for(int i=0; i<linha; ++i)
		matriz[i] = (char*)malloc(coluna*sizeof(char));
	return matriz;
}

//libera memoria
char **libera_matriz_caracters(char **matriz, int linha){
	for(int i=0; i<linha; ++i)
		free(matriz[i]);
	free(matriz);
	return matriz;
}

int moore_conta_vizinho(char **matriz, int linha, int coluna, int linha1, int coluna1){
	int vizinho = 0, l1, c1;
	
	//considera a menor posicao do vizinho mais distante do ponto passado
	l1 = linha-1;
	c1 = coluna-1;
	//garante que não vamos acessar um ponto invalido na matriz
	if(0 > l1)
		l1 = 0;
	if(0 > c1)
		c1 = 0;
	
	//considera a maior posicao do vizinho mais distante do ponto passado
	//soma 2 ao invés de um pois procuraremos até um limite menor que 2
	linha = linha + 2;
	coluna = coluna + 2;

	//garante que não vamos acessar um ponto invalido na matriz
	if(linha > linha1){
		linha = linha1;
	}
	if(coluna > coluna1){
		coluna = coluna1;
	}

	//contorna a 'celula' caso encontre um vizinho soma 
	for(int i = l1; i<linha; ++i){
		for(int j = c1 ; j<coluna; ++j){
			if(matriz[i][j] == 'x'){
				vizinho++;
			}
		}
	}

	return vizinho;
}

int vonNeuman_conta_vizinho(char **matriz, int l1, int c1, int linha, int coluna){
	int vizinho = 0, l, c;

	//considera a menor posicao do vizinho mais distante do ponto passado
	l = l1 - 2;
	if(0 > l)
		l = 0;

	c = c1 - 2;
	if(0 > c)
		c = 0;

	int limL, limC; //limL - limite da linha e limC - limite da coluna

	//considera a maior posicao do vizinho mais distante do ponto passado
	//novamente consideramos o valor maximo 1 a mais do procurado
	limL = l1 + 3;
	if(limL > linha)
		limL = linha;

	limC= c1 + 3;
	if(limC > coluna)
		limC = coluna;


	for(int i = l; i<limL; ++i){
		for(int j = c ; j<limC; ++j){
			//quando estivermos no raio da linha ou coluna
			//sera o território valido para se considerar um vizinho
			if(i == l1 || j == c1){
				if(matriz[i][j] == 'x'){
					vizinho++;
				}
			}
		}
	}
	return vizinho;
}

//copia a matriz para a matriz 2
char **copia_matriz(char **matriz2, char **matriz, int linha, int coluna){
	for(int i=0; i<linha; ++i){
		for(int j=0; j<coluna; ++j){
			matriz2[i][j] = matriz[i][j];
		}
	}
	return matriz2;
}

char **game_of_file(char **matriz, int linha, int coluna, int geracao, int verifica){
	int contVizinho = 0;
	
	char **matrizAux = cria_matriz_caracters(linha,coluna);
	matrizAux = copia_matriz(matrizAux,matriz,linha,coluna);

	while(geracao > 0){
		for(int i=0; i<linha; ++i)
		{
			for(int j=0; j<coluna; ++j)
			{	
				//0 para moore e 1 para Von Neuman
				if(verifica == 0)
					contVizinho = moore_conta_vizinho(matriz,i,j, linha, coluna);
				if(verifica == 1)
					contVizinho = vonNeuman_conta_vizinho(matriz,i,j, linha, coluna);
				
				//considerando o total de viznhos mudo as celulas de acordo com a especificacao
				if(matriz[i][j] == 'x'){ //celulas vivas
					//no caso de celulas vivas o contador considera tbm a celula inicial por isso tiramos 1
					contVizinho--;
					if(contVizinho < 2){ 
						//Qualquer celula viva com menos de dois vizinhos vivos morre de solidao.
						matrizAux[i][j] = '.';
					}else if(contVizinho > 3){
						//Qualquer celula viva com mais de tres vizinhos vivos morre de superpopulacao.
						matrizAux[i][j] = '.';
					}
				}else if(contVizinho == 3){ //celulas mortas
					//Qualquer celula morta com exatamente tres vizinhos vivos se torna uma celula viva (nasce).
					matrizAux[i][j] = 'x';
				}
			}
		}
		//atualizo a matriz original no final da "geração"
		matriz = copia_matriz(matriz,matrizAux,linha,coluna);
		geracao--;
	}
	
	matrizAux =	libera_matriz_caracters(matrizAux,linha);
	return matriz;
}