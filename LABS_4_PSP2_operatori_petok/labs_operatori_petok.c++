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

using namespace std;

class Biblioteka{
private:
	string *knigi;
	int brK;
public:
	Biblioteka(string knigiv="Bedni lugje",int brKv=1){
		brK=brKv;
		knigi=new string[brK];
		for(int i=0;i<brK;i++){
			knigi[i]=knigiv[i];
		}
	}

	~Biblioteka(){
		delete[] knigi;
	}

	 bool operator<(Biblioteka &b){
		return (this->brK<b.brK);
	}

	 friend ostream &operator<<(ostream &output,Biblioteka &b){
		 output<<"Broj na knigi: "<<b.brK<<endl;
		 for(int i=0;i<b.brK;i++){
			 output<<b.knigi[i]<<", ";
		 }
		 output<<endl;
		 return output;
	 }

	 Biblioteka &operator=(Biblioteka &b){
		 if(this==&b){
			 return *this;
		 }else{
			 delete[] knigi;
			 knigi=new string[b.brK];
			 this->brK=b.brK;
			 for(int i=0;i<brK;i++){
				 knigi[i]=b.knigi[i];
			 }
		 }
		 return *this;
	 }

	 Biblioteka &operator-=(string naslov){
		 int j=0;
		 string *novaNiza=new string[brK-1];
		 for(int i=0;i<brK;i++){
			 if(knigi[i]!=naslov){
				 novaNiza[j]=knigi[i];
				 j++;
			 }
		 }
		 delete[] knigi;
		 brK--;
		 knigi=novaNiza;
		 return *this;
	 }

	 Biblioteka &operator++(string naslov){
		 string *novaNiza=new string[brK+1];
		 novaNiza[0]=naslov;
		 for(int i=0;i<brK;i++){
			 novaNiza[i+1]=knigi[i];
		 }
		 delete[] knigi;
		 brK++;
		 knigi=novaNiza;
		 return *this;
	 }
};

