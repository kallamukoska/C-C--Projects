/*
 * tekstualni_nizi.c
 *
 *  Created on: 27.12.2021
 *      Author: User
 */
/*
// PRVA.
// da se otstranat praznite mesta od krajot na tekstualnata niza.
// *ptr -> samata tekstualna niza
#include<stdio.h>
#include <ctype.h>

#define MAX 100

int strlen (const char *str){
	int n;
	for(n=0; *str!= '\0'; str++){
		n++;
	}
	return n;
}

void change( char *str){
	int i;
	i=strlen(str);

	for(i--;i>=0 && isspace(str[i]); i--){

	}
	str[i+1]='\0';

}

int main(){
	char s[MAX],ch; // ch kje ni broi se dodeka ne stasame do NULL
	int i=0;

	while((i < MAX-1 ) && ((ch=getchar())!='\n')){ // nizata zavrsuva so nov red
		s[i++]=ch;
	}
	// ako rabotime so while mora da go napisime null terminatorot
	s[i]='\0'; // znaeme koja e sodrzinata na nizata, kolkava e dolzinata

	printf("Vnesenata niza e %s\n",s);
	fflush(stdout);

	change(s);

	printf("Promenetata niza e : %s\n",s);
	fflush(stdout);

	return 0;
}*/


/*
 * return_type name(type_1 parametar_1,....){
 * }
 *
 * return_type n;
 * type_1; type_2 pt2;
 * n=name(p1,...);
 */
// int islower(int c); vrakja 1 ako e mala
//int isalnum(int c);
// int isdigit(int c);-> DALI E CIFRA 0,1,2,3,4,5,6,7,8,9
//digitdigitdigit digitdigit digit

// int tolower(int c) MALIOT KARAKTER KJE GO NAPRAVI GOLEM
// int toupper


// PROGRAMA: dali nizata znaci e PALINDROM. pred proverkata da se isfrla SITE prazni mesta. nema razlika megju mali i golemi bukvi.

// VTORA.
/*
#include<stdio.h>
#include<string.h>
#include <ctype.h>

#define MAX 100
// SITE GOLEMI BUKVI KJE GI NAPRAVI MALI.
void change( char *str){ // test Ab R \0
	char *a=str, *b=str; // bilo koi promeni da se napravat vo a ili b se pravat vo str ( negovata adresa)

	while(*a){ // se dodeka ne sme do null pointerot
		if(isalpha(*a)){
			if(isupper(*a)){
				*b=tolower(*a);
			}else {
				*b=*a; // ako ne postoi golema bukva ne se pravi promena.
			}
			b++; // b e vnatre bidekji stoi na praznite mesta

		}
		a++;
	}
	*b='\0';
}

int palindrom ( char *str){
	int i,len;
	int p=1; // stanuva zbro za palindrom
	change(str); // PRVO JA PROMENUVAME STR, POTOA BROIME DOLZINA
	// na promenetata sodrzina, bidejkji taa e sodrzinata na palindromot, ili na taa sto treba da ja razgleduvame.

	len=strlen(str);

	// ab ba    ab  x  ba
	for(i=0;i<len/2;i++){
		if(*(str+i)!=*(str+len-1-i)){ // elementot na ita pozicija od pocetok i elementot na ita pozicija od krajot.
			p=0;
		}
	}

	return p;
}

int main(){

	char s[MAX];

	printf("Vnesete string:\n");
	fflush(stdout);
	gets(s); // ni vcituva cel string -> go pravi istoto sto go pravese while ciklusot -> sega null terminatorot se vnesuva sam


	if(palindrom(s)){
		printf("Da, %s e palindrom.\n",s);
	}else{
		printf("Ne, %s ne e palindrom.\n",s);
	}


	return 0;
}*/


