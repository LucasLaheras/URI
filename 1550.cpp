#include<iostream>
#include<vector>
#include<queue>
#include <cstdlib>

using namespace std;

vector< vector<int> > g; // Lista de Adjac�ncia

// Algoritmo calcula a menor distancia para alcan�ar todos os vertices do grafo partindo de um vertice inicial.
vector<int> bfs(int inicio, int final){
	//para os 3 vetores a seguir, cada posi��o do vetor representa um vertice do grafo.
    vector<int> d(g.size(), -1); // Vetor de dist�ncia minima para alcan�ar o vertice.
    vector<int> p(g.size(), -1); // Vetor que armazena o pai de cada vertice.
    vector<bool> cor(g.size(), false); // Define se cada vertice ja foi encontrado ou n�o.

	queue<int> Q; // Fila que define a ordem de acesso aos vertices.

	// Inicializa��o
    cor[inicio] = true; // Define a cor do v�rtice raiz como acessado.
    d[inicio] = 0; // Define a dist�ncia da raiz para ela mesma como 0.

    Q.push(inicio); // Enfileira a raiz.

    // Enquanto a fila n�o estiver vazia.
    while(!Q.empty()){
        int u = Q.front(); // Define u como sendo o v�rtice na frente na fila.
        Q.pop(); // Desenfileira.
		//cout<<"vertice atual: "<<u<<endl;
        // Para todo vertice adjacente � "u".
        for(int i = 0; i < g[u].size(); i++){
            // Se o vertice adjacente � "u" n�o tiver sido encontrado.
			if(cor[g[u][i]] == false){
				//cout<<g[u][i]<<endl;
                Q.push(g[u][i]); // Enfileira o vertice adjacente.
                cor[g[u][i]] = true; // Define o vertice adjacente como encontrado.
                d[g[u][i]] = d[u]+1; // Define a distancia minima para alcan�ar o vertice.
                if (g[u][i] == final)
                    cout<< d[g[u][i]] <<endl;
                p[g[u][i]] = u; // Define o pai do vertice adjacente como "u".
            }
        }
    }

    // *** OBS: O RETORNO DA FUN��O PODE SER ALTERADO CONFORME A NECESSIDADE DO PROBLEMA. ***
    return d; // Retorna o vetor peso.
}


int main(){
 	int n;

	cin>>n;

	g.resize(10000 + 1);

	/*
    vector< vector<int> > g;
	for (int i = 0; i <= n; i++){
    	g.push_back( vector<int>(m+1, 0));// Create an empty row---declara��o de lista de adjacencia com vector
    }

    */
	int NUM, NUM1, NUM2, NUM3, NUM4;
	
	for(int i = 0; i < 10000; i++)
	{
		g[i].push_back(i + 1);
        if(i > 9)
		{
            NUM = i;
		  	NUM1 = NUM % 10;
		  	NUM = NUM / 10;
		  	NUM2 = NUM % 10;
		  	NUM = NUM / 10;
		  	NUM3 = NUM % 10;
		  	NUM = NUM / 10;
		  	NUM4 = NUM % 10;
		  	
		  	if (NUM4 == 0 && NUM3 == 0)
		  	    NUM = NUM1 * 10 + NUM2;
     		else if (NUM4 == 0 )
		  	    NUM = NUM1 * 100 + NUM2 * 10 + NUM3;
         	else
		  		NUM = NUM1 * 1000 + NUM2 * 100 + NUM3 * 10 + NUM4;
		  		
		  	g[i].push_back(NUM);
		}
		
	}

	int N, M;
	
	for (int i = 0; i < n; i++)
	{
		cin >> M >> N;
		
		vector <int> dist = bfs(M, N); //passa o n�mero inicial e o n�mero final

	}


	system("pause");
    return 0;
}
