#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, idx = 0;
    
    sort(people.begin(), people.end());
    
    while(people.size() > idx){
        if(people[idx] + people.back() <= limit) idx++;
        answer++;
        people.pop_back();
    }
    return answer;
}