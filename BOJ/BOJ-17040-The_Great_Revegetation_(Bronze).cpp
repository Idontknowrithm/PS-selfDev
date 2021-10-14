// 쉬운 알고리즘이라 추측되는데 데이터 제한이 작으면
// 다 해보는 쪽으로 방향을 잡아야 함

#include<iostream>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>

const int MAX = 105;
int N, M, possible[MAX][5];
std::vector<pp> cows;
std::vector<int> graph[MAX];

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
        if(a > b)
            cows.push_back({b, a});
        else
            cows.push_back({a, b});
    }
    std::sort(cows.begin(), cows.end());
    for(int i = 1; i <= N; ++i){
        for(int k = 1; k <= 4; ++k)
            if(!possible[i][k]){
                possible[i][k] = 1;
                for(int u = 0; u < graph[i].size(); ++u)
                    if(!possible[graph[i][u]][k])
                        possible[graph[i][u]][k] = -1;
                break;
            }
    }
    for(int i = 1; i <= N; ++i)
        for(int u = 1; u <= 4; ++u)
            if(possible[i][u] == 1){
                printf("%d", u);
                break;
            }
    
    return 0;
}
