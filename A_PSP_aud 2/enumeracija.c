//3. ENUMERACIJA , pocnuvaat od 0 , moze da ima isti vrednosti no ne i isti iminja
/* 1. da ovozmozime vnesuvanje bojata
 * 2. da ovozmozime procenka na vnesenata boja ( ili sporedba na nizata so dozvolenite boi)
 * 3. sporedba so vrednosta na enumeraciskata konstanta i da dademe poraka za toa na koj student/ka mu e omilena boja
 */
#include <stdio.h>
#include <string.h>

enum boi {bela,crvena,zolta,zelena,sina,violetova,crna};
// boite mora da gi povrzeme so nekakvi nizi
char *boite[]={"bela","crvena","zolta","zelena","sina","violetova","crna"}; //boite od 1 kje ja povikuvaat crvena

int main (){
	char vnesenaBoja[20];
	enum boi odbrana; // promenliva od tip boi
	int i;

	printf("Vnesete ime na boja.\n");
	fflush(stdout);
	gets(vnesenaBoja);
	odbrana=10; // nekoj broj sto go nemame

	for(i=bela;i<=crna;i++){
		if(strcmp(vnesenaBoja,boite[i])==0){ // ako se ISTI vrakja 1 , gi sporeduvame cmp
			odbrana=i;
		}
	}

	switch(odbrana){
	case bela: printf("Belata boja e omilena na Veronika.\n"); break;
	case crvena: printf("Crvenata boja e omilena na David.\n"); break;
	case zolta: printf("Zoltata e omilena boja na Eva.\n"); break;
	case zelena: printf("Zelenata e omilena boja na Kristina.\n"); break;
	case sina: printf("Sinata e omilena boja na Emi.\n"); break;
	case violetova: printf("Violetovata e omilena boja na Ana.\n"); break;
	case crna: printf("%sta e omilena boja na Andrej.\n",boite[crna]); break;
	default: printf("%s boja ne mu e omilena nikomu!\n",vnesenaBoja);
	}
	return 0;
}


// enum MNOZESTVO od CELI BROEVI ama nie im davame nekakvi iminja na tie broevi
