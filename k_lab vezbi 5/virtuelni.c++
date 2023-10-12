/*�� �� ������ ��������� �� ����� �� ����� ��������� �� �������� �� ������� �����
�������� �� �������� �� ������� ����. �� ���� ������ � ������� �����, ����� �� ��������� �
����� �� ����� ����� ��� �� ������� �� �������� �� ����� �� �������. ��������� ������ ��
�������� �� �������� �� ������ ���� ����� �� ��������� �� �� ������� �� 5, � ����� �� ��������
�� 1 �� ����� ����� ���� �� ����� �� �������.
��������� ���� �� ����� ��������� ��� �������.
�� ����������� �� ���� � ������� ���� ��� ������ �� ���������� ����� ����� �� �� �������
������ ����������. �� ��� �������� �� �������� �� ��������� �� 20 ������� ��� ������ ��
���������� �����.
�� ��������� �� ���� � ������� �� ����� �� ������� ������� �� ����� �� �� �����. �� �����
20 ������� �����, �������� �� �������� �� ��������� �� 5%.
�� ����� �� ������� �� �� ���������� ������������ �� ����������� (default) ��������� �
�����������. �� �� ���������� � ������ �� ������� �� ���� ���������� �� ����������� �����
(�� ���������� ����� �� �� ������ � ��������� ������� �� ������� �� ��������� �����). ���� ����
�� ����� ����� �� �� �������� ������� presmetajIndeks() �� ��� ����� �� ���������� ��������
�� �������� �� �� �����.

 ������ �� ������� �� �� ������ ������� pomalIndeks() ��� �� ����
������ ��� ��������� ��� �� ���������� ��� ������ �� ����� ������ � ���� 1 �� ����� ���
������� ��� �� �������� ������ �������� ��� ����� ������ �� �������� � 0 ������� (���������
����� �� ������ �� ���� ��� ���������� ������ �� ��� ��������� �/��� �������). ������������,
������ �� ������� �� �� ������ ������� najmalIndeks() ��� ����� ��� ���������: ���� ��
���������� ��� ������� � ������� ���. ��������� najmalIndeks() ����� �� �� �������
��������� pomalIndeks() � �� �� ����� ������� ��� �� �������� �� ����� ������ �� ��������.
���������: �������� �������� � ������ �� �����������.*/
#include <iostream>
#include <string>
using namespace std;

class Medium{
protected:
	string ime;
	int vraboteni;
	int brLazniV;
public:
	Medium(string imev="",int vraboteniv=0,int brLazniVv=0){
		ime=imev;
		vraboteni=vraboteniv;
		brLazniV=brLazniVv;
	}

	virtual ~Medium(){}

	virtual float presmetajIndeks(){
		float indeks=(5*vraboteni) - brLazniV;
		return indeks;
	}

	virtual void pechati(){
		cout<<ime<<" "<<" Broj vraboteni: "<<vraboteni<<" Broj na lazni vesti: "<<brLazniV<<endl;
	}
};

class Televizija: public Medium{
private:
	bool profil;
public:
	Televizija(string imev="",int vraboteniv=0,int brLazniVv=0,bool profilv=0):Medium(imev,vraboteniv,brLazniVv){
		profil=profilv;
	}

	float presmetajIndeks(){
		float indeks=Medium::presmetajIndeks();
		if(profil){
			indeks+=20;
		}
		return indeks;
	}

	void pechati(){
		Medium::pechati();
		cout<<"Profil: "<<(profil?"ima":"nema")<<endl;
	}
};
class Portal:public Medium{
private:
	int posts;
public:
	Portal(string imev="",int vraboteniv=0,int brLazniVv=0,int postsv=0): Medium(imev,vraboteniv,brLazniVv){
		posts=postsv;
	}

	float presmetajIndeks(){
		float indeks=Medium::presmetajIndeks();
		for(int i=0;i<posts;i=i+20){
			indeks+=indeks*(5/100);
		}
		return indeks;
	}

	void pechati(){
		Medium::pechati();
		cout<<"Broj na postovi: "<<posts<<endl;
	}
};

int pomalIndeks(Medium *A,Medium *B){

	if(A->presmetajIndeks() < B->presmetajIndeks()){
		return 1;
	}else{
		return 0;
	}
}

int najmalIndeks(Medium **niza,int br){
	int pozicija;
	float min=0.0;
	for(int i=0;i<br;i++){
		for(int j=i+1;j<br;j++){
			if(pomalIndeks(niza[i],niza[j])){
				if(niza[i]->presmetajIndeks() < min){
					min=niza[i]->presmetajIndeks();
					pozicija=i;
				}
			}
		}
	}
	return pozicija;
}

int main()
{
Medium *E[4];
Portal G1((char *)"Plusinfo", 8, 20, 150);
Portal G2((char *)"SDK", 10, 2, 100);
Televizija K1((char *)"Alfa", 22, 5, true);
E[0] = &G1; E[1] = &G2; E[2] = &K1;
K1.pechati();
cout<<K1.presmetajIndeks();


E[najmalIndeks(E,3)]->pechati();
return 0;
}

