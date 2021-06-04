#include <iostream>
#include <string>
#define MAX 5

using namespace std;
void popolamento(struct persona* persona);
void stampa(struct perosna array[],int inseriti);
void menu();


struct persona
{
	string nome;
	string cognome;
	int eta;
};

int main()
{
	int inseriti = 0;							
	char scelta;
	struct persona array[MAX];			
	
	do
	{
			
		menu();
		
		cout<<endl<<" SCEGLI ---> [1-3]: ";
		cin>>scelta;
		
		switch(scelta)
		{
			case '1':
				
			cout<<endl<<" INSERISCI I DATI DELL'UTENTE "<<endl<<endl;
			 
			 	cout<<" !! - INSERISCI I DATI DELL' "<<inseriti<<" UTENTE - !! "<<endl<<endl;
			 	popolamento(&array[inseriti]);			
			 	
			 	inseriti++;								
				
	   
	   			system(" pause ");
				system(" CLS ");
				break;
				
			case '2':
				
				cout<<" STAMPA I DATI DELL'UTENTE "<<endl;
				stampa(array,inseriti);
				
				
				
				system(" pause ");
				system(" CLS ");
				break;
			
	
			
			
			case '3':
		
		       
				return 0;
				break;		
		}
			
	}while(scelta!= '6');
	return 0;
	
	return 0;
}

void poplamento(struct persona* persona)
{
	cin.ignore();
	
	cout<<" NOME ---> ";
	getline(cin,persona->nome);
	
	cout<<" COGNOME---> ";
	getline(cin,persona->cognome);
	
	cout<<" ETA ---> ";
	cin>>persona->eta;
}
void stampa(struct persona array[MAX],int inseriti)
{
	for(int i=0;i<MAX;i++)
	{
		cout<<endl<<" STAMPO LA "<<i<<" PERSONA "<<endl;
		
		cout<< array[i].nome<<endl;
		cout<< array[i].cognome<<endl;
		cout<< array[i].eta<<endl;
	}
}

void menu()
{
	cout<<endl<<"  OPERAZIONI  : "<<endl;
	  
	  cout<<"1) CREAZIONE PERSONA "<<endl;
	  cout<<"2) STAMPA DATI PERSONA "<<endl;
	  cout<<"3) Esci"<<endl;
}
