#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

int result[MAX][MAX];
bool visited[MAX][MAX];

vector<int> v;
int island;
int w, h;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; // 대각선까지 포함
int dy[8] = { -1, 0, 1, 1, -1, -1, 0, 1 };

void DFS(int x, int y)
{
	visited[x][y] = true;
	island++;

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
		if (result[nx][ny] == 1 && visited[nx][ny] == false) DFS(nx, ny);
	}
}

void Reset() //초기화
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			visited[i][j] = false;
			result[i][j] = 0;
			v.clear();
		}
	}
}

int main()
{
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		int value = 0;
		for (int i = 0; i <h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> value;
				result[i][j] = value;
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (result[i][j] == 1 && visited[i][j] == false)
				{
					island = 0;
					DFS(i, j);
					if (island != 0) v.push_back(island); // 섬의 크기를 벡터에 넣는다
				}
			}
		}
		cout << v.size() << "\n"; // 섬의 개수
		Reset();
	}
	return 0;
}