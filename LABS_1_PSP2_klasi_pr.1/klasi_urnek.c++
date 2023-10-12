#include <iostream>
#include <cstdlib>

using namespace std;

class kosharkar{
private:
	string ime;
	int osnovnaplata;
public:
	kosharkar(string imev="Kiko",int osnovnaplatav=0){
		ime=imev;
		osnovnaplata=osnovnaplatav;
	}

	int getOsnovnaPlata(){
		return osnovnaplata;
	}

	void pechati(){
		cout<<"Ime: "<<ime<<" Plata: "<<osnovnaplata<<endl;
	}

/* За класата kosarkar да
се напише и функција за пресметка на платата која на влез добива реален број кој служи за да го
содржи просекот на постигнати поени по натпревар за неговата екипа.*/
 int PlataIgrach(int broj){
	 kosharkar kosh;
	 int platavk=0;
	 for(int i=0;i<broj;i++){
		 platavk=kosh.getOsnovnaPlata()+50;
	 }
	 cout<<"Vkupnata plata na igrachot e :"<<endl;
	 return platavk;
 }
};

class ekipa{
private:
	string ime;
	int brK;
	int prosek;
	kosharkar igrach[8];
public:
	ekipa(string imev="Dzvezda",int brKv=5,int prosekv=45,kosharkar *igrachv=NULL){
		if(brK<0){
			brK=0;
		}else{
			brK=brKv;
		}

		if(prosek<0){
			prosek=0;
		}else{
			prosek=prosekv;
		}

		for(int i=0;i<brK;i++){
			igrach[i]=igrachv[i];
		}

		ime=imev;
	}

	int getBrK(){
		return brK;
	}

	int getProsek(){
		return prosek;
	}

	void pechati(){
		cout<<"Ime na ekipa: "<<ime<<endl;
		cout<<"Broj na igrachi: "<<brK<<endl;
		cout<<"Ekipen prosek: "<<prosek<<endl;
		cout<<"Igracite se: "<<endl;
		for(int i=0;i<brK;i++){
			igrach[i].pechati();
		}
	}


	void PlataNaEdenKPoProsek(){
		for(int i=0;i<brK;i++){
			int plataplus=0; // po igrach vo ekipata
			for(int j=0;j<prosek;j++){
				plataplus+=50;
			}
			cout<<"Platata na igrachot so postignatiot prosek e: "<<endl;
			cout<<plataplus+igrach[i].getOsnovnaPlata()<<endl;
		}
	}
};


int main(){
	kosharkar kosharkari[5]={{},{},{},{},{}};
	ekipa ekipica("Pobednichka",5,85,kosharkari);

	for(int i=0;i<5;i++){
		kosharkari[i].pechati();
		kosharkari[i].PlataIgrach(85);
	}
	ekipica.PlataNaEdenKPoProsek();
	ekipica.pechati();

	return 0;
}













