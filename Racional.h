#ifndef RACIONAL_H
#define RACIONAL_H
class Racional{
	private:
		int numerador;
		int denominador;
	public:
		int getDen() const;
		int getNum() const;
		Racional();
		Racional(int,int);
		const Racional operator+(const Racional&)const;
		const Racional operator-(const Racional&)const;
		const Racional operator*(const Racional&)const;
		const Racional operator/(const Racional&)const;
		const void operator+=(const Racional&);
		const void operator-=(const Racional&);
		const void operator*=(const Racional&);
		const void operator/=(const Racional&);
		void Simplificar();	
		void write(int,int)const;
};
#endif
