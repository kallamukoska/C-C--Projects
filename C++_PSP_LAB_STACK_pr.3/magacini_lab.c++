/*�� �� ������ ������� ��� ���� �������� ����� ��������� �������. �� ��������� ����� �� ��
������� ����������� �� �������� ������� �������� �� ���������. �� ������� �� �������� �� ��
����� ���� ��������� ��� ����� ��� �� �������� �� ����.
������, �� �������� �� �������� ���� �� �� ��������� ���� ���������� �� ��� ��������� �������,
������� ��������� ��� ����������� �� ��� (init, push, peek, pop, isEmpty, isFull). �� ���, �� �� ��
�������� ���������� �� ���������, ����� ������ �� �� �������� ���� �� ������ �� ��� �������� ��
���� ������. ���������� �������� �� ����� �� ���� ������ ����� �� ������� �������� �� ��
������� �� ��� ������� �������. ������ ���� �������� �� ������������ ������� �� �����
��������, �� ��������� ������� �� ����� �������� ������������ �������� �� �� ������� ������
��������, � ��� �� ����� �� ����� ������� �� ������������ �������. �������� �� ��������� � ��
��������� �� ��������� ���� ���� ����� �� �� �������� ���� ��� �� ��������.
�������: 7 1 2 1 5 1 ������� �������: 1 7 1 2 1 5  */

#include <iostream>

using namespace std;

const int MAX=10;

struct element{
	int x;
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

	void dodadiElement(int n){
		if(isFull()){
			return;
		}

		top++;
		S[top].x=n;
	}

	int izvadiElement(){
		if(isEmpty()){
			return{};
		}

		int n=S[top].x;
		top--;
		return n;
	}

	void pechatiMagacin(){
		for(int i=0;i<=top;i++){
			cout<<S[i].x<<" ";
		}
	}

	int pogledni(){
		if(isEmpty()){
			return{};
		}
		return S[top].x;
	}
};

void function(magacin &m){
	magacin pomoshen;
	pomoshen.init();
	int el1,el2;

	if(m.isEmpty()){
		cout<<"Magacinot e prazen,funkcijata ne moze da se izvrsi!"<<endl;
		return;
	}

	while(!m.isEmpty()){
		// ALGORITAM ZA VADENJE PO PAR
		el1=m.izvadiElement();//go vadime prviot element
		el2=m.izvadiElement();//go vadime vtoriot element i gi stavame vo promenlivi

		pomoshen.dodadiElement(el2);//vo pomoshen go dodavame vtoriot element (prvo)
		pomoshen.dodadiElement(el1);//go dodavame prviot element (vtoro)
	}

	while(!pomoshen.isEmpty()){
		m.dodadiElement(pomoshen.izvadiElement());
	}
}


int main(){
	magacin s;
	int brbr,element;
	s.init();

	cout<<"Vnesete kolku elementi ima vasiot magacin."<<endl;
	cin>>brbr;

	for(int i=0;i<brbr;i++){
		cin>>element;
		s.dodadiElement(element);
	}

	function(s);
	s.pechatiMagacin();

	return 0;
}

















