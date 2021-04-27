#include<iostream>
#include<algorithm>

int N, kids[205], cache[205];

int LIS(int start){
    if(start == N - 1) return 1;

    int &ret = cache[start + 1];
    if(ret) return ret;

    ret = 1;
    for(int i = start + 1; i < N; ++i){
        if(kids[start] < kids[i])
            ret = std::max(ret, LIS(i) + 1);
        else if(i == -1)
            ret = std::max(ret, LIS(i));
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &kids[i]);
    
    printf("%d", N - LIS(-1) + 1);
    return 0;
}
