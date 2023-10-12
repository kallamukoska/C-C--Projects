/*Да се напише програма која ќе симулира едноставно движење на лифт. За лифтот
познати се: состојбата (стои, се движи нагоре или се движи надолу), спратот на кој
моментално се наоѓа и бројот на патници кои се возат во него. За секој патник кој може да го
повика лифтот познат е спратот на кој патникот тековно се наоѓа, како и спратот до кој сака да
стигне.
Да се напише функција со која патник го повикува лифтот. Функцијата треба за време
на целото возење на лифтот да ги менува: состојбата во која се наоѓа лифтот како и спратот на
кој моментално се наоѓа. Кога лифтот ќе стигне до спратот на кој се наоѓа патникот, ако бројот
на патници во него не е поголем од дозволениот (максимум 5 патници), да се испише
соодветна порака, ако не се менува бројот на патници во лифтот, и се повторува движењето до
одредишниот спрат.
Во главната програма да се иницијализира лифт и патник и да се повика функцијата.*/

/* 1. da gi definirame strukturite
 * lift: sostojba sprat i br patnici
 * patnik:odkade, dokade.
 * 2. Funkcija- da go pridvizi liftot sprat po sprat do spratot kade se naogja patnikot ( vo for ciklus),
 * proverka dali ima mesto za patnikot , da se odnese liftot do odredisniot sprat ( vo for ciklus kje se menuva spratot)
 * 3. vo main da se inicijaliziraat strukturite i da se povika funkcijata.
 */

/* struct lift loftot ( vo glavnata programa struct lift e isto kako da napisis samo int,
 toa e tip na podatok, zatoa mora da pisime i promenliva do nego struct lift(int) liftot.
 liftot e promenliva koja e od tip structura lift.
 */

#include <stdio.h>

enum sostojbi {stoi,nagore,nadolu};
typedef struct Lift{
	 enum sostojbi sostojba;
	 int sprat;
	 int brPat;
}lift;

typedef struct Patnik{
	int odkade;
	int dokade;
}patnik;


void povikajLift(struct Lift *l,patnik p){
	int i;
	if(l->sostojba!=stoi){
		l->sostojba=stoi;
		printf("liftot stoi.\n");
	}

	if(l->sprat<p.odkade){
		l->sostojba=nagore;
		printf("Liftot trgna nagore.\n");

		for(i=l->sprat;i<p.odkade;i++){
			printf("Liftot se naogja na %d sprat.\n",i);
			l->sprat++;
		}
		printf("Liftot se naogja na %d sprat.\n",i);
		l->sostojba=stoi;
		printf("Liftot zastana.\n");


	}else if(l->sprat>p.odkade){
		l->sostojba=nadolu;
		printf("Liftot trgna nadolu.\n");

		for(i=l->sprat;i>p.odkade;i--){
			l->sprat--;
			printf("Liftot e na %d sprat.\n",i);
		}
		printf("Liftot e na %d sprat.\n",i);
		l->sostojba=stoi;
		printf("Liftot zastana.\n");
	}

	if(l->brPat >= 5){
		printf("Nema mesto, odete pesh! Toa e dobro za fizickoto zdravje.\n");
		return ; // ja zavrsuvame programata.
	}

	l->brPat++;
	printf("Brojot na patnici e %d.\n",l->brPat);

	if(p.odkade>p.dokade){
		l->sostojba=nadolu;
		printf("Liftot trgna nadolu.\n");
		for(i=p.odkade;i>p.dokade;i--){
			l->sprat--;
			printf("Liftot se naogja na %d sprat.\n",l->sprat);
		}
		l->sostojba=stoi;
		printf("Liftot zastana.\n");
	}else if(p.odkade<p.dokade){
		l->sostojba=nagore;
		printf("Liftot trgna nagore.\n");
		for(i=p.odkade;i<p.dokade;i++){
			l->sprat++;
			printf("Liftot se naogja na %d sprat.\n",l->sprat);
		}
		l->sostojba=stoi;
		printf("Liftot zastana.\n");
	}

	l->brPat--;
	printf("Brojot na patnici e %d.\n",l->brPat);
};

int main(){
	lift liftot ={stoi,3,0};
	patnik patnikot={1,6};

	povikajLift(&liftot,patnikot);
	return 0;
}




