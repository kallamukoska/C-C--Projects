/* dvizi=dvizi->link;
   head=head->link;

   Listata kako struktura:
   -> head
   headot ne mora da bide vlez vo samata f-cija(c++)

   Strukturi
   - jazol: info pole(int), pokazuvac kon jazol struktura
   - lista: pokazuvac kon jazol *head, site barani funkcii: init(),kreirajEden(),
   brisiPrv(),brisiPos(),dodadiPrv(),dodadiPos(),brisiLista()

   Napravi main() kade kje gi testirame site f-cii.
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

int main(){
	EPlista L1;

	L1.init();
	L1.dodadiPrv(7);
	L1.dodadiPosleden(9);
	L1.dodadiPrv(1);

	L1.pechatiLista();

	L1.brisiPrv();
	L1.pechatiLista();
	L1.brisiPosleden();
	L1.pechatiLista();

	L1.brisiLista();
	return 0;
}




