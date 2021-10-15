#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

const int MAX = 105;
int N, ans;
std::vector<int> graph[MAX];

int BFS(int start, int end){
    bool reached[MAX] = {false,};
    std::queue<int> que;
    que.push(start);
    reached[start] = true;
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        for(int i = 0; i < graph[tmp].size(); ++i){
            int next = graph[tmp][i];
            if(!reached[next]){
                reached[next] = true;
                que.push(next);
            }
        }
    }
    return reached[end];
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }
    for(int i = 1; i <= N; ++i){
        int can_reach = 0;
        for(int u = 1; u <= N; ++u)
            can_reach += BFS(u, i);
        if(can_reach == N){
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
