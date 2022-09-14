#include <iostream>

using namespace std;

int A[10];
int B[10];
int A_Score;
int B_Score;
int check[10];

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> A[i]; // A 점수 입력
	}

	for (int i = 0; i < 10; i++)
	{
		cin >> B[i]; // B 점수 입력
	}

	for (int i = 0; i < 10; i++)
	{
		if (A[i] > B[i]) A_Score += 3; // A가 이긴경우 +3점
		else if (A[i] < B[i])
		{
			B_Score += 3; // B가 이긴경우 +3점
			check[i] = 1; // B Win : 1  A Win : 0
		}
		else
		{
			A_Score += 1; // 비긴경우 +1점 씩
			B_Score += 1;
			check[i] = -1; // Draw : -1
		}
	}
	cout << A_Score << " " << B_Score << "\n";

	if (A_Score > B_Score) cout << "A\n";
	else if (A_Score < B_Score) cout << "B\n";
	else
	{
		int i = 0;
		for (i = 9; i >= 0; i--) // 총 10번 돈다.
		{
			if (check[i] == 0) // 가장 최근에 A가 이긴경우
			{
				cout << "A\n";
				break;
			}
			else if (check[i] == 1) // 가장 최근에 B가 이긴경우
			{
				cout << "B\n";
				break;
			}
		}
		if (i < 0) cout << "D\n"; // 10라운드 다 점수가 같은 경우
	}
	return 0;
}