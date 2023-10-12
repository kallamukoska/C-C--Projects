/*Да се креира класа работа со ливче за спортско обложување. Во ливчето за спортско
обложување се чува динамички алоцирана низа од типувања и бројот на внесени типувања. Секое
типување се состои од две имиња за учесниците во мечот (реализирани како стрингови), тип (може
да биде 0, 1 или 2) и коефициент на добивка. Типувањето да се реализира како структура.
Да се обезбедат следниве методи за класата за работа со ливче за спортско обложување:
• Конструктор со default параметри кој добива низа од типувања и број на типувања
во ливче за спортско обложување. Доколку конструкторот се повика без аргументи се креира
ливче за спортско обложување со 0 типови.
• Деструктор кој ќе ја брише динамички алоцираната меморија.
Дополнително да се преоптоварат следниве оператори:
• Операторот >> за вчитување на сите податоци за ливче за спортско обложување.
• Операторот << за печатење на сите податоци за ливче за спортско обложување.
• Операторот = за доделување на ливче за спортско обложување.
• Операторот > за споредување на две ливче за спортско обложување (ако производот
на коефициентите на добивка на левиот аргумент е поголем од соодветниот
производ на десната страна операторот да врати true инаку да врати false).
• Операторот += кој го ќе додаде типување (кое се дава како десен операнд) на крај од
ливче за спортско обложување.
• Операторот -- кој овозможува бришење на типувањето на крај од низата.
Да се напише главна програма во која ќе се тестира работата на сите креирани методи и
преоптоварувања.*/

#include <iostream>
#include <cstring>

using namespace std;

struct Tipuvanje{
	string ime1,ime2;
	int tip;
	float koef;

	void init(string ime1v,string ime2v,int tipv,float koefv){
		ime1=ime1v;
		ime2=ime2v;
		if(tipv>=0 && tipv<=2){
			tip=tipv;
		}else{
			tip=0;
		}
		koef=koefv;
	}

	void pechati(){
		cout<<ime1<<" "<<ime2<<" tip:"<<tip<<" koeficient na dobivka:"<<koef<<endl;
	}
};

class Livche{
private:
	Tipuvanje *tipuvanja;
	int broj;
public:
	Livche(Tipuvanje *tipuvanjev=NULL,int brojv=0){
		broj=brojv;
		tipuvanja=new Tipuvanje[broj];
		for(int i=0;i<broj;i++){
			tipuvanja[i]=tipuvanjev[i];
		}
	}

	~Livche(){
		delete[] tipuvanja;
	}

	friend istream &operator>>(istream &input,Livche &l){
		cout<<"Vnesete broj na tipuvanja."<<endl;
		input>>l.broj;

		delete[] tipuvanja;
		l.tipuvanja=new Tipuvanje[l.broj];

		cout<<"Vnesete podatoci za tipuvanjata vo livcheto."<<endl;
		for(int i=0;i<l.broj;i++){
			input<<l.tipuvanja[i].ime1>>l.tipuvanja[i].ime2>>l.tipuvanja[i].tip>>l.tipuvanja[i].koef;
		}
		return input;
	}

	friend ostream &operator<<(ostream &output,const Livche &l){
		output<<"Pechatenje na site podatoci za livhce za sportsko oblozuvanje:"<<endl;
		for(int i=0;i<l.broj;i++){
			l.tipuvanja[i].pechati();
		}
		return output;
	}

	Livche &operator=(Livche &l){
		if(this==&l){
			return *this;
		}else{
			broj=l.broj;
			delete[] tipuvanja;
			tipuvanja=new Tipuvanje[l.broj];
			for(int i=0;i<l.broj;i++){
				tipuvanja[i]=l.tipuvanja[i];
			}
		}
		return *this; // ovde mu e napishano bez *
	}

	//Операторот > за споредување на две ливче за спортско обложување (ако производот
	//на коефициентите на добивка на левиот аргумент е поголем од соодветниот
	//производ на десната страна операторот да врати true инаку да врати false).

	bool operator>(Livche &l){
		float p1,p2;
		p1=p2=1;
		for(int i=0;i<this->broj;i++){
			p1*=this->tipuvanja[i].koef;
		}

		for(int i=0;i<l.broj;i++){
			p2*=l.tipuvanja[i].koef;
		}

		return (p1>p2);
	}

