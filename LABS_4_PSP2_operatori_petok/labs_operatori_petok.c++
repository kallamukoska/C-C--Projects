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

using namespace std;

class Biblioteka{
private:
	string *knigi;
	int brK;
public:
	Biblioteka(string knigiv="Bedni lugje",int brKv=1){
		brK=brKv;
		knigi=new string[brK];
		for(int i=0;i<brK;i++){
			knigi[i]=knigiv[i];
		}
	}

	~Biblioteka(){
		delete[] knigi;
	}

	 bool operator<(Biblioteka &b){
		return (this->brK<b.brK);
	}

	 friend ostream &operator<<(ostream &output,Biblioteka &b){
		 output<<"Broj na knigi: "<<b.brK<<endl;
		 for(int i=0;i<b.brK;i++){
			 output<<b.knigi[i]<<", ";
		 }
		 output<<endl;
		 return output;
	 }

	 Biblioteka &operator=(Biblioteka &b){
		 if(this==&b){
			 return *this;
		 }else{
			 delete[] knigi;
			 knigi=new string[b.brK];
			 this->brK=b.brK;
			 for(int i=0;i<brK;i++){
				 knigi[i]=b.knigi[i];
			 }
		 }
		 return *this;
	 }

	 Biblioteka &operator-=(string naslov){
		 int j=0;
		 string *novaNiza=new string[brK-1];
		 for(int i=0;i<brK;i++){
			 if(knigi[i]!=naslov){
				 novaNiza[j]=knigi[i];
				 j++;
			 }
		 }
		 delete[] knigi;
		 brK--;
		 knigi=novaNiza;
		 return *this;
	 }

	 Biblioteka &operator++(string naslov){
		 string *novaNiza=new string[brK+1];
		 novaNiza[0]=naslov;
		 for(int i=0;i<brK;i++){
			 novaNiza[i+1]=knigi[i];
		 }
		 delete[] knigi;
		 brK++;
		 knigi=novaNiza;
		 return *this;
	 }
};

