#include<iostream>
#include<iomanip>
using namespace std;

struct notas
{
	float n1[50];
	float n2[50];
	float n3[50];
	float n4[50];
	float media[50];
};

int main ()
{
	float total;
	int tam;
	int i;
	
	
	total = 0;
	cin >> tam;
	notas *p;
	p = new notas;

	for (i = 0; i < tam; i++)
	{
		cin >> p->n1[i];
		cin >> p->n2[i];
		cin >> p->n3[i];
		cin >> p->n4[i];
		p->media[i] = 1.0 * (p->n1[i] + p->n2[i] + p->n3[i] + p->n4[i]) / 4;


		total = total + p->media[i];
	}

	cout << fixed << setprecision(2) << total / tam << endl;

	delete [] p;
	return 0;

}
