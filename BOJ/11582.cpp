#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> v_sort;

void sorting(int start, int end)
{
	if (start == v.size()) return; // 만약 끝까지 다 sorting했을경우

	for (int i = start; i < end; i++)
	{
		v_sort.push_back(v[i]); // 정렬을 위한 벡터에 시작점 to 끝점 까지 값을 넣는다
	}
	sort(v_sort.begin(), v_sort.end()); // 오름차순 정렬

	for (int i = 0; i < end - start; i++) // 출력
	{
		cout << v_sort[i] << " ";
	}

	v_sort.clear(); // 정렬을 위한 벡터 초기화
	sorting(end , 2 * end - start); // 끝점을 시작점으로 해서 다시 sorting 함수에 넣는다
}


int main()
{

	int N = 0;
	cin >> N;

	// 값 입력
	int value = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	int k = 0;
	cin >> k;

	//시작점, 출발점 입력
	sorting(0, N/k);
	cout << "\n";

	return 0;
}