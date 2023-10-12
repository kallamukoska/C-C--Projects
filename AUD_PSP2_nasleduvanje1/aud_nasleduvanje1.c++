#include <iostream>
#include <cstring>

using namespace std;

class Igrach{
	//protected vs private
protected:
	string ime;
	string prezime;
	bool liga;
public:
	Igrach(string ime="",string prezime="",bool liga=true){
		this->ime=ime;
		this->prezime=prezime;
		this->liga=liga;
	}

	friend ostream &operator<<(ostream &output,Igrach &I){
		output<<I.ime<<" "<<I.prezime<<(I.liga?"igra vo liga.":"ne igra vo liga.")<<endl;
		return output;
	}

};

// nasleduvanje
class ATPIgrach: public Igrach{
private:
	// ne smeat da gi povtoruvaat clenovite od osnovnata klasa
	int rang; // kako extra promenliva
public:
	ATPIgrach(string ime="",string prezime="",bool liga=true,int rangv=1):Igrach(ime,prezime,liga){
		// ne treba da gi inicijalizirame osnovnive clenovi samo povikuvame konstruktor
		rang=rangv;
	}

	friend ostream &operator<<(ostream &output,ATPIgrach &A){
		Igrach I(A);
		output<<I;
		output<<"Igrachot e so ATP rang: "<<A.rang<<endl;
		return output;
	}
};

int main(){
	Igrach I("Daniel","Medvedev",true);
	ATPIgrach A("Novak","Gjokovich",true,1);

		cout<<I;
		cout<<A;



	return 0;
}
