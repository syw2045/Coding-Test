#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<string> v(N);
	vector<string> ans;

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	string name = "";
	for (int i = 0; i < M; i++)
	{
		cin >> name;
		if (binary_search(v.begin(), v.end(), name))
		{
			ans.push_back(name);
		}
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

	return 0;
}