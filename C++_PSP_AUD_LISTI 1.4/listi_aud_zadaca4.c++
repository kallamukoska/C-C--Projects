#include <iostream>

using namespace std;

struct jazol{
	int info;
	jazol *link;
};
struct EPlista{
	jazol *head;

	void init(){
		head=NULL;
	}

	void dodadiPrv(int x){
		jazol *pom= new jazol;
		pom->info=x;
		pom->link=head;
		head=pom;
	}
	void brisiLista(){
		while(head!=NULL){
			jazol *pom=head;
			head=head->link;
			delete pom;
		}
	}

	void pechati(){
		jazol *dvizi=head;

		if(dvizi==NULL){
			return;
		}
		while(dvizi->link!=NULL){
			cout<<"|"<<dvizi->info<<"|";
			dvizi=dvizi->link;
		}
		cout<<"|"<<dvizi->info<<"|";
	}
};

void prevrtiLista(EPlista &L1){
	jazol *head=L1.head; // x
	jazol *novaHead=NULL;
	jazol *pom=head;

	while(head!=NULL){
		head=head->link;
		pom->link=novaHead;
		novaHead=pom;
		pom=head;
	}
	L1.head=novaHead;
}

int main(){
	EPlista lista;
	lista.init();

	lista.dodadiPrv(1);
	lista.dodadiPrv(7);
	lista.dodadiPrv(3);
	lista.dodadiPrv(5);
	lista.dodadiPrv(2);

	lista.pechati();
	prevrtiLista(lista);
	lista.pechati();
	lista.brisiLista();


	return 0;
}





















