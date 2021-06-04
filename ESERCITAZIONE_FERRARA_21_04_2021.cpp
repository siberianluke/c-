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
	int inseriti = 0;							//per tenere conto di quanti ne ho già inseriti (elettrodomestici dentro array)
	char scelta;
	struct elettrodomestici array[MAX];			//definisco un array che conterrà struct elettrodomestici
	
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
			 	popola(&array[inseriti]);				//gli passo l'indirizzo usando & per modificarne il contenuto
			 	
			 	inseriti++;								//incremento inseriti dopo aver effettivamente inserito un elettrodomestico nell'array
				
	   
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
	int scaffale;												//per fare un controllo sulla correttezza del dato inserito da utente
	
	cin.ignore();												//perchè sennò non riesco a inserirere il tipo 
	cout<<" INSERISCI IL TIPO DELL' ELETTRODOMESTICO :  ";
	getline(cin,elettrodomestici->tipo);
	
	
	cout<<" INSERISCI LA MARCA DELL' ELETTRODOMESTICO : ";
	getline(cin,elettrodomestici->marca);
	
	
	cout<<" INSERISCI LO SCAFFALE : ";
	cin>> scaffale;
	
	while(scaffale > 10 || scaffale == 0)						//controllo sulla correttezza, scaffale deve essere compreso tra 1 e 10
	{	
		cout<<" !-  LO SCAFFALE DEVE ESSERE TRA 1 E 10 -!";
		cout<<" INSERISCI LO SCAFFALE : ";
		
		cin>>scaffale;
	}
	
	elettrodomestici->scaffale = scaffale;						//una volta che lo scaffale è corretto lo memorizzo
	
	

	cout<<" INSERISCI IL PREZZO : ";
	cin>>elettrodomestici->prezzo;
}

void marca(struct elettrodomestici array[MAX],int inseriti)		//vede quanti elettromestici di una determinata marca ci sono
{
	string marca;
	int contatore = 0;
	
	cin.ignore();
	cout<<" QUALE MARCA VUI CONTROLLARE ? -----> ";			
	getline(cin,marca);											//faccio inserire all'utente la marca da cercare
		
	for(int i=0;i<inseriti;i++)
	{
		if(array[i].marca == marca)								//vedo se marca elettrodomestico corrisponde a quello inserito in precedenza
		{
			contatore++ ;
		}
		
	}
	
	cout<< " HO TROVATO "<<contatore<<" ELETTRODOMESTICI "<<marca<<endl;
}

void stampa(struct elettrodomestici array[MAX],int inseriti)		//stampa a schermo tutto l'array di elettrodomestici insieriti
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

void PrezzoBasso(struct elettrodomestici array[MAX],int inseriti)		//ricerca il tipo di elettrodomestico che l'utente inserisce col prezzo minore
{
	string tipo;
	float minimo = 1000000000000000 ;
	int casella;
	
	cin.ignore();
	cout<<" QUALE MARCA VUI CONTROLLARE ? -----> ";
	getline(cin,tipo);
	
	for(int i=0;i<inseriti;i++)
	{
		if(array[i].tipo == tipo && array[i].prezzo < minimo)		//controllo se il tipo corrisponde a quello inserito e se il prezzo è minore di quello che finora è il minimo 
		{
			minimo = array[i].prezzo;								//aggiorno prezzo min e la posizione in cui ho trovato quel'elettrodomestico
			casella = i;
		}
		
	}
	
	cout<< " QUELLO CHE COSTA DI MENO E' "<<endl;				//stampo tutte le info di quell'elettrodomestico
	
	cout<< array[casella].tipo<<endl;
	cout<< array[casella].marca<<endl;
	cout<< array[casella].scaffale<<endl;
	cout<< array[casella].prezzo<<endl;
}

void ordinamento(struct elettrodomestici array[MAX],int inseriti)		//ordinamento decrescente in base al prezzo usando il selection sort
{
	int massimo;														//per memorizzare la posizione in cui ho trovato il prezzo massimo finora
	
	struct elettrodomestici temp;										//serve per effettuare lo scambio di due caselle dell'array, temporaneo
	
	for(int i=0;i<inseriti-1;i++)										//dopo ogni iterazione metto al primo posto il massimo, poi al secondo il secondo più grande ....
    {

		massimo = i;

		for(int j=i+1;j<inseriti;j++)
		{	

			if (array[j].prezzo > array[massimo].prezzo)

				massimo= j;

		}

			temp=array[massimo];										// effettuo lo scambio

			array[massimo] = array[i] ;

			array[i] = temp;
			
		}
		
		stampa(array,inseriti);										// stampo nuovamente tutto l'array ordinato in maniera decrescente
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
