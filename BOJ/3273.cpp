#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int X = 0;
	cin >> X;

	int start = 0;
	int end = v.size() - 1;

	int cnt = 0;
	while (start < end)
	{
		int sum = v[start] + v[end];
		if (sum >= X)
		{
			if (sum == X) cnt++;
			end--;
		}
		else start++;
	}

	cout << cnt << "\n";
	return 0;
}