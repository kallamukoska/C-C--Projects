/*
 1.Klasa let: 4 privatni promenlivi
 Javni clenovi:konstruktor so difoltni parametri,pechati,shifrata na pilotot (geter za shifra).

 2.Klasa pilot: 3 privatni clenovi (podatocni promenlivi)
 Javni clenovi: konstruktor, geter za shifra,geter za plata, funkcija za pechatenje.

 3.Klasa AvioKompanija: 3 privatni clenovi
 Javni clenovi: konstruktor,funkcii plata i proveri.

 4. Main

 */


#include <iostream>
#include <cstring>
using namespace std;

class Let{
private:
	int sifraLet;
	int sifraPilot;
	char polet[30];
	char destinacija[30];

public:
	Let(int sifraLetv=0, int sifraPilotv=0, char *poletv="Skopje", char *destinacijav="Ohrid"){
		if(sifraLetv<0){
			sifraLet=0;
		}else{
			sifraLet=sifraLetv;
		}

		if(sifraPilot<0){
			sifraPilot=0;
		}else{
			sifraPilot=sifraPilotv;
		}

		strcpy(polet,poletv);
		strcpy(destinacija,destinacijav);
	}

	int getSifraLet(){
		return sifraLet;
	}

	int getSifraPilot(){
		return sifraPilot;
	}

	void pechati(){
		cout<<sifraLet<<":"<<polet<<","<<destinacija<<endl;
	}
};



class Pilot{
private:
	int sifraP;
	char ime[30];
	int plataPoLet;

public:
	Pilot(int sifraPv=0, char *imev="Pero",int plataPoLetv=10000){
		sifraP=sifraPv;
		strcpy(ime,imev);
		plataPoLet=plataPoLetv;
	}

	int getsifraP(){
		return sifraP;
	}

	int getplataPoLet(){
		return plataPoLet;
	}

	const char *getIme(){
		return ime;
	}

	void pechati(){
		cout<<ime<<" "<<sifraP<<" , "<<plataPoLet<<endl;
	}

};

class AvioKompanija{
private:
	Let letovi[15];
	int brLet;
	char ime[30];

public:
	AvioKompanija(Let *letoviv= NULL,int brLetv=0, char *imev="WizzAir"){
		brLet=brLetv;
		for(int i=0;i<brLet;i++){
			letovi[i]=letoviv[i];
		}
		strcpy(ime,imev);
	}


	int proveri(int sifra){
		for(int i=0;i<brLet;i++){
			if(letovi[i].getSifraPilot()==sifra){
				return i;
			}
		}
		return -1; // ne sme nasle nieden let cija sifra odgovara na sifrata vo argument (sifra od pilotot)
	}

	void plata(Pilot *p,int n){
		for(int i=0;i<n;i++){
			int platavk=0;

			for(int j=0;j<brLet;j++){
				//p[i] pilotot sto momentalno go razgleduvame
				if(letovi[j].getSifraPilot()==p[i].getsifraP()){
					platavk+=p[i].getplataPoLet();
				}
			}

			cout<<"Plata: "<<platavk<<", za: ";
			p[i].pechati();
		}
	}
};

int main(){
	Let letovi[4]={{1,1,"Skopje","Praga"},{2,1,"Skopje","Havai"},{3,2,"Skopje","Bajkonur"},{4,2,"Skopje","Ohrid"}};
	Pilot piloti[3]={{1,"Pero",10000},{2,"Arben",12000},{3,"Tanas",13000}};

	AvioKompanija A(letovi,4,"WizzAir");

	cout<<A.proveri(piloti[0].getsifraP())<<endl;
	cout<<A.proveri(piloti[2].getsifraP())<<endl;

	A.plata(piloti, 3);


	return 0;
}

















