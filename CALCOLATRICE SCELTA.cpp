#include <iostream>

using namespace std;

void menu();

int main(){
	
	float SOMMA;
	float SOTTRAZIONE;
	float MOLTIPLICAZIONE;
	float DIVISIONE;
	float valore1;
	float valore2;
	int  scelta;
	
	
	do{
			
		menu();
		
		cout<<"Inserisci una scelta[1-5]: ";
		cin>>scelta;
		
		
		
	    
		

		switch(scelta)
		{
			case 1:
				
				cout<<"ADDIZIONE"<<endl;
				cout<< " inserisci il primo valore  : ";
	            cin>> valore1;
	            cout<< " inserisci il secondo valore : ";
	            cin>> valore2;
	   
	   

	if(valore1 > 0)
	{
		
	   SOMMA= valore1 + valore2;
	   
	   
	}
	   	
	if(valore2 > 0)
	{
		
	   SOMMA= valore1 + valore2;
	   
	   cout<< " Il risultatto della addizione equivale a  : " <<SOMMA<<endl;
	   
	   
	}
	
		        
				system(" pause ");
				system(" CLS ");
				break;
				
			case 2:
				
				cout<<"SOTTRAZIONE"<<endl;
					cout<< " inserisci il primo valore  : ";
	            cin>> valore1;
	            cout<< " inserisci il secondo valore : ";
	            cin>> valore2;
	   
	   

	if(valore1 > 0)
	{
		
	   SOTTRAZIONE= valore1 - valore2;
	   
	   
	}
	   	
	if(valore2 > 0)
	{
		
	   SOMMA= valore1 - valore2;
	   
	   cout<< " Il risultato della sottrazione equivale a  : " <<SOTTRAZIONE<<endl;
	   
	   
	}
	
	            
	            system(" pause ");
				system(" CLS ");
				break;
			
			case 3:
				
				cout<<"MOLTIPLICAZIONE"<<endl;
					cout<< " inserisci il primo valore  : ";
	            cin>> valore1;
	            cout<< " inserisci il secondo valore : ";
	            cin>> valore2;
	   
	   

	if(valore1 > 0)
	{
		
	   MOLTIPLICAZIONE= valore1 * valore2;
	   
	   
	}
	   	
	if(valore2 > 0)
	{
		
	   
	   MOLTIPLICAZIONE= valore1 * valore2;
	   cout<< "Il risultatto della moltiplicazione equivale a  : " <<MOLTIPLICAZIONE<<endl;
	   
	   
	}
	
	else
	
	   cout<< " !INSERISCI VALORI MAGGIORI! "<<endl;
				
				system(" pause ");
				system(" CLS ");
				break;
			
			case 4:
				
				cout<<"DIVISIONE"<<endl;
				cout<< " inserisci il primo valore  : ";
	            cin>> valore1;
	            cout<< " inserisci il secondo valore : ";
	            cin>> valore2;
	   
	   

	if(valore1 > 0)
	{
		
	   DIVISIONE= valore1 / valore2;
	   
	   
	}
	   	
	if(valore2 > 0)
	{
		
	   DIVISIONE= valore1 / valore2;
	   
	   cout<< " Il risultatto della divisione equivale a  : " <<DIVISIONE<<endl;
	   
	   
	}
				system(" pause ");
				system(" CLS ");
				break;
			
			case 5:
		
		       
				
				
				return 0;
				break;
				
				
						
		}
		
	
		
	}while(scelta!= 5);
	

    return 0;
}

void menu()
{
	
	
	  cout<<"  OPERAZIONI  : "<<endl;
	  
	  cout<<"1) ADDIZIONE "<<endl;
	  cout<<"2) SOTTRAZIONE "<<endl;
	  cout<<"3) MOLTIPLICAZIONE "<<endl;
	  cout<<"4) DIVISIONE "<<endl;
	  cout<<"5) Esci"<<endl;
	  return;
	  
}
