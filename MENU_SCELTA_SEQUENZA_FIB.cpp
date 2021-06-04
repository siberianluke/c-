#include <iostream>
#define MAX 5
#define MIN 10
#define MEDIUM 15

using namespace std;

void Fibonacci(float array[]); 
void Tribonacci(float array[]);
void Tetranacci(float array[]); 
void menu();

int main()
{
	float array[MAX];
	int scelta;
	float FIB;
	float TRIB;
	float TRET;
	
	do
	{
		menu();
		
		cout<<" Inserisci una scelta [1-4] : ";
		cin>>scelta;
		
		
		switch(scelta)
		{
			case '1' :
				
				cout<<endl<<" SEQUENZA DI FIBONACCI "<<endl;
				FIB=Fibonacci(array);
				
			  system(" pause ");
			  system(" cls ");
			  break;
			  
		    case '2' :
		    	
		    	cout<<endl<<" SEQUENZA DI TRIBONACCI  "<<endl;
		        TRIB=Ttribonacci(array);
		      
			  system(" pause ");
			  system(" cls ");
			  break;
			  
			case '3' :
				
				cout<<endl" SEQUENZA DI TETRANACCI "<<endl;
				TRET=Tetranacci(array);
				
				
			  system(" pause ");
			  system(" cls ");
			  break;
			  
			  return 0;
			  break;
		
		}
   }while(scelta!3)
   
   return 0;
}

void menu()
{
	cout<<endl<< " QUALE SEQUENZA VUOI FARE ? "<<endl;
	
	cout<<"1) FIBONACCI "<<endl;
	cout<<"2) TRIBONACCI "<<endl;
	cout<<"3) TETRANACCI "<<endl;
	cout<<"4) Esci "<<endl;
	  
}

void Fibonacci(float array[MAX])
{
	array[0]=0; // inizializzo la prima cella a 0
	array[1]=1; // inizializzo la seconda cella a 1
	
	for(int i=2;i<MAX;i++)  // inizializzo i=2 avendo già dichiarato le due celle precedenti
	{
		array[i]= array[i-1] + array[i-2]; // primo for per eseguire la sequenza di fibonacci
	}
	
	
	for(int i=0;i<MAX;i++) // secondo for per visualizzare la sequenza di fibonacci 
	{
		cout<<endl<<array[i]<<endl;
	}
}

void Tribonacci(float array[MIN])
{
	array[0]=0;
	array[1]=1;
	array[2]=1;
	
	for(int i=3;i<MIN;i++)
	{
		array[i]= array[i-1] + array[i-2] + array[i-3];
	}
	
	for(int i=0;i<MIN;i++)
	{
		cout<<endl<<array[i]<<endl;
	}
}

void Tetranacci(float array[MEDIUM])
{
	array[0]=0;
	array[1]=1;
	array[2]=1;
	array[3]=2;
	
	for(int i=4;i<MEDIUM;i++)
	{
		array[i]= array[i-1] + array[i-2] + array[i-3] + array[i-4];
	}
	
	for(int i=0;i<MEDIUM;i++)
	{
		cout<<endl<<array[i]<<endl;
	}
}
