#include <stdio.h>

int main(void) {
  
	int limite = 80;
	float velocidade, multa;

	scanf("%f", &velocidade);

	//compara com o limite
	if(velocidade > limite){
		multa = 2 * (velocidade - limite); //calcula a multa apenas se o limite for excedido
		printf("Limite de velocidade excedido! Multado no valor de R$%0.2f!\n", multa);
	}else{
		printf("Velocidade dentro do limite permitido.\n");
	}

  return 0;
}