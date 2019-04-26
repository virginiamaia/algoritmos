/* slide 40 da aula 2
Algoritmo para converter uma representacao de um grafo orientado sob forma de matriz de adjacencia em matriz de incidencia.

Passos seguidos:
1. Ler o arquivo da matriz e preencher com o conteudo;
2. Imprimir a matriz;
3. Verificar a quantidade de arestas;
4. Preencher com zeros;
5. Realizar a conversao;

Matriz de adjacencia:			Matriz de incidencia: 
[ 0 1 1 0 ]				  		[ 1 1 0 0 0 ]
[ 0 0 1 1 ]				  		[-1 0 1 1 0 ]
[ 0 0 0 1 ]				  		[ 0-1-1 0 1 ]
[ 0 0 0 0 ]				  		[ 0 0 0-1-1 ]

*/

#include <iostream>
#include <fstream>
using namespace std;

int main (){
	
int n;
int k;
int linha = 0;
int coluna = 0;
int arco = -1;
 
// Lendo o arquivo da matriz
	ifstream arquivo;
	string linhaArquivo;
	arquivo.open ("matriz.txt");
		arquivo >> n;
		int matriz[n][n];
		
		// Preenchendo a matriz com o conteudo do arquivo
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {			
				arquivo >> matriz[i][j];			
			}
		}
	arquivo.close();
	
	// Imprimindo a matriz preenchida
	cout << "Matriz de adjacencia:" << endl;

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				printf ("%2d", matriz[i][j]); 	
			}
		cout << endl;
		}
		
// Verificando a quantidade de arestas da matriz
int qtdArestas = 0;
for (int i = 0; i < n; i ++) {
	for (int j = 0; j < n; j ++) {
		if (matriz[i][j] == 1)
		qtdArestas = qtdArestas + 1;
	}
}

// Inicializando a matriz de incidencia
int matrizIncidencia[n][qtdArestas]; 

// Preenchendo a matriz com zeros
for (int i = 0; i < n; i ++) {
	for (int j = 0; j < qtdArestas; j ++) {
		matrizIncidencia[i][j] = 0;
	}
}

// Convertendo as matrizes
while (linha <= n) {
	while (coluna <= n) {
		if (matriz[linha][coluna] == 1) {
			arco = arco + 1;
			k = 1;
			while (k <= n) {
				matrizIncidencia[k][arco] = 0;
				k = k + 1;
			}
			matrizIncidencia[linha][arco] = 1;
			matrizIncidencia[coluna][arco] = -1;
		}
		coluna = coluna + 1;
	}
	coluna = 1;
	linha = linha + 1;
}

cout << endl;

cout << "Matriz de incidencia:" << endl;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < qtdArestas; j ++) {		
				printf ("%2d",matrizIncidencia[i][j]); 
			}
		cout << endl;
		}
return 0;
}

