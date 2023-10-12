/*�� �� ������ ����� Sadnica �� ��� �� ����� �������� ����� ����� Drvo � Cvet. �� �������
Sadnica �� ���� ����� �� ��������� (���� ��������� ���� �� char ��������) � ��������� ����
���� ������� (float).
�� ������� Drvo ������������ �� ���� ����� �� ������ ����� � ����� ������ (int).
�� ������� Cvet ������������ �� ���� ����� �� ������ �� ��� � ��������� ������ (int).
������ �� ������� ������� �� ���������� �� �������� �����: ��������� ���� �� ��������� ��
��������� �� 10% ������� �� ����� ��� ������ �������.
������ �� �������� ������� �� ���������� ���� ��� ��������� ���� �� �������� �� �������� ������� ���� ������� �� 14 ����.
�� ����� �� ������� �� �� ������ ������� presmetaj_cena() ��� �� ���������� ������ ��
����������� ����� �� ��� ����� � ������� pechati() ��� �� ������ ���������� �� ����� ��
����������� ����� � ������ ���� ��� �� �������� �� ��������� �� ���������� ����� �� �� �������
�������� �� ��������� �����. �� ����� �� ������� �� �� ������� � ������������ �� default
���������, copy ����������� � �������� = �� ����������.
������ �� ������� �� �� ������ ������� ��� ���� ��������� ����� ��� ���������: ���� ��
���������� ��� ������� ��������� �� ����� �� ��������� � ������� ���, � �� ���� � �� ������
���� ���������� �� ��������� ��� ��� �������� ����.
�� ����������� � ������ �������� ������� �� ���������� �� ��� ����� �� �� ���������
�������:*/
#include <iostream>
#include <cstring>

using namespace std;


class Sadnica{
protected:
	char *ime;
	float cena;
public:
	Sadnica(char *imev="",float cenav=0.0){
		ime=new char[strlen(imev)+1];
		strcpy(ime,imev);
		cena=cenav;
	}

	Sadnica(const Sadnica &s){
		ime=new char[strlen(s.ime)+1];
		strcpy(ime,s.ime);
		cena=s.cena;
	}

	Sadnica &operator=(Sadnica &s){
		if(this==&s){
			return *this;
		}else{
			delete[] ime;
			ime=new char[strlen(s.ime)+1];
			strcpy(ime,s.ime);
			cena=s.cena;
		}
		return *this;
	}

	void pechati(){
		cout<<"Ime na sadnicata: "<<ime<<",cena: "<<cena;
	}
};

class Drvo : public Sadnica{
private:
	int brMeseci;
public:
	Drvo(char *imev="",float cenav=0.0,int brMeseciv=0) : Sadnica(imev,cenav){
		brMeseci=brMeseciv;
	}

	Drvo(const Drvo &d) : Sadnica(d.ime,d.cena){
		brMeseci=d.brMeseci;
	}

	Drvo &operator=(Drvo &d){
		if(this==&d){
			return *this;
		}else{
			Sadnica::operator =(d);
			brMeseci=d.brMeseci;
		}
		return *this;
	}

	   /* Drvo &operator=(Drvo &s){
        if(this == &s){
            return *this;
        }
        else{
            delete [] ime;
            ime = new char[strlen(s.ime)+1];
            strcpy(ime,s.ime);
            cena = s.cena;
            starost = s.starost;
        }
        return *this;
    }*/

	float presmetaj_cena(){
		for(int i=0;i<brMeseci;i+2){
			cena=cena + (1/10)*cena;
		}
		return cena;
	}

	void pechati(){
		Sadnica::pechati();
		cout<<",starost na drvo (vo meseci):"<<brMeseci;
	}

};

class Cvet : public Sadnica{
private:
	int brDenovi;
public:
	Cvet(char *imev="",float cenav=0.0,int brMeseciv=0,int brDenoviv=0) : Sadnica(imev,cenav){
		brDenovi=brDenoviv;
	}

	float presmetaj_cena(){
		if(brDenovi<14){
			cena= cena/2;
		}
		return cena;
	}

	Cvet(const Cvet &c):Sadnica(c.ime,c.cena){
		brDenovi=c.brDenovi;
	}

