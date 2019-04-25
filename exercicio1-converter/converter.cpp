/* slide 40 da aula 2
Algoritmo para converter uma representação de um grafo orientado sob forma de matriz de adjacência em matriz de incidência.

Passos a seguir de acordo com o pseudocódigo:

1. Ler o arquivo da matriz e preencher com o conteúdo;
2. Imprimir a matriz;
3. Verificar a quantidade de arestas;
4. Preencher com zeros;
5. Realizar a conversão;

*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	
int n, k, linha = 0, coluna = 0, arco = 0;
 
// Lendo o arquivo da matriz
	
	ifstream arquivo;
	string linhaArquivo;
	arquivo.open("matriz.txt");
		arquivo >> n;
		int matriz[n][n];
		
		// Preenchendo a matriz com conteúdo do arquivo
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{			
				arquivo >> matriz[i][j];			
			}
		}
	arquivo.close();
	
	// Imprimindo a matriz preenchida
	
	cout << "Matriz de adjacencia:" << endl;

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				printf("%2d ",matriz[i][j]); 	
			}
		cout << endl;
		}
		
printf("________________________________");

// Verificando a quantidade de arestas da matriz

int contArestas = 0;
for(int i=0; i<n; i++)
{
	for(int j=0; j<n; j++)
	{
		if(matriz[i][j] == 1)
		contArestas = contArestas +1;
	}
}
int matrizIncidencia[n][contArestas]; 

// Preenchendo a matriz com zeros

for(int i=0; i<n; i++)
{
	for(int j=0; j<contArestas; j++)
	{
		matrizIncidencia[i][j] = 0;
	}
}

// Convertendo as matrizes

while(linha <= n)
{
	while(coluna <= n)
	{
		if(matriz[linha][coluna]== 1)
		{
			arco = arco + 1;
			matrizIncidencia[linha][arco] = 1;
			matrizIncidencia[coluna][arco] = -1;
		}
		coluna = coluna +1;
	}
	coluna = 0;
	linha = linha +1;
}

cout << endl;
cout << endl;

cout << "Matriz de incidencia:" << endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<contArestas; j++)
			{	
				printf("%2d ",matrizIncidencia[i][j]); 
			}
		cout << endl;
		}
return 0;
}

