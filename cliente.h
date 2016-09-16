#include <iostream>
#include <string>
using namespace std;
class cliente{
	private:
		string nombre;
		string id;
		double cantidad;
		int tarjeta[15];
	public:
		cliente();
		~cliente();
		cliente(string,string,double,int[]);
		string getNombre();
		void setNombre(string);
		string getId();
		void setId(string);
		double getCantidad();
		void setCantidad(double);
		int* getTarjeta();
		void setTarjeta(int[]);
		string toString()const;
};