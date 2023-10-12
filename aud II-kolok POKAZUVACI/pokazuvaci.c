/*
 * pokazuvaci.c
 *
 *  Created on: 13.12.2021
 *      Author: User
 */
// POKAZUVACI 1.
// nagolema rastecka podniza, so POKAZUVACI

/*#include<stdio.h>
#include<math.h>


void function(int nizaa[],int n,int *pos,int *len){
	int i,poc,dolz;

	poc=0;dolz=1;
	*pos=0;*len=1;
	i=0;

	while(i<n-1){
		poc=i;
		dolz=1;
		while((nizaa[i]<nizaa[i+1]&&(i<n-1))){
			i++;
			dolz++;
		}
		if(dolz > *len){
			*len=dolz;
			*pos=poc;
		}
		i++;
	}

}

#define MAX 100
int main(){
	int niza[100];
	int i,n,pos,len;

	printf("Vnesete dolzina na niza:\n");
	fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",niza[i]);
	}

	function(niza,n,&pos,&len); // pos i len moram lokaciski da gi vnesam.
	printf("Pocetokot %d , dolzina %d \n",pos,len);



	return 0;
}*/

// POKAZUVACI 2.
#include<stdio.h>
#include<math.h>
#define MAX 100

void function(int *a,int *da,int *b, int *db){ // a - nizaA da- dozlina  na niza a , no moze da gi ostavime istite iminja
	//koja niza e pogolema
	// * ni pokazuva vrednost vo lokacijata, sto ima vnatre
	int *mala, *golema, *dm, *dg;
	int i;

	if(*da>*db){
		mala=b; // izednacuvame pokazuvaci, ne dodeluvame vrednosti vo memorija zatoa bez dzvezda, ovde vikame samo gledaj vo adresata,pokazuvaj
		golema=a;
		dm=db;
		dg=da;
	}else{
		mala=a;
		golema=b;
		dm=da;
		dg=db;
	}

	for(i=0;i< *dg;i+=3){ //sega ovde so dzvezda bidejkji ne interesira dolzinata
		*(mala+ *dm)=*(golema + i); // se dvizam za dm mesta. mala[dm]- identicno so sredni zagradi
		*dm+=1;
	}

}
int main(){
	// dve nizi plus dolzini na nizite
	// da ja promeni pomalata niza taka sto kje gi dodade 3n(n=0,1,..) elementite od pogolemata niza

	// a=[ 0,3,4 ] -> a=[ 0,3,4,5,4,0]
	// b=[5,6,2,4,1,9,0]


	int nizaA[MAX], nizaB[MAX];
	int i,n,m; //n=dolzA, M=m=dolzB
	printf("Vnesete dolzina na dvete nizi:\n");
		fflush(stdout);
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%d",&nizaA[i]);
		}
		for(i=0;i<m;i++){
			scanf("%d",&nizaB[i]);
		}

		function(nizaA,&n,nizaB,&m); //gi davame adresite preku ova

		for(i=0;i<n;i++){
					printf("%d, ",nizaA[i]);
				}
				for(i=0;i<m;i++){
					printf("%d, ",nizaB[i]);
				}


	/*int niza[100];
	int i,n,pos,len; појма немма со е ова */

	return 0;
}

