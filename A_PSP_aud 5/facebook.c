/*Да се напише програма која имитира поедноставена facebook апликација. Програмата
чува податоци за вашиот профил: facebook име, град, датум на раѓање, листа од пријатели,
број на пријатели. Датумот на раѓање е од облик: ден, месец, година. За секој пријател
познати се следниве информации: facebook име, датум на раѓање и порака за ѕид.
Да се напишат функции со кои може да ги промените основните податоци за вашиот
профил: facebook име, град и датум на раѓање.
Да се напише функција со која прифаќате пријател и го додавате во листата од
пријатели, но само доколку бројот на пријатели не го надминува максимално дозволениот
број (5000 пријатели) и соодветно го менувате вашиот број на пријатели.
Да се напише функција со која бришете пријател (според facebook име) од листата на
пријатели и соодветно го менувате вашиот број на пријатели.
Да се напише функција со која им честитате роденден (менувајќи го членот – порака за
ѕид) на сите пријатели кои се родени на датумот кој се проследува како аргумент на
функцијата.
Да се напише главна програма која ги тестира горенаведените функции.*/
#include <stdio.h>
#include <string.h>



//enum meseci {jan,feb,mart,april,may,jun,july,aug,sep,oct,nov,dec};
//char *mesecite[]={"Januari","Fevruari","Mart","April","Maj","Juni","Juli","Avgust"};

typedef struct datumNaRagjanje{
	int den;
	int mesec;
	//enum meseci mesec;
	int godina;
}datumNaR;

typedef struct Prijatel{
	char facebookIme[10];
	datumNaR datum;
	char poraka[50];
}prijatel;

typedef struct Profil{
	char facebookIme[20];
	char grad[20];
	datumNaR datum;
	prijatel listaprijateli[5000];
	int brPrijateli;
}profil;

//funkcii za promena na podatocite na profilot

void promenaNaIme(profil *p){
	printf("Vnesete go vaseto novo facebook ime.\n");
	gets(p->facebookIme);
	printf("Vaseto facebook ime e smeneto.\n");
	fflush(stdout);

/* DALI MOZI VAKA ?
 void promenaNaIme(profil *p, char ime[]){
 printf("Vnesete go vaseto novo facebook ime.\n");
 fflush(stdout);
 scanf("%s",ime);
 p->facebookIme=ime;
 printf("Vaseto novo ime e %s.\n", p->facebookIme);
 fflush(stdout);
 }
 */
}

void promenaNaGrad(profil *p){
	printf("Vnesete go vasiot nov grad.\n");
	gets(p->grad);
	printf("Go promenivme podatokot za vasiot grad.\n");
	fflush(stdout);
}

void promenaNaDatum(profil *p){
	printf("Vnesete novi podatoci za vasiot datum na ragjanje.\n");
	// ovde ne mozam so gets, ama mozam so scanf
	printf("Vnesete den.\n");
	fflush(stdout);
	scanf("%d",&(p->datum.den));
	printf("Vnesete mesec.\n");
	fflush(stdout);
	/* scanf("%s",p->datum.mesec); JAVUVA PROBLEM SO VAKA NAPISANO,ZOSTO? */
	scanf("%d",&(p->datum.mesec));
	printf("Vnesi godina.\n");
	fflush(stdout);
	scanf("%d",&(p->datum.mesec));
}


void dodajPrijateli(profil *p, prijatel novPrijatel){
	if(p->brPrijateli>5000){
		printf("Ne moze da go prifatite prijatelot.\n");
		fflush(stdout);
	}else if(p->brPrijateli<5000){
		// noviot prijatel se dodava na krajot od nizata!
		p->listaprijateli[p->brPrijateli]=novPrijatel; // VIDI GO REDOV I ZAPAMTI
		(p->brPrijateli)++;
		printf("Go prifativte noviot prijatel.\n");
		fflush(stdout);
	}
}

// VIDI JA FUNKCIJAVA.
/*Да се напише функција со која бришете пријател (според facebook име) од листата на
пријатели и соодветно го менувате вашиот број на пријатели.*/
void brisiPrijatel(profil *p, char brisiPr[]){ // OVDE ne treba pr.prijatel brisiPrijatel,tuku vnesuvame obicen char podatok koj treba da se sporedi so nesto od strukturite.
	/*printf("Vnesete koj prijatel sakate da go izbrisite.\n");
	fflush(stdout);
	scanf("%s",izbrisanPr.facebookIme);*/

	int i,j,flag=0;
	for(i=0;i<p->brPrijateli;i++){
		if(!strcmp(brisiPr, p->listaprijateli[i].facebookIme)){
			for(j=i;j<p->brPrijateli-1;j++){ // broj na prijateli -1
				/* сите пријатели после најдениот пријател ги поместуваме за едно место
				во лево */
				p->listaprijateli[j]= p->listaprijateli[j+1];
				(p->brPrijateli)--;
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("Prijatelot so ime %s e izbrisan od vasata lista na prijateli.\n",brisiPr);
			fflush(stdout);
		}else{
			printf("Prijatel,pod takvo ime ne e pronajden.\n");
			fflush(stdout);
		}
	}
}

void cestitajRod(profil *p, datumNaR rodenden){ //void cestitaj(int den,int mesec,int godina)
	int i;
	for(i=0;i<p->brPrijateli;i++){
		if((p->listaprijateli[i].datum.den== rodenden.den) && (p->listaprijateli[i].datum.mesec== rodenden.mesec)){
			strcpy(p->listaprijateli[i].poraka, "Happy birthday!!!\n");
			printf("Cestitavte rodenden na %s.\n",p->listaprijateli[i].facebookIme);
			fflush(stdout);
		}
	}
}

void pecatiProfil( profil *p){
	int i;
	printf("Podatoci za profilot:\n");
	printf("Facebook ime:%s.\n",p->facebookIme);
	printf("Grad:%s.\n",p->grad);
	printf("Datum na ragjanje:\n");
	printf("den/mesec/godina : %d/%d/%d \n",p->datum.den,p->datum.mesec,p->datum.godina);
	printf("Listata na prijateli i nivnite podatoci:\n");
	for(i=0;i<p->brPrijateli;i++){
		printf("%s \n",p->listaprijateli[i].facebookIme);
	}
	printf("\n");
}


int main(){
	profil mojProfil= {"Kristina","Prilep", {25,12,2002},{ { "Emilija",{15.5,2001}, ""},{"Ana",{21,5,2001},""},
			{"Eva",{26,9,2001}, ""} },3};

	prijatel drugar;
	pecatiProfil(&mojProfil);
	promenaNaIme(&mojProfil);
	pecatiProfil(&mojProfil);
	printf("Dodadete nov prijatel.\n");
	printf("Vnesete go imeto na noviot prijatel.\n");
	fflush(stdout);
	scanf("%s",drugar.facebookIme);
	printf("Vnesete go datumot(den/mesec/godina) na ragjanje na vasiot nov prijatel.\n");
	fflush(stdout);
	scanf("%d%d%d", &(drugar.datum.den), &(drugar.datum.mesec), &(drugar.datum.godina));
	printf("Vnesete poraka za dzid na vasiot priojatel.\n");
	fflush(stdout);
	scanf("%s",drugar.poraka);

	dodajPrijateli(&mojProfil,drugar);
	pecatiProfil(&mojProfil);
	brisiPrijatel(&mojProfil,"Eva");
	pecatiProfil(&mojProfil);
	return 0;
}






