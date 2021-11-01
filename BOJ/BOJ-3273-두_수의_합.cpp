#include<iostream>
#include<algorithm>

int N, X, seq[100005];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &seq[i]);
    scanf("%d", &X);

    std::sort(seq, seq + N);
    int start = 0, end = N - 1, ans = 0;
    while(start < end){
        if(seq[start] + seq[end] == X){
            ++start; --end; ++ans;
        }
        else if(seq[start] + seq[end] < X)
            ++start;
        else 
            --end;
    }
    printf("%d", ans);
    return 0;
}
