#include <iostream>
using namespace std;
const int MAX = 20;

struct cevel{
	bool leva;

	/*void pechatiKupuvac(){
		cout<<ime<<" "<<endl;
	}*/
};

struct red{
	int f;
	int r;
	cevel Q[MAX];

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

	void dodadiKondura(cevel c){
		if(isFull()){
			cout<<"Nema mesto vo redot, dojdete pokasno."<<endl;
			return;
		}
		r++;
		Q[r]=c;
	}

	cevel izvadiKondura(){
		if(isEmpty()){
			cout<<"Nema lugje vo redot."<<endl;
			return{};
		}
		cevel pom=Q[f];
		for(int i=0;i<=r;i++){
			Q[i]=Q[i+1];
	}
		r--;
		return pom;
	}

	cevel pogledni(){
		if(isEmpty()){
			cout<<"Redot e prazen."<<endl;
			return{};
		}
		return Q[f];
	}
/*	void pechatiRed(){
		for(int i=0;i<=r;i++){
			cout<<Q[i].leva;
		}
		cout<<endl;
	}*/
};
struct magacin{
	int top;
	cevel S[MAX];

	void init(){
		top=-1;
	}

	int isEmpty(){
		return top<0;
	}

	int isFull(){
		return top>=MAX-1;
	}

	void dodadiElement(cevel n ){
		if( isFull() ){
			cout<<"Nema mesto vo magacinot."<<endl;
			return;
		}
		top++;
		S[top]=n;
	}

	cevel izvadiElement(){
		if( isEmpty() ){
			cout<<"Magacinot e prazen"<<endl;
			return{};
		}
		cevel x=S[top];
		top--;
		return x;
	}
/*	void pechati(){
		for(int i=0;i<=top;i++){
			S[i]<<" ";

			cout<<endl;
		}
	}*/

	cevel dzirka(){
		if( isEmpty() ){
			cout<<"Ne dzirkaj, nema nisto vo magacinot."<<endl;
			return {};
		}
		return S[top];
	}
};



void function(red &lenta){
	magacin magacince;
	magacince.init();
	cevel cevelce;
	int brbr=0;


	if(lenta.isEmpty()){
		cout<<"Nema konduri vo magacinot."<<endl;
		return;
	}

	while(!lenta.isEmpty()){
		cevelce=lenta.izvadiKondura();
		// samo za prvata kondura
		if(magacince.isEmpty()){
			magacince.dodadiElement(cevelce);
		}else{
			if(cevelce.leva != magacince.dzirka().leva){
				magacince.izvadiElement();
				brbr++;
		}else{
			magacince.dodadiElement(cevelce);
		}
	}
}
	cout<<"Brojot na spareni chevli e :"<<brbr<<endl;
}


int main(){
	red mashina;
	mashina.init();
	cevel kondura;
	int n;

	cout<<"Vnesete kolku chevli kje imate vo mashinata."<<endl;
	cin>>n;
	cout<<"Vnesete 1 za LEVA ili 0 za DESNA"<<endl;
	for(int i=0;i<n;i++){
		cin>>kondura.leva;
		mashina.dodadiKondura(kondura);
	}

	function(mashina);
	return 0;
}

