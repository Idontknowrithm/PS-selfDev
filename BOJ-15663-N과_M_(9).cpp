#include<iostream>
#include<algorithm>

bool same(int* a, int* b, int size){
    for(int i = 0; i < size; ++i)
        if(a[i] != b[i])
            return false;
    return true;
}

int main () {
    int N, M, permTable[8], trace[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d", &permTable[i]);
    std::sort(permTable, permTable + N);
    do{
        if(same(trace, permTable, M))
            continue;
        for(int i = 0; i < M; ++i){
            trace[i] = permTable[i];
            printf("%d ", permTable[i]);
        }
        puts("");
    }while(std::next_permutation(permTable, permTable + N));
    return 0;
}
