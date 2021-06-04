//Data una tabella quadrata di char e inserita una stringa da ricercare, 
//verificarne la presenza, la posizione iniziale e la direzione di ricerca 
//(2 orizzontali, 2 verticali e 4 diagonali)

#include <iostream>
#include <stdlib.h> 
#include <time.h>  
#include <cstring>

#define MAX 11

void CercaIniziale(char array[][MAX],char* parola);
void Stringa(char* parola);
int LunghezzaParola(char* parola);
bool CercaDx(char array[][MAX],char* parola,int posizione_i,int posizione_j);
bool CercaSx(char array[][MAX],char* parola,int posizione_i,int posizione_j);
void popolamento(char array[][MAX]);
bool CercaGiu(char array[][MAX],char* parola,int posizione_i,int posizione_j);
bool CercaSu(char array[][MAX],char* parola,int posizione_i,int posizione_j);
bool CercaDiagonaleDxSu(char array[][MAX],char* parola,int posizione_i,int posizione_j);
bool CercaDiagonaleDxGiu(char array[][MAX],char* parola,int posizione_i,int posizione_j);
bool CercaDiagonaleSxSu(char array[][MAX],char* parola,int posizione_i,int posizione_j);
bool CercaDiagonaleSxGiu(char array[][MAX],char* parola,int posizione_i,int posizione_j);

using namespace std;

int main ()
{
	char array[MAX][MAX]; 					//creo lo spazio per la tabella
	srand (time(NULL));						//serve nel caso in cui uso random()
	char* parola = new char [100];			// puntatore per la parola da cercare
	popolamento(array);						
	Stringa(parola);
	CercaIniziale(array,parola);
	return 0;
}

//funzione che popola l'array

void popolamento(char array[MAX][MAX])						
{
	string s="itsinoimacasrpastaitisabpianistisccidtonsorerhlratooroteofargopitssalumiereaotbaliaeaechartierenoulnihcranomdoigooiataleg";
	int n= s.length();				// QUESTA FUNZIONE CALCOLA LA LUNGHEZZA DELLA STRINGA S
	char cruciverba[n+1];           // ALLOCATO ARRAY DIMENSIONE N+1--> TEMINATORE DI STRINGA OCCUPA UNO SPAZIO
	strcpy(cruciverba, s.c_str());  // STR
    int c=0;
    
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			//array[i][j] = 97 + rand() % 26;		//costruzione tabella usando random
			array[i][j]= cruciverba[c];				//costruzione tabella usando cruciverba esistente	
			cout<<" "<<array[i][j]<<" ";
			c++;

		}
		cout<<endl;
	}
}

//chiedo in input la parola da cercare e la memorizzo in parola

void Stringa(char* parola)
{

	cout<<endl<<" LE PAROLE CHE PUOI CERCARE SONO : "<<endl;
	
	cout<<endl<<" armieri - artiere - attori - balla - camionisti - educatori - gelataio - hostess - monarchi "<<endl<<endl;
	cout<<" osti - pastai - pianisti - pittore - sacrestani - salumiere - sbirri - soldati - tipografo - tonsore "<<endl;
		
	cout<<endl<<endl<<" Quale parola vuoi cercare ? ";
	cin>>parola;

}


//cerca l'iniziale della parola


void CercaIniziale(char array[MAX][MAX],char* parola)
{
	cout<<endl;
	
	bool trovato = false;
	
	for(int i=0;i<MAX;i++)
	{
		
		for(int j=0;j<MAX;j++)
		{
			if(array[i][j]==parola[0])			//ogni volta che trova iniziale chiama le funzioni per cercare in tutte le direzioni
			{	
			
				if(	CercaDx(array,parola,i,j) ||							//se almeno una funzione di ricerca trova la parola la condizione è vera (tante condizione in or --> basta che una sia vera)
					CercaSx(array,parola,i,j) ||
					CercaSu(array,parola,i,j) ||
					CercaGiu(array,parola,i,j) ||
					CercaDiagonaleDxSu(array,parola,i,j) ||
					CercaDiagonaleDxGiu(array,parola,i,j) ||
					CercaDiagonaleSxSu(array,parola,i,j) ||
					CercaDiagonaleSxGiu(array,parola,i,j)) 
				
				    trovato = true;				//nel caso in cui trova la parola
			}
		}
			
	}
	
	if(trovato == false)
	{
		cout<<" NON HO TROVATO "<<parola<<" NEL CRUCIVERBA =( ";
	}        
}

//funzione per calcolare la lunghezza della parola inserita

int LunghezzaParola(char* parola)
{
	int i=0;
	int lunghezza=0;
	while(parola[i] != 0)
	{
		lunghezza++;
		i++;
	}
	return lunghezza;
}


//cerca la parola dall'iniziale verso destra

bool CercaDx(char array[MAX][MAX],char* parola,int posizione_i,int posizione_j)
{
	int lunghezza=LunghezzaParola(parola);
	int posi=posizione_i;
	int pos=posizione_j;
	bool trovato=true;
	
	for(int i=0;i<lunghezza;i++)
	{
		if(parola[i] != array[posizione_i][posizione_j])
		{
			trovato = false;
 
			
			
			return trovato;
		}
		posizione_j++;
	}
	cout<<" Dalla posizione ["<<posi<<","<<pos<<"]"<<" verso destra  !!! HO TROVATO LA PAROLA !!!"<<endl; 
	
	return trovato;
	
}

