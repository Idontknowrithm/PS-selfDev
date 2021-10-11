#include<iostream>

int c1, a1, c2, a2, c3, a3;

int main() {
    scanf("%d %d\n%d %d\n%d %d", &c1, &a1, &c2, &a2, &c3, &a3);
    for(int i = 0; i < 100; ++i){
        if(i % 3 == 0){
            if(a1 + a2 > c2){
                a1 = a1 + a2 - c2;
                a2 = c2;
            }
            else{
                a2 += a1;
                a1 = 0;
            }
        }
        else if(i % 3 == 1){
            if(a2 + a3 > c3){
                a2 = a2 + a3 - c3;
                a3 = c3;
            }
            else{
                a3 += a2;
                a2 = 0;
            }
        }
        else if(i % 3 == 2){
            if(a1 + a3 > c1){
                a3 = a3 + a1 - c1;
                a1 = c1;
            }
            else{
                a1 += a3;
                a3 = 0;
            }
        }
    }
    printf("%d\n%d\n%d", a1, a2, a3);
    return 0;
}
