#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    long long answer;

    cin >> a >> b;

    if(a > b) answer = a - b;
    else answer = b - a;

    cout << answer;

    return 0;
}