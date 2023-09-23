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

	int start = 0, end = v.size() - 1;
	int min = 2000000000;
	vector<int> result(2);

	while (start < end)
	{
		if (abs(v[start] + v[end]) < min)
		{
			min = abs(v[start] + v[end]);
			result[0] = v[start];
			result[1] = v[end];

			if (v[start] + v[end] == 0) break;
		}
		
		if (v[start] + v[end] < 0) start++;
		else if (v[start] + v[end] > 0) end--;
	}
	
	cout << result[0] << " " << result[1] << "\n";
	return 0;
}