#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

int matrix[MAX][MAX];
bool visited[MAX][MAX];

int row, col;
int result;

queue<pair<int, int>> q;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };

void BFS() // BFS
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		visited[x][y] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
			if (visited[nx][ny] == false && matrix[nx][ny] == 0)
			{
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				matrix[nx][ny] = matrix[x][y] + 1;
			}
		}
	}
}

int main()
{
	cin >> col >> row; // 열 , 행
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> matrix[i][j]; // 데이터 입력
			if (matrix[i][j] == 1) q.push(make_pair(i, j)); // 데이터가 1 인경우 queue에 넣는다
		}
	}

	BFS();

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0) // 만약 토마토가 익지 않았다면
			{
				cout << "-1\n";
				return 0;
			}
			if (matrix[i][j] > result)
			{
				result = matrix[i][j]; // 최대 값을 찾는다
			}
		}
	}

	cout << result - 1 << "\n"; // 시작을 "1" 부터 했기 때문에 마지막에 1을 빼준다.
	return 0;
}