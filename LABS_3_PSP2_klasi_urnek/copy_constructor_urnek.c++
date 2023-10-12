/*Да се напише програма за следење на телесна тежина. За таа намена, да се креира класа Korisnik во
која се чуваат податоци за името на корисникот (динамички алоцирана низа од карактери), низа од
реални вредности за измерените тежини во килограми (динамички алоцирана низа од float елементи)
и број на мерења. За класата Korisnik да се напише:
- Default конструктор кој ќе креира корисник со празно име и едно мерење кое има вредност 60.
- Copy конструктор и конструктор со 3 аргументи.
- Деструктор
- Функција pechati() која ги печати податоците за корисникот
- метод dodadiMerenje(float m) кој ќе го додаде мерењето во низата од мерења на крајна позиција.
- метод brishiMerenje() кој ќе го избрише првото мерење во низата со измерени тежини
Да се напише main во кој ќе се тестира задачата. Во main функцијата прво да се креира низа од 4
мерења. Потоа со низата од мерења да се иницијализира објект од класа Korisnik и да се испечатат сите
податоци за овој објект. Потоа на објектот да му се додаде дополнителнo мерење со методата
dodadiMerenje(69.3) и да му се избрише мерење со методата brishiMerenje() по што треба повторно да
се испечатат сите информации за објектот.*/

#include <iostream>
#include <cstring>

using namespace std;

class korisnik{
private:
	char *ime;
	float *merenja;
	int brMerenja;

public:
	korisnik(){
		ime=new char[1];
		strcpy(ime,"");
		brMerenja=1;
		merenja=new float[1];
		merenja[0]=60.0;
	}

	korisnik(const korisnik &k){
		brMerenja=k.brMerenja;
		ime=new char[strlen(k.ime)+1];
		strcpy(ime,k.ime);

		merenja=new float(k.brMerenja);
		for(int i=0;i<brMerenja;i++){
			merenja[i]=k.merenja[i];
		}
	}

	korisnik(char *imev,float *merenjav,int brojv){
		brMerenja=brojv;
		ime=new char[strlen(imev)+1];
		strcpy(ime,imev);

		merenja=new float[brMerenja];
		for(int i=0;i<brMerenja;i++){
			merenja[i]=merenjav[i];
		}
	}

	~korisnik(){
		delete[] ime;
		delete[] merenja;
	}

	void pechati(){
		cout<<"Ime: "<<ime<<", broj na merenja: "<<brMerenja<<endl;
		for(int i=0;i<brMerenja;i++){
			cout<<i+1<<". ";
			cout<<merenja[i]<<endl;
		}
	}

	void dodadiMerenje(float m){
		// nova niza
		float *novaNiza=new float[brMerenja+1];
		for(int i=0;i<brMerenja;i++){
			novaNiza[i]=merenja[i];
		}
		delete[] merenja;
		novaNiza[brMerenja++]=m;
		merenja=novaNiza;
	}

	void brishiMerenje(){
		float *novaNiza=new float[brMerenja-1];
		for(int i=0;i<brMerenja-1;i++){
			novaNiza[i]=merenja[i+1];
		}
		delete[] merenja;

		merenja=novaNiza;
		brMerenja--;

	}
};

int main(){
	float nizaMerenja[4];
	for(int i=0;i<4;i++){
		cin>>nizaMerenja[i];
	}
	korisnik k("Kristina",nizaMerenja,4);
	k.pechati();
	k.dodadiMerenje(69.3);
	k.pechati();
	k.brishiMerenje();
	k.pechati();

	return 0;
}




