/*Да се напише програма за обработка на текст. За таа намена, да се креира класа Recenica во која
се чуваат знаците во реченицата (динамички алоцирана низа од char елементи). За класата Korisnik
да се напише:
- Default конструктор кој ќе креира Recenica со содржина “Zdravo!”.
- Copy конструктор и конструктор со 1 аргумент.
- Деструктор
- Функција pechati() која ja печати реченицата
- метод dodadiZnaci(char *niza, bool lok) кој ќе ја додаде niza во реченица и тоа на крај ако lok е 1
и на почеток ако lok е 0.
- метод brishiZnak(int poz) кој ќе го избрише знакот кој се наоѓа на позиција poz.
Да се напише main во кој ќе се тестира задачата. Во main функцијата прво да се креира низа од
“Mnogu sakam da ucham PSP!” и потоа со низата да се иницијализира објект од класа Rechenica и да
се испечати реченицата. Потоа на објектот да му се додаде следнта низа од знаци “za copy
konstruktor.” на крај од низата. Потоа од реченицата да се избрише знакот на позиција 24 и да се
испечати реченицата.*/


#include <iostream>
#include <cstring>
using namespace std;

class Rechenica{
private:
	char *rechenica;
public:
	Rechenica(){
		rechenica=new char[7];
		strcpy(rechenica,"Zdravo!");
	}

	Rechenica(char *rechenicaV){
		rechenica=new char[strlen(rechenicaV)+1];
		strcpy(rechenica,rechenicaV);
	}


	Rechenica(const Rechenica &r){
		rechenica=new char[strlen(r.rechenica)+1];
		strcpy(rechenica,r.rechenica);
	}

	~Rechenica(){
		delete [] rechenica;
	}

	void pechati(){
		// VAKA MOZAM DA PECHATAM CHAR !
		cout<<rechenica<<endl;
	}

	void dodadiZnaci(char *niza, bool lok){
		char *novaRec=new char[strlen(rechenica)+strlen(niza)+1];
		strcpy(novaRec,"");
		if(lok){
			// strcat DODAVA NA KRAJ
			// strcat(char *destination, const char *source)
			strcat(novaRec,rechenica);
			strcat(novaRec,niza);
		}else{
			strcat(novaRec,niza);
			strcat(novaRec,rechenica);
		}

		delete[] rechenica;
		rechenica=novaRec;
	}

	void brishiZnak(int poz){
		int j=0;
		char *novaRec=new char[strlen(rechenica)];  // NE TREBA OVDE -1,bez toa sto ne pisuvame +1, si se namaluva za 1
		strcpy(novaRec,"");

		int dolzhina=strlen(rechenica);
		// I CHAR I STRING SO FOR
		for(int i=0;i<dolzhina;i++){
			if(i!=(poz-1)){
				novaRec[j]=rechenica[i];
				j++;
			}
		}


		novaRec[dolzhina-1]='\0';

		delete[] rechenica;
		rechenica=novaRec;
	}

	/*    void brishiZnak(int poz){
    	char *novaRec=new char[strlen(rechenica)];
    	strcpy(novaRec,"");
    	for(int i=0; i<poz; i++){
    		novaRec[i]=rechenica[i];
    	}
    	int dolzina=strlen(rechenica);
    	for(int i=poz+1; i<dolzina; i++){
    		novaRec[i-1]=rechenica[i];
    	}
    	novaRec[dolzina-1]='\0';
    	delete rechenica;
    	rechenica=novaRec;
    }*/

};

int main(){
	char *Niza="Mnogu sakam da ucam PSP!";
	char *extra=" za copy constructor.";

	Rechenica r(Niza);
	r.pechati();

	r.dodadiZnaci(extra, 1);
	r.pechati();

	r.brishiZnak(24);
	r.pechati();

	return 0;
}
