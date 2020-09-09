#include<iostream>

int main() {
    int a, b, c, N, arr[305];  
    
    for(int i = 1; i < 305; ++i)
        arr[i] = 999999999;
    arr[0] = 0;
    scanf("%d %d %d %d", &a, &b, &c, &N);

    for(int i = 1; i <= N; ++i){
        int min = 999999999;
        if(i - a >= 0)
            min = (min > arr[i - a]) ? arr[i - a] : min;
        if(i - b >= 0)
            min = (min > arr[i - b]) ? arr[i - b] : min;
        if(i - c >= 0)
            min = (min > arr[i - c]) ? arr[i - c] : min;
        arr[i] = (min == 999999999) ? min : min + 1;
    }

    if(arr[N] != 999999999)
        printf("1");
    else 
        printf("0");
    return 0;
}
