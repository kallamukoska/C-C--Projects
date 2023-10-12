/*�� �� ������ ������� ��� ���� ��������� ���+�� ��� ��������� �������. �� ��������� ����� ��
�� ������ ������ ������� � �� ��� �� ���� �� �� ������� ���� ���� �������� ��� ��� �����
����� �� ��������� ����� ���� �������� �� ��������� �� ������� ������� �� ��� �� ��� ��
�����, ������ ������� ����� ������� �� ������ ������� ����� �� �� ������ ����� ��������� ��
���� �������� �� ������� ������� ����� �� �� ��������. ������� ��� �� �������� ��������� 2,
����� �� ���������� ���� ����������� �������� �� ��������� 1.
�� �������� �� �������� ���� �� �� ��������� ���� ���������� �� ��� ��������� �������,
������� ��������� ��� ����������� �� ��� (init, push, peek, pop, isEmpty, isFull). �� ���, �� �� ��
�������� ���������� �� ��������� 1, ����� ������ �� �� �������� ������� �� �������. ������
��������� �� ��� �� �������� ����� �� �� ��������� �� ��������� �� �� ���� ������ �� ���������
2 (��� ������ �� �� ������ �� ��������� 2). ��� ���������� ������� �� ��������� 1 �� � ��� ��
��������� �� � ������ �� ��������� 2, ���������� ��������� �� ��������� 1 �� �� �������� � ��
�� ���� ��������� �� � ������ �� ��������� 2. ���������, ������� ���������� ������� ��
������� 1 � ��� �� ��������� �� � ������ �� ��������� 2, ���������� ������� �� ������� 1 ��
����� �� ��� ������� �������, � ��������� ������� �� ��������� 2 �� ���������� �� ������� 2.
������ ���� �������� �� ������� 1 �� ����� ���������, �� ��������� ������� �� �����
����������� ���������� ��� ����� �� �� �������, � ��� �� ����� �� ����� ������� �� ��������� 1.
�������� �� ��������� � �� ��������� �� ��������� ���� ���� ����� �� �� �������� ���� ��� ��
��������.

������� 1: 7 1 2 3 5 1 5 ������� ������� 1: 1 2 1 5
������� 2: 1 2 1 5 4 5   ������� ������� 2: 4 5 */


#include <iostream>

using namespace std;

const int MAX=30;

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
		if(isEmpty()){
			return;
		}
		top++;
		S[top].x=n;
	}

	int izvadiElement(){
		if(isFull()){
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
		cout<<endl;
	}

	int pogledni(){
		if(isEmpty()){
			return{};
		}

		return S[top].x;
	}
};

void function(magacin m1, magacin m2){
	magacin pomoshen;
	pomoshen.init();
	int izvadenm1;
	int poglednim2;


	if(m1.isEmpty() || m2.isEmpty()){
		cout<<"Funkcijata ne moze da se izvrsi!"<<endl;
		return;
	}

	while(!m1.isEmpty()){
		izvadenm1=m1.izvadiElement();
		poglednim2=m2.pogledni();

		if(izvadenm1==poglednim2){
			pomoshen.dodadiElement(poglednim2);
			m2.izvadiElement();
		}

		while(!pomoshen.isEmpty()){
			m1.dodadiElement(pomoshen.izvadiElement());
		}
	}
}

int main(){
	magacin s1,s2;
	s1.init();
	s2.init();
	int brbr1,brbr2,element;

	cout<<"Vnesete kolku elementi kje ima magacinot 1."<<endl;
	cin>>brbr1;

	for(int i=0;i<brbr1;i++){
		cin>>element;
		s1.dodadiElement(element);
	}

	cout<<"Vnesete kolku elementi kje ima magacinot 2."<<endl;
	cin>>brbr2;

	for(int i=0;i<brbr2;i++){
		cin>>element;
		s2.dodadiElement(element);
	}

	function(s1,s2);

	s1.pechatiMagacin();
	s2.pechatiMagacin();

	return 0;
}










