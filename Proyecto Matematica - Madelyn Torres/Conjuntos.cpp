#include <iostream>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

//Madelyn Arleth Torres Gómez 4490-22-7308

using namespace std;
      
//variables
char C1, C2, C3, C4;
char Operador1, Operador2, Operador3;
int opcion=0;
int Vc1[4] = {0,1,1,0};
int Vc2[4] = {0,0,1,1};
int VcR1[4] = {0,0,0,0};
int VcR2[4] = {0,0,0,0};
int VcR[4] = {0,0,0,0};//almacena el resultado final

int operar(int ope){	
	switch(ope)
	{
		case 1: //union
			for(int x=0;x<4;x++)
			{
				if ((Vc1[x]==1)||(Vc2[x]==1))
				VcR[x]=1;
			}
			break;
		case 2: //interseccion
			for(int x=0;x<4;x++)
			{
				if ((Vc1[x]==1)&&(Vc2[x]==1))
				VcR[x]=1;
			}
			break;
		case 3://diferencia
			for(int x=0;x<4;x++)
			{
				if ((Vc1[x] ==1)&&(Vc2[x]!=1))
				VcR[x]=1;
			}
			break;
		case 4://diferencia simetrica
			for(int x=0;x<4;x++)
			{
				if (((Vc1[x] ==1)&&(Vc2[x]!=1)) || ((Vc1[x] !=1)&&(Vc2[x] ==1)))
				VcR[x]=1;
			}
			break;
	}
	return 0;
}

int operar2(int ope){	
	switch(ope)
	{
		case 1: //union
			for(int x=0;x<4;x++)
			{
				if ((VcR1[x]==1)||(VcR2[x]==1))
				VcR[x]=1;
			}
			break;
		case 2: //interseccion
			for(int x=0;x<4;x++)
			{
				if ((VcR1[x]==1)&&(VcR2[x]==1))
				VcR[x]=1;
			}
			break;
		case 3://diferencia
			for(int x=0;x<4;x++)
			{
				if ((VcR1[x] ==1)&&(VcR2[x]!=1))
				VcR[x]=1;
			}
			break;
		case 4://diferencia simetrica
			for(int x=0;x<4;x++)
			{
				if (((VcR1[x] ==1)&&(VcR2[x]!=1)) || ((VcR1[x] !=1)&&(VcR2[x] ==1)))
				VcR[x]=1;
			}
			break;
	}
	return 0;
}	

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int DdV_relleno()
{ 
	for (int y=0;y<20;y++)
	{
		for (int x=0; x<58; x++)//conjunto horizontal
		{  
		gotoxy(11+x,3+y);
		printf("/");
	 	}
	}
	gotoxy(1,25);
	cout<<"-";
	return 0;
}


int DdV()
{ //Diagrama de dos conjuntos y universo
	for (int x=0; x<60; x++){ //Universo Horizontal
		gotoxy(10+x,2);
		cout<<"*";
		gotoxy(10+x,23);
		cout<<"*";
	}
	
	for (int x=0; x<21; x++){   //Univ Vertical
		gotoxy(10,2+x);
		cout<<"*";
		gotoxy(69,2+x);
		cout<<"*";	
	}
	
	if(VcR[0]!=0)
	{
		for (int y=0;y<20;y++)
			{
				for (int x=0; x<58; x++)//relleno universo
					{  
						gotoxy(11+x,3+y);
						printf("/");
	 				}
	 		}
	}
	
	for (int x=0; x<30; x++){  //conjunto1 horitontal
		gotoxy(20+x,6);
		cout<<"*";
		gotoxy(20+x,14);
		cout<<"*";
	}
	
	for (int x=0; x<8; x++){   //conjunto1 Vertical
		gotoxy(20,6+x);
		cout<<"*";
		gotoxy(49,6+x);
		cout<<"*";	
	}
	
	if(VcR[1]!=0)
	{
		for (int y=0;y<7;y++)
			{
				for (int x=0; x<28; x++)//relleno conjunto1
					{  
						gotoxy(21+x,7+y);
						printf("/");
	 				}
	 		}
	}
	
	
	for (int x=0; x<30; x++){ //conjunto2 horizontal
		gotoxy(32+x,10);
		cout<<"*";
		gotoxy(32+x,19);
		cout<<"*";
	}
	
	for (int x=0; x<9; x++){   //conjunto2 Vertical
		gotoxy(32,10+x);
		cout<<"*";
		gotoxy(61,10+x);
		cout<<"*";	
	}
	
	if(VcR[3]!=0)
	{
		for (int y=0;y<8;y++)
			{
				for (int x=0; x<28; x++)//relleno conjunto2
					{  
						gotoxy(33+x,11+y);
						printf("/");
	 				}
	 		}
	}
	
	char aux=' ';
	if	(VcR[2]!=0) aux='/';
	{
		for (int y=0;y<3;y++)
			{
				for (int x=0; x<16; x++) //relleno interseccion
					{  
						gotoxy(33+x,11+y);
						printf("%c",aux);
	 				}
	 		}
	}

	gotoxy(1,25);
	cout<<"-";
	return 0;
	
}

