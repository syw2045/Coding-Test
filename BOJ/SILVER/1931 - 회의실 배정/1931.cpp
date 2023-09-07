#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if(a.second == b.second)
		return a.first < b.first;
	else return a.second < b.second;
}

int main()
{
	int N = 0;
	cin >> N;

	int start = 0, end = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end(), compare);

	int answer = 1;
	int last = 0;
	for (int i = 0; i < N-1; i++)
	{
		if (v[i + 1].first >= v[last].second)
		{
			answer++;
			last = i+1;
		}
	}
	cout << answer << "\n";
	return 0;
}