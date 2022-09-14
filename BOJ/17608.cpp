#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;

	int num = 0;
	cin >> num;

	int height = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> height;

		if (s.empty()) s.push(height);
		else
		{
			while (!s.empty() && s.top() <= height) // top이 입력수보다 작거나 같으면 다 pop 시키고 마지막에 push
			{
				s.pop();
			}
			s.push(height);
		}
	}
	cout << s.size() << "\n"; // 스택 사이즈 출력
	return 0;
}