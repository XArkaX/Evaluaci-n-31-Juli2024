#include <iostream>
#include <queue>
#include <string>
#include<locale.h>
#include <stdlib.h>
#include<iomanip>
using namespace std;
int opc;
struct galonx
{
	string name;
	char aux;
	int galon_a, galon_c,galon_s,aux2;//unidad entrada
	float tgalon_a, tgalon_c,tgalon_s; //total de salida
	float dgalon_a, dgalon_c,dgalon_s;//descuento salida
	float m_t,m_d,m_n;//montos a pagar
	void galon()
	{
		cout<<"\t==========*******  LA  CASA  DEL  PINTOR  *******=========="<<endl;
		cout<<"\tIngrese su Nombre: ";
		cin>>name;
		do
		{
			cout<<"\tSeleccione el tipo del Galon deseado: "<<endl;
			cout<<"\t 1.Galon de Pintura de Aceite 6.200 Bs."<<endl;
			cout<<"\t 2.Galon de Pintura de Caucho 5.400 Bs."<<endl;
			cout<<"\t 3.Galon de Pintura Satinada 10.500 Bs."<<endl;
			cout<<"\tSELECCIONE UNA OPCIÓN: ";
			cin>>opc;
			switch (opc)
			{
				case 1:
					cout<<"\tCuantos Galones Quiere? ";
					cin>>aux2;
					galon_a=galon_a+aux2;
				break;
				case 2:
					cout<<"\tCuantos Galones Quiere? ";
					cin>>aux2;
					galon_c=galon_c+aux2;
				break;
				case 3:
					cout<<"\tCuantos Galones Quiere? ";
					cin>>aux2;
					galon_s=galon_s+aux2;
				break;
			}//fin del switch galon
			cout<<"\tDesea terminar su pedido? S/N: ";
			cin>>aux;
		}while(tolower(aux)!='s');//fin de do galon
		system ("pause");
		system ("cls");
	}//FIN DE GALON
	float fact()
	{
		tgalon_a=6200*galon_a;
		tgalon_c=5400*galon_c;
		tgalon_s=10500*galon_s;
		//precios total sin descuentos 
		
		dgalon_a=tgalon_a*0.20;//descuento de galon aceite
		if(galon_c>=3 && galon_c<=5)
		{
			dgalon_c=tgalon_c*0.7;
		}
		if(galon_c>=6 && galon_c<=10)
		{
			dgalon_c=tgalon_c*0.10;
		}
		if(galon_c>10)
		{
			dgalon_c=tgalon_c*0.15;
		}
		//descuentos de galon caucho
		if(galon_s>5)
		{
			dgalon_s=tgalon_s*0.12;
		}//descuento de satinado
		//TERMINAN DESCUENTOS
		m_t=tgalon_a+tgalon_c+tgalon_s;
		m_d=dgalon_a+dgalon_c+dgalon_s;
		m_n=m_t-m_d;
	}//fin calculo de factura
	
	void factura()
	{
		
		cout<<"\t==========******* FACTURA CASA DEL PINTOR *******=========="<<endl;
		cout<<"\tCliente: "<<name<<endl;
		cout<<"\tMonto Total por Galones de Aceite comprados: "<<tgalon_a<<" Bs."<<endl;
		cout<<"\tMonto Total por Galones de Caucho comprados: "<<tgalon_c<<" Bs."<<endl;
		cout<<"\tMonto Total por Galones Satinados comprados: "<<tgalon_s<<" Bs."<<endl;
		cout<<"\tTotal descuento por Galones de Aceite comprados: "<<dgalon_a<<" Bs."<<endl;
		cout<<"\tTotal descuento por Galones de Caucho comprados: "<<dgalon_c<<" Bs."<<endl;
		cout<<"\tTotal descuento por Galones Satinados comprados: "<<dgalon_s<<" Bs."<<endl;
		cout<<"\tMonto total de la Factura: "<<m_t<<" Bs."<<endl;
		cout<<"\tMonto total de Descuento: "<<m_d<<" Bs."<<endl;
		cout<<"\tMonto Neto a Pagar: "<<m_n<<" Bs."<<endl;
	}//fin de factura
};//fin destruct galonx
galonx galon;
int main ()
{
	setlocale(LC_ALL,"spanish");//AGG SIGNOS ESPECIALES
	galon.galon();
	galon.fact();
	galon.factura();
}
