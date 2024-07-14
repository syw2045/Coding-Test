#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<pair<int, int>> v;
    
    for(int i=0; i<arr.size(); i++) v.push_back(make_pair(arr[i], i));
    
    sort(v.begin(), v.end());
    
    arr.erase(arr.begin() + v[0].second);
    
    for(auto i : arr) answer.push_back(i);
    
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}