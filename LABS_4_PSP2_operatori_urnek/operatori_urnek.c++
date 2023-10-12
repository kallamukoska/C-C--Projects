/*Да се креира класа Recenica која е составена од низа од зборови (динамички алоцирана), и бројот на
зборовите. Да се обезбедат следниве конструктори и методи за класата:
• Конструктор со default параметри кој како аргументи добива низа од зборови и должина на
низата, но ако се повика без аргименти прави низа од еден збор со содржина “default”
• Деструктор кој соодветно ќе ја избрише динамички алоцираната меморија.
Дополнително да се преоптоварат и следниве оператори за работа со низите:
• Операторот << за печатење на сите зборови во реченицата.
• Операторот = за доделување.
• Операторот > кој споредува две решеници и враќа true ако левиот објект има повеќе зборови
од десниот објект во однос на операторот.
• Операторот -= (string zbor) кој го додава зборот zbor на почеток на низата.
• Операторот ++ кој го отстранува последниот збор од низата а е реализиран како постфикс.
• Операторот [] кој го враќа зборот кој се наоѓа во реченицата на соодветната позиција и
дозволува истиот да биде променет.
Напомена: Класата треба да се грижи за мемориско оптимизирање на низата (преку грижа за
динамичката алокација при секоја операција)!
 */

#include <iostream>
#include <cstring>

using namespace std;

class Rechenica{
private:
	string *rechenica;
	int brE;
public:
	Rechenica(){
		rechenica=new string[1];
		rechenica[0]="default";
		brE=1;
	}

	Rechenica(const Rechenica &r){
		brE=r.brE;
		rechenica=new string[brE];
		for(int i=0;i<r.brE;i++){
			rechenica[i]=r.rechenica[i];
		}
	}

	Rechenica(string *rechenicav,int brEv){
		brE=brEv;
		rechenica=new string[brE];
		for(int i=0;i<brE;i++){
			rechenica[i]=rechenicav[i];
		}
	}

	~Rechenica(){
		delete[] rechenica;
	}

	friend ostream &operator<<(ostream &output,const Rechenica &r){
		for(int i=0;i<r.brE;i++){
			output<<r.rechenica[i]<<" ";
		}
		cout<<"Broj na elementi: ";
		output<<r.brE<<endl;

		return output;
	}

	Rechenica &operator=(Rechenica &r){
		if(this==&r)
			return *this;

		delete[] rechenica;
		brE=r.brE;
		rechenica=new string[brE];
		for(int i=0;i<brE;i++){
			rechenica[i]=r.rechenica[i];
		}
		return *this;
	}

	bool operator>(Rechenica &r){
		return brE>r.brE;
	}

	//Операторот -= (string zbor) кој го додава зборот zbor на почеток на низата.
	Rechenica &operator-=(string zbor){
		Rechenica *novaRec=new string[brE+1];
		novaRec[0]=zbor;
		for(int i=0;i<brE;i++){
			novaRec[i+1]=rechenica[i];
		}
		delete[] rechenica;
		brE++;
		rechenica=novaRec;
		return *this;
	}

	//Операторот ++ кој го отстранува последниот збор од низата а е реализиран како постфикс.
	Rechenica &operator++(int){
		Rechenica rech(*this);  // AKO IMAME POST FIKS MORA SO COPY CONSTRUCTOR I RETURN TOJ (THIS)
		Rechenica *novaRec=new string[brE-1];
		for(int i=0;i<brE-1;i++){
			novaRec[i]=rechenica[i];
		}
		delete[] rechenica;
		brE--;
		rechenica=novaRec;
		return rech;
	}

	//Операторот [] кој го враќа зборот кој се наоѓа во реченицата на соодветната позиција и
	//дозволува истиот да биде променет.
	string operator[](int pozicija){
		return rechenica[pozicija];
	}
};




/*#include<iostream>
#include<cstring>

using namespace std;

class Recenica{
private:
	string *recenica;
	int broj;
public:
	Recenica(){
		cout<<"Default Constructor called"<<endl;
		recenica = new string[1];
		recenica[0] = "default";
		broj = 1;
	}
	Recenica(string *recenicaF,int brojF){
		cout<<"Argument Constructor called"<<endl;
		recenica = new string[brojF+1];
		for(int i=0;i<brojF;i++){
			 recenica[i] = recenicaF[i];
		}
		broj = brojF;
	}
	~Recenica(){
		cout<<"~Destructor() called"<<endl;
		delete[] recenica;
	}
	friend ostream &operator<<(ostream &out,Recenica &rec){
		cout<<"Cast operator working..."<<endl;
		for(int i = 0;i<rec.broj;i++){
			out << rec.recenica[i]<<" ";
		}
		out<<endl;
		return out;
	}

	Recenica &operator=(const Recenica &rec){
		cout<<"Equal operator working..."<<endl;
		if(this==&rec){ // obrni vnimanie na ovaj uslov
              return *this;
		}
		else{
        delete [] recenica;
        broj = rec.broj;
        recenica = new string[broj];
        for(int i = 0;i <broj; i++)
        	recenica[i] = rec.recenica[i];

        return *this;
        }
    }

	bool operator>(Recenica &rec){
		cout<<"Comparison operator working..."<<endl;
		return (broj>rec.broj);
	}
	Recenica &operator-=(string zbor){ // dodava broj na pocetok na nizata
		cout<<"Subtraction operator working..."<<endl;
		string *rec = new string[broj+1];
		rec[0] = zbor;
		for(int i = 0;i<broj;i++){
			rec[i+1] = recenica[i];
		}
		broj++;
		delete [] recenica;
		recenica = rec;
		return *this;
	}
	Recenica &operator++(int) { // go brisi posledniot element
		cout<<"Increment operator working..."<<endl;

		string *rec = new string[broj-1];
		for(int i=0;i<broj-1;i++){
			rec[i] = recenica[i];
		}
		delete[] recenica;
		recenica = rec;
		broj--;
		 return *this;
	}
	string &operator[](int pozicija){ // vrati zbor na pozicija na dadeniot indeks
		return this->recenica[pozicija];
	}

};

int main()
{
	string zborovi[6]={"sakam","da","polozam","psp","vo","juni"};
	Recenica r1= Recenica();
	Recenica r2= Recenica(zborovi,6);
	Recenica r3;
	r3=r2;
	cout<<r2;
	cout<<r3;
	r2-="Jas";
	cout<<r2;
	r2++;
	cout<<r2;
	cout<<(r2>r1)<<endl;
	if(r2>r1){
		cout<<"r2 e pogolemo od r1"<<endl;
	}
	else{
		cout<<"r2 e pomalo od r1"<<endl;
	}
	cout<<r2[0]<<endl;
	return 0;
}*/


