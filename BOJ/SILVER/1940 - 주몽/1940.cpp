#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
    int N, M;
    cin >> N;
    cin >> M;

    int value;
    for(int i = 0; i< N; i++)
    {   
        cin >> value;
        v.push_back(value);
    }

    sort(v.begin(), v.end());

    int start_idx = 0;
    int end_idx = N-1;
    int cnt = 0;

    while(start_idx < end_idx)
    {
        int sum = v[start_idx] + v[end_idx];
        
        if(sum > M)
        {
            end_idx--;
        }
        else if(sum < M)
        {
            start_idx++;
        }
        else
        {
            cnt++;
            end_idx--;
            start_idx++;
        }
    }

    cout << cnt << "\n";

    return 0;
}