#include <iostream>
#include <iomanip>

using namespace std;


struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;

};


typedef treenode *treenodeptr;


int y;

void tInsere(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}


treenodeptr tMenor(treenodeptr &raiz)
{
	treenodeptr t;
	t = raiz;
	if (t->esq == NULL) // encontrou o menor valor
	{
		raiz = raiz->dir;
		return t;
	}
	else // continua a busca na sub´arvore esquerda
		return tMenor(raiz->esq);
}

int tRemove(treenodeptr &raiz, int x)
{
	treenodeptr p;
	if (raiz == NULL) // ´arvore vazia
		return 1;
	if (x == raiz->info)
	{
		p = raiz;
		if (raiz->esq == NULL) // a raiz n~ao tem filho esquerdo
			raiz = raiz->dir;
		else if (raiz->dir == NULL) // a raiz n~ao tem filho direito
			raiz = raiz->esq;
		else // a raiz tem ambos os filhos
		{
			p = tMenor(raiz->dir);
			raiz->info = p->info;
		}
		delete p;
		return 0;
	}
	else if (x < raiz->info)
		return tRemove(raiz->esq, x);
	else
		return tRemove(raiz->dir, x);
}

void emOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << " ";
	
		emOrdem(arvore->dir);
	}
}


int main()
{
	int x = 0;
	treenodeptr arvore = NULL;
	cin >> x;

	while(x != 0)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	cin >> y;
	
	while(tRemove(arvore, y) == 0){}
		
	emOrdem(arvore);


	return 0;
}
