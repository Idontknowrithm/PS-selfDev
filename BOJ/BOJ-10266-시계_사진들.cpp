// 환형 문자열 다루는 문제

#include<iostream>
#include<algorithm>

const int MAX = 200005;
int N, clock1[MAX], clock2[MAX];
int prepro1[MAX], prepro2[MAX];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &clock1[i]);
    for(int i = 0; i < N; ++i)
        scanf("%d", clock2[i]);
    std::sort(clock1, clock1 + N);
    std::sort(clock2, clock2 + N);

    for(int i = 0; i < N; ++i){
        if(i == N - 1)
            prepro1[i] = clock1[0] + 360000 - clock1[i];
        else 
            prepro1[i] = clock1[i + 1] - clock1[i];
        
        if(i == N - 1)
            prepro2[i] = clock2[0] + 360000 - clock2[i];
        else 
            prepro2[i] = clock2[i + 1] - clock2[i];
    }
    
}
