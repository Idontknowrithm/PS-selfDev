// 시작 색을 결정하기만 하면 되는데 시작 색에 따라 끝 색을 결정해버림
// -> 시작 색이 R일 때 끝 색의 G, B 중 더 작은 값을 고정하고 DP함
// 과도한 제한인 지 확인해보고 제한 조건 걸기

#include<iostream>
#include<algorithm>
#define FRT first_RGB_tracker
#define SFS start_fixed_solution

const int INF = 1000005;
int N, ans = INF, RGB[1005][3];

int SFS(int start){
    int DP[1005][3];
    for(int i = 0; i < N; ++i){
        DP[i][0] = RGB[i][0];
        DP[i][1] = RGB[i][1];
        DP[i][2] = RGB[i][2];
    }
    for(int i = 0; i < 3; ++i){
        if(i != start) DP[0][i] = INF;
        if(i == start) DP[N - 1][i] = INF;
    }
    for(int i = 1; i < N; ++i){
        DP[i][0] += std::min(DP[i - 1][1], DP[i - 1][2]);
        DP[i][1] += std::min(DP[i - 1][0], DP[i - 1][2]);
        DP[i][2] += std::min(DP[i - 1][0], DP[i - 1][1]);
    }
    return std::min(std::min(DP[N - 1][0], DP[N - 1][1]), DP[N - 1][2]);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
    
    printf("%d", std::min(SFS(0), std::min(SFS(1), SFS(2))));
    return 0;
}
