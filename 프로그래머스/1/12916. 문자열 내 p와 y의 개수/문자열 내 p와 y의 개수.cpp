#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;
    
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'P') cnt++;
        else if(s[i] == 'Y') cnt--;
    }
    
    return !cnt;
}