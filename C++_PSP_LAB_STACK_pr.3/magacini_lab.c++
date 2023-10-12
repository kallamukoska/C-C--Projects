/*Да се напише функција која како аргумент прима структура магацин. Во функцијата треба да се
заменат вредностите на паровите соседни елементи на магацинот. Во рамките на фукцијата да се
смета дека магацинот има парен број на елементи во него.
Притоа, за решавање на задачата може да ја користите само променливи од тип структура магацин,
односно функциите кои структурата ги има (init, push, peek, pop, isEmpty, isFull). Со тоа, за да ги
изминете елементите од магацинот, треба истиот да го празните така ќе вадите по два елементи во
секој циклус. Извадените елементи од парот во секој циклус треба во обратен редослед да ги
ставите во нов помошен магацин. Откако сите елементи од оригиналниот магацин ќе бидат
изминати, во помошниот магацин ќе бидат правилно разместените елементи но во обратен вкупен
редослед, и тие ќе треба да бидат вратени во оригиналниот магацин. Кодовите за магацинот и за
функциите на магацинот исто така треба да ги напишете како дел од задачата.
Магацин: 7 1 2 1 5 1 Излезен магацин: 1 7 1 2 1 5  */

#include <iostream>

using namespace std;

const int MAX=10;

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
		if(isFull()){
			return;
		}

		top++;
		S[top].x=n;
	}

	int izvadiElement(){
		if(isEmpty()){
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
	}

	int pogledni(){
		if(isEmpty()){
			return{};
		}
		return S[top].x;
	}
};

void function(magacin &m){
	magacin pomoshen;
	pomoshen.init();
	int el1,el2;

	if(m.isEmpty()){
		cout<<"Magacinot e prazen,funkcijata ne moze da se izvrsi!"<<endl;
		return;
	}

	while(!m.isEmpty()){
		// ALGORITAM ZA VADENJE PO PAR
		el1=m.izvadiElement();//go vadime prviot element
		el2=m.izvadiElement();//go vadime vtoriot element i gi stavame vo promenlivi

		pomoshen.dodadiElement(el2);//vo pomoshen go dodavame vtoriot element (prvo)
		pomoshen.dodadiElement(el1);//go dodavame prviot element (vtoro)
	}

	while(!pomoshen.isEmpty()){
		m.dodadiElement(pomoshen.izvadiElement());
	}
}


int main(){
	magacin s;
	int brbr,element;
	s.init();

	cout<<"Vnesete kolku elementi ima vasiot magacin."<<endl;
	cin>>brbr;

	for(int i=0;i<brbr;i++){
		cin>>element;
		s.dodadiElement(element);
	}

	function(s);
	s.pechatiMagacin();

	return 0;
}

















