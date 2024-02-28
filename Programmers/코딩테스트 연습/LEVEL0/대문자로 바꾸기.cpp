#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(int i; i < myString.length(); i++)
    {
        if('a' <= myString[i] && myString[i] <= 'z')
            answer += myString[i] - 32;
        else answer += myString[i];
    }
    return answer;
}