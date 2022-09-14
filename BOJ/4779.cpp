#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<char> v;

void cantor(int start, int end)
{
	if (end - start == 1) return; // 길이가 1이라면 종료

	int erase_start = start + (end - start) / 3; // Erase 시작 지점
	int erase_end = end - (end - start) / 3; // Erase 끝 지점

	for (int i = erase_start; i < erase_end; i++)
	{
		v[i] = ' ';
	}

	cantor(start, erase_start);
	cantor(erase_start + (end - start) / 3, end);
}

int main()
{
	int N = 0;
	while (cin >> N) // 계속 입력을 받음
	{
		// 문자열 생성
		for (int i = 0; i < pow(3, N); i++)
		{
			v.push_back('-');
		}

		// 칸토어 집합 계산
		cantor(0, pow(3, N));

		// 출력
		for (int i = 0; i < pow(3, N); i++)
		{
			cout << v[i];
		}
		cout << "\n";

		// vector 초기화
		v.clear();
	}
	return 0;
}