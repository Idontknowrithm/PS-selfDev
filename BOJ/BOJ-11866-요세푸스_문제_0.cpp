#include<iostream>
#include<vector>

int main () {
    int N, K, index = -1;
    std::vector<int> josephus;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i)
        josephus.push_back(i + 1);
    printf("<");
    index += K--;
    printf("%d", josephus[index]);
    josephus.erase(josephus.begin() + index);
    for(int i = 0; i < N - 1; ++i){
        index += (index + K >= josephus.size()) ? (index + K) % josephus.size() - index : K;
        printf(", %d", josephus[index]);
        if(!josephus.empty())
            josephus.erase(josephus.begin() + index);
    }
    printf(">");
    return 0;
}
