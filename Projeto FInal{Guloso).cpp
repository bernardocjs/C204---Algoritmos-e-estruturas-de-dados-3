#include<iostream> 
#include<climits>
#include<list> 
using namespace std; 

int main () {
	
	// entrando com os entregadores 
	cout << "Quantos entregadores estao disponiveis?" << endl; 
	int ent; 
	cin >> ent; 
	int mot[ent]; 
	bool viagem[ent]; 
	
	// entrando com a quantidade de compras 
	cout << "Quantas entregas sao?" << endl; 
	int comp; 
	cin >> comp; 
	bool entrega[comp+1]; // ver se a compra ja foi levada ou não
	int peso[comp+1]; // peso de cada compra
	
	
	//lista para recuperar o caminho e as compras entregues
	list<int> fila[ent+1]; 
	int x; 
	
	// entrando com a distancia de cada casa:
	int n; // numero de casas
	cout << "Insira a quantidade de casas" << endl;
	cin >> n; 
	
	int custo[n][n]; // custo de cada caminho ate o outro 
	
	int inicial; // cidade onde começa 
	int total_custos=0; // aux para definir o max valor que um custo pode chegar 
	// colocando o custo de cada caminho ate o outro 
	for (int i=1; i<= n; i++) {
		for (int j=i+1; j<=n; j ++) { // o j=i+1 pois os caminhos calculados serao por exemplo N=3 // 0-1, 0-2, 0-3 / 1-2, 1-3 / 2-3
			cout << "Insira quanto tempo leva do ponto " << i << " ate o ponto " << j << endl; 
			cin >> custo[i][j]; 
			custo[j][i]=custo[i][j]; 
			total_custos+=custo[i][j]; 
		}
	}
	
	// entrando com o peso aguentado pela mochila
	int mochila; 
	cout << "Insira o peso que a mochila do entregador aguenta: " << endl; 
	cin >> mochila;

	
    // qual ponto é o supermercado, definir como ponto inicial:
	cout << "Qual ponto esta o supermercado?" << endl; 
	cin >> inicial;	
	
	// entrando com o peso de cada compra: 
	
	for(int i=1; i<=comp+1;i++) {
			if(i!=inicial) {
			cout << "Insira o peso da compra da casa " << i << endl;
			cin >> peso[i]; 
			}
			else {
				peso[i]=0; 
			}
	}
	
 	//iniciando o vetor entrega
 	for(int i=1;i<=comp+1;i++) {
		 entrega[i]=false; 
	 }
	 
	 //entrando com o tempo dos motoqueiros 
	 for(int i=1;i<=ent;i++) {
		 cout << "Insira o tempo que o motoqueiro " << i << " esta do supermercado" << endl; 
		 cin >> mot[i]; 
	 }
	 
	 //inicializando o vetor viagem 
	 for(int i=1;i<=ent;i++) {
		 viagem[i]=false; 
	 }
	 
	 
	 
	 int menor_custo[ent];  
	 int r;
	 int s=0; 
	 for(int e=1;e<=ent;e++) {
	// gulosodo caminho pra cada entregador:
	menor_custo[e]=0; 
	int custo_atual; // var auxiliar 
	int casa_atual; 
	int proxima_casa=0; 
	int pmochila=0; // peso da mochila
	casa_atual=inicial; // começa no supermercado 
	for(int i=1;i<=n;i++) { // rodando entre os caminhos dps de sair do inicial
		
		custo_atual=INT_MAX; // maior tempo que o custo pode assumir
		entrega[casa_atual]=true;
		
		for(int j=1;j<=n;j++){
			
			if(entrega[j]==false && custo_atual>custo[casa_atual][j] && (peso[j]+pmochila) <= mochila) { 
				proxima_casa=j;  
				custo_atual=custo[casa_atual][j]; 
				r=j; 
			}
		}
    if(s!=r) {
 	 s = r; 
	pmochila = pmochila+peso[r]; 
    menor_custo[e] += custo_atual;
    fila[e].push_back(r); 	
    casa_atual=proxima_casa; 
	}
	}
	
}
	 

	int tempo[ent];
	
	// saida do caminho e com cada entregador 
	int t;
	for(int i=1;i<=ent;i++) {
		
		int menor=9999; // var auxiliar para definir a prioridade dos motoqueiros
		// prioridade de saida dos motoqueiros
		for(int m=1;m<=ent;m++) {
			
			if(menor>mot[m] && viagem[m]==false) {
				menor=mot[m];  
				t=m;
			}
		}
    if(menor_custo[i]!=0) {
    tempo[i]=menor_custo[i]+ mot[t]; 
	cout << "O entregador " << t << " levou " << tempo[i] << " minutos e foram entregues as compras nessas ordens de caminho: " << inicial << " " ; 
		while(!fila[i].empty()) {
			x=*fila[i].begin(); 
			cout << x << " "; 
			fila[i].pop_front(); 
		}
		cout << endl; 
	} 
	viagem[t]=true;
	}
	
	cout << endl; 	
	
	// tempo total gasto:
	int maior=0; 
	for(int y=1;y<=ent;y++) {
		if(total_custos>menor_custo[y] && menor_custo[y]>0 && tempo[y]>maior) {
			maior = tempo[y]; 
		}
	}
	
	cout << "O tempo total gasto para realizar todas as entregas foi de: " << maior << " minutos" << endl;  
	
	 
	return 0;
	
}