//cerca la parola dall'iniziale verso sinistra

bool CercaSx(char array[MAX][MAX],char* parola,int posizione_i,int posizione_j)
{
	int lunghezza=LunghezzaParola(parola);
	int pos=posizione_j;
	int posi=posizione_i;
	bool trovato=true;
	
	for(int i=0;i<lunghezza;i++)
	{
		if(parola[i] != array[posizione_i][posizione_j])
		{
			trovato = false;
			 
 
			
			return trovato;
		}
		posizione_j--;
	}

	cout<<" Dalla posizione ["<<posi<<","<<pos<<"]"<<" verso sinistra  !!! HO TROVATO LA PAROLA !!!"<<endl; 
	return trovato;
	
}

//cerca la parola dall'iniziale verso l'alto

bool CercaSu(char array[MAX][MAX],char* parola,int posizione_i,int posizione_j)
{
	int lunghezza=LunghezzaParola(parola);
	int pos=posizione_j;
	int posi=posizione_i;
	bool trovato=true;
	
	for(int i=0;i<lunghezza;i++)
	{
		if(parola[i] != array[posizione_i][posizione_j])
		{
			trovato = false;
			 
 
			
			return trovato;
		}
		posizione_i--;
	}

	cout<<" Dalla posizione ["<<posi<<","<<pos<<"]"<<" verso l'alto  !!! HO TROVATO LA PAROLA !!!"<<endl; 
	return trovato;	
}

//cerca la parola dall'iniziale verso il basso

bool CercaGiu(char array[MAX][MAX],char* parola,int posizione_i,int posizione_j)
{
	int lunghezza=LunghezzaParola(parola);
	int pos=posizione_j;
	int posi=posizione_i;
	bool trovato=true;
	
	for(int i=0;i<lunghezza;i++)
	{
		if(parola[i] != array[posizione_i][posizione_j])
		{
			trovato = false;
			 

			
			return trovato;
		}
		posizione_i++;
	}

	cout<<" Dalla posizione ["<<posi<<","<<pos<<"]"<<" verso il basso  !!! HO TROVATO LA PAROLA !!!"<<endl; 
	return trovato;	
}

//cerca la parola dall'iniziale verso diagonale destra alta

bool CercaDiagonaleDxSu(char array[MAX][MAX],char* parola,int posizione_i,int posizione_j)
{
	int lunghezza=LunghezzaParola(parola);
	int pos=posizione_j;
	int posi=posizione_i;
	bool trovato=true;
	
	for(int i=0;i<lunghezza;i++)
	{
		if(parola[i] != array[posizione_i][posizione_j])
		{
			trovato = false;
			 

			
			return trovato;
		}
		posizione_i--;
		posizione_j++;
	}

	cout<<" Dalla posizione ["<<posi<<","<<pos<<"]"<<" verso la diagonale destra alta  !!! HO TROVATO LA PAROLA !!!"<<endl; 
	return trovato;	
}

//cerca la parola dall'iniziale verso diagonale destra bassa

bool CercaDiagonaleDxGiu(char array[MAX][MAX],char* parola,int posizione_i,int posizione_j)
{
	int lunghezza=LunghezzaParola(parola);
	int pos=posizione_j;
	int posi=posizione_i;
	bool trovato=true;
	
	for(int i=0;i<lunghezza;i++)
	{
		if(parola[i] != array[posizione_i][posizione_j])
		{
			trovato = false;
			 
 
			
			return trovato;
		}
		posizione_i++;
		posizione_j++;
	}

	cout<<" Dalla posizione ["<<posi<<","<<pos<<"]"<<" verso la diagonale destra bassa  !!! HO TROVATO LA PAROLA !!!"<<endl; 
	return trovato;	
}

//cerca la parola dall'iniziale verso diagonale sinistra alta

bool CercaDiagonaleSxSu(char array[MAX][MAX],char* parola,int posizione_i,int posizione_j)
{
	int lunghezza=LunghezzaParola(parola);
	int pos=posizione_j;
	int posi=posizione_i;
	bool trovato=true;
	
	for(int i=0;i<lunghezza;i++)
	{
		if(parola[i] != array[posizione_i][posizione_j])
		{
			trovato = false;
			 

			
			return trovato;
		}
		posizione_i--;
		posizione_j--;
	}

	cout<<" Dalla posizione ["<<posi<<","<<pos<<"]"<<" verso la diagonale sinistra alta  !!! HO TROVATO LA PAROLA !!!"<<endl; 
	return trovato;	
}

//cerca la parola dall'iniziale verso diagonale sinistra bassa

bool CercaDiagonaleSxGiu(char array[MAX][MAX],char* parola,int posizione_i,int posizione_j)
{
	int lunghezza=LunghezzaParola(parola);
	int pos=posizione_j;
	int posi=posizione_i;
	bool trovato=true;
	
	for(int i=0;i<lunghezza;i++)
	{
		if(parola[i] != array[posizione_i][posizione_j])
		{
			trovato = false;
			 

			
			return trovato;
		}
		posizione_i++;
		posizione_j--;
	}

	cout<<" Dalla posizione ["<<posi<<","<<pos<<"]"<<" verso la diagonale sinistra bassa  !!! HO TROVATO LA PAROLA !!!"<<endl; 
	return trovato;	
}
