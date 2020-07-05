#include<iostream>

int main () {
    int N, inp;
    scanf("%d", &N);
    while(1){
        scanf("%d", &inp);
        if(!inp)
            break;
        if(inp % N == 0)
            printf("%d is a multiple of %d.\n", inp, N);
        else 
            printf("%d is NOT a multiple of %d.\n", inp, N);
    }
    return 0;
}
