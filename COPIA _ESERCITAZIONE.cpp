/* FILA B
  
 FERRARA GIANLUCA
  
 21/04/2021

*/

#include <iostream>
#include <string>
#define MAX 20

using namespace std;
void popola(struct elettrodomestici* elettrodomestici);
void marca(struct elettrodomestici array[],int inseriti);
void stampa(struct elettrodomestici array[],int inseriti);
void PrezzoBasso(struct elettrodomestici array[],int inseriti);
void ordinamento(struct elettrodomestici array[],int inseriti);
void menu();

struct elettrodomestici
{
	string tipo ;
	string marca ;
	int scaffale ;
	float prezzo ;
};


int main()
{
	int inseriti = 0;							
	char scelta;
	struct elettrodomestici array[MAX];			
	
	do
	{
			
		menu();
		
		cout<<endl<<" SCEGLI ---> [1-6]: ";
		cin>>scelta;
		
		switch(scelta)
		{
			case '1':
				
			cout<<endl<<" INSERISCI I DATI DELL'ELETTRODOMESTICO "<<endl<<endl;
			 
			 	cout<<" !! - INSERISCI I DATI DELL' "<<inseriti<<" ELETTRODOMESTICO - !! "<<endl<<endl;
			 	popola(&array[inseriti]);			
			 	
			 	inseriti++;								
				
	   
	   			system(" pause ");
				system(" CLS ");
				break;
				
			case '2':
				
				cout<<" STAMPA ELETTRODOMESTICI "<<endl;
				stampa(array,inseriti);
				
				
				
				system(" pause ");
				system(" CLS ");
				break;
			
			case '3':
				
			    cout<<" RICERCA PER MARCA  "<<endl;
			    marca(array,inseriti);
			      
			      
			    system(" pause ");
				system(" CLS ");
				break;
			 
				
			case '4':
				
			    cout<<" TROVA PREZZO PIU' BASSO "<<endl;
			    PrezzoBasso(array,inseriti);
			      
			    system(" pause ");
				system(" CLS ");
				break;
			    
				
			case '5':
				
			    cout<<" ORDINAMENTO DECRESCENTE "<<endl;
			    ordinamento(array,inseriti);
			      
			    system(" pause ");
				system(" CLS ");
				break;
			
			
			case '6':
		
		       
				return 0;
				break;		
		}
			
	}while(scelta!= '6');
	return 0;
	
	return 0;
}

void popola(struct elettrodomestici* elettrodomestici)
{
	int scaffale;												
	
	cin.ignore();												
	cout<<" INSERISCI IL TIPO DELL' ELETTRODOMESTICO :  ";
	getline(cin,elettrodomestici->tipo);
	
	
	cout<<" INSERISCI LA MARCA DELL' ELETTRODOMESTICO : ";
	getline(cin,elettrodomestici->marca);
	
	
	cout<<" INSERISCI LO SCAFFALE : ";
	cin>> scaffale;
	
	while(scaffale > 10 || scaffale == 0)						
	{	
		cout<<" !-  LO SCAFFALE DEVE ESSERE TRA 1 E 10 -!";
		cout<<" INSERISCI LO SCAFFALE : ";
		
		cin>>scaffale;
	}
	
	elettrodomestici->scaffale = scaffale;						
	
	

	cout<<" INSERISCI IL PREZZO : ";
	cin>>elettrodomestici->prezzo;
}

void marca(struct elettrodomestici array[MAX],int inseriti)		
{
	string marca;
	int contatore = 0;
	
	cin.ignore();
	cout<<" QUALE MARCA VUI CONTROLLARE ? -----> ";			
	getline(cin,marca);											
		
	for(int i=0;i<inseriti;i++)
	{
		if(array[i].marca == marca)								
		{
			contatore++ ;
		}
		
	}
	
	cout<< " HO TROVATO "<<contatore<<" ELETTRODOMESTICI "<<marca<<endl;
}

void stampa(struct elettrodomestici array[MAX],int inseriti)		
{
	
	
	for(int i=0;i<inseriti;i++)
	{
		cout<<endl<< " STAMPO IL "<<i<<" ELETTRODOMESTICO "<<endl;
		
		cout<< array[i].tipo<<endl;
		cout<< array[i].marca<<endl;
		cout<< array[i].scaffale<<endl;
		cout<< array[i].prezzo<<endl;
	}
	
	
}

void PrezzoBasso(struct elettrodomestici array[MAX],int inseriti)		
{
	string tipo;
	float minimo = 1000000000000000 ;
	int casella;
	
	cin.ignore();
	cout<<" QUALE MARCA VUI CONTROLLARE ? -----> ";
	getline(cin,tipo);
	
	for(int i=0;i<inseriti;i++)
	{
		if(array[i].tipo == tipo && array[i].prezzo < minimo)		
		{
			minimo = array[i].prezzo;								
			casella = i;
		}
		
	}
	
	cout<< " QUELLO CHE COSTA DI MENO E' "<<endl;				
	
	cout<< array[casella].tipo<<endl;
	cout<< array[casella].marca<<endl;
	cout<< array[casella].scaffale<<endl;
	cout<< array[casella].prezzo<<endl;
}

void ordinamento(struct elettrodomestici array[MAX],int inseriti)		
{
	int massimo;														
	
	struct elettrodomestici temp;										
	
	for(int i=0;i<inseriti-1;i++)										
    {

		massimo = i;

		for(int j=i+1;j<inseriti;j++)
		{	

			if (array[j].prezzo > array[massimo].prezzo)

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
	cout<<endl<<" 1) INSERISCI I DATI DELL'ELETTRODOMESTICO "<<endl;
	cout<<" 2) STAMPA ELETTRODOMESTICI "<<endl;
	cout<<" 3) RICERCA PER MARCA "<<endl;
	cout<<" 4) TROVA PREZZO PIU' BASSO "<<endl;
	cout<<" 5) ORDINAMENTO DECRESCENTE "<<endl;
	cout<<" 6) ESCI "<<endl;
}