	Cvet &operator=(Cvet &c){
		if(this==&c){
			return *this;
		}else{
			Sadnica::operator =(c);
			brDenovi=c.brDenovi;
		}
		return *this;
	}

	void pechati(){
		Sadnica::pechati();
		cout<<",starost na cvet (vo meseci):"<<brDenovi<<endl;
	}
};


int main()
{
    Sadnica *niza[20];
    Drvo m("Lipa",400,12);
    Cvet sl1("Lubicica",300,20),sl2("Krin",400,10);
    niza[0]=&m;
    niza[1]=&sl1;
    niza[2]=&sl2;
    //sl2=sl1; // go komentirav za da go probam presmetaj_cena
    sl2.pechati();
    m.pechati();
    cout<<"Presmetana cena na drvoto:"<<m.Drvo::presmetaj_cena()<<endl;
    cout<<"Presmetana cena na cvetot:"<<sl1.Cvet::presmetaj_cena()<<endl;
    cout<<"Presmetana cena na cvetot: "<<sl2.Cvet::presmetaj_cena()<<endl;;

    //function(niza,3);

    return 0;
}


/*

class Sadnica{
protected:
    char *ime;
    float cena;
public:
    Sadnica(char *imev = "",float cenav = 0.0){
        ime = new char[strlen(imev)+1];
        strcpy(ime,imev);
        cena = cenav;
    }
    Sadnica(const Sadnica &s){
        ime = new char[strlen(s.ime)+1];
        strcpy(ime,s.ime);
        cena = s.cena;
    }
    Sadnica &operator=(Sadnica &s){
        if(this == &s){
            return *this;
        }
        else{
            delete [] ime;
            ime = new char[strlen(s.ime)+1];
            strcpy(ime,s.ime);
            cena = s.cena;
        }
        return *this;
    }
    void pechati(){
        cout<<"Ime na sadnicata: "<<ime<<endl;
        cout<<"Cena na sadnicata: "<<cena<<endl;
    }


};

class Drvo : public Sadnica{
private:
    int starost;
public:
    Drvo(char *imev ="",float cenav=0.0,int starostv=0) : Sadnica(imev,cenav){
        starost = starostv;
    }
    Drvo &operator=(Drvo &s){
        if(this == &s){
            return *this;
        }
        else{
            delete [] ime;
            ime = new char[strlen(s.ime)+1];
            strcpy(ime,s.ime);
            cena = s.cena;
            starost = s.starost;
        }
        return *this;
    }
    int presmetaj_cena(){
    	for(int i =0;i<(starost/2);i++){
    		cena = cena + (1/10)*cena;
    	}
    	return cena;
    }
    void pechati(){
    	Sadnica::pechati();
    	cout<<"Starosta na drvoto: "<<starost<<endl;
    	cout<<endl;
    }
};


class Cvet : public Sadnica{
private:
    int brDenovi;
public:
    Cvet(char *imev="",float cenav=0.0,int brDenoviv=0) : Sadnica(imev,cenav){
        brDenovi = brDenoviv;
    }
    Cvet &operator=(Cvet &s){
        if(this == &s){
            return *this;
        }
        else{
            delete [] ime;
            ime = new char[strlen(s.ime)+1];
            strcpy(ime,s.ime);
            cena = s.cena;
            brDenovi = s.brDenovi;
        }
        return *this;
    }
    float presmetaj_cena(){
      if(brDenovi<14){
          cena = cena/2;
      }
      return cena;
    }
    void pechati(){
    	Sadnica::pechati();
    	cout<<"Broj na denovi: "<<brDenovi<<endl;
    	cout<<endl;
    }
};

int main()
{
    Sadnica *niza[20];
    Drvo m("Lipa",400,12);
    Cvet sl1("Lubicica",300,20),sl2("Krin",400,10);
    niza[0]=&m;
    niza[1]=&sl1;
    niza[2]=&sl2;
    //sl2=sl1; // go komentirav za da go probam presmetaj_cena
    sl2.pechati();
    m.pechati();
    cout<<"Presmetana cena na drvoto:"<<m.Drvo::presmetaj_cena()<<endl;
    cout<<"Presmetana cena na cvetot:"<<sl1.Cvet::presmetaj_cena()<<endl;
    cout<<"Presmetana cena na cvetot: "<<sl2.Cvet::presmetaj_cena()<<endl;;
    return 0;
}*/





