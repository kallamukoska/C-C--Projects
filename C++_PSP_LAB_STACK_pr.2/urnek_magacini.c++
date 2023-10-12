/*Да се напише функција која како аргументи прима две целобројни вредности и структура магацин.
Во функцијата од магацинот треба да се задржат оние елементи од магацинот чија вредност се
наоѓа во интервалот на внесените броеви (вклучувајќи ги и самите броеви).

Притоа, за решавање на задачата може да ја користите само променливи од тип структура магацин,
односно функциите кои структурата ги има (init, push, peek, pop, isEmpty, isFull). Со тоа, за да ги
изминете елементите од магацинот, треба истиот да го празните елемент по елемент. Но,
елементите кои ги вадите од магацинот и кои според барањето на задачата треба да останат во
магацинот по проверката треба да ги зачувате во нов помошен магацин. Откако сите елементи од
оригиналниот магацин ќе бидат проверени, во помошниот магацин ќе бидат преостанати
елементите што треба да се задржат, и тие ќе треба да бидат вратени во оригиналниот магацин.
Кодовите за магацинот и за функциите на магацинот исто така треба да ги напишете како дел од
задачата.*/

#include <iostream>
using namespace std;
const int MAX = 20;

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

	void dodadiElement(int n ){
		if( isFull() ){
			cout<<"Nema mesto vo magacinot."<<endl;
			return;
		}
		top++;
		S[top].x=n;
	}

	element izvadiElement(){
		if( isEmpty() ){
			cout<<"Magacinot e prazen"<<endl;
			return{};
		}
		element x=S[top];
		top--;
		return x;
	}

	void pechati(){
		cout<<"Elementite vo magacinot se:"<<endl;
		for(int i=0;i<=top;i++){
			cout<<S[i].x<<" ";

			cout<<endl;
		}
	}

	element dzirka(){
		if( isEmpty() ){
			cout<<"Ne dzirkaj, nema nisto vo magacinot."<<endl;
			return {};
		}
		return S[top];
	}

};



void function( int br1, int br2, magacin &m){
	magacin pom1;
	pom1.init();
	int n;

	if(m.isEmpty()){
		cout<<"Magacinot e prazen."<<endl;
		return;
	}
	while( !m.isEmpty() ){
		 n=m.izvadiElement().x;
		 if((n>=br1) && (n<=br2)){
			 pom1.dodadiElement(n);
		 }
	}
	while( !pom1.isEmpty() ){
		m.dodadiElement(pom1.izvadiElement().x);
	}
}

int main(){
	magacin s;
	s.init();
	int br,element;
	int brbr1,brbr2;

	cout<<"Vnesete kolku elementi kje ima magacinot."<<endl;
	cin>>br;
	for(int i=0;i<br;i++){
			cin>>element;
			s.dodadiElement(element);
	}

	cout<<"Vnesete go intervalot."<<endl;
	cin>>brbr1>>brbr2;
	if(brbr2<brbr1){
		int pom=brbr2;
		brbr2=brbr1;
		brbr1=pom;
	}

	function(brbr1,brbr2,s);
	cout<<"Elementite vo magacinot se:"<<endl;

	for(int i=0;i<1;i++){ // za da se ispechati samo ednas
		while(!s.isEmpty()){
			s.pechati();
		}
	}

return 0;
}



/* OD DAVID
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

const int MAX = 20;

struct element{
	int podatok;
};

struct magacin{
	element elementi[MAX];
	int vrv;


	void init(){
		vrv = -1;
	}
	bool prazen(){
		return(vrv == -1);
	}
	bool poln(){
		return(vrv == MAX-1);
	}
	void vmetni(int el){
		if(poln()){
			cout<<"Magacinot e poln"<<endl;
			return;
		}
		elementi[++vrv].podatok = el;

	}
	element izvadi(){
		if(prazen()){
			cout<<"Magacinot e prazen"<<endl;
			return {};
		}
		return elementi[vrv--];
	}
	int pogledni(){
			if(prazen()){
				cout<<"Nema sto da vidam, magacinot e prazen"<<endl;
			}
			return elementi[vrv].podatok;
		}

};
void swap(int *prv,int *vtor){
	int temp;
		temp=*prv;
		*prv=*vtor;
		*vtor=temp;
}

void func(int br1,int br2,magacin &m){
	magacin pm;
	pm.init();
	int pod;
	if(m.poln()){
		cout<<"Nema nisto vo magacinot"<<endl;
		exit(-1);
	}
	while(!m.prazen()){
		pod = m.izvadi().podatok;
		if( pod >= br1 && pod <= br2){
			pm.vmetni(pod);
		}
	}
	while(!pm.prazen()){
		m.vmetni(pm.izvadi().podatok);
	}
}

void inverter(int *elementi,int k){
	int pomos[MAX],j=0;
	for(int i = k ;i>=0;i--){
		pomos[j]=elementi[i];
		j++;
	}
	for(int i=0;i<j;i++){
		elementi[i]=pomos[i];
	}
}


int main(){
	magacin mag;
	int brEl,broj1,broj2,elmnt,k=0,niza[MAX];
	mag.init();
	cout<<"Vnesete broj na elementi vo magacin (max 20)"<<endl;
	cin>>brEl;
	cout<<"Pocnete so vnesuvanje elementi: "<<endl;
	for(int i=0;i<brEl;i++){
		cin>>elmnt;
		mag.vmetni(elmnt);
	}
	cout<<"Vnesete interval(dva broja(sad) "<<endl;
	cin>>broj1>>broj2;
	if(broj1 == broj2){
				cout<<"Ne vnesovte interval"<<endl;
				exit(-1);
			}
	if(broj1>broj2){
			swap(&broj1,&broj2);
		}
	func(broj1,broj2,mag);

	while(!mag.prazen()){
		niza[k] =  mag.izvadi().podatok;
		k++;
	}
	inverter(niza,k-1);
	for(int i=0;i<=k-1;i++){
		cout<<niza[i]<<" ";
	}
	return 0;
}*/



