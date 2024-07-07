#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int cnt=0;
    for(int i=0; i<s.size(); i++, cnt++)
    {
        if(s[i] == ' ') // 공백이면
        {
            cnt = 1;
            answer += s[i];
        }
        else
        {
            if(cnt % 2 == 0) answer += toupper(s[i]); // 짝수번째 -> 대문자
            else answer += tolower(s[i]); // 홀수번째 -> 소문자
        }
        
    }
    return answer;
}