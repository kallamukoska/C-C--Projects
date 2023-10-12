#include <iostream>
using namespace std;

struct jazol{
	int info;
	jazol *next;
	jazol *prev;
};
struct DPlista{
	jazol *head;
	jazol *tail;

	void initLista(){
		head=NULL;
		tail=NULL;
	}

	void dodadiPrv(int x){
		jazol *nov=new jazol;
		nov->info=x;
		nov->prev=NULL;

		if(head==NULL){
			head=tail=nov;
			nov->next=NULL;
		}
		nov->next=head;
		head->prev=nov;
		head=nov;
	}

	void dodadiPosleden(int x){
		jazol *nov=new jazol;
		nov->info=x;
		nov->next=NULL;
		if(head==NULL){
			head=tail=nov;
			nov->prev=NULL;
			return;
		}

		nov->prev=tail;
		tail->next=nov;
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
		head=head->next;
		head->prev=NULL;

		delete pom;
	}

	void brisiPosleden(){
		if(head==NULL){
			return;
		}
		if(head==tail){
			brisiPrv();
			/*delete head;
			head=tail=NULL;*/
			return;
		}
		jazol *pom=tail;
		tail=tail->prev;
		tail->next=NULL;
		delete pom;
	}

	void brisiLista(){
		while(head!=NULL){
			brisiPosleden();
		}
	}

	void pechatiLista(){
		jazol *dvizi=head;
		if(dvizi==NULL){
			return;
		}
		if(dvizi->next==NULL){
			// ako imame eden jazol
			cout<<"|"<<dvizi->info<<"|"<<endl;
			return;
		}

		cout<<"|"<<dvizi->info<<"|";
		dvizi=dvizi->next;

		while(dvizi->next!=NULL){
			cout<<"|"<<dvizi->info<<"|";
			dvizi=dvizi->next;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}

};

int main(){
	DPlista L;
	L.initLista();

	L.dodadiPrv(2);
	L.dodadiPosleden(5);
	L.dodadiPosleden(3);
	L.dodadiPosleden(7);
	L.dodadiPosleden(1);


	L.pechatiLista();

	L.brisiPosleden();
	L.pechatiLista();
	L.brisiPrv();
	L.pechatiLista();

    L.brisiLista();

	return 0;
}









