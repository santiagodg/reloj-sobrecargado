#include "Reloj.h"

#include <iostream>
using namespace std;

int main()
{
	Reloj r1, r2;
	int iOpcion;
	do
	{
		cout << "MENU" << endl;
		cout << "1) Leer reloj1 >>" << endl;
		cout << "2) Leer reloj2 >>" << endl;
		cout << "3) Suma reloj1 + reloj2" << endl;
		cout << "4) Resta reloj2 - reloj1" << endl;
		cout << "5) Suma al reloj1 += reloj2" << endl;
		cout << "6) Resta al reloj2 -= reloj1" << endl;
		cout << "7) reloj1 > reloj2" << endl;
		cout << "8) reloj1 >= reloj2" << endl;
		cout << "9) reloj1 < reloj2" << endl;
		cout << "10) reloj1 <= reloj2" << endl;
		cout << "11) reloj1 == reloj2" << endl;
		cout << "12) reloj1 != reloj2" << endl;
		cout << "13) Suma al reloj1++" << endl;
		cout << "14) Resta al reloj2--" << endl;
		cout << "15) Terminar" << endl;
		cout << "Ingrese la opción deseada: ";
		cin >> iOpcion;
		switch (iOpcion)
		{
			case 1:
			{
				cout << "Ingrese la hora (HH MM): ";
				cin >> r1;
				break;
			}
			case 2:
			{
				cout << "Ingrese la hora (HH MM): ";
				cin >> r2;
				break;
			}
			case 3:
			{
				cout << (r1 + r2) << endl;
				break;
			}
			case 4:
			{
				cout << (r2 - r1) << endl;
				break;
			}
			case 5:
			{
				r1 += r2;
				break;
			}
			case 6:
			{
				r2 -= r1;
				break;
			}
			case 7:
			{
				cout << (r1 > r2 ? "true" : "false") << endl;
				break;
			}
			case 8:
			{
				cout << (r1 >= r2 ? "true" : "false") << endl;
				break;
			}
			case 9:
			{
				cout << (r1 < r2 ? "true" : "false") << endl;
				break;
			}
			case 10:
			{
				cout << (r1 <= r2 ? "true" : "false") << endl;
				break;
			}
			case 11:
			{
				cout << (r1 == r2 ? "true" : "false") << endl;
				break;
			}
			case 12:
			{
				cout << (r1 != r2 ? "true" : "false") << endl;
				break;
			}
			case 13:
			{
				r1++;
				break;
			}
			case 14:
			{
				r2--;
				break;
			}
			case 15:
			{
				break;
			}
			default:
			{
				cout << "Opcion invalida." << endl;
				cout << "Ingrese otra opcion: ";
				cin >> iOpcion;
			}
		}
	} while (iOpcion != 15);
	return 0;
}