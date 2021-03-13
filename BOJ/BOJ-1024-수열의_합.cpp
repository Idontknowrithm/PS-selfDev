#include<iostream>

int N, L, real_len, mid, seq[105];

int main() {
    scanf("%d %d", &N, &L);
    real_len = L;
    while(1){
        if((real_len & 1) && N % real_len == 0) break;
        if(!(real_len & 1) && N % real_len == real_len / 2) break;
        if(real_len == 101) break;
        ++real_len;
    }
    if(real_len == 101){
        printf("-1");
    }
    else if((real_len & 1) && (N / real_len) - real_len / 2 >= 0){
        for(int i = 0; i < real_len; ++i)
            printf("%d ", (N / real_len) - real_len / 2 + i);
    }
    else if(!(real_len & 1) && (N / real_len) - real_len / 2 + 1 >= 0){
        for(int i = 0; i < real_len; ++i)
            printf("%d ", (N / real_len) - real_len / 2 + i + 1);
    }
    else{
        printf("-1");
    }
    return 0;
}
