#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

int T, N, M, A[1005], B[1005];
ll ans;
std::vector<int> Aseq, Bseq;

int main() {
    int input, Aptr, Bptr;
    scanf("%d", &T);
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &input);
        A[i] = A[i - 1] + input;
    }
    for(int i = 1; i <= N; ++i)
    for(int u = i; u <= N; ++u)
        Aseq.push_back(A[u] - A[u - i]);
    scanf("%d", &M);
    for(int i = 1; i <= M; ++i){
        scanf("%d", &input);
        B[i] = B[i - 1] + input;
    }
    for(int i = 1; i <= M; ++i)
    for(int u = i; u <= M; ++u)
        Bseq.push_back(B[u] - B[u - i]);
    
    std::sort(Aseq.begin(), Aseq.end());
    std::sort(Bseq.begin(), Bseq.end());
    
    Aptr = 0;
    Bptr = Bseq.size() - 1;

    while(Aptr < Aseq.size() && Bptr >= 0){
        if(Aseq[Aptr] + Bseq[Bptr] == T){
            ll Atmp = 1, Btmp = 1;
            while(Aptr < Aseq.size() - 1 && Aseq[Aptr] == Aseq[Aptr + 1]){
                ++Atmp;
                ++Aptr;
            }
            ++Aptr;
            while(Bptr > 0 && Bseq[Bptr] == Bseq[Bptr - 1]){
                ++Btmp;
                --Bptr;
            }
            --Bptr;
            ans += Atmp * Btmp;
        }
        else if(Aseq[Aptr] + Bseq[Bptr] > T)
            --Bptr;
        else 
            ++Aptr;
    }
    printf("%lld", ans);
    return 0;
}
