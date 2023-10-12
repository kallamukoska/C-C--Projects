/*2.�� �� ������ ������� ��� ���� �������� ������ ��� ��������� �������� �������� �����
��� ����� ������� ���� ������, � ����� �� ������� ��� ���� �������� �������� �����. ��
������ ����� �� �� ������� ������� ��� ����� ���������� �� ������� ������, ������ ��
������� ����� �� �� ������� ������� ��� ����� ���������� �� ������� ������.
���������: �� ����� ����������� ����� �� �� ���� ������ ��������� �� ������� �� ������
�����. ����������� �� ����������� � ��������� �� ������ �� �������� �������� ����� ��
����������� ������.
3. ���� �� ������ ��� �������� �������� ����� ��� ����� �� ��������� �� �������� ��������.
�� �� ������ ������� ��� �� �� ���� ����� ����� �� ���� �����, ��� ����� �� � ��������� ��
�������� ��������. �� ������������� ����� ������ �� �������� �����.
���������: ������������� ���� �� ������� ���� ���������. ����������� �� ����������� �
��������� �� ������ �� �������� �������� ����� �� ������ 1.
�� ����: ������� ������� ���������, � ���� �������� ����� �� �� ������ ���� ����� ��
������������� �����! */

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

	void kreirajEden(int _info){
		if(head!=NULL){
			cout<<"Listata e vekje kreirana,koristete druga f-ja."<<endl;
			return;
		}
		jazol *nov=new jazol;
		nov->info=_info;
		nov->link=NULL;
		head=nov;
	}

	void dodadiPrv(int _info){
		jazol *nov=new jazol;
		nov->info=_info;
		nov->link=head;
		head=nov;
	}

	void dodadiPosleden(int _info){
		jazol *nov=new jazol;
		nov->info=_info;
		nov->link=NULL;

		if(head==NULL){
			head=nov;
			return;
		}
		jazol *dvizi=head;
		while(dvizi->link!=NULL){
			dvizi=dvizi->link;
		}
		dvizi->link=nov;
	}

	void pechatiLista(){
		jazol *dvizi=head;
		while(dvizi->link != NULL){
			cout<<"|"<<dvizi->info<<"|";
			dvizi=dvizi->link;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}

	void brisiPrv(){
		if(head==NULL){
			cout<<"Prazna lista."<<endl;
			return;
	}
		jazol *pom=head;
		head=pom->link;
		delete(pom);
	}

	void brisiPosleden(){
		if(head==NULL){
			return;
		}
		if(head->link==NULL){
			delete head;
			head=NULL;
			return;
		}
		jazol *dvizi=head;
		while((dvizi->link)->link!=NULL){
			dvizi=dvizi->link;
		}
		jazol *pomoshen=dvizi->link;
		dvizi->link=NULL;
		delete(pomoshen);
	}

	void deleteJazol(jazol *node){
		if(node==head){
			brisiPrv();
		}else{
			jazol *dvizi=head;
			while(dvizi!=node){
				dvizi=dvizi->link;
			}
			dvizi->link=node->link;
			delete(node);
		}
	}

	void brisiLista(){
		while(head!=NULL){
			brisiPrv();
		}
	}
};

void function(EPlista &L1,EPlista &L2){
	EPlista L;
	L.init();

	jazol *dvizi1=L1.head;
	jazol *dvizi2=L2.head;

	while((dvizi1 != NULL) && (dvizi2 != NULL)){
		if(dvizi1->info < dvizi2->info){
			L.dodadiPosleden(dvizi1->info);
			dvizi1=dvizi1->link;
		}else{
			L.dodadiPosleden(dvizi2->info);
			dvizi2=dvizi2->link;
		}
	}

	while(dvizi1!=NULL){
		L.dodadiPosleden(dvizi1->info);
		dvizi1=dvizi1->link;
	}

	while(dvizi2!=NULL){
		L.dodadiPosleden(dvizi2->info);
		dvizi2=dvizi2->link;
	}

	L.pechatiLista();
}


int main(){
	EPlista lista1;
	lista1.init();
	EPlista lista2;
	lista2.init();
	int brbr1=0,brbr2=0;
	int broj;

	cout<<"Vnesete kolku jazli kje ima prvata lista i kolku vtorata."<<endl;
	cin>>brbr1>>brbr2;

	cout<<"Vnesete gi elementite na prvata lista."<<endl;
	for(int i=0;i<brbr1;i++){
		cin>>broj;
		lista1.dodadiPosleden(broj);
	}

	cout<<"Vnesete gi elementite na vtorata lista."<<endl;
	for(int i=0;i<brbr2;i++){
		cin>>broj;
		lista2.dodadiPosleden(broj);
	}

function(lista1,lista2);

	return 0;
}







