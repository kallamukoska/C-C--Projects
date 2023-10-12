/* 1.klasa proizvod: private: ime,shifra,zaliha,prodadeno
 public:konstruktori(default, konstruktor so parametri i copy konstruktor),
 get i set f-cii, f-ja za pechatenje.
 2. Funkcija za sortiranje: na default vlezni parametri: zaliha i opagjacki
 3. Glavna funkcija : da prezeme odredeno mnozestvo na proizvodi, da gi sortira i da gi pechati.
 */
#include <iostream>
#include <cstring>
using namespace std;

class proizvod{
private:
	char ime[20]; // char *ime; ( dinamicka alokacija )
	int shifra;
	int zaliha;
	int prodadeno;

public:
	// konstruktor bez parametri
	proizvod(){
		ime[0]='\0';
		shifra=0;
		zaliha=0;
		prodadeno=0;
	}

	proizvod(char *imev,int shifrav,int zalihav,int prodadenov){
		strcpy(ime,imev);
		shifra=shifrav;
		zaliha=zalihav;
		prodadeno=prodadenov;
	}

	// copy constructor
	proizvod(const proizvod &p){
		// proizvod d(a); ->vaka kje go aktivirame
		// privatnite promenlivi od a kje bidat dostapni vo objektot d.
		//prosto za dinamicha alokacija ( no sega nemame dinamicka alokacija )
		strcpy(ime,p.ime);
		shifra=p.shifra;
		zaliha=p.zaliha;
		prodadeno=p.prodadeno;
	}

	void pechati(){
		cout<<ime<<": "<<shifra<<",prodadeno: "<<prodadeno<<",a na zaliha: "<<zaliha<<endl;
	}

	const char *getIme(){
		return ime;
	}

	int getZaliha(){
		return zaliha;
	}

};
void sortirajPoImeRast(proizvod *nizaP,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			// ako e pogolema prvata vrakja 1 , ako se isti 0, ako e pogolema vtorata -1.
			if(strcmp(nizaP[i].getIme(),nizaP[j].getIme())>0){
				// privremen objekt
				proizvod temp=nizaP[i];
				nizaP[i]=nizaP[j];
				nizaP[j]=temp;
			}
		}
	}
}

void sortirajPoImeOpag(proizvod *nizaP,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			// ako e pogolema prvata vrakja 1 , ako se isti 0, ako e pogolema vtorata -1.
			if(strcmp(nizaP[i].getIme(),nizaP[j].getIme())>0){
				// privremen objekt
				proizvod temp=nizaP[i];
				nizaP[i]=nizaP[j];
				nizaP[j]=temp;
			}
		}
	}
}

void sortirajPoZalihaRast(proizvod *nizaP,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(nizaP[i].getZaliha() > nizaP[j].getZaliha()){
				proizvod temp=nizaP[i];
				nizaP[i]=nizaP[j];
				nizaP[j]=temp;
			}
		}
	}
}

void sortirajPoZalihaOpag(proizvod *nizaP,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(nizaP[i].getZaliha() < nizaP[j].getZaliha()){
				proizvod temp=nizaP[i];
				nizaP[i]=nizaP[j];
				nizaP[j]=temp;
			}
		}
	}
}

void sortiranjeNiza(proizvod *nizaP,int n,int kriterium=2,bool pravec=1){
	if(kriterium==0){
		// znaci kje imame sortiranje po ime
		if(pravec==0){
			sortirajPoImeRast(nizaP,n);
		}else{
			sortirajPoImeOpag(nizaP,n);
		}
	}else if(kriterium==2){
			if(pravec==false){
				sortirajPoZalihaRast(nizaP,n);
			}else{
				sortirajPoZalihaOpag(nizaP,n);
			}
	}else{
		cout<<"Takov kriterium seuste ne e implementiran."<<endl;
	}
}


int main(){
	int n;
	proizvod nizaP[30];
	proizvod pom;

	cout<<"Vnesete broj na proizvodsi."<<endl;
	cin>>n;
	cout<<"Vnesete gi imeto,shifrata,kolichinata na zaliha i kolichinata na prodadeni edinici od proizvodot."<<endl;
	for(int i=0;i<n;i++){
		char ime[30];
		int shifra;
		int zaliha;
		int prodadeno;

		cin>>ime>>shifra>>zaliha>>prodadeno;
		nizaP[i]=proizvod(ime,shifra,zaliha,prodadeno);
	}

	cout<<"Vnesete kriterium za sortiranje i pravec."<<endl;
	int krit;
	bool pravec;
	cin>>krit>>pravec;

	sortiranjeNiza(nizaP,n,krit,pravec);

	cout<<"Sortiranata niza e :"<<endl;
	for(int i=0;i<n;i++){
		nizaP[i].pechati();
	}

	return 0;
}









