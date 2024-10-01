#include<iostream>
#include<conio.h>
#include<stdlib.h>

//Madelyn Arleth Torres Gómez 4490-22-7308

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *pa;
};

//Propotipos
void menu();
Nodo *crearNodo(int, Nodo*);
void insertarNodo(Nodo *&,int, Nodo*);
void mostrarAr(Nodo *,int);
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void Nivel(Nodo *,int);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *min(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destNodo(Nodo *);
void mostrarnivel(Nodo *, int);
int contnivel(Nodo *);

Nodo *arbol = NULL;

int main(){
	menu();
	
	getch();
	return 0;
}

//funcion menu
void menu(){
	int dato, opcion, contador=0;
	
	do{
		cout<<"\n --------------MENU---------------- "<<endl;
		cout<<"\n 1. Insertar un nuevo nodo ";
		cout<<"\n 2. Mostrar el arbol completo ";
		cout<<"\n 3. Buscar un elemento en el arbol ";
		cout<<"\n 4. Recorrer arbol en preOrden ";
		cout<<"\n 5. Recorrer arbol en inOrden ";
		cout<<"\n 6. Recorrer arbol en postOrden ";
		cout<<"\n 7. Recorrer arbol por niveles ";
		cout<<"\n 8. Eliminar nodo de un arbol ";
		cout<<"\n 9. Salir "<<endl;
		cout<<"\n Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\n Digite un numero: ";
				cin>>dato;
				insertarNodo(arbol,dato,NULL);
				cout<<"\n";
				system("pause");
				break;
			case 2: cout<<"\n Mostrar el arbol:\n\n";
				mostrarAr(arbol,contador);
				cout<<"\n";
				system("pause");
				break;
			case 3: cout<<"\n Disgite el elemento a buscar: ";
				cin>>dato;
				if(busqueda(arbol,dato) == true){
					cout<<"\n Elemento "<<dato<<" ha sido encontrado\n";
				}
				else{
					cout<<"\n Elemento no encontrado\n";
				}
				cout<<"\n";
				system("pause");
				break;
			case 4: cout<<"\n Recorrido en preorden: ";
				preOrden(arbol);
				cout<<"\n";
				system("pause");
				break;
			case 5: cout<<"\n Recorrido en inorden: ";
				inOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 6: cout<<"\n Recorrido en postorden: ";
				postOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 7: 
				for(int i=0; i<contnivel(arbol); i++){
				cout<<"\n Recorrido por Nivel: "<<i<<endl;
				mostrarnivel(arbol, i);
				cout<<"\n ";
				}
				system("pause");
				break;
			case 8: cout<<"\n Ingrese el numero a eliminar: ";
				cin>>dato;
				eliminar(arbol,dato);
				cout<<"\n";
				system("pause");
				break;
		}
		system("cls");	
	}while(opcion != 9);
}

//funcion para crear un nuevo nodo
Nodo *crearNodo(int n, Nodo *pa){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->pa = pa;
	
	return nuevo_nodo;
}
	
//funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol, int n, Nodo *pa){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n, pa);
		arbol = nuevo_nodo;
	}
	else{ 
		int valraiz = arbol->dato;
		if(n < valraiz){
			insertarNodo(arbol->izq,n,arbol);
		}
		else{
			insertarNodo(arbol->der,n,arbol);
		}
	}
}

//funcion mostrar arbol
void mostrarAr(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarAr(arbol->der,cont+1);
		for(int i=0; i<cont; i++){
			cout<<"   ";
		} 
		cout<<arbol->dato<<endl;
		mostrarAr(arbol->izq,cont+1);
	}
}

//funcion para buscar un elemento en el arbol
bool busqueda(Nodo *arbol, int n){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato == n){
		return true;
	}
	else if(n < arbol->dato){
		return busqueda(arbol->izq, n);
	}
	else{
		return  busqueda(arbol->der,n);
	}
}

//funcion para recorrido profundidad - preorden
void preOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

//funcion para recorrido profundidad - inorden
void inOrden(Nodo * arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
}

//funcion para recorrido profundidad - postorden
void postOrden(Nodo * arbol){
	if(arbol == NULL){
		return;
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}

//funcion para recorriddo por nivel 
int contnivel(Nodo *arbol){
	if(arbol != NULL){
		int izq= contnivel(arbol->izq) +1;
		int der= contnivel(arbol->der) +1;
		if(izq>der){
			return izq;
		}else{
			return der;
		}
	}
}

void mostrarnivel(Nodo *arbol, int ni){
	if(arbol != NULL){
		if(ni==0){
			cout<<arbol->dato<<" ";
		}
		mostrarnivel(arbol->izq, ni-1);
		mostrarnivel(arbol->der, ni-1);
	}
}

//eliminar un nodo
void eliminar(Nodo *arbol, int n){
	if(arbol == NULL){
		return;
	}
	else if(n < arbol->dato){
		eliminar(arbol->izq,n);
	}
	else if(n > arbol->dato){
		eliminar(arbol->der,n);
	}
	else{
		eliminarNodo(arbol);
	}
}

//funcion determinar izq 
Nodo *min(Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq){
		return min(arbol->izq);
	}
	else{
		return arbol;
	}
}

//funcio reemplazar nodos
void reemplazar(Nodo *arbol, Nodo*nuevoNodo){
	if(arbol->pa){
		if(arbol->dato == arbol->pa->izq->dato){
			arbol->pa->izq = nuevoNodo;
		}		
		else if(arbol->dato == arbol->pa->der->dato){
			arbol->pa->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->pa = arbol->pa;
	}
}

//funcion destruir nodo
void destNodo(Nodo * nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	
	delete nodo;
}

//funcion para eliminar nodo encotrado
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor = min(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izq){
		reemplazar(nodoEliminar,nodoEliminar->izq);
		destNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar,nodoEliminar->der);
		destNodo(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar,NULL);
		destNodo(nodoEliminar);
	}
}
