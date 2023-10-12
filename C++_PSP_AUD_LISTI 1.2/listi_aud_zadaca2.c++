/*
 Nova funkcija koja na vlez ima EPlista

 Treba da formirame i da inicijalizirame dve novi listi

 Treba da se dvizime niz jazlite na EPlista

 Ako jazolot ima neparen element-go dodavame na listata so neparni elementi

 Ako jazolot ima paren element vo nego- go dodavame vo listata so parni elementi

 Na kraj listite treba da gi ispecatime i da gi izbrisime

 */

#include <iostream>
using namespace std;

struct jazol{
	int info;
	jazol *link; //pokazuvac kon structura jazol
};

struct EPlista{
	jazol *head;

	void init(){
		head=NULL;
	}

	void kreirajEden(int x){
		if(head != NULL){
			cout<<"Listata e vekje kreirana, ako sakate da dodadete jazol koristete druga f-cija."<<endl;
			return;
		}
		jazol *pom;
		pom=new jazol;

		pom->info=x;
		pom->link=NULL;
		head=pom;
	}

	void dodadiPrv(int x){
		jazol *pom=new jazol;
		pom->info=x;

		pom->link=head; // ja zema adresata na prviot jazol
		head=pom; // head treba da ja ima adresata na noviot jazol
	}

	void dodadiPosleden(int x){
		jazol *pom=new jazol;
		pom->info=x;
		pom->link=NULL;

		if(head==NULL){
			head=pom;
			return;
		}

		//dvizenje so head NE

		jazol *dvizi=head;
		while(dvizi->link!=NULL){
			dvizi=dvizi->link;
		}

		dvizi->link=pom;
	}

	void brisiPrv(){
		if(head==NULL){
			cout<<"Prazna lista."<<endl;
			return;
		}
		jazol *pom=head;
		head=pom->link; //head=head->link;

		delete pom;
	}

	void brisiPosleden(){
		if(head==NULL){ // ako e prazna listata
			return;
		}
		if(head->link==NULL){ // ako ima samo eden jazol
			delete head;
			head=NULL;
			return;
		}
		// sega ako imame povekje od eden jazol
		jazol *dvizi=head;
		while((dvizi->link)->link==NULL){
			dvizi=dvizi->link;
		}

		jazol *pom=dvizi->link;
		dvizi->link=NULL;
		delete pom;
	}

	void brisiLista(){
		while(head!=NULL){
			brisiPrv();
		}
	}
	void pechatiLista(){
		jazol *dvizi=head;

		while(dvizi->link!=NULL){
			cout<<"|"<<dvizi->info<<"|->";
			dvizi=dvizi->link;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}
};

void podeliLista(EPlista &LO){ // LO- originalna lista
	jazol *dvizi = LO.head;
	EPlista neparni,parni;

	neparni.init();
	neparni.init();

	while(dvizi!=NULL){
		if((dvizi->info)%2){
			neparni.dodadiPosleden(dvizi->info);
		}else if((dvizi->info)/2){
			parni.dodadiPosleden(dvizi->info);
		}
		dvizi=dvizi->link;
	}

	cout<<"Parnata podlista e :"<<endl;
	parni.pechatiLista();
	cout<<"Neparnata podlista e :"<<endl;
	neparni.pechatiLista();

	parni.brisiLista();
	neparni.brisiLista();
}

int main(){
	EPlista L1;

	L1.init();
	L1.dodadiPrv(3);
	L1.dodadiPosleden(4);
	L1.dodadiPrv(2);
	L1.dodadiPrv(1);

	podeliLista(L1);

	L1.pechatiLista();

	L1.brisiLista();
	return 0;
}

// ne mi pecati


