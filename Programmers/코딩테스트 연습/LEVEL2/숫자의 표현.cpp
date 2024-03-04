#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    int sum[10001] = {0,};
    int arr[10001] = {0,};
    
    int start=0, end=1;
    
    for(int i=1; i<=n; i++){
        arr[i] = i;
        sum[i] = sum[i-1] + arr[i];
    }
    
    while(start!=n && end!=n){
        if(sum[end] - sum[start] > n){
            start++;
        }
        else if(sum[end] - sum[start] < n){
            end++;
        }
        else{
            answer++;
            start++;
        }
    }
    
    return answer;
}