#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include<cassert>
#include <algorithm>
#include <iomanip>
#define M_PI 3.14159265358979323846

using namespace std;


double find_Q(double _a, double _b, double _c, double _d) {
	double p, q, result;
	double w2 = 2;
	double w3 = 3;
	double w9 = 9;
	double w27 = 27;
	double one_1, two_2;
	__asm {
		finit
		fld w3
		fmul _a
		fmul _c
		fld _b
		fmul _b
		fsub
		fld w3
		fmul _a
		fmul _a
		fdiv
		fstp p

		fld w2
		fmul _b
		fmul _b
		fmul _b
		fld w9
		fmul _a
		fmul _b
		fmul _c
		fsub
		fld w27
		fmul _a
		fmul _a
		fmul _d
		fadd
		fld w27
		fmul _a
		fmul _a
		fmul _a
		fdiv
		fstp q

		fld p
		fdiv w3
		fstp one_1
		fld one_1
		fmul one_1
		fmul one_1
		fstp one_1
		fld q
		fdiv w2
		fstp two_2
		fld two_2
		fmul two_2
		fadd one_1
		fstp result

	}
	return result;
}


int main() {
	setlocale(LC_ALL, "Russian");

	double a, b, c, d;
	cout << "Введите a:";
	cin >> a;
	cout << "Введите b:";
	cin >> b;
	cout << "Введите c:";
	cin >> c;
	cout << "Введите d:";
	cin >> d;
	cout << endl;

	double p = (3 * a * c - b * b) / (3 * a * a);
	double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);
	//double Q = (p / 3) * (p / 3) * (p / 3) + (q / 2) * (q / 2);
	//cout << Q << endl;
	//assert(Q >= 0);
	//Q = max(Q, 0.0);
	double Q = find_Q(a, b, c, d);
	cout << "Q = " << Q << endl;
	if (Q >= 0) {
		cout << "Q >= 0" << endl;
		cout << "Поскольку дискриминант положителен, то находим корни по формуле Кардано" << endl;
		double alpha = cbrt(-q / 2 + sqrt(Q));
		double beta = cbrt(-q / 2 - sqrt(Q));
		double y = alpha + beta;
		double y2_1 = -((alpha + beta) / 2);
		double y2_2 = ((alpha - beta) / 2) * sqrt(3);
		double x = y - b / (3 * a);
		double x_1 = y2_1 - b / (3 * a);

		cout << "x3 = " << setprecision(4) << x << endl;
		cout << "x2 = " << x_1 << " + " << y2_2 << "i" << endl;
		cout << "x3 = " << x_1 << " - " << y2_2 << "i" << endl;
	}
	else {
		cout << "Q < 0" << endl;
		cout << "Поскольку дискриминант отрицателен, то находим корни по формуле Виета" << endl;
		double cos_fi = -(q / 2) * pow((3 / (-p)), 1.5);
		double fi = acos(cos_fi);
		//cout << cos_fi << endl;
		//cout << fi << endl;

		double y_1 = 2 * sqrt(-p / 3) * cos(fi / 3);
		//cout <<"y1 = " << y_1 << endl;
		double y_2 = 2 * sqrt(-p / 3) * cos(fi / 3 + 2 * M_PI / 3);
		//cout << "y2 = " << y_2 << endl;
		double y_3 = 2 * sqrt(-p / 3) * cos(fi / 3 - 2 * M_PI / 3);
		//cout << "y3 = " << y_3 << endl;

		double x_1 = y_1 + 2.0 / 3;
		double x_2 = y_2 + 2.0 / 3;
		double x_3 = y_3 + 2.0 / 3;
		cout << "x1 = " << x_1 << endl;
		cout << "x2 = " << x_2 << endl;
		cout << "x3 = " << x_3 << endl;

	}

	return 0;
}