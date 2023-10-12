/*Дадени се две двојно поврзани листи чии јазли содржат парен број цели броеви (бројот на
елементи во двете листи мора да е еднаков, доколку не е еднаков, се отфрлаат вишокот на
елементи од подолгата листа). Да се напише функција која како аргумент прима три двојно
поврзани листи, од кои две веќе пополнети и една празна која ја враќа пополнета на следниов
начин: се земаат по два броеви од двете листи наизменично (еден број од почеток и еден од крајот
на првата, па на ист начин два броја од втората, во следната итерација вториот број од почетокот и
претпоследниот на првата листа, истото и од втората, инт.) и се проверува дали апсолутната
вредност од разликата на првите два броеви е иста со апсолутната вредност од разликата на
броевите од втората листа. Доколку овој услов е исполнет, во новата двојно поврзана листа се
сместува 1, доколку пак условот не е исполнет во новата листа да се смести 0.
Како дел од програмата да се напишат структури за имплементација на јазол и двојно поврзана
листа заедно со функциите за поддршка на листата: функции за иницијализација, додавање и
бришење на елемент на почеток од листата, додавање и бришење на елемент на крај од листата,
бришење на цела листа и печатење на елементите од листата.
Како дел од програмата да се напише главна функција во која ќе се дефинираат и
иницијализираат сите листи, и првите две листи ќе се пополнат со елементи кои корисникот ќе ги
внесува преку тастатура. Во main функцијата потоа да се повика функциите за печатење на
првите две листи, по што ќе се повика бараната функција (која треба да се имплементира) и на
крај ќе се испечати новата листа после модификацијата. Програмата да се напише во C++.
Пример:
L1: 2 ↔ 5 ↔ 10 ↔ 7 ↔ 1 ↔ 4 ↔ 12 ↔ 6
L2: 3 ↔ 21 ↔ 0 ↔ 12 ↔ 6 ↔ 6 ↔ 14 ↔ 7
Резултантна листа: 1 ↔ 1 ↔ 1 ↔ 1*/
#include<iostream>
#include<cmath>

using namespace std;

struct Jazol{
	int info;
	Jazol *next;
	Jazol *prev;

	void init(int infoF,Jazol *nextF,Jazol *prevF){
		info = infoF;
		next = nextF;
		prev = prevF;
	}
};
struct DPList{
	Jazol *head;
	Jazol *tail;

	void init(){
		head = NULL;
		tail = NULL;
	}
	void insertFirst(int info){
		Jazol *nov = new Jazol;
		nov->init(info, head, NULL);
		if(tail == NULL){
			tail = nov;
		}
		else{
			head->prev = nov;
		}
		head = nov;
	}
	void insertLast(int info){
		if(head == NULL){
			insertFirst(info);
		}
		else{
			Jazol *nov = new Jazol;
			nov->init(info, NULL, tail);
			tail->next = nov;
			tail = nov;
		}
	}
	void pecati(){
		Jazol *dvizi = head;
		while(dvizi->next != NULL){
			cout<<dvizi->info<<" ";
			dvizi = dvizi->next;
		}
		cout<<dvizi->info;
	}
	void deleteFirst(){
		Jazol *dvizi = head;
		if(dvizi != NULL){
			head = head->next;
			head->prev = NULL;
		}
		if(head == NULL){
			tail = NULL;
		}
		delete dvizi;
	}
	void deleteJazol(Jazol *node){
		if(node == head){
			deleteFirst();
		}
		else{
			Jazol *prethodnik = node->prev;
			Jazol *sledbenik = node->next;
			prethodnik->next = sledbenik;
			sledbenik->prev = prethodnik;
			delete node;
		}

	}
};

void function(DPList &L,DPList &L1,DPList &L2){
	L.init();

	Jazol *pocetok1=L1.head;
	Jazol *kraj1=L2.tail;

	Jazol *pocetok2=L2.head;
	Jazol *kraj2=L2.tail;

	while(pocetok1!=NULL){
		if((abs((pocetok1->info)-(kraj2->info)))==(abs((pocetok2->info)-(kraj2->info)))){
			L.insertLast(1);
		}else{
			L.insertLast(0);
		}


		pocetok1=pocetok1->next;
		kraj1=kraj1->prev;

		pocetok2=pocetok2->next;
		kraj2=kraj2->prev;
	}
}


int main(){
	DPList lista,lista1,lista2;
	lista1.init();
	lista2.init();
	int broj1,broj2;
	int brbr1=0,brbr2=0;

	cout<<"Vnesete kolku jazli kje ima prvata lista. "<<endl;
	cin>>brbr1;
	cout<<"Vnesete gi elementite na prvata lista."<<endl;
	for(int i=0;i<brbr1;i++){
		cin>>broj1;
		lista1.insertLast(broj1);
	}

	cout<<"Vnesete kolku jazli kje ima vtorata lista. "<<endl;
	cin>>brbr2;
	cout<<"Vnesete gi elementite na prvata lista."<<endl;
	for(int i=0;i<brbr2;i++){
		cin>>broj2;
		lista2.insertLast(broj2);
	}

	/* ne raboti ???

	  if(brbr2>brbr1){
		Jazol *dvizi=lista2.tail;
		for(int i=0;i<(brbr2-brbr1);i++){
			lista2.deleteJazol(dvizi);
			dvizi=dvizi->prev;
		}
	}else{
		Jazol *dvizi=lista1.tail;
		for(int i=0;i<(brbr1-brbr2);i++){
			lista1.deleteJazol(dvizi);
			dvizi=dvizi->prev;
		}
	}*/

	lista1.pecati();
	cout<<endl;
	lista2.pecati();
	cout<<endl;

	function(lista,lista1,lista2);
	cout<<"Modificirana:"<<endl;
	lista.pecati();

// pechati 0 0 0 0 0 0 0 0


	return 0;
}
















