#include<iostream>

int N;

bool prime(int num){
    for(int i = 2; i * i <= num; ++i){
        if(num % i == 0)
            return false;
    }
    return true;
}

void calc(int target, int len){
    if(prime(target)){
        if(len == N){
            printf("%d\n", target);
            return;
        }
        for(int i = 1; i <= 9; ++i)
            calc(target * 10 + i, len + 1);
    }
}

int main() {
    scanf("%d", &N);
    
    calc(2, 1);
    calc(3, 1);
    calc(5, 1);
    calc(7, 1);

    return 0;
}
