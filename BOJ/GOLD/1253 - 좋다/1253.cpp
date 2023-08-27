#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    int N;
    cin >> N;

    vector<long> V(N,0);

    for(int i=0; i<N; i++)
    {
        cin >> V[i];
    }

    sort(V.begin(), V.end());

    int M = 0;
    int answer = 0;
    while(M < N)
    {
        int start_idx = 0;
        int end_idx = N-1;
        while(start_idx < end_idx)
        {
            if(V[start_idx] + V[end_idx] == V[M])
            {
                if(start_idx != M && end_idx != M)
                {
                    answer++;
                    break;
                }
                if(start_idx == M) start_idx++;
                if(end_idx == M) end_idx--;
            }
            else if(V[start_idx] + V[end_idx] > V[M])
            {
                end_idx--;
            }
            else start_idx++;
        }
        M++;
    }

    cout << answer << "\n";
    return 0;
}