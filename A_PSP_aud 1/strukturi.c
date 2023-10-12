
/* 2. Да се напише програма во која ќе се дефинира структура за претставување на комплексни
броеви. Потоа да се напишат функции за собирање, одземање и множење на два комплексни
броја. Програмата треба да се тестира со внесување на два комплексни броја.*/

/*#include <stdio.h>

struct kompleks {
	float Re;
	float Im; // dva clena vo strukturata sto se realni broevi
};

struct kompleks zbir(struct kompleks x,struct kompleks y){
	//ni treba da ni vrati zbir na dva broj a tie se x i y
	struct kompleks rezultat;
	rezultat.Re=x.Re + y.Re;
	rezultat.Im=x.Im + y.Im;

	return rezultat;
}

struct kompleks razlika(struct kompleks *x,struct kompleks *y){ // sega na vlez imame pokazuvaci
	struct kompleks rezultat;
	rezultat.Re=x->Re- y->Re;
	rezultat.Im=x->Im - y->Im;

	return rezultat;
}

void proizvod(struct kompleks x,struct kompleks y,struct kompleks *z){
	// proizvodot kje go vratime kako treta promenliva bidejkji e void
	z->Re = x.Re*y.Re - x.Im*y.Im;
	z->Re=x.Im*y.Re + x.Re*y.Im;

}

void pecati(struct kompleks x){
	printf("%.2f",x.Re);
	if(x.Im > 0){
		printf("+j%.2f\n",x.Im);
	}else {
		printf("-j%.2f\n",-x.Im);
	}
}

int main(){
	struct kompleks x,y,z;
	printf("Vnesete gi realniot i imaginarniot del od x,potoa i od y.\n");
	fflush(stdout);
	scanf("%f%f",&(x.Re),&(x.Im));
	scanf("%f%f",&(y.Re),&(y.Im));

	z = zbir(x,y);
	printf("Zbirot e :\n");
	pecati(z);

	z=razlika(&x,&y); // bidejkji odzemi ocekuva pokazuvaci na vlez
	printf("Razlikata e :\n");
	pecati(z);

	printf("Proizvodot e :\n");
	proizvod(x,y,&z);
	pecati(z);

	return 0;
}*/

/*3. Од тастатура се читаат непознат број податоци за студенти. Податоците се внесуваат така што во
секој ред се дава:
- име,
- презиме,
- број на индекс , и
- четири броја (поени од секоја задача)
со произволен број празни места или табулатори меѓу нив. Да се напише програма која ќе
испечати список на студенти, каде во секој ред ќе има: презиме, име, број на индекс, вкупен број
на поени од четирите задачи, сортиран според вкупниот број на поени. Имињата и презимињата
да се напишат со голема почетна буква.*/

#include <stdio.h>
#include <ctype.h>

typedef struct stt {
	char ime[20];
	char prezime[20];
	int indeks[2];
	int zad[4]; // 4 zadaci
	int vkupno;

}student; //imeto koe sakame da se koristi ponatamu,bez typedef ova bi bilo promenliva

int main(){
	student studenti[20], pom;
	int i,j,k,brS;

	for(;;){ //jamka koja trae celo vreme
		k=scanf("%s%s%d/%d%d%d%d%d",studenti[i].ime,studenti[i].prezime,&(studenti[i].indeks[0]),&(studenti[i].indeks[1]),
				&(studenti[i].zad[0]),&(studenti[i].zad[1]),&(studenti[i].zad[2]),&(studenti[i].zad[3]));

		if(k<8){
			break;
		}

		if(islower(studenti[i].ime[0])){
			// jas:toupper(studenti[i].ime[0]);
			studenti[i].ime[0]=toupper(studenti[i].ime[0]);
		}

		if(islower(studenti[i].prezime[0])){
			studenti[i].prezime[0]=toupper(studenti[i].prezime[0]);
		}
		i++;

		brS=i; // brojot na studenti

		for(i=0;i<brS;i++){
			 // za sekoj od studentite vkupniot broj na poeni
			studenti[i].vkupno=0;
			for(j=0;j<4;j++){
				studenti[i].vkupno+=studenti[i].zad[j];
			}

			// ALGORITAM ZA SORTIRANJE
			for(i=0;i<brS;i++){
				for(j=i+1;j<brS;j++){
					if(studenti[j].vkupno>studenti[i].vkupno){
						pom=studenti[i];
						studenti[i]=studenti[j];
						studenti[j]=pom;
					}
				}
			}


			printf("Spisokot so studenti e :\n");
			for(i=0;i<brS;i++){
				printf("%d. %s %s %d/%d vk poeni:%d\n",i+1,studenti[i].ime, studenti[i].prezime, studenti[i].indeks[0], studenti[i].indeks[1], studenti[i].vkupno);
			}
		}
	}

	return 0;
}












