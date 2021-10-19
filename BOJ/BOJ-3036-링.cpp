#include<iostream>

int N, start_r, next_r;

void divider(int &a, int &b){
    int d = (a > b) ? b : a;
    for(int i = a; i > 1; --i){
        if(a % i == 0 && b % i == 0){
            a /= i;
            b /= i;
            return;
        }
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d", &start_r);
    int a = 1, b = 1;
    for(int i = 1; i < N; ++i){
        scanf("%d", &next_r);
        a *= start_r;
        b *= next_r;
        divider(a, b);
        printf("%d/%d\n", a, b);
        start_r = next_r;
    }
    return 0;
}
