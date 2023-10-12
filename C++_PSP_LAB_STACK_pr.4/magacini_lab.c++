/*Да се напише функција која како аргументи при+ма две структури магацин. Во функцијата треба да
се измине првиот магацин и на крај од него да се задржат само оние елементи кои при нивно
вадење од магацинот имале иста вредност со елементот во вториот магацин кој бил на ред за
вадење, притоа доколку даден елемент од првиот магацин треба да се задржи тогаш елементот со
иста вредност од вториот магацин треба да се отстрани. Доколку прв се испразни магацинот 2,
тогаш се задржуваат сите преостанати елементи од магацинот 1.
За решавање на задачата може да ја користите само променливи од тип структура магацин,
односно функциите кои структурата ги има (init, push, peek, pop, isEmpty, isFull). Со тоа, за да ги
изминете елементите од магацинот 1, треба истиот да го празните елемент по елемент. Притоа
елементот кој сте го извадиле треба да го споредите со елементот кој се наоѓа најгоре во магацинот
2 (без притоа да го вадите од магацинот 2). Ако извадениот елемент од магацинот 1 не е ист со
елементот кој е најгоре во магацинот 2, извадениот елементот од магацинот 1 не се задржува и не
се вади елементот кој е најгоре од магацинот 2. Спротивно, доколку извадениот елемент од
магацин 1 е ист со елементот кој е најгоре во магацинот 2, извадениот елемент од магацин 1 се
става во нов помошен магацин, а најгорниот елемент од магацинот 2 се отстранува од магацин 2.
Откако сите елементи од магацин 1 ќе бидат проверени, во помошниот магацин ќе бидат
преостанати елементите што треба да се задржат, и тие ќе треба да бидат вратени во магацинот 1.
Кодовите за магацинот и за функциите на магацинот исто така треба да ги напишете како дел од
задачата.

Магацин 1: 7 1 2 3 5 1 5 Излезен магацин 1: 1 2 1 5
Магацин 2: 1 2 1 5 4 5   Излезен магацин 2: 4 5 */


#include <iostream>

using namespace std;

const int MAX=30;

struct element{
	int x;
};
struct magacin{
	int top;
	element S[MAX];

	void init(){
		top=-1;
	}

	int isEmpty(){
		return top<0;
	}

	int isFull(){
		return top>=MAX-1;
	}

	void dodadiElement(int n){
		if(isEmpty()){
			return;
		}
		top++;
		S[top].x=n;
	}

	int izvadiElement(){
		if(isFull()){
			return{};
		}

		int n=S[top].x;
		top--;
		return n;
	}

	void pechatiMagacin(){
		for(int i=0;i<=top;i++){
			cout<<S[i].x<<" ";
		}
		cout<<endl;
	}

	int pogledni(){
		if(isEmpty()){
			return{};
		}

		return S[top].x;
	}
};

void function(magacin m1, magacin m2){
	magacin pomoshen;
	pomoshen.init();
	int izvadenm1;
	int poglednim2;


	if(m1.isEmpty() || m2.isEmpty()){
		cout<<"Funkcijata ne moze da se izvrsi!"<<endl;
		return;
	}

	while(!m1.isEmpty()){
		izvadenm1=m1.izvadiElement();
		poglednim2=m2.pogledni();

		if(izvadenm1==poglednim2){
			pomoshen.dodadiElement(poglednim2);
			m2.izvadiElement();
		}

		while(!pomoshen.isEmpty()){
			m1.dodadiElement(pomoshen.izvadiElement());
		}
	}
}

int main(){
	magacin s1,s2;
	s1.init();
	s2.init();
	int brbr1,brbr2,element;

	cout<<"Vnesete kolku elementi kje ima magacinot 1."<<endl;
	cin>>brbr1;

	for(int i=0;i<brbr1;i++){
		cin>>element;
		s1.dodadiElement(element);
	}

	cout<<"Vnesete kolku elementi kje ima magacinot 2."<<endl;
	cin>>brbr2;

	for(int i=0;i<brbr2;i++){
		cin>>element;
		s2.dodadiElement(element);
	}

	function(s1,s2);

	s1.pechatiMagacin();
	s2.pechatiMagacin();

	return 0;
}










