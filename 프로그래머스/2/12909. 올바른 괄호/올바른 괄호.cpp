#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> ss;
    
    for(int i=0; i<s.size(); i++){
        if(!ss.empty() && ss.top() == '(' && s[i] == ')') ss.pop();
        else ss.push(s[i]);
    }
    return ss.empty();
}