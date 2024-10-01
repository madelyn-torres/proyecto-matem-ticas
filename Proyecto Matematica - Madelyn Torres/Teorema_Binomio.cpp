#include <iostream>
#include <cmath>    
#include <cstdlib>  
using namespace std;

//Madelyn Arleth Torres Gómez 4490-22-7308
 
 float cmb(int n,int p) {
    int i;
    if (n < 0 || p < 0 || p > n){
		return 0;
	} 
	
    float c = 1;
    if ( p > n / 2)
        p = n - p;
    for ( p; p>=1; p--,n--)
    c*= n / p;
    return c;
}

main(){
	
    long int n, c, d, p, nume, y, k=0, exp, n1, n2;
    char sg, v1, v2;
    
    cout<<"Teorema del Binomio"<<endl;
    
    cout<<"\n Ingrese exponente de la ecuacion: ";
    cin>>exp;
 
    cout<< "\n Ingrese primer termino numerico: ";
    cin>>n1;
    
    cout<< "\n Ingrese primer variable: ";
    cin>>v1;
    
    cout<< "\n Ingrese segundo termino numerico: ";
    cin>>n2;
    
   	cout << "\nIngrese segunda variable: ";
   	cin>>v2;
    
    n = exp;
    c = n1;
    d = n2;
    
    cout<<endl;
	cout<<"\n El Producto Notable ("<<n1<<v1<<"+"<<n2<<v2<<")^"<<exp<<" es...";
	cout<<endl<<endl;
    
    for (p=0; p<=n; p++, k++)
    {
    	
        nume = cmb(n,p);
        y = n - p;
        if ( p % 2 == 0)
            sg='+';
    
        if ( p == 0 )
            cout<<sg<<pow(c,n)<<" "<<v1<<"^"<< n;
            
        else if ( p==n)
            cout<<" "<<sg<< pow(d,n)<<" "<<v2<<"^"<<p;
            
       else {
        	cout <<sg<<nume*pow(c,n-k)*pow(d,k)<<" "<<v1<<"^"<<y<< " * " <<v2<<"^"<< p  ;
       }
     }
     
     cout<<"\n\n";
     cout<<"\n Ingrese posicion que deseas averiguar: ";
     cin>>p;
     cout<<endl;
     k = p;
     nume = cmb(n, p);
     y = n - p;
     
     if ( p % 2 == 0)
            sg='+';
     
     if (p == 0){
     	cout<<sg<<pow(c, n)<<" "<<v1<<"^"<<n<<" ";
	 }
	 else if (p == n){
	 	cout<<" "<<sg<<pow(d, n)<<" "<<v2<<"^"<<p;
	 }
	 else {
        	cout<<" "<<sg<<nume*pow(c,n-k)*pow(d,k)<<" "<<v1<<"^"<<y<<"*"<<v2<<"^"<<p ;
       }
    
	cout <<"\n"; 
    system("pause") ;
    return 0;
}
