#include <stdio.h>

int main(void) {

	int altura;		//valor n corespondente a altura no triangulo
	char caracter; //valores que irao dar forma ao triangulo (pate da tabela ASCII)

	scanf("%d", &altura); 	//0  <altura <= 25
	scanf("%c", &caracter); //tira o buffer do enter na entrada do teclado
	scanf("%c", &caracter);

	if(altura <= 0 || altura > 25)
		printf("Altura invalida");
	else
	{
		for(int i=0; i<altura; i++){ //controla a altura
			
			for(int j=1; j<altura-i; j++){ //controla a linha
				printf(" ");
			}

			for(int j=0; j<i+(i+1); j++){ //controla a linha
				printf("%c", caracter);
			}
			printf("\n");
		}
	}

  return 0;
}