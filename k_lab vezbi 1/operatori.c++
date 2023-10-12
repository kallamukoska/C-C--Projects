/*�� �� ������ ����� �� ���� �� ����������. �� ������������ �� ���� ��������� ��������� ���� ��
������� �� ����� (�������� � ������) � ����� �� ����� �� �� ��� �� ������������.
�� �� ��������� �������� ������ �� �������:
� ����������� �� default ��������� �� ������ ���� �� ����� � ��� �� ����� ��
������������. ������� ������������� �� ������ ��� ��������� �� ������ ���������� ��
���� ����� (�� ������ �� ���������� �����).
� ���������� �� �� �� ����� ��������� ����������� �������.
������������ �� �� ������������ �������� ���������:
� ���������� < �� �������� �� ��� ���������� (����� true ��� ������� ������� ��� �����
����� � fasle �� ���������)
� ���������� << �� ������� �� ���� �������� �� ������������.
� ���������� = �� ���������� ����������.
� ���������� -= �� �� ���� �������� �� � ����� ���� ����� ������� � �� ��������� ��
������ �� ������� (������� �� �� ����, �� �� ��������� �����).
� ���������� ++ �� ���������� �������� �� ��� ������ �� �� ������ ���� ����� �������
(���������� �� �� ������� �� ������� �� ������ �� �������).
�� �� ������ ������ �������� �� ��� �� �� ������� �������� �� ���� �������� ������ �
���������������.*/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Biblioteka{
private:
	string *knigi;
	int brKnigi;
public:

	/*Biblioteka(){
		brKnigi=1;
		knigi=new string[1];
		knigi[0]="Bedni lugje";
	}*/

	Biblioteka(string *knigiv=NULL,int brKnigiv=1){
		if(knigiv==NULL){
			knigi=new string[1];
			knigi[0]="Bedni lugje";
			brKnigi=1;
		}else{
			brKnigi=brKnigiv;
			knigi=new string[brKnigi];
			for(int i=0;i<brKnigi;i++){
				knigi[i]=knigiv[i];
			}
		}
	}

	~Biblioteka(){
		delete[] knigi;
	}

	friend istream &operator>>(istream &input,Biblioteka &b){
		delete[] knigi;
		cout<<"Vnesete broj na knigi."<<endl;
		input>>b.brKnigi;
		knigi=new string[b.brKnigi];
		for(int i=0;i<b.brKnigi;i++){
			input>>b.knigi[i];
		}
		return input;
	}

	bool operator<(Biblioteka &B){
		return (brKnigi < B.brKnigi);
	}


	friend ostream &operator<<(ostream &os,Biblioteka &B){
		os<<"Broj na knigi vo bibiliotekata: "<<B.brKnigi<<endl;
		for(int i=0;i<B.brKnigi;i++){
			os<<B.knigi[i]<<",";
		}
		os<<endl;
		return os;
	}

	Biblioteka &operator=(Biblioteka &B){
		if(this==&B){
			return *this;
		}else{
			delete[] knigi;
			brKnigi=B.brKnigi;
			knigi=new string[brKnigi];
			for(int i=0;i<brKnigi;i++){
				knigi[i]=B.knigi[i];
			}
		}
		return *this;
	}

	Biblioteka &operator-=(string naslov){
		int j=0;
		int flag=0;

		for(int i=0;i<brKnigi;i++){
			if(knigi[i]==naslov){
				flag=1;
				break;
			}
		}

		if(flag){
			string *novaNiza=new string[brKnigi-1];
			for(int i=0;i<brKnigi;i++){
				if(knigi[i]!=naslov){
					novaNiza[j]=knigi[i];
					j++;
				}
			}
			brKnigi--;
			delete[] knigi;
			knigi=novaNiza;
			return *this;
		}else{
			return *this;
		}
	}


	Biblioteka &operator+=(string naslov){
		string *novaNiza=new string[brKnigi+1];
		novaNiza[0]=naslov;
		for(int i=0;i<brKnigi;i++){
			novaNiza[i+1]=knigi[i];
		}
		brKnigi++;
		delete[] knigi;
		knigi=novaNiza;
		return *this;
	}
};

int main(){
	string kristina="Kristina";
	string david="Lolita";
	Biblioteka B1;
	string niza[3]={"Lolita","1984","Robinzon Kruso"};
	Biblioteka B2(niza,3);

	cout<<B1;
	cout<<B2;
	B1=B2;
	cout<<B1;

	B2.operator -=(david);
	cout<<B2;

	B1.operator +=(kristina);
	cout<<B1;

	return 0;
}



