#include <iostream>

using namespace std;

struct jazol{
	int info;
	jazol *link;
};
struct EPKlista{
	jazol *head;
	jazol *tail;

	void init(){
		head=tail=NULL;
	}

	void dodadiPrv(int x){
			jazol *nov = new jazol;

			nov->info = x;
			if(head == tail){
				nov->link = nov;
				head = tail = nov;
				return;
			}
			nov->link= head;
			tail->link = nov;
			head = nov;
		}

	void dodadiPosleden(int x){
		jazol *nov=new jazol;

		nov->info=x;

		if(head==NULL){
			nov->link=nov;
			head=tail=nov;
			return;
		}

		nov->link=head;
		tail->link=nov;
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

		jazol *pomoshen=head;
		tail->link=head->link;
		head=head->link;

		delete pomoshen;
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
		jazol *pomoshen=tail;

		jazol *dvizi=head;
		while(dvizi->link!=tail){
			dvizi=dvizi->link;
		}
		dvizi->link=head;
		tail=dvizi;
		delete pomoshen;
	}

	void brisiLista(){
		while(head!=NULL){
			brisiPrv();
		}
	}

	void pechatiLista(){
		if(head==NULL){
			return;
		}
		jazol *dvizi=head;
		while(dvizi!=tail){
			cout<<"|"<<dvizi->info<<"|";
			dvizi=dvizi->link;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}

};


int main(){
	EPKlista L;
	L.init();

	L.dodadiPrv(1);
	L.dodadiPosleden(4);
	L.dodadiPosleden(6);
	L.dodadiPosleden(5);
	L.dodadiPosleden(3);

	L.pechatiLista();

	L.brisiPrv();
	L.pechatiLista();
	L.brisiPosleden();
	L.pechatiLista();

	return 0;
}


