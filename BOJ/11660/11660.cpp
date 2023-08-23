#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int map[1025][1025] = {};

    int value=0;
    // make the map
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
        {
            cin >> value;
            map[i][j] = value;
        }

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
        {
            map[i][j] += map[i-1][j] + map[i][j-1] - map[i-1][j-1];
        }


    int x1, y1, x2, y2 =0;

    for(int i=1; i<=M; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int answer = map[x2][y2] - map[x1-1][y2] - map[x2][y1-1] + map[x1-1][y1-1];
        cout << answer << "\n";
    }
    return 0;
}