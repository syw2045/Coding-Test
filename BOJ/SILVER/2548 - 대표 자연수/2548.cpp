#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int answer = 0;
	int minimum = 999999999;

	int N = 0;
	cin >> N;

	int value;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		v.push_back(value);
	}
	sort(v.begin(), v.end()); // 오름차순 정렬

	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		int result = 0;
		for (int j = 0; j < N; j++)
		{
			if (v[i] > v[j]) // 차를 구한다.
			{
				result += v[i] - v[j];
				cnt++; // 기준값보다 작다면 cnt + 1
			}
			else result += v[j] - v[i];
		}
		if (result < minimum)
		{
			minimum = result;
			answer = v[i];
		}
		if (cnt > N / 2) break; // cnt가 절반보다 많아 질 경우
	}
	cout << answer << "\n";
	return 0;
}