#include <iostream>
#include <fstream>
#include <string>


using namespace std;
void popolamento();
void visualizza();
void ricerca();
void menu();

struct persona
{
   char nome[25];
   char cognome[30];
   int eta;	
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
			
	
			case '3':
		
		       ricerca();
				system(" pause ");
				system(" CLS ");
				break;
			
			case '4':
		
		       
				return 0;
				break;		
		}
			
	}while(scelta!= '4');

	
	return 0;
}

void popolamento()
{
	
	struct persona persona;
	
	std::ofstream oFile("dati.txt", std::ios_base::out | std::ios_base::app);    
		
		if(oFile.is_open())
		{
			cout<<endl<<" NOME ---> ";
			cin>>persona.nome;
			
			cout<<endl<<" COGNOME ---> ";
			cin>>persona.cognome;
			
			cout<<endl<<" ETA ---> ";
			cin>>persona.eta;
			
			oFile<<persona.nome<<","<<persona.cognome<<","<<persona.eta<<endl;
		}
		else 
			cout<<"ERRORE";
		oFile.close();
}

void visualizza()
{
	std::ifstream iFile("dati.txt");
	
	if(iFile.is_open())
	{
		
		string nome;
		string cognome;
		string eta;
		cout<<endl;
		
		while(getline(iFile,nome,','))
		{
		   	getline(iFile,cognome,',');
			getline(iFile,eta);
			
			cout<<" NOME : "<<nome<<endl;
			cout<<" COGNOME : "<<cognome<<endl;
			cout<<" ETA : "<<eta<<endl;
			
			cout<<" --------------------------------------------------------------------- "<<endl;		
		}
	}
	
	
	iFile.close();
	
}

void ricerca()
{
	std::ifstream iFile("dati.txt");
	
	if(iFile.is_open())
	{
		
		string nome,fine;
		int conta=0;
		
		while(getline(iFile,nome,','))
		{
		   	if(nome == "Mario" || nome == "mario")
		   		conta++;
		   		
		   	getline(iFile,fine);	
		}
		
		cout<<" HO TROVATO "<<conta<<" MARIO "<<endl;
		
	}
	
	iFile.close();
}

void menu()
{
	cout<<endl<<" 1) POPOLAMENTO "<<endl;
	cout<<" 2) VISUALIZZAZIONE "<<endl;
	cout<<" 3) RICERCA MARIO "<<endl;
	cout<<" 4) ESCI "<<endl;
}


