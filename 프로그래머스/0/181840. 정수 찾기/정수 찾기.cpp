#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = 0;
    
    sort(num_list.begin(), num_list.end());
    
    for(int i=0; i<num_list.size(); i++){
        if(num_list[i] == n) answer = 1;
    }
    
    return answer;
}