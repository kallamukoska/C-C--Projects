/* operator =
 operator ++
 operator <<
 operator +=
 operator <<
 */

#include <iostream>
#include <cstring>

using namespace std;

class Uchenik{
private:
	char *ime;
	float prosek;
	int godina;
public:
	Uchenik(char *imev="",float prosekv=0.0,int godinav=0){
		ime=new char[strlen(imev)+1];
		strcpy(ime,imev);
		prosek=prosekv;
		godina=godinav;
	}

	~Uchenik(){
		delete [] ime;
	}

	Uchenik(const Uchenik &u){
		ime=new char[strlen(u.ime)+1];
		strcpy(ime,u.ime);
		prosek=u.prosek;
		godina=u.godina;
	}


	// operator del od klasa
	// operatorot za dodeluvanje
	// a=b <=> a.operator(b)
	Uchenik & operator=(Uchenik &u){
		// nema potreba da kopirame
		if(this==&u)
			return *this;

		delete [] ime;
		ime=new char[strlen(u.ime)+1];
		strcpy(ime,u.ime);
		prosek=u.prosek;
		godina=u.godina;

		return *this;
	}

	// operator ++ za zgolemuvanje na skolskata godina
	// prefiks
	Uchenik & operator++(){
		godina++;
		return *this;
	}

	//operatorot za pechatenje ne moze da bide vnatre vo klasata
	// globalna funkcija
	friend ostream & operator<<(ostream &Os,Uchenik &u){
		Os<<"Ime: "<<u.ime<<endl;
		Os<<"Prosek: "<<u.prosek<<endl;
		Os<<"Godina: "<<u.godina<<endl;

		return Os;
	}
};

class Paralelka{
private:
	Uchenik *ucenici;
	int brU;
public:
	Paralelka(Uchenik *uceniciv=NULL,int brUv=0 ){
		brU=brUv;
		ucenici=new Uchenik[brU];
		for(int i=0;i<brU;i++){
			// sega go napishavme operatorot za dodeluvanje
			ucenici[i]=uceniciv[i];
		}
	}

	~Paralelka(){
		delete[] ucenici;
	}

	Paralelka(const Paralelka &P){
		brU=P.brU;
		ucenici=new Uchenik[P.brU]; // ili samo [brU] bidejkji sme go dodelile
		for(int i=0;i<brU;i++){
			ucenici[i]=P.ucenici[i];
		}
	}

	Paralelka operator++(int){
		// lokalna kopija
		Paralelka temp(*this);

		for(int i=0;i<brU;i++){
			//go povikuvame ++ operatorot
			++ucenici[i];
		}

		return temp;
	}

	Paralelka & operator+=(Uchenik &u){
		// ni treba nova kopija od samata niza
		Uchenik *nova=new Uchenik[brU+1]; // bidejkji kje dodademe eden ucenik na kraj

		for(int i=0;i<brU;i++){
			nova[i]=ucenici[i];
		}
		nova[brU]=u;
		brU++;
		delete[] ucenici;
		ucenici=nova;
		return *this;
	}

	// ova funkcija si koristi nezavisno od klasata
	friend ostream & operator<<(ostream &Os, Paralelka &P){
		Os<<"Paralelkata ima "<<P.brU<<" uchenici: "<<endl;
		for(int i=0;i<P.brU;i++){
			Os<<i+1<<". "<<P.ucenici[i];
		}
		return Os;
	}
};


int main(){
	Uchenik nizaU[3]={{"Pero",5.0,3},{"Stojan",4.5,3},{"Ana",4.7,3}};
	Uchenik U("Vera",4.3,3);

	Paralelka P(nizaU,3);
	cout<<P;

	P+=U;

	P++;

	cout<<P;









	return 0;
}



