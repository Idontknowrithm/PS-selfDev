#include<iostream>

int N, table[1005];

int DP(){
    // 1: CY   2: SK;
    table[1] = 1;
    table[2] = 2;
    table[3] = 1;
    table[4] = 2;
    table[5] = 2;
    if(N <= 5) return table[N];
    for(int i = 6; i <= N; ++i){
        if(table[i - 1] == 1 ||
           table[i - 3] == 1 ||
           table[i - 4] == 1){
            table[i] = 2;
        }
        else{
            table[i] = 1;
        }
    }
    return table[N];
}

int main() {
    scanf("%d", &N);
    printf("%s", (DP() == 1) ? "CY" : "SK");
    return 0;
}
