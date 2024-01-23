#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct playlist{
	char *playNome;
	int nrMusicas; //medido em segundos
}Playlist;

typedef struct musica{
	char *mNome;
	char *artista;
	int tempo; //medido em segundos
}Musica;

/*le uma linha de string
	*Retorna um pontiro para a linha lida
	*/
char *read_line(){

	char *line;
	//cria uma string para ler os caracters
	line = (char*)malloc(5000*sizeof(char));
	
	//le a linha
	scanf("%[^\n]", line);
	//printf("LINE: %s\n", line);

	int tam = strlen(line); //'\0' + o total de caracters na string
	line = (char*)realloc(line,tam+2*sizeof(char)); //realoca o tamanho
	line[tam+1] = '\0'; //garante que vai ter um \0 no final
		
	return line;
}

void nova_musica(Musica *music, int pos){
	scanf("%*c");
	music[pos].mNome = read_line(); //recebe o nome da musica
	scanf("%*c");
	music[pos].artista = read_line(); //recebe o nome do artista
	scanf("%d", &music[pos].tempo);

	printf("Musica %s de %s adicionada com sucesso.\n", music[pos].mNome, music[pos].artista);
}

void imprime_playlist(Playlist *play, Musica *music, Musica *musicaAtual){
	printf("---- Playlist: %s ----\n", play->playNome);
	printf("Total de musicas: %d\n", play->nrMusicas);

	for(int i=0; i<play->nrMusicas; ++i){
		
		printf("\n");//pula uma linha branca
		if(musicaAtual == &music[i]) printf("=== NOW PLAYING ===\n");
		printf("(%d). '%s'\n", (i+1), music[i].mNome);
		printf("Artista: %s\n", music[i].artista);
		printf("Duracao: %d segundos\n", music[i].tempo);
	}
	printf("\n");//pula uma linha branca
}

Musica *atualiza_musicaAtual(Musica *musicaAtual, Musica *music, int num){
	musicaAtual = &music[num]; //salva o enderoço da musica sendo tocada no momento
	return musicaAtual;
}

int main() {
  
	Playlist *play;
	Musica *music, *musicaAtual;

	play = malloc(1*sizeof(Playlist)); //apenas uma playlist é usada por vez
	music = (Musica*)malloc(15*sizeof(Musica));

	play->playNome = read_line(); //recebe o nome da playlist
	play->nrMusicas = 0; //inicializa a variavel

	int opt; //controla a opção a ser acessada
	scanf("%d", &opt);

	int musicaTocando = 0;

	while(opt < 5){
		switch(opt){
			case 1: //adiciona uma nova musica no final	
				if(play->nrMusicas < 15){
					play->nrMusicas++;
					nova_musica(music,play->nrMusicas-1);
					//caso seja a primeira musica adcionada marco como a musica tocando
					if(play->nrMusicas == 1) musicaAtual = atualiza_musicaAtual(musicaAtual, music, musicaTocando);
				
				}else printf("Playlist cheia!\n");
			break;

			case 2: //mostra as musicas na playlist
				imprime_playlist(play,music,musicaAtual);
			break;

			case 3: //avança para a proxima musica
				musicaTocando++;
				if(musicaTocando > play->nrMusicas-1) musicaTocando = 0;
				musicaAtual = atualiza_musicaAtual(musicaAtual,music,musicaTocando);
			break;

			case 4: //volta a musica
				musicaTocando--;
				if(musicaTocando < 0) musicaTocando = 14;
				musicaAtual = atualiza_musicaAtual(musicaAtual,music,musicaTocando);
			break;
		}

		scanf("%d", &opt);
	}

	//Libera memoria
	for(int i=0; i<play->nrMusicas; ++i){
		free(music[i].mNome);
		free(music[i].artista);
	}
	free(music);
	free(play[0].playNome);
	free(play);

  return 0;
}