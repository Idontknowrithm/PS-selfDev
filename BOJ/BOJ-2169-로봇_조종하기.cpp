// 갔던 길은 다시 갈 수 없는 DP 류의 문제는 DP 테이블을 설계할 때 현재 칸에
// 오기 전 칸의 정보를 구분할 수 있어야 함
// ex) 현재 칸에 오기 전에 윗 칸에 있었는지, 좌 칸에 있었는지에 대한 정보
// 왜냐하면 갔던 길을 다시 갈 수 없는 제한이 있는 경우 길이 꼬여서 최적 값이 
// 아닌 경우인데도 불구하고 cache 값이 갱신이 되어 if(ret == -1) return ret
// 부분에서 최적해가 아닌데도 통과되어 최적해를 내지 못하는 경우가 발생하기 때문

#include<iostream>
#include<algorithm>
#include<cstring>

const int y[3] = {0, 0, 1};
const int x[3] = {-1, 1, 0};
const int MAX = 1005, INF = 10000005;
int N, M, mars[MAX][MAX], cache[MAX][MAX][3], visited[MAX][MAX];

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < M;
}
int DP(int r, int c, int dir){
    if(r == N - 1 && c == M - 1){
        
        return mars[r][c];
    } 
    int &ret = cache[r][c][dir];
    if(ret != -1) return ret;
    

    ret = -INF;
    for(int i = 0; i < 3; ++i){
        int R = r + y[i], C = c + x[i];
        if(possible(R, C) && !visited[R][C]){
            visited[R][C] = 1;
            ret = std::max(ret, DP(R, C, i));
            visited[R][C] = 0;
        }
    }
    ret += mars[r][c];
    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        scanf("%d", &mars[i][u]);
    
    memset(cache, -1, sizeof(cache));
    visited[0][0] = 1;
    printf("%d", DP(0, 0, 0));
    
    return 0;
}
