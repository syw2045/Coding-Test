#include <iostream>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	int cnt = 0;

	for (int i = 3; i <= 3000; i += 3)
	{
		for (int j = 3; j <= 3000; j += 3)
		{
			if (i + j >= N) break;
			if ((N - j - i) % 3 == 0) cnt++; // j와 i가 결정되면 k를 결정할수있다.
		}
	}
	cout << cnt << "\n";
	return 0;
}