#include <iostream>
#include <algorithm>

#define MAX 501
#define INF 999999999

using namespace std;

int vertex, edge;
int matrix[MAX][MAX];

void Floyd() // 플로이드-와샬 알고리즘
{
	for (int i = 1; i <= vertex; i++)
	{
		for (int j = 1; j <= vertex; j++)
		{
			for (int k = 1; k <= vertex; k++)
			{
				if (matrix[j][i] != INF && matrix[i][k] != INF)
				{
					matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
				}
			}
		}
	}
}

int main()
{
	cin >> vertex >> edge;

	int a, b = 0;

	for (int i = 1; i <= vertex; i++)
	{
		for (int j = 1; j <= vertex; j++)
		{
			matrix[i][j] = INF; // 배열 초기화
		}
	}

	for (int i = 0; i < edge; i++)
	{
		cin >> a >> b;
		matrix[a][b] = 1;
	}

	Floyd();

	int result = 0;
	for (int i = 1; i <= vertex; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= vertex; j++)
		{
			if (i == j) continue;
			if (matrix[i][j] != INF || matrix[j][i] != INF) // i와 j가 비교가 가능하면
			{
				cnt++;
			}
		}
		if (cnt == vertex - 1) result++; // 자기자신을 제외한 모두와 비교가 가능하면
	}
	cout << result << "\n";
	return 0;
}