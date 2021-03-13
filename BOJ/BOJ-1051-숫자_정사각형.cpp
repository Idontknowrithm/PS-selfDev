#include<iostream>
#include<set>

int N, M, rectangle[55][55];

int main() {
    int N, M, ans = -1;
    char inp;
    scanf("%d %d\n", &N, &M);
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            scanf("%c", &inp);
            rectangle[i][u] = inp - '0';
        }
        getchar();
    }
    int minlen = (N < M) ? N : M;
    for(int i = 0; i < minlen; ++i){
        for(int u = 0; u < N - i; ++u){
            for(int k = 0; k < M - i; ++k){
                std::set<int> edge;
                edge.insert(rectangle[u][k]);
                edge.insert(rectangle[u + i][k]);
                edge.insert(rectangle[u][k + i]);
                edge.insert(rectangle[u + i][k + i]);
                if(edge.size() == 1) ans = (i + 1) * (i + 1);
            }
        }
    }
    printf("%d", ans);
    return 0;   
}
