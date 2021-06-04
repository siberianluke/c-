#include <iostream>
#include <string>
#define MAX 5

using namespace std;
void popolamento(struct studente* studente)






struct studente
{
	string nome;
	string cognome;
	string classe;
	char sezione;
};

int main()
{
	cout<<" POPOLAMENTO "<<endl;
	popolamento(&studente);
	
	return 0;
}

void popolamento(struct studente* studente)
{
	cin.ignore();
	
	cout<<" COGNOME --->";
	getline(cin,studente->cognome);
	
	cout<<" NOME ---> ";
	getline(cin,studente->nome);
	
	cout<<" CLASSE ---> ";
	cin>>studente->classe;
	
	cout<<" SEZIONE ---> ";
	cin>>studente->sezione;
}
