/*
 * datoteki.c
 *
 *  Created on: 27.12.2021
 *      Author: User
 */
//PRVA.


/* za dadena tekstualna datoteka, chie ime se vnesuva kako argument od komandna linija.
kje gi najdeme site redovi koi IMAAT POVEKJE od 10 mali bukvi.

Vo vtora datoteka, chie ime se vnesuva kako argument od komandna linija,
kje gi zapise REDNITE BROEVI na pronajdenite redovi. Na kraj da se zapise i vkupniot broj na takvi redovi.

Programata treba da proveri dali korisnikot vnel vlezna i izlezna datoteka,
i dokolku nema vneseno validni datoteki treba da se ispecati poraka za greska.*/

#include<stdio.h>
#include <ctype.h>
#include<stdlib.h>
int main(int argc, char *argv[]){// mora da dademe nacin na citanje na argumentite od komandna linija
	// niza od 3 tekstualni nizi -> argv
	FILE *in_dat, *out_dat; //(brojot na argumeni+exe file-ot)
	char c;
	int red, mali,vkupno;

	if(argc!=3){
		printf("Imas greska vo vnesuvanjeto na datoteki. Treba da se vnesat dve: edna za citanje,vtora za zapsuvanje.\n");
		return -1;
	}

	if((in_dat=fopen(argv[1],"r"))== NULL){
		printf("Datoteka so ova ime ne postoi, vnesi druga validna.\n");
		return -1;
	}
	if((out_dat=fopen(argv[2],"w"))== NULL){
			printf("Vo ovaa papka nemam privilegii da kreiram file.\n");
			return -1;
		}

	// work
	red=1;
	mali=vkupno=0;
	while((c=fgetc(in_dat))!= EOF ){
		// dali e mala bukva
		if(isalpha(c)&&islower(c)){
			mali++;
		}
		// me interesira dali si nov red.
		if(c=='\n'){
			if(mali>=10){
				fprintf(out_dat,"red %d\n",red); // pecati vo file-ot
				vkupno++;
			}
			mali=0; // vo sledniot red pocnuvame da broime pak od 0 mali bukvi
			red++; // odime na sleden red.
		}
	}
	fprintf(out_dat,"Vkupno takvi redovi imase %d.\n",vkupno);

	fclose(out_dat);
	fclose(in_dat);

	return 0;
}
// gcc ime.c */


