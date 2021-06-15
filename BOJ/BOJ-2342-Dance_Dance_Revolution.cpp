// DP는 캐시 테이블, 점화식 두 개가 전부
// 캐시 테이블이 3차원, 4차원일 수도 있으니 굳이 1차원, 2차원으로 
// 줄이기가 힘들다면 3, 4차원도 생각을 해볼 수 있도록 

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

const int INF = 400005;
int N, cache[5][5][100005];
std::vector<int> input;

int interpreter(int cur, int next){
    if(!cur)                      return 2;
    else if(cur == next)          return 1;
    else if(abs(cur - next) == 2) return 4;
    else                          return 3;
}
int DP(int l, int r, int cur){
    if(cur == N) return 0;

    int &ret = cache[l][r][cur];
    if(ret) return ret;

    ret = INF;

    ret = std::min(ret, DP(input[cur], r, cur + 1) + interpreter(l, input[cur]));
    ret = std::min(ret, DP(l, input[cur], cur + 1) + interpreter(r, input[cur]));

    return ret;
}

int main() {
    int tmp = -1;
    scanf("%d", &tmp);
    while(tmp){
        input.push_back(tmp);
        scanf("%d", &tmp);
    }
    N = input.size();
    printf("%d", DP(0, 0, 0));
    return 0;
}
