// 한 줄로 된 간단한 정보 놓쳐서 어이없게 한 번 틀림


#include<iostream>

const int INF = 2147483647;
int T, N, M, W, s, e, t, space[505][505]; // start from 1

void floyd_warshall(){
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int u = 1; u <= N; ++u){
                if(space[i][k] == INF || space[k][u] == INF) continue;
                space[i][u] = (space[i][k] + space[k][u] < space[i][u]) ? space[i][k] + space[k][u] : space[i][u];
            }
        }
    }
}
void validation(){
    for(int i = 1; i <= N; ++i)
        if(space[i][i] < 0){
            printf("YES\n");
            return;
        }
    printf("NO\n");
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d %d %d", &N, &M, &W);
        for(int i = 1; i <= N; ++i)
        for(int u = 1; u <= N; ++u)
            space[i][u] = INF;
        for(int i = 1; i <= N; ++i)
            space[i][i] = 0;
        for(int i = 0; i < M; ++i){
            scanf("%d %d %d", &s, &e, &t);
            if(space[s][e] > t){
                space[s][e] = t;
                space[e][s] = t;
            }
        }
        for(int i = 0; i < W; ++i){
            scanf("%d %d %d", &s, &e, &t);
            space[s][e] = -t;
        }
        floyd_warshall();
        
        validation();   
    }

    return 0;
}
