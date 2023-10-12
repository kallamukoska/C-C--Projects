#include <iostream>
using namespace std;

const int pi=3.14;

class Tochka{
protected: // za da moze da pristapime do (private) istite
	int x,y;
public:
	Tochka(int xv=0,int yv=0){
		x=xv;
		y=yv;
	}

	void pechati(){
		cout<<"("<<x<<", "<<y<<")"<<endl;
	}
};

class Krug: public Tochka{
protected:
	float r;
public:
	Krug(int xv=0,int yv=0,float rv=0): Tochka(xv,yv){
		r=rv;
	}

	float ploshtina(){
		return r*r*pi;
	}

	void pechati(){
		cout<<"Radius: "<<r<<endl;
		cout<<"Centar: ";
		Tochka::pechati();
	}
};

class Sfera: public Krug{
private:
	int z;
public:
	Sfera(int xv=0,int yv=0,float rv=0,int zv=0):Krug(xv,yv,rv){
		z=zv;
	}

	float ploshtina(){
		return Krug::ploshtina()*4;
	}

	float volumen(){
		return ploshtina()*r/3;
		// return Krug::ploshtina()*4*r/3;
	}

	void pechati(){
		cout<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
		cout<<"Radius: "<<r<<endl;
		cout<<"Ploshtina: "<<ploshtina()<<endl;
		cout<<"Volumen: "<<volumen()<<endl;
		cout<<"Ploshtinata samo na krug koj e presek niz centarot na sferata: "<<Krug::ploshtina()<<endl;

	}
};

int main(){
	Tochka T(3,4);
	Krug K(3,4,2.15);
	Sfera S(3,4,2.15,5);

	T.pechati();
	K.pechati();
	S.pechati();



	return 0;
}

// ako vo krug imavme private a ne protected, x y nema da mozeme da gi koristime pr vo Sfera
// ili treba protected ili ako se private da napravime int getX i int getY


















