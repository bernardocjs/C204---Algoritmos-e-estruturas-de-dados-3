#include<iostream>
#include<iomanip>


using namespace std;

int main ()
{

	int N;
	int maior = -1000;
	int *vetor = NULL;
	cin >> N;
	vetor = new int [N];

	int *p;
	int i;
	p = vetor;

	for(i = 0; i < N; i++)
	{
		cin >> *p;
	if(*p>maior){
	maior = *p;	
	} 
		p++;
	}

	
		cout << maior << endl;
	

	delete [] vetor;

	return 0;
}
