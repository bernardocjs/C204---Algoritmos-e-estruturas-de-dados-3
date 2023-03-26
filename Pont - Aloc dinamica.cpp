#include<iostream>
#include<iomanip>
using namespace std;

struct dado
{
	double media;
	int n1;
	int n2;
	int n3;
	int n4;
};

int main ()
{
	dado *p;

	p = new dado;

	//entradas
	cin >> p->n1;
	cin >> p->n2;
	cin >> p->n3;
	cin >> p->n4;

	//calc da media
	p->media =1.0*(p->n1 + p->n2 + p->n3 + p->n4) / 4;
	
	//saidas do programa
	cout << fixed << setprecision(2) << p->media << endl;
	
	delete p;
	return 0;
}
