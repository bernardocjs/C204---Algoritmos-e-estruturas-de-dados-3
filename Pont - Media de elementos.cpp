#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{

	int N;
	double soma = 0;
	int *vetor = NULL;
	cin >> N;
	vetor = new int [N];

	int *p;
	int i;
	p = vetor;

	for(i = 0; i < N; i++)
	{
		cin >> *p;
		soma += vetor[i];
		p++;
	}

	
		cout << 1.0*soma/N << endl;
	

	delete [] vetor;

	return 0;
}
