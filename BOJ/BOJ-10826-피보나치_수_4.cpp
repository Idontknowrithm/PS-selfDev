#include<iostream>

char num[10005][5000];
int numLen[10005];

void plus(char* dest, char* src1, int src1len, char* src2, int src2len, int destIdx){
    // src1len < src2len
    int next = 0;
    for(int i = 0; i < src1len; ++i){
        int temp = next + (src1[i] - '0') + (src2[i] - '0');
        if(temp < 10){
            dest[i] = temp + '0';
            next = 0;   ++numLen[destIdx];
        }
        else{
            dest[i] = temp % 10 + '0';
            next = 1;   ++numLen[destIdx];
        }
    }
    for(int i = src1len; i < src2len; ++i){
        int temp = next + (src2[i] - '0');
        if(temp < 10){
            dest[i] = temp + '0';
            next = 0;   ++numLen[destIdx];
        }
        else{
            dest[i] = temp % 10 + '0';
            next = 1;   ++numLen[destIdx];
        }
    }
    if(next){
        dest[src2len] = '1';
        ++numLen[destIdx];
    }
}

int main() {
    int N;
    
    scanf("%d", &N);
    if(N == 0){
        printf("%d", 0);
        return 0;
    }
    if(N == 1){
        printf("%d", 1);
        return 0;
    }
    if(N == 2){
        printf("%d", 1);
        return 0;
    }
    if(N == 3){
        printf("%d", 2);
        return 0;
    }
    num[0][0] = '0'; num[1][0] = '1'; num[2][0] = '1';
    numLen[0] =      numLen[1] =      numLen[2] =  1 ;
    for(int i = 3; i <= N; ++i){
        if(numLen[i - 1] < numLen[i - 2])
            plus(num[i], num[i - 1], numLen[i - 1], num[i - 2], numLen[i - 2], i);
        else
            plus(num[i], num[i - 2], numLen[i - 2], num[i - 1], numLen[i - 1], i);
    }

    for(int i = numLen[N] - 1; i >= 0; --i)
        printf("%c", num[N][i]);
    
    return 0;
}
