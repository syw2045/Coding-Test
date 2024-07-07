#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> t_arr(10000001);

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for(auto i:tangerine){
        t_arr[i]++;
    }
    
    sort(t_arr.rbegin(), t_arr.rend());
    
    for(int i=0; i<t_arr.size(); i++){
        if(t_arr[i] < k){
            k -= t_arr[i];
            answer++;
        }
        else{
            answer++;
            break;
        }
    }
    return answer;
}