//MAGACIN
/*Да се напише функција isPalindrome() која како аргументи прима збор (string) и структура
магацин (каде елементите кои се дел од магацинот имаат член кој е од тип char). Во функцијата
со помош на магацинот да се провери дали зборот е палиндром (да се прави разлика меѓу мала и
голема буква). Проверката да се направи така што прво ќе се измине зборот и сите негови буки
ќе се стават во магацинот, а потоа уште еднаш ќе се измине зборот и паралелно ќе се празни
магацинот. Доколку зборот е палиндром, функцијата треба да врати True, во спротивно False.
Исто така, потребно е да се напише главна програма во која од тастатура ќе се внесува еден збор
и за него потоа да се повика функцијата isPalindrome(). На крај на екран да се испечати дали
внесениот збор е палиндром или не.
Напомена: Како дел од програмата да се дефинира и испише структура за магацин заедно со
функциите потребни за функционирање на магацинот. Програмата може да се решава во C или
во C++ по ваш избор.*/
#include <iostream>
#include <string>

using namespace std;

const int MAX=20;

struct element{
	char x;
};

struct magacin{
	int top;
	element S[MAX];

	void init(){
		top=-1;
	}

	int isEmpty(){
		return top<0;
	}

	int isFull(){
		return top>=MAX-1;
	}

	void dodadiElement(element x){
		if(isFull()){
			cout<<"Funkcijata ne moze da se izvrsi,nema mesto vo magacinot!"<<endl;
			return;
		}
		top++;
		S[top]=x;
	}

	element izvadiElement(){
		if(isEmpty()){
			cout<<"Vo magacinot ne ostana nisto."<<endl;
			return{};
		}
		element x=S[top];
		top--;
		return x;
	}

	element pogledni(){
		if(isEmpty()){
			cout<<"Ne dzirkaj nema nisto !"<<endl;
			return{};
		}
		return S[top];
	}

	void pechatiMagacin(){
		while(!isEmpty()){
			for(int i=0;i<=top;i++){
				cout<<S[i].x<<" ";

				cout<<endl;
			}
		}
	}
};

int daliEPalindrom(magacin &magacince){
	magacin pomoshen;
	pomoshen.init();
	element el1,el2;
	int broj;

	if(magacince.isEmpty()){
		cout<<"Magacinot e prazen,f-jata ne moze da se izvrsi."<<endl;
		return -1;
	}

	while(!magacince.isEmpty()){
		el2=magacince.pogledni();
		pomoshen.dodadiElement(el2);
		el1=magacince.izvadiElement();
		el2=pomoshen.izvadiElement();

		if( el2.x != el1.x){
			break;
		}
	}

	if(magacince.isEmpty() && pomoshen.isEmpty()){
		broj=1;
	}
	return broj;
}
int main(){
string zborot;
magacin magacinot;
magacinot.init();
cout<<"Vnesete zbor za koj sakate da proverite dali e palindrom:"<<endl;
cin>>zborot;

for(int i=0;i<zborot.length();i++){
	element pom;
	pom=zborot[i];
	magacinot.dodadiElement(pom);

}

 int izlez=daliEPalindrom(magacinot);
 cout<<"Zborot e palindrom:1 / zborot NE e palindrom:!=1."<<endl;
 cout<<izlez<<endl;

/*bool izlez = isPalindrome(zborot, magacinot);
cout<<"Zborot "<<(izlez?"":"ne ")<<"e palindrom"<<endl;*/

return 0;
}




/*bool isPalindrome(string zbor, magacin &mag){

for(int i=0; i<zbor.length(); i++){
element pom;
pom.bukva = zbor[i];
mag.push(pom);
}

for(int i=0; i<zbor.length();i++){

element pom = mag.pop();
if(pom.bukva!=zbor[i])
return 0;
}

return 1;
}*/

