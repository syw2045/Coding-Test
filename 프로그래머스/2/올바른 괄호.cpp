#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s){
    stack<char> ss;

    bool answer = true;
    for(int i =0; i< s.size(); i++)
    {   
        if(!ss.empty() && ss.top() == '(' && s[i] == ')') ss.pop();
        else ss.push(s[i]);
    }
    if(!ss.empty()) answer = false;

    return answer;
}