#include<iostream>

int N, M, K, ans, lamp[55][55];
std::string input;

bool row_equal(int arow, int brow){
    for(int i = 0; i < M; ++i)
        if(lamp[arow][i] != lamp[brow][i]) return false;
    return true;
}
bool possible(int row){
    int tmp = 0;
    for(int i = 0; i < M; ++i)
        tmp += (lamp[row][i] == 0) ? 1 : 0;
    
    return (tmp <= K && !((tmp + K) & 1));
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;
    for(int i = 0; i < N; ++i){
        std::cin >> input;
        for(int u = 0; u < M; ++u)
            lamp[i][u] = input[u] - '0';
    }
    std::cin >> K;

    for(int i = 0; i < N; ++i){
        if(!possible(i)) continue;

        int tmp = 1;
        for(int u = i + 1; u < N; ++u){
            tmp += (row_equal(i, u)) ? 1 : 0;
        }
        ans = (tmp > ans) ? tmp : ans;
    }
    printf("%d\n", ans);
    return 0;
}
