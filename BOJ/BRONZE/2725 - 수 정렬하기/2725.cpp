#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> V(N,0);

    for(int i=0; i<N; i++)
    {
        cin >> V[i];
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N -1 - i; j++)
        {
            if(V[j] > V[j+1])
            {
                int temp = V[j];
                V[j] = V[j+1];
                V[j+1] = temp;
            }
        }
    }

    for(int i=0; i<V.size(); i++)
    {
        cout << V[i] << "\n";
    }

    return 0;
}