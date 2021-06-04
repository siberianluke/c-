#include <iostream>
#include <fstream>
#include <string>


using namespace std;
void popolamento();
void visualizza();
void ricerca();

struct persona
{
   char nome[25];
   char cognome[30];
   int eta;	
};

int main()
{

	popolamento();
	visualizza();
	ricerca();
	
	return 0;
}

void popolamento()
{
	
	struct persona persona;
	
	std::ofstream oFile("dati.txt",std::ios_base::out | std::ios_base::app);     
		
		if(oFile.is_open())
		{
			cout<<endl<<" NOME ---> ";
			cin>>persona.nome;
			
			cout<<endl<<" COGNOME ---> ";
			cin>>persona.cognome;
			
			cout<<endl<<" ETA ---> ";
			cin>>persona.eta;
			
			oFile<<endl<<persona.nome<<","<<persona.cognome<<","<<persona.eta;
		}
		
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
		   	if(nome == "Mario")
		   		conta++;
		   		
		   	getline(iFile,fine);	
		}
		
		cout<<" HO TROVATO "<<conta<<" MARIO ";
		
	}
	
	iFile.close();
}



