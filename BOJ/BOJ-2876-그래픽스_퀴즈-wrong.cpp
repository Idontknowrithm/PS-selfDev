#include<iostream>

int N, max, maxi, target, table[100005][2], answer[5];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &table[i][0], &table[i][1]);
    }

    for(int i = 0; i < 5; ++i){
        answer[i] = 0;
        for(int u = 0; u < N; ++u){
            if(table[u][0] == i + 1 || table[u][1] == i + 1){
                ++target;
            }
            else{
                answer[i] = (target > answer[i]) ? target : answer[i];
                target = 0;
            }
        }
    }
    for(int i = 0; i < 5; ++i)
        if(max < answer[i]){
            max = answer[i];
            maxi = i + 1;
        }
    printf("%d %d", max, maxi);
    return 0;
}
