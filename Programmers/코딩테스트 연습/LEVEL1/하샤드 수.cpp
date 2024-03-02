#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int init_x = x;
    int sum=0;
    
    while(x>0){
        sum += x % 10;
        x = x / 10;
    }
    if(init_x % sum == 0) answer = true;
    else answer = false;
    
    return answer;
}