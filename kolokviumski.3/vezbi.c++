// MAGACIN
/*Од тастатура се внесуваат N броеви во неопаѓачки редослед (секој нареден број е поголем или
ист со неговиот претходник) во главната функција. Тие броеви се сместуваат во магацин, исто
така во главната функција. Потоа во истата се внесува карактер (i или d) и се повикува функција
funcRONDC().
Да се напише функцијата funcRONDC() која како аргументи ги добива променливата од тип
магацин и променливата од тип карактер. Функцијата треба да ги избрише дупликатите и ако
карактерната променлива е i да ги испечати броевите во растечки редослед, а ако карактерната
променлива е d да ги испечати броевите во опаѓачки редослед.
Напомена: Како дел од променливата да се дефинира и испише структура за магацин заедно со
функциите потребни за функционирање на магацинот. За решавање на задачата може да се
користи само структурата магацин, односно функциите кои структурата ги има (init, push, peek,
pop, isEmpty, isFull). Притоа, дозволено е користење само на магацини, не смее да се користат
низи. Програмата може да се решава во C или C++ по ваш избор.*/
//    6 7 8 8 10 20
// d: 20 10 8 7 6
// i: 6 7 8 10 20

#include <iostream>

using namespace std;

const int MAX=20;

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

	void dodadiElement(int x){
		if(isFull()){
			cout<<"Funkcijata ne moze da se izvrsi,nema mesto vo magacinot!"<<endl;
			return;
		}
		top++;
		S[top].x=x;
	}

	int izvadiElement(){
		if(isEmpty()){
			cout<<"Vo magacinot ne ostana nisto."<<endl;
			return{};
		}
		int x=S[top].x;
		top--;
		return x;
	}

	int pogledni(){
		if(isEmpty()){
			cout<<"Ne dzirkaj nema nisto !"<<endl;
			return{};
		}
		return S[top].x;
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

void function(magacin magacince,char karakter){
	magacin pomoshen;
	pomoshen.init();
	int el1,el2;

	if(magacince.isEmpty()){
		cout<<"Programata ne moze da se izvrsi, magacinot e prazen."<<endl;
		return;
	}
	// opagjacki
	if(karakter=='d'){
		while(!magacince.isEmpty()){
			el1=magacince.izvadiElement();
			el2=magacince.pogledni();

			if(el1==el2){
				cout<<" "<<el1<<" ";
				el2=magacince.izvadiElement(); //ova e el2
			}else{
				el2=magacince.izvadiElement();
				cout<<" "<<el1<<" "<<el2<<" ";
			}
		}

   // rastecki
	}else if(karakter=='i'){
		while(!magacince.isEmpty()){
		el1=magacince.izvadiElement();
		el2=magacince.pogledni();

		if(el1==el2){
			pomoshen.dodadiElement(el1);
			el2=magacince.izvadiElement();
		}else{
			el2=magacince.izvadiElement();
			pomoshen.dodadiElement(el1);
			pomoshen.dodadiElement(el2);
		}
	}
}

	//pomoshen.pechatiMagacin();

	while(!pomoshen.isEmpty()){
		int broj=pomoshen.pogledni();
		cout<<" "<<broj<<" ";
		pomoshen.izvadiElement();
	}
}

int main(){
	int N,broj, pom, i;
	char c;
	magacin m;
	m.init();

	cout<<"Kolku broevi ke vnesete? (MAX=40) : ";
	cin>>N;
	cout<<"Vnesete gi broevite vo neopagjacki redosled"<<endl;
	cin>>broj;
	m.dodadiElement(broj);
	pom=broj;
	for (i=1;i<N;i++)
	{
	cin>>broj;
	if(broj>=pom)
	{
	m.dodadiElement(broj);
	}
	else
	{
	cout<<"Brojot ne se sovpagja vo neopagjackiot redosled!"<<endl;
	break;
	}
	pom=broj;
	}
	cout<<endl;
	if (i==N)
	{
	cout<<"Vnesete karakter (i ili d): ";
	cin>>c;
	if (c=='d' || c=='i')
	{
	function(m,c);
	}
	else
	cout<<"Vnesovte nevaliden karakter!"<<endl;
	}
	return 0;
	}















