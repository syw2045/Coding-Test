#include <string>
#include <vector>

#define MAX 201

using namespace std;

bool isvisited[MAX];

void DFS(int start, int n, vector<vector<int>> computers){
    isvisited[start] = true;
    
    for(int i=0; i<n; i++){
        if(!isvisited[i] && computers[start][i] == 1) DFS(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        if(!isvisited[i]){
            DFS(i, n, computers);
            answer++;
        }
    }
    return answer;
}

