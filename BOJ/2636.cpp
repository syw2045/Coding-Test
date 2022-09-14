#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> v;
int result[MAX][MAX];
bool visited[MAX][MAX];
bool check_cheese[MAX][MAX];

int row, col; // 행 열
int rest_cheese; // 남아 있는 치즈
int cnt; // 횟수

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void DFS(int x, int y)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue; // 좌표를 벗어난경우
		if (result[nx][ny] == 1 && check_cheese[nx][ny] == false) check_cheese[nx][ny] = true; // check될 치즈
		if (result[nx][ny] == 0 && visited[nx][ny] == false) DFS(nx, ny);
	}
}

void Remove() // 체크된 치즈를 없애는 함수
{
	v.push_back(rest_cheese); // 치즈의 개수 저장
	if (rest_cheese == 0) return;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			visited[i][j] = 0;
			if (check_cheese[i][j] == true)
			{
				check_cheese[i][j] = false;
				result[i][j] = 0;
				rest_cheese--; // 치즈를 없애면서 개수 감소
			}
		}
	}
	cnt++;
}

int main()
{
	cin >> row >> col;
	int value = 0;
  //치즈 입력
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> value;
			result[i][j] = value;
			if(value == 1) rest_cheese++;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (result[i][j] == 0 && visited[i][j] == false)
			{
				DFS(i, j);
				Remove();
				if (rest_cheese == 0) // 치즈가 다 없어졌을 경우
				{
					cout << cnt << "\n";
					cout << v[v.size() - 1] << "\n";
					return 0;
				}
			}
		}
	}
}