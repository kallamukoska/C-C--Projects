/*�� �� ������ ��������� �� ����� �� ����� ��������� �� ��������� �� ������� �� ����
������. �� ���� ���� � ������ ��������, ����� �� ������� ��� �� ������� �� ���� � ����������
���� �� �������. ��������� ��������� �� ��������� �� ������ ���� ����� �� ������� �� �� �������
�� ���������� ���� �� �������. ��������� ���� �� ����� ����� ��� �������.
�� ������� �� ���� � ������� �� ����� �� ������ �����. ������ ��������� �� ��������� ��
�������� �����, ����������� �� ������� �� �������� �� 1% �� ����� ������ �����.
�� ��������� �� ���� � ������� �� ��� ���� �������� ����� ��� ����������� ������� ��
���������. ������� ��� ����� �������, ����������� �� ��������� �� �������� �� 15%.
�� ����� �� ������� �� �� ���������� ������������ �� ����������� (default) ��������� �
�����������.

 �� ����� ����� �� �� �������� ������� presmetajZarabotka() �� ��� ����� ��
���������� ����������� �� ����������� ���� (��� ����������� �� ���������� ����� �� �� ������
��������� presmetajZarabotka() �� ��������� �����). ������ �� ������� �� �� ������ �������
najgolemaZarabotka() ��� ����� ��� ���������: ���� �� ���������� ��� ������� � �������
���. ��������� najgolemaZarabotka() ����� �� �� ����� ������� ��� �� ������ �� ��������
���������. ������������, ������ �� ������� �� �� ������ � ������� vkupnaZarabotka() ���
����� ��� ���������: ���� �� ���������� ��� ������� � ������� ���, � �� ����� �� �����
�������� ��������� �� ���� ������� (��������� �� ����� �� ���������).
���������: �������� �������� � ������ �� �����������.*/

#include <iostream>
#include <string>
using namespace std;

class Film{
protected:
	string naslov;
	int brG;
	int cena;
public:
	Film(string naslovv="",int brGv=0,int cenav=0){
		naslov=naslovv;
		brG=brGv;
		cena=cenav;
	}

	virtual~Film(){}

	virtual int presmetajZarabotka(){
		return cena*brG;
	}



};

class Akcija:public Film{
private:
	int opasniS;
	public:
	Akcija(string naslovv="",int brGv=0,int cenav=0,int opasniSv=0):Film(naslovv,brGv,cenav){
		opasniS=opasniSv;
	}

	int presmetajZarabotka(){
		int zarabotkavk=Film::presmetajZarabotka();
		for(int i=0;i<opasniS;i++){
			zarabotkavk-=zarabotkavk*(1/100);
		}
		return zarabotkavk;
	}

};

class Komedija:public Film{
private:
	bool dogovor;
public:
	Komedija(string naslovv="",int brGv=0,int cenav=0,bool dogovorv=0):Film(naslovv,brGv,cenav){
		dogovor=dogovorv;
	}

	int presmetajZarabotka(){
		int zarabotkavk=Film::presmetajZarabotka();
		if(dogovor){
			zarabotkavk=zarabotkavk-zarabotkavk*(15%100);
			return zarabotkavk;
		}else{
			return zarabotkavk;
		}
	}
};


//��������� najgolemaZarabotka() ����� �� �� ����� ������� ��� �� ������ �� �������� ���������.
//DVOEN POKAZUVAC, POKAZUVAC KON NIZA
int najgolemaZarabotka(Film **niza,int brbr){
	int maxZarabotka=0;
	int pozicija;
	for(int i=0;i<brbr;i++){
		if(niza[i]->presmetajZarabotka()>maxZarabotka){
			pozicija=i;
			maxZarabotka=niza[i]->presmetajZarabotka();
		}
	}
	return pozicija;
}

int vkupnaZarabotka(Film **niza,int brbr){
	int vkupno=0;
	for(int i=0;i<brbr;i++){
		vkupno+=niza[i]->presmetajZarabotka();
	}
	return vkupno;
}

int main()
{
Film *E[4];
Komedija G1((char *)"Hangover", 100000, 5, false);
Komedija G2((char *)"Borat", 90000, 5, true);
Akcija K1((char *)"Mission impossible", 500000, 6, 20);
Akcija K2((char *)"Avengers", 3500000, 4, 30);
E[0] = &G1; E[1] = &G2; E[2] = &K1; E[3] = &K2;
cout<<"Najgolema zarabotka ima filmot so indeks "<<najgolemaZarabotka(E,4)<<endl;
cout<<"Vkupnata zarabotka na studioto iznesuva "<<vkupnaZarabotka(E,4)<<endl;
return 0;
}


