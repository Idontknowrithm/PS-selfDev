#include<iostream>
#define INF 2147483647

int N, S, ans = INF, seq[100005], sum[100005];

int main() {
    int ptr1 = 0, ptr2 = 1;
    scanf("%d %d", &N, &S);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &seq[i]);
        sum[i] = seq[i] + sum[i - 1];
    }
        
    while(ptr2 != N + 1){
        if(sum[ptr2] - sum[ptr1] < S) ++ptr2;
        else{
            ans = (ans > ptr2 - ptr1) ? ptr2 - ptr1 : ans;
            ++ptr1;
        }
    }
    printf("%d", (sum[N] < S) ? 0 : ans);
    return 0;
}
