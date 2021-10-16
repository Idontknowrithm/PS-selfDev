#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

int N, ans = 1000000, score[25][25], comb[25];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &score[i][u]);
    for(int i = 0; i < N / 2; ++i)
        comb[i] = 1;
    
    do{
        std::vector<int> a, b;
        int asum = 0, bsum = 0;
        for(int i = 0; i < N; ++i)
            if(comb[i])
                a.push_back(i);
            else 
                b.push_back(i);
        for(int i = 0; i < N / 2 - 1; ++i)
        for(int u = i + 1; u < N / 2; ++u){
            asum += score[a[i]][a[u]] + score[a[u]][a[i]];
            bsum += score[b[i]][b[u]] + score[b[u]][b[i]];
        }
        ans = std::min(ans, std::abs(asum - bsum));
    }while(std::prev_permutation(comb, comb + N));
    
    printf("%d", ans);
    return 0;
}
