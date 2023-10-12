
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
�� �� ������� � ������ ������� �� ��� ����� �� �� ������� �������� �� ���������.
 */
#include <iostream>
#include <cstring>

using namespace std;

class Prostor{
protected:
	char *lokacija;
	float kvadratura;
	float cena;
public:
	Prostor(char *lokacijav="",float kvadraturav=0.0,float cenav=0.0){
		lokacija=new char[strlen(lokacijav)+1];
		strcpy(lokacija,lokacijav);
		kvadratura=kvadraturav;
		cena=cenav;
	}

	Prostor(const Prostor &P){
		lokacija=new char[strlen(P.lokacija)+1];
		strcpy(lokacija,P.lokacija);
		kvadratura=P.kvadratura;
		cena=P.cena;
	}

	virtual ~Prostor(){
		delete[] lokacija;
	}

	 Prostor &operator=(Prostor &P){
		if(this == &P){
			return *this;
		}else{
			delete[] lokacija;
			lokacija=new char[strlen(P.lokacija)+1];
			strcpy(lokacija,P.lokacija);
			kvadratura=P.kvadratura;
			cena=P.cena;
		}
		return *this;
	}

	virtual float presmetaj_cena(){
		return (cena*kvadratura);
	}


	virtual void pechati(){
		cout<<"Lokacija: "<<lokacija<<endl;
		cout<<"Kvadratura: "<<kvadratura<<endl;
		cout<<"Cena: "<<cena<<endl;
	}
};

class StanbenProstor : public Prostor{
private:
	int parking;
public:
	StanbenProstor(char *lokacijav="",float kvadraturav=0.0,float cenav=0.0,int parkingv=0):Prostor(lokacijav,kvadraturav,cenav){
		parking=parkingv;
	}

	StanbenProstor(const StanbenProstor &S){
		lokacija=new char[strlen(S.lokacija)+1];
		strcpy(lokacija,S.lokacija);
		kvadratura=S.kvadratura;
		cena=S.cena;
		parking=S.parking;
	}

	StanbenProstor &operator=(StanbenProstor &S){
		if(this == &S){
			return *this;
		}else{
			Prostor::operator =(S);
			parking=S.parking;
		}
		return *this;
	}

	float presmetaj_cena(){
		float vkupno=Prostor::presmetaj_cena();
		for(int i=0;i<parking;i++){
			vkupno=vkupno+5000;
		}
		return vkupno;
	}

	void pechati(){
		Prostor::pechati();
		cout<<"Parking: "<<parking<<endl;
	}
};

class MaloprodazenProstor : public Prostor{
	int brendovi;
public:
	MaloprodazenProstor(char *lokacijav="",float kvadraturav=0.0,float cenav=0.0,int brendoviv=0):Prostor(lokacijav,kvadraturav,cenav){
		brendovi=brendoviv;
	}

	MaloprodazenProstor(const MaloprodazenProstor &M){
		lokacija=new char[strlen(M.lokacija)+1];
		strcpy(lokacija,M.lokacija);
		kvadratura=M.kvadratura;
		cena=M.cena;
		brendovi=M.brendovi;
	}

	MaloprodazenProstor &operator=(MaloprodazenProstor &M){
		if(this == &M){
			return *this;
		}else{
			Prostor::operator =(M);
			brendovi=M.brendovi;
		}
		return *this;
	}

	float presmetaj_cena(){
		float vkupno=Prostor::presmetaj_cena();
		return (vkupno=vkupno-((1/100)*brendovi));
	}

	void pechati(){
		Prostor::pechati();
		cout<<"Brendovi: "<<brendovi<<endl;
	}

};


void najevtinProstor(Prostor *p[], int br){
	int min=p[0]->presmetaj_cena();
	int pozicija;
	for(int i=0;i<br;i++){
		if(p[i]->presmetaj_cena()<min){
			min=p[i]->presmetaj_cena();
			pozicija=i;
		}
	}

	p[pozicija]->pechati();

}

int main()
{
    Prostor *niza[20];
    StanbenProstor m1("FlatIron",100,1600,2),m2("Vodno",60,1400,1);
    MaloprodazenProstor p1("Kam",200,1000,43),p2("Tinex",150,950,25);
    niza[0]=&m1;
    niza[1]=&p1;
    niza[2]=&p2;
    //p2=p1;
    p2.pechati();
    m1.pechati();
    m2.pechati();
    m2 = m1;
    m2.pechati();
    cout<<endl;
    cout<<endl;

    najevtinProstor(niza,3);


    cout<<endl;
    cout<<"Presmetana cena na stanbeniot prostor:"<<m1.presmetaj_cena()<<endl;
    cout<<"Presmetana cena na stanbeniot prostor:"<<m2.presmetaj_cena()<<endl;
    cout<<endl;
    cout<<"Presmetana cena na maloprodazen prostor: "<<p1.presmetaj_cena()<<endl;
    cout<<"Presmetana cena na maloprodazen prostor: "<<p2.presmetaj_cena()<<endl;;
    return 0;
}








// go komentirav za da go probam presmetaj_cena
