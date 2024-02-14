#include <iostream>
#define MAX 100

using namespace std;

bool visited[MAX][MAX]; // 가로 세로 100

int main()
{
	int num = 0;
	cin >> num; // 입력 개수

	int X, Y = 0; // 가로 세로
	int result = 0; // 넓이

	for (int i = 0; i < num; i++)
	{
		cin >> X >> Y;
		for (int j = X; j < X + 10; j++) // 가로 + 10
		{
			for (int k = Y; k < Y + 10; k++) // 세로 + 10
			{
				if (visited[j][k] == false) // 만약 칠한적이 없다면
				{
					visited[j][k] = true; // 칠한다
					result++; // 넓이 1만큼 증가
				}
			}
		}
	}
	cout << result << "\n";
	return 0;
}