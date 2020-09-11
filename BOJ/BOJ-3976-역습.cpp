#include<iostream>

int p1[100005], p2[100005], d1[100005], d2[100005];
int ans1[100005], ans2[100005];

int main() {
    int T;
    for(scanf("%d", &T); T > 0; --T){
        int N, s1, s2;
        scanf("%d %d %d %d %d", &N, &ans1[0], &ans2[0], &s1, &s2);
        for(int i = 1; i < 100005; ++i)
            ans1[i] = ans2[i] = 2100000000;
        for(int i = 0; i < N - 1; ++i)
            scanf("%d", &p1[i]);
        for(int i = 0; i < N - 1; ++i)
            scanf("%d", &d1[i]);
        for(int i = 0; i < N - 1; ++i)
            scanf("%d", &p2[i]);
        for(int i = 0; i < N - 1; ++i)
            scanf("%d", &d2[i]);
        for(int i = 1; i < N; ++i){
            ans1[i] = (ans1[i - 1] + d1[i - 1] < ans2[i - 1] + p2[i - 1]) ? ans1[i - 1] + d1[i - 1] : ans2[i - 1] + p2[i - 1];
            ans2[i] = (ans2[i - 1] + d2[i - 1] < ans1[i - 1] + p1[i - 1]) ? ans2[i - 1] + d2[i - 1] : ans1[i - 1] + p1[i - 1];
        }
        printf("%d\n", (ans1[N - 1] + s1 < ans2[N - 1] + s2) ? ans1[N - 1] + s1 : ans2[N - 1] + s2);
    }
    return 0;
}
