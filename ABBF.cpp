#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;
struct nodo {
	int nro;
	struct nodo *pad;
	struct nodo *der;
	struct nodo *izq;
};
typedef struct nodo *ABB;

ABB crearNodo(int x) {
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->nro = x;
	nuevoNodo->pad = NULL;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	return nuevoNodo;
}
ABB aux=NULL;
void insertar(ABB &arbol, int x) {
	if (arbol == NULL) {
		arbol = crearNodo(x);
		arbol->pad = aux;
	}
	else if (x < arbol->nro) {
		aux = arbol;
		insertar(arbol->izq, x);
	}
	else if (x > arbol->nro) {
		aux = arbol;
		insertar(arbol->der, x);
	}
}

void preOrden(ABB arbol) {
	if (arbol != NULL) {
		cout << arbol->nro << " ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void enOrden(ABB arbol) {
	if (arbol != NULL) {
		enOrden(arbol->izq);
		cout << arbol->nro << " ";
		enOrden(arbol->der);
	}
}

void postOrden(ABB arbol) {
	if (arbol != NULL) {
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout << arbol->nro << " ";
	}
}

void verArbol(ABB arbol, int n) {
	if (arbol == NULL) {
		return;
	}
	else {
		verArbol(arbol->der, n+1);
		for (int i = 0; i<n; i++)
			cout << "   ";
		cout << arbol->nro << endl;
		verArbol(arbol->izq, n + 1);
	}
}

int NExistente(ABB arbol, int x) {
	int y;
	while (arbol != NULL) {
		if (x == arbol->nro) {
			cout << "Dato existente\n";
			system("pause");
			y = 1;
		}
		else if (x<arbol->nro) {
			arbol = arbol->izq;
			y = 0;
		}
		else {
			arbol = arbol->der;
			y = 0;
		}
	}
	return y;
}
void elim(ABB arbol, int x);
void elimNodo(ABB arbol);
void rmp(ABB arbol, ABB nnodo);
void destNodo(ABB);
ABB min(ABB arbol);

int main() {
	ABB arbol=NULL;
	int x, l, r;
	cout << "\n\tArbol binario \n\n";
	do {
		cout << "\t --Menu:--\n 1)Ingresar Arbol.\n 2)Eliminar Nodo.\n 3)Mostrar arbol y recorridos.\n 4)Salir.\n";
		cin >> r;
		switch (r) {
		case 1:
			cout << "Ingrese el nodo raiz:";
			cin >> x;
			insertar(arbol, x);
			cout << endl;
			do {
				system("cls");
				cout << "\n 1) Nuevo nodo.\n 2)No mas nodos.\n";
				cin >> l;
				switch (l) {
				case 1:
					cout << "ingrese el dato:\n";
					cin >> x;
					NExistente(arbol, x);
					if (NExistente(arbol, x) != 1) {
						insertar(arbol, x);
					}
					break;
				case 2:
					cout << "Bueno";
					break;
				default: cout << "Opcion no valida";
				}
			} while (l != 2);
			system("cls");
			break;
		case 2:
			cout << "Ingrese el dato a eliminar:";
			cin >> x;
			system("cls");
			elim(arbol, x);
			break;
		case 3:
			system("cls");
			cout << "\n Mostrando ABB \n\n";
			verArbol(arbol, 0);
			cout << "\n Recorridos del ABB";
			cout << "\n\n Inorden   :  "; enOrden(arbol);
			cout << "\n\n Pre Orden  :  "; preOrden(arbol);
			cout << "\n\n Post Orden :  "; postOrden(arbol);
			cout << endl << endl;
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "\nBye";
			break;
		default: cout << "Opcion no valida";
		}
		system("cls");
	} while (r != 4);
	return 0;
}

void elim(ABB arbol, int x) {
	if (arbol == NULL) {
		return;
	}
	else if (x < arbol->nro) {
		elim(arbol->izq, x);
	}
	else if (x > arbol->nro) {
		elim(arbol->der, x);
	}
	else {
		elimNodo(arbol);
	}
}

void elimNodo(ABB arbolel) {
	if (arbolel->izq && arbolel->der) {
		ABB m = min(arbolel->der);
		arbolel->nro = m->nro;
		elimNodo(m);
	}
	else if (arbolel->izq) {
		rmp(arbolel, arbolel->izq);
		destNodo(arbolel);
	}
	else if (arbolel->der) {
		rmp(arbolel, arbolel->der);
		destNodo(arbolel);
	}
	else {
		rmp(arbolel, NULL);
		destNodo(arbolel);
	}
}

void rmp(ABB arbol, ABB nnodo) {
	if (arbol->pad) {
		if (arbol->nro == arbol->pad->izq->nro) {
			arbol->pad->izq = nnodo;
		}
		else if (arbol->nro == arbol->pad->der->nro) {
			arbol->pad->der = nnodo;
		}
	}else{
		ABB aux, aux2;
		cout<<"Hola";
		system("pause");
		aux=arbol->der;
		aux->pad=NULL;
		aux2->izq;
		arbol=aux;
		while(arbol->izq!=NULL){
			arbol=arbol->izq;
		}
		arbol->izq=aux2;
	}
	if (nnodo) {

	}
}

void destNodo(nodo *n) {
	n->izq = NULL;
	n->der = NULL;
	delete n;
}

ABB min(ABB arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->izq) {
		return min(arbol->izq);
	}
	else {
		return arbol;
	}
}
