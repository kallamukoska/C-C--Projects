//DPKL
#include <iostream>

using namespace std;

struct jazol{
	int info;
	jazol *next;
	jazol *prev;
};

struct DPKlista{
	jazol *head;
	jazol *tail;
	// brElementi

	void init(){
		head=NULL;
		tail=NULL;
	}

	void dodadiPrv(int x){
		jazol *nov=new jazol;
		nov->info=x;

		if(head==NULL){
			nov->next=nov;
			nov->prev=nov;
			head=tail=nov;
			return;
		}
		nov->next=head;
		nov->prev=tail;
		head->prev=nov;
		tail->next=nov;
		head=nov;
	}

	void dodadiPosleden(int x){
		jazol *nov=new jazol;
		nov->info=x;

		if(head==NULL){
			nov->next=nov;
			nov->prev=nov;
			head=tail=nov;
			return;
		}

		nov->next=head;
		nov->prev=tail;
		tail->next=nov;
		head->prev=nov;
		tail=nov;
	}

	void brisiPrv(){
		if(head==NULL){
			return;
		}
		if(head==tail){
			delete head;
			head=tail=NULL;
			return;
		}
		jazol *pom=head;
		tail->next=head->next;
		head->next->prev=tail; //toa so head
		head=head->next;
		delete pom;
	}

	void brisiPosleden(){
		if(head==NULL){
			return;
		}
		if(head==tail){
			delete head;
			head=tail=NULL;
			return;
		}
		jazol *pom=tail;
		tail->prev->next=head;
		head->prev=tail->prev;
		tail=tail->prev;
		delete pom;
	}

	void brisiLista(){
		while(head!=NULL){
			brisiPosleden();
		}
	}

	void pechati(){
		jazol *dvizi=head;
		if(head==NULL){
			return;
		}
		while(dvizi!=tail){
			cout<<"|"<<dvizi->info<<"|";
			dvizi=dvizi->next;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}
};


int main(){
	DPKlista l;
	l.init();

	l.dodadiPrv(2);
	l.dodadiPosleden(5);
	l.dodadiPosleden(3);
	l.dodadiPosleden(7);
	l.dodadiPosleden(1);

	l.pechati();
	l.brisiPrv();
	l.pechati();
	l.brisiPosleden();
	l.pechati();

	l.brisiLista();
	return 0;
}
















