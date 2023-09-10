#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int result[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX]; //거리 배열

queue<pair<int, int>> q;
int row, col;

int dx[4] = { -1 , 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void BFS()
{
	int x = 0;
	int y = 0;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	dist[x][y] = 1;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
			if (result[nx][ny] == '1' && visited[nx][ny] == false)
			{
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1; // 거리 + 1
			}
		}
	}
}

int main()
{
	cin >> row >> col;

	string road;
	for (int i = 0; i < row; i++)
	{
		cin >> road;
		for (int j = 0; j < col; j++)
		{
			result[i][j] = road[j];
		}
	}

	BFS();
	cout << dist[row-1][col-1] << "\n";

	return 0;
}