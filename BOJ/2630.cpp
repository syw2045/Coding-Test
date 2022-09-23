#include <iostream>

using namespace std;

bool matrix[128][128];
int white, blue = 0;

void Calculate(int size, int x, int y)
{
	if (size == 1)
	{
		if (matrix[x][y] == 1) blue++;
		else white++;
		return;
	}

	bool onlyOne = true;
	bool onlyZero = true;
	
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if(matrix[i][j] == 0) onlyOne = false;
			if(matrix[i][j] == 1) onlyZero = false;
		}
	}

	if (onlyZero)
	{
		white++;
		return;
	}
	if (onlyOne)
	{
		blue++;
		return;
	}

	Calculate(size / 2, x, y);
	Calculate(size / 2, x + size / 2, y);
	Calculate(size / 2, x, y + size / 2);
	Calculate(size / 2, x + size / 2, y + size / 2);
}

int main()
{
	int value = 0;
	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> value;
			matrix[i][j] = value;
		}
	}

	Calculate(N, 0, 0);

	cout << white << "\n" << blue << "\n";

	return 0;
}