#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

int result[MAX][MAX];
bool visited[MAX];
int N=0, M=0, V=0;

void dfs(int start){
    visited[start] = true;
    cout << start << " ";

    for(auto i=1; i<=N; i++)
        if(visited[i] == false && result[start][i] == 1) dfs(i);
}

void bfs(int start){
    queue<int> q;

    q.push(start);
    visited[start] = true;
    cout << start << " ";

    while(!q.empty()){
        start = q.front();
        q.pop();

        for(int i=1; i<=N; i++){
            if(result[start][i] == 1 && visited[i] == false){
                q.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }
}

void RESET(){
    cout << "\n";
    for(int i=0; i<MAX; i++){
        visited[i] = false;
    }
}

int main(){
    int x=0, y=0;
    cin >> N >> M >> V;

    for(auto i=0; i<M; i++){
        cin >> x >> y;
        result[x][y] = result[y][x] = 1;
    }

    dfs(V);
    RESET();
    bfs(V);
    return 0;
}