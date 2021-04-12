#include<iostream>
#include<algorithm>

int N, A, B, C, ans, cal[105];

int main() {
    scanf("%d\n%d %d\n%d", &N, &A, &B, &C);
    for(int i = 0; i < N; ++i)
        scanf("%d", &cal[i]);
    std::sort(cal, cal + N);

    ans = C / A;
    for(int i = N - 1; i >= 0; --i){
        C += cal[i];
        A += B;
        ans = (ans < C / A) ? C / A : ans;
    }
    printf("%d", ans);
    return 0;
}
