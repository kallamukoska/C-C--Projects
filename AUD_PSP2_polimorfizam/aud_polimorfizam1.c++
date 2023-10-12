/*Polimorfizam:
 * 1.Pokazuvac od osnovna klasa
 * 2.Pokazuvacot treba da pokazuva kon objekt od izvedena klasa
 * 3.Koga kje se aktivira funkcija koja e clenka na osnovnata klasa so pomos na pokazuvacot
 * treba da se aktivira verzijata na taa funkcija za izvedenata klasa
 *
 * Realizacija: so toa sto funkciite za koi treba da se aktivira polimorfizam,se deklariraat
 * kako virtuelni vo osnovnata klasa.
 *
 * Ako funkcijata e cisto vortuelna-togas osnovnata klasa se vika APSTRAKTNA i od nea ne moze da se
 * napravat objekti ( cisto virtuelna funkcija po deklaracijata ima =0)
 *
 * Ako od nekoja klasa moze da se napravi objekt togas toe e konkretna klasa.
 */


#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Registracija{
protected:
	string ime;
	int brSh;
	int zaf;
	int osCena;
	char **zemji;
	int brZ;
public:
	Registracija(string imev="",int brShv=0,int zafv=0,int osCenav=0,int brZv=0,char *zemjiv[]=NULL){
		ime=imev;
		brSh=brShv;
		zaf=zafv;
		osCena=osCenav;

		brZ=brZv;
		zemji=new char*[brZ]; // POKAZUVACI KON NIZA

		for(int i=0;i<brZ;i++){
			zemji[i]=new char[strlen(zemjiv[i])+1];
			strcpy(zemji[i],zemjiv[i]);
		}
	}

	Registracija(const Registracija &R){
		ime=R.ime;
		brSh=R.brSh;
		zaf=R.zaf;
		osCena=R.osCena;
		brZ=R.brZ;

		zemji=new char*[brZ];
		for(int i=0;i<brZ;i++){
			zemji[i]=new char[strlen(R.zemji[i])];
			strcpy(zemji[i],R.zemji[i]);
		}
	}

	Registracija &operator=(Registracija &R){
		if(this==&R){
			return *this;
		}else{
			ime=R.ime;
			brSh=R.brSh;
			zaf=R.zaf;
			osCena=R.osCena;

			for(int i=0;i<brZ;i++){
				delete[] zemji[i];
			}

			delete[] zemji;

			zemji=new char*[R.brZ];
			for(int i=0;i<brZ;i++){
				zemji[i]=new char[strlen(R.zemji[i])+1];
				strcpy(zemji[i],R.zemji[i]);
			}
		}
		return *this;
	}


	virtual int vkCena(){
		return osCena;
	}

	virtual ~Registracija(){
		for(int i=0;i<brZ;i++){
			delete[] zemji[i];
		}

		delete[] zemji;
	}

	virtual void pechati(){
		cout<<ime<<" "<<brSh<<" "<<zaf<<" "<<osCena<<endl;
		cout<<"Vazhi vo "<<brZ<<" zemji:"<<endl;
		for(int i=0;i<brZ;i++){
			cout<<zemji[i]<<" ";
		}
		cout<<endl;
	}

};


class Avto: public Registracija{
protected:
	bool uchestvo;
public:
	Avto(string imev="",int brShv=0,int zafv=0,int osCenav=0,int brZv=0,char *zemjiv[]=NULL,bool uchestvov=false):
		Registracija(imev,brShv,zafv,osCenav,brZv,zemjiv){
		uchestvo=uchestvov;
	}

	Avto(const Avto &A) : Registracija(A){
		uchestvo=A.uchestvo;
	}


	Avto &operator=(Avto &A){
		Registracija::operator =(A);
		this->uchestvo=A.uchestvo;

		return *this;
	}

	int vkCena(){
		int vk=Registracija::vkCena();

		if(zaf>2000){
			vk=1.1*vk;
		}

		if(uchestvo==false){
			vk=0.95*vk;
		}

		return vk;
	}

	void pechati(){
		cout<<"Klasa Reg_Auto"<<endl;
		Registracija::pechati();
		cout<<"Vk cena: "<<vkCena()<<endl;
	}
};


class Kamion:public Registracija{
protected:
	int brM;
public:
	Kamion(string imev="",int brShv=0,int zafv=0,int osCenav=0,int brZv=0,char *zemjiv[]=NULL,int brMv=0):Registracija(imev,brShv,zafv,osCenav,brZv,zemjiv){
		brM=brMv;
	}

	int vkCena(){
		int vk=Registracija::vkCena();
		vk=vk*(1+(brM/72)*4/100);

		return vk;
	}

	void pechati(){
		cout<<"Klasa Reg_Kamion:"<<endl;
		Registracija::pechati();
		cout<<"Vk cena: "<<vkCena()<<endl;
	}
};

bool sporedi(Registracija *L,Registracija *D){
	return (L->vkCena() > D->vkCena());
}

void platilNajmalku(Registracija **niza,int brbr){
	int j=0; // informacija za pozicija na pokazuvachot koj pokazuva kon objekt koj plaka najmalku
	for(int i=0;i<brbr;i++){
		if(sporedi(niza[j],niza[i])){
			j=i;
		}
	}
	cout<<"Podatoci na toj sto platil najmalku: "<<endl;
	niza[j]->pechati();
}

int main(){
	char *zemji1[3]={"Makedonija","Albanija","Srbija"};
	char *zemji2[3]={"Kosovo","Crna Gora","Bosna i Hercegovina"};
	char *zemji3[4]={"Grcija","Bugarija","Hrvatska","Slovenija"};

	Registracija *Niza[3];
	Avto A1("Ljubinka",2,2500,12000,3,zemji1,false);
	Avto A2("Maja",3,1700,10000,3,zemji2,false);
	Kamion K1("Naum",4,3000,15000,4,zemji3,90);

	Niza[0]=&A1;
	Niza[1]=&K1;
	Niza[2]=&A2;

	platilNajmalku(Niza,3);

	return 0;
}

























