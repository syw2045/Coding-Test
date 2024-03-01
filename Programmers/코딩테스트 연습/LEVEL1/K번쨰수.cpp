#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        vector<int> v_sort = array;
        
        int idx_i = commands[i][0];
        int idx_j = commands[i][1];
        int idx_k = commands[i][2];
        
        //정렬
        sort(v_sort.begin() + idx_i - 1 , v_sort.begin() + idx_j);
        
        // 출력
        answer.push_back(v_sort[idx_k + idx_i - 2]);
        v_sort.clear();
    }
    return answer;
}