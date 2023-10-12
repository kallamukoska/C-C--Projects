/*

 Treba funkcija da napravime: na vlez imame 3 listi(dve polni edna prazna)

 Treba dvete da gi izmineme i vo tretata da go dodademe po eden element od listite vo sekoja iteracija

 1 3 4 7 8
 2 5 6

Izlezna lista:  1 2 3 4 5 6 7 8
elementite sto ostanale vo nekoja od listite gi dodavae vo izleznata lista.
sporeduvame element so element, koga kje iv=zvadime element listata ja pridvizuvame kon desno.

Na kraj kje napravime ciklus za pomestuvanje na nivnite elementi ama ciklusot kje se aktivira samo za ednata
(bidejkji za drugata uslovot povrzan ..

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

void kreirajKombiniranaLista(EPlista &L1,EPlista &L2,EPlista &L3 ){
	jazol *dvizi1=L1.head;
	jazol *dvizi2=L2.head;

	while((dvizi1!=NULL)&&(dvizi2!=NULL)){
		if(dvizi1->info < dvizi2->info){
			L3.dodadiPosleden(dvizi1->info);
			dvizi1=dvizi1->link; // go pridvizuvame kon desno, ednata lista a drugata ne
		}else{
			L3.dodadiPosleden(dvizi2->info);
			dvizi2=dvizi2->link;
		}
	}
	while(dvizi1!=NULL){
		L3.dodadiPosleden(dvizi1->info);
		dvizi1=dvizi1->link;
	}

	while(dvizi2!=NULL){
		L3.dodadiPosleden(dvizi2->info);
		dvizi2=dvizi2->link;
	}
}


int main(){
	EPlista L1;
	EPlista L2;
	EPlista L3;

	L1.init();
	L2.init();
	L3.init();
	L1.dodadiPrv(1);
	L1.dodadiPosleden(3);
	L1.dodadiPosleden(4);
	L1.dodadiPosleden(7);
	L1.dodadiPosleden(8);

	L2.dodadiPrv(2);
	L2.dodadiPosleden(5);
	L2.dodadiPosleden(6);

	kreirajKombiniranaLista(L1,L2,L3);

	L3.pechatiLista();

	L1.brisiLista();
	L2.brisiLista();
	L3.brisiLista();
	return 0;
}













