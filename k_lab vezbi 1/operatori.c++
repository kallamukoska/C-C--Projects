/*Да се креира класа за опис на библиотека. За библиотеката се чува динамички алоцирана низа од
наслови на книги (насловот е стринг) и бројот на книги кој го има во библиотеката.
Да се обезбедат следниве методи за класата:
• Конструктор со default параметри кој добива низа од книги и број на книги во
библиотеката. Доколку конструкторот се повика без аргументи се креира библиотека со
една книга (со наслов по произволен избор).
• Деструктор кој ќе ја брише динамички алоцираната меморија.
Дополнително да се преоптоварат следниве оператори:
• Операторот < за споредба на две библиотеки (враќа true ако десниот операнд има повеќе
книги и fasle во спротивно)
• Операторот << за печатење на сите податоци за библиотеката.
• Операторот = за доделување библиотека.
• Операторот -= кој го наоѓа насловот кој е даден како десен операнд и го остранува од
низата со наслови (доколку не го најде, да не отстанува ништо).
• Операторот ++ кој овозможува додавање на нов наслов кој се добива како десен операнд
(додавањето да се направи на почеток од низата со наслови).
Да се напише главна програма во која ќе се тестира работата на сите креирани методи и
преоптоварувања.*/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Biblioteka{
private:
	string *knigi;
	int brKnigi;
public:

	/*Biblioteka(){
		brKnigi=1;
		knigi=new string[1];
		knigi[0]="Bedni lugje";
	}*/

	Biblioteka(string *knigiv=NULL,int brKnigiv=1){
		if(knigiv==NULL){
			knigi=new string[1];
			knigi[0]="Bedni lugje";
			brKnigi=1;
		}else{
			brKnigi=brKnigiv;
			knigi=new string[brKnigi];
			for(int i=0;i<brKnigi;i++){
				knigi[i]=knigiv[i];
			}
		}
	}

	~Biblioteka(){
		delete[] knigi;
	}

	friend istream &operator>>(istream &input,Biblioteka &b){
		delete[] knigi;
		cout<<"Vnesete broj na knigi."<<endl;
		input>>b.brKnigi;
		knigi=new string[b.brKnigi];
		for(int i=0;i<b.brKnigi;i++){
			input>>b.knigi[i];
		}
		return input;
	}

	bool operator<(Biblioteka &B){
		return (brKnigi < B.brKnigi);
	}


	friend ostream &operator<<(ostream &os,Biblioteka &B){
		os<<"Broj na knigi vo bibiliotekata: "<<B.brKnigi<<endl;
		for(int i=0;i<B.brKnigi;i++){
			os<<B.knigi[i]<<",";
		}
		os<<endl;
		return os;
	}

	Biblioteka &operator=(Biblioteka &B){
		if(this==&B){
			return *this;
		}else{
			delete[] knigi;
			brKnigi=B.brKnigi;
			knigi=new string[brKnigi];
			for(int i=0;i<brKnigi;i++){
				knigi[i]=B.knigi[i];
			}
		}
		return *this;
	}

	Biblioteka &operator-=(string naslov){
		int j=0;
		int flag=0;

		for(int i=0;i<brKnigi;i++){
			if(knigi[i]==naslov){
				flag=1;
				break;
			}
		}

		if(flag){
			string *novaNiza=new string[brKnigi-1];
			for(int i=0;i<brKnigi;i++){
				if(knigi[i]!=naslov){
					novaNiza[j]=knigi[i];
					j++;
				}
			}
			brKnigi--;
			delete[] knigi;
			knigi=novaNiza;
			return *this;
		}else{
			return *this;
		}
	}


	Biblioteka &operator+=(string naslov){
		string *novaNiza=new string[brKnigi+1];
		novaNiza[0]=naslov;
		for(int i=0;i<brKnigi;i++){
			novaNiza[i+1]=knigi[i];
		}
		brKnigi++;
		delete[] knigi;
		knigi=novaNiza;
		return *this;
	}
};

int main(){
	string kristina="Kristina";
	string david="Lolita";
	Biblioteka B1;
	string niza[3]={"Lolita","1984","Robinzon Kruso"};
	Biblioteka B2(niza,3);

	cout<<B1;
	cout<<B2;
	B1=B2;
	cout<<B1;

	B2.operator -=(david);
	cout<<B2;

	B1.operator +=(kristina);
	cout<<B1;

	return 0;
}



