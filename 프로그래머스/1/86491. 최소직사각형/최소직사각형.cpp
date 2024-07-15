#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
        
    int first = 0, second = 0;
    
    for(int i=0; i<sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]) swap(sizes[i][0], sizes[i][1]);
        
        if(sizes[i][0] > first) first = sizes[i][0];
        if(sizes[i][1] > second) second = sizes[i][1];
    }    
    answer = first * second;
    return answer;
}