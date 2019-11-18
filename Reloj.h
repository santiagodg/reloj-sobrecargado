
#ifndef RELOJ_H
#define RELOJ_H

#include <iostream>
using namespace std;

class Reloj
{
	private:
		// Atributos
		int iHoras;
		int iMinutos;

	public:
		// Constructores
		Reloj();			// Default 12:00
		Reloj(int, int);

		// Acceso
		int getHoras();
		int getMinutos();

		// Modificación
		void setHoras(int);
		void setMinutos(int);

		// Métodos
		void toString(); 			// Formato HH:MM
		/* void horaConFormato();		// 23:40 -> 11:40 PM */

		// Operadores
		Reloj operator+(Reloj);
		Reloj operator-(Reloj);
		void operator+=(Reloj);
		void operator-=(Reloj);
		bool operator<(Reloj);
		bool operator>(Reloj);
		bool operator<=(Reloj);
		bool operator>=(Reloj);
		bool operator==(Reloj);
		bool operator!=(Reloj);
		void operator++(int);
		void operator--(int);
		friend istream& operator>>(istream&, Reloj&);
		friend ostream& operator<<(ostream&, Reloj);
};

Reloj::Reloj()
{
	iHoras = 12;
	iMinutos = 0;
}

Reloj::Reloj(int iH, int iM)
{
	iHoras = iH;
	iMinutos = iM;
}

int Reloj::getHoras()
{
	return iHoras;
}

int Reloj::getMinutos()
{
	return iMinutos;
}

void Reloj::setHoras(int iH)
{
	iHoras = iH;
}

void Reloj::setMinutos(int iM)
{
	iMinutos = iM;
}

void Reloj::toString()
{
	if (iHoras < 10)
	{
		cout << '0';

	}
	cout << iHoras;
	cout << ':';
	if (iMinutos < 10)
	{
		cout << '0';
	}
	cout << iMinutos << endl;
}

/* void Reloj::horaConFormato()
{
	char cM;
	if (iHoras < 12)
	{
		cM = 'A';
		if (iHoras == 0)
		{
			cout << "12";
		}
		else if (iHoras < 10)
		{
			cout << '0';
			cout << iHoras;
		}
		else
		{
			cout << iHoras;
		}
	}
	else
	{
		cM = 'P';
		if (iHoras == 12)
		{
			cout << iHoras;
		}
		else
		{
			cout << iHoras - 12;
		}
	}
	cout << ':';
	if (iMinutos < 10)
	{
		cout << '0';
	}
	cout << iMinutos;
	cout << cM;
	cout << 'M' << endl;
} */

Reloj Reloj::operator+(Reloj r)
{
	int iHr, iMr;
	iHr = iHoras + r.getHoras();
	iMr = iMinutos + r.getMinutos();
	if (iHr > 23)
	{
		iHr -= 24;
	}
	if (iMr > 59)
	{
		iHr++;
		iMr -= 60;
	}
	Reloj rr(iHr, iMr);
	return rr;
}

Reloj Reloj::operator-(Reloj r)
{
	int iHr, iMr;
	iHr = iHoras - r.getHoras();
	iMr = iMinutos - r.getMinutos();
	if (iHr < 0)
	{
		iHr += 24;
	}
	if (iMr < 0)
	{
		iHr--;
		iMr += 60;
	}
	Reloj rr(iHr, iMr);
	return rr;
}

void Reloj::operator+=(Reloj r)
{
	*this = *this + r;
}

void Reloj::operator-=(Reloj r)
{
	*this = *this - r;
}

bool Reloj::operator<(Reloj r)
{
	if (iHoras < r.getHoras())
	{
		return true;
	}
	else if (iHoras == r.getHoras())
	{
		if (iMinutos < r.getMinutos())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Reloj::operator>(Reloj r)
{
	if (iHoras > r.getHoras())
	{
		return true;
	}
	else if (iHoras == r.getHoras())
	{
		if (iMinutos > r.getMinutos())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Reloj::operator<=(Reloj r)
{
	if (*this < r || *this == r)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Reloj::operator>=(Reloj r)
{
	if (*this > r || *this == r)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Reloj::operator==(Reloj r)
{
	if (iHoras == r.getHoras() && iMinutos == r.getMinutos())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Reloj::operator!=(Reloj r)
{
	return !(*this == r);
}

void Reloj::operator++(int)
{
	iHoras++;
	if (iHoras > 23)
	{
		iHoras -= 24;
	}
}

void Reloj::operator--(int)
{
	iHoras--;
	if (iHoras < 0)
	{
		iHoras += 24;
	}
}

istream& operator>>(istream &is, Reloj &r)
{
	is >> r.iHoras >> r.iMinutos;
	return is;
}

ostream& operator<<(ostream &os, Reloj r)
{
	if (r.iHoras < 10)
	{
		os << '0';
	}
	os << r.iHoras << ':';
	if (r.iMinutos < 10)
	{
		os << '0';
	}
	os << r.iMinutos;
	return os;
}

#endif
