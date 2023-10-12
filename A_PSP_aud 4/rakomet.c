/*Да се напише програма која опишува првенство во ракомет. За првенството познати се
репрезентациите кои учествуваат (име на репрезентација, листа од играчи, вкупен број на
голови по репрезентација), а за секој играч познати се следниве информации: име, презиме,
позиција (лево крило, десно крило, лев бек, десен бек, пивот, центар, голман) и постигнати
голови.
Да се напише функција која го пресметува вкупниот број на голови за секоја
репрезентација (познат е бројот на голови на секој играч во репрезентацијата).
Да се напише функција која ќе избере најдобри играчи на првенството, во секоја од 7-
те позиции и ќе ги прикаже истите.
Во главната програма да се иницијализираат неколку репрезентации и да се повикаат
функциите.*/

/* 1. da napravime strukturi
  reprezentacija: ime, niza od igraci,bkGolovi,brigraci.
  igrac: ime, pozicija, golovi.
  2. funkcija za presmetka na vkupno golovi za sekoja reprezentacija.
  3. Izbor na igraci za sekoja pozicija so najmnogu golovi.
  4. vo main da inicijalizirame.
 */

#include <stdio.h>

enum pozicii {levokr, levbeg, centar, piker, desenbeg, desnokr, golman};
char *pozociite[]={"levo krilo", "lev beg", "cenar", "piker", "desen beg","desno krilo", "golman"};

typedef struct Igrac{
	char ime[30];
	enum pozicii pozicija;
	int brGol;
}igrac;

typedef struct Reprezentacija{
	char ime[30];
	igrac igraci [10];
	int vkGolovi;
	int brIgraci;
}reprezentacija;

void presmetajVKGolovi(reprezentacija *reprezentacii, int brRep){
	int i,j;
	for(i=0;i<brRep;i++){
		reprezentacii[i].vkGolovi=0; // vkupno golovi za SEKOJA reprezentacija.
		for(j=0;j<reprezentacii->brIgraci;j++){
			reprezentacii[i].vkGolovi+=reprezentacii[i].igraci[j].brGol;
		}
	}
}

void pecatiIgrac(igrac I){
	printf("%s pozicija:%d , broj golovi %d.\n",I.ime, I.pozicija, I.brGol);
}


void najdiNajdobarsostav(reprezentacija *reprezentacii,int brRep){
	igrac najdobri[7];
	int i,j;

	for(i=0;i<7;i++){
		najdobri[i].brGol=-1; // na pocetok site da se na 0
	}

	for(i=0;i<brRep;i++){
		for(j=0;j<reprezentacii[i].brIgraci;j++){
			switch(reprezentacii[i].igraci[j].pozicija){
			case levokr:if(najdobri[levokr].brGol<reprezentacii[i].igraci[j].brGol)
				{najdobri[levokr]=reprezentacii[i].igraci[j];} break;
			case levbeg:
				if(najdobri[levbeg].brGol<reprezentacii[i].igraci[j].brGol)
				{najdobri[levbeg]=reprezentacii[i].igraci[j];} break;
			case centar:
				if(najdobri[centar].brGol<reprezentacii[i].igraci[j].brGol)
				{najdobri[centar]=reprezentacii[i].igraci[j];} break;
			case piker:
			    if(najdobri[piker].brGol<reprezentacii[i].igraci[j].brGol)
				{najdobri[piker]=reprezentacii[i].igraci[j];} break;
			case desenbeg:
				if(najdobri[desenbeg].brGol<reprezentacii[i].igraci[j].brGol)
				{najdobri[desenbeg]=reprezentacii[i].igraci[j];} break;
			case desnokr:
				if(najdobri[desnokr].brGol<reprezentacii[i].igraci[j].brGol)
				{najdobri[desnokr]=reprezentacii[i].igraci[j];} break;
			case golman:
				if(najdobri[golman].brGol<reprezentacii[i].igraci[j].brGol)
			    {najdobri[golman]=reprezentacii[i].igraci[j];} break;

			}
		}
	}

	for(i=levokr;i<=golman;i++){
		pecatiIgrac(najdobri[i]);
	}
}


int main(){
	reprezentacija R[2]=
	{
			{"Makedonija",{{"Manaskov",levokr,17},{"Filip",levbeg,18},{"Igor",centar,6},
					{"Stoilov",piker,25},{"Kire",desenbeg,9},{"Georgievski",desnokr,12},{"Mitrevski",golman,1}},0,7
			},
			{
				"AA",{{"A1",levokr,1},{"A2",levbeg,2},{"A3",centar,3},{"A4",piker,4},
				     {"A5",desenbeg,5},{"A6",desnokr,7},{"A7",golman,8}},0,7

			}
	};

	najdiNajdobarsostav(R,2); // 2 kolku sto e brojot na reprezentacii.
	return 0;
}





