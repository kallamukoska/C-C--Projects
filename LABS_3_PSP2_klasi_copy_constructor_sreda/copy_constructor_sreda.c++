/*�� �� ������ �������� �� ��������� �� �����. �� ��� ������, �� �� ������ ����� Rechenica �� ���
�� ������ �������� �� �������� ��������: ��������� � ���������������� ����� �� ����������
(��������� ��������� ���� �� ���������) � ��� �� �������� �� ����������. �� ������� Rechenica
�� �� ������:
- Default ����������� �� �� ������ �������� �� ��� �������� �Zdravo� � �!�.
- Copy ����������� � ����������� �� 2 ���������.
- ����������
- ������� pechati() ��� �� ������ ����������
- ����� dodadiElement(string m) �� �� �� ������ ������� (���� ��� �������������� ����) �� ���
�� ����������.
- ����� brishiElement(int poz) �� �� �� ������� ��������� �� ������� poz
�� �� ������ main �� �� �� �� ������� ��������. �� main ��������� ���� �� �� ������ ���� ��
�������� �� ���������� �Mnogu sakam da ucham PSP!� (����������� �� ���������� ���� �� ��
������� �����). ����� �� ������ �� �������� �� �� ������������ ����� �� ����� Rechenica � �� ��
�������� ����������. ����� �� ������� �� �� �� ������� ���������� �� �������� ����������� �za
copy konstruktor.�. ����� �� ���������� �� �� ������� ��������� �� ������� 5 � �� �� ��������
����������.*/

#include <iostream>
#include <cstring>

using namespace std;

class rechenica{
	string *recenica;
	int brElementi;
public:
	rechenica(){
		recenica=new string[2];
		recenica[0]="Zdravo";
		recenica[1]="!";
		brElementi=2;
	}

	rechenica(string *recenicav,int brElementiv){
		brElementi=brElementiv;
		recenica=new string[brElementiv+1];
		for(int i=0;i<brElementi;i++){
			recenica[i]=recenicav[i];
		}
	}

	rechenica(const rechenica &r){
		brElementi=r.brElementi;
		recenica=new string[r.brElementi+1];
		for(int i=0;i<brElementi;i++){
			recenica[i]=r.recenica[i];
		}
	}

	~rechenica(){
		delete[] recenica;
	}

	void pechati(){
		cout<<"Recenicata e : ";
		for(int i=0;i<brElementi;i++){
			cout<<recenica[i]<<" ";
		}
		cout<<endl;
	}

	void dodadiElement(string m){
		string *novaRecenica=new string[brElementi+1];
		for(int i=0;i<brElementi;i++){
			novaRecenica[i]=recenica[i];
		}
		delete[] recenica;
		novaRecenica[brElementi++]=m;
		recenica=novaRecenica;
	}

	void brishiElement(int poz){
		int j=0;
		string *novaRecenica=new string[brElementi-1];
		for(int i=0;i<brElementi;i++){
			if(i!=(poz-1))
            {
				novaRecenica[j]=recenica[i];
				j++;
            }
		    }
		brElementi--;
		delete[] recenica;
		recenica=novaRecenica;
	}

};

int main(){
	string niza[5]={"Mnogu", "sakam", "da", "ucham", "PSP!"};
	rechenica rec(niza,5);
	string podRec[3]={"za","copy","konstruktor."};

	rec.pechati();

	for(int i=0;i<3;i++){
		rec.dodadiElement(podRec[i]);
	}
	rec.pechati();


	rec.brishiElement(5);
	rec.pechati();


	return 0;
}





/*void brishiElement1(int poz)
{
    int j=0;
    string *novaRecenica=new string[brElementi-1];
    for(int i=0;i<poz-1;i++)
    {
        novaRecenica[i]=recenica[i];
        j++;
    }
    for(int i=poz;i<brElementi;i++)
    {
        novaRecenica[j]=recenica[i];
        j++;
    }

    brElementi--;
	delete[] recenica;
	recenica=novaRecenica;
}*/
