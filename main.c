/*
 * traccia esame
 * spicoli piersilvio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100 //dimensione costante per array di record

//dato strutturato
typedef struct{
	int id_citta; //50 dimensione array di char (50 caratteri)
	char nome_citta[50];
	int id_zona;
	char nome_zona[50];
	char indirizzo[50];
	int n_stanze;
	int n_servizi;
	char piano[50];
	float costo_loc;
	char stato[10];
}appartamenti;

//dichiarazione array di record (struttura dati)
appartamenti app[max];

//prototipi di funzione
void input(appartamenti[]);
void richiesta(appartamenti[]);

//variabili globali
int i, n_casa = 0;
int flag1 = 0, flag2 = 0;
int scelta = 0;

int main(){

	setbuf(stdout, NULL); //libera il bufffer

	input(app);
	richiesta(app);

	return 0;
}

void input(appartamenti arr[]){ //passagio del parametro formale

	do{
		printf("inserire il numero di case: ");
		scanf("%d", &n_casa);
	}while(n_casa <= 0);


	for(i = 0; i < n_casa; i++){ //inizializza i!

		arr[i].id_citta += 1;

		printf(":: nome citta: ");
		scanf("%s", arr[i].nome_citta);

		arr[i].id_zona += 1;

		printf(":: nome zona: ");
		scanf("%s", arr[i].nome_zona);
		printf(":: indirizzo: ");
		scanf("%s", arr[i].indirizzo);
		printf(":: numero di stanze: ");
		scanf("%d", &arr[i].n_stanze);
		printf(":: numero di servizi: ");
		scanf("%d", &arr[i].n_servizi);
		printf(":: piano (immettere il nome del piano): ");
		scanf("%s", arr[i].piano);
		printf(":: costo di locazione: ");
		scanf("%f", &arr[i].costo_loc);
		printf(":: stato di occupazione ('libero' o 'occupato'): ");
		scanf("%s", arr[i].stato);
		printf("\n");
	}
}

void richiesta(appartamenti arr[]){

	char nome_input[20];
	char citta_input[50];
	int n_minimo_stanze;
	float n_massimo_loc;

	void print(appartamenti[]);

	printf("\n inserire il nome del richiedente: \n");
	scanf("%s", nome_input);

	printf("inserire la citta di ricerca: \n");
    scanf("%s", citta_input);

	i = 0;

	do{
		if(strcmp(citta_input, arr[i].nome_citta) == 0){
			flag1 = 1;

			do{
				printf("inserire numero di stanze: \n");
				scanf("%d", &n_minimo_stanze);
				printf("inserire costo di locazione massimo: \n");
				scanf("%f", &n_massimo_loc);
			}while((n_minimo_stanze <= 0) && (n_massimo_loc <= 0));

			if((n_minimo_stanze == arr[i].n_stanze) && (n_massimo_loc == arr[i].costo_loc) && (strcmp(arr[i].stato, "libero") == 0)){
				flag2 = 1;
				print(arr);
			}

			i += 1;
		}
	}while(i < n_casa && flag1 == 1);

	if(flag1 == 0){
		printf("citta non presente!");

	}else if(flag2 == 0){
		printf("richiesta non soddisfatta!");

	}else{
		printf("richiesta soddisfatta!");
	}
}

void print(appartamenti arr[]){

	for(i = 0; i < n_casa; i++){ //inizializza i!

			printf(":: codice citta: %d", arr[i].id_citta);
			printf(":: nome citta: %s", arr[i].nome_citta);
			printf(":: codice zona: %d", arr[i].id_zona);
			printf(":: nome zona: %s", arr[i].nome_zona);
			printf(":: indirizzo: %s", arr[i].indirizzo);
			printf(":: numero di stanze: %d", arr[i].n_stanze);
			printf(":: numero di servizi: %d", arr[i].n_servizi);
			printf(":: piano: %s", arr[i].piano);
			printf(":: costo di locazione: %f", arr[i].costo_loc);
			printf(":: stato di occupazione: %s", arr[i].stato);
	}
}
