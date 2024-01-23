#include <stdio.h>

int main(void) {
	float celsius, farenheit;

	scanf("%f", &farenheit);

	//Converte a temperatura
	//C = (°F − 32) ÷ 1, 8
	celsius = ((farenheit - 32) / 1.8);

	printf("%0.2f\n", celsius);

  return 0;
}