#include<iostream>
#include<queue>
#define INF 2147483647

int N, M, jump[105], DP[105];
std::queue<int> que;

int main() {
    int ia, ib;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < 105; ++i){
        jump[i] = i;
        DP[i] = INF;
    }
    DP[1] = 0;
    for(int i = 0; i < N + M; ++i){
        scanf("%d %d", &ia, &ib);
        jump[ia] = ib;
    }
    que.push(1); 
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        if(tmp == 100) break;

        for(int i = 1; i <= 6; ++i){
            if(tmp + i <= 100 && DP[jump[tmp + i]] > DP[tmp] + 1){
                DP[jump[tmp + i]] = DP[tmp] + 1;
                que.push(jump[tmp + i]);
            }
        }
    }
    printf("%d", DP[100]);
    return 0;
}
