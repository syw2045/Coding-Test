#include <string>
#include <vector>
#include <iostream>
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
    
    //정렬
    sort(v.begin(), v.end());
    
    answer = to_string(v.front()) + " " + to_string(v.back());
    return answer;
}