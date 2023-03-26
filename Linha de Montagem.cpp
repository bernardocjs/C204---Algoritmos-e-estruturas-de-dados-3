#include <iostream>
#include <list>
using namespace std;

int main()
{
	//Variaveis de entrada
	int n; // numero de maquinas por linha
	int tMesmLinha[2][100]; // tMesmLinha[i][j]: tempo de processamento da maquina j da linha i -> tMesmLinha[0,4] = 8
	int tOutLinha[2][100]; //tOutLinha[i][j]: tempo pra ir da maquina j da linha i para a outra linha -> tOutLinha[0,4] = 4
	int entrada[2]; // entrada[i]: tempo de entrar na linha i
	int saida[2]; // saida[i]: tempo para sair da linha i
	
	////Variaveis que serão calculadas
	int tempAcumulado[2][100]; // menor tempo para levar um chassi desde a entrada até a estacao da linha "i" e maquina "j" -> tempAcumulado[0,4]
	int linhaUsada[2][100]; // linha cuja estacaoo j-1 eh usada como o caminho mais rapido atraves da estacao da linha "i" e maquina "j" -> dois valores 0 ou 1 
	
	int menorTotal; // f* -> menor tempo total
	int melhorSaida; // l* -> linha cuja ultima estacao eh usada como o caminho mais rapido atraves de toda a fabrica
	
	// Entrada
	cout << "Entre com o numero de maquinas em cada linha: " << endl;
	cin >> n;
	
	for(int i = 0;i < 2; i++)
	{
		cout << "Entre com o custo para entrar na linha " << i << endl;
		cin >> entrada[i];
	}
	
	for(int i = 0;i < 2; i++)
		for(int j = 0;j < n; j++)
		{
			cout << "Entre com o tempo de operacao da maquina " << j << " da linha " << i << endl;
			cin >> tMesmLinha[i][j];
		}
		
	for(int i = 0;i < 2; i++)
		for(int j = 0;j < n-1; j++)
		{
			cout << "Entre com o tempo para mudar para a linha " << i << " a partir da maquina " << j << endl;
			cin >> tOutLinha[i][j];
		}	
		
	for(int i = 0;i < 2; i++)
	{
		cout << "Entre com o custo para sair da linha " << i << endl;
		cin >> saida[i];
	}
	
	// PROGRAMACAO DINAMICA
	// inicializacao
	int custo1, custo2;

	// caso base
	tempAcumulado[0][0] = entrada[0] + tMesmLinha[0][0]; //caso base
	tempAcumulado[1][0] = entrada[1] + tMesmLinha[1][0]; //case base
	linhaUsada[0][0] = -1; 
	linhaUsada[1][0] = -1;
	
	
	// caso geral
	for (int maq = 1;maq < n; maq++) // A maquina 0 já foi processada no caso base
	{
		for(int linha = 0;linha < 2; linha++)
		{
			// calculo os custos para continuar na linha ou mudar
			// O(n)
			if(linha == 0)
			{
				custo1 = tempAcumulado[0][maq-1] + tMesmLinha[0][maq]; //manter na linha 0
				custo2 = tempAcumulado[1][maq-1] + tOutLinha[1][maq-1] + tMesmLinha[0][maq]; //trocar de linha 
			}
			else //linha = 1
			{
				custo1 = tempAcumulado[1][maq-1] + tMesmLinha[1][maq]; //manter na linha 1
				custo2 = tempAcumulado[0][maq-1] + tOutLinha[0][maq-1] + tMesmLinha[1][maq]; //trocar de linha
			}

			// avalio qual eh melhor
			if(custo1 < custo2) // manter na linha
			{
				tempAcumulado[linha][maq] = custo1;
				linhaUsada[linha][maq] = linha;
			}
			else // (cussto2 < custo 1) trocar de linha
			{
				tempAcumulado[linha][maq] = custo2;
				if(linha == 0)
					linhaUsada[linha][maq] = 1;
				else
					linhaUsada[linha][maq] = 0;
			}
		}	
	}
	
	// calculo para sair da linha de producao
	tempAcumulado[0][n] = tempAcumulado[0][n-1] + saida[0];  //(0,6)
	linhaUsada[0][n] = 0; 
	tempAcumulado[1][n] = tempAcumulado[1][n-1] + saida[1]; //(1,6)
	linhaUsada[1][n] = 1;

	// analise do melhor tempo total
	if(tempAcumulado[0][n] < tempAcumulado[1][n])
	{
		menorTotal = tempAcumulado[0][n];
		melhorSaida = 0;
	}
	else
	{
		menorTotal = tempAcumulado[1][n];
		melhorSaida = 1;
	}

	// Resposta
	cout << "Menor tempo necessario para producao: " << menorTotal << endl;
	cout << "Melhor saida pela linha: " << melhorSaida << endl;

	// Recuperação do caminho
	// Caminho contrario 
	int i = melhorSaida;
	for(int j = n-1; j>= 1; j--){
		i = linhaUsada[i][j];
		cout << "linha " << i << " estacao " << j-1 << endl;
	}
	
	
	return 0;	
}