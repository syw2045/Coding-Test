#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int value;
    int cnt = 1;

    stack<int> S;
    queue<char> Q;

    for(int i=0; i<N; i++)
    {
        cin >> value;
        while(true)
        {
            if(S.empty() || value != S.top())
            {
                S.push(cnt);
                Q.push('+');
                cnt++;
            }
            else
            {
                S.pop();
                Q.push('-');
                break;
            }

            if(S.top() > N)
            {
                cout << "NO\n";
                return 0;
            }
        }
    }

    while(!Q.empty())
    {
        cout << Q.front() << "\n";
        Q.pop();
    }

    return 0;
}