#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;
    vector<int> v;
    
    for(int i=0; i<absolutes.size(); i++){
        if(signs[i]) v.push_back(absolutes[i]);
        else v.push_back(absolutes[i] * -1);
    }
    
    answer = accumulate(v.begin(), v.end(), 0);
    return answer;
}