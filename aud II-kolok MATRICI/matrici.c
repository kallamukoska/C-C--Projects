/*
 * MATRICI.c
 *
 *  Created on: 9.12.2021
 *      Author: User
 */
/* PRVA.OGLEDALO VO ODNOST NA HORIZONTALATA

#include<stdio.h>
#include<math.h>

#define max 100
int main (){
	int mat[max][max];
	int i,j,n,m;
	int pom;

	printf("Vnesete dimenzii na matricata:\n");
	fflush(stdout);
	scanf("%d %d",&m,&n);

	printf("Vnesete ja matricata:\n");
	fflush(stdout);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}

	for(i=0;i<m/2;i++){ // MORA M/2 !!! zamena, mora pomosna promenliva ! zapamti
		for(j=0;j<n;j++){
			pom=mat[i][j];
			mat[i][j]=mat[m-1-i][j];
			mat[m-1-i][j]=pom;
		}
	}

	printf("Matricata e :\n");
	for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				printf("%d\t",&mat[i][j]);
			}
			printf("\n");
	}
return 0;
}
*/




#include<stdio.h>
#include<math.h>

#define max 100

// m x n
// site elemnti vo mattricata da se pridvizat vo desno.
/*
 * | 1 2 3 |       | 9 1 2 |
 * | 4 5 6 |  ---> | 3 4 5 |
 * | 7 8 9 |       | 6 7 8 |
 */

 int main (){
	int mat[max][max];
	int i,j,m,n,k;
	int pom;

	printf("Vnesete dimenzii na matricata:\n");
	fflush(stdout);
	scanf("%d %d",&m,&n);

	printf("Vnesete ja matricata:\n");
	fflush(stdout);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}

	/*
	 * | 1 2 3 |       | 9 1 2 |
	 * | 4 5 6 |  ---> | 3 4 5 |
	 * | 7 8 9 |       | 6 7 8 |
	 */

	// 9kata racno,site drugi treba da se najde nacin,koj element kade treba da dvizi

	pom=mat[m-1][n-1];
	//pridvizuvanje na site elementi osven 9kata
	// mat ni e so dimenzii n i m -> brojot na elementi e m*n -1 ( bez 9kATA)
	// m=3 n=3 k=3*3-1=8 (matricata vo memorija e kako niza)
	// 1,2,3,
	// 4,5,6,
	// 7,8,9,
	for(k=n*m-1;k>0;k--){//br na pomestuvanja // k=8,7,.....1
		printf("%d %d %d %d %d %d \n",k,k/n,k%n,mat[k/n][k%n],mat[(k-1)/n][(k-1)%n]);
		mat[k/n][k%n]= mat[(k-1)/n][(k-1)%n];

	}
	mat[0][0]=pom;

	printf("Matricata e:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d\t",mat[i][j]);
			}
		printf("\n");
	}
return 0;
}


  /*// CETVRTA-DIJAGONALI
  #include<stdio.h>
  #include<math.h>

  #define max 100
  int main (){
  	int mat[max][max];
  	int i,j,m,n,k;
  	int suma,p;

  	printf("Vnesete dimenzii na matricata:\n");
  	fflush(stdout);
  	scanf("%d %d",&m,&n);

  	printf("Vnesete ja matricata:\n");
  	fflush(stdout);
  	for(i=0;i<m;i++){
  		for(j=0;j<n;j++){
  			scanf("%d",&mat[i][j]);
  		}
  	}

  	for(i=0;i<n;i++){ //site redici kaj koi moze da se pravi proverka
  		// bidejkji imaat elementi levo od sporednata dijagonala

  		//glavna dijagonala -> i da e ednakvo na j
  		//sporednata dijagonala -> i+j da e ednakvo na n-1
  		suma=0;
  		//ako treba da gi sobereme elementite levo od sporedna dijagonala -> i+j < n-1
  		//ako treba da gi sobereme elementite desno od sporedna dijagonala -> i+j > n-1

  		for(j=0;(i+j)<n-1;j++){
  			suma+=mat[i][j];
  		}
  		// sumata na elementi levo od sporednata dijagonala za ovaa redica
  		if(suma!=mat[i][j]){ //j i+j=n-1 -> j=n-1-i;
  			p=0;
  			break; //ako edna ne ispolnuva site ne go ispolnuvaat
  		}
  	}
  	if(p){
  		printf("da.");
  	}else {
  		printf("ne.");
  	}

  	printf("Matricata e :\n");
  		for(i=0;i<m;i++){
  				for(j=0;j<n;j++){
  					printf("%d\t",&mat[i][j]);
  				}
  				printf("\n");
  		}

  return 0;
  }

  */


 /* PETTA.
 #include<stdio.h>
 #include<math.h>

 #define MAX 100
 int main(){
 	int m,n,i,j,k;
 	int a[MAX][MAX];
 	int kolku,prov;

 	printf("Vnesete gi dimenziite na matricata.\n");
 	fflush(stdout);
 	scanf("%d%d",&n,&m);

 	printf("Vnesete gi elementite na matricata.\n");
 	fflush(stdout);
 	for(i=0;i<n;i++){
 		for(j=0;j<m;j++){
 			scanf("%d",&a[i][j]);
 		}
 	}

 	printf("Sodrzinata na matricata e :\n");
 	for(i=0;i<n;i++){
 			for(j=0;j<m;j++){
 				printf("%d\t",a[i][j]); //  \t:tab space
 			}
 			printf("\n");
 		}
 	// element sto se pojavuva vo redovite barem po ednas (treba da se proveri dali postoi barem eden element)
 	/* 1 2 3
 	 * 2 5 7
 	 * 1 2 7
 	 */
 	// za sekoj element od prvata redica kje proverime dali go ima kako element vo sekoja od ostanatite redici
 	// k -> ni go dvizi sekoj element od prvata redica
 	// i -> sekoja preostanata redica od matricata
 	// j -> go dvizi sekoj element po kolona vo ostanatite redici
     /*
    kolku=0;
 	for(k=0;k<m;k++){//za sekoj element po kolona vo redicata so indeks 0, sakame da vidime sto se slucuva so toj element
 		for(i=1;i<n;i++){
 			prov=0; // pretpostavuvame deka nema
 			for(j=0;j<m;j++){
 				if (a[0][k]==a[i][j]){
 					prov=1;
 					break;
 				}
 			}
 			// ako jas vo ovaa redica najdov element,treba da odam na sledna
 			if(prov==0){
 				break;
 			}
 		}
 		if(prov==1){
 			printf(" Elementot %d go ispolnuva uslovot.\n", a[0][k]);
 			kolku++;
 		}
 	}
 	if(kolku==0){
 		printf(" Greska .\n");
 	}

 return 0;
 }
 */


