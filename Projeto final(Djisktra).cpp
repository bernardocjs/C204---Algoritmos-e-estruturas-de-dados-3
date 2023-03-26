#include <iostream>
#include <list>
#include <climits>
#include <algorithm>
using namespace std;

// struct para montar o grafo
struct no
{
	int v; // vertice de destino da aresta
	int peso; // peso da aresta
};

// função que cria a aresta do grafo
void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux; // var aux para inserir as arestas em adj

	aux.v = v;
	aux.peso = p;
	adj[u].push_back(aux);
	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}

// função que calcula o menor custo dos caminhos do grafo
void dijkstra(list<no>adj[], int nVertices, int start, int end)
{
	bool intree[100];
	int distance[100];
	int parent[100];
	list<int> caminho; // lista para armazenar o caminho feito com menor custo
	int u, v;
	int destino;
	int weight;
	int dist;
	list<no>::iterator p; // iterator para varrer a lista adj
	int custo = 0; // var aux para armazenar o custo do caminho
	list<int>::iterator c;

	for(u = 1; u <= nVertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}
	distance[start] = 0;
	v = start;
	while(intree[v] == false)
	{
		intree[v] = true;
		for(p = adj[v].begin(); p != adj[v].end(); p++)
		{
			destino = p->v;
			weight = p->peso;
			if(distance[destino] > distance[v] + weight)
			{
				distance[destino] = distance[v] + weight;
				parent[destino] = v;
			}
		}
		v = 0;
		dist = INT_MAX;
		for(u = 0; u < nVertices; u++)
		{
			if(intree[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
		}
	}

	// salvando o end na var u para poder fazer o controle de parents
	u = end;
	// colocando o elemento final no primeiro lugar da fila
	caminho.push_front(end);
	// salvando o caminho na fila
	while(parent[u] != -1) // se parents for -1, quer dizer que não tem mais caminhos
	{
		caminho.push_front(parent[u]);
		u = parent[u];
	}
	// salvando o custo
	custo = distance[end]; // o custo, por ser acumulativo, é igual a distancia do último vértice

	// mostrando o vetor na ordem certa e o custo do caminho total
	cout << "Caminho escolhido: ";
	c = caminho.begin();
	while ( c != caminho.end()) // foram salvos 4 caminhos, mas no vetor as posições vão de 0 - 3
	{
		cout << *c << " ";
		c++;
	}

	cout << endl << "Tempo gasto para os caminhos: " << custo << endl;
}

int main()
{
	list<no> adj[100]; // lista de adjacencia
	int u, v; // vertices de origem e destino de cada aresta
	int peso; // peso da aresta
	int nVertices; // numero de vertices do grafo
	list<no>::iterator p; // iterator para varrer a lista de adjacência
	int orientado = 0; // 1:orientado, 0:não orientado
	int start; // vértice inicial da árvore
	int end; // vértice final da árvore

	int nitens;
	int capacidademot; //capacidade total da mochila e capacidade restante da mochila
	int peso_obj[100]; //peso dos itens
	int itens[100][100]; //itens pegos
	int y = 0; //auxiliar
	int cinicial;
	int qmotoqueiros; //quantidade de motoqueiros
	int motoqueiros[50]; //vetor de motoqueiros
	int cmochila; // capacodade da mochila
	bool pego[50]; // verificação dos obj na mochila
	int soma = 0;


	// entrando com o numero de vertices do grafo
	cout << "entre com a quantidade de casas" << endl;
	cin >> nVertices;
	cout << "Entre com a quantidade de itens" << endl;
	cin >> nitens;
	cout << "Entre com a cidade inicial" << endl;
	cin >> cinicial;
	cout << "Entre com a quantidade de motoqueiros" << endl;
	cin >> qmotoqueiros;
	cout << "Entre com a capacidade da mochila" << endl;
	cin >> cmochila;
	cout << "Insira todas as conexões entre as casas (ponto1, ponto 2, peso)" << endl;
	cin >> u >> v >> peso; // inserindo arestas
	while(u != -1 && v != -1 && peso != -1)
	{
		cria_aresta(adj, u, v, peso, orientado);
		cin >> u >> v >> peso;
	}

	for(int i = 1; i <= qmotoqueiros; i++)
	{
		cout << "Entre com a distancia do motoqueiro " << i << " do supermercado" << endl;
		cin >> motoqueiros[i];
	}




	for(int i = 1; i <= nitens; i++) // marcando os itens como não pegos
	{
		pego[i] = false;
	}


	for(int i = 1; i <= nitens + 1; i++) //input dos pesos dos objetos
	{
		if(i == cinicial)
		{
			peso_obj[i] = INT_MAX;
		}
		else
		{
			cout << "Entre com o peso do item " << i << endl;
			cin >> peso_obj[i];
		}
	}
	bool viagem[qmotoqueiros];
	//inicializando o vetor viagem
	for(int i = 1; i <= qmotoqueiros; i++)
	{
		viagem[i] = false;
	}



	for(int j = 1; j <= qmotoqueiros; j++) //repetição para cada motoqueiro
	{
		capacidademot = cmochila;
		for(int i = 1; i <= nitens + 1; i++) //repetição para cada item
		{

			if(capacidademot >= peso_obj[i] && pego[i] == false) //colocando o item na mochila
			{
				itens[y][j] = i;
				capacidademot -= peso_obj[i];
				y++;
				pego[i] = true;
			}
		}

		cout << "Uma viagem levara os itens: ";

		for(int i = 0; i < y; i++) //output do que o motoboy pegou
		{
			if(itens[i][j] != 0)
			{
				cout << itens[i][j] << " ";
			}
		}

		cout << endl;



		// saida do caminho e com cada entregador
		int t;
		for(int i = 1; i <= qmotoqueiros; i++)
		{

			int menor = 9999; // var auxiliar para definir a prioridade dos motoqueiros
			// prioridade de saida dos motoqueiros
			for(int m = 1; m <= qmotoqueiros; m++)
			{

				if(menor > motoqueiros[m] && viagem[m] == false)
				{
					menor = motoqueiros[m];
					t = m;
				}
			}
		}
		viagem[t] = true;

		//saindo do supermercado
		start = cinicial;
		for (int i = 0; i < y; i++)
		{
			if(itens[i][j] != 0)
			{
				end = itens[i][j];
				i = y;
				cout << "O motoqueiro " << t << " esta a " << motoqueiros[t] << " minutos do supermercado e fara essa viagem" << endl;
				dijkstra(adj, nVertices, start, end);
			}
		}

		//saindo da entrega anterior
		for(int i = 0; i < y; i++)
		{

			if(itens[i][j] != 0)
			{
				start = itens[i][j];
				for (int k = i + 1; k < y; k++)
				{
					if(itens[k][j] != 0)
					{
						end = itens[k][j];
						k = y;
						dijkstra(adj, nVertices, start, end);
					}
				}
			}
		}

		cout << endl;
	}


	return 0;
}
