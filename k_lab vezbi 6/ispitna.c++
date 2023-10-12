/*За секој одмор се знае името на дестинацијата (динамички алоцирана низа од знаци), колку дена трае
(цел број), основната цена на аранжманот (цел број), број на понудени факултативни посети, како и цена за секоја
понудена факултативна посета (динамички алоцирана низа од цели броеви). Одморот може да биде летен или
зимски. За летниот одмор дополнително се чува информација за типот на превоз (автомобил - 0, автобус - 1, авион
- 2), како и информација дали аранжманот е полупансион - 1 или цел пансион - 2. За зимскиот одмор дополнително
се чува информација дали е уплатена ски-карта, како и цена за ски-картата за еден ден.
 Да се напише функција presmetajCena() која ја пресметува вкупната цена која треба да се плати. Цената се
пресметува на тој начин што основната цена се собира со цената на сите факултативни посети. Доколку
станува збор за летен одмор, за полупансион се доплаќа 100, а за цел пансион се доплаќа 150. Ако превозот
е со авион се доплаќа уште 100. Доколку станува збор за зимски одмор, за уплатена ски карта се собира и
цената на ски картатата за секој ден од одморот.
 Да се преоптовари операторот > кој проверува дали првиот одмор (независно од типот) има поголема
вкупна цена од вториот одмор.
 Надвор од класите да се напише функција najdiSporedKategorija() која како аргументи прима низа од
одмори независни од типот, број на одмори во низата, број на денови и име на дестинација. Функцијата
треба да го најде и испечати најскапиот одмор во низата на дадената дестинација, кој не трае повеќе од
бројот на денови пренесени како аргумент.
Главната програма е дадена во продолжение.*/
#include <iostream>
#include <cstring>
#include<string>

using namespace std;

enum prevoz{avtomobil,avtobus,avion};
string prevozi[3]={"avtomobil","avtobus","avion"};
enum tip{polupansion=1,pansion};
string tipovi[2]={"polupansion","pansion"};


class Odmor{
protected:
	char *destinacija;
	int traenje;
	int cena;
	int brposeti;
	int *poseti;
public:
	Odmor(char *destinacijav=NULL,int traenjev=0,int cenav=0,int brposetiv=0,int *posetiv=NULL){
		destinacija=new char[strlen(destinacijav)+1];
		strcpy(destinacija,destinacijav);
		traenje=traenjev;
		cena=cenav;
		brposeti=brposetiv;
		poseti=new int[brposeti];
		for(int i=0;i<brposeti;i++){
			poseti[i]=posetiv[i];
		}
	}

	virtual~Odmor(){
		delete[] destinacija;
		delete[] poseti;
	}

	virtual int presmetajCena(){
		int vkupno=cena;
		for(int i=0;i<brposeti;i++){
			vkupno+=poseti[i];
		}
		return vkupno;
	}

	int getTraenje(){
		return traenje;
	}

	char getDestinacija(){
		return *destinacija;
	}


	bool operator>(Odmor &o){
		return (presmetajCena() > o.presmetajCena());
	}

	virtual void pechati(){
		cout<<"Destinacija: "<<destinacija<<" traenje: "<<traenje<<endl;
	}

};
class LO:public Odmor{
private:
	prevoz prevozot;
	tip tipot;
public:
	LO(char *destinacijav=NULL,int traenjev=0,int cenav=0,int brposetiv=0,int *posetiv=NULL,prevoz prevozotv=avion,tip tipotv=pansion):
		Odmor(destinacijav,traenjev,cenav,brposetiv,posetiv){
		prevozot=prevozotv;
		tipot=tipotv;
	}

	int presmetajCena(){
		int vkupno=Odmor::presmetajCena();
		if(tipot==polupansion){
			vkupno+=100;
		}else if(tipot==pansion){
			vkupno+=150;
		}

		if(prevozot==avion){
			vkupno+=100;
		}
		return vkupno;
	}

	void pechati(){
		cout<<"Leten odmor: "<<endl;
		Odmor::pechati();
		}

};

class ZO:public Odmor{
	bool plateno;
	int cenaKarta; // za eden den
public:
	ZO(char *destinacijav=NULL,int traenjev=0,int cenav=0,int brposetiv=0,int *posetiv=NULL,bool platenov=0,int cenaKartav=0):
		Odmor(destinacijav,traenjev,cenav,brposetiv,posetiv){
		plateno=platenov;
		cenaKarta=cenaKartav;
	}

	int presmetajCena(){
		int vkupno=Odmor::presmetajCena();

		if(plateno){
			for(int i=0;i < traenje ;i++){
				vkupno+=cenaKarta;
			}
		}
		return vkupno;
	}

	void pechati(){
		cout<<"Zimski odmor: "<<endl;
		Odmor::pechati();
		}
};

void najdiSporedKategorija(Odmor **niza,int br,int denovi,string destinacija){
	int max=0;
	int pozicija=0;
	for(int i=0;i<br;i++){
		if((niza[i]->presmetajCena() > max) && (niza[i]->getTraenje() < denovi) && (niza[i]->getDestinacija())){
			pozicija=i;
			max=niza[i]->presmetajCena();
		}
	}
	cout<<"Najskapiot odmor so dadenite uslovi e : "<<endl;
	niza[pozicija]->pechati();
}

int main()
{
Odmor *odmori[3];
int ceni1[4] = {50,30,20,60};
int ceni2[3] = {20,25,20};
int ceni3[3] = {10,15,30};
odmori[0] = new LO("Maldivi", 10, 1000, 4, ceni1, avtomobil, polupansion);
odmori[1] = new ZO("Kopaonik", 7, 500, 3, ceni2, true, 40);
odmori[2] = new LO("Santorini", 7, 700, 3, ceni3, avion, pansion);
najdiSporedKategorija(odmori, 3, 8,"Kopaonik");
return 0;
}



