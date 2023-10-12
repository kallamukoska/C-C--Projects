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
динамичката алокација при секоја операција)!*/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Recenica{
	string *zborovi;
	int brZ;
public:
	Recenica(string *zboroviv=NULL,int brZv=0){
		if(brZv==1){
			brZ=1;
			zborovi=new string[1];
			zborovi[0]="default";

		}else{
			zborovi=new string[brZv];
			brZ=brZv;
			for(int i=0;i<brZ;i++){
				zborovi[i]=zboroviv[i];
		}
	}
}

	~Recenica(){
		delete[] zborovi;
	}

	Recenica(const Recenica &r){
		zborovi=new string[r.brZ];
		brZ=r.brZ;
		for(int i=0;i<brZ;i++){
			zborovi[i]=r.zborovi[i];
		}
	}

	friend ostream &operator<<(ostream &os,Recenica &r){
		os<<"Broj na zborovi vo rechenicata: "<<r.brZ<<endl;
		for(int i=0;i<r.brZ;i++){
			os<<r.zborovi[i]<<" ";
		}
		os<<endl;
		return os;
	}


	Recenica &operator=(Recenica &r){
		if(this==&r){
			return *this;
		}else{
			delete[] zborovi;
			brZ=r.brZ;
			zborovi=new string[brZ];
			for(int i=0;i<brZ;i++){
				zborovi[i]=r.zborovi[i];
			}
		}
		return *this;
	}

	bool operator>(Recenica &r){
		return (brZ > r.brZ);
	}

	Recenica &operator-=(string zbor){
		string *novaNiza=new string[brZ+1];
		novaNiza[0]=zbor;
		for(int i=0;i<brZ;i++){
			novaNiza[i+1]=zborovi[i];
		}
		brZ++;
		delete[] zborovi;
		zborovi=novaNiza;
		return *this;
	}

	Recenica operator++(int){
		Recenica copy(*this);

		string *novaNiza=new string[brZ-1];
		for(int i=0;i<brZ-1;i++){
			novaNiza[i]=zborovi[i];
		}
		brZ--;
		delete[] zborovi;
		zborovi=novaNiza;
		return copy;
	}

	string &operator[](int pozicija){
		return zborovi[pozicija];
	}
};


int main()
{
string zborovi[6]={"sakam","da","polozam","psp","vo","juni"};
Recenica r1=Recenica();
Recenica r2=Recenica(zborovi,6);
Recenica r3;
r3=r2;
cout<<r2;
cout<<r3;
r2-="Jas";
cout<<r2;
r2-="zbor";
cout<<r2;
cout<< (r2>r1);
r1[0]="Nov";
cout<<r2[0];
return 0;
}






