#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int, int>> v;
vector<int> compare_v;

int result;

bool compare(pair<int, int >a, pair<int, int> b)
{
	return a.second < b.second;
}

int shortpath()
{
	sort(compare_v.begin(), compare_v.end());
	for (int i = 1; i < compare_v.size()-1; i++) 
	{
		int before = compare_v[i] - compare_v[i - 1];
		int after = compare_v[i + 1] - compare_v[i];

		if (before < after) result += before;
		else result += after;
	}
	result += compare_v[1] - compare_v[0]; 
	result += compare_v[compare_v.size() - 1] - compare_v[compare_v.size() - 2]; // 맨 뒤

	return result;
}

int main()
{
	int num = 0;
	cin >> num;

	int value, type = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> value >> type;
		v.push_back(make_pair(value, type));
	}

	sort(v.begin(), v.end(), compare);


	int type_start = v[0].second;
	for (int i = 0; i < num; i++)
	{
		if (type_start == v[i].second) compare_v.push_back(v[i].first); // 색깔이 같으면 백터에 넣는다.
		else
		{
			shortpath();
			compare_v.clear(); 
			type_start = v[i].second;
			compare_v.push_back(v[i].first);
		}
	}
	shortpath();
	cout << result << "\n";

	return 0;
}