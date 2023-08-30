#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> V(N);

    for(int i=0; i<N; i++)
    {
        cin >> V[i].first;
        V[i].second = i;
    }

    sort(V.begin(), V.end());

    int max = -999999;
    for(int i=0; i<N; i++)
    {
        if(max < V[i].second - i) max = V[i].second - i;
    }

    cout << max + 1 << "\n";

    return 0;
}