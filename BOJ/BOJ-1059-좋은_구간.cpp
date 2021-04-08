#include<iostream>
#include<algorithm>

int where, L, N, S[55];

int main(){
    scanf("%d", &L);
    for(int i = 0; i < L; ++i)
        scanf("%d", &S[i]);
    scanf("%d", &N);
    std::sort(S, S + L);
    for(int i = 0; i < L; ++i){
        if(N < S[i]){
            where = i - 1;
            break;
        }
        else if(N == S[i]){
            where = -999;
            break;
        }
        else if(i == L - 1 && N > S[i]){
            where = i;
        }
    }
    if(where == -999){
        printf("0");
    }
    else if(where == -1){
        printf("%d", N * (S[0] - N) - 1);
    }
    else if(where == L - 1){
        printf("%d", (N - S[L - 1]) * (1000 - N) - 1);
    }
    else{
        printf("%d", (N - S[where]) * (S[where + 1] - N) - 1);
    }
    return 0;
}
