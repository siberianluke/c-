#include <iostream>
#define MAX 10

// POPOLAMENTO DI UN ARRAY DI 10 NUMERI CON LA VISUALIZAZIONE DEL DOPPIO DI OGNI ELEMENTO //

using namespace std;
 
int main()
{
	int i;
	float vettore[MAX];
	
	cout<<"ANDIAMO A POPOLARE IL VETTORE! "<<endl;
	
	for(i=0;i<MAX;i++)
	{
		cout<<"inserisci il "<<i<<" elemento dell'array: ";
		cin>>vettore[i];
	}
	
	for(i=0;i<MAX;i++)
	
	    vettore[i]=vettore[i] * 2;
	    
	 system(" cls");
	 cout<<" visualizzazzione quadrato del vettore "<<endl;
	 
	for(i=0;i<MAX;i++)
	{
		cout<<" vettore ["<<i<<"]: ";
		cout<< vettore[i]<<endl;
	}
	
	system ( " pause" );
	return 0;
	
}
