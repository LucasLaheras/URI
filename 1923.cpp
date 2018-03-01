#include<iostream>
#include<vector>
#include<queue>
#include <cstdlib>
#include <map>

using namespace std;

map <string, int> nome;
map <string, int> ::iterator it;
int *nomes;

vector< vector<int> > g; // Lista de Adjac�ncia

// Algoritmo calcula a menor distancia para alcan�ar todos os vertices do grafo partindo de um vertice inicial.
vector<int> bfs(int inicio, int print){
	//para os 3 vetores a seguir, cada posi��o do vetor representa um vertice do grafo.
    vector<int> d(g.size(), -1); // Vetor de dist�ncia minima para alcan�ar o vertice.
    vector<int> p(g.size(), -1); // Vetor que armazena o pai de cada vertice.
    vector<bool> cor(g.size(), false); // Define se cada vertice ja foi encontrado ou n�o.

	queue<int> Q; // Fila que define a ordem de acesso aos vertices.

	// Inicializa��o
    cor[inicio] = true; // Define a cor do v�rtice raiz como acessado.
    d[inicio] = 0; // Define a dist�ncia da raiz para ela mesma como 0.

    Q.push(inicio); // Enfileira a raiz.
	int b = 0;
    // Enquanto a fila n�o estiver vazia.
    while(!Q.empty()){
        int u = Q.front(); // Define u como sendo o v�rtice na frente na fila.
        Q.pop(); // Desenfileira.
        //if(u == print - 1)
		//	cout << "vertice atual: " << u << endl;
		//}
		
	    // Para todo vertice adjacente � "u".
	    for(int i = 0; i < g[u].size(); i++)
		{
	        // Se o vertice adjacente � "u" n�o tiver sido encontrado.
			if(cor[g[u][i]] == false){
				//cout<<g[u][i]<<endl;
				
	            Q.push(g[u][i]); // Enfileira o vertice adjacente.
	            cor[g[u][i]] = true; // Define o vertice adjacente como encontrado.
	            d[g[u][i]] = d[u]+1; // Define a distancia minima para alcan�ar o vertice.
             	if (d[g[u][i]] <= print)
             	{
	                nomes[b] = g[u][i];
	                b++;
				}
	            p[g[u][i]] = u; // Define o pai do vertice adjacente como "u".
	        }
	    }
     //cout<<endl;

    }

    // *** OBS: O RETORNO DA FUN��O PODE SER ALTERADO CONFORME A NECESSIDADE DO PROBLEMA. ***
    return d; // Retorna o vetor peso.
}

int main(){
	int N, M;
    
	cin >> N >> M; //N = quanotos vertices s�o; M = quantas liga��es tem
	
	nomes = new int[N];
	
	string x, y;
	int vertice;

	g.resize(N+1);

	/*
    vector< vector<int> > g;
	for (int i = 0; i <= n; i++){
    	g.push_back( vector<int>(m+1, 0));// Create an empty row---declara��o de lista de adjacencia com vector
    }

    */
	int o = 1;
	
	for(int i=0;i < N; i++)
	{
		cin >> x >> y;
		if (nome.find(x) == nome.end())
		{
			nome.insert(pair <string, int> (x, o));
			o++;
		}
		if (nome.find(y) == nome.end())
		{
			nome.insert(pair <string, int> (y, o));
			o++;
		}
        //cout << nome[x] << endl;
		//cout << nome[y] << endl;
		
		g[nome[x]].push_back(nome[y]);
		g[nome[y]].push_back(nome[x]);
	}

	vector<int> dist = bfs(1, M); //passa o vetor "inicio" com o n�mero digitado
	int cont = 0;
	
	for (int i = 0; i < N; i++)
		if(nomes[i])
		{
			cont++;
		}
		
	cout << cont << endl;
	
	for(it = nome.begin(); it != nome.end(); ++it)
	{
		for (int i = 0; i < N; i++)
			if(it->second == nomes[i])
			{
				cout << it->first << endl;
			}
	}

	system("pause");
    return 0;
}
