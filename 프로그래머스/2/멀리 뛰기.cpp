#include <string>
#include <vector>

using namespace std;

int arr[2001] = {0,1,2,};

long long solution(int n) {
    long long answer = 0;
    
    for(int i=3; i<=n; i++)
    {
        arr[i] = (arr[i-1] + arr[i-2]) % 1234567;
    }
    answer = arr[n];
    return answer;
}