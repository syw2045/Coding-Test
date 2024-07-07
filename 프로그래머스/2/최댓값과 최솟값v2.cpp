#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> v;
    string temp = "";

    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            v.push_back(stoi(temp));
            temp.clear();
            continue;
        }
        temp += s[i];
    }
    v.push_back(stoi(temp));
    
    auto min = *min_element(v.begin(), v.end());
    auto max = *max_element(v.begin(), v.end());
    
    answer = to_string(min) + " " + to_string(max);
    return answer;
}