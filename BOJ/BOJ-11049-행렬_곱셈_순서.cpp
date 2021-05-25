// 선형적인 문제풀이에서 순서대로만 관찰하는 문제 발생
// 1, 2, 3, 4가 있으면 1 하고 2 하고 3 하고 4 이렇게만 관찰함
// --> 1, 3, 2, 4로 탐색해야 풀릴 수도 

// #include<iostream>
// #include<algorithm>
// #define pp std::pair<int, int>

// int N, cache[505][505];
// pp matrix[505];

// int main() {
//     int ia, ib;
//     scanf("%d", &N);
//     for(int i = 0; i < N; ++i){
//         scanf("%d %d", &ia, &ib);
//         matrix[i] = {ia, ib};
//     }
//     for(int i = 0; i < N - 1; ++i){
//         cache[i][i + 1] = matrix[i].first * matrix[i].second * matrix[i + 1].second;
//     }
//     for(int i = 2; i < N; ++i){
//         for(int u = 0; u < N - i; ++u){
//             cache[u][u + i] = std::min(cache[u][u + i - 1] + 
//                 matrix[u].first * matrix[u + i].first * matrix[u + i].second,
//                 cache[u + 1][u + i] +
//                 matrix[u].first * matrix[u].second * matrix[u + i].second);
//         }
//     }
//     printf("%d", cache[0][N - 1]);
//     return 0;
// }

#include<iostream>
#include<algorithm>
#include<cstring>
#define pp std::pair<int, int>

const int INF = 2147483647;
int N, cache[505][505];
pp matrix[505];

int DP(int left, int right){
    if(left == right)
        return 0;
    if(right - left == 1)
        return matrix[left].first * matrix[left].second * matrix[right].second;

    int &ret = cache[left][right];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = left; i < right; ++i){
        ret = std::min(ret, DP(left, i) + DP(i + 1, right) + 
                       matrix[left].first * matrix[i].second * matrix[right].second);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int ia, ib;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &ia, &ib);
        matrix[i] = {ia, ib};
    }
    printf("%d", DP(0, N - 1));
}
