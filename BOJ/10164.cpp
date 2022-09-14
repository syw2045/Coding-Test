#include <iostream>

using namespace std;

int arr[16][16];
bool point[16][16];
int N, M, X, Y;
int Check;


void Cal_no(int X, int Y) // 경유지가 없는 경우
{
	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Y; j++)
		{
			if (i == 1 || j == 1) arr[i][j] = 1;
			else arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	cout << arr[N][M] << "\n";
}

void Cal_yes(int X, int Y) // 경유지가 있는 경우
{
	// 경유지 까지의 경우의수 구하기
	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Y; j++)
		{
			if (i == 1 || j == 1) arr[i][j] = 1; // 맨 처음 경우의수를 1로 고정한다.
			else arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			// 그 외의 경우의수는 왼쪽 칸 + 위쪽 칸 이다.
		}
	}

	// 경유지 부터 목적지 까지의 경우의 수 구하기
	for (int i = X; i <= N; i++)
	{
		for (int j = Y; j <= M; j++)
		{
			if (i == X || j == Y) arr[i][j] = arr[X][Y];
			else arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	cout << arr[N][M] << "\n";
}

int main()
{
	cin >> N >> M >> Check;
	if (Check != 0)
	{
		if (Check % M == 0) // point 좌표 구하기
		{
			X = Check / M;
			Y = M;
		}
		else
		{
			X = Check / M + 1;
			Y = Check % M;
		}
		point[X][Y] = true; // 거쳐 가는 점 체크
		Cal_yes(X, Y); // 경유지가 있는 경우
	}
	else Cal_no(N, M); // 경유지가 없는 경우

	return 0;
}