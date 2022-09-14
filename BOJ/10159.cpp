#include <iostream>
#include <algorithm>

#define MAX 101
#define INF 999999999

using namespace std;

int matrix[MAX][MAX];

int vertex, edge;

void Floyd()
{
	for (int i = 1; i <= vertex; i++)
	{
		for (int j = 1; j <= vertex; j++)
		{
			for (int k = 1; k <= vertex; k++)
			{
				matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
			}
		}
	}

}
int main()
{
	cin >> vertex >> edge;


	for (int i = 1; i <= vertex; i++)
	{
		for (int j = 1; j <= vertex; j++)
		{
			matrix[i][j] = INF; // 초기 배열 INF로 초기화
		}
	}

	int heavy, light = 0;
	for (int i = 0; i < edge; i++)
	{
		cin >> heavy >> light;
		matrix[heavy][light] = 1;
	}

	Floyd();

	for (int i = 1; i <= vertex; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= vertex; j++)
		{
			if (i == j) continue;
			if (matrix[i][j] == INF && matrix[j][i] == INF) cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}