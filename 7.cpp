#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double x_1 = 0, x_2 = 0.2, x_3 = -1 / 3, x1 = x_1, x2 = x_2, x3 = x_3, eps = 0.0001;
	for(int i = 0; i < 10;i++)
	{
		x_1 = x1;
		x_2 = x2;
		x_3 = x3;
		x1 = 2 * x2 / 3 + 5 * x3 / 3;
		x2 = 0.2 + 0.2 * x1 - 0.4 * x3;
		x3 = -1 / 3 + 2 * x1 / 3 + 2 * x2 / 3;
	} 
	cout << "Корни " << x1 << ", " << x2 << ", " << x3 << endl;
}