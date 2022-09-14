#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	vector<int> v;

	int N = 0;
	int K = 0;

	cin >> N >> K;

	int value = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		v.push_back(value);
	}
	sort(v.begin(), v.end(), compare); // 내림 차순 정렬

	//빼지는 점수
	int minus = 0;
	for (int i = 0; i < K; i++)
	{
		minus += i;
	}

    //선택하는 전체 점수
	int total = 0;
	for (int i = 0; i < K; i++)
	{
		total += v[i];
	}

	int result = total - minus;

	cout << result << "\n";

	return 0;
}