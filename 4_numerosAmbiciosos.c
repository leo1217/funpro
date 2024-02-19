#include<stdio.h>

void impresionNumerosPoderosos(int rangoInferior, int rangoSuperior, int *dir_cantPrimos, int *dir_cantCompuestos);
int hallarSiEsAmbicioso(int rangoInferior);
int hallarSumaDivPropios(int rangoInferior);
int hallarSiEsPerfecto(int sumaDivPropios);
int hallarSumaDig(int rangoInferior);
void hallarSiEsPrimoCompuesto(int sumaDig, int *dir_esPrimo, int *dir_esCompuesto);

int main(){
	
	int rangoInferior, rangoSuperior, cantPrimos, cantCompuestos;
	
	printf("Ingrese un rango. El primer numero debe ser mayor que 0:");
	scanf("%d %d", &rangoInferior, &rangoSuperior);
	if(rangoInferior>0 && rangoInferior<rangoSuperior){
		printf("En el rango [%d,%d] se encontraron los siguientes numeros ambiciosos:", rangoInferior, rangoSuperior);
		impresionNumerosPoderosos(rangoInferior, rangoSuperior, &cantPrimos, &cantCompuestos);
		printf("En total hay\n");
		printf(" %d numeros cuya suma de digitos es un numero primo\n", cantPrimos);
		printf(" %d numeros cuya suma de digitos es un numero compuesto\n", cantCompuestos);
	}
	else{
		printf("Rango incorrecto");
	}
	
	
	
	return 0;
}

void impresionNumerosPoderosos(int rangoInferior, int rangoSuperior, int *dir_cantPrimos, int *dir_cantCompuestos){
	int esAmbicioso, esPrimo, esCompuesto, sumaDig;
	*dir_cantCompuestos=0;
	*dir_cantPrimos=0;
	
	while(rangoInferior<=rangoSuperior){
		esAmbicioso=hallarSiEsAmbicioso(rangoInferior);
		if(esAmbicioso==1){
			printf("%d", rangoInferior);	
			sumaDig=hallarSumaDig(rangoInferior);
			hallarSiEsPrimoCompuesto(sumaDig, &esPrimo, &esCompuesto);
			if(esPrimo==1){
				(*dir_cantPrimos)++;
				printf("la suma de sus digitos es un numero primo\n");
			}else{
				if(esCompuesto==1){
					(*dir_cantCompuestos)++;
					printf("la suma de sus digitos es un numero compuesto\n");
				}
			}
		}
		
		rangoInferior++;
	}
}

int hallarSiEsAmbicioso(int rangoInferior){
	int i, dig, sumaDivPropios, centinela, esPerfecto;
	centinela=1;
	while(centinela){
		sumaDivPropios=hallarSumaDivPropios(rangoInferior);
		esPerfecto=hallarSiEsPerfecto(sumaDivPropios);
		if(esPerfecto==1){
			return 1;
			centinela=0;
			break;
		}
		else{
			rangoInferior=sumaDivPropios;
		}
		if(sumaDivPropios==1){
			centinela=0;
			return 0;
		}
	}
}

int hallarSumaDivPropios(int rangoInferior){
	int i, suma, dig, resto;
	i=1;
	suma=0;
	while(i<rangoInferior){					/*hallo la suma de divisores propios*/
		resto=rangoInferior%i;
		if(resto==0){
			suma=suma+i;
		}
			
		i++;
	}
	return suma;
}

int hallarSiEsPerfecto(int sumaDivPropios){
	int suma, i, resto;
	suma=0;
	i=1;
	while(i<=sumaDivPropios){
		resto=sumaDivPropios%i;
		if(resto==0){
			suma=suma+i;
		}
		
		i++;
	}	
	return (suma==sumaDivPropios);
}

int hallarSumaDig(int rangoInferior){
	int centinela, suma, dig;
	centinela=1;
	suma=0;
	while(centinela){
		dig=rangoInferior%10;
		suma=suma+dig;
		rangoInferior=rangoInferior/10;
		if(rangoInferior==0){
			centinela=0;
		}
	}
	return suma;
}

void hallarSiEsPrimoCompuesto(int sumaDig, int *dir_esPrimo, int *dir_esCompuesto){
	int cantDiv, i, resto;
	cantDiv=0;
	i=1;
	*dir_esCompuesto=0;
	*dir_esPrimo=0;
	while(i<=sumaDig){
		resto=sumaDig%i;
		if(resto==0){
			cantDiv++;
		}	
		
		i++;
	}
	if(cantDiv==2){
		*dir_esPrimo=1;
	}
	else{
		*dir_esCompuesto=1;
	}
}





