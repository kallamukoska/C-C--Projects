/*�� �� ������ �������� �� ��������� �� �����. �� ��� ������, �� �� ������ ����� Recenica �� ���
�� ������ ������� �� ���������� (��������� ��������� ���� �� char ��������). �� ������� Korisnik
�� �� ������:
- Default ����������� �� �� ������ Recenica �� �������� �Zdravo!�.
- Copy ����������� � ����������� �� 1 ��������.
- ����������
- ������� pechati() ��� ja ������ ����������
- ����� dodadiZnaci(char *niza, bool lok) �� �� �� ������ niza �� �������� � ��� �� ��� ��� lok � 1
� �� ������� ��� lok � 0.
- ����� brishiZnak(int poz) �� �� �� ������� ������ �� �� ���� �� ������� poz.
�� �� ������ main �� �� �� �� ������� ��������. �� main ��������� ���� �� �� ������ ���� ��
�Mnogu sakam da ucham PSP!� � ����� �� ������ �� �� ������������ ����� �� ����� Rechenica � ��
�� �������� ����������. ����� �� ������� �� �� �� ������ ������� ���� �� ����� �za copy
konstruktor.� �� ��� �� ������. ����� �� ���������� �� �� ������� ������ �� ������� 24 � �� ��
�������� ����������.*/


#include <iostream>
#include <cstring>
using namespace std;

class Rechenica{
private:
	char *rechenica;
public:
	Rechenica(){
		rechenica=new char[7];
		strcpy(rechenica,"Zdravo!");
	}

	Rechenica(char *rechenicaV){
		rechenica=new char[strlen(rechenicaV)+1];
		strcpy(rechenica,rechenicaV);
	}


	Rechenica(const Rechenica &r){
		rechenica=new char[strlen(r.rechenica)+1];
		strcpy(rechenica,r.rechenica);
	}

	~Rechenica(){
		delete [] rechenica;
	}

	void pechati(){
		// VAKA MOZAM DA PECHATAM CHAR !
		cout<<rechenica<<endl;
	}

	void dodadiZnaci(char *niza, bool lok){
		char *novaRec=new char[strlen(rechenica)+strlen(niza)+1];
		strcpy(novaRec,"");
		if(lok){
			// strcat DODAVA NA KRAJ
			// strcat(char *destination, const char *source)
			strcat(novaRec,rechenica);
			strcat(novaRec,niza);
		}else{
			strcat(novaRec,niza);
			strcat(novaRec,rechenica);
		}

		delete[] rechenica;
		rechenica=novaRec;
	}

	void brishiZnak(int poz){
		int j=0;
		char *novaRec=new char[strlen(rechenica)];  // NE TREBA OVDE -1,bez toa sto ne pisuvame +1, si se namaluva za 1
		strcpy(novaRec,"");

		int dolzhina=strlen(rechenica);
		// I CHAR I STRING SO FOR
		for(int i=0;i<dolzhina;i++){
			if(i!=(poz-1)){
				novaRec[j]=rechenica[i];
				j++;
			}
		}


		novaRec[dolzhina-1]='\0';

		delete[] rechenica;
		rechenica=novaRec;
	}

	/*    void brishiZnak(int poz){
    	char *novaRec=new char[strlen(rechenica)];
    	strcpy(novaRec,"");
    	for(int i=0; i<poz; i++){
    		novaRec[i]=rechenica[i];
    	}
    	int dolzina=strlen(rechenica);
    	for(int i=poz+1; i<dolzina; i++){
    		novaRec[i-1]=rechenica[i];
    	}
    	novaRec[dolzina-1]='\0';
    	delete rechenica;
    	rechenica=novaRec;
    }*/

};

int main(){
	char *Niza="Mnogu sakam da ucam PSP!";
	char *extra=" za copy constructor.";

	Rechenica r(Niza);
	r.pechati();

	r.dodadiZnaci(extra, 1);
	r.pechati();

	r.brishiZnak(24);
	r.pechati();

	return 0;
}
