#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;


int main() {
int p ;


    // Daten aus datei einlesen 
    int n, i, j, N;
    cout<< "Which dimension do u want? (n)";
    cin >> n ;
    N=n ;
    
    double h=1.0/(n+1);
    double x[n+1];
    double matrix[n][n] ;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
  		 matrix[i][i]=2 ;
  		 matrix[i-1][i]=-1;
  		 matrix[i+1][i]=-1;
    //Vektor einlesen
    double vektor[N][2] ; 
    for(int i=0;i<N ; i++)
    vektor[i][1]=h*h*(100*exp(-10*i*h));
	

    /*
    cout << "Die gegebene n x n Matrix A mit n = " << N << " ist:" << endl ;
    for(int i=0;i<N;i++)
	{
			for(int j=0;j<N;j++)
    	cout << setw(4) << matrix[i][j] ;
    	cout << endl;
	}
	cout << "Der gegebene Vektor b ist: " << endl ;
	
	for(int i=0; i<N ; i++){
		cout << setw(4) << vektor[i][1] << endl ;
	}
*/

// BEGIN DER BERECHNUNGEN !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


double matrixtmp[N][N], vektortmp[N][2];
int k ;
cout << "Wollen Sie den Algorithmus zur numerischen Optimierung benutzen? (Zeilentausch)" << endl;
char antwort = ' ';  

cout<<"Ja (j) /Nein (n): "; 
cin>>antwort; 



for(int a=0 ; a<N ; a++){
//tauschen
cout << "N ist "<< N ;
if (antwort == 'j') {
for(int i=1+a ; i<N; i++){
	if(matrix[a][a]<matrix[i][a]){
		for(int k=0; k<N ; k++){
		matrixtmp[a][k]=matrix[a][k];
		matrix[a][k]=matrix[i][k];
		matrix[i][k]=matrixtmp[a][k];
	}
	vektortmp[a][1]=vektor[a][1];
	vektor[a][1]=vektor[i][1]; //komisch, ohne tmp funktioniert das nicht mehr; 
	vektor[i][1]=vektortmp[a][1];
	}
}
}

//addieren

double f ;
for(int i=1; i+a<N;i++){//die a+i-te Zeile soll in der [a+i][a] Komp Null haben
	f=-matrix[a+i][a]/matrix[a][a];
	for( int k=0;k<N;k++){ // es geht hier entlang der Zeile, damit alle Komponenten mitgenommen werden
		matrix[a+i][k]=matrix[a+i][k]+f*matrix[a][k];
	}
	vektor[a+i][1]=vektor[a+i][1]+f*vektor[a][1];
}

}
//Anfang Test
/*
cout << "ueberpruefung der Matrix: " << endl;
    cout << "Die  n x n Matrix A mit n = " << N << " ist:" << endl ;
    for(int i=0;i<N;i++)
	{
			for(int j=0;j<N;j++)
    	cout << setw(4) << matrix[i][j] ;
    	cout << endl;
	}
	
	cout << "Der berechnete Vektor b ist: " << endl ;
	
	for(int i=0; i<N ; i++){
		cout << setw(4) << vektor[i][1] << endl ;
	}
	*/
//ende Test

//restlichen Komponenten sollen Null werden
for(int a=N-1 ; a>=0 ; a--){
	for(int i=1; i<a+1 ; i++){
	double f ;
	f= - matrix[a-i][a]/matrix[a][a];
	matrix[a-i][a]=matrix[a-i][a]+f*matrix[a][a];
	vektor[a-i][1]=vektor[a-i][1]+f*vektor[a][1];
}
}

//normieren der einzelnen Komponenten auf 1
for(int a=0; a<N; a++){
	vektor[a][1]=vektor[a][1]/matrix[a][a];
//	matrix[a][a]=1;
}
/*
cout << "ueberpruefung der Matrix: " << endl;
    cout << "Die  n x n Matrix A mit n = " << N << " ist:" << endl ;
    for(int i=0;i<N;i++)
	{
			for(int j=0;j<N;j++)
    	cout << setw(4) << matrix[i][j] ;
    	cout << endl;
	}
*/
	cout << "Der berechnete Vektor b ist: " << endl ;
	
	for(int i=0; i<N ; i++){
		cout << setw(4) << vektor[i][1] << endl ;
	}

cin >> p ;
return(0);
}
