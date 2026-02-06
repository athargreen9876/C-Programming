/*
Design a Cpp Program for an electrical engg simulation system to compute impedance
Z = R + jX in AC circuit
where R is resistance,
X is reactance,
Xl = 2(pie)Fl,
Xc =-1 / [2(pie)Fc],
F is frequency,
to calculate X use either inductor or capacitor as a component.
*/
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265359;

class Inductor{
	public:
		double L;

Inductor(double l){
	L = l;
}
double reactance(double f)
{
return 2 * PI * f * L;
}
};

class Capacitor{
public:
double C;
Capacitor(double c)
{
C = c;
}
double reactance(double f){
return -1 / ( 2 * PI * f * C);
}
};


class Impedance{
public:
double R;
Impedance(double r){
R = r;
}

void calculate(double f, Inductor ind){
double X = ind.reactance(f);
cout << "Impedance Z = " << R << " + j(" << X << ")" << endl;
}
void calculate(double f, Capacitor cap){
double X = cap.reactance(f);
cout << "Impedance Z = " << R << " + j(" << X << ")" << endl;
}
};

int main(){
double R, f;
cout << "Enter Resistance(ohm) R and Frequency(Hz)" << endl;
cin >> R >> f;
Impedance Z(R);
Inductor L(0.01);
cout << "Using Inductor :" << endl;
Z.calculate(f, L);
Capacitor C(100e-6);
cout << "Using Capacitor : " << endl;
Z.calculate(f, C);
 return 0;

}
