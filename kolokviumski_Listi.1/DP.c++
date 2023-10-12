/*Дадена е двојно поврзана листа чии јазли содржат парен број цели броеви. Да се напише функција
која како аргумент прима една листа, проверува дали листата е точно шифрирана и враќа нова листа
која дава преглед кој елементи го исполнуваат условот на следниов начин: се земаат два броеви од
дадената листа (еден број од почеток и еден од крајот на листата, па вториот и претпоследниот, итн.) и
се проверува дали се деливи првите два броеви, па наредните два итн. Во новата листа се сместува 1
доколку се, а 0 доколку не се.
Во главната програма се проверува дали се сите вредности 1 од јазлите во новата листа, односно дали
е добро шифрирана првата листа и одговорот се печати.
Како дел од програмата да се напишат структури за имплементација на јазол и двојно поврзана листа
заедно со функциите за поддршка на листата: функции за иницијализација, додавање и бришење на
елемент на почеток од листата, додавање и бришење на елемент на крај од листата, бришење на цела
листа и печатење на елементите од листата. Како дел од програмата да се напише main функција во
која ќе се дефинираат и иницијализираат двете листи, и првата листа ќе се пополни со елементи кои
корисникот ќе ги внесува преку тастатура. Во main функцијата потоа да се повика функцијата за
печатење првата листа, по што ќе се повика бараната функција (која треба да се имплементира) и на
крај ќе се испечати резултантната листа и одговорот. Програмата да се напише во C++.
Пример:
L1: 2 ↔ 5 ↔ 10 ↔ 7 ↔ 21 ↔ 120↔ 15 ↔ 6
Резултантна листа: 1 ↔ 1 ↔ 1 ↔ 1
Одговор: Da*/

#include <iostream>
using namespace std;

struct jazol{
	int info;
	jazol *next;
	jazol *prev;

	void initJazol(int _info,jazol *_next,jazol *_prev){
		info=_info;
		next=_next;
		prev=_prev;
	}
};
struct DPlista{
	jazol *head;
	jazol *tail;

	void init(){
		head=NULL;
		tail=NULL;
	}

	void insertFirst(int _info){
		jazol *nov=new jazol;
		nov->initJazol(_info, head, NULL);
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
			jazol *nov=new jazol;
			nov->initJazol(_info, NULL, tail);
			tail->next=nov;
			tail=nov;
		}
	}

	void pechatiLista(){
		jazol *dvizi=head;
		while(dvizi!=NULL){
			cout<<"|"<<dvizi->info<<'|';
			dvizi=dvizi->next;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}

	void deleteFirst(){
		jazol *pom=head;
		if(pom!=NULL){
			head=head->next;
			head->prev=NULL;
		}
		if(head==NULL)
			tail=NULL;
		delete(pom);
	}

	void deleteJazol(jazol *node){
		if(node==head){
			deleteFirst();
		}else{
			jazol *prethodnik=node->prev;
			jazol *sledbenik=node->next;
			prethodnik->next=sledbenik;
			sledbenik->prev=prethodnik;
			delete(node);
			}
		}
};

void function(DPlista &original,DPlista &modificirana){
	jazol *pocetok=original.head;
	jazol *posleden=original.tail;
	modificirana.init();
	int brPoc,brKr;


	while(pocetok!=NULL && posleden!=NULL){
		brPoc=pocetok->info;
		brKr=posleden->info;

		if(brPoc<brKr){
			int temp;
			temp = brPoc;
			brPoc = brKr;
			brKr = temp;
		}

		if((brPoc%brKr)==0){
			// dvata broevi se delat.
			modificirana.insertLast(1);
		}else{
			modificirana.insertLast(0);
		}
		pocetok=pocetok->next;
		posleden=posleden->prev;
	}
}

int main(){
	DPlista lista1;
	DPlista lista2;
	lista1.init();
	lista2.init();
	int n;
	cout<<"Vnesete kolku jazli kje imate vo listata."<<endl;
	cin>>n;
	int broj,flag;
	for(int i=0;i<n;i++){
		cin>>broj;
		lista1.insertLast(broj);
	}
	cout<<"Originalnata lista:"<<endl;
	lista1.pechatiLista();

	function(lista1,lista2);

	cout<<"Posle modifikacijata listata izgleda:"<<endl;
	lista2.pechatiLista();

	cout<<"Odgovor:";
	jazol *dvizi=lista2.head;
	while(dvizi!=NULL){
		flag=1;
		if(dvizi->info==1){
			dvizi=dvizi->next;
		}else{
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<"DA."<<endl;
	}else{
		cout<<"NE."<<endl;
	}

	return 0;
}















