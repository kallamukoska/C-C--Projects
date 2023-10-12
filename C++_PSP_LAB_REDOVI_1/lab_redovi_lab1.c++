/*Задача 1: Во една лабораторија во која се прават тестови за КОВИД-19 потребен е софтвер кој автоматски
ќе ги распредели во соодветни редови луѓето кои чекаат. За секој човек се знае името, ЕМБР, дали чека
резултат од направен тест и дали ќе прави серолошки тест и дали ќе прави PCR тест. Чекаат N луѓе во ист
ред, кои треба да се распределат во три реда: луѓе кои чекаат резултат и луѓе кои чекаат за серолошки тест
и луѓе кои чекаат за PCR тест. Ако некој сака да земе резултат и повторно да прави тест, прво чека во ред
за резултат, а потоа во ред за соодветното тестирање (откако ќе биде услужен во редот за резултати,
застанува на крај од редот за соодветното тестирање). Ако некој сака двете тестирања да ги направи, прво
застанува во редот за серолошко тестирање, а потоа (откако ќе биде опслужен) на крај од редот за PCR
тестирање.
Распределувањето и услужувањето на луѓето да се прави во посебна функција raspredeli&usluzi(). Во истата
функција да се распределуваат луѓето во редовите. Во функцијата и да се симулира дејството на
услужување со тоа што ќе се печатат името и ЕМБР на пациентот и порака за што биле услужени. Прво да
се опслужи редот за резултати, потоа редот за серолошко тестирање, а на крај редот за PCR тестирање.
Да се напише кодот за структурата Queue која ги вклучува и функциите за манипулација на елементите од
редот.*/

#include <iostream>
using namespace std;

const int MAX=20;

struct covek{
	string ime;
	int embr;
	bool rezultat;
	bool ser;
	bool pcr;

	void pechatiCovek(){
		cout<<ime<<" "<<embr<<" "<<endl;
	}
};

struct red{
	int f;
	int r;
	covek Q[MAX];

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

	void dodadiCovek(covek c){
		if(isFull()){
			cout<<"Nema mesto vo redot, dojdete pokasno."<<endl;
			return;
		}
		r++;
		Q[r]=c;
	}

	covek izvadiCovek(){
		if(isEmpty()){
			cout<<"Nema lugje vo redot."<<endl;
			return{};
		}
		covek pom=Q[f];
		for(int i=0;i<=r;i++){
			Q[i]=Q[i+1];
	}
		r--;
		return pom;
	}

	covek pogledni(){
		if(isEmpty()){
			cout<<"Redot e prazen."<<endl;
			return{};
		}
		return Q[f];
	}

	void pechatiRed(){
		for(int i=0;i<=r;i++){
		Q[i].pechatiCovek();
		}
		cout<<endl;
	}
};

void raspredeliUsluzi(red &lugje, red &za_rezultati, red &za_pcr, red &za_ser){
	covek covek;
	za_rezultati.init();
	za_pcr.init();
	za_ser.init();

	if(lugje.isEmpty()){
		cout<<"Vo redot ne cekaat lugje."<<endl;
		return;
	}

	while(!lugje.isEmpty()){
		covek=lugje.izvadiCovek();

		if(covek.rezultat == 1){
			za_rezultati.dodadiCovek(covek);
		}else if(covek.ser==1){
			za_ser.dodadiCovek(covek);
		}else{
			za_pcr.dodadiCovek(covek);
		}
	}

	while(!za_rezultati.isEmpty()){
		covek=za_rezultati.izvadiCovek();
		cout<<"Za rezultati bil/a opsluzen/a: "<<endl;
		covek.pechatiCovek();
		if(covek.ser==1){
			za_ser.dodadiCovek(covek);
		}else  if(covek.pcr==1){
			za_pcr.dodadiCovek(covek);
		}
	}

	while(!za_ser.isEmpty()){
		covek=za_ser.izvadiCovek();
		cout<<"Za seroloshki test bil/a opsluzen/a: "<<endl;
		covek.pechatiCovek();
		if(covek.pcr==1){
			za_pcr.dodadiCovek(covek);
		}
	}

	while(!za_pcr.isEmpty()){
		covek=za_pcr.izvadiCovek();
		cout<<"Za PCR test bil/a opsluzen/a: "<<endl;
		covek.pechatiCovek();
	}
}
int main(){
	red red,rezultat,pcr,ser;
	covek pomoshen;
	red.init();
	rezultat.init();
	pcr.init();
	ser.init();
	char c;
	int i=1;

	while(1){
		cout<<"Vnesete podatoci za covek "<<i<<endl;
		cin>>pomoshen.ime>>pomoshen.embr>>pomoshen.rezultat>>pomoshen.ser>>pomoshen.pcr;

		red.dodadiCovek(pomoshen);
		cout<<endl;
		cout<<"Vnesete . za kraj na vnesuvanjeto."<<endl;
		cin>>c;

		if(c=='.')
			break;
		i++;
	}

	raspredeliUsluzi(red,rezultat,pcr,ser);
	cout<<endl;

	return 0;
}






