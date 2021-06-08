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
    for(int i = 0; i < 3; ++i)
        if(i != start) DP[0][i] = INF;

    switch(start){
        case 0:
            if(DP[N - 1][1] < DP[N - 1][2])
                DP[N - 2][1] = DP[N - 1][0] = DP[N - 1][2] = INF;
            else 
                DP[N - 2][2] = DP[N - 1][0] = DP[N - 1][1] =  INF;
            break;
        case 1:
            if(DP[N - 1][0] < DP[N - 1][2])
                DP[N - 2][0] =  DP[N - 1][1] = DP[N - 1][2] = INF;
            else 
                DP[N - 2][2] =  DP[N - 1][0] = DP[N - 1][1] = INF;
            break;
        case 2:
            if(DP[N - 1][0] < DP[N - 1][1])
                DP[N - 2][0] =  DP[N - 1][1] = DP[N - 1][2] = INF;
            else 
                DP[N - 2][1] =  DP[N - 1][0] = DP[N - 1][1] = INF;
            break;
    }
    for(int i = 1; i < N; ++i){
        DP[i][0] += std::min(DP[i - 1][1], DP[i - 1][2]);
        DP[i][1] += std::min(DP[i - 1][0], DP[i - 1][2]);
        DP[i][2] += std::min(DP[i - 1][1], DP[i - 1][0]);
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
