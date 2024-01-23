#include <stdio.h>

int main(void) {
  int numero,  ba = 0 , dum = 0, tss = 0, multiplo;

	scanf("%d", &numero);

	//verifica o multiplo
	//e marca qual o multiplo
	if(numero % 11 == 0)
		ba = 1;
	if(numero % 13 == 0)
		dum = 1;
  if(numero % 19 == 0)
		tss = 1;
	
	multiplo = (ba + dum + tss); //conta o total de multiplos que o numero tem

	if(multiplo == 0){ //Caso  o numero nao seja multiplo de 11 13 e 19
		printf("%d", numero);
	}else{

		if(ba == 1) 			//caso o numero seja multiplo de 11 printa ba
			printf("Ba");
		
		if(multiplo == 1) //se ele for multiplo de apenas 1 printa ba no inicio
			printf("Ba");

		if(dum == 1)			//caso o numero seja multiplo de 13 printa dum
			printf("Dum");
		
		if(multiplo == 2) //se ele for multiplo de 2 printa dum no meio
			printf("Dum");

		if(tss == 1)			//caso o numero seja multiplo de 19 printa Tss
			printf("Tss");
		
		if(multiplo == 3)	//se for multiplo dos 3 printa tss no final
			printf("Tss");
	}

	printf("\n");

	
  return 0;
}