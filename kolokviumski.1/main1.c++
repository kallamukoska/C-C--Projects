/*2. Во една продавница се организира акција за 8ми Март - со сметка над 500 денари купувачите од
женски пол добиваат подарок. За секој купувач се чува информација за неговото име, пол и колкав промет направил во продавницата.
 Потребно е да се испечатат сите клиенти кои добиле подарок, но во обратен редослед (последниот добитник ќе се испечати прв).
  Ако некој машки клиент има направено промет над 1000 денари, а позади него чека жена, тогаш и таа, без разлика на направениот промет, добива подарок.
Влез: Бројот на купувачи се внесува од тастатура, како и нивните податоци.
Излез: Името на клиентите кои добиле подарок.
Пример:
влез: (“Таnjа”, Z, 600), (“Pavel”, M, 550), (“Tea”, Z, 200), (“Goran”, M, 1050), (“Lena”, Z, 400), (“Dora”, Z, 350), (“Eva”, Z, 520)
излез: Eva, Lena, Tanja
Забелешка: Не е дозволено користење на низи! Функциите за работа со редови и магацини се наоѓаат во датотеката Termin1Zad2.cpp*/

#include <iostream>
using namespace std;

const int MAX=20;

struct kupuvac{
	string ime;
	bool female;
	int promet;

	void pechatiKupuvac(){
		cout<<ime<<" "<<endl;
	}
};

struct red{
	int f;
	int r;
	kupuvac Q[MAX];

	void init(){
		f=0;
		r=-1;
	}

	int isEmpty(){
		return r<0;
	}

	int isFull(){
		return r>=MAX-1;
	}

	void dodadiCovek(kupuvac c){
		if(isFull()){
			cout<<"Nema mesto vo redot, dojdete pokasno."<<endl;
			return;
		}
		r++;
		Q[r]=c;
	}

	kupuvac izvadiCovek(){
		if(isEmpty()){
			cout<<"Nema lugje vo redot."<<endl;
			return{};
		}
		kupuvac pom=Q[f];
		for(int i=0;i<=r;i++){
			Q[i]=Q[i+1];
	}
		r--;
		return pom;
	}

	kupuvac pogledni(){
		if(isEmpty()){
			cout<<"Redot e prazen."<<endl;
			return{};
		}
		return Q[f];
	}
	void pechatiRed(){
		for(int i=0;i<=r;i++){
		Q[i].pechatiKupuvac();
		}
		cout<<endl;
	}
};
struct magacin{
	int top;
	kupuvac S[MAX];

	void init(){
		top=-1;
	}

	int isEmpty(){
		return top<0;
	}

	int isFull(){
		return top>=MAX-1;
	}

	void dodadiElement(kupuvac n ){
		if( isFull() ){
			cout<<"Nema mesto vo magacinot."<<endl;
			return;
		}
		top++;
		S[top]=n;
	}

	kupuvac izvadiElement(){
		if( isEmpty() ){
			cout<<"Magacinot e prazen"<<endl;
			return{};
		}
		kupuvac x=S[top];
		top--;
		return x;
	}
	void pechati(){
		for(int i=0;i<=top;i++){
			S[i].pechatiKupuvac();

			cout<<endl;
		}
	}

	kupuvac dzirka(){
		if( isEmpty() ){
			cout<<"Ne dzirkaj, nema nisto vo magacinot."<<endl;
			return {};
		}
		return S[top];
	}
};

void function(red &redce){
	kupuvac pomoshen;
	magacin magacince;
	magacince.init();
	int flag=0;

	if(redce.isEmpty()){
		cout<<"Redot e prazen,nema zeni nitu mazi."<<endl;
		return;
	}

	while(!redce.isEmpty()){
		pomoshen=redce.izvadiCovek();
		if((pomoshen.promet>500)){
			if(pomoshen.female){
				flag=1;
				magacince.dodadiElement(pomoshen);
			}else if(!pomoshen.female && pomoshen.promet > 1000){
				flag=0;
			}
	}
		if(flag==0 && pomoshen.female){
			magacince.dodadiElement(pomoshen);
		}
}

	cout<<"Zenite koi go ispolnuvaat uslovot se: "<<endl;
	while(!magacince.isEmpty()){
		magacince.izvadiElement().pechatiKupuvac();
	}

}


int main(){
	red redot;
	redot.init();
	kupuvac kupuvac;
	int n;

	cout<<"Vnesete kolku kupuvaci kje imate vo redot."<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Vnesete info za "<<i<<"-ot kupuvac vo redot."<<endl;
		cout<<"Ime: Zena(1)/Maz(0): Promet:"<<endl;
		cin>>kupuvac.ime>>kupuvac.female>>kupuvac.promet;
		redot.dodadiCovek(kupuvac);
	}

	function(redot);
	return 0;
}


