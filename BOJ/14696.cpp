#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v_a, v_b;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	int round = 0;
	cin >> round; // 라운드 수

	int A = 0;
	int B = 0;
	int value;
	for (int i = 0; i < round; i++)
	{
		cin >> A;
		for (int j = 0; j < A; j++)
		{
			cin >> value;
			v_a.push_back(value); // A의 모양 저장
		}

		cin >> B;
		for (int k = 0; k < B; k++)
		{
			cin >> value;
			v_b.push_back(value); // B의 모양 저장
		}
		sort(v_a.begin(), v_a.end(), compare); // 내림차순으로 정렬
		sort(v_b.begin(), v_b.end(), compare);

		int small = min(v_a.size(), v_b.size()); // A와 B의 모양의 개수가 작은 것
		for (int s = 0; s < small; s++)
		{
			if (v_a[s] > v_b[s]) // A가 큰 경우
			{
				cout << "A\n";
				break;
			}
			else if (v_a[s] < v_b[s]) // B가 큰 경우
			{
				cout << "B\n";
				break;
			}
			else if (s == small - 1) // 끝까지 비교를 못했을때
			{
				if (v_a.size() > v_b.size()) cout << "A\n"; // A의 모양이 더 많음
				else if (v_a.size() < v_b.size()) cout << "B\n"; // B의 모양이 더 많음
				else cout << "D\n"; // 다 똑같음
			}
		}
		v_a.clear(); // 벡터 초기화
		v_b.clear();
	}

	return 0;
}