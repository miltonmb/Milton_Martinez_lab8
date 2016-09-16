#include <iostream>
#include <string>
#include "cliente.h"
#include <stdio.h>
#include <vector>
bool luhn(int[]);
int main(){
	vector<cliente*> clientes;
	int opcion;
	char respuesta= 'S';
	while(respuesta=='s'||respuesta=='S'){
		cout << "Que desea hacer: \n";
		cout << "1.Agregar un cliente\n";
		cout << "2.Eliminar cliente\n";
		cout << "3.Listar cliente\n";
		cout << "4.Verificar el numero de tarjeta de un cliente\n";
		cout << "5.Salir\n";
		cin >> opcion;
		switch(opcion){
			case 1:{
				string nombre,id;
				int num;
				double cantidad;
				int tarjeta[15];
				cout << "Ingrese un nombre: ";
				cin >>nombre;
				cout << endl;
				cout << "Ingrese el id: ";
				cin >> id;
				cout << endl;
				cout << "Ingrese la cantidad: ";
				cin >> cantidad;
				cout << endl;
				for (int i = 0; i <= 15; ++i)
				{
					cout << "Ingrese el numero "<<i<<" de la tarjeta: ";
					cin >> num;
					tarjeta[i]=num;
				}
				cliente* x = new cliente(nombre,id,cantidad,tarjeta);
				clientes.push_back(x);
				break;
			}

			case 2:{
				int opEl;
				cout << "A que cliente desea eliminar: \n";
				for (int i = 0; i < clientes.size(); ++i){
					cout << i<<" --- " << clientes[i]->getNombre()<<"\n";
				}
				cin >> opEl;
				clientes.erase(clientes.begin()+opEl);
				break;
			}

			case 3:{
				cout << "---CLIENTES LISTADOS---\n";
				for (int i = 0; i < clientes.size(); ++i){
					cout << clientes[i]->toString()<<"\n";
				}
				break;
			}

			case 4:{
				int opVer;
				cout << "De que cliente desea Verificar tarjeta: \n";
				for (int i = 0; i < clientes.size(); ++i){
					cout << i<<" --- " << clientes[i]->getNombre()<<"\n";
				}
				cin >> opVer;
				if(luhn(clientes[opVer]->tarjeta)){
					cout << "Es valida\n";
				}else{
					cout << "La tarjeta no es valida\n";
					clientes.erase(clientes.begin()+opVer);
				}
			}
		}
	}
}

bool luhn(int tarjeta[]) {
        int suma = 0;
        int t = 16;
        for (int i = 0; i < t; i++) {
            int num = tarjeta[t-i-1];
            if (i % 2 == 1) {
                num = num * 2;
            }
            if (num > 9) {
                num = num - 9;
            }
            suma = suma + num;
        }
        return suma % 10 == 0;
    }
