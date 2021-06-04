#include <iostream>
#include <string>
#define MAX 3

using namespace std;

void popolamento(struct ricetta* ricetta);
void stampa(struct ricetta array[],int inseriti);
void ordinamentogenere(struct ricetta array[],int inseriti);
void ordinamentonome(struct ricetta array[],int inseriti);
void menu();

struct ricetta
{
	string codice;
	string nome;
	char genere;
	float tempo;
};

int main()
{
	struct ricetta array[MAX];
	int inseriti;
	int scelta;
	
	
	
	do{
			
		menu();
		
		cout<<endl<<" SCEGLI ---> [1-5]: ";
		cin>>scelta;
		
		
		
	    
		

		switch(scelta)
		{
			case 1:
				
			cout<<endl<<" POPOLIAMO LE RICETTE "<<endl<<endl;
			 
			 	cout<<" !- POPOLO LA  "<<inseriti<<" RICETTA -! "<<endl<<endl;
				popolamento(&array[inseriti]);
				
				inseriti++;
	   
				system(" pause ");
				system(" cls ");
				break;
				
			case 2:
				
				cout<<endl<<" VISUALIZZIAMO LE RICETTE "<<endl<<endl;
				    stampa(array,inseriti);
					
				system(" pause ");
				system(" cls ");
				break;
				
			case 3:
				
				cout<<endl<<" ORDINAMENTO RICETTE GENERE "<<endl<<endl;
				   	ordinamentogenere(array,inseriti);
				   	
				system(" pause ");
				system(" cls ");
				break;
				
			case 4:
				
				cout<<endl<<" ORDINAMENTO RICETTE NOME "<<endl<<endl;
				   	ordinamentonome(array,inseriti);
				   	
				system(" pause ");
				system(" cls ");
				break;
				
			case 5:
				
				return 0;
				break;
				
				
	}
		
	
		
	}while(scelta!= 5 );
	
	return 0;
}

void popolamento(struct ricetta* ricetta)
{
	cin.ignore();
	
	cout<<" INSERISCI IL CODICE ---> ";
	getline(cin,ricetta->codice);
	
	cout<<endl<<" INSERISCI IL NOME --->  ";
	getline(cin,ricetta->nome);
	
	cout<<endl<<" INSERISCI IL GENERE ---> ";
	cin>>ricetta->genere;
	
	cout<<endl<<" INSERISCI IL TEMPO ---> ";
	cin>>ricetta->tempo;
}

void stampa(struct ricetta array[MAX],int inseriti)
{
	for(int i=0;i<inseriti;i++)
	{
		cout<<endl<<  " CODICE ---> "<<array[i].codice<<endl;
		
		cout<< " NOME ---> "<<array[i].nome<<endl;
		
		cout<< " GENERE ---> " <<array[i].genere<<endl;
		
		cout<< " TEMPO ---> "<<array[i].tempo<<endl;
	}
}

void ordinamentogenere(struct ricetta array[MAX],int inseriti)
{
	char massimo = 'a';														
	
	struct ricetta temp;										
	
	for(int i=0;i<inseriti-1;i++)										
    {

		massimo = i;

		for(int j=i+1;j<inseriti;j++)
		{	

			if (array[j].genere < array[massimo].genere)
			
			      massimo= j;
		}

			temp=array[massimo];										

			array[massimo] = array[i] ;

			array[i] = temp;
	}
		
		stampa(array,inseriti);	
}

void ordinamentonome(struct ricetta array[MAX],int inseriti)
{
	char massimo = 'a';														
	
	struct ricetta temp;										
	
	for(int i=0;i<inseriti-1;i++)										
    {

		massimo = i;

		for(int j=i+1;j<inseriti;j++)
		{	

			if (array[j].nome < array[massimo].nome)
			
			      massimo= j;
		}

			temp=array[massimo];										

			array[massimo] = array[i] ;

			array[i] = temp;
	}
		
		stampa(array,inseriti);	
}

void menu()
{
	cout<<endl<<" 1) POPOLAMENTO RICETTE "<<endl;
	cout<<endl<<" 2) VISUALIZZAZIONE RICETTE "<<endl;
	cout<<endl<<" 3) ORDINAMENTO CRESCENTE GENERE "<<endl;
	cout<<endl<<" 4) ORDINAMENTO CRESCENTE NOME "<<endl;
	cout<<endl<<" 5) Esci "<<endl;
}
