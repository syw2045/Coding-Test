#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> V;
    V.push_back(A);
    V.push_back(B);
    V.push_back(C);

    sort(V.begin(), V.end());

    cout << V[0] << " " << V[1] << " " << V[2] << "\n";

    return 0;
}