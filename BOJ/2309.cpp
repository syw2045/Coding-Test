#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;

	int value = 0;
	int total_height = 0;
	int fake = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> value;
		v.push_back(value);
		total_height += value; // 9 난쟁이들의 키 합
	}

	sort(v.begin(), v.end()); // 오름차순 정렬
	fake = total_height - 100; // 거짓말 치는 두 난쟁이 키의 합

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (v[i] + v[j] == fake) // i 와 j 가 거짓말 난쟁이
			{
				v[i] = v[j] = -1;
				for (int k = 0; k < 9; k++) // 거짓말 난쟁이를 제외한 나머지 오름차순 출력
				{
					if (v[k] == -1) continue;
					cout << v[k] << "\n";
				}
				return 0;
			}
		}
	}
}