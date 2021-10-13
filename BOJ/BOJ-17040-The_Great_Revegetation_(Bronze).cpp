#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define pp std::pair<int, int>

const int MAX = 105;
int N, M, pastures[MAX];
std::vector<pp> favors;


int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a < b)
            favors.push_back({a, b});
        else
            favors.push_back({b, a});
    }
    std::sort(favors.begin(), favors.end());
    for(int i = 0; i <= N; ++i)
        pastures[i] = 1;
    for(int u = 0; u < 150; ++u)
        for(int i = 0; i < favors.size(); ++i){
            if(favors[i].first < favors[i].second && 
            pastures[favors[i].second] == pastures[favors[i].first])
                pastures[favors[i].second] = pastures[favors[i].first] + 1;
        }
    for(int i = 1; i <= N; ++i)
        printf("%d", pastures[i]);
    return 0;
}
