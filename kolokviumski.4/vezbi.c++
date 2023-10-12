//MAGACIN
/*�� �� ������ ������� isPalindrome() ��� ���� ��������� ����� ���� (string) � ���������
������� (���� ���������� ��� �� ��� �� ��������� ����� ���� �� � �� ��� char). �� ���������
�� ����� �� ��������� �� �� ������� ���� ������ � ��������� (�� �� ����� ������� ��� ���� �
������ �����). ���������� �� �� ������� ���� ��� ���� �� �� ������ ������ � ���� ������ ����
�� �� ������ �� ���������, � ����� ���� ����� �� �� ������ ������ � ��������� �� �� ������
���������. ������� ������ � ���������, ��������� ����� �� ����� True, �� ��������� False.
���� ����, �������� � �� �� ������ ������ �������� �� ��� �� ��������� �� �� ������� ���� ����
� �� ���� ����� �� �� ������ ��������� isPalindrome(). �� ��� �� ����� �� �� �������� ����
��������� ���� � ��������� ��� ��.
��������: ���� ��� �� ���������� �� �� �������� � ������ ��������� �� ������� ������ ��
��������� �������� �� ������������� �� ���������. ���������� ���� �� �� ������ �� C ���
�� C++ �� ��� �����.*/
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

