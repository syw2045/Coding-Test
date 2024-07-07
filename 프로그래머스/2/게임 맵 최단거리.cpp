#include<vector>
#include<queue>

#define MAX 101

using namespace std;

bool isChecked[MAX][MAX] = {0,};
int dist[MAX][MAX] = {0,};

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

queue<pair<int, int>> q;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int N = maps.size(), M = maps[0].size();
    
    q.push(make_pair(0,0));
    isChecked[0][0] = true;
    dist[0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(isChecked[nx][ny] == true) continue;
            if(maps[nx][ny] == 0) continue;
            
            isChecked[nx][ny] = true;
            q.push(make_pair(nx, ny));
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    if(dist[N-1][M-1] == 0) answer = -1;
    else answer = dist[N-1][M-1];
    return answer;
}