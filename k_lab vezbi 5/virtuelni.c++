/*Да се креира хиерархија на класи за водење евиденција за квалитет на медиуми преку
индексот за квалитет на месечно ниво. За секој медиум е познато името, бројот на вработени и
бројот на лажни вести кои се појавиле во медиумот во текот на месецот. Почетниот индекс за
квалитет за медиумот се добива кога бројот на вработени ќе се помножи со 5, и потоа се намалува
за 1 за секоја лажна вест во текот на месецот.
Медиумите може да бидат телевизии или портали.
За телевизиите се чува и податок дали има профил на социјалните мрежи преку кој ги пласира
своите информации. За нив индексот на квалитет се зголемува за 20 доколку има профил на
социјалните мрежи.
За порталите се чува и податок за бројот на објавени постови во текот на тој месец. За секои
20 објавени поста, индексот за квалитет се зголемува за 5%.
Во секоја од класите да се дефинираат конструктори со подразбрани (default) вредности и
деструктори. Да се дефинираат и методи за печатење на сите информации за соодветните класи
(во изведените класи да се повика и искористи методот за печатење на основната класа). Исто така
за секоја класа да се дефинира функција presmetajIndeks() со чија помош се пресметува индексот
за квалитет за тој месец.

 Надвор од класите да се напише функција pomalIndeks() која на влез
добива два аргументи кои се покажувачи кон објекти од класа медиум и дава 1 на излез ако
објектот кон кој покажува првиот аргумент има помал индекс на квалитет и 0 обратно (функцијата
треба да работи за било која комбинација објекти од тип телевизија и/или портали). Дополнително,
надвор од класите да се напише функција najmalIndeks() која прими два аргументи: низа од
покажувачи кон медиуми и нивниот број. Функцијата najmalIndeks() треба да ја користи
функцијата pomalIndeks() и да го врати редниот број на медиумот со најмал индекс на квалитет.
Забелешка: Главната програма е дадена во продолжение.*/
#include <iostream>
#include <string>
using namespace std;

class Medium{
protected:
	string ime;
	int vraboteni;
	int brLazniV;
public:
	Medium(string imev="",int vraboteniv=0,int brLazniVv=0){
		ime=imev;
		vraboteni=vraboteniv;
		brLazniV=brLazniVv;
	}

	virtual ~Medium(){}

	virtual float presmetajIndeks(){
		float indeks=(5*vraboteni) - brLazniV;
		return indeks;
	}

	virtual void pechati(){
		cout<<ime<<" "<<" Broj vraboteni: "<<vraboteni<<" Broj na lazni vesti: "<<brLazniV<<endl;
	}
};

class Televizija: public Medium{
private:
	bool profil;
public:
	Televizija(string imev="",int vraboteniv=0,int brLazniVv=0,bool profilv=0):Medium(imev,vraboteniv,brLazniVv){
		profil=profilv;
	}

	float presmetajIndeks(){
		float indeks=Medium::presmetajIndeks();
		if(profil){
			indeks+=20;
		}
		return indeks;
	}

	void pechati(){
		Medium::pechati();
		cout<<"Profil: "<<(profil?"ima":"nema")<<endl;
	}
};
class Portal:public Medium{
private:
	int posts;
public:
	Portal(string imev="",int vraboteniv=0,int brLazniVv=0,int postsv=0): Medium(imev,vraboteniv,brLazniVv){
		posts=postsv;
	}

	float presmetajIndeks(){
		float indeks=Medium::presmetajIndeks();
		for(int i=0;i<posts;i=i+20){
			indeks+=indeks*(5/100);
		}
		return indeks;
	}

	void pechati(){
		Medium::pechati();
		cout<<"Broj na postovi: "<<posts<<endl;
	}
};

int pomalIndeks(Medium *A,Medium *B){

	if(A->presmetajIndeks() < B->presmetajIndeks()){
		return 1;
	}else{
		return 0;
	}
}

int najmalIndeks(Medium **niza,int br){
	int pozicija;
	float min=0.0;
	for(int i=0;i<br;i++){
		for(int j=i+1;j<br;j++){
			if(pomalIndeks(niza[i],niza[j])){
				if(niza[i]->presmetajIndeks() < min){
					min=niza[i]->presmetajIndeks();
					pozicija=i;
				}
			}
		}
	}
	return pozicija;
}

int main()
{
Medium *E[4];
Portal G1((char *)"Plusinfo", 8, 20, 150);
Portal G2((char *)"SDK", 10, 2, 100);
Televizija K1((char *)"Alfa", 22, 5, true);
E[0] = &G1; E[1] = &G2; E[2] = &K1;
K1.pechati();
cout<<K1.presmetajIndeks();


E[najmalIndeks(E,3)]->pechati();
return 0;
}

