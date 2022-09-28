#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<ll> Oil;
vector<ll> Dist;

int main()
{
	int N = 0;
	cin >> N;

	ll value = 0;
	for (ll i = 0; i < N-1; i++)
	{
		cin >> value;
		Dist.push_back(value);
	}
	Dist.push_back(0);

	for (ll i = 0; i < N; i++)
	{
		cin >> value;
		Oil.push_back(value);
	}

	ll min_oil = Oil[0];
	ll answer = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (min_oil > Oil[i])
		{
			min_oil = Oil[i];
		}
		answer += Dist[i] * min_oil;
	}
	
	cout << answer << "\n";
	return 0;
}