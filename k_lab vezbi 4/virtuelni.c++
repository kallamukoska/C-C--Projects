/*�� �� ������ ��������� �� ����� �� ����� ��������� �� ��������� �� ������� �� ����
������. �� ���� ���� � ������ ��������, ����� �� ������� ��� �� ������� �� ���� � ����������
���� �� �������. ��������� ��������� �� ��������� �� ������ ���� ����� �� ������� �� �� �������
�� ���������� ���� �� �������. ��������� ���� �� ����� ����� ��� �������.
�� ������� �� ���� � ������� �� ����� �� ������ �����. ������ ��������� �� ��������� ��
�������� �����, ����������� �� ������� �� �������� �� 1% �� ����� ������ �����.
�� ��������� �� ���� � ������� �� ��� ���� �������� ����� ��� ����������� ������� ��
���������. ������� ��� ����� �������, ����������� �� ��������� �� �������� �� 15%.
�� ����� �� ������� �� �� ���������� ������������ �� ����������� (default) ��������� �
�����������. �� ����� ����� �� �� �������� ������� presmetajZarabotka() �� ��� ����� ��
���������� ����������� �� ����������� ���� (��� ����������� �� ���������� ����� �� �� ������
��������� presmetajZarabotka() �� ��������� �����).

 ������ �� ������� �� �� ������ �������
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
	int gledachi;
	float prosekCena;
public:
	Film(string naslovv="",int gledachiv=0,float prosekCenav=0.0){
		naslov=naslovv;
		gledachi=gledachiv;
		prosekCena=prosekCenav;
	}

	virtual~Film(){}

	virtual float presmetajZarabotka(){
		float vkzarabotka=gledachi*prosekCena;
		return vkzarabotka;
	}
};

class Akcija: public Film{
private:
	int opasniSceni;
public:
	Akcija(string naslovv="",int gledachiv=0,float prosekCenav=0.0,int opasniSceniv=0):Film(naslovv,gledachiv,prosekCenav){
		opasniSceni=opasniSceniv;
	}

	float presmetajZarabotka(){
		float vkzarabotka=Film::presmetajZarabotka();
		vkzarabotka-=vkzarabotka*(opasniSceni/100);
		return vkzarabotka;
	}
};

class Komedija: public Film{
	bool dogovor;
public:
	Komedija(string naslovv="",int gledachiv=0,float prosekCenav=0.0,bool dogovorv=0):Film(naslovv,gledachiv,prosekCenav){
		dogovor=dogovorv;
	}

	float presmetajZarabotka(){
		float vkzarabotka=Film::presmetajZarabotka();
		if(dogovor){
			vkzarabotka-=vkzarabotka*(15/100);
		}
		return vkzarabotka;
	}
};

int najgolemaZarabotka(Film **niza, int br){
	float max=0.0;
	int pozicija=0;

	for(int i=0;i<br;i++){
		if(niza[i]->presmetajZarabotka() > max){
			max=niza[i]->presmetajZarabotka();
			pozicija=i;
		}
	}
	return pozicija;
}

float vkupnaZarabotka(Film **niza,int br){
	float vkupno=0.0;
	for(int i=0;i<br;i++){
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






