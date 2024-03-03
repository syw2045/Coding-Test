#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    
    for(int i =0; i<s.length(); i++){
        if(s[i] == ' '){
            temp[0] = toupper(temp[0]);
            answer += temp + " ";
            temp.clear();
            continue;
        }
        temp += tolower(s[i]);
    }
    temp[0] = toupper(temp[0]);
    answer += temp;    
    return answer;
}