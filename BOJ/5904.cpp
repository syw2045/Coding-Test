#include <iostream>

using namespace std;

string Moo = "moo";

void Cal_MOO(int N, int cnt, int len)
{
	int new_len = len * 2 + (cnt + 3);
	if (N <= 3)
	{
		cout << Moo[N - 1] << "\n";
		exit(0);
	}
	if (N > new_len)
	{
		Cal_MOO(N, cnt + 1, new_len);
	}
	else
	{
		if (N > len && N <= len + cnt + 3) // second
		{
			if (N - len != 1) cout << "o\n";
			else cout << "m\n";
			exit(0);
		}
		else Cal_MOO(N - (len + cnt + 3), 1, 3);
	}
}

int main()
{
	int N = 0;
	cin >> N;

	Cal_MOO(N, 1, 3);

	return 0;
}