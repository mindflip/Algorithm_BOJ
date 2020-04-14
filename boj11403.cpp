#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int N, M;
bool visited[101];
vector<int> graph[101];
int result[101][101];

void bfs(int start){
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int front = q.front();
        q.pop();

        
        for(int i = 0; i < graph[front].size(); i++){
            int next = graph[front][i];
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> M;
            if (M == 1) {
                graph[i].push_back(j);
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        memset(visited, 0, sizeof(visited));
        bfs(i);
        for(int j = 0; j < N; j++){
            if(visited[j]){
                result[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << result[i][j] << " ";
            if(j == N - 1)
                cout << endl;
        }
    }
}
