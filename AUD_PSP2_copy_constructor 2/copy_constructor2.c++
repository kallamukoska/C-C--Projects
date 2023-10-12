/*
 1.Vo podatocnite clenovi na klasata da ima pokazuvac i vo konstruktorot da se alocira memoria
 onolku kolku sto e potrebno.
 2. Vo destruktorot taa memorija mora da se oslobodi.
 3. COPY CONSTRUKTOROT ako e potreben mora racno da go napisete ( i na operator za dodeluvanje )
 4.Koga ja menuvame goleminata na nizata koja e dinamicki alocirana:
 - kreirame pomoshen pokazuvac i mu dodeluvame prostor kolku ni e potreben za smestuvanje
 za site elementi koi treba da gi ima na izlez nizata.
 - gi prefrlate elementite od starata niza vo novata (tie koi treba da bidat prefrleni) i go dodavate ( ako treba da se dodade ) extra elementot.
 - ja brishite starata niza i adresata na novata niza ja smestuvate vo pokazuvacot na starata niza.

 Klasa ucenik:
 Private: pole (dinamicki alocirano),decimalen broj i cel broj za skolska godina.
 Public: konstruktor,destruktor,copy constructor,pechati(),zgolemi(),prezemi(ucenik)

 Klasa paralelka:
 Private: pole od ucenici (dinamicki) i broj na ucenici
 Public:konstruktor so defaultni parametri, destruktor, copy constructor, zgolemi(),dodadiUcenik(ucenik),pechati(),pechati5().
 */

#include <iostream>
#include <cstring>
using namespace std;

class ucenik{
private:
	char *ime; // SAMO KAKO POKAZUVAC
	double prosek; // ili float
	int shG;
public:
	ucenik(char *imev="",double prosekv=0.0,int shGv=1){
		ime= new char[strlen(imev)+1];
		strcpy(ime,imev);
		prosek=prosekv;
		shG=shGv;
	}

	// copy constructor
	ucenik(const ucenik &u){
		ime=new char[strlen(u.ime)+1];
		// ime=u.ime; ova kje go napravi kompajlerot no ne treba vaka da go napisime
		strcpy(ime,u.ime);
		prosek=u.prosek;
		shG=u.shG;
	}

	~ucenik(){
		delete[] ime;
	}

	void prezemi(ucenik &u){
		// prezemi ja pravime na vekje kreiran objekt zatoa prvo delete
		delete[] ime;
		// pa da napravime novo
		ime=new char[strlen(u.ime)+1];
		strcpy(ime,u.ime);
		prosek=u.prosek;
		shG=u.shG;
	}

	void zgolemi(){
		shG++;
	}

	void pechati(){
		cout<<ime<<",prosek: "<<prosek<<",shkolska godina: "<<shG<<endl;
	}

	double getProsek(){
		return prosek;
	}

};

class paralelka{
private:
	ucenik *ucenici; // niza od objekti
	int brU;
public:
	paralelka(ucenik *uceniciv=NULL,int brUv=0){
		brU=brUv;
		ucenici=new ucenik[brU];
		for(int i=0;i<brU;i++){
			ucenici[i].prezemi(uceniciv[i]);
		}
	}

	paralelka(const paralelka &p){
		brU=p.brU;

		ucenici=new ucenik[p.brU];
		for(int i=0;i<brU;i++){
			ucenici[i].prezemi(p.ucenici[i]);
		}
	}

	~paralelka(){
		delete[] ucenici;
	}


	void doadiUcenik(ucenik &u){
		// kreirame nova niza i nov dinamicki prostor
		ucenik *nizaU=new ucenik[brU+1];

		for(int i=0;i<brU;i++){
			nizaU[i].prezemi(ucenici[i]);
		}
		nizaU[brU].prezemi(u);

		brU++;
		delete[] ucenici;

		// MORA OVA DA GO NAPRAVIME
		// nizaU e lokalna promenliva zatoa treba da ja zemime adresata
		// zatoa vo adresata na ucenici ja stavame novata niza bidejkji ucenici e definirano vo samata klasa i nema da se unisti
		ucenici=nizaU;
	}

	void zgolemi(){
		for(int i=0;i<brU;i++){
			ucenici[i].zgolemi();
		}
	}

	void pechati(){
		cout<<"Vo paralelkata se slednite ucenici:"<<endl;
		for(int i=0;i<brU;i++){
			cout<<i+1<<". ";
			ucenici[i].pechati();
		}
	}

	void pechati5(){
		cout<<"Vo paralelkata slednite ucenici imaat prosek 5: "<<endl;
		int j=0;
		for(int i=0;i<brU;i++){
			if(ucenici[i].getProsek()>4.999){
				cout<<j+1<<". ";
				ucenici[i].pechati();
				j++;
			}
		}
	}

};

int main(){
	ucenik ucenici[3]={{"Pero",5.0,3},{"Jana",4.5,3},{"Milan",3.0,3}};
	ucenik dopolnitelen("Mia",5.0,3);

	paralelka P(ucenici,3);
	P.pechati();
	P.doadiUcenik(dopolnitelen);
	P.pechati();
	P.zgolemi();
	P.pechati5();

	return 0;
}






