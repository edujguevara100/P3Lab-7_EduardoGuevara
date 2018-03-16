#include <iostream>
#include "Racional.h"
#include <vector>
using namespace std;
int menu();
const Racional Select1(vector<const Racional*>);
const Racional Select2(vector<const Racional*>);
void show(vector<const Racional*>);

int main(){
	int op = 0;
	int den, num;
	vector<const Racional*> racionales;
	while(op != 6){
		Racional* r,r1,r2;
		Racional r3;
		switch(op = menu()){
			case 1:
				if(racionales.size() > 1){
					r1 = Select1(racionales);
					r2 = Select2(racionales);
					r3 = r1+r2;
					r1+=r2;
					cout<<r3.getNum()<<"/"<<r3.getDen()<<endl;
				}else{
					cout<<"No hay suficientes numeros racionales guardados"<<endl;
				}
				break;
			case 2:
				if(racionales.size() > 1){
					r1 = Select1(racionales);
					r2 = Select2(racionales);
					r3 = r1-r2;
					r1-=r2;
					cout<<r3.getNum()<<"/"<<r3.getDen()<<endl;
				}else{
					cout<<"No hay suficientes numeros racionales guardados"<<endl;
				}	
				break;
			case 3:
				if(racionales.size() > 1){
					r1 = Select1(racionales);
					r2 = Select2(racionales);
					r3 = r1*r2;
					r1*=r2;
					cout<<r3.getNum()<<"/"<<r3.getDen()<<endl;
				}else{
					cout<<"No hay suficientes numeros racionales guardados"<<endl;
				}
				break;
			case 4:
				if(racionales.size() > 1){
					r1 = Select1(racionales);
					r2 = Select2(racionales);
					r3 = r1/r2;
					r1/=r2;
					cout<<r3.getNum()<<"/"<<r3.getDen()<<endl;
				}else{
					cout<<"No hay suficientes numeros racionales guardados"<<endl;
				}
				break;
			case 5:
				cout<<"Ingrese el numerador"<<endl;
				cin>>num;
				cout<<"Ingrese el denominador"<<endl;
				cin>>den;
				racionales.push_back(new Racional(num,den));
				break;
			case 6:
				break;
		}
	}
	return 0;
}

int menu(){
	int op;
	cout<<"1: Sumar Racionales"<<endl
		<<"2: Restar Racionales"<<endl
		<<"3: Multiplicar Racionales"<<endl
		<<"4: Dividir Racionales"<<endl
		<<"5: Crear Racionales"<<endl
		<<"6: Salir"<<endl;
	cin>>op;
	return op;
}

const Racional Select1(vector<const Racional*> r){
	int op = 0;
	while(op < 0 || op >= r.size()){
		show(r);
		cin>>op;
		op--;
	}
	return *r[op];
}

const Racional Select2(vector<const Racional*> r){
	int op = 0;
	while(op < 0 || op >= r.size()){
		show(r);
		cin>>op;
		op--;
	}
	return *r[op];
}

void show(vector<const Racional*> r){
	for(int i = 0; i < r.size(); i++){
		cout<<i+1<<": "<<r[i]->getNum()<<"/"<<r[i]->getDen()<<endl;
	}
}
