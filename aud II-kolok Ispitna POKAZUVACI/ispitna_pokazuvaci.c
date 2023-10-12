/*
 * k.c
 *
 *  Created on: 20.12.2021
 *      Author: User
 */
// ispitna zadaca POKAZUVACI
/* da se napise f-ja sto kje dobie niza od celi broevi.
 * funkcijata:
 * -vrakja 1 kako rezultat ako nizata e strogo rastecka
 * -vrakja 2 ako ne e strogo rastecka, pri sto nizata treba da se transtformira vo steogo rastecka (ako ne e)
 * ZABRANETO koristenje na sredni zagradi. []
 * -glavna programa za testiranje na rabotata na f-jata
 *
 * Transformacija se pravi na toj nacin:
 * 1.nizata se sortira vo rastecki redosled
 * 2.od sortiranata niza se otstranuvaat duplikati
 *
 * primeri:
 * 1.[ 1 2 3 5 7 9 ] -> strogo rastecka niza -> f treba da vrati 1
 * 2.[ 1 1 2 2 4 5 5 8 ]-> NE E STROGO RASTECKA: se transformira [ 1 2 4 5 8 ] -> f treba da vrati 2
 * 3.[ 2 3 1 7 6 ]-> [ 1 2 3 6 7 ]-> f treba da vrati 2 - ovde moze da se javat duplikati
 *
 */
void zamena(int *prv, int *vtor){
	int pom;
	pom=*prv;
	*prv=*vtor;
	*vtor=pom;
}


void sortiraj(int *niza,int n){ // ne davame pokazuvac za n , ni treba brojkata na n
	int i,j;
	for(i=0;i<n;i++){ // za sekoj element
		for(j=0;j<n-1;j++){ // za sekoj par
			if(*(niza+i) < *(niza+j)){
			zamena(niza+i,niza+j);
			}
		}
	}
}
void otrfli_duplikati(int *niza,int n, int *new_n){
	int i,j,pom;

	pom=0; // kolku elemenyti se duplikati
	for(i=0;i<n;i++){ // za sekoj element
		j=0;
		while((j<=pom) && (*(niza+i)!=*(niza+j))){
			j++;
			//printf("%d %d %d %d %d",i,*(niza+i),j,*(niza+j),pom);
		}
		if(j>pom){
			pom++;
			*(niza+pom)=*(niza+i);
			//printf("%d %d %d ", pom,*(niza+pom), *(niza+i));
		}
	}
	*new_n=pom+1; // kolku elementi imame vo novata niza+1.

}
int funkcija(int *niza,int *n){
	int i,vrati;

	vrati=1; // pretpostavuvame deka imame strogo rastecka
	for(i=0;i<*n-1;i++){ // n-1, ne go sporeduvame bidejkji e posleden i nema sledbenik
		if(*(niza+i)< *(niza+i+1)){
			continue;
		}else { // vo sportivno sledniot element ne e pogolemo od segasniot -> inicijalnata niza ne bila strogo rastec.
			vrati=2;
			break; // sme nasle eden par sto ne go ispolnuva uslovot, zastanuvame
		}
	}

	// dali nizata treba da se transformira ili ne?
	// nizata ne treba da se transformira AKO I SAMO AKO taa e strogo rastecka-> ako vrati=1
	if(vrati==2){ // ako ne e sr , togas transformiraj ja
		sortiraj(niza,*n);
		otfrli_duplikati(niza,*n,n);
	}
	//return 1; // ako e sr ( strogo rastecka)
	//return 2; // vo sekoj drug slucaj

	return vrati;
}


#include<stdio.h>
#include<math.h>
#define MAX 100
int main (){
	int i,n,rf,niza[MAX];
	printf("Vnesete go brojot na elementi vo nizata i potoa vnesete gi elementite:\n");
	fflush(stdout);
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&niza[i]);
	}

	// testirame rabotenje na funkcijata
	//rf=funkcija(niza,n); ova ne e tocno!
	rf=funkcija(niza,&n);
	if(rf==1){
		printf("Nizata e strogo rastecka.\n");
		fflush(stdout);
	}else{
		printf("Nizata ne bila strogo rastecka, sega e tranformirana.\n");
		fflush(stdout);
		for(i=0;i<n;i++){ // so novata vrednost na n , dimenzijata ostanuva ista, ako e napravena promena ovde e prosledena
			printf("%d, ",niza[i]);
		}
	}


	return 0;
}

