#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v1;
vector<pair<int, int>> v2;

bool compare(pair<int, int> a, pair<int, int > b)
{
	if (a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

// 산술평균
void average()
{
	double sum = 0.0;
	int result = 0;

	for (int i = 0; i < v1.size(); i++)
	{
		sum += v1[i];
	}
	result = floor(sum / v1.size() + 0.5);
	if (result == -0) cout << 0 << "\n";
	else cout << result << "\n";
}

//중앙값
void middle()
{
	int result = v1[v1.size() / 2];
	cout << result << "\n";
}

//최빈값
void most()
{
	int cnt = 0;

	v2.push_back(make_pair(v1[0], 0));
	for (int i = 1; i < v1.size(); i++)
	{
		if (v1[i] == v1[i - 1]) cnt++;
		else cnt = 0;
		v2.push_back(make_pair(v1[i], cnt));
	}

	sort(v2.begin(), v2.end(), compare);

	if (v2[0].second > v2[1].second) cout << v2[0].first << endl;
	else cout << v2[1].first << endl;
}

// 범위
void range()
{
	int result = v1[v1.size() - 1] - v1[0];
	cout << result << endl;
}

// N이 1인경우
void one_input()
{
	for (int i = 0; i < 3; i++)
	{
		cout << v1[0] << "\n";
	}
	cout << 0 << "\n";
}

int main()
{
	int N = 0;
	int value = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		v1.push_back(value);
	}

	// N이 1인경우
	if (N == 1)
	{
		one_input();
		return 0;
	}
	sort(v1.begin(), v1.end());

	average(); //산술평균
	middle(); // 중앙값
	most(); // 최빈값
	range(); // 범위

	return 0;
}