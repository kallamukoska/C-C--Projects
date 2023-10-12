/*Да се напише програма за обработка на текст. За таа намена, да се креира класа Rechenica во која
се чуваат податоци за нејзините елементи: зборовите и интерпункциските знаци во реченицата
(динамички алоцирана низа од стрингови) и број на елементи во реченицата. За класата Rechenica
да се напише:
- Default конструктор кој ќе креира реченица со два елементи “Zdravo” и “!”.
- Copy конструктор и конструктор со 2 аргументи.
- Деструктор
- Функција pechati() која ја печати реченицата
- метод dodadiElement(string m) кој ќе го додаде елемент (збор или интерпункциски знак) на крај
од реченицата.
- метод brishiElement(int poz) кој ќе го избрише елементот на позиција poz
Да се напише main во кој ќе се тестира задачата. Во main функцијата прво да се креира низа од
елементи на реченицата “Mnogu sakam da ucham PSP!” (одвојувањето на елементите може да се
направи рачно). Потоа со низата од елементи да се иницијализира објект од класа Rechenica и да се
испечати реченицата. Потоа на објектот да му се додадат елементите од следната подреченица “za
copy konstruktor.”. Потоа од реченицата да се избрише елементот на позиција 5 и да се испечати
реченицата.*/

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
