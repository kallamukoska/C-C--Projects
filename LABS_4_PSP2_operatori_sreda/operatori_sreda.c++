/*
 Да се креира класа работа со лото ливче. За лото ливчето се чува динамички алоцирана низа
од цели броеви и бројот на внесени броеви во ливчето.
Да се обезбедат следниве методи за класата:
• Конструктор со default параметри кој добива низа од цели броеви и број на цели
броеви во лото ливчето. Доколку конструкторот се повика без аргументи се креира лото
ливче со 1 број (со произволна вредност).
• Деструктор кој ќе ја брише динамички алоцираната меморија.
Дополнително да се преоптоварат следниве оператори:
• Операторот >> за вчитување на сите податоци за лото ливчето.
• Операторот << за печатење на сите податоци за лото ливчето.
• Операторот = за доделување на лото ливче.
• Операторот == за споредување на две лото ливчиња (ако имаат ист број на внесени
броеви и исти вредности за внесените броеви да врати true инаку да врати false).
• Операторот [] кој го враќа бројот од соодветната позиција.
• Операторот ++ кој овозможува додавање на нов број на крај од низата.
Да се напише главна програма во која ќе се тестира работата на сите креирани методи и
преоптоварувања.
 */
#include <iostream>
#include <cstring>
using namespace std;

class Loto{
private:
	int *livche;
	int br;
public:
	/*Loto(){
		livche=new int[1];
		br=1;
		livche[0]=5;
	}*/

	Loto(int *livchev=NULL,int brv=1){
		br=brv;
		livche=new int[br];
		for(int i=0;i<br;i++){
			livche[i]=livchev[i];
		}
	}

	~Loto(){
		delete[] livche;
	}

	friend istream & operator>>(istream &input,Loto &l){
		delete[] l.livche;
		cout<<"Dodadi dolzina na livhceto."<<endl;
		input>>l.br;

		input.livche=new int[l.br];

		for(int i=0;i<l.br;i++){
			input>>l.livche[i];
		}
		return input;
	}

	friend ostream & operator<<(ostream &output,Loto &l){
		cout<<"Pechatenje na Loto livche."<<endl;
		for(int i=0;i<l.br;i++){
			output<<l.livche[i]<<" ";
		}
		output<<endl;
		return output;
	}

	Loto & operator=(Loto &l){
		if(this==&l){
			return *this;
		}
		delete[] livche; //this->livche;
		br=l.br;
		livche=new int[br];
		for(int i=0;i<br;i++){
			livche[i]=l.livche[i];
		}
		return *this;
	}

	bool operator==(Loto &l){
		if(br==l.br){
			for(int i=0;i<br;i++){
				if(livche[i]!=l.livche[i]){
					break;
					return false;
				}
			}
		}else{
			return false;
		}
		return true;
	}

	int operator[](int pozicija){
		//OVDE NE TREBA SO FOR
		return this->livche[pozicija];
	}

	Loto &operator++(int novBroj){
		int *novoLivche;
		novoLivche=new int[br+1];
		for(int i=0;i<br;i++){
			novoLivche[i]=livche[i];
		}
		novoLivche[br++]=novBroj;
		delete [] livche;
		livche=novoLivche;
		return *this;
	}
};

/*#include<iostream>
#include<cstring>

using namespace std;

class Loto{
private:
	int *livche;
	int dolzhina;
public:

	Loto(int *broeviF=NULL,int dolzhinaF=1){
		livche = new int[dolzhinaF];
		for(int i=0;i<dolzhinaF;i++){
			livche[i] = broeviF[i];
		}
		dolzhina = dolzhinaF;
	}
	~Loto(){
		delete[] livche;

	}
	friend istream &operator>>(istream &input,Loto &l){
		cout<<"Vnesi golemina na niza "<<endl;
		input>>l.dolzhina;
		delete [] l.livche;
		l.livche = new int[l.dolzhina];
		cout<<"Vnesuvaj elementi vo nizata: "<<endl;
		for(int i=0;i<l.dolzhina;i++){
			input>>l.livche[i];
		}
		return input;
	}
	friend ostream &operator<<(ostream &output,Loto &l){
		for(int i = 0;i<l.dolzhina;i++){
			output << l.livche[i]<<" ";
		}
		output<<endl;
		return output;
		}
	Loto &operator=(const Loto &l){
		if(this==&l){
	       return *this;
		}
		else{
	    delete [] livche;
	    dolzhina = l.dolzhina;
	    livche = new int[dolzhina];
	    for(int i = 0;i <dolzhina; i++)
	        livche[i] = l.livche[i];

	    return *this;
	        }
	    }
	bool operator==(Loto &l){
		int x = 0;
		if(dolzhina == l.dolzhina){
			for(int i = 0;i<l.dolzhina;i++){
				if(livche[i] == l.livche[i]){
					x++;
				}
				else{
					return false;
					break;
				}
			}
		}else{
			return false;
		}
		return (x==dolzhina);
	}
	int &operator[](int pozicija){
		return this->livche[pozicija];
	}
	Loto &operator++(int broj){

		int *broi = new int[dolzhina+1];
		for(int i = 0;i<dolzhina;i++){
			broi[i] = livche[i];
		}
		delete [] livche;
		broi[dolzhina++] = broj;
		livche = broi;
		return *this;
		}
};
int main(){
	int niza[6] = {37,26,3,7,2,1};
	Loto l1();
	Loto l2(niza,6);
	Loto l3;
	cout<<l2;
	l3=l2;
	cout<<l3;
	if(l2 == l3){
		cout<<"l2 i l3 se isti"<<endl;
	}
	else{
		cout<<"l2 i l3 ne se isti"<<endl;
	}
	cout<<"Brojot na 4ta pozicija vo l2 nizata"<<endl;
	cout<<l2[4]<<endl;
	l2.operator ++(5);
	cout<<l2;
	return 0;
}*/


/*	Loto(){
		livche = new int[1];
		dolzhina = 1;
		livche[0] = 124;
	}*/



