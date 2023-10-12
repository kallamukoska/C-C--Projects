/*�� �� ������ ����� Prostor �� ��� �� ����� �������� ����� StanbenProstor �
MaloprodazenProstor. �� ������� Prostor �� ���� ��������� (���� ��������� ���� �� �����),
������������ �� ��������� � ��������� ���� �� ����� ���������. �� ������� StanbenProstor �� ����
���������� �� ����� �� ������� ����� ��� ������������ ���� �� �� ����. �� �������
MaloprodazenProstor �� ���� ���������� �� ����� �� �������� ��� �� ���� ���������� ��� ��
�������� ���������.
�� ����� �� ������� �� �� ������ ������� presmetaj_cena() ��� �� ���������� ������ ��
����������� �������. �������� ������� ���� �� ������� �� ���������� ���� �������� ��
������������ �� ��������� � ��������� ���� �� ����� ���������. ������ �� ������� ������� ��
���������� �� �� ����� ��� �� �������� ������� ���� �� �������� 5000 �� ����� ������ �������
�����. ������ �� ������������ ������� �� ���������� �� �� ����� ��� �������� ��������� ����
�� �������� �� ������ �������� ����� ��� ���������� ��� ��������.
������������, �� ������� �� �� ������ ������� pechati() ��� �� ������ ���������� �� �����
�� ����������� �����, �� �� ������� ������������ �� default ���������, copy ����������� � �� ��
����������� ���������� = �� ����������.
������ �� ������� �� �� ������ ������� ��� ���� ��������� ����� ��� ���������: ���� ��
���������� ��� �������� ��������� �� ����� �� ��������� � ����� �� ��������, � ������ �� ����
���������� ������� � �� ���� �� ������ ���� ����������.
�� �� ������� � ������ ������� �� ��� ����� �� �� ������� �������� �� ���������.*/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Prostor{
protected:
	char *lokacija;
	int kvadrat;
	int cena;
public:
	Prostor(char *lokacijav=NULL,int kvadratv=0,int cenav=0){
		lokacija=new char[strlen(lokacijav)+1];
		strcpy(lokacija,lokacijav);
		kvadrat=kvadratv;
		cena=cenav;
	}

	Prostor(const Prostor &P){
		lokacija=new char[strlen(P.lokacija)+1];
		kvadrat=P.kvadrat;
		cena=P.cena;
	}

	Prostor &operator=(Prostor &P){
		if(this==&P){ // OVDE KAJ THIS NE TREBA *
			return *this;
		}else{
			delete[] lokacija;
			lokacija=new char[strlen(P.lokacija)+1];
			strcpy(lokacija,P.lokacija);
			kvadrat=P.kvadrat;
			cena=P.cena;
		}
		return *this; // NE GO ZABORAVAJ
	}

	virtual ~Prostor(){
		delete[] lokacija;
	}

	virtual int presmetaj_cena(){
		int vkupno=cena*kvadrat;
		return vkupno;
	}

	virtual void pechati(){
		cout<<"Lokacija: "<<lokacija<<" Kvadrat: "<<kvadrat<<" Cena: "<<cena<<endl;
		cout<<"Krajna cena: "<<presmetaj_cena()<<endl;
	}

};

class StanbenProstor:public Prostor{
private:
	int parking;
public:
	StanbenProstor(char *lokacijav=NULL,int kvadratv=0,int cenav=0, int parkingv=0):Prostor(lokacijav,kvadratv,cenav){
		parking = parkingv;
	}

	StanbenProstor(const StanbenProstor &S):Prostor(S){
		parking=S.parking;
	}

	StanbenProstor &operator=(StanbenProstor &S){
		Prostor::operator =(S);
		parking=S.parking;
		return *this;
	}


	int presmetaj_cena(){
		int vkupno=Prostor::presmetaj_cena();
		vkupno+=parking*5000;
		return vkupno;
	}

	void pechati(){
		Prostor::pechati();
		cout<<"Parking mesta: "<<parking<<endl;
		cout<<"Krajna cena: "<<presmetaj_cena()<<endl;
	}
};

class MaloprodazenProstor:public Prostor{
private:
	int brend;
public:
	MaloprodazenProstor(char *lokacijav=NULL,int kvadratv=0,int cenav=0,int brendv=0):Prostor(lokacijav,kvadratv,cenav){
		brend=brendv;
	}

	MaloprodazenProstor(const MaloprodazenProstor &M):Prostor(M){
		brend=M.brend;
	}

	MaloprodazenProstor &operator=(MaloprodazenProstor &M){
		Prostor::operator =(M);
		brend=M.brend;
		return *this;
	}

	int presmetaj_cena(){
		int vkupno=Prostor::presmetaj_cena();
		vkupno-= vkupno*(brend/100);
		return vkupno;
	}

	void pechati(){
		Prostor::pechati();
		cout<<"Broj na brendovi: "<<brend<<endl;
		cout<<"Krajna cena: "<<presmetaj_cena()<<endl;
	}
};

void najeftinProstor( Prostor **niza, int br){
	int min=0;
	int pozicija=0;

	for(int i=0;i<br;i++){
		if(niza[i]->presmetaj_cena() < min){
			min=niza[i]->presmetaj_cena();
			pozicija=i;
		}
	}
	cout<<"Najeftiniot prostor i negovite podatoci: "<<endl;
	niza[pozicija]->pechati();
}

int main(){
	/*Prostor **niza;

	niza=new Prostor("Karposh 2",5,1000);
	niza=new Prostor("Karposh 3",7,2000);
	niza =new StanbenProstor("Karposh4",4,3000,5);

	najeftinProstor(&niza,3);*/

	return 0;
}