	// Операторот += кој го ќе додаде типување (кое се дава како десен операнд) на крај од
	//ливче за спортско обложување.

	Livche &operator+=(Tipuvanje &plusTipuvanje){
		Tipuvanje *novoLivche=new Tipuvanje[broj+1];
		for(int i=0;i<broj;i++){
			novoLivche[i]=tipuvanja[i];
		}
		novoLivche[broj++]=plusTipuvanje;
		delete[] tipuvanja;
		tipuvanja=novoLivche;

		return *this;
	}

	//Операторот -- кој овозможува бришење на типувањето на крај од низата.
	Livche &operator--(int){
		Tipuvanje *novoLivche=new Tipuvanje[broj-1];
		for(int i=0;i<broj-1;i++){
			novoLivche[i]=tipuvanja[i];
		}
		broj--;
		delete[] tipuvanja;
		tipuvanja=novoLivche;
		return *this;
	}



};
































/*#include <iostream>
#include <string>
using namespace std;
struct tipuvanje{
    string i1,i2;
    int tip;
    float koeficient;
    void init(string i1v,string i2v,int tipv,float koeficientv)
    {
        i1=i1v;
        i2=i2v;
        (tipv>0&&tipv<=2)? tip=tipv:tip=0;
        koeficient=koeficientv;
    }
    void pechati()
    {
        cout<<"\t"<<i1<<"-"<<i2<<" tip: "<<tip<<", koeficient: "<<koeficient<<endl;
    }
};
class livce{
    private:
        tipuvanje *niza;
        int broj;
    public:
        livce(tipuvanje *nizav=NULL,int brojv=0)
        {
            broj=brojv;
            niza=new tipuvanje[broj];
            for(int i=0;i<broj;i++)
            {
                niza[i]=nizav[i];
            }
        }
        ~livce()
        {
            delete []niza;
        }
        friend ostream & operator<<(ostream &out,livce &l)
        {
            out<<"tipuvanja od livceto:"<<endl;
            for(int i=0;i<l.broj;i++)
            {
                l.niza[i].pechati();
            }
            return out;
        }
        livce &operator=(livce &l)
        {
            if(this==&l)
            {
                return this;
            }
            broj=l.broj;
            delete []niza;
            niza=new tipuvanje[broj];
            for(int i=0;i<broj;i++)
            {
                niza[i]=l.niza[i];
            }
            return this;
        }
        bool operator>(livce &l)
        {
            float n,n1;
            n=n1=1;
            for(int i=0;i<broj;i++)
            {
                n=niza[i].koeficient;
            }
            for(int i=0;i<l.broj;i++)
            {
                n1=l.niza[i].koeficient;
            }
            return (n>n1);
        }
        livce &operator+=(tipuvanje &t)
        {
            tipuvanje *pom=new tipuvanje[broj+1];
            for(int i=0;i<broj;i++)
            {
                pom[i]=niza[i];
            }
            pom[broj]=t;
            broj++;
            delete []niza;
            niza=pom;
            return *this;
        }
        livce &operator--(int )
        {
            tipuvanje *pom=new tipuvanje[broj-1];
            for(int i=0;i<broj-1;i++)
            {
                pom[i]=niza[i];
            }
            broj--;
            delete []niza;
            niza=pom;
            return *this;
        }
        friend istream &operator>>(istream &in,livce &l)
        {
            cout<<"vnesi broj na tipuvanja"<<endl;
            in>>l.broj;
            delete []l.niza;
            l.niza=new tipuvanje[l.broj];
            for(int i=0;i<l.broj;i++)
            {
                cout<<"vnesi iminja na dvata igraci "<<endl;
                in>>l.niza[i].i1>>l.niza[i].i2;
                cout<<"vnesi tip: ";
                in>>l.niza[i].tip;
                cout<<"vnesi koeficient: ";
                in>>l.niza[i].koeficient;
            }
            return in;
        }


};
int main()
{
    livce l;
    cin>>l;
    cout<<l;


    return 0;
}*/

