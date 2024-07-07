#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int cnt = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = cnt; j < B.size(); j++)
        {
            cnt++;
            if (A[i] < B[j])
            {
                answer++;
                break;
            }
        }
    }
    return answer;
}