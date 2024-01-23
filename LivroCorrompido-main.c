#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declara a funcao
char *read_line();

int main(){

	int nLinhas;
	scanf("%d", &nLinhas); //total de linhas a ser lido;

	if(nLinhas>0)//veridica se o total de linhas é maior que zero
	{ 
		char **linhas;
		//aloca memoria de acordo com o total de linhas a ser lida
		for(int i=0; i<nLinhas; ++i)
			linhas = (char**)malloc(nLinhas*sizeof(char*));

		
		//chama a funcao de ler linha e guarda essa linha na matriz
		for(int i=0; i<nLinhas; ++i){
			scanf("%*c"); //tira o \n
			linhas[i] = read_line();
		}
		
		int vIndices = 0; //indice das linhas não corrompidas
		scanf("%d", &vIndices);

		if(vIndices > 0 && vIndices <= nLinhas) //verifica se as condicoes de indice estão corretas
		{	
			//aloca a memoria no vetor
			int *indices;
		  indices = (int*)malloc(vIndices*sizeof(int));
	
			//recebe os indeces
			for(int i=0; i<vIndices; ++i){
				scanf("%d", &indices[i]);
				
			}
			//imprime a linha de acordo com o valor esperado
			for(int i=0; i<vIndices; ++i){
				printf("%s\n", linhas[indices[i]]);
			}

			//libera memoria
			free(indices);
		}
		
		//libera a memoria
		for(int i=0; i<nLinhas; ++i)
			free(linhas[i]);
		free(linhas);
	}

  return 0;
}

char *read_line(){
	char *line;

	//cria uma string para ler os caracters
	line = (char*)malloc(5000*sizeof(char));
	
	//le a linha
	scanf("%[^\n]", line);

	int tam = 1;
	tam += strlen(line); //'\0' + o total de caracters na string
	line = (char*)realloc(line,tam*sizeof(char)); //realoca o tamanho
	line[tam] = '\0'; //garante que vai ter um \0 no final

	return line;
}