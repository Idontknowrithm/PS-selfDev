#include<iostream>

int N, K, DP[100001] = {0,};
std::pair<int, int> input[110];
int main () {
    int inp1, inp2;

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &inp1, &inp2);
        input[i] = {inp1, inp2};
    }
    for(int i = 0; i < K; ++i){
        for(int u = 0; u < N; ++u){
            if(i + input[u].first <= K)
                DP[i + input[u].first] = (DP[i + input[u].first] < DP[i] + input[u].second)\
                ? DP[i] + input[u].second : DP[i + input[u].first];
        }
    }

    printf("%d", DP[K]);

    return 0;
}
