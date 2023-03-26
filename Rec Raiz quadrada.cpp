#include <iostream>

using namespace std;


float raiz(float x, float n, float e)
{
	float res;

	res = n * n - x;
	
	if (res < 0)
		res = res * -1;

	if(res <= e)
		return n;

	else
	{
		return raiz(x, (n * n + x) / (2 * n), e);
	}
}

int main()
{

	float x;
	float n; // x0
	float e;

	cin >> x >> n >> e;

	cout << raiz(x, n, e) << endl;

	return 0;
}
