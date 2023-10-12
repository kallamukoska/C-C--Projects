/*Дадени се двојно поврзани листи чии јазли кои содржат парен број цели броеви
и бројот на елементи е еднаков. Да се напише функција која како аргументи прима
три листи, од кои две се веќе пополнети и една празна која ја враќа пополнета на следниов начин: се
земаат по два броја од почетокот на првата листа и два броја од крајот од втората листа и се проверува
дали сумата на првите два броеви од првата листа е делива со разликата на броевите од втората листа. Доколку
условот е исполнет, во новата листа се сместува 1, доколку пак условот не е исполнет во новата листа се сместува 0.
Како дел од програмата да се напишат структури за имплементација на јазол и двојно поврзана листа заедно со функциите
за поддршка на листата: функции за иницијализација, додавање и бришење на елемент на почеток од листата, додавање и бришење
на елемент на крај од листата, бришење на цела листа и печатење на елементите од листата. Како дел од програмата да се напише
главна функција во која ќе се дефинираат и иницијализираат сите листи, и првите две листи ќе се пополнат со елементи кои корисникот
ќе ги внесува преку тастатура. Во main функцијата потоа да се повика функциите за печатење на првите две листи, по што ќе се повика
бараната функција (која треба да се имплементира) и на крај ќе се испечати новата листа после модификацијата. Програмата да се напише во C++.
Пример:
L1: 2 ↔ 8 ↔ 10 ↔ 7 ↔ 11 ↔ 10↔ 15 ↔ 6
L2: 2 ↔ 5 ↔4 ↔ 7 ↔ 5 ↔ 12↔ 4 ↔ 6
Резултантна листа: 1 ↔ 0 ↔ 1 ↔ 1*/
#include <iostream>
using namespace std;

struct jazol{
	int info;
	jazol *next;
	jazol *prev;

	void init(int _info,jazol *_next,jazol *_prev){
		info=_info;
		next=_next;
		prev=_prev;
	}
};
struct DPlista{
	jazol *head;
	jazol *tail;

	void initLista(){
		head=NULL;
		tail=NULL;
	}

	void insertFirst(int _info){
		jazol *nov=new jazol;
		nov->init(_info, head, NULL);
		if(tail==NULL){
			tail=nov;
		}else{
			head->prev=nov;
		}
		head=nov;
	}

	void insertLast(int _info){
		if(head==NULL){
			insertFirst(_info);
		}else{
			jazol *nov= new jazol;
			nov->init(_info, NULL, tail);
			tail->next=nov;
			tail=nov;
		}
	}

	void deleteFirst()
	    {
	        jazol *temp = head;
	        if(temp!=NULL)
	        {
	            head = head->next;
	            head->prev = NULL;
	        }
	        if(head==NULL)
	            tail = NULL;
	        delete temp;
	    }
	void deleteJazol(jazol *node){
		if(node==head){
			deleteFirst();
		}else{
			jazol *pr=node->prev;
			jazol *sl=node->next;
			pr->next=sl;
			sl->prev=pr;
			delete(node);
		}
	}

	void pechatiLista(){
		jazol *dvizi=head;
		while(dvizi->next!=NULL){
			cout<<"|"<<dvizi->info<<"|";
			dvizi=dvizi->next;
		}
		cout<<"|"<<dvizi->info<<"|";
	}
};

void function(DPlista &L,DPlista &L1,DPlista &L2){

	jazol *pocetok1=L1.head;
	jazol *pocetok2=L1.head->next;

	jazol *kraj1=L2.tail;
	jazol *kraj2=L2.tail->prev;

	while((pocetok1!=NULL)){
		if(((pocetok1->info+pocetok2->info)%(kraj1->info-kraj2->info))==0){
			L.insertLast(1);
		}else{
			L.insertLast(0);
		}

		pocetok1=pocetok1->next->next;
		if(pocetok1!=NULL){
			pocetok2=pocetok2->next->next;

		}


		kraj1=kraj1->prev->prev;
		if(kraj1!=NULL){
			kraj2=kraj2->prev->prev;

		}
	}
}
int main(){
	DPlista lista,lista1,lista2;
	lista.initLista();
	lista1.initLista();
	lista2.initLista();
	int brbr,broj;
	cout<<"Vnesi broj na elementi: "<<endl;
	cin>>brbr;
	cout<<"Pocni da vnesuvas vo prvata lista"<<endl;
	for(int i=0;i<brbr;i++){
		cin>>broj;
		lista1.insertLast(broj);
	}
	cout<<"Pocni da vnesuvas vo vtorata lista"<<endl;
	for(int i=0;i<brbr;i++){
		cin>>broj;
		lista2.insertLast(broj);
	}

	lista1.pechatiLista();
	cout<<endl;
	lista2.pechatiLista();
	cout<<endl;


	function(lista,lista1,lista2);

	lista.pechatiLista();

	return 0;
}

/*void function(DList &l1,DList &l2,DList &l3){
	Jazol *poc1 = l1.head;
	Jazol *kraj2 = l2.tail;
	while((poc1 != NULL)){
	int br11=poc1->info,  br12=poc1->next->info,  br21=kraj2->info,  br22=kraj2->prev->info;
		if((br11+br12)%(br21-br22)==0){
			l3.insertLast(1);
		}
		else{
			l3.insertLast(0);
		}
		poc1 = poc1->next->next;
		kraj2 = kraj2->prev->prev;
	}

}*/
