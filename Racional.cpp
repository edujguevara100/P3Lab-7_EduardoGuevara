#include "Racional.h"
#include <fstream>
#include <cmath>
using namespace std;

Racional::Racional(){
	
}

Racional::Racional(int num, int den){
	numerador = num;
	denominador = den;
	Simplificar();
}

int Racional::getDen()const {
	return denominador;
}

int Racional::getNum()const{
	return numerador;
}

const Racional Racional::operator+(const Racional& rac)const{
	int denacum,num1,num2,numf;
	denacum = denominador*rac.getDen();
	num1 = numerador*rac.getDen();
	num2 = rac.getNum()*denominador;
	numf = num1+num2;
	Racional r(numf,denacum);
	ofstream racio("Racionales.txt",ios::app);
	if(racio.is_open()){
		racio<<numerador<<"/"<<denominador<<"   +   "<<rac.getNum()<<"/"<<rac.getDen()<<"   =   "<< r.getNum()<<"/"<<r.getDen()<<endl;
		racio.close();
	}
	return r;
}

const Racional Racional::operator-(const Racional& rac)const{
	int denacum,num1,num2,numf;
	denacum = denominador*rac.getDen();
	num1 = numerador*rac.getDen();
	num2 = rac.getNum()*denominador;
	numf = num1-num2;
	Racional r(numf,denacum);
	ofstream racio("Racionales.txt",ios::app);
	if(racio.is_open()){
		racio<<numerador<<"/"<<denominador<<"   -   "<<rac.getNum()<<"/"<<rac.getDen()<<"   =   "<< r.getNum()<<"/"<<r.getDen()<<endl;
		racio.close();
	}
	return r;
}

const Racional Racional::operator*(const Racional& rac)const{
	Racional r(numerador*rac.getNum(),denominador*rac.getDen());
	ofstream racio("Racionales.txt",ios::app);
	if(racio.is_open()){
		racio<<numerador<<"/"<<denominador<<"   *   "<<rac.getNum()<<"/"<<rac.getDen()<<"   =   "<< r.getNum()<<"/"<<r.getDen()<<endl;
		racio.close();
	}
	return r;
}

const Racional Racional::operator/(const Racional& rac)const{
	Racional r(numerador*rac.getDen(), denominador*rac.getNum());
	ofstream racio("Racionales.txt",ios::app);
	if(racio.is_open()){
		racio<<numerador<<"/"<<denominador<<"   /   "<<rac.getNum()<<"/"<<rac.getDen()<<"   =   "<< r.getNum()<<"/"<<r.getDen()<<endl;
		racio.close();
	}
	return r;
}

const void Racional:: operator+=(const Racional& rac){
	int denacum,num1,num2,numf;
	denacum = denominador*rac.getDen();
	num1 = numerador*rac.getDen();
	num2 = rac.getNum()*denominador;
	numf = num1+num2;
	//numerador = numf;
	//denominador = denacum;
	//Simplificar();
	ofstream racio("Racionales.txt",ios::app);
	if(racio.is_open()){
		racio<<numerador<<"/"<<denominador<<"   +=   "<<rac.getNum()<<"/"<<rac.getDen()<<"   =   ";
		numerador = numf;
		denominador = denacum;
		Simplificar();
		racio<< numerador<<"/"<<denominador<<endl;
		racio.close();
	}
}

const void Racional:: operator-=(const Racional& rac){
	int denacum,num1,num2,numf;
	denacum = denominador*rac.getDen();
	num1 = numerador*rac.getDen();
	num2 = rac.getNum()*denominador;
	numf = num1-num2;
	//numerador = numf;
	//denominador = denominador*rac.getDen();
	//Simplificar();
	ofstream racio("Racionales.txt",ios::app);
	if(racio.is_open()){
		racio<<numerador<<"/"<<denominador<<"   -=   "<<rac.getNum()<<"/"<<rac.getDen()<<"   =   ";
		numerador = numf;
		denominador = denacum;
		Simplificar();
		racio<<numerador<<"/"<<denominador<<endl;
		racio.close();
	}
}

const void Racional:: operator*=(const Racional& rac){
	//numerador = numerador*rac.getNum();
	//denominador = denominador*rac.getDen();
	//Simplificar();
	ofstream racio("Racionales.txt",ios::app);
	if(racio.is_open()){
		racio<<numerador<<"/"<<denominador<<"   *=   "<<rac.getNum()<<"/"<<rac.getDen()<<"   =   ";
		numerador = numerador*rac.getNum();
		denominador = denominador*rac.getDen();
		Simplificar();
		racio<< numerador<<"/"<<denominador<<endl;
		racio.close();
	}
}

const void Racional:: operator/=(const Racional& rac){
	//numerador = numerador*rac.getDen();
	//denominador = denominador*rac.getNum();
	//Simplificar();
	ofstream racio("Racionales.txt",ios::app);
	if(racio.is_open()){
		racio<<numerador<<"/"<<denominador<<"   /=   "<<rac.getNum()<<"/"<<rac.getDen()<<"   =   ";
		numerador = numerador*rac.getDen();
		denominador = denominador*rac.getNum();
		Simplificar();
		racio<< numerador<<"/"<<denominador<<endl;
		racio.close();
	}
}

void Racional::Simplificar(){
	for(int k = 0; k < 100; k++){
		if(numerador>denominador){
			for(int i = 1; i <= abs(denominador); i++){
				if(numerador%i == 0 && denominador%i == 0){
					numerador = numerador/i;
					denominador = denominador/i;
				}
			}
		}else if(denominador>numerador){
			for(int i = 1; i <= abs(numerador); i++){
				if(numerador%i == 0 && denominador%i == 0){
					numerador = numerador/i;
					denominador = denominador/i;
				}
			}
		}else{
			numerador = 1;
			denominador = 1;
		}
	}
}

void Racional::write(int num, int den)const{
	ofstream racional("Racionales.txt",ios::app);
	if(racional.is_open()){
		racional<<num<<"/"<<den<<"	";
		racional.close();
	}
}
