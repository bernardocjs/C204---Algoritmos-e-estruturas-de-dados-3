#include<iostream>

using namespace std;

int main ()
{

	int N;
	int *vetor = NULL;
	cin >> N;
	vetor = new int [N];

	int *p;
	int p1 = 0;
	int i;
	p = vetor;

	for(i = 0; i < N; i++)
	{
		cin >> *p;
		if(*p > 0 && *p % 2 == 0)
		{
			p1 = p1+ 1;
		}
		p++;
	}


	cout << p1 << endl;


	delete [] vetor;

	return 0;
}
