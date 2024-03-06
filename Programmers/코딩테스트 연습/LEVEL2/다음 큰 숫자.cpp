#include <string>
#include <vector>

using namespace std;

int to_binary(int n){
    int cnt=0;
    while(n>0){
        if(n%2==1) cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int num_one = to_binary(n);
    n++;
    while(num_one != to_binary(n)){
        n++;
    }
    answer = n;
    return answer;
}