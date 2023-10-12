/*Да се напише класа Prostor од која ќе бидат изведени класи StanbenProstor и
MaloprodazenProstor. Во класата Prostor се чува локацијата (како динамичка низа од знаци),
квадратурата на просторот и основната цена по метар квадратен. За класата StanbenProstor се чува
информација за бројот на паркинг места кои сопственикот сака да ги купи. За класата
MaloprodazenProstor се чува информација за бројот на брендови кои ги носи групацијата што го
изнајмува просторот.
За секоја од класите да се напише функција presmetaj_cena() која ја пресметува цената за
соодветниот простор. Вкупната основна цена на простор се пресметува како производ од
квадратурата на просторот и основната цена по метар квадратен. Цената на станбен простор се
пресметува на тој начин што на вкупната основна цена се додаваат 5000 за секое купено паркинг
место. Цената на малопродажен простор се пресметува на тој начин што вкупната основната цена
се намалува за онолку проценти колку што групацијата има брендови.
Дополнително, за класите да се напише функција pechati() која ги печати податоците за објект
од соодветната класа, да се напишат конструктори со default параметри, copy конструктор и да се
преоптовари операторот = за доделување.
Надвор од класите да се напише функција која како аргументи прима два парамтери: низа од
покажувачи кон простори независни од типот на просторот и бројот на простори, а истата го наоѓа
најефтиниот простор и за него ги печати сите информации.
Да се состави и главна функција во која треба да се тестира работата на функцијата.*/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Prostor{
protected:
	char *lokacija;
	int kvadrat;
	int cena;
public:
	Prostor(char *lokacijav=NULL,int kvadratv=0,int cenav=0){
		lokacija=new char[strlen(lokacijav)+1];
		strcpy(lokacija,lokacijav);
		kvadrat=kvadratv;
		cena=cenav;
	}

	Prostor(const Prostor &P){
		lokacija=new char[strlen(P.lokacija)+1];
		kvadrat=P.kvadrat;
		cena=P.cena;
	}

	Prostor &operator=(Prostor &P){
		if(this==&P){ // OVDE KAJ THIS NE TREBA *
			return *this;
		}else{
			delete[] lokacija;
			lokacija=new char[strlen(P.lokacija)+1];
			strcpy(lokacija,P.lokacija);
			kvadrat=P.kvadrat;
			cena=P.cena;
		}
		return *this; // NE GO ZABORAVAJ
	}

	virtual ~Prostor(){
		delete[] lokacija;
	}

	virtual int presmetaj_cena(){
		int vkupno=cena*kvadrat;
		return vkupno;
	}

	virtual void pechati(){
		cout<<"Lokacija: "<<lokacija<<" Kvadrat: "<<kvadrat<<" Cena: "<<cena<<endl;
		cout<<"Krajna cena: "<<presmetaj_cena()<<endl;
	}

};

class StanbenProstor:public Prostor{
private:
	int parking;
public:
	StanbenProstor(char *lokacijav=NULL,int kvadratv=0,int cenav=0, int parkingv=0):Prostor(lokacijav,kvadratv,cenav){
		parking = parkingv;
	}

	StanbenProstor(const StanbenProstor &S):Prostor(S){
		parking=S.parking;
	}

	StanbenProstor &operator=(StanbenProstor &S){
		Prostor::operator =(S);
		parking=S.parking;
		return *this;
	}


	int presmetaj_cena(){
		int vkupno=Prostor::presmetaj_cena();
		vkupno+=parking*5000;
		return vkupno;
	}

	void pechati(){
		Prostor::pechati();
		cout<<"Parking mesta: "<<parking<<endl;
		cout<<"Krajna cena: "<<presmetaj_cena()<<endl;
	}
};

class MaloprodazenProstor:public Prostor{
private:
	int brend;
public:
	MaloprodazenProstor(char *lokacijav=NULL,int kvadratv=0,int cenav=0,int brendv=0):Prostor(lokacijav,kvadratv,cenav){
		brend=brendv;
	}

	MaloprodazenProstor(const MaloprodazenProstor &M):Prostor(M){
		brend=M.brend;
	}

	MaloprodazenProstor &operator=(MaloprodazenProstor &M){
		Prostor::operator =(M);
		brend=M.brend;
		return *this;
	}

	int presmetaj_cena(){
		int vkupno=Prostor::presmetaj_cena();
		vkupno-= vkupno*(brend/100);
		return vkupno;
	}

	void pechati(){
		Prostor::pechati();
		cout<<"Broj na brendovi: "<<brend<<endl;
		cout<<"Krajna cena: "<<presmetaj_cena()<<endl;
	}
};

void najeftinProstor( Prostor **niza, int br){
	int min=0;
	int pozicija=0;

	for(int i=0;i<br;i++){
		if(niza[i]->presmetaj_cena() < min){
			min=niza[i]->presmetaj_cena();
			pozicija=i;
		}
	}
	cout<<"Najeftiniot prostor i negovite podatoci: "<<endl;
	niza[pozicija]->pechati();
}

int main(){
	/*Prostor **niza;

	niza=new Prostor("Karposh 2",5,1000);
	niza=new Prostor("Karposh 3",7,2000);
	niza =new StanbenProstor("Karposh4",4,3000,5);

	najeftinProstor(&niza,3);*/

	return 0;
}