int main()
	{
	cout<<"Ingrese Conjunto 1: ";
	cin>>C1;
	cout<<"Ingrese Conjunto 2: ";
	cin>>C2;
	cout<<"\n Ingrese Operador logico: "<<endl;
	cout<<"1. Union "<<endl;
	cout<<"2. Interseccion "<<endl;
	cout<<"3. Diferencia"<<endl;
	cout<<"4. Diferencia simetrica "<<endl;
	cout<<"\n Que desea hacer? ";
	cin>>opcion;
	
	switch(opcion)
		{
		case 1: Operador1='U';
			operar(1);
			break;	
		case 2: Operador1='^';
			operar(2);
			break;
		case 3: Operador1='-';
			operar(3);
			break;
		case 4: Operador1='&';
			operar(4);
			break;
	}
	cout<<"\n LA OPERACION INGRESADA ES: "<<endl<<endl;
	cout<<C1<<" "<<Operador1<<" "<<C2<<endl; 	
	for(int i=0; i<4; i++)
	{
		cout<<VcR[i]<<" ";
	}
	
	cout<<endl;
	opcion = 0;
	cout<<"\n DESEA REALIZAR OTRA OPERACION DE CONJUNTOS (1 = Si/2 = No)? ";
	cin>>opcion;
	if(opcion == 1) {
		for(int i=0; i<4; i++) {
			VcR1[i] = VcR[i];
			VcR[i] = 0;
		}
		
		cout<<endl;
		opcion = 0;
		cout<<"Ingrese Conjunto 3: ";
		cin>>C3;
		cout<<"Ingrese Conjunto 4: ";
		cin>>C4;
		cout<<"\n Ingrese Operador logico: "<<endl;
		cout<<"1. Union "<<endl;
		cout<<"2. Interseccion "<<endl;
		cout<<"3. Diferencia"<<endl;
		cout<<"4. Diferencia simetrica "<<endl;
		cout<<"\n Que desea hacer? ";
		cin>>opcion;
		
		switch(opcion)
			{
			case 1: Operador2='U';
				operar(1);
				break;	
			case 2: Operador2='^';
				operar(2);
				break;
			case 3: Operador2='-';
				operar(3);
				break;
			case 4: Operador2='&';
				operar(4);
				break;
		}
		cout<<"\n LA OPERACION INGRESADA ES: "<<endl<<endl;
		cout<<C3<<" "<<Operador2<<" "<<C4<<endl; 	
		for(int i=0; i<4; i++)
		{
			cout<<VcR[i]<<" ";
		}
		
		for(int i=0; i<4; i++) {
			VcR2[i] = VcR[i];
			VcR[i] = 0;
		}
		
		cout<<endl;
		opcion = 0;
		cout<<"\n Ingrese Operador logico para operar conjuntos ("<<C1<<" "<<Operador1<<" "<<C2<<") y ("<<C3<<" "<<Operador2<<" "<<C4<<"): "<<endl;
		cout<<"1. Union "<<endl;
		cout<<"2. Interseccion "<<endl;
		cout<<"3. Diferencia"<<endl;
		cout<<"4. Diferencia simetrica "<<endl;
		cout<<"\n Que desea hacer? ";
		cin>>opcion;
		
		switch(opcion)
			{
			case 1: Operador3='U';
				operar2(1);
				break;	
			case 2: Operador3='^';
				operar2(2);
				break;
			case 3: Operador3='-';
				operar2(3);
				break;
			case 4: Operador3='&';
				operar2(4);
				break;
		}
		
		cout<<"("<<C1<<" "<<Operador1<<" "<<C2<<") "<<Operador3<<" ("<<C3<<" "<<Operador2<<" "<<C4<<")"<<endl; 	
		for(int i=0; i<4; i++)
		{
			cout<<VcR[i]<<" ";
		}
	}
	
	
	cout<<endl; 
	system("pause"); 
	system("cls");
	DdV();
	//DdV_relleno();
	return 0;
}

		
