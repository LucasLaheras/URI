#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <algorithm>
#include <string>


#define INF -1 // N�o descoberto (desconexo).
#define NUL -2 // Orf�o (raiz).
#define PRETO 0 // Descendentes j� est�o pretos ou n�o tem descendentes.
#define CINZA 1 // Descoberto.
#define BRANCO 2 // N�o descoberto.


int *cor;
int *predescessor;
int *descoberta; // Tempo de descoberta
int *termino; // Tempo de t�rmino
int tempo; // "Rel�gio"

using namespace std;

vector<int> *g;


void DFS_visit(int vA)
{
     int vB;
     vector<int>::iterator it;
     cor[vA] = CINZA; // Pinta de cinza o v�rtice que est� sendo avaliado no momento, o que significa que ele acaba de ser descoberto.
     tempo++; // O tempo passa, uma vez que a chamada desta fun��o representa o percorrimento de uma aresta (afastando-se da raiz).
     descoberta[vA] = tempo; // Guarda o tempo em que o v�rtice foi descoberto. Em outras palavras, guarda o tempo em que a busca em profundidade passa pelo v�rtice pela primeira vez.

     for(it = g[vA].begin(); it != g[vA].end(); it++){ // Varre o vector, passando por todos os v�rtices adjacentes ao v�rtice u.

         vB = *it; // Recebe o valor para que o iterador est� apontando
         if(cor[vB] == BRANCO){ // Se o v�rtice(vB) adjacente �quele que est� sendo avaliado(vA) ainda n�o tiver sido descoberto (branco).

			 printf("%c,", vB);
             predescessor[vB] = vA; // O predecessor do v�rtice adjacente se torna o v�rtice que est� sendo avaliado pela fun��o(vA).
             DFS_visit(vB); // A fun��o � chamada, recursivamente, para avaliar o v�rtice adjacente.
         }
         else cout << endl;
     }

     cor[vA] = PRETO; // Pinta de preto o v�rtice que est� sendo avaliado pela fun��o, j� que todos os v�rtices descendentes dele j� foram completamente avaliados (e tamb�m pintados de preto).
     termino[vA] = tempo; // Guarda o tempo em que todos os v�rtices descendentes daquele que est� sendo avaliado (vA) s�o completamente avaliados (e tamb�m pintados de preto). Em outras palavras, guarda o tempo em que a busca em profundidade passa pelo v�rtice pela segunda vez.
     tempo++; // O tempo passa, uma vez que o fim desta fun��o representa o percorrimento de uma aresta (aproximando-se da raiz).
}


void DFS(int numeroDeVertices, int raiz){
    // Aloca��o din�mica
    cor = new int[numeroDeVertices];
    predescessor = new int[numeroDeVertices];
    descoberta = new int[numeroDeVertices];
    termino = new int[numeroDeVertices];

    int vA;

    for(vA=0; vA < numeroDeVertices; vA++){ // Coloca os valores iniciais em todas as posi��es dos vetores cor, descoberta e predecessor.

        cor[vA] = BRANCO;
        descoberta[vA] = INF;
        predescessor[vA] = NUL;
    }

    tempo = -1; // Inicia tempo como -1 pois, como a fun��o DFS_visit o incrementa em seu inicio, o valor deste ser? 0 na execu��o da fun��o para o primeiro v�rtice (raiz).
    for(int i=1; i <= numeroDeVertices; i++){
		if(cor[i]==BRANCO)
    		DFS_visit(i); // Chama uma segunda fun��o, que ser� utilizada recursivamente, enviando o v�rtice raiz como par�metro.
	}
}


int main(){
	int T;
	cin >> T;
	for (int j = 0; j < T;  j++)
	{
		int N,M;
		cin >> N >> M;
	    g = new vector<int> [130];
	    /*
	    vector< vector<int> > g;
		for (int i = 0; i <= n; i++){
	    	g.push_back( vector<int>(m+1, 0));// Create an empty row---declara��o de lista de adjacencia com vector
	    }

	    */

	    char x,y;
	    
		for(int i=0;i<M;i++)
		{
			cin >> x >> y;
			g[x].push_back(y);
	  		g[y].push_back(x);
		}
		
		cout << "Case #" << j+1 << ":" << endl;
		
		DFS(130, 97); //primerio par�metro = tamanho do grafo; segundo par�metro = v�rtice inicial
		/*for(int i=1;i<=N;i++){
			cout<<i<<" = "<<descoberta[i]<<endl;
		}*/
	}
	system ("pause");
    return 0;
}
