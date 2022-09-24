#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
	int N = 0;
	cin >> N;

	int loop = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> loop;
		v.push_back(loop);
	}

	sort(v.rbegin(), v.rend());

	int weight = 0;
	for (int i = 0; i < N; i++)
	{
		weight = v[i] * (i + 1);
		v[i] = weight;
	}
	sort(v.rbegin(), v.rend());
	cout << v[0] << "\n";
	return 0;
}