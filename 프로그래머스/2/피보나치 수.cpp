#include <string>
#include <vector>

using namespace std;

long long sum[100001] = {0,1,};

int solution(int n) {
    int answer = 0;
    
    for(int i=2; i<=n; i++){
        sum[i] = sum[i-1] + sum[i-2];
        if(sum[i] > 1234567) sum[i] %= 1234567;
    }
    
    answer = sum[n];
    return answer;
}

