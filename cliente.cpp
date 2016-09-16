#include <iostream>
#include <sstream>
#include "cliente.h"
#include <string.h>
using namespace std;

cliente::cliente(){

}

cliente::~cliente(){

}

cliente::cliente(string n,string i,double c, int t[]){
 	nombre = n;
 	id = i;
 	cantidad = c;
 	for (int i = 0; i < 16; ++i)
 	{
 		tarjeta[i]=t[i];
 	}
}

string cliente::getNombre(){
	return nombre;
}

void cliente::setNombre(string n){
	nombre = n;
}

string cliente::getId(){
	return id;
}

void cliente::setId(string i){
	id = i;
}

double cliente::getCantidad(){
	return cantidad;
}

void cliente::setCantidad(double c){
	cantidad = c;
}
int* cliente::getTarjeta(){
	return tarjeta;
}


string cliente::toString()const{
	stringstream ss;
	ss << "nombre: "<<nombre<<"\n";
	ss << "Identidad: "<<id<<"\n";
	ss << "Dinero: "<<cantidad<<"\n";
	ss << "Tarjeta: ";
	for (int i = 0; i < 16; ++i){
		ss << tarjeta[i];
	}
	ss <<"\n";
	return ss.str();
}
