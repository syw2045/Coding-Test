#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int S[100001] {};
    
    // 전체 합 구하기
    for(int i {1}; i<=N; i++)
    {
        int temp;
        cin >> temp;
        S[i] = S[i-1] + temp;
    }

    // 구간 합 구하기
    for(int i {0}; i<M; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << S[end] - S[start-1] << "\n";
    }
    return 0;
}