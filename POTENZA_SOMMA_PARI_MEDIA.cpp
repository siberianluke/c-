// media elementi di 3 array - elevamento a potenza di ogni elemento di ogni array- somma elementi di posto pari di ogni array //

#include <iostream>

#define DIM 4

using namespace std;

void stampa(float x[DIM]);

float media(float x[DIM]);

void elevamento(float x[DIM]);
		
float somma_elementi_posto_pari(float x[DIM]);

void popolamento(float x[DIM]);
 

int main(){
	
	float arr_1[DIM], arr_2[DIM], arr_3[DIM];
	
	cout<<" Inserisci gli elementi del 1 array : "<<endl;
	popolamento(arr_1);
	cout<<" Inserisci gli elementi del 2 array : "<<endl;
	popolamento(arr_2);
	cout<<" Inserisci gli elementi del 3 array : "<<endl;
	popolamento(arr_3);
	
	cout<<endl<<" media del  1 array ";
	cout<<media(arr_1);
	cout<<endl<<" media del  2 array ";
	cout<<media(arr_2);
	cout<<endl<<" media del  3 array ";
	cout<<media(arr_3);
	
	cout<<endl<<" somma_elementi_posto_pari del  1 array ";
	cout<<somma_elementi_posto_pari(arr_1);
	cout<<endl<<" somma_elementi_posto_pari del  2 array ";
	cout<<somma_elementi_posto_pari(arr_2);
	cout<<endl<<" somma_elementi_posto_pari del  3 array ";
	cout<<somma_elementi_posto_pari(arr_3);
	
	cout<<endl<<" elevamento del  1 array "<<endl;
	elevamento(arr_1);
    cout<<" elevamento del  2 array "<<endl;
	elevamento(arr_2);
	cout<<" elevamento del  3 array "<<endl;
	elevamento(arr_3);
	
	stampa(arr_3);
	return 0;
}

void popolamento(float x[DIM])
{
	
	for(int i=0; i<DIM; i++)
	
	{
			
			cout<<" Inserisci il " <<i<< " elemento dell'array ";
			
			cin>>x[i];	
	}
	

} 

float somma_elementi_posto_pari(float x[DIM])
{
	
	float somma=0;
	for(int i=1; i<DIM; i=i+2)
	
	{
		somma+=x[i];
	}
	
	return somma;
}

void elevamento(float x[DIM])
	
	{
	
	
	for(int i=0; i<DIM; i++)
		
		{
		
			x[i]=x[i]*x[i];
			cout<<" potenza del elemento  " <<i<< "  e' pari a   "<<x[i]<<endl;
		}
	}
	
float media(float x[DIM])
{
	
	float media=0;
	float somma=0;	
	for(int i=0; i<DIM; i++)
	
	{
		
		somma+=x[i];
	}
	
	media=somma/DIM;
	return media; 
}

void stampa(float x[DIM])
{
	
	for(int i=0; i<DIM; i++)
	
	{
		
		cout<<"valore["<<i<<"]: "<<x[i];
	}
}	

