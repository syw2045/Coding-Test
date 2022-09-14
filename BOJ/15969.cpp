#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;

	int num = 0;
	cin >> num;

	int value = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> value;
		v.push_back(value);
	}
	sort(v.begin(), v.end());

	int result = v[v.size() - 1] - v[0];
	cout << result << "\n";
	return 0;
}