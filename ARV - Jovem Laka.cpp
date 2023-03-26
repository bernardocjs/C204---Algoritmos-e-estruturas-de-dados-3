#include <iostream>
#include <list>
using namespace std;


struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;

};


typedef treenode *treenodeptr;

int pos;
int pos2;
int pre;
int pre2;
int em;
int em2;

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

void preOrdem (int y, treenodeptr arvore)
{
	if (arvore != NULL)
	{
		pre++;
		if(arvore->info == y)
			pre2 = pre;
	//	cout <<"Pre" << arvore->info << endl;
		preOrdem(y, arvore->esq);
		preOrdem(y, arvore->dir);
	}
}


void emOrdem (int y, treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(y, arvore->esq);
			em++;
		if(arvore->info == y)
			em2 = em;
	//	cout << " Em" << arvore->info << " ";
		emOrdem(y, arvore->dir);
	}
}

void emNivel(treenodeptr t)
{
    treenodeptr n;
    list<treenodeptr> q;
    if (t!=NULL)
    {
        q.push_back(t);
        while (!q.empty())
        {
            n = *q.begin();
            q.pop_front();
            if (n->esq != NULL)
                q.push_back(n->esq);
            if (n->dir != NULL)
                q.push_back(n->dir);
            cout << n->info << " ";
        }
        cout << endl;
    }
}

void posOrdem (int y, treenodeptr arvore)
{
	if (arvore != NULL)
	{
		
		posOrdem(y, arvore->esq);
		posOrdem(y, arvore->dir);
		pos++;
		if(arvore->info == y)
		{
			pos2 = pos;
		}
	//	cout << "Pos" << arvore->info << endl;
	}
}

void tDestruir (treenodeptr &arvore)
{
if (arvore != NULL)
{
tDestruir(arvore->esq);
tDestruir(arvore->dir);
delete arvore;
}
arvore = NULL;
}



int main()
{
	int x = 0;
	
	treenodeptr arvore = NULL;

	int y;

	cin >> x;

	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	cin >> y;

	emOrdem(y,arvore);
	posOrdem(y, arvore);
	preOrdem(y, arvore);

	if(pre2 <= pos2 && pre2 <= em2)
	{
		cout << "Pre" << endl;
	}
	else if(pos2 <= pre2 && pos2 <= em2)
	{
		cout << "Pos" << endl;
	}
	else
		cout << "Em" << endl;

	tDestruir(arvore);
	return 0;
}
