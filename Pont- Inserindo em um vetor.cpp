#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{

	int N;
	int *vetor = NULL;
	cin >> N;
	vetor = new int [N];

	int *p;
	int i;
	p = vetor;

	for(i = 0; i < N; i++)
	{
		cin >> *p;
		p++;
	}
	for(i = 0; i < N; i++)
	{
		cout << vetor[i] << " ";
	}

	delete [] vetor;

	return 0;
}
