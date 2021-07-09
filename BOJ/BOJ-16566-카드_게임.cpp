#include<iostream>
#include<algorithm>
#include<vector>

int N, M, K, submitted[4000005];
std::vector<int> card;

int main() {
    int input;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; ++i){
        scanf("%d", &input);
        card.push_back(input);
    }
    std::sort(card.begin(), card.end());
    for(int i = 0; i < K; ++i){
        scanf("%d", &input);
        int idx = std::upper_bound(card.begin(), card.end(), input) - card.begin();
        while(submitted[idx]) ++idx;
        printf("%d\n", card[idx]);
        ++submitted[idx];
    }
    return 0;
}
