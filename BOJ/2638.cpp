#include <iostream>
#define MAX 101

using namespace std;

int result[MAX][MAX];
bool visited[MAX][MAX];
int cnt[MAX][MAX];

int row, col; // 행 열
int times; // 시간
int rest_cheese; // 남은 치즈

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1 ,1 };

void DFS(int x, int y)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
		if (result[nx][ny] == 1) cnt[nx][ny]++; // 공기와 접촉할경우
		if (result[nx][ny] == 0 && visited[nx][ny] == false) DFS(nx, ny);
	}
}

void Remove()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			visited[i][j] = false;
			if (cnt[i][j] >= 2) // 2변 이상이 만날경우
			{
				result[i][j] = 0;
				rest_cheese--; // 치즈 감소
			}
			cnt[i][j] = 0; // 변 초기화
		}
	}
	times++;
}

int main()
{
	cin >> row >> col;
	int value = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> value;
			result[i][j] = value;
			if(value == 1) rest_cheese++; // 치즈의 총 개수 구하기
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (result[i][j] == 0)
			{
				DFS(i, j);
				Remove();
				if (rest_cheese == 0) // 치즈가 다 사라지면
				{
					cout << times << "\n";
					return 0;
				}
			}
		}
	}
}