#include <iostream>
#define MAX 100

using namespace std;

void calcola_sequenza(int[],int);

void stampa_sequenza(int[],int);

int main() 
{
	int sequenza[MAX];
	int n;
	
	cout<<" Inserisci il valore finale della funzione: ";
	cin>>n;
	cout<<endl;
	
	calcola_sequenza(sequenza,n+1);
	
	stampa_sequenza(sequenza,n+1);
	
	return 0;
}

void calcola_sequenza(int v[MAX],int l)
{
	int i;
	
	v[0]=0;
	v[1]=1;
	
	for(i=2; i<l; i++)
	   
	   {
	   	  v[i]=v[i-1]+v[i-2];
	   }
	   
}

void stampa_sequenza(int v[MAX],int l)
{
	int i;
	
	for(i=0; i<l; i++)
	   
	   {
	   	  cout<<" indice --> "<<i<<" valore sequenza --> "<<v[i]<<endl;
	   }
		
}


