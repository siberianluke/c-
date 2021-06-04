#include <iostream>
#include <string>
#define MAX 3

using namespace std;

void popolamento(struct libro* libro);

void menu();

struct libro
{
	int codice;
	int pagine;
	float costo;
};

int main()
{
	int scelta;
	struct libro array[MAX];
	int inseriti;
	
	cout<<endl<<" POPOLIAMO IL LIBRO "<<endl;
	popolamento(&array[inseriti]);
	
	return 0;
}

void popolamento(struct libro* libro)
{
	cin.ignore();
	
	cout<<" INSERISCI IL CODICE ---> ";
	cin>>libro->codice;
	
	cout<<" INSERISCI IL NUMERO DI PAGINE ----> ";
	cin>>libro->pagine;
	
	cout<<" INSERISCI IL COSTO ----> ";
	cin>>libro->costo;
}
