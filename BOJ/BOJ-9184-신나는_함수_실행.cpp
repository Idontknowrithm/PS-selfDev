#include<iostream>
#include<cstring>

int a, b, c, cache[105][105][105];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) 
        return 1;

    int &ret = cache[a + 50][b + 50][c + 50];
    if(ret != -1) return ret;

    if(a > 20 || b > 20 || c > 20)
        ret = w(20, 20, 20);
    else if(a < b && b < c)
        ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else 
        ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return ret;
}

int main(){
    memset(cache, -1, sizeof(cache));
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1)
            return 0;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));        
    }
    return 0;
}
