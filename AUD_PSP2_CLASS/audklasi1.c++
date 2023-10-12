/*1.Treba da osmislime klasi:
 -podatocni clenovi (privatni): ime,plata,rabotna pozicija
 -javni metodi (javni): konstruktor,pechati,geter za plata
 2. Funkcija za sortiranje koja na vlez dobiva niza od objekti
 3. Glavna f-cija vo koja kje gi vnesuvame soodvetnite podatoci, kje gi formirame
 objektite i kje ja povikame f-jata za sortiranje.
 */

#include <iostream>
using namespace std;

enum pozicija {rabotnik, rakovoditel, direktor};

string nizapoz[3]={"rabotnik","rakovoditel","direktor"};

class vraboten{
private:
	string ime;
	int plata;
	pozicija poz;

public:
	// konstruktor so difoltni parametri : ime plata so difoltni parametri
	// a bez ovie vo zagradava bi bil difolten konstruktor bez parametri
	//pozcija pozv= (pozicija)0 ->vaka moze kako int da go gleda
	vraboten(string imev="", int platav=0, pozicija pozv=rabotnik){
		ime=imev;
		plata=platav;
		poz=pozv;
	}

	void pechati(){
		cout<<ime<<" "<<",plata: "<<plata<<" "<<",rabotna pozicija: "<<nizapoz[poz]<<endl;
	}

	//funkcijata sto treba da vrati parametar.
	int getPlata(){
		return plata;
	}

	// ni ovozmozuva da go promenime imeto.
	void setIme(string imev){
		ime=imev;
	}
};

// f-cijata za sortiranje
void sort(vraboten *v,int n){
 for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		if(v[i].getPlata()<v[j].getPlata()){
			// kreiraj go temp so difolten konstruktor i potoa kopiraj ja sodrzinata na v[i]
            //vraboten temp(v[i]);
			vraboten temp = v[i];
			v[i]=v[j];
			v[j]=temp;
	  }
	}
  }
}


int main(){
	vraboten niza[20];
	int n=0;

	cout<<"Vnesete gi podatocite za vrabotenite ili vnesete . za imeto za kraj"<<endl;
	while(1){
		string ime;
		int pozv;
		int plata;

		cin>>ime>>plata>>pozv;
		if(ime == "."){
			break;
		}

		// kreirame objekt i go smestuvame vo nizata
		niza[n]=vraboten(ime,plata,pozicija(pozv));
		n++;
	}

	sort(niza,n);

	for(int i=0;i<n;i++){
		niza[i].pechati();
	}


	return 0;
}





