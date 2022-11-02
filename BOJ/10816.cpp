#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	vector<int> v1(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v1[i];
	}

	int M = 0;
	cin >> M;
	vector<int> v2(M);
	for (int i = 0; i < M; i++)
	{
		cin >> v2[i];
	}

	sort(v1.begin(), v1.end());
	
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		ans = upper_bound(v1.begin(), v1.end(), v2[i]) - lower_bound(v1.begin(), v1.end(), v2[i]);
		cout << ans << " ";
	}
	return 0;
}