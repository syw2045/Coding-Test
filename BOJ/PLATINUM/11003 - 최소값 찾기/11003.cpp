#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> Node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    deque<Node> D;

    for(int i=0; i<N; i++)
    {
        int check;
        cin >> check;

        //deque에 값이 있고, 입력되는 값이 더 작으면
        while(D.size() && D.back().first > check)
        {
            D.pop_back(); // pop하고 최소값 후보로 등록
        }
        D.push_back(Node(check, i)); // deque에 저장

        // second에 저장된 값 : index
        if(D.front().second <= i - L) //윈도우를 벗어남
        {
            D.pop_front(); // 이미 비교한 최소값 pop
        }

        cout << D.front().first << ' '; // deque에서 최소값 출력
    }

    return 0;
}