/* 
   Il candidato stili un programma in grado di gestire le informazioni su memoria di massa memorizzate
    su file di testo (“cellulari.TXT”) relative ai dati dei  telefoni seguendo il seguente
	tracciato di memorizzazione(fax simile)
   
   	Popoli il file (ok)
   	
			Visualizzi il contenuto del file (ok)
			
			Conti  i Telefoni  con prezzo superiore a 500.00€
			Visualizzi quanti Telefoni di una marca letta in input ho nell’archivio (se presente nell’archivio)
			Visualizzi il costo totale di tutti i telefoni presenti in archivio
   
   Gianluca Ferrara
   
   3Ai
   
   03/06/2021
   
   FILA  1
   
*/

#include <iostream>
#include <fstream>
#include <string>


using namespace std;
void popolamento();
void visualizza();
void menu();

struct veicolo
{
   string marca;
   string modello;
   float prezzo;	
};

int main()
{

	char scelta;
	do
	{
			
		menu();
		
		cout<<endl<<" SCEGLI ---> [1-4]: ";
		cin>>scelta;
		
		switch(scelta)
		{
			case '1':
				
			 	popolamento();							
				
	   
	   			system(" pause ");
				system(" CLS ");
				break;
				
			case '2':
				
				visualizza();
				
				
				
				system(" pause ");
				system(" CLS ");
				break;
			
	
//			case '3':
//		
//		       ricerca();
//				system(" pause ");
//				system(" CLS ");
//				break;
			
			case '4':
		
		       
				return 0;
				break;		
		}
			
	}while(scelta!= '4');

	
	return 0;
}

void popolamento()
{
	cin.ignore();
	
	struct veicolo veicolo;
	
	std::ofstream oFile("cellulari.txt", std::ios_base::out | std::ios_base::app);    
		
		if(oFile.is_open())
		{
			cout<<endl<<" MARCA ---> ";
			getline(cin,veicolo.marca);
			
			cout<<endl<<" MODELLO ---> ";
			getline(cin,veicolo.marca);
			
			cout<<endl<<" PREZO ---> ";
			cin>>veicolo.prezzo;
			
			oFile<<veicolo.marca<<","<<veicolo.modello<<","<<veicolo.prezzo<<endl;
		}
		else 
			cout<<"ERRORE";
		oFile.close();
}

void visualizza()
{
	
	
	std::ifstream iFile("cellulari.txt");
	
	if(iFile.is_open())
	{
		
		string marca;
		string modello;
		string prezzo;
		cout<<endl;
		
		while(getline(iFile,marca,','))
		{
		   	getline(iFile,modello,',');
			getline(iFile,prezzo);
			
			cout<<" MARCA  : "<<marca<<endl;
			cout<<" MODELLO : "<<modello<<endl;
			cout<<" PREZZO : "<<prezzo<<endl;
			
			cout<<" --------------------------------------------------------------------- "<<endl;		
		}
	}
	
	
	iFile.close();
	
}

void ricerca()
{
	
	float max = 500.00;
	
	std::ifstream iFile("cellulari.txt");
	
	
	if(iFile.is_open())
	{
		
		string prezzo,fine;
		float prezzo_telefoni;
		
		int conta=0;
		
		while(getline(iFile,modello,','))
		{
		   	prezzo_telefoni = std::stof(prezzo);
		   	
			   if(prezzo_telefoni > max )
		   		conta++;
		   		
		   	getline(iFile,fine);	
		}
		
		cout<<" HO TROVATO "<<conta<<" TELEFONI "<<endl;
		
	}
	
	iFile.close();
}

void menu()
{
	cout<<endl<<" 1) POPOLAMENTO "<<endl;
	cout<<" 2) VISUALIZZAZIONE "<<endl;
	cout<<" 3) RICERCA PREZZO "<<endl;
	cout<<" 3) SOMMA PREZZI "<<endl;
	cout<<" 4) ESCI "<<endl;
}
