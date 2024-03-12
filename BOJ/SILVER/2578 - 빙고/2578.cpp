#include <iostream>

using namespace std;

int bingo[5][5];
bool check[5][5];
int bingo_cnt;

void Bingo_Check(int k, int j)
{
	int cnt = 0;

	//가로
	for (int i = 0; i < 5; i++)
	{
		if (check[k][i] == true) cnt++;
		else break;
	}
	if (cnt == 5) bingo_cnt++;


	//세로
	cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		if (check[i][j] == true) cnt++;
		else break;
	}
	if (cnt == 5) bingo_cnt++;

	//대각선 좌 -> 우
	cnt = 0;
	if (k == j)
	{
		for (int i = 0; i < 5; i++)
		{
			if (check[i][i] == true) cnt++;
			else break;
		}
		if (cnt == 5) bingo_cnt++;
	}

	//대각선 우 -> 좌
	cnt = 0;
	if (k + j == 4)
	{
		for (int i = 0; i < 5; i++)
		{
			if (check[i][4-i] == true) cnt++;
			else break;
		}
		if (cnt == 5) bingo_cnt++;
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> bingo[i][j]; //빙고판 생성
		}
	}

	int value = 0;
	for (int i = 0; i < 25; i++)// 25개 입력받음
	{
		cin >> value;

		for (int k = 0; k < 5; k++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingo[k][j] == value)
				{
					check[k][j] = true;
					Bingo_Check(k, j);
					if (bingo_cnt >= 3) //동시에 2개가 늘어나서 4개가 될수도 있어서 >= 붙임
					{
						cout << i+1 << "\n";
						return 0;
					}
					else // bingo_cnt가 3이 아니라면 새로운 수를 입력받아야하므로 탈출조건을 준다
					{
						k = 5;
						j = 5;
					}
				}
			}
		}
	}

	return 0;
}