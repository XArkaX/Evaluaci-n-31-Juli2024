#include <iostream>
#include <queue>
#include <string>
#include<locale.h>
#include <stdlib.h>
#include<iomanip>
using namespace std;
int opc;//AUC DEL MENU
float nota100;//AUX PARA CLASIFICAR NOTAS
void menu ()
{
	cout<<"\t_..---====******  MENU PRINCIPAL  *****====---.._"<<endl;
	cout<<"\t1. Ingresar Notas"<<endl;
	cout<<"\t2. Informe"<<endl;
	cout<<"\t3. SALIR"<<endl;
	cout<<"\tSELECCIONE UNA OPCIÓN: ";
	cin>>opc;
	system ("pause");
	system ("cls");	
}//METODO MENU
struct notax
{
	float corte1,corte2,corte3;
	void case_1()
	{
		float aux;
		cout<<"\t_..---====******  INGRESAR NOTAS  *****====---.._"<<endl;
		do
		{
			cout<<"\tIngresar Calificacion del 1º Corte:";
			cin>>corte1;
			if (corte1<=30 && corte1>=0)
			{
				cout<<"\tIngresar Calificacion del 2º Corte:";
				cin>>corte2;
				if(corte2<=30 && corte2>=0)
				{
					cout<<"\tIngresar Calificacion del 3º Corte:";
					cin>>corte3;
					if(corte3<=40 && corte3>=0)
					{
						aux=1;
					}
					else
					{
						cout<<"\tERROR DE NOTA POR EXCEDER LOS 40 PUNTOS"<<endl;
						system ("pause");
						system ("cls");		
					}//FIN DE 3 CORTE
				}
				else
				{
					cout<<"\tERROR DE NOTA POR EXCEDER LOS 30 PUNTOS"<<endl;
					system ("pause");
					system ("cls");		
				}//FIN DE 2 CORTE
			}
			else
			{
				cout<<"\tERROR DE NOTA POR EXCEDER LOS 30 PUNTOS"<<endl;
				system ("pause");
				system ("cls");		
			}//FIN DE 1 CORTE
		}while (aux=!1);//FIN DE LOS 3 CORTES
		nota100=corte1+corte2+corte3;
	}	
};
queue <notax> cola;
notax nota;
void calificacion()
{
	if(nota100<=100)
		{
			if (nota100>=78)
			{
				cout<<"\tSu Calificacion en equivalencia de Letra es: A"<<endl;
				cout<<"\tSu Calificacion en equivalencia de Base 20 es: "<<(nota100/100)*20<<endl;
				system ("pause");
				system ("cls");	
			}//CLASIFICAR NOTAS EN A
			if (nota100>=63 && nota100<78)
			{
				cout<<"\tSu Calificacion en equivalencia de Letra es: B"<<endl;
				cout<<"\tSu Calificacion en equivalencia de Base 20 es: "<<(nota100/100)*20<<endl;
				system ("pause");
				system ("cls");	
			}//CLASIFICAR NOTAS EN B
			if (nota100>=48 && nota100<63)
			{
				cout<<"\tSu Calificacion en equivalencia de Letra es: C"<<endl;
				cout<<"\tSu Calificacion en equivalencia de Base 20 es: "<<(nota100/100)*20<<endl;
				system ("pause");
				system ("cls");	
			}//CLASIFICAR NOTAS EN C
			if (nota100<48)
			{
				cout<<"\tSu Calificacion en equivalencia de Letra es: D"<<endl;
				cout<<"\tSu Calificacion en equivalencia de Base 20 es: "<<(nota100/100)*20<<endl;
				cout<<"\tALUMNO NO APROBO LA MATERIA"<<endl;
				system ("pause");
				system ("cls");	
			}//CLASIFICAR NOTAS EN D REPROVADO
		}
		else 
		{
			cout<<"\tERROR DE NOTAS POR EXCEDER LOS 100 PUNTOS"<<endl;
			system ("pause");
			system ("cls");	
		}
}//FIN DE CLASICIFICAR NOTA
void case_2()
{	
cout<<"\t_..---====****** INFORME DE NOTAS *****====---.._"<<endl;
	cout<<"\tI CORTE"<<setw(15)<<"II CORTE"<<setw(15)<<"III CORTE"<<endl;
	while(!cola.empty())
	{
		notax cola_act=cola.front();
		cout<<"\t"<<cola_act.corte1<<setw(15)<<cola_act.corte2<<setw(15)<<cola_act.corte3<<endl;
		cout<<"\t--------------------------------------"<<endl;
		cola.pop();
	}
	system ("pause");
	system ("cls");
}//FIN DE METODO INFORME
int main ()
{
	setlocale(LC_ALL,"spanish");//AGG SIGNOS ESPECIALES
	do
	{
		menu();
		switch(opc)
		{
			case 1:
				nota.case_1();
				cola.push(nota);
				calificacion();
			break;
			case 2:
				case_2();
			break;
		}//FIN DEL SWITCH MENU
	}
	while(opc!=3);//FIN DEL DO MENU
}
