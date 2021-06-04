#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void lettura();
void maiuscole(string carattere);
void minuscole(string carattere);
void numeri(string carattere);
void altro(string carattere);
bool appartiene(string lunga,string carattere);

int main()
{
	
	lettura(); // lettura legge master e chiama tutte le altre funzioni
	
	return 0;
}

void lettura()
{
	ifstream file("master.txt");  // apro il file in lettura
	if(file.is_open())
	{
		char carattere;
		
		string maiu = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string minu = "abcdefghijklmnopqrstuvwxyz"; // faccio appartenere ad altro le lettere accentate presenti sulla tastiera
		string num = "0123456789";
		
		while(file.get(carattere))
		{
			string c(1, carattere);  // converto il carattere da  char a string
			
			if(appartiene(maiu,c))  //uso if e else if perche il caattere appartine ad una SOLA categoria
				maiuscole(c);
				
			else if(appartiene(minu,c))
				minuscole(c);
				
			else if(appartiene(num,c))
				numeri(c);
			
			else  // si riferisce all'ultimo caso (altro)
				altro(c);
		}
		
		cout<<" HO CREATO I 4 FILE CON LE APPOSITE CATEGORIE ";
	}
	file.close();
}

void maiuscole(string carattere) // Sara la funzione che inserisce le maiuscole nel file corretto
{
	ofstream oFile("maiuscole.txt",ios_base::out | ios_base::app);
	
	if(oFile.is_open())
	{
		oFile<<carattere;
	}
	
	oFile.close();
}

void minuscole(string carattere) // Sara la funzione che inserisce le minuscole nel file corretto
{
	ofstream oFile("minuscole.txt",ios_base::out | ios_base::app);
	
	if(oFile.is_open())
	{
		oFile<<carattere;
	}
	
	oFile.close();
}

void numeri(string carattere) // Sara la funzione che inserisce numeri nel file corretto
{
	ofstream oFile("numeri.txt",ios_base::out | ios_base::app);
	
	if(oFile.is_open())
	{
		oFile<<carattere;
	}
	
	oFile.close();
}

void altro(string carattere) // Sara la funzione che inserisce altro nel file corretto
{
	ofstream oFile("altro.txt",ios_base::out | ios_base::app);
	
	if(oFile.is_open())
	{
		oFile<<carattere;
	}
	
	oFile.close();
}

bool appartiene(string lunga,string carattere)
{
	int lunghezza = lunga.length();      // calcola la lunghezza della stringa
	
	for(int i=0;i<lunghezza;i++)
	{
		if(lunga[i] == carattere[0])
			return true;
	}
	
	return false;
}